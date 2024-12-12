#pragma once
#include "def.h"
#include "node.h"
#include "range_node/def.h"
#include <unordered_set>

enum class UNARY_OP{
    NOTHING,
    ADD,
    SUB,
    PARENS
};

class MultiArgumentNode;
class BinaryNode;
class ValueNode;
class VariableNode;

using namespace node_range_operation;
class UnaryNode:public Node{
    UNARY_OP operation_;
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP op):operation_(op){}
    inline UnaryNode(const UnaryNode& other):Node(other){
        operation_ = other.operation_;
    }
    inline UnaryNode(UnaryNode&& other):Node(other){
        operation_ = other.operation_;
    }

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::UNARY;
    }
    inline const std::shared_ptr<Node>& child() const{
        return childs().at(0);
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual TYPE_VAL type_val() const override;
    UNARY_OP operation() const;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
};
