#include "arithmetic_types.h"
#include "types.h"

#define ENUM_NAME(p) #p;

void Node::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        parent_->refresh();
        caller_ = false;
    }
}

void Node::add_parent(Node* parent){
    parent_=parent;
}

bool Node::has_parent() const{
    return parent_!=nullptr;
}

Node* UnaryNode::first_undefined_child_node(){
    if(!child_)
        return this;
    else return child_->first_undefined_child_node();
}

Value_t UnaryNode::__calculate__(Value_t&& child_exec){
    switch (operation)
        {
        case UNARY_OP::ADD:
            return child_exec;
            break;
        case UNARY_OP::SUB:
            return (-1)*(child_exec);
            break;
        case UNARY_OP::PARENS:
            return child_exec;
            break;
        default:
            throw std::invalid_argument("Unknown type of unary expression");
            break;
        }
}

Value_t UnaryNode::execute(){
    using namespace boost::multiprecision;
    if(child_){
        return __calculate__(std::move(child_->execute()));
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
}

Value_t UnaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(child_){
        return __calculate__(std::move(child_->execute(index)));
    }
    else
        throw std::runtime_error("Undefined unary operation");
    return 0.;
}

Node* BinaryNode::first_undefined_child_node(){
    Node* ptr;
    if(!lhs_)
        return this;
    else if((ptr = lhs_->first_undefined_child_node()))
        return ptr;
    else if(!rhs_)
        return this;
    else if((ptr = rhs_->first_undefined_child_node()))
        return ptr;
    return nullptr;
}

Value_t BinaryNode::__calculate__(){
    switch (operation_)
    {
        case BINARY_OP::ADD:
            std::cout<<"Add: "<<lhs_cache()<<" and "<<rhs_cache()<<std::endl;
            return lhs_cache()+rhs_cache();
            break;
        case BINARY_OP::SUB:
            std::cout<<"Sub: "<<lhs_cache()<<" and "<<rhs_cache()<<std::endl;
            return lhs_cache()-rhs_cache();
            break;
        case BINARY_OP::MUL:
            std::cout<<"Mul: "<<lhs_cache()<<" and "<<rhs_cache()<<std::endl;
            return lhs_cache()*rhs_cache();
            break;
        case BINARY_OP::DIV:
            std::cout<<"Div: "<<lhs_cache()<<" and "<<rhs_cache()<<std::endl;
            return lhs_cache()/rhs_cache();
            break;
        case BINARY_OP::POW:
            std::cout<<"Pow: "<<lhs_cache()<<" and "<<rhs_cache()<<std::endl;
            return pow(lhs_cache(),rhs_cache());
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
}

Value_t BinaryNode::__calculate__(size_t index){
    switch (operation_)
    {
        case BINARY_OP::ADD:
            std::cout<<"Add: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
            return lhs_cache(index)+rhs_cache(index);
            break;
        case BINARY_OP::SUB:
            std::cout<<"Sub: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
            return lhs_cache(index)-rhs_cache(index);
            break;
        case BINARY_OP::MUL:
            std::cout<<"Mul: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
            return lhs_cache(index)*rhs_cache(index);
            break;
        case BINARY_OP::DIV:
            std::cout<<"Div: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
            return lhs_cache(index)/rhs_cache(index);
            break;
        case BINARY_OP::POW:
            std::cout<<"Pow: "<<lhs_cache(index)<<" and "<<rhs_cache(index)<<std::endl;
            return pow(lhs_cache(index),rhs_cache(index));
            break;
        default:
            throw std::invalid_argument("Unknown type of binary expression");
            break;
    }
}

Value_t BinaryNode::execute(){
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        if(lhs_->caller()) //left branch call refreshing
            lhs_->execute();
        else if(rhs_->caller()) //right branch call refreshing
            rhs_->execute();
        else{
            lhs_cache() = lhs_->execute();
            rhs_cache() = rhs_->execute();
            std::cout<<"lhs: "<<lhs_cache()<<std::endl;
            std::cout<<"rhs: "<<rhs_cache()<<std::endl;
        }
        return __calculate__();
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

Value_t BinaryNode::execute(size_t index){
    using namespace boost::multiprecision;
    if(lhs_ && rhs_){
        if(lhs_->caller()) //left branch call refreshing
            lhs_->execute(index);
        else if(rhs_->caller()) //right branch call refreshing
            rhs_->execute(index);
        else{
            lhs_cache(index) = lhs_->execute(index);
            rhs_cache(index) = rhs_->execute(index);
        }
        return __calculate__(index);
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

VariableNode::VariableNode(VariableBase* variable):
    var_(variable){}

const VariableBase* VariableNode::variable() const{
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

VariableBase* VariableNode::variable(){
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

void VariableNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        refresh_parent_links();
        for(auto parent:parents_){
            parent->refresh();
        }
        caller_ = false;
    }
}

Value_t VariableNode::execute(){
    if(var_){
        if(var_->is_value()){
            return var_->get<Value_t>();
        }
        else if(var_->is_arithmetic_tree()){
            return var_->get<ArithmeticTree>().execute();
        }
        else if(var_->is_undef())
            return 0.;
        else
        throw std::invalid_argument("Invalid type of variable: not calculable");
    }
    else throw std::runtime_error("Uninitialized variable");
}

Value_t VariableNode::execute(size_t index){
    if(var_){
        if(var_->is_array()){
            const Array_val& val = var_->get<Array_t>().at(index);
            if(val.is_expression())
                return val.get<ArithmeticTree>().execute();
            else if(val.is_value())
                return val.get<Value_t>();
            else throw std::invalid_argument("Invalid type of array item");
        }
        else if(var_->is_numeric()){
            if(var_->is_value())
                return var_->get<Value_t>();
            else if(var_->is_arithmetic_tree())
                return var_->get<ArithmeticTree>().value();
            else throw std::invalid_argument("Invalid type of variable");
        }
        throw std::invalid_argument("Invalid type of variable: not array or numeric");
    }
    else throw std::runtime_error("Uninitialized variable");
    
}

void VariableNode::add_parent(Node* parent){
    if(parents_.contains(parent))
        parents_.erase(parent);
    parents_.insert(parent);
}

void VariableNode::refresh_parent_links() const{
    for(auto iterator_node = parents_.begin();iterator_node!=parents_.end();++iterator_node)
        if(!(*iterator_node))
            parents_.erase(iterator_node);
}

std::shared_ptr<Node> FunctionNode::child(size_t id) const{
    if(id<childs_.size()){
        if(__is_simple_node__(id))
            return std::get<std::shared_ptr<Node>>(childs_.at(id));
        else return std::get<std::weak_ptr<VariableNode>>(childs_.at(id)).lock();
    }
    else
        throw std::invalid_argument("Incorrect child's id");
}

auto FunctionNode::__register_array_input__(){
    if(childs_.empty())
        throw std::invalid_argument("Invalid function parameters");
    std::vector<std::reference_wrapper<const Array_t>> params;
    for(size_t i = 0;i<childs_.size();++i){
        auto child_i = child(i);
        if(child_i->type()==ARITHM_NODE_TYPE::VARIABLE){
            auto ptr = reinterpret_cast<VariableNode*>(child_i.get())->variable();
            if(ptr->is_array())
                params.push_back(ptr->get<Array_t>());
            else throw std::invalid_argument("Invalid function parameter");
        }
    }
    return params;
}

Value_t FunctionNode::execute(){
    if(array_type_function?childs_.size()>0:childs_.size()==number_of_arguments){
        if(!cache_.has_value()){
            switch (operation_){
                case FUNCTION_OP::LN:
                    return log(child(0)->execute());
                    break;
                case FUNCTION_OP::LG10:
                    return log10(child(0)->execute());
                    break;
                case FUNCTION_OP::EXP:
                    return exp(child(0)->execute());
                    break;
                case FUNCTION_OP::LOG_BASE:
                    std::cout<<"log_x: "<<log(child(0)->execute())<<std::endl;
                    std::cout<<"log_x base: "<<log(child(1)->execute())<<std::endl;
                    cache_.emplace(log(child(0)->execute())/log(child(1)->execute()));
                    break;
                case FUNCTION_OP::SUMPRODUCT:
                {
                    std::vector<std::reference_wrapper<const Array_t>> params;
                    for(size_t i = 0;i<childs_.size();++i){
                        auto child_i = child(i);
                        if(child_i->type()==ARITHM_NODE_TYPE::VARIABLE){
                            auto ptr = reinterpret_cast<VariableNode*>(child_i.get())->variable();
                            if(ptr->is_array())
                                params.push_back(ptr->get<Array_t>());
                            else throw std::invalid_argument("Invalid function parameter");
                        }
                    }
                    cache_.emplace(functions::Arithmetic::SumProduct(std::move(params)));
                    break;
                }
                case FUNCTION_OP::SUM:
                {
                    std::vector<std::reference_wrapper<const Array_t>> params;
                    for(size_t i = 0;i<childs_.size();++i){
                        auto child_i = child(i);
                        if(child_i->type()==ARITHM_NODE_TYPE::VARIABLE){
                            auto ptr = reinterpret_cast<VariableNode*>(child_i.get())->variable();
                            if(ptr->is_array())
                                params.push_back(ptr->get<Array_t>());
                            else throw std::invalid_argument("Invalid function parameter");
                        }
                    }
                    cache_.emplace(functions::Arithmetic::Sum(std::move(params)));
                    break;
                }
                case FUNCTION_OP::PROD:
                {
                    if(childs_.empty())
                        throw std::invalid_argument("Invalid function parameters");
                    std::vector<std::reference_wrapper<const Array_t>> params;
                    for(size_t i = 0;i<childs_.size();++i){
                        auto child_i = child(i);
                        if(child_i->type()==ARITHM_NODE_TYPE::VARIABLE){
                            auto ptr = reinterpret_cast<VariableNode*>(child_i.get())->variable();
                            if(ptr->is_array())
                                params.push_back(ptr->get<Array_t>());
                            else throw std::invalid_argument("Invalid function parameter");
                        }
                    }
                    cache_.emplace(functions::Arithmetic::Product(std::move(params)));
                    break;
                }
                default: 
                    throw std::invalid_argument("Unknown multiargument operation");
            }
        }
    }
    else throw std::invalid_argument("Invalid number of arguments");
    return cache_.value();
}

Value_t FunctionNode::execute(size_t index){
    return execute();
}

void FunctionNode::add_child(const std::shared_ptr<Node>& node){
    if(node->type() == ARITHM_NODE_TYPE::FUNCTION){
        for(auto it:reinterpret_cast<FunctionNode*>(node.get())->get_dependecies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::RANGEOP){
        for(auto it:reinterpret_cast<RangeOperationNode*>(node.get())->get_dependecies())
            var_dependence_.insert(it);
    }
    childs_.push_back(node);
}

void FunctionNode::add_child(std::weak_ptr<VariableNode>&& node){
    if(!node.expired())
        var_dependence_.insert(node.lock().get());
    childs_.push_back(node);
}

Value_t RangeOperationNode::execute(){
    Value_t result;
    if(!__checking_childs__())
        throw std::invalid_argument("Invalid input of variables");
    if(operation_==RANGE_OP::SUM)
        result = 0.;
    else if(operation_==RANGE_OP::PROD)
        result = 1.;
    for(size_t i=0;i<range_size;++i){
        if(operation_==RANGE_OP::SUM)
            result+=execute(i);
        else if(operation_==RANGE_OP::PROD)
            result*=execute(i);
    }
    return result;
}

Value_t RangeOperationNode::execute(size_t index){
    return range_expression.execute(index);
}

ranges::ArithmeticTree& RangeOperationNode::expression(){
    return range_expression;
}

const ranges::ArithmeticTree& RangeOperationNode::expression() const{
    return range_expression;
}

//can has only one parent (unlike the variable node)
void RangeOperationNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        parent_->refresh();
        caller_ = false;
    }
}

//can has only one parent (unlike the variable node)
void FunctionNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        parent_->refresh();
        caller_ = false;
    }
}

const std::unordered_set<VariableNode*>& FunctionNode::get_dependecies() const{
    return var_dependence_;
}

const std::unordered_set<VariableNode*>& RangeOperationNode::get_dependecies() const{
    return expression().get_dependecies();
}

#ifdef DEBUG

void UnaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::UNARY);
    std::cout<<'}'<<std::endl;
}

void BinaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::BINARY);
    std::cout<<"; ";
    if(operation_==BINARY_OP::ADD){
        std::cout<<ENUM_NAME(BINARY_OP::ADD);}
    else if(operation_==BINARY_OP::SUB){
        std::cout<<ENUM_NAME(BINARY_OP::SUB);}
    else if(operation_==BINARY_OP::MUL){
        std::cout<<ENUM_NAME(BINARY_OP::MUL);}
    else if(operation_==BINARY_OP::DIV){
        std::cout<<ENUM_NAME(BINARY_OP::DIV);}
    else std::cout<<ENUM_NAME(BINARY_OP::POW);
    std::cout<<'}'<<std::endl;
}

void ValueNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VALUE);
    std::cout<<"; "<<val_<<'}'<<std::endl;
}

void VariableNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VARIABLE);
    std::cout<<var_->name()<<'}'<<std::endl;
}

void FunctionNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::FUNCTION);
    std::cout<<ENUM_NAME(operation());
    std::cout<<'}'<<std::endl;
}

void RangeOperationNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::RANGEOP);
    if(operation_==RANGE_OP::PROD)
        std::cout<<ENUM_NAME(RANGE_OP::PROD);
    if(operation_==RANGE_OP::SUM)
        std::cout<<ENUM_NAME(RANGE_OP::SUM);
    std::cout<<'}'<<std::endl;
}

#endif