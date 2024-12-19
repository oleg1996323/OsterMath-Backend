#pragma once
#include "def.h"
#include "abstract_node.h"
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

#include "node_manager.h"
using namespace node_range_operation;
class UnaryNode:public AbstractNode{
    UNARY_OP operation_;
    friend MultiArgumentNode;
    friend BinaryNode;
    friend ValueNode;
    friend VariableNode;
    public:
    UnaryNode(UNARY_OP op):operation_(op){}
    UnaryNode(const UnaryNode& other):AbstractNode(other){
        if(&other!=this){
            operation_ = other.operation_;
            rel_mng_->copy_childs(this,other.childs());
        }
    }
    UnaryNode(UnaryNode&& other):AbstractNode(other){
        if(&other!=this){
            operation_ = other.operation_;
            rel_mng_->swap_childs(this,&other);
        }
    }
    ~UnaryNode();

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::UNARY;
    }
    const std::shared_ptr<AbstractNode>& child() const{
        return childs().at(0);
    }
    //virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() const override;
    virtual Result cached_result() const override{
        if(has_child(0))
            return child()->execute();
        else throw std::runtime_error("Unexpected error: not completely identified unary node");
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual bool is_empty() const override;
    virtual TYPE_VAL type_val() const override;
    UNARY_OP operation() const;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
};
