#pragma once
#include <vector>
#include <memory>
#include "def.h"
#include "node.h"
#include "function_node/def.h"


class FunctionNode:public Node{
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
    std::shared_ptr<Node> child(size_t id) const;
    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }
    inline bool is_array_function() const{
        return array_type_function;
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual Result execute() override;
    virtual Result execute(size_t index) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    FUNCTION_OP operation() const;
    private:
    FUNCTION_OP operation_;
    Result cache_;
    bool array_type_function;

    Result __multiargument_numeric_case__();
    Result __fixed_size_case__();
    std::vector<ArrayNode*> __get_vector_of_arrays__();
};