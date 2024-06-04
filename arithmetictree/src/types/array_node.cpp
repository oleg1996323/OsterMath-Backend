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

std::shared_ptr<Node>& ArrayNode::child_depth(size_t& depth, size_t abs_id) const{
    return childs_;
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
        for(std::shared_ptr<Node> child:childs_){
            Node* undef = child->first_undefined_child_node();
            if(undef){
                undef->insert(node);
                if(node->type()==NODE_TYPE::VARIABLE)
                    var_dependence_.insert(reinterpret_cast<VariableNode*>(node.get()));
                return;
            }
        }
    }

    if(childs_.size()<childs_.capacity())
        childs_.push_back(node);
    else throw std::runtime_error("Invalid array initialization");

    if(node->type()==NODE_TYPE::VARIABLE)
        var_dependence_.insert(reinterpret_cast<VariableNode*>(node.get()));
}

void ArrayNode::serialize(std::ostream& stream){

}

void ArrayNode::deserialize(std::ostream& stream){

}

#ifdef DEBUG
void ArrayNode::print() const{
    
}
#endif

bool ArrayNode::is_numeric() const{
    return std::all_of(childs_.begin(),childs_.end(),[](const std::shared_ptr<Node>& node){
        if(node->type()==NODE_TYPE::ARRAY)
            return reinterpret_cast<const std::shared_ptr<ArrayNode>&>(node)->is_numeric();
        else if(node->type()==NODE_TYPE::VARIABLE)
            return reinterpret_cast<const std::shared_ptr<VariableNode>&>(node)->is_numeric();
        else 
            return true;
    });
}

bool ArrayNode::is_string() const{
    return std::all_of(childs_.begin(),childs_.end(),[](const std::shared_ptr<Node>& node){
        if(node->type()==NODE_TYPE::ARRAY)
            return reinterpret_cast<const std::shared_ptr<ArrayNode>&>(node)->is_string();
        else if(node->type()==NODE_TYPE::VARIABLE)
            return reinterpret_cast<const std::shared_ptr<VariableNode>&>(node)->is_string();
        else 
            return true;
    });
}