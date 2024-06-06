#pragma once
#include "def.h"
#include "node.h"

enum class UNARY_OP{
    ADD,
    SUB,
    PARENS
};

class MultiArgumentNode;
class BinaryNode;
class ValueNode;
class VariableNode;

class UnaryNode:public Node{
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP op):operation_(op){}

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

    virtual void printText() const;

    virtual std::ostream& operator<<(std::ostream& stream) override{
        if(operation_==UNARY_OP::ADD)
            stream<<"+"<<childs_.at(0);
        else if(operation_==UNARY_OP::SUB)
            stream<<"-"<<childs_.at(0);
        else if(operation_==UNARY_OP::PARENS)
            stream<<"("<<childs_.at(0)<<")";
        else stream<<"";
        return stream;
    }

    private:
    Result __calculate__();
    UNARY_OP operation_;
};
