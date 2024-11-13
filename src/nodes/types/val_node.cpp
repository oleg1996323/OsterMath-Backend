#include "val_node.h"
#include "array_node.h"

void ValueNode::print_text(std::ostream& stream) const{
    stream<<val_;
}

void ValueNode::print_result(std::ostream& stream) const{
    stream<<val_;
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

void ValueNode::insert_back(std::shared_ptr<Node> node){
    throw std::logic_error("Invalid inserting back. Prompt: Unvalailable to insert_back node to finite node Value");
}