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

    bool is_numeric() const;

    bool is_string() const;

    size_t size() const;

    bool empty() const;

    std::shared_ptr<Node>& child_depth(size_t& depth, size_t& abs_id);

    std::vector<std::shared_ptr<Node>>::const_iterator begin() const;

    std::vector<std::shared_ptr<Node>>::iterator begin();

    std::vector<std::shared_ptr<Node>>::const_iterator end() const;

    std::vector<std::shared_ptr<Node>>::iterator end();

    #ifdef DEBUG
    virtual void print() const override;
    #endif

    virtual void add_parent(Node*);

    protected:
    mutable std::unordered_set<VariableNode*> var_dependence_;
};