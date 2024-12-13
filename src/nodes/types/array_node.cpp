#include "def.h"
#include "array_node.h"
#include "types.h"
#include <vector>
#include <memory>
#include "relation_manager.h"

ArrayNode::ArrayNode(size_t sz):
    Node(sz)
{}

NODE_TYPE ArrayNode::type() const{
    return NODE_TYPE::ARRAY;
}

Result ArrayNode::execute() const{
    flush_cache();
    for(auto child:childs()){
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

std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::begin() const{
    return childs().begin();
}

std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::end() const{
    return childs().end();
}

std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::cbegin() const{
    return begin();
}
std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::cend() const{
    return begin();
}

void ArrayNode::insert_back(std::shared_ptr<Node> node){
    if(node){
        flush_cache();
        if(type_val_.has_value() && !(type_val_.value()&node->type_val()))
            __invalidate_type_val__();
        else{
            type_val_.emplace(node->type_val() | TYPE_VAL::ARRAY);
        }
        rel_mng_->insert_back(this,node);
    }
}

std::shared_ptr<Node> ArrayNode::insert(size_t id,std::shared_ptr<Node> node){
    if(node){
        flush_cache();
        if(type_val_.has_value() && !(type_val_.value()&node->type_val()))
            __invalidate_type_val__();
        else
            type_val_.emplace(node->type_val() | TYPE_VAL::ARRAY);
        rel_mng_->insert(this,id,node);
        rel_mng_->add_parent(childs()[id].get(),this, id);
        return node;
    }
    else return std::make_shared<Node>();
}

std::shared_ptr<Node> ArrayNode::replace(size_t id,std::shared_ptr<Node> node){
    if(node){
        flush_cache();
        if(type_val_.has_value() && !(type_val_.value()&node->type_val()))
            __invalidate_type_val__();
        else
            type_val_.emplace(node->type_val() | TYPE_VAL::ARRAY);
        rel_mng_->swap_childs(this,node.get());
        rel_mng_->add_parent(childs()[id].get(),this,id);
        return node;
    }
    else return std::make_shared<Node>();
}

bool ArrayNode::is_numeric() const{
    if(type_val_.has_value() && type_val_.value()&TYPE_VAL::NUMERIC_ARRAY)
        return true;
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](std::shared_ptr<Node> child){
        return child->is_numeric();
    })){
        type_val_.emplace(TYPE_VAL::NUMERIC_ARRAY);
        return true;
    }
    else return false;
}

bool ArrayNode::is_string() const{
    if(type_val_.has_value() && type_val_.value()&TYPE_VAL::STRING_ARRAY)
        return true;
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](std::shared_ptr<Node> child){
        return child->is_string();
    })){
        type_val_.emplace(TYPE_VAL::STRING_ARRAY);
        return true;
    }
    else return false;
}

bool ArrayNode::is_array() const{
    return true;
}

void ArrayNode::print_text(std::ostream& stream) const{
    // if(&stream!=&std::cout)
    //     print_text(std::cout);
    bool first = true;
    stream<<'[';
    for(auto child:childs()){
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
        for(auto child:childs()){
            if(first)
                first = false;
            else
                stream<<"; ";
            child->print_result(stream);
                
        }
    }
    stream<<']';
}

std::ostream& operator<<(std::ostream& stream, const std::shared_ptr<ArrayNode>& node){
    node->print_text(stream);
    return stream;
}

TYPE_VAL ArrayNode::type_val() const{
    if(type_val_.has_value())
        return type_val_.value();
    if(is_numeric())
        type_val_=TYPE_VAL::NUMERIC_ARRAY;   
    else if(is_string())
        type_val_=TYPE_VAL::STRING_ARRAY;
    else
        type_val_=TYPE_VAL::ARRAY;
    return type_val_.value();
}

#include "aux_functions.h"

bool ArrayNode::is_rectangle() const{
    return std::all_of(begin(),end(),[this](const std::shared_ptr<Node>& child)
    {
        return child->childs().size()==(*begin())->childs().size() && functions::auxiliary::is_rectangle_array_node(child);
    });
}