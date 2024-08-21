#include "node.h"
#include "def.h"
#include "var_node.h"
#include "types.h"
#include "serialize.h"

NODE_TYPE Node::type() const{
    return NODE_TYPE::UNDEF;
}

Node::~Node(){
    for(Node* parent:parents_){
        for(std::shared_ptr<Node>& child:parent->childs_)
            if(child.get()==this)
                child.reset();
    }
    release_childs();
}

Node::Node(size_t sz):
    childs_([&sz](){std::vector<std::shared_ptr<Node>> vector;
                    vector.reserve(sz);
                    return vector;}()){}

Node::Node()=default;

//don't copy parents
Node::Node(const Node& other){
    if(&other!=this){
        for(const std::shared_ptr<Node>& child:other.childs_){
            release_childs();
            if(child->type()!=NODE_TYPE::VARIABLE)
                childs_.push_back(std::make_shared<Node>(*child.get()));
            else childs_.push_back(child);
        }
    }
}

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
    return 0;
}

Result Node::execute(size_t index) const{
    return 0;
}

Result Node::execute(){
    return 0;
}

Result Node::execute(size_t index){
    return 0;
}

bool Node::is_empty() const{
    return true;
}

bool Node::is_array() const{
    return false;
}

bool Node::is_numeric() const{
    return false;
}

bool Node::is_string() const{
    return false;
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
    return parents();
}

std::unordered_set<Node*>& Node::parents(){
    return parents_;
}

void Node::replace_move_child_to(Node* node_target,size_t id, size_t at_pos){
    if(node_target!=this && this->has_child(id)){
        this->child(id)->parents_.erase(this);
        this->child(id)->add_parent(node_target);
        node_target->insert(at_pos,std::move(this->child(id)));
        this->childs_.erase(childs_.begin()+id);
    }
}

void Node::replace_copy_child_to(Node* node_target,size_t id, size_t at_pos){
    if(node_target!=this && this->has_child(id)){
        node_target->insert(at_pos,std::make_shared<Node>(*child(id).get()));
    }
}

void Node::insert_back(std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert back child to this type of node");
}

void Node::insert(size_t,std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert child to this type of node");
}

void Node::replace(size_t,std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to replace child to this type of node");
}

void Node::print_text(std::ostream& stream) const{
    stream<<"$NaN";
}
void Node::print_result(std::ostream& stream) const{

}