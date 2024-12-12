#pragma once
#include "node.h"

class ReferenceNode:public Node{
    std::vector<int> ids_;
    mutable std::shared_ptr<exceptions::Exception> cache_;
    public:
    using Node::operator=;
    using Node::insert_back;
    ReferenceNode(const std::vector<int>& ids,std::shared_ptr<Node> node);
    ReferenceNode(const ReferenceNode& other);
    ReferenceNode(ReferenceNode&&) = delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::VARIABLE;
    }
    ~ReferenceNode(){}
    virtual void insert_back(std::shared_ptr<Node> node) override;
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