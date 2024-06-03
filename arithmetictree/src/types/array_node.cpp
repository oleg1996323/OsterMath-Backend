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

    }

    virtual Node* first_undefined_child_node() override{
        if(childs_.empty())
            this;
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

    virtual Value_t execute() override{
        assert(true);
    }

    virtual Value_t execute(size_t index) override{
        if(childs_.size()>index)
            return childs_.at(index);
        else return 0.;
    }

    virtual void refresh() override{
        if(has_parents()){
            
        }
            
    }

    virtual void insert(std::shared_ptr<Node> node) override{
        // if(!childs_.empty()){
        //     if(childs_.back()->type()==NODE_TYPE::FUNCTION )

        // }

        if(childs_.size()<childs_.capacity())
            childs_.push_back(node);
        else throw std::runtime_error("Invalid array initialization");

        if(node->type()==NODE_TYPE::VARIABLE)
            dependencies_.insert(reinterpret_cast<VariableNode*>(node.get())->variable()->name());
    }

    virtual void serialize(std::ostream& stream) override{

    }

    virtual void deserialize(std::ostream& stream) override{

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
    std::unordered_set<std::string_view> dependencies_;
    bool caller_ = false;
};