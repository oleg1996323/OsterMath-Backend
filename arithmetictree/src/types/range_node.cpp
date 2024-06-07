#include "range_node.h"
#include "def.h"

Result RangeOperationNode::execute(){
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

Result RangeOperationNode::execute(size_t index){
    return range_expression.execute(index);
}

std::ostream& RangeOperationNode::print_text(std::ostream& stream) const{
    if(operation_==RANGE_OP::PROD)
        stream<<"prod_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    for(auto child:childs_){
        stream<<child;
    stream<<")";
    return stream;
    }
}

bool RangeOperationNode::is_numeric() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_numeric();
    });
}

bool RangeOperationNode::is_string() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_string();
    });
}

bool RangeOperationNode::is_array() const{
    return false;
}

//checks the childs types and them correct vals types
//Childs should be only numeric variable-arrays and have same length
bool RangeOperationNode::__checking_childs__() const{
    for(auto& child:childs_){
        if(child->type()==NODE_TYPE::ARRAY){
            ArrayNode* ptr = reinterpret_cast<ArrayNode*>(child.get());
            if(ptr->first_undefined_child_node()!=nullptr)
                throw std::runtime_error("Incorrect initialization of array");
            if(ptr->is_numeric()){
                if(range_size==0){
                    if((range_size=ptr->size())==0)
                        throw std::invalid_argument("Null size array input in range function");
                    else continue;
                }
                else {
                    if(range_size!=ptr->size())
                        throw std::invalid_argument("Unequal size array input in range function");
                    else continue;
                }
            }
            else {
                throw std::invalid_argument("Not numeric array data");
                return false;
            }

        }
        else return false;
    }
    return range_size;
}