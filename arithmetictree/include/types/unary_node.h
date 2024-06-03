#pragma once
#include "def.h"
#include "node.h"

enum class UNARY_OP{
    ADD,
    SUB,
    PARENS
};

class UnaryNode:public Node{
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP op):operation(op){}

    virtual Node* first_undefined_child_node() override;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::UNARY;
    }

    std::shared_ptr<Node>& child(){
        return childs_.at(0);
    }

    const std::shared_ptr<Node>& child() const{
        return childs_.at(0);
    }

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void serialize(std::ostream& stream) override{

    }

    virtual void deserialize(std::ostream& stream) override{

    }

    #ifdef DEBUG
    virtual void print() const;
    #endif

    private:
    Result __calculate__();
    UNARY_OP operation;
};