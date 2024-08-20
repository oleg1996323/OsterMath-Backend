#include "val_node.h"

void ValueNode::print_text(std::ostream& stream) const{
    if(val_.has_value())
        stream<<val_.value();
    else stream<<"#NAN";
}

void ValueNode::print_result(std::ostream& stream) const{
    if(val_.has_value())
        stream<<val_.value();
    else stream<<"#NAN";
}

bool ValueNode::is_numeric() const{
    return true;
}

bool ValueNode::is_string() const{
    return false;
}

bool ValueNode::is_array() const{
    return false;
}

void ValueNode::insert(std::shared_ptr<Node> node){
    throw std::logic_error("Invalid inserting back. Prompt: Unvalailable to insert_back node to finite node Value");
}

//insert before value at id
void ValueNode::insert(int,std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert node to finite node Value");
}

void ValueNode::replace(int,std::shared_ptr<Node>){
    throw std::logic_error("Invalid replacing. Prompt: Unvalailable to replace node to finite node Value");
}

void ValueNode::serialize(std::ostream& stream){

}

void ValueNode::deserialize(std::ostream& stream){

}
