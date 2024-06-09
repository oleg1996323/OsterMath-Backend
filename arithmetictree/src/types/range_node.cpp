#include "range_node.h"
#include "def.h"

Result RangeOperationNode::execute(){
    Value_t result;
    childs_.clear();
    range_expression->get_array_childs(childs_);
    define_range_length();
    if(operation_==RANGE_OP::SUM)
        result = 0.;
    else if(operation_==RANGE_OP::PROD)
        result = 1.;
    for(size_t i=0;i<range_size;++i){
        std::cout<<"Index: "<<i<<std::endl;
        if(operation_==RANGE_OP::SUM)
            result+=execute(i).get<Value_t>();
        else if(operation_==RANGE_OP::PROD)
            result*=execute(i).get<Value_t>();
    }
    return result;
}

Result RangeOperationNode::execute(size_t index){
    if(range_expression)
        return range_expression->execute(index);
    else return 0.;
}

void RangeOperationNode::print_text(std::ostream& stream) const{
    if(operation_==RANGE_OP::PROD)
        stream<<"product_i(";
    else if(operation_==RANGE_OP::SUM)
        stream<<"sum_i(";
    else stream<<"";

    range_expression->print_text(stream);

    stream<<")";
}

void RangeOperationNode::print_result(std::ostream& stream) const{
    stream<<const_cast<RangeOperationNode*>(this)->execute();
}

bool RangeOperationNode::is_numeric() const{
    if(range_expression)
        return range_expression->is_numeric();
    else return false;
}

bool RangeOperationNode::is_string() const{
    if(range_expression)
        return range_expression->is_string();
    else return false;
}

bool RangeOperationNode::is_array() const{
    return false;
}

void RangeOperationNode::insert(std::shared_ptr<Node> node){
    range_expression = node;
    node->add_parent(this);
}

void RangeOperationNode::serialize(std::ostream& stream){
    
}

void RangeOperationNode::deserialize(std::ostream& stream){

}

void RangeOperationNode::define_range_length(){
    size_t sz = 0;
    for (auto child:childs_){
        if(sz==0){
            sz = reinterpret_cast<std::shared_ptr<ArrayNode>&>(child)->size();
            if(sz==0)
                throw std::invalid_argument("Empty array argument to range-operation-function");
        }
        else{
            if(reinterpret_cast<std::shared_ptr<ArrayNode>&>(child)->size()!=sz)
                throw std::invalid_argument("Innegal sizes of range-operation-function arguments");
        }
    }
    range_size = sz;
}