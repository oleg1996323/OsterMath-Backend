#include "func_node.h"

#ifdef DEBUG
void FunctionNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::FUNCTION);
    std::cout<<ENUM_NAME(operation());
    std::cout<<'}'<<std::endl;
}
#endif

std::shared_ptr<Node> FunctionNode::child(size_t id) const{
    if(id<childs_.size()){
        if(__is_simple_node__(id))
            return std::get<std::shared_ptr<Node>>(childs_.at(id));
        else return std::get<std::weak_ptr<VariableNode>>(childs_.at(id)).lock();
    }
    else
        throw std::invalid_argument("Incorrect child's id");
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