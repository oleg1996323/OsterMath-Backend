#pragma once
#include "def.h"
#include "var_node.h"
#include "array_node.h"

enum class RANGE_OP{
    SUM,
    PROD
};

//calculate some expressions by range of input values.
//Childs should be only numeric variable-arrays and have same length
class RangeOperationNode:public Node{
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}
    template<template<typename,typename> typename... PAIRS, typename T>
    requires (std::is_same_v<std::pair<T,T>,PAIRS<T,T>> && ...)
    RangeOperationNode(RANGE_OP op, PAIRS<T,T>... args):operation_(op){}
    RangeOperationNode(const RangeOperationNode& other);
    RangeOperationNode(RangeOperationNode&&) = delete;

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::RANGEOP;
    }

    virtual Result execute() override;
    virtual Result execute(size_t index) override;
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    const std::shared_ptr<Node>& get_range_expression() const{
        return range_expression;
    }

    RANGE_OP operation() const;

    size_t range_length() const{
        return range_size;
    }

    private:

    void define_range_length();

    mutable size_t range_size = 0;
    std::shared_ptr<Node> range_expression;
    RANGE_OP operation_;
};