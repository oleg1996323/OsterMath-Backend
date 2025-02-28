#pragma once
#include <unordered_set>
#include "abstract_node.h"

class VariableBase;
using namespace node_range_operation;
class VariableNode:public AbstractNode{
    mutable std::shared_ptr<exceptions::Exception> cache_;
    VariableBase* var_;
    public:
    using AbstractNode::operator=;
    VariableNode(VariableBase* variable);
    VariableNode(const VariableNode& other) = delete;
    VariableNode(VariableNode&&) = delete;

    virtual NODE_TYPE type() const override;
    ~VariableNode();

    const VariableBase* variable() const noexcept;

    VariableBase* variable() noexcept;

    //virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual Result execute() const override;

    virtual void print_text(std::ostream& stream) const override;

    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_empty() const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void flush_cache() const override;

    inline virtual Result cached_result() const override;

    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
};