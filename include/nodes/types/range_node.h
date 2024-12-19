#pragma once
#include "def.h"
#include "var_node.h"
#include "array_node.h"
#include "range_node/def.h"
#include "node_manager.h"

enum class RANGE_OP{
    SUM,
    PROD
};

#include "aux_functions.h"
using namespace node_range_operation;
//calculate some expressions by range of input values.
//Childs should be only numeric variable-arrays and have same length
class RangeOperationNode:public AbstractNode{
    mutable Result cache_;
    mutable std::unordered_map<const VariableNode*,std::optional<size_t>> var_ids_;
    mutable size_t sz_iteration = 0;
    RANGE_OP operation_;
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    RangeOperationNode(RANGE_OP op, std::shared_ptr<AbstractNode> expr):
    operation_(op){
        set_expression(expr);
    }

    RangeOperationNode(const RangeOperationNode& other);
    RangeOperationNode(RangeOperationNode&&) = delete;
    ~RangeOperationNode(){
        rel_mng_->delete_node(this);
    }

    virtual NODE_TYPE type() const override{
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
    virtual bool is_empty() const override;
    inline void set_expression(std::shared_ptr<AbstractNode> expr){
        insert_back(expr);
    }
    inline bool has_expression() const{
        return has_child(0) && child(0);
    }
    inline std::shared_ptr<AbstractNode> get_expression() const{
        if(has_child(0))
            return child(0);
        else return std::shared_ptr<AbstractNode>();
    }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    inline void set_variable_order(const std::shared_ptr<VariableNode>& var,size_t order){
        var_ids_[var.get()].emplace(order);  
    }

    inline std::optional<size_t> set_variable_order(const std::shared_ptr<VariableNode>& var){
        if(var_ids_.contains(var.get())){
            return var_ids_.at(var.get());
        }
        return std::nullopt;
    }

    protected:
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const override;
    private:
    // virtual void insert_back(std::shared_ptr<Node> node) override{
    //     if(has_child(0))
    //         rel_mng_->child(this,0) = node;
    //     else rel_mng_->insert_back(this,node);
    //     rel_mng_->add_parent(node.get(),this, childs().size()-1);
    // }
    bool check_variables_sizes_and_define_size_iteration(size_t, 
                execute_for_array_variables_t&) const;
    std::set<std::shared_ptr<AbstractNode>> define_range_node_range_nodes() const;
    std::set<std::shared_ptr<VariableNode>> define_range_node_array_type_variables() const;
    std::set<std::shared_ptr<VariableNode>> define_array_type_variables() const;
};