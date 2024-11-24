#pragma once
#include "def.h"
#include "var_node.h"
#include "array_node.h"
#include "range_node/def.h"

enum class RANGE_OP{
    SUM,
    PROD
};

#include "aux_functions.h"
//calculate some expressions by range of input values.
//Childs should be only numeric variable-arrays and have same length
class RangeOperationNode:public Node{
    mutable Result cache_;
    std::set<VariableNodeIndexInRangeOperation,VariableNodeIndexInRangeOperation::Comparator> vars_;
    std::shared_ptr<Node> range_expression;
    RANGE_OP operation_;
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr,
        const std::set<VariableNodeIndexInRangeOperation,VariableNodeIndexInRangeOperation::Comparator>& args = {}):
    vars_(args),
    range_expression(expr),
    operation_(op){
        std::set<std::shared_ptr<VariableNode>> nodes = range_expression->refer_to_vars();
        if(args.size()!=nodes.size())
            cache_ = std::make_shared<exceptions::InvalidNumberOfArguments>(nodes.size());
    }

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr,
        std::set<VariableNodeIndexInRangeOperation,VariableNodeIndexInRangeOperation::Comparator>&& args):
    vars_(std::move(args)),
    range_expression(expr),
    operation_(op){}
    
    RangeOperationNode(const RangeOperationNode& other);
    RangeOperationNode(RangeOperationNode&&) = delete;

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::RANGEOP;
    }

    virtual Result execute() const override;
    inline virtual Result cached_result() const override{
        return cache_;
    }
    
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    void set_expression(std::shared_ptr<Node> expr){
        range_expression = expr;
    }
    std::shared_ptr<Node> get_expression() const{
        return range_expression;
    }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    protected:

    virtual Result execute_for_array_variables(const RangeNodeExecuteStruct& through_struct) const override;
    private:
    virtual void insert_back(std::shared_ptr<Node> node) override{
        range_expression = node;
        node->add_parent(this);
    }
    std::set<std::shared_ptr<VariableNode>> define_range_node_variables() const;
    
};