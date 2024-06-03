#include "val_node.h"

#ifdef DEBUG
void ValueNode::print() const{
    std::cout<<'{'<<ENUM_NAME(ARITHM_NODE_TYPE::VALUE);
    std::cout<<"; "<<val_<<'}'<<std::endl;
}
#endif