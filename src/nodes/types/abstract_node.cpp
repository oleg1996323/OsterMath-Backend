#include "abstract_node.h"
#include "var_node.h"
#include "types.h"
#include "events_errors/exception.h"
#include "string_node.h"
#include "node_manager.h"

AbstractNode* AbstractNodeNMProxy::__insert_back_internal__(AbstractNode* node, std::unique_ptr<AbstractNode>&& val){
    return node->relation_manager()->insert_back(node,std::move(val));
}

AbstractNode* AbstractNodeNMProxy::__insert_internal__(AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child){
    return node->relation_manager()->insert(node,id,std::move(new_child));
}
AbstractNode* AbstractNodeNMProxy::__replace_internal__(AbstractNode* node, size_t id,std::unique_ptr<AbstractNode>&& new_child){
    return node->relation_manager()->replace(node,id,std::move(new_child));
}
void AbstractNodeNMProxy::__reserve_childs_internal__(AbstractNode* node, size_t sz){
    return node->relation_manager()->__reserve_childs__(node,sz);
}

AbstractNode::AbstractNode(const std::shared_ptr<BaseData>& bd):
rel_mng_(bd->relation_manager()){}

AbstractNode::AbstractNode(NodeManager* rel_mng):
rel_mng_(rel_mng){}

AbstractNode* AbstractNode::child(size_t id) const{
    if(has_child(0))
        return rel_mng_->child(this,id);
    else return nullptr;
}
AbstractNode* AbstractNode::child(size_t id){
    if(has_child(0))
        return rel_mng_->child(this,id);
    else return nullptr;
}
bool AbstractNode::has_owner() const{
    return rel_mng_->has_owner(this);
}
INFO_NODE AbstractNode::owner() const{
    return rel_mng_->owner(this);
}

AbstractNode::AbstractNode(size_t sz, NodeManager* mng){
    rel_mng_ = mng;
    AbstractNodeNMProxy::__reserve_childs_internal__(this,sz);
}

void AbstractNode::refresh() const{
    execute();
    caller_ = true;
    for(auto ref:references())
        ref->refresh();
    caller_ = false;
}

bool AbstractNode::has_references() const{
    if(type()==NODE_TYPE::VARIABLE)
        return !references().empty();
    else return references().size()>0;
}
const Childs_t& AbstractNode::childs() const{
    return rel_mng_->childs(const_cast<AbstractNode*>(this));
}
bool AbstractNode::has_childs() const noexcept{
    return rel_mng_->has_childs(this);
}
bool AbstractNode::has_child(size_t id) const noexcept{
    return rel_mng_->has_child(this,id);
}

TYPE_VAL AbstractNode::type_val() const{
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

Result AbstractNode::execute() const{
    return std::monostate();
}

Result AbstractNode::execute_for_array_variables(const execute_for_array_variables_t& structure) const{
    return std::make_shared<exceptions::InvalidTypeOfArgument>("objective numeric-result node");
}

std::string AbstractNode::get_result() const{
    std::stringstream result;
    print_result(result);
    return result.str();
}
std::string AbstractNode::get_text() const{
    std::stringstream result;
    print_text(result);
    return result.str();
}

bool AbstractNode::is_empty() const{
    return true;
}

bool AbstractNode::is_array() const{
    return false;
}

bool AbstractNode::is_numeric() const{
    return false;
}

bool AbstractNode::is_string() const{
    return false;
}

bool AbstractNode::refer_to_var(std::string_view var_name) const{
    if(childs().empty()){
        return false;
    }
    else {
        return std::any_of(childs().begin(),childs().end(),[var_name](const AbstractNode* child){
            if(child->type()==NODE_TYPE::VARIABLE && 
                static_cast<const VariableNode*>(child)->variable()->name()==var_name)
                return true;
            else return child->refer_to_var(var_name);
        });
    }
}

bool AbstractNode::is_not_cycled() const{
    for(auto ref:references()){
        if(!ref->owner().parent->__is_not_cycled__(this))
            return false;
    }
    if(type()!=NODE_TYPE::VARIABLE && !owner().parent->__is_not_cycled__(this))
        return false;
    return true;
}

bool AbstractNode::__is_not_cycled__(const AbstractNode* node_cycled_search) const{
    if(this == node_cycled_search)
        return false;
    for(auto ref:references()){
        if(!ref->owner().parent->__is_not_cycled__(node_cycled_search))
            return false;
    }
    if(type()!=NODE_TYPE::VARIABLE && !owner().parent->__is_not_cycled__(this))
        return false;
    return true;
}

#include "aux_functions.h"

std::set<const VariableNode*> AbstractNode::refer_to_vars() const{
    return rel_mng_->refer_to_vars(this);
}

std::set<const AbstractNode*> AbstractNode::refer_to_node_of_type(NODE_TYPE t) const{
    return rel_mng_->refer_to_node_of_type(this,t);
}

const References_t& AbstractNode::references() const{
    return rel_mng_->references(this);
}
bool AbstractNode::is_reference_of(AbstractNode* node) const{
    return rel_mng_->is_reference_of(this,node);
}
AbstractNode* AbstractNode::__insert_back__(std::unique_ptr<AbstractNode>&& node){
    return AbstractNodeNMProxy::__insert_back_internal__(this,std::move(node));
}
AbstractNode* AbstractNode::__insert__(size_t id,std::unique_ptr<AbstractNode>&& node){
    return AbstractNodeNMProxy::__insert_internal__(this,id,std::move(node));
}
AbstractNode* AbstractNode::__replace__(size_t id,std::unique_ptr<AbstractNode>&& node){
    return AbstractNodeNMProxy::__replace_internal__(this,id,std::move(node));
}
AbstractNode* AbstractNode::insert_back_ref(AbstractNode* ref_child){
    return __insert_back__(rel_mng_->make_node<ReferenceNode>(ref_child));
}
AbstractNode* AbstractNode::insert_ref(size_t id,AbstractNode* ref_child){
    return __insert__(id,rel_mng_->make_node<ReferenceNode>(ref_child));
}
AbstractNode* AbstractNode::replace_ref(size_t id,AbstractNode* ref_child){
    return __replace__(id,rel_mng_->make_node<ReferenceNode>(ref_child));
}
void AbstractNode::print_text(std::ostream& stream) const{
}
void AbstractNode::print_result(std::ostream& stream) const{
    stream<<0;
}
INFO_NODE AbstractNode::child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last){
    return rel_mng_->child(this,first,last);
}
bool AbstractNode::is_refered_by(const AbstractNode* ref_owner) noexcept{
    return NodeManager::is_refered_by(ref_owner,this);
}
#include "func_node.h"
#include "bin_node.h"
#include "range_node.h"
#include "unary_node.h"

//only copies childs. The owner and references will be set manually by insert/replace methods
AbstractNode::AbstractNode(const AbstractNode& other, NodeManager* mng):
rel_mng_(mng),
caller_(other.caller_)
{}

AbstractNode::AbstractNode(AbstractNode&& other, NodeManager* mng):
rel_mng_(mng),
caller_(other.caller_)
{}

//only copies childs. The owner and references will be set manually by insert/replace methods
void AbstractNode::copy_paste(const AbstractNode* other){
    try{
        if(!other)
            throw kernel::FatalError("Nullptr node argument", kernel::codes::NULLPTR_AT_NODE_ARG);
        if(other!=this){
            rel_mng_->copy_node(const_cast<AbstractNode*>(other),this);
            caller_ = other->caller_;
        }
    }
    catch(const kernel::FatalError& err){}
}

void AbstractNode::cut_paste(AbstractNode* other){
    try{
        if(!other)
            throw kernel::FatalError("Nullptr node argument", kernel::codes::NULLPTR_AT_NODE_ARG);
        if(other!=this){
            rel_mng_->move_node(other,this);
            caller_ = other->caller_;
        }
    }
    catch(const kernel::FatalError& err){}
}

void copy_paste(AbstractNode* copy_from, AbstractNode* paste_to){
    if(copy_from && paste_to && copy_from!=paste_to)
        copy_from->copy_paste(paste_to);
}
void cut_paste(AbstractNode* cut_from, AbstractNode* paste_to){
    if(cut_from && paste_to && cut_from!=paste_to)
        cut_from->cut_paste(paste_to);
}

void AbstractNode::erase_child(size_t id){
    if(childs().size()>id)
        rel_mng_->erase_child(this,id);
    else throw std::invalid_argument("Invalid id for child delete");
}
void AbstractNode::erase_childs(size_t first_id, size_t last_id){
    rel_mng_->erase_childs(this,first_id,last_id);
}
AbstractNode* insert_back_move(AbstractNode* at_insertion, AbstractNode* to_move) noexcept{
    if(at_insertion && to_move)
        return NodeManager::insert_back_move(at_insertion,to_move);
    else return nullptr;
}
AbstractNode* insert_back_copy(AbstractNode* at_insertion,AbstractNode* to_copy){
    if(at_insertion && to_copy)
        return NodeManager::insert_back_copy(at_insertion,to_copy);
    else return nullptr;
}
AbstractNode* insert_move(AbstractNode* at_insertion, size_t id, AbstractNode* to_move) noexcept{
    if(at_insertion && to_move)
        return NodeManager::insert_move(at_insertion,id,to_move);
    else return nullptr;
}
AbstractNode* insert_copy(AbstractNode* at_insertion, size_t id,AbstractNode* to_copy){
    if(at_insertion && to_copy)
        return NodeManager::insert_copy(at_insertion,id,to_copy);
    else return nullptr;
}
AbstractNode* replace_move(AbstractNode* to_replace, size_t id, AbstractNode* to_move) noexcept{
    if(to_replace && to_move)
        return NodeManager::replace_move(to_replace,id,to_move);
    else return nullptr;
}
AbstractNode* replace_copy(AbstractNode* to_replace, size_t id,AbstractNode* to_copy){
    if(to_replace && to_copy)
        return NodeManager::replace_copy(to_replace,id,to_copy);
    else return nullptr;
}
Childs_Iter_t insert_back_move(AbstractNode* at_insert,Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    return NodeManager::insert_back_move(at_insert,to_move_first,to_move_last);
}
Childs_Iter_t insert_back_copy(AbstractNode* at_insert,Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    return NodeManager::insert_back_copy(at_insert,to_copy_first,to_copy_last);
}
Childs_Iter_t insert_move(AbstractNode* at_insert,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    return NodeManager::insert_move(at_insert,id,to_move_first,to_move_last);
}
Childs_Iter_t insert_copy(AbstractNode* at_insert,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    return NodeManager::insert_copy(at_insert,id,to_copy_first,to_copy_last);
}
Childs_Iter_t replace_move(AbstractNode* to_replace,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last){
    return NodeManager::replace_move(to_replace,id,to_move_first,to_move_last);
}
Childs_Iter_t replace_copy(AbstractNode* to_replace,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last){
    return NodeManager::replace_copy(to_replace,id,to_copy_first,to_copy_last);
}