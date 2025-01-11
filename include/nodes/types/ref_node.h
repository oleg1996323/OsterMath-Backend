#pragma once
#include "abstract_node.h"

class ReferenceNode:public AbstractNode{
    public:
    ReferenceNode(AbstractNode* reference);
    ReferenceNode(const ReferenceNode& other);
    ReferenceNode(ReferenceNode&&) = delete;
    ReferenceNode* copy_from(const ReferenceNode* other){
        return static_cast<ReferenceNode*>(AbstractNode::copy_from(other));
    }
    ReferenceNode* move_from(ReferenceNode* other) noexcept{
        return static_cast<ReferenceNode*>(AbstractNode::move_from(other));
    }

    virtual NODE_TYPE type() const override;
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