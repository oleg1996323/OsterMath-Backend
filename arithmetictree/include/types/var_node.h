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
        //in listener inserting directly in VariableNode, not in VariableBase
        for(auto& child:childs_){
            Node* ptr = child->first_undefined_child_node();
            if(ptr)
                return ptr;
            else continue;
        }
        return nullptr;
    }

    const VariableBase* variable() const noexcept;

    VariableBase* variable();

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual const Result& execute() override;

    virtual const Result& execute(size_t index) override;

    virtual std::ostream& print_text(std::ostream& stream) const override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    private:
    VariableBase* var_;

    void refresh_parent_links() const;
};
