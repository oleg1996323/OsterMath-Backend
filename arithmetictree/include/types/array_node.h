#pragma once
#include "def.h"
#include "node.h"
#include "types.h"
#include <vector>
#include <memory>

class ArrayNode:public Node{
    public:
    ArrayNode(size_t sz);

    virtual NODE_TYPE type() const override;

    virtual Node* first_undefined_child_node() override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    size_t size() const;

    #ifdef DEBUG
    virtual void print() const override;
    #endif

    virtual void add_parent(Node*);

    protected:
    mutable std::unordered_set<VariableNode*> var_dependence_;
    bool caller_ = false;
};