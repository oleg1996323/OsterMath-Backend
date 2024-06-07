#include "node.h"
#include "def.h"
#include "var_node.h"
#include "types.h"

void Node::refresh(){
    execute();
    caller_ = true;
    for(auto parent:parents_)
        parent->refresh();
    caller_ = false;
}

void Node::add_parent(Node* parent){
    parents_.insert(parent);
}

bool Node::has_parents() const{
    return !parents_.empty();
}

const std::vector<std::shared_ptr<Node>>& Node::childs() const{
    return childs_;
}

std::ostream& Node::print_result(std::ostream& stream) const{
    stream<<execute();
    return stream;
}

std::ostream& Node::print_text(std::ostream& stream) const{
    stream<<"#NaN"<<std::endl;
    return stream;
}

bool VariableNode::refer_to(std::string_view var_name) const{
    if(childs_.empty()){
        return false;
    }
    else {
        for(auto& child:childs_){
            if(child->type()==NODE_TYPE::VARIABLE && 
            reinterpret_cast<const std::shared_ptr<VariableNode>&>(child)->variable()->name()==var_name)
                return true;
            else return child->refer_to(var_name);
        }
    }
}