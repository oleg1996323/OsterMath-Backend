#include "def.h"
#include "array_node.h"
#include "types.h"
#include <vector>
#include <memory>
#include "relation_manager.h"

ArrayNode::ArrayNode(size_t sz):
    AbstractNode(sz)
{}

ArrayNode::~ArrayNode(){
    rel_mng_->delete_node(this);
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

std::vector<std::shared_ptr<AbstractNode>>::const_iterator ArrayNode::begin() const{
    return childs().begin();
}

std::vector<std::shared_ptr<AbstractNode>>::const_iterator ArrayNode::end() const{
    return childs().end();
}

std::vector<std::shared_ptr<AbstractNode>>::const_iterator ArrayNode::cbegin() const{
    return begin();
}
std::vector<std::shared_ptr<AbstractNode>>::const_iterator ArrayNode::cend() const{
    return begin();
}

bool ArrayNode::is_numeric() const{
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](std::shared_ptr<AbstractNode> child){
        return child->is_numeric();
    })){
        return true;
    }
    else return false;
}

bool ArrayNode::is_string() const{
    if(!childs().empty() && std::all_of(childs().begin(),childs().end(),[](std::shared_ptr<AbstractNode> child){
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
    if(is_numeric())
        return TYPE_VAL::NUMERIC_ARRAY;   
    else if(is_string())
        return TYPE_VAL::STRING_ARRAY;
    else
        return TYPE_VAL::ARRAY;
}