#include "func_node.h"
#include "def.h"

std::ostream& FunctionNode::print_text(std::ostream& stream) const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::FUNCTION);
    std::cout<<ENUM_NAME(operation());
    std::cout<<'}'<<std::endl;
}

bool FunctionNode::is_numeric() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_numeric();
    });
}

bool FunctionNode::is_string() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_string();
    });
}

bool FunctionNode::is_array() const{
    return false;
}

std::shared_ptr<Node> FunctionNode::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}

Result FunctionNode::execute(){
    if(array_type_function?childs_.size()>0:childs_.size()==childs_.capacity()){
        if(!cache_.has_value()){
            switch (operation_){
                case FUNCTION_OP::LN:
                    return log(child(0)->execute().get<Value_t>());
                    break;
                case FUNCTION_OP::LG10:
                    return log10(child(0)->execute().get<Value_t>());
                    break;
                case FUNCTION_OP::EXP:
                    return exp(child(0)->execute().get<Value_t>());
                    break;
                case FUNCTION_OP::LOG_BASE:
                    std::cout<<"log_x: "<<log(child(0)->execute().get<Value_t>())<<std::endl;
                    std::cout<<"log_x base: "<<log(child(1)->execute().get<Value_t>())<<std::endl;
                    cache_.emplace(log(child(0)->execute().get<Value_t>())/log(child(1)->execute().get<Value_t>()));
                    break;
                case FUNCTION_OP::SUMPRODUCT:
                {
                    std::vector<std::shared_ptr<ArrayNode>> params;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->type()==NODE_TYPE::VARIABLE){
                            Result res = child->execute();
                            if(res.is_array())
                                params.push_back(res.get<std::vector<std::shared_ptr<Node>>>());
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

#include "types.h"

void FunctionNode::add_child(const std::shared_ptr<Node>& node){
    if(node->type() == ARITHM_NODE_TYPE::FUNCTION){
        for(auto it:reinterpret_cast<FunctionNode*>(node.get())->get_dependencies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::RANGEOP){
        for(auto it:reinterpret_cast<RangeOperationNode*>(node.get())->get_dependencies())
            var_dependence_.insert(it);
    }
    else if(node->type() == ARITHM_NODE_TYPE::VARIABLE){
        VariableNode* var_node = reinterpret_cast<VariableNode*>(node.get());
        if(var_node->variable()->is_arithmetic_tree())
            for(auto it:var_node->variable()->get<ArithmeticTree>().get_dependencies())
                var_dependence_.insert(it);
        else if(var_node->variable()->is_array())
            for(auto it:var_node->variable()->get<Array_t>().get_dependencies())
                var_dependence_.insert(it);
    }
    childs_.push_back(node);
}

void FunctionNode::add_child(std::weak_ptr<VariableNode>&& node){
    if(!node.expired())
        var_dependence_.insert(node.lock().get());
    childs_.push_back(node);
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

const std::unordered_set<VariableNode*>& FunctionNode::get_dependencies() const{
    for(auto var_node:var_dependence_){
        if(var_node->variable()->is_arithmetic_tree())
            for(auto it:var_node->variable()->get<ArithmeticTree>().get_dependencies())
                var_dependence_.insert(it);
        else if(var_node->variable()->is_array())
            for(auto it:var_node->variable()->get<Array_t>().get_dependencies())
                var_dependence_.insert(it);
    }
    return var_dependence_;
}

std::ostream& FunctionNode::operator<<(std::ostream& stream){
    if(operation_==FUNCTION_OP::ACOS)
        stream<<"acos(";
    else if(operation_==FUNCTION_OP::COS)
        stream<<"cos(";
    else if(operation_==FUNCTION_OP::ASIN)
        stream<<"asin(";
    else if(operation_==FUNCTION_OP::SIN)
        stream<<"sin(";
    else if(operation_==FUNCTION_OP::EXP)
        stream<<"exp(";
    else if(operation_==FUNCTION_OP::FACTORIAL)
        stream<<"factorial(";
    else if(operation_==FUNCTION_OP::LG10)
        stream<<"lg10(";
    else if(operation_==FUNCTION_OP::LN)
        stream<<"ln(";
    else if(operation_==FUNCTION_OP::LOG_BASE)
        stream<<"log_x(";
    else if(operation_==FUNCTION_OP::PROD)
        stream<<"prod(";
    else if(operation_==FUNCTION_OP::SUM)
        stream<<"sum(";
    else if(operation_==FUNCTION_OP::SUMPRODUCT)
        stream<<"sumproduct(";
    else stream<<"";

    for(auto child:childs_){
        stream<<child;
    stream<<")";
    return stream;
    }
}
