#include "func_node.h"
#include "var_node.h"
#include "node.h"
#include "def.h"
#include "arithmetic_functions.h"

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
                    cache_ = exp(child(0)->execute().get<Value_t>());
                    return cache_;
                    break;
                case FUNCTION_OP::LOG_BASE:
                    cache_ = log(child(0)->execute().get<Value_t>())/log(child(1)->execute().get<Value_t>());
                    return cache_;
                    break;
                case FUNCTION_OP::SUMPRODUCT:
                {
                    std::vector<std::shared_ptr<ArrayNode>> params;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->type()==NODE_TYPE::VARIABLE){
                            Result res = child->execute();
                            if(res.is_array())
                                params.push_back(res.get<std::shared_ptr<ArrayNode>>());
                            else throw std::invalid_argument("Invalid function parameter");
                        }
                    }
                    cache_ = functions::Arithmetic::SumProduct(std::move(params));
                    break;
                }
                case FUNCTION_OP::SUM:
                {
                    std::vector<std::shared_ptr<ArrayNode>> arrays;
                    for(auto& child:childs_){
                        if(child->is_array())
                            arrays.push_back(reinterpret_cast<std::shared_ptr<ArrayNode>&>(child));
                        else throw std::invalid_argument("Invalid function parameter");
                    }
                    cache_ = functions::Arithmetic::Sum(std::move(arrays));
                    break;
                }
                case FUNCTION_OP::PROD:
                {
                    std::vector<std::shared_ptr<ArrayNode>> arrays;
                    for(auto& child:childs_){
                        if(child->is_array())
                            arrays.push_back(reinterpret_cast<std::shared_ptr<ArrayNode>&>(child));
                        else throw std::invalid_argument("Invalid function parameter");
                    }
                    cache_ = functions::Arithmetic::Product(std::move(arrays));
                    break;
                }
                default:
                    throw std::invalid_argument("Unknown multiargument operation");
            }
        }
    }
    else throw std::invalid_argument("Invalid number of arguments");
    return cache_;
}

Result FunctionNode::execute(size_t index){
    //because function is like a constant
    return execute();
}

#include "types.h"

void FunctionNode::add_child(const std::shared_ptr<Node>& node){
    childs_.push_back(node);
}

std::ostream& FunctionNode::print_text(std::ostream& stream) const{
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
        stream<<child->print_text(stream);
    stream<<")";
    return stream;
    }
}
