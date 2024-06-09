#include "def.h"
#include "node.h"
#include "func_node.h"
#include "var_node.h"
#include "array_node.h"
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
                    cache_ =  log(child(0)->execute().get<Value_t>());
                    return cache_;
                    break;
                case FUNCTION_OP::LG10:
                    cache_ =  log10(child(0)->execute().get<Value_t>());
                    return cache_;
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
                    std::vector<ArrayNode*> arrays;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->is_array()){
                            ArrayNode* push_node;
                            if(child->type()==NODE_TYPE::VARIABLE && child->childs().size()==1)
                               push_node = reinterpret_cast<ArrayNode*>(child->child(0).get());
                            else 
                                push_node = reinterpret_cast<ArrayNode*>(child.get());
                            arrays.push_back(push_node);
                        }
                        else throw std::invalid_argument("Invalid function parameter");
                    }
                    cache_ = functions::Arithmetic::SumProduct(arrays);
                    break;
                }
                case FUNCTION_OP::SUM:
                {
                    std::vector<ArrayNode*> arrays;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->is_array()){
                            ArrayNode* push_node;
                            if(child->type()==NODE_TYPE::VARIABLE && child->childs().size()==1)
                               push_node = reinterpret_cast<ArrayNode*>(child->child(0).get());
                            else 
                                push_node = reinterpret_cast<ArrayNode*>(child.get());
                            arrays.push_back(push_node);
                        }
                        else throw std::invalid_argument("Invalid function parameter");
                    }
                    cache_ = functions::Arithmetic::Sum(arrays);
                    break;
                }
                case FUNCTION_OP::PROD:
                {
                    std::vector<ArrayNode*> arrays;
                    for(std::shared_ptr<Node>& child:childs_){
                        if(child->is_array()){
                            ArrayNode* push_node;
                            if(child->type()==NODE_TYPE::VARIABLE && child->childs().size()==1)
                               push_node = reinterpret_cast<ArrayNode*>(child->child(0).get());
                            else 
                                push_node = reinterpret_cast<ArrayNode*>(child.get());
                            arrays.push_back(push_node);
                        }
                        else throw std::invalid_argument("Invalid function parameter");
                    }
                    cache_ = functions::Arithmetic::Product(arrays);
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

void FunctionNode::print_text(std::ostream& stream) const{
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
        child->print_text(stream);
    }
    stream<<")";
}

void FunctionNode::print_result(std::ostream& stream) const{
    stream<<const_cast<FunctionNode*>(this)->execute();
}

void FunctionNode::insert(std::shared_ptr<Node> node){
    if(childs_.size()<childs_.capacity()){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to full defined function node");
}

void FunctionNode::serialize(std::ostream& stream){

}

void FunctionNode::deserialize(std::ostream& stream){

}
