#include "node/def.h"
#include "node.h"

std::shared_ptr<Node> INFO_NODE::node() const{
    if(has_node())
        return parent->child(id);
    else return std::shared_ptr<Node>();
}

bool INFO_NODE::has_node() const{
    if(is_valid() && parent->has_child(id))
        return true;
    else return false;
}

bool INFO_NODE::operator<(const INFO_NODE& v) const noexcept{
    return parent<v.parent;
}

bool INFO_NODE::operator==(const INFO_NODE& other) const noexcept{
    return parent == other.parent;
}

bool INFO_NODE::operator<(Node* v) const noexcept{
    return parent<v;
}

bool INFO_NODE::operator==(Node* other) const noexcept{
    return parent == other;
}

bool INFO_NODE_Comparator::operator()(const INFO_NODE& lhs,const INFO_NODE& rhs) const noexcept{
    return lhs.parent < rhs.parent;
}

bool INFO_NODE_Comparator::operator()(const Node* lhs, const INFO_NODE& rhs) const noexcept
{
    return lhs < rhs.parent;
}

bool INFO_NODE_Comparator::operator()(const INFO_NODE& lhs,const Node* rhs) const noexcept
{
    return lhs.parent < rhs;
}