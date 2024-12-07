#pragma once
#include "nodes/def.h"
#include "node.h"
#include "range_node/def.h"
#include <unordered_set>

enum class BINARY_OP{
    ADD='+',
    SUB='-',
    MUL='*',
    DIV='/',
    POW='^'
};

using namespace node_range_operation;
class BinaryNode:public Node{
    BINARY_OP operation_;
    friend UnaryNode;
    friend MultiArgumentNode;
    friend ValueNode;
    friend VariableNode;
    public:
    BinaryNode(BINARY_OP op):operation_(op){}

    template<typename T>
    inline BinaryNode(const T& other):Node(other),operation_(other.operation_){
        *this = Node::operator=(other);
    }
    BinaryNode(const BinaryNode& other);
    BinaryNode(BinaryNode&&) =delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::BINARY;
    }
    virtual Result execute() const override;

    std::shared_ptr<Node> lhs() const{
        return child(0);
    }
    std::shared_ptr<Node> rhs() const{
        return child(1);
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual Result cached_result() const override{
        return execute();
    }
    virtual TYPE_VAL type_val() const override;
    BINARY_OP operation() const{
        return operation_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t& struct_) const override;
};
