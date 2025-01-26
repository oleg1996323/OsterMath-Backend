#include "def.h"
#include "array_node.h"
#include "types.h"
#include <vector>
#include <memory>
#include "node_manager.h"

ArrayNode::ArrayNode(size_t sz, NodeManager* mng):
    AbstractNode(sz, mng)
{}

ArrayNode::ArrayNode(const ArrayNode& arr,NodeManager* mng):AbstractNode(arr,mng){
    if(this!=&arr){
        rel_mng_->copy_node(this,&arr);
        cache_ = arr.cache_;
    }
}
ArrayNode::ArrayNode(ArrayNode&& arr,NodeManager* mng):AbstractNode(arr,mng){
    if(this!=&arr){
        rel_mng_->swap_node(this,&arr);
        std::swap(cache_,arr.cache_);
    }
}

ArrayNode::~ArrayNode(){
    std::cout<<"ArrayNode deleted: "<<this<<std::endl;
    if(rel_mng_)
        rel_mng_->delete_node(this);
}

NODE_TYPE ArrayNode::type() const{
    return NODE_TYPE::ARRAY;
}

Result ArrayNode::execute() const{
    flush_cache();
    for(const AbstractNode* child:childs()){
        if(child->execute().is_error()){
            cache_ = child->cached_result();
            return cache_;
        }
    }
    cache_ = this;
    return cache_;
}

size_t ArrayNode::size() const{
    return childs().size();
}

bool ArrayNode::empty() const{
    return childs().empty();
}

Childs_t::const_iterator ArrayNode::begin() const{
    return childs().begin();
}

Childs_t::const_iterator ArrayNode::end() const{
    return childs().end();
}

Childs_t::const_iterator ArrayNode::cbegin() const{
    return begin();
}
Childs_t::const_iterator ArrayNode::cend() const{
    return begin();
}

bool ArrayNode::is_numeric() const{
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](const AbstractNode* child){
        return child->is_numeric();
    })){
        return true;
    }
    else return false;
}

bool ArrayNode::is_string() const{
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](const AbstractNode* child){
        return child->is_string();
    })){
        return true;
    }
    else return false;
}

bool ArrayNode::is_array() const{
    return true;
}

bool ArrayNode::is_empty() const{
    return false;
}

void ArrayNode::print_text(std::ostream& stream) const{
    // if(&stream!=&std::cout)
    //     print_text(std::cout);
    bool first = true;
    stream<<'[';
    for(const AbstractNode* child:childs()){
        if(first)
            first = false;
        else
            stream<<"; ";
        child->print_text(stream);  
    }
    stream<<']';
}

void ArrayNode::print_result(std::ostream& stream) const{
    // if(&stream!=&std::cout)
    //     print_result(std::cout);
    bool first = true;
    stream<<'[';
    if(!childs().empty()){
        for(const AbstractNode* child:childs()){
            if(first)
                first = false;
            else
                stream<<"; ";
            child->print_result(stream);
        }
    }
    stream<<']';
}

std::ostream& operator<<(std::ostream& stream, const ArrayNode* node){
    node->print_text(stream);
    return stream;
}

TYPE_VAL ArrayNode::type_val() const{
    if(is_numeric())
        return TYPE_VAL::NUMERIC_ARRAY;   
    else if(is_string())
        return TYPE_VAL::STRING_ARRAY;
    else
        return TYPE_VAL::ARRAY;
}

#include "string_node.h"
#include "val_node.h"
#include "func_node.h"
#include "range_node.h"
#include "empty_node.h"
//discard from arraynode to its child
AbstractNode* ArrayNode::discard(){
    if(has_child(0)){
        AbstractNode* res = child(0);
        rel_mng_->move_node(this,res);
        return res;
    }
    else return owner().parent->replace<EmptyNode>(owner().id);
}
#include "core/system.h"
#include "core/sys_exceptions.h"
ArrayNode* ArrayNodeNMProxy::__implementation__(AbstractNode* val){
    ArrayNode* array = nullptr;
    try{
        if(!val)
            throw kernel::FatalError(std::string("Undefined node at ")+__func__,kernel::codes::NULLPTR_AT_NODE_ARG);
        INFO_NODE tmp_owner = val->owner();
        if(!tmp_owner.is_valid())
            throw kernel::FatalError(std::string("Undefined owner at node of type ")+nodes_types[(size_t)val->type()],kernel::codes::OWNER_UNDEFINED);
        NodeManager* active_node_manager = val->relation_manager();
        array = static_cast<ArrayNode*>(NodeManager::add_node(active_node_manager,
        std::move(std::make_unique<ArrayNode>(1,active_node_manager))));
        if(!array)
            throw std::bad_alloc();
        active_node_manager->childs_[array].push_back(val);
        active_node_manager->owner_[array]=tmp_owner;
        active_node_manager->childs_.at(tmp_owner.parent).at(tmp_owner.id)=array;
        active_node_manager->owner_.at(val)=INFO_NODE{array,0};
        array->set_relation_manager(active_node_manager);
    }
    catch(const std::bad_alloc& alloc_err){
        kernel::System::get_logger().log_error_and_exit(alloc_err.what(),kernel::codes::BAD_NODE_CREATION);
    }
    catch(const kernel::FatalError& err){}
    return array;
}

ArrayNode* ArrayNodeNMProxy::__implement_by_var__(AbstractNode* array_owner, int id,VariableNode* var){
    ArrayNode* array = nullptr;
    try{
        if(!var || !array_owner)
            throw kernel::FatalError(std::string("Undefined node at ")+__func__,kernel::codes::NULLPTR_AT_NODE_ARG);
        if(!var->has_owner())
            throw kernel::FatalError(std::string("Unexpected owner at ")+nodes_types[(size_t)NODE_TYPE::VARIABLE],kernel::codes::OWNER_UNEXPECTED_DEFINITION);
        NodeManager* active_node_manager = array_owner->relation_manager();
        array = static_cast<ArrayNode*>(NodeManager::add_node(active_node_manager,
        std::move(std::make_unique<ArrayNode>(1,active_node_manager))));
        if(!array)
            throw std::bad_alloc();
        array->set_relation_manager(active_node_manager);
        //make new reference
        array->insert_back_ref(var);
        //delete node of reference
        active_node_manager->nodes_.erase(active_node_manager->nodes_.find(active_node_manager->childs_.at(array_owner).at(id)));
        //assign new child at id of deleted reference
        active_node_manager->childs_.at(array_owner).at(id)=array;
    }
    catch(const std::bad_alloc& alloc_err){
        kernel::System::get_logger().log_error_and_exit(alloc_err.what(),kernel::codes::BAD_NODE_CREATION);
    }
    catch(const kernel::FatalError& err){}
    return array;
}