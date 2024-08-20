#include "node.h"
#include "def.h"
#include "var_node.h"
#include "types.h"
#include "serialize.h"

NODE_TYPE Node::type() const{
    return NODE_TYPE::UNDEF;
}

Node::Node(size_t sz):
    childs_([&sz](){std::vector<std::shared_ptr<Node>> vector;
                    vector.reserve(sz);
                    return vector;}()){}

Node::Node()=default;

void Node::refresh(){
    execute();
    refresh_parent_links();
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

TYPE_VAL Node::type_val() const{
    if(is_numeric()){
        if(is_array())
            return TYPE_VAL::NUMERIC_ARRAY;
        else return TYPE_VAL::VALUE;
    }
    else if(is_string()){
        if(is_array())
            return TYPE_VAL::STRING_ARRAY;
        else return TYPE_VAL::STRING;
    }
    else if(is_array()){
        if(is_array())
            return TYPE_VAL::ARRAY;
        else return TYPE_VAL::UNKNOWN;
    }
    else
        return TYPE_VAL::UNKNOWN;
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
        return std::any_of(childs_.begin(),childs_.end(),[var_name](const std::shared_ptr<Node>& child){
            if(child->type()==NODE_TYPE::VARIABLE && 
                reinterpret_cast<const std::shared_ptr<VariableNode>&>(child)->variable()->name()==var_name)
                return true;
            else return child->refer_to(var_name);
        });
    }
}

void Node::refresh_parent_links() const{
    if(type()==NODE_TYPE::VARIABLE){
        for(Node* parent:parents_)
            if(!parent || parent->type()==NODE_TYPE::UNDEF)
                parents_.erase(parent);
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

void Node::serialize_header(serialization::SerialData& serial_data, const std::shared_ptr<Node>& from){
    // for(auto& child:childs_){
    //     if(!serial_data.contains_node(child) && child!=from){
    //         serial_data.insert_node(child);
    //         child->serialize_header(serial_data,from);
    //     }
    // }
}

void Node::deserialize_header(serialization::SerialData& serial_data, const std::shared_ptr<Node>& from){

}

void Node::replace_move_child_to(int id, Node* node_target){
    if(node_target!=this && this->has_child(id)){
        this->child(id)->parents_.erase(this);
        this->child(id)->add_parent(this);
        node_target->insert(id,std::move(this->child(id)));
        this->childs_.erase(childs_.begin()+id);
    }
}