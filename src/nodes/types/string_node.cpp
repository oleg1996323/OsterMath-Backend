#include "string_node.h"
#include "array_node.h"

void StringNode::print_text(std::ostream& stream) const{
    stream<<"\""<<cache_<<"\"";
}

void StringNode::print_result(std::ostream& stream) const{
    stream<<"\""<<cache_<<"\"";
}

bool StringNode::is_numeric() const{
    return false;
}

bool StringNode::is_string() const{
    return true;
}

bool StringNode::is_array() const{
    return false;
}

void StringNode::insert_back(std::shared_ptr<Node> node){
    throw std::logic_error("Invalid inserting back. Prompt: Unvalailable to insert_back node to finite node String");
}