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

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual const Result& execute() override;

    virtual const Result& execute(size_t index) override;

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual std::ostream& print_text(std::ostream& stream) const override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    size_t range_length() const{
        return range_size;
    }

    private:

    //checks the childs types and them correct vals types
    //Childs should be only numeric variable-arrays and have same length
    bool __checking_childs__() const;

    mutable size_t range_size = 0;
    std::shared_ptr<Node> range_expression;
    RANGE_OP operation_;
    Result cache_;
};
