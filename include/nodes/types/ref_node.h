#pragma once
#include "abstract_node.h"

class ReferenceNode:public AbstractNode{
    public:
    ReferenceNode(std::shared_ptr<AbstractNode> reference);
    ReferenceNode(const ReferenceNode& other);
    ReferenceNode(ReferenceNode&&) = delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::REF;
    }
    ~ReferenceNode();
    //virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_empty() const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual Result cached_result() const override;
    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
};