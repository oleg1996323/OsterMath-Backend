#pragma once
#include <vector>
#include <memory>
#include "def.h"
#include "node.h"
#include "function_node/def.h"
#include "range_node/def.h"

using namespace node_range_operation;
class FunctionNode:public Node{
    mutable Result cache_;
    FUNCTION_OP operation_;
    bool array_type_function;
    public:
    inline FunctionNode(FUNCTION_OP op):
    Node((int)NUMBER_OF_ARGUMENT[(int)op]),
    operation_(op),
    array_type_function(ARRAY_TYPE_FUNCTION[int(op)])
    {
        if(array_type_function)
            throw std::runtime_error("Incorrect constructor. Prompt: function is array-type.");
        //std::cout<<(int)NUMBER_OF_ARGUMENT[(int)op]<<std::endl;
    }
    inline FunctionNode(FUNCTION_OP op, size_t arr_sz):
    Node(arr_sz),
    operation_(op),
    array_type_function(ARRAY_TYPE_FUNCTION[int(op)])
    {
        if(!array_type_function)
            throw std::runtime_error("Incorrect constructor. Prompt: function is not array-type.");
        //std::cout<<(int)NUMBER_OF_ARGUMENT[(int)op]<<std::endl;
    }
    FunctionNode(const FunctionNode& other);
    FunctionNode(FunctionNode&&) = delete;
    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }
    inline bool is_array_function() const{
        return array_type_function;
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    inline virtual Result cached_result() const override{
        return cache_;
    }
    FUNCTION_OP operation() const;
    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }
    private:
    inline virtual Result execute_for_array_variables(const std::vector<size_t>&,
                                const std::set<ThroughVarStruct,ThroughVarStruct::Comparator>&) const override{
        return execute();
    }
};