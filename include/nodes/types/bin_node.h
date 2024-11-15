#pragma once
#include "include/nodes/def.h"
#include "node.h"

enum class BINARY_OP{
    ADD='+',
    SUB='-',
    MUL='*',
    DIV='/',
    POW='^'
};

class BinaryNode:public Node{
    BINARY_OP operation_;
    friend UnaryNode;
    friend MultiArgumentNode;
    friend ValueNode;
    friend VariableNode;
    public:
    BinaryNode(BINARY_OP op):operation_(op){}
    BinaryNode(const BinaryNode& other);
    BinaryNode(BinaryNode&&) =delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::BINARY;
    }
    virtual Result execute() const override;
    virtual Result execute(size_t index) const override;

    std::shared_ptr<Node> lhs(){
        return child(0);
    }
    std::shared_ptr<Node> rhs(){
        return child(1);
    }
    const std::shared_ptr<Node> lhs() const {
        return child(0);
    }
    const std::shared_ptr<Node> rhs() const {
        return child(1);
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual Result cached_result() override{
        return execute();
    }
    inline virtual Result cached_result(size_t index) noexcept override{
        return execute(index);
    }

    BINARY_OP operation() const{
        return operation_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    inline bool IsError(size_t index);

    Result __calculate__() const;
    Result __calculate__(size_t index) const;
};
