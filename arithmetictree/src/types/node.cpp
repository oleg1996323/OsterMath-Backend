#include "node.h"
#include "def.h"
#include "var_node.h"
#include "types.h"
#include "serialize.h"

size_t Node::counter = 0;

Node::Node(size_t sz):
    childs_([&sz](){std::vector<std::shared_ptr<Node>> vector;
                    vector.reserve(sz);
                    return vector;}()),
                    node_count(counter++){
                        std::cout<<node_count<<std::endl;
                    }

Node::Node():node_count(counter++){
    std::cout<<node_count<<std::endl;
}

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

Result Node::execute() const{
    return const_cast<Node*>(this)->execute();
}

Result Node::execute(size_t index) const{
    return const_cast<Node*>(this)->execute(index);
}

void Node::print_text(std::ostream& stream) const{
    stream<<"#NaN"<<std::endl;
}

bool Node::refer_to(std::string_view var_name) const{
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
        return false;
    }
}

void Node::get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const{
    for(auto child:childs_){
        if(child->type()==NODE_TYPE::ARRAY)
            childs.push_back(child);
        else child->get_array_childs(childs);
    }
}

const std::unordered_set<Node*>& Node::parents() const{
    return parents_;
}

size_t Node::id() const{
    return node_count;
}

void Node::serialize_header(serialization::SerialData& serial_data, const std::shared_ptr<Node>& from){
    for(auto& child:childs_){
        if(!serial_data.contains_node(child) && child!=from){
            serial_data.insert_node(child);
            child->serialize_header(serial_data,from);
        }
    }
}

void Node::deserialize_header(serialization::SerialData& serial_data, const std::shared_ptr<Node>& from){

}