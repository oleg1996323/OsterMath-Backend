#include "empty_node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"
#include "node_manager.h"

EmptyNode::EmptyNode(NodeManager* mng):
AbstractNode(mng){}

TYPE_VAL EmptyNode::type_val() const{
    return TYPE_VAL::UNKNOWN;
}
EmptyNode::~EmptyNode(){
    //std::cout<<"EmptyNode deleted: "<<this<<std::endl;
    //rel_mng_-> call delete method for destructed node
    if(rel_mng_)
        rel_mng_->delete_node(this);
}

NODE_TYPE EmptyNode::type() const{
    return NODE_TYPE::UNDEF;
}

Result EmptyNode::execute() const{
    return std::monostate();
}

Result EmptyNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    return std::make_shared<exceptions::InvalidTypeOfArgument>("objective numeric-result node");
}

bool EmptyNode::is_empty() const{
    return true;
}

bool EmptyNode::is_array() const{
    return false;
}

bool EmptyNode::is_numeric() const{
    return false;
}

bool EmptyNode::is_string() const{
    return false;
}

bool EmptyNode::__is_not_cycled__(const AbstractNode* node_cycled_search) const{
    return true;
}

#include "aux_functions.h"
void EmptyNode::print_text(std::ostream& stream) const{
}
void EmptyNode::print_result(std::ostream& stream) const{
    stream<<0;
}