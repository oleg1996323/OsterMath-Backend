#include "types.h"
#include "var_node.h"

VariableNode::VariableNode(VariableBase* variable):Node(),
    var_(variable){}

const VariableBase* VariableNode::variable() const noexcept{
    return var_;
}

VariableBase* VariableNode::variable() noexcept{
    return var_;
}

Result VariableNode::execute(){
    if(has_childs())
        return childs_.at(0)->execute();
    else return 0;
}

Result VariableNode::execute(size_t index){
    return childs_.at(0)->execute(index);
}

void VariableNode::refresh_parent_links() const{
    for(auto iterator_node = parents_.begin();iterator_node!=parents_.end();++iterator_node)
        if(!(*iterator_node))
            parents_.erase(iterator_node);
}

bool VariableNode::is_numeric() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_numeric();
    }
    else return false;
}

bool VariableNode::is_string() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_string();
    }
    else return false;
}

bool VariableNode::is_array() const{
    if(childs_.size()==1){
        return childs_.at(0)->is_array();
    }
    else return false;
}

void VariableNode::print_text(std::ostream& stream) const{
    stream<<"VAR(!('"<<var_->get_data_base_name()<<"\')#"<<var_->name()<<")";
}

void VariableNode::print_result(std::ostream& stream) const{
    if(childs_.size()==1)
        childs_.at(0)->print_result(stream);
}

void VariableNode::insert(std::shared_ptr<Node> node){
    if(childs_.size()<1){
        childs_.push_back(node);
        node->add_parent(this);
    }
    else {
        childs_.at(0)=node;
        node->add_parent(this);
    }
}

void VariableNode::serialize(std::ostream& stream){

}

void VariableNode::deserialize(std::ostream& stream){

}
