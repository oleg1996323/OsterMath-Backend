#include "node/def.h"
#include "node.h"

AbstractNode* INFO_NODE::node() const{
    if(has_node())
        return parent->child(id);
    else return nullptr;
}

bool INFO_NODE::has_node() const{
    if(is_valid() && parent->has_child(id))
        return true;
    else return false;
}

bool INFO_NODE::is_valid() const{
    if(parent && id>-1)
        return true;
    else return false;
}

bool INFO_NODE::operator<(const INFO_NODE& v) const noexcept{
    return parent<v.parent;
}

bool INFO_NODE::operator==(const INFO_NODE& other) const noexcept{
    return parent == other.parent;
}

bool INFO_NODE::operator<(AbstractNode* v) const noexcept{
    return parent<v;
}

bool INFO_NODE::operator==(AbstractNode* other) const noexcept{
    return parent == other;
}

bool INFO_NODE_Comparator::operator()(const INFO_NODE& lhs,const INFO_NODE& rhs) const noexcept{
    return lhs.parent < rhs.parent;
}

bool INFO_NODE_Comparator::operator()(const AbstractNode* lhs, const INFO_NODE& rhs) const noexcept
{
    return lhs < rhs.parent;
}

bool INFO_NODE_Comparator::operator()(const INFO_NODE& lhs,const AbstractNode* rhs) const noexcept
{
    return lhs.parent < rhs;
}

void INFO_NODE::swap(INFO_NODE& other) noexcept{
    if(this!=&other){
        std::swap(this->parent,other.parent);
        std::swap(this->id,other.id);
    }
}