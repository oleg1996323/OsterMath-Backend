#pragma once
#include <unordered_set>
#include "def.h"
#include "node.h"

class VariableBase;

class VariableNode:public Node{
    public:
    VariableNode(VariableBase* variable);
    
    virtual NODE_TYPE type() const override{
        return NODE_TYPE::VARIABLE;
    }

    virtual Node* first_undefined_child_node() override{
        if(childs_.empty())
            return this;
        else{
            for(auto& child:childs_){
                Node* ptr = child->first_undefined_child_node();
                if(ptr)
                    return ptr;
                else return nullptr;
            }
        }
        return nullptr;
    }

    const VariableBase* variable() const;

    VariableBase* variable();

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    virtual bool is_defined() const override{
        for(auto& child:childs_)
            if(child->first_undefined_child_node()==nullptr)
                continue;
            else return false;
        return true;
    }

    virtual void add_parent(Node* parent) override; 

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    private:
    mutable std::unordered_set<VariableNode*> var_dependence_;
    VariableBase* var_; 

    void refresh_parent_links() const;
};