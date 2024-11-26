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
    std::shared_ptr<Node> range_expression;
    mutable size_t sz_iteration = 0;
    RANGE_OP operation_;
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr):
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
    inline void set_expression(std::shared_ptr<Node> expr){
        range_expression = expr;
    }
    inline std::shared_ptr<Node> get_expression() const{
        return range_expression;
    }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    protected:
    virtual Result execute_for_array_variables(const std::vector<size_t>& through_struct) const override;
    private:
    virtual void insert_back(std::shared_ptr<Node> node) override{
        range_expression = node;
        node->add_parent(this);
    }
    bool check_variables_sizes_and_define_size_iteration(size_t depth) const;
    std::set<std::shared_ptr<Node>> define_range_node_range_nodes() const;
    std::set<std::shared_ptr<VariableNode>> define_range_node_array_type_variables() const;
    std::set<std::shared_ptr<VariableNode>> define_array_type_variables() const;
};