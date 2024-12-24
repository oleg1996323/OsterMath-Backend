#include "def.h"
#include "array_node.h"
#include "types.h"
#include <vector>
#include <memory>
#include "node_manager.h"

ArrayNode::ArrayNode(size_t sz):
    AbstractNode(sz)
{}

ArrayNode::~ArrayNode(){
    rel_mng_->delete_node(this);
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

template<>
std::unique_ptr<ArrayNode>&& ArrayNode::implement_by(StringNode* val) noexcept{
    if(val){
        //replace child in owner by array
        // do it safely by anonymous NodeManager
        INFO_NODE tmp_owner = val->owner();
        assert(tmp_owner.is_valid());
        std::unique_ptr<ArrayNode> tmp = std::make_unique<ArrayNode>(0);
        NodeManager::begin(val->relation_manager());
        AbstractNode* result = NodeManager::add_node(tmp_owner.parent->relation_manager(),std::move(tmp));
        
        tmp_owner.parent->relation_manager()->replace_child_wo_delete_in_owner_by(
                tmp_owner.parent,
                tmp_owner.id,
                result
        );
        assert(result);
        result->insert_back(std::move(val));
        NodeManager::end();
        tmp->set_relation_manager(val->relation_manager()); //setting same NodeManager as value
    }
    return result;
}