#pragma once
#include "def.h"
#include "node.h"
#include "types.h"
#include <vector>
#include <memory>

class ArrayNode:public Node{
    public:
    ArrayNode(size_t sz):
        Node(sz)
    {}

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::ARRAY;
    }

    virtual Node* first_undefined_child_node() override{
        if(childs_.empty())
            return this;
        else {
            for(auto& child:childs_){
                Node* ptr = child->first_undefined_child_node();
                if(ptr!=nullptr)
                    return ptr;
                else continue;
            }
        }
        return nullptr;
    }

    virtual Result execute() override{
        return childs_;
    }

    virtual Result execute(size_t index) override{
        if(childs_.size()>index)
            return childs_.at(index)->execute(index);
        else throw std::invalid_argument("Invalid index. Prompt: out of range index");
    }

    virtual void insert(std::shared_ptr<Node> node) override{
        // if(!childs_.empty()){
        //     if(childs_.back()->type()==NODE_TYPE::FUNCTION )

        // }

        if(childs_.size()<childs_.capacity())
            childs_.push_back(node);
        else throw std::runtime_error("Invalid array initialization");

        if(node->type()==NODE_TYPE::VARIABLE)
            var_dependence_.insert(reinterpret_cast<VariableNode*>(node.get()));
    }

    virtual void serialize(std::ostream& stream) override{

    }

    virtual void deserialize(std::ostream& stream) override{

    }

    size_t size() const{
        return childs_.size();
    }

    bool is_defined() const override{
        for(auto& child:childs_)
            if(child->first_undefined_child_node()==nullptr)
                continue;
            else return false;
        return childs_.size()==childs_.capacity();
    }

    #ifdef DEBUG
    virtual void print() const override{
        
    }
    #endif

    virtual void add_parent(Node*);

    bool caller() const{
        return caller_;
    }

    protected:
    mutable std::unordered_set<VariableNode*> var_dependence_;
    bool caller_ = false;
};