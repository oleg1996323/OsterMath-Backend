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
    mutable Result cache_;
    std::vector<VariableNode*> vars_;
    std::shared_ptr<Node> range_expression;
    RANGE_OP operation_;
    public:
    RangeOperationNode(RANGE_OP op):operation_(op){}

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr,const std::vector<VariableNode*>& args):
    vars_(args),
    range_expression(expr),
    operation_(op){
        std::set<VariableNode*> nodes = range_expression->refer_to_vars();
        if(args.size()!=nodes.size())
            cache_ = std::make_shared<exceptions::InvalidNumberOfArguments>(nodes.size());
    }

    RangeOperationNode(RANGE_OP op, std::shared_ptr<Node> expr,std::vector<VariableNode*>&& args):
    vars_(std::move(args)),
    range_expression(expr),
    operation_(op){}
    
    RangeOperationNode(const RangeOperationNode& other);
    RangeOperationNode(RangeOperationNode&&) = delete;

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::RANGEOP;
    }

    virtual Result execute() const override;
    virtual Result execute(size_t index) const override;
    inline virtual Result cached_result() override{
        return cache_;
    }
    inline virtual Result cached_result(size_t index){
        return cache_;
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    // const std::shared_ptr<Node>& get_range_expression() const{
    //     return range_expression;
    // }

    RANGE_OP operation() const;

    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }

    private:

    //void define_range_length() const;
};