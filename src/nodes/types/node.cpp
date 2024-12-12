#include "node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"
#include "relation_manager.h"

Node::Node():
rel_mng_(BaseData::get_anonymous_relation_manager()){}

Node::Node(const std::shared_ptr<BaseData>& bd):
rel_mng_(bd->relation_manager()){}

Node::Node(RelationManager* rel_mng):
rel_mng_(rel_mng?rel_mng:BaseData::get_anonymous_relation_manager()){}

void Node::release_childs(){
    rel_mng_->release_childs(this);
}

const std::shared_ptr<Node>& Node::child(size_t id) const{
    return rel_mng_->child(this,id);
}
std::shared_ptr<Node>& Node::child(size_t id){
    return rel_mng_->child(this,id);
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
    //rel_mng_-> call delete method for destructed node
    rel_mng_->delete_node(this);
}

Node::Node(size_t sz):
rel_mng_(BaseData::get_anonymous_relation_manager()){
    rel_mng_->reserve_childs(this,sz);
}

void Node::refresh() const{
    execute();
    refresh_parent_links();
    caller_ = true;
    for(auto& [parent,ids]:parents())
        parent->refresh();
    caller_ = false;
}

void Node::__add_parent__(Node* parent, int id){
    rel_mng_->add_parent(this,parent,id);
}

void Node::__erase_parent__(const Node* parent){
    rel_mng_->erase_parent(this,parent);
}

bool Node::has_parents() const{
    return !parents().empty();
}

const std::vector<std::shared_ptr<Node>>& Node::childs() const{
    return rel_mng_->childs(this);
}

// std::vector<std::shared_ptr<Node>>& Node::childs(){
//     return rel_mng_->childs(this);
// }

bool Node::has_childs() const noexcept{
    return rel_mng_->has_childs(this);
}
bool Node::has_child(size_t id) const noexcept{
    return rel_mng_->has_child(this,id);
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
    if(childs().empty()){
        return false;
    }
    else {
        return std::any_of(childs().begin(),childs().end(),[var_name](const std::shared_ptr<Node>& child){
            if(child->type()==NODE_TYPE::VARIABLE && 
                std::dynamic_pointer_cast<VariableNode>(child)->variable()->name()==var_name)
                return true;
            else return child->refer_to(var_name);
        });
    }
}

bool Node::is_not_cycled() const{
    if(parents().empty()){
        return true;
    }
    else {
        for(auto& [parent,id]:parents()){
            if(!parent->__is_not_cycled__(this))
                return false;
        }
        return true;
    }
}

bool Node::__is_not_cycled__(const Node* node_cycled_search) const{
    if(this == node_cycled_search)
        return false;
    if(parents().empty()){
        return true;
    }
    else {
        for(auto& [parent,id]:parents()){
            if(!parent->__is_not_cycled__(node_cycled_search))
                return false;
        }
        return true;
    }
}

#include "aux_functions.h"

std::set<std::shared_ptr<VariableNode>> Node::refer_to_vars() const{
    std::set<std::shared_ptr<VariableNode>> vars_;
    for(const std::shared_ptr<Node>& child:childs()){
        if(child->type()==NODE_TYPE::VARIABLE)
            vars_.insert(std::dynamic_pointer_cast<VariableNode>(child));
        else
            vars_.merge(child->refer_to_vars());
    }
    return vars_;
}

std::set<std::shared_ptr<Node>> Node::refer_to_node_of_type(NODE_TYPE t) const{
    std::set<std::shared_ptr<Node>> nodes_;
    for(const std::shared_ptr<Node>& child:childs()){
        if(child->type()==t)
            nodes_.insert(child);
        else
            nodes_.merge(child->refer_to_node_of_type(t));
    }
    return nodes_;
}

void Node::refresh_parent_links() const{
    if(type()==NODE_TYPE::VARIABLE){
        for(const auto&[parent,ids]:parents())
            if(!parent || parent->type()==NODE_TYPE::UNDEF)
                rel_mng_->erase_parent(this,parent);
    }
}

const std::unordered_map<const Node*,std::vector<int>>& Node::parents() const{
    return rel_mng_->parents(this);
}
// , childs().size()-1

// void Node::replace_move_child_to(Node* node_target,size_t id, size_t at_pos){
//     flush_cache();
//     __invalidate_type_val__();
//     if(node_target!=this && this->has_child(id)){
//         auto found = child(id)->parents().find(this);
//         if(found!=child(id)->parents().end())
//             this->child(id)->parents().erase(found);
//         this->child(id)->add_parent(node_target,id);
//         node_target->insert(at_pos,std::move(this->child(id)));
//         this->childs().erase(childs().begin()+id);
//     }
// }

// void Node::replace_copy_child_to(Node* node_target,size_t id, size_t at_pos){
//     flush_cache();
//     __invalidate_type_val__();
//     if(node_target!=this && this->has_child(id)){
//         node_target->insert(at_pos,std::make_shared<Node>(*child(id))); //TODO remake with specified type
//     }
// }

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
#include "core/settings.h"
//get the node which is not intermediate (ValueNode, StringNode, RangeNode, FunctionNode, VariableNode, ArrayNode)
INFO_NODE Node::child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last){
    if(type()==NODE_TYPE::VARIABLE || type()==NODE_TYPE::ARRAY){ //only valuable node
        INFO_NODE info{this,*first};
        std::vector<int>::const_iterator iter;
        for(iter=first;iter<last;++iter){
            if(info.parent->type()==NODE_TYPE::VARIABLE){
                while (info.parent->type()==NODE_TYPE::VARIABLE)
                    if(info.parent->has_child(0)){
                        info.parent = info.parent->child(0).get();
                        info.id = *iter;
                        if(info.has_node())
                            continue;
                        else return INFO_NODE();
                    }
                    else
                        return INFO_NODE();
            }
            else{
                if(info.has_node()){
                    info.parent = info.node().get();
                    info.id = *iter;
                    if(!info.has_node())
                        return INFO_NODE();
                }
                else return INFO_NODE();
            }
            assert(info.has_node());
        }
        if(kernel::settings::Model::show_through_var_nodes()){
            while (info.node()->type()==NODE_TYPE::VARIABLE)
                if(info.node()->has_child(0)){
                    info.parent = info.node().get();
                    info.id = 0;
                }
                else
                    return INFO_NODE();
            return info; 
        }
        return info;
    }
    else return INFO_NODE();
}
INFO_NODE Node::child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last) const{
    return child(first,last);
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

#include "func_node.h"
#include "bin_node.h"
#include "range_node.h"
#include "unary_node.h"

Node::Node(const Node& other):
rel_mng_(other.rel_mng_){
    if(&other!=this){
        std::shared_ptr<Node> this_node_tmp;
        if(!parents().empty())
            this_node_tmp = parents().begin()->first->child(parents().begin()->second.front());
        for(auto& [parent,ids]:parents())
            for(int id:ids)
                parent->erase_child(id);
        release_childs();
        rel_mng_->copy_childs(this,other.childs());
    }
}

Node::Node(Node&& other):
rel_mng_(std::move(other.rel_mng_)){
    if(&other!=this){
        rel_mng_->swap_childs(this,&other);
        for(auto& [parent,ids]:parents())
            for(int id:ids)
                parent->erase_child(id);
        std::swap(caller_,other.caller_);
    }
}

Node& Node::operator=(Node&& other){
    if(&other!=this){
        rel_mng_->swap_childs(this,&other);
        std::swap(caller_,other.caller_);
    }
    return *this;
}

void Node::__invalidate_type_val__() const{
    for(auto& [parent,id]:parents()){
        parent->__invalidate_type_val__();
    }
}

void Node::erase_child(size_t id) const{
    if(childs().size()>id)
        rel_mng_->erase_child(this,id);
    else throw std::invalid_argument("Invalid id for child delete");
}

Node& Node::operator=(const Node& other){
    if(&other!=this){
        //if releasing the parents stays
        release_childs();
        rel_mng_->copy_childs(this,other.childs());
    }
    return *this;
}

void Node::__rel_tmp_forward_insert_back__(const std::shared_ptr<Node>& node){
    rel_mng_->insert_back(this,node);
}