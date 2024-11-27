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
    std::set<node_range_operation::VariableNodeIndex, node_range_operation::VariableNodeIndex::Comparator> var_ids_;
    mutable size_t sz_iteration = 0;
    RANGE_OP operation_;
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr):
    operation_(op){
        set_expression(expr);
    }
    
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
        insert_back(expr);
    }
    inline bool has_expression() const{
        return has_child(0) && child(0);
    }
    inline std::shared_ptr<Node> get_expression() const{
        if(has_child(0))
            return child(0);
        else return std::shared_ptr<Node>();
    }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    inline void set_variable_order(const std::shared_ptr<VariableNode>& var,size_t order){
        node_range_operation::VariableNodeIndex tmp;
        tmp.order_id.emplace(order);
        tmp.var_node = var;
        var_ids_.insert(tmp);  
    }

    inline std::optional<size_t> set_variable_order(const std::shared_ptr<VariableNode>& var){
        if(var_ids_.contains(var)){
            return var_ids_.find(var)->order_id;
        }
        return std::nullopt;
    }

    protected:
    virtual Result execute_for_array_variables(const std::vector<size_t>& through_struct) const override;
    private:
    virtual void insert_back(std::shared_ptr<Node> node) override{
        if(has_child(0))
            childs_.at(0) = node;
        else childs_.push_back(node);
        node->add_parent(this);
    }
    bool check_variables_sizes_and_define_size_iteration(size_t depth) const;
    std::set<std::shared_ptr<Node>> define_range_node_range_nodes() const;
    std::set<std::shared_ptr<VariableNode>> define_range_node_array_type_variables() const;
    std::set<std::shared_ptr<VariableNode>> define_array_type_variables() const;
};