#include "var_node.h"
#include "types.h"
#include "def.h"

std::ostream& VariableNode::print_text(std::ostream& stream) const{
    stream<<"VAR(!('"<<var_->get_data_base_name()<<"\')#"<<var_->name()<<"\'="<<!childs_.empty()?child(0)->print_text(stream):"NaN";
    return stream;
}

VariableNode::VariableNode(VariableBase* variable):
    var_(variable){}

const VariableBase* VariableNode::variable() const{
    if(var_)
        return var_;
    else throw "Variable don't exists"s;
}

VariableBase* VariableNode::variable() noexcept{
    return var_;
}

Result VariableNode::execute(){
    return childs_.at(0)->execute();
}

Result VariableNode::execute(size_t index){
    return childs_.at(0)->execute();
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

bool VariableNode::refer_to(std::string_view var_name) const{
    if(childs_.empty()){
        return false;
    }
    else {
        for(auto& child:childs_){
            if(child->refer_to(var_name))
                return true;
        }
    }
}