#pragma once
#include "nodes/def.h"
#include "def.h"
#include "abstract_node.h"
#include "range_node/def.h"
#include <unordered_set>

enum class BINARY_OP{
    ADD='+',
    SUB='-',
    MUL='*',
    DIV='/',
    POW='^'
};

#include "node_manager.h"
using namespace node_range_operation;
class BinaryNode:public AbstractNode{
    BINARY_OP operation_;
    friend UnaryNode;
    friend MultiArgumentNode;
    friend ValueNode;
    friend VariableNode;
    public:
    BinaryNode(BINARY_OP op):operation_(op){}
    BinaryNode(const BinaryNode& other):AbstractNode(other),operation_(other.operation_){
        if(this!=&other)
            rel_mng_->copy_childs(this,other.childs());
    }
    BinaryNode(BinaryNode&& other):AbstractNode(other),operation_(other.operation_){
        if(this!=&other)
            rel_mng_->swap_childs(this,&other);
    }
    ~BinaryNode();
    virtual NODE_TYPE type() const override{
        return NODE_TYPE::BINARY;
    }
    virtual Result execute() const override;

    const AbstractNode* lhs() const{
        return child(0);
    }
    const AbstractNode* rhs() const{
        return child(1);
    }

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
    virtual bool is_empty() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t& struct_) const override;
};
