#include "string_node.h"
#include "array_node.h"
#include "relation_manager.h"

StringNode::~StringNode(){
    rel_mng_->delete_node(this);
}

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

bool StringNode::is_empty() const{
    return false;
}