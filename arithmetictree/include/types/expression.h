#pragma once
#include "node.h"

class ExpressionNode{
    public:
    ExpressionNode(size_t sz):
        childs_([&sz](){std::vector<std::shared_ptr<Node>> vector;
                        vector.reserve(sz);
                        return vector;}()){}
    
    ExpressionNode() = default;

    virtual NODE_TYPE type() const override;

    virtual Node* first_undefined_child_node() override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    #ifdef DEBUG
    virtual void print() const{
        std::cout<<"Undef node"<<std::endl;
    }
    #endif

    virtual ~Node(){}

    virtual void add_parent(Node*);

    bool has_parents() const;

    bool caller() const{
        return caller_;
    }

    const std::vector<std::shared_ptr<Node>>& childs() const;

    protected:
    mutable std::unordered_set<Node*> parents_;
    std::vector<std::shared_ptr<Node>> childs_;
    bool caller_ = false;
};