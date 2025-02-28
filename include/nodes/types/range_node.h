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
    RangeOperationNode(RANGE_OP op,NodeManager* mng):
    AbstractNode(mng),
    operation_(op){}

    template<typename T,typename... ARGS>
    RangeOperationNode(RANGE_OP op, ARGS&&... expr,NodeManager* mng):
    AbstractNode(mng),
    operation_(op){
        set_expression<T>(std::forward<ARGS>(expr)...);
    }

    RangeOperationNode(RANGE_OP op, AbstractNode* expr,NodeManager* mng):
    AbstractNode(mng),
    operation_(op){
        set_expression(expr);
    }

    RangeOperationNode(const RangeOperationNode& other,NodeManager* mng);
    RangeOperationNode(RangeOperationNode&&) = delete;
    ~RangeOperationNode();

    virtual NODE_TYPE type() const override;

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
    template<typename T,typename... ARGS>
    inline T* set_expression(ARGS&&... args){
        return insert_back<T>(std::forward<ARGS>(args)...);
    }
    inline AbstractNode* set_expression(AbstractNode* expr){
        return insert_back_ref(expr);
    }
    inline bool has_expression() const{
        return has_child(0) && child(0);
    }
    inline const AbstractNode* get_expression() const{
        if(has_child(0))
            return child(0);
        else return nullptr;
    }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    inline void set_variable_order(const VariableNode* var,size_t order){
        var_ids_[var].emplace(order);  
    }

    inline std::optional<size_t> set_variable_order(const VariableNode* var){
        if(var_ids_.contains(var)){
            return var_ids_.at(var);
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
    std::set<const AbstractNode*> define_range_node_range_nodes() const;
    std::set<const VariableNode*> define_range_node_array_type_variables() const;
    std::set<const VariableNode*> define_array_type_variables() const;
};