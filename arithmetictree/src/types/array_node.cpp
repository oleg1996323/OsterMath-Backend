#include "def.h"
#include "array_node.h"
#include "types.h"
#include <vector>
#include <memory>

ArrayNode::ArrayNode(size_t sz):
    Node(sz)
{}

NODE_TYPE ArrayNode::type() const{
    return NODE_TYPE::ARRAY;
}

Node* ArrayNode::first_undefined_child_node(){
    for(auto& child:childs_){
            Node* ptr = child->first_undefined_child_node();
            if(ptr!=nullptr)
                return ptr;
            else continue;
        }

        return childs_.size()!=childs_.capacity()?nullptr:this;
}

Result ArrayNode::execute(){
    return std::shared_ptr<ArrayNode>(this);
}

Result ArrayNode::execute(size_t index){
    if(childs_.size()>index)
        return childs_.at(index)->execute(index);
    else throw std::invalid_argument("Invalid index. Prompt: out of range index");
}

size_t ArrayNode::size() const{
    return childs_.size();
}

bool ArrayNode::empty() const{
    return childs_.empty();
}

std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::begin() const{
    return childs_.begin();
}

std::vector<std::shared_ptr<Node>>::iterator ArrayNode::begin(){
    return childs_.begin();
}

std::vector<std::shared_ptr<Node>>::const_iterator ArrayNode::end() const{
    return childs_.end();
}

std::vector<std::shared_ptr<Node>>::iterator ArrayNode::end(){
    return childs_.end();
}

void ArrayNode::insert(std::shared_ptr<Node> node){
    if(!childs_.empty()){
        for(std::shared_ptr<Node> child:childs_)
            child->first_undefined_child_node()->insert(node);
    }

    if(childs_.size()<childs_.capacity())
        childs_.push_back(node);
    else throw std::runtime_error("Invalid array initialization");
}

void ArrayNode::serialize(std::ostream& stream){

}

void ArrayNode::deserialize(std::ostream& stream){

}

bool ArrayNode::is_numeric() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_numeric();
    });
}

bool ArrayNode::is_string() const{
    return std::all_of(childs_.begin(),childs_.end(),[](std::shared_ptr<Node> child){
        return child->is_string();
    });
}

bool ArrayNode::is_array() const{
    return true;
}

std::ostream& ArrayNode::print_text(std::ostream& stream) const{
    stream<<'[';
    for(auto child:childs_){
        stream<<child;
    }
    stream<<']';
    return stream;
}