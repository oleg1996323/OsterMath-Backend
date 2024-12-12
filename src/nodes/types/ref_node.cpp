#include "ref_node.h"

ReferenceNode::ReferenceNode(const std::vector<int>& ids,std::shared_ptr<Node> node):Node(),ids_(ids){
    if(node)
        insert_back(node);
}

Result ReferenceNode::execute() const{
    flush_cache();
    if(!is_not_cycled())
        cache_=std::make_shared<exceptions::CyclicReference>("");
    if(has_childs())
        return childs().at(0)->execute();
    else return Node::execute();
}

inline Result ReferenceNode::cached_result() const{
    if(!is_not_cycled())
        cache_=std::make_shared<exceptions::CyclicReference>("");
    if(has_childs()){
        return childs().at(0)->cached_result();
    }
    else return Node::execute();
}

void ReferenceNode::flush_cache() const{
    cache_.reset();
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
    for(int id:ids_)
        stream<<id;
    stream<<")"<<std::endl;
}

void ReferenceNode::print_result(std::ostream& stream) const{
    if(childs().size()==1)
        childs().at(0)->print_result(stream);
}

#include "relation_manager.h"
void ReferenceNode::insert_back(std::shared_ptr<Node> node){
    if(node){
        if(childs().size()<1)
            rel_mng_->insert_back(this,node);
        else
            rel_mng_->child(this,0)=node;
        rel_mng_->add_parent(node.get(),this,0);
    }
}

#include "test/log_duration.h"
Result ReferenceNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    if(has_child(0))
        return child(0)->execute_for_array_variables(structure);
    else throw std::runtime_error("Fatal error: not defined reference node");
}