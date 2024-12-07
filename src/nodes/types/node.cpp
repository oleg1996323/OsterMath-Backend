#include "node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"

void Node::release_childs(){
    for(std::shared_ptr<Node>& child:childs_)
        if(child){
            auto found = child->parents_.find(this);
            if(found!=child->parents_.end())
                child->parents_.erase(found);
        }
    childs_.clear();
}

const std::shared_ptr<Node>& Node::child(size_t id) const{
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
}
std::shared_ptr<Node>& Node::child(size_t id){
    if(id<childs_.size())
        return childs_.at(id);
    else
        throw std::invalid_argument("Incorrect child's id");
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
    for(const INFO_NODE& parent:parents_){
        for(std::shared_ptr<Node>& child:parent.parent->childs_)
            if(child.get()==this)
                child.reset();
    }
    release_childs();
}

Node::Node(size_t sz):
    childs_([&sz](){std::vector<std::shared_ptr<Node>> vector;
                    vector.reserve(sz);
                    return vector;}()){}

void Node::refresh(){
    execute();
    refresh_parent_links();
    caller_ = true;
    for(auto parent:parents_)
        parent.parent->refresh();
    caller_ = false;
}

void Node::add_parent(Node* parent, int id){
    parents_.insert({parent,id});
}

bool Node::has_parents() const{
    return !parents_.empty();
}

const std::vector<std::shared_ptr<Node>>& Node::childs() const{
    return childs_;
}

TYPE_VAL Node::type_val() const{
    if(is_numeric()){
        if(is_array()) return TYPE_VAL::NUMERIC_ARRAY;   
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
    else return TYPE_VAL::UNKNOWN;
}

Result Node::execute() const{
    return std::monostate();
}

Result Node::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    return std::make_shared<exceptions::InvalidTypeOfArgument>("objective numeric-result node");
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

bool Node::is_not_cycled() const{
    if(parents_.empty()){
        return true;
    }
    else {
        return std::all_of(parents_.begin(),parents_.end(),[this](const INFO_NODE& parent){
            return parent.parent->__is_not_cycled__(this);
        });
    }
}

bool Node::__is_not_cycled__(const Node* node_cycled_search) const{
    if(this == node_cycled_search)
        return false;
    if(parents_.empty()){
        return true;
    }
    else {
        return std::all_of(parents_.begin(),parents_.end(),[node_cycled_search](const INFO_NODE& parent){
            return parent.parent->__is_not_cycled__(node_cycled_search);
        });
    }
}

#include "aux_functions.h"

std::set<std::shared_ptr<VariableNode>> Node::refer_to_vars() const{
    std::set<std::shared_ptr<VariableNode>> vars_;
    for(const std::shared_ptr<Node>& child:childs_){
        if(child->type()==NODE_TYPE::VARIABLE)
            vars_.insert(std::dynamic_pointer_cast<VariableNode>(child));
        else
            vars_.merge(child->refer_to_vars());
    }
    return vars_;
}

std::set<std::shared_ptr<Node>> Node::refer_to_node_of_type(NODE_TYPE t) const{
    std::set<std::shared_ptr<Node>> nodes_;
    for(const std::shared_ptr<Node>& child:childs_){
        if(child->type()==t)
            nodes_.insert(child);
        else
            nodes_.merge(child->refer_to_node_of_type(t));
    }
    return nodes_;
}

void Node::refresh_parent_links(){
    if(type()==NODE_TYPE::VARIABLE){
        for(const INFO_NODE& parent:parents_)
            if(!parent.parent || parent.parent->type()==NODE_TYPE::UNDEF)
                parents_.erase(parent);
    }
}

const std::set<INFO_NODE,INFO_NODE_Comparator>& Node::parents() const{
    return parents_;
}

std::set<INFO_NODE,INFO_NODE_Comparator>& Node::parents(){
    return parents_;
}
// , childs_.size()-1

void Node::replace_move_child_to(Node* node_target,size_t id, size_t at_pos){
    flush_cache();
    __invalidate_type_val__();
    if(node_target!=this && this->has_child(id)){
        auto found = child(id)->parents_.find(this);
        if(found!=child(id)->parents_.end())
            this->child(id)->parents_.erase(found);
        this->child(id)->add_parent(node_target,id);
        node_target->insert(at_pos,std::move(this->child(id)));
        this->childs_.erase(childs_.begin()+id);
    }
}

void Node::replace_copy_child_to(Node* node_target,size_t id, size_t at_pos){
    flush_cache();
    __invalidate_type_val__();
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
        else return INFO_NODE();
    else{
        if(has_child(0)){
            if(indexes.size()>1 && child(0)->has_child(*indexes.begin()))
                return child(0)->child(*indexes.begin())->child(std::vector<size_t>(indexes.cbegin()+1,indexes.cend()));
            else if(indexes.size()==1 && child(0)->has_child(*indexes.begin())){
                info.parent = child(0).get();
                info.id = *indexes.begin();
                return info;
            }
            else return INFO_NODE();
        }
        else return INFO_NODE();
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

Node& Node::operator=(Node&& other){
    if(&other!=this){
        childs_.swap(other.childs_);
        for(auto& parent:parents_) //TODO: need swapping 
            parent.parent->childs_.erase(childs_.begin()+parent.id);
        parents_.swap(other.parents_);
        std::swap(caller_,other.caller_);
    }
    return *this;
}

#include "func_node.h"
#include "bin_node.h"
#include "range_node.h"
#include "unary_node.h"
Node& Node::operator=(const Node& other){
    if(&other!=this){
        std::shared_ptr<Node> this_node_tmp;
        if(!parents_.empty())
            this_node_tmp = parents_.begin()->node();
        for(auto& parent:parents_)
            parent.parent->childs_.erase(parent.parent->childs_.begin()+parent.id);
        release_childs();
        for(const std::shared_ptr<Node>& child:other.childs_){
            switch(child->type()){
                case NODE_TYPE::ARRAY:{
                    insert_back(std::make_shared<ArrayNode>(*std::dynamic_pointer_cast<ArrayNode>(child))); //need to check
                    break;
                }
                case NODE_TYPE::BINARY :{
                    childs_.push_back(std::make_shared<BinaryNode>(*std::dynamic_pointer_cast<BinaryNode>(child))); //need to check
                    break;                        
                }
                case NODE_TYPE::RANGEOP :{
                    childs_.push_back(std::make_shared<RangeOperationNode>(*std::dynamic_pointer_cast<RangeOperationNode>(child))); //need to check
                    break;                        
                }
                case NODE_TYPE::FUNCTION :{
                    childs_.push_back(std::make_shared<FunctionNode>(*std::dynamic_pointer_cast<FunctionNode>(child))); //need to check
                    break;                        
                }
                case NODE_TYPE::STRING :{
                    childs_.push_back(std::make_shared<StringNode>(*std::dynamic_pointer_cast<StringNode>(child))); //need to check
                    break;                        
                }
                case NODE_TYPE::UNARY :{
                    childs_.push_back(std::make_shared<UnaryNode>(*std::dynamic_pointer_cast<UnaryNode>(child))); //need to check
                    break;                        
                }
                case NODE_TYPE::VALUE :{
                    childs_.push_back(std::make_shared<ValueNode>(*std::dynamic_pointer_cast<ValueNode>(child))); //need to check
                    break;
                }
                case NODE_TYPE::CUSTOM :{
                    //TODO: integrate further
                    assert(true);
                    break;
                }
                case NODE_TYPE::VARIABLE:{
                    childs_.push_back(child);
                    break;
                }
                default:{
                    childs_.push_back(std::make_shared<Node>(*child.get())); //need to check
                    break;
                }
            }
        }
    }
    return *this;
}

void Node::__invalidate_type_val__() const{
    for(auto& parent:parents_){
        parent.parent->__invalidate_type_val__();
    }
}