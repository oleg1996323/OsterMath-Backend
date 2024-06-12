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

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::RANGEOP;
    }

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual void print_text(std::ostream& stream) const override;

    virtual void print_result(std::ostream& stream) const override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    RANGE_OP operation() const;

    size_t range_length() const{
        return range_size;
    }

    private:

    void define_range_length();

    mutable size_t range_size = 0;
    std::shared_ptr<Node> range_expression;
    RANGE_OP operation_;
    Result cache_;
};