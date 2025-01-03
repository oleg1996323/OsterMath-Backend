#include "ref_node.h"
#include "node_manager.h"

ReferenceNode::ReferenceNode(AbstractNode* reference):AbstractNode(reference->relation_manager()){
    relation_manager()->insert_back_ref(this,reference);
}

ReferenceNode::ReferenceNode(const ReferenceNode& other):AbstractNode(){//should refer the same node as "other" (node should not be copied)
    if(other.has_child(0))
        relation_manager()->insert_back_ref(this,other.child(0));
}
ReferenceNode::~ReferenceNode(){
    rel_mng_->delete_node(this);
}
Result ReferenceNode::execute() const{
    assert(has_child(0));
    return child(0)->execute();
}
bool ReferenceNode::is_empty() const{
    return childs().size()==0;
}
bool ReferenceNode::is_numeric() const{
    if(childs().size()==1){
        return childs().at(0)->is_numeric();
    }
    else return false;
}
bool ReferenceNode::is_string() const{
    if(childs().size()==1){
        return childs().at(0)->is_string();
    }
    else return false;
}
bool ReferenceNode::is_array() const{
    if(childs().size()==1){
        return childs().at(0)->is_array();
    }
    else return false;
}
void ReferenceNode::print_text(std::ostream& stream) const{
    /*variable:
        WS* ((VAR_TAG '(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')' node_access?) | (VARIABLE node_access?))  WS*
    ;*/
    //WS* ('('  WS*  ')') | ('(' WS* UINT WS*  ')') | ('('  WS* UINT WS* (';' WS* UINT)* WS*  ')') WS*
    stream<<"(";
    // for(int id:ids_)
    //     stream<<id;
    stream<<")"<<std::endl;
}
void ReferenceNode::print_result(std::ostream& stream) const{
    if(childs().size()==1)
        childs().at(0)->print_result(stream);
}
#include "test/log_duration.h"
Result ReferenceNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    if(has_child(0))
        return child(0)->execute_for_array_variables(structure);
    else throw std::runtime_error("Fatal error: not defined reference node");
}
Result ReferenceNode::cached_result() const{
    if(has_child(0))
        return child(0)->cached_result();
    else return std::make_shared<warnings::UndefinedRef>();
}