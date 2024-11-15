#include "node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"

std::shared_ptr<Node> INFO_NODE::node() const{
    if(has_node())
        return parent->child(id);
    else return std::shared_ptr<Node>();
}

bool INFO_NODE::has_node() const{
    if(is_valid() && parent->has_child(id))
        return true;
    else return false;
}

bool INFO_NODE::is_valid() const{
    if(parent && id>-1)
        return true;
    else return false;
}

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
    return std::monostate();
}

Result Node::execute(size_t index) const{
    return std::monostate();
}

std::string Node::get_result() const{
    std::stringstream result;
    print_result(result);
    return result.str();
}
std::string Node::get_text() const{
    std::stringstream result;
    print_text(result);
    return result.str();
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
                std::dynamic_pointer_cast<VariableNode>(child)->variable()->name()==var_name)
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

// void Node::get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const{
//     for(auto child:childs_){
//         if(child->type()==NODE_TYPE::ARRAY)
//             childs.push_back(child);
//         else child->get_array_childs(childs);
//     }
// }

const std::set<Node*>& Node::parents() const{
    return parents();
}

std::set<Node*>& Node::parents(){
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

std::shared_ptr<Node> Node::insert(size_t,std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to insert child to this type of node");
}

std::shared_ptr<Node> Node::replace(size_t,std::shared_ptr<Node>){
    throw std::logic_error("Invalid inserting. Prompt: Unvalailable to replace child to this type of node");
}

void Node::print_text(std::ostream& stream) const{
}
void Node::print_result(std::ostream& stream) const{
    stream<<0;
}

INFO_NODE Node::child(const std::vector<size_t>& indexes){
    INFO_NODE info;
    if(type()!=NODE_TYPE::VARIABLE)
        if(indexes.size()>1 && has_child(*indexes.begin()))
            return child(*indexes.begin())->child(std::vector<size_t>(indexes.cbegin()+1,indexes.cend()));
        else if(indexes.size()==1 && has_child(*indexes.begin())){
            info.parent = this;
            info.id = *indexes.begin();
            return info;
        }
        else throw exceptions::NodeChildDontExists("");
    else{
        if(has_child(0)){
            if(indexes.size()>1 && child(0)->has_child(*indexes.begin()))
                return child(0)->child(*indexes.begin())->child(std::vector<size_t>(indexes.cbegin()+1,indexes.cend()));
            else if(indexes.size()==1 && child(0)->has_child(*indexes.begin())){
                info.parent = child(0).get();
                info.id = *indexes.begin();
                return info;
            }
            else throw exceptions::NodeChildDontExists("");
        }
        else throw exceptions::NodeChildDontExists("");
    }
}

INFO_NODE Node::child(const std::vector<size_t>& indexes) const{
    return child(indexes);
}

void Node::__insert_back_string_node__(const std::string& string){
    insert_back(std::make_shared<StringNode>(string));
}
void Node::__insert_back_string_node__(std::string&& string){
    insert_back(std::make_shared<StringNode>(std::move(string)));
}
void Node::__insert_back_value_node__(const Value_t& val){
    insert_back(std::make_shared<ValueNode>(val));
}
void Node::__insert_back_value_node__(Value_t&& val){
    insert_back(std::make_shared<ValueNode>(std::move(val)));
}

/*
INFO_NODE Node::child(const std::vector<size_t>& indexes, const Node* caller) const{
    return child(indexes, this);
}

INFO_NODE Node::child(const std::vector<size_t>& indexes, Node* caller){
    INFO_NODE info;
    if(type()!=NODE_TYPE::VARIABLE)
        if(indexes.size()>1 && has_child(*indexes.begin())){
            std::shared_ptr<INFO_NODE> this_info = std::make_shared<INFO_NODE>(caller,std::shared_ptr<INFO_NODE>(),*indexes.begin());
            INFO_NODE res = child(*indexes.begin())->child(std::vector<size_t>(indexes.cbegin()+1,indexes.cend()));
            res.parent_info = std::move(this_info);
            return res;
        }
        else if(indexes.size()==1 && has_child(*indexes.begin())){
            info.parent = this;
            info.id = *indexes.begin();
            return info;
        }
        else throw exceptions::NodeChildDontExists("");
    else{
        if(has_child(0)){
            if(indexes.size()>1 && child(0)->has_child(*indexes.begin())){
                std::shared_ptr<INFO_NODE> this_info = std::make_shared<INFO_NODE>(caller,std::shared_ptr<INFO_NODE>(),*indexes.begin());
                INFO_NODE res = child(0)->child(*indexes.begin())->child(std::vector<size_t>(indexes.cbegin()+1,indexes.cend()));
                res.parent_info = std::move(this_info);
                return res;
            }
            else if(indexes.size()==1 && child(0)->has_child(*indexes.begin())){
                info.parent = child(0).get();
                info.id = *indexes.begin();
                return info;
            }
            else throw exceptions::NodeChildDontExists("");
        }
        else throw exceptions::NodeChildDontExists("");
    }
}*/