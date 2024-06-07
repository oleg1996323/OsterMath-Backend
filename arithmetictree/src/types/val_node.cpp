#include "val_node.h"

std::ostream& ValueNode::print_text(std::ostream& stream) const{
    stream<<val_;
    return stream;
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

bool ValueNode::refer_to(std::string_view var_name) const {
    return false;
}