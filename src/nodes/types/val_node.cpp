#include "val_node.h"
#include "array_node.h"
#include "node_manager.h"

ValueNode::~ValueNode(){
    //std::cout<<"ValueNode deleted: "<<this<<std::endl;
    //std::cout<<"Internal ReadBuf: "<<std::cout.rdbuf()<<std::endl;
    rel_mng_->delete_node(this);
}
NODE_TYPE ValueNode::type() const{
    return NODE_TYPE::VALUE;
}
void ValueNode::print_text(std::ostream& stream) const{
    stream<<cache_;
}
void ValueNode::print_result(std::ostream& stream) const{
    stream<<cache_;
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
bool ValueNode::is_empty() const{
    return false;
}