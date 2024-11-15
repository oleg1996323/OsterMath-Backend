#pragma once
#include <unordered_set>
#include "node.h"

class VariableBase;

class VariableNode:public Node{
    VariableBase* var_;
    public:
    VariableNode(VariableBase* variable);
    VariableNode(const VariableNode& other);
    VariableNode(VariableNode&&) = delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::VARIABLE;
    }

    ~VariableNode(){}

    const VariableBase* variable() const noexcept;

    VariableBase* variable() noexcept;

    virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual Result execute() const override;

    virtual Result execute(size_t index) const override;

    virtual void print_text(std::ostream& stream) const override;

    virtual void print_result(std::ostream& stream) const override;

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    inline virtual Result cached_result() override;
    inline virtual Result cached_result(size_t index) override;

    private:
};