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

void UnaryNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::UNARY);
    std::cout<<'}'<<std::endl;
}

Value_t UnaryNode::__calculate__(Value_t&& child_exec){
    switch (operation)
        {
        case UNARY_OP::LN:
            return log(child_exec);
            break;
        case UNARY_OP::LG10:
            return log10(child_exec);
            break;
        case UNARY_OP::ADD:
            return child_exec;
            break;
        case UNARY_OP::SUB:
            return (-1)*(child_exec);
            break;
        case UNARY_OP::EXP:
            return exp(child_exec);
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

Value_t BinaryNode::__calculate__(){
    switch (operation_)
    {
        case BINARY_OP::ADD:
            return lhs_cache()+rhs_cache();
            break;
        case BINARY_OP::SUB:
            return lhs_cache()-rhs_cache();
            break;
        case BINARY_OP::MUL:
            return lhs_cache()*rhs_cache();
            break;
        case BINARY_OP::DIV:
            return lhs_cache()/rhs_cache();
            break;
        case BINARY_OP::POW:
            return pow(lhs_cache(),rhs_cache());
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
            lhs_cache() = lhs_->execute(index);
            rhs_cache() = rhs_->execute(index);
        }
        return __calculate__();
    }
    else
        throw std::runtime_error("Undefined binary operation");
    return 0.;
}

void ValueNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VALUE);
    std::cout<<"; "<<val_<<'}'<<std::endl;
}

VariableNode::VariableNode(VariableBase* variable):
    var_(variable){}

const VariableBase* VariableNode::variable() const{
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

void VariableNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VARIABLE);
    std::cout<<var_->name()<<'}'<<std::endl;
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
            return var_->get<Array_t>().at(index).get<Value_t>();
        }
        throw std::invalid_argument("Invalid type of variable: must be array");
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

Node* MultiArgumentNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}

void MultiArgumentNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::MULTIARG);
    std::cout<<ENUM_NAME(operation());
    std::cout<<'}'<<std::endl;
}

auto MultiArgumentNode::__register_array_input__(){
    if(childs_.empty())
        throw std::invalid_argument("Invalid function parameters");
    std::vector<std::reference_wrapper<const Array_t>> params;
    for(Node* child:childs_){
        if(child->type()==ARITHM_NODE_TYPE::VARIABLE){
            auto ptr = reinterpret_cast<VariableNode*>(child)->variable();
            if(ptr->is_array())
                params.push_back(ptr->get<Array_t>());
            else throw std::invalid_argument("Invalid function parameter");
        }
    }
    return params;
}

Value_t MultiArgumentNode::execute(){
    if(!cache_.has_value()){
        if(operation_==MULTI_ARG_OP::LOG_BASE){
            if(childs_.size()!=2)
                throw std::invalid_argument("Invalid function parameters");
            cache_.emplace(log(childs_.at(0)->execute())/log(childs_.at(1)->execute()));
        }
        else if(operation_==MULTI_ARG_OP::SUMPRODUCT){
            if(childs_.empty())
                throw std::invalid_argument("Invalid function parameters");
            std::vector<std::reference_wrapper<const Array_t>> params;
            for(Node* child:childs_){
                if(child->type()==ARITHM_NODE_TYPE::VARIABLE){
                    auto ptr = reinterpret_cast<VariableNode*>(child)->variable();
                    if(ptr->is_array())
                        params.push_back(ptr->get<Array_t>());
                    else throw std::invalid_argument("Invalid function parameter");
                }
            }
            cache_.emplace(functions::Arithmetic::SumProduct(std::move(params)));
        }
        else if(operation_==MULTI_ARG_OP::SUM){
            if(childs_.empty())
                throw std::invalid_argument("Invalid function parameters");
            std::vector<std::reference_wrapper<const Array_t>> params;
            for(Node* child:childs_){
                if(child->type()==ARITHM_NODE_TYPE::VARIABLE){
                    auto ptr = reinterpret_cast<VariableNode*>(child)->variable();
                    if(ptr->is_array())
                        params.push_back(ptr->get<Array_t>());
                    else throw std::invalid_argument("Invalid function parameter");
                }
            }
            cache_.emplace(functions::Arithmetic::Sum(std::move(params)));
        }
        else if(operation_==MULTI_ARG_OP::PROD){
            if(childs_.empty())
                throw std::invalid_argument("Invalid function parameters");
            std::vector<std::reference_wrapper<const Array_t>> params;
            for(Node* child:childs_){
                if(child->type()==ARITHM_NODE_TYPE::VARIABLE){
                    auto ptr = reinterpret_cast<VariableNode*>(child)->variable();
                    if(ptr->is_array())
                        params.push_back(ptr->get<Array_t>());
                    else throw std::invalid_argument("Invalid function parameter");
                }
            }
            cache_.emplace(functions::Arithmetic::Product(std::move(params)));
        }
        else throw std::invalid_argument("Unknown multiargument operation");
    }
    return cache_.value();
}

Value_t MultiArgumentNode::execute(size_t index){
    return execute();
}

void MultiArgumentNode::add_child(Node* node){
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
    else if(operation_==RANGE_OP::SUMPRODUCT)
        result = 0.;
    for(size_t i=0;i<range_size;++i){
        if(operation_==RANGE_OP::SUM)
            result+=execute(i);
        else if(operation_==RANGE_OP::PROD)
            result*=execute(i);
        else if(operation_==RANGE_OP::SUMPRODUCT)
            result+=execute(i);
    }
    return result;
}

Value_t RangeOperationNode::execute(size_t index){
    return range_expression.execute(index);
}

ranges::ArithmeticTree& RangeOperationNode::expression(){
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
void MultiArgumentNode::refresh(){
    execute();
    if(has_parent()){
        caller_ = true;
        parent_->refresh();
        caller_ = false;
    }
}

void RangeOperationNode::add_child(VariableNode* var){
    this->childs_.insert(var);
}