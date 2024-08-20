#pragma once
#include <vector>
#include <memory>
#include "def.h"
#include "node.h"

enum class FUNCTION_OP{
    LN,
    LG10,
    EXP,
    COS,
    ACOS,
    SIN,
    ASIN,
    FACTORIAL,
    LOG_BASE,
    SUM,
    PROD,
    SUMPRODUCT
};

constexpr bool ARRAY_TYPE_FUNCTION [int(FUNCTION_OP::SUMPRODUCT)+1] =
{
    /*LN*/{false},
    /*LG10*/{false},
    /*EXP*/{false},
    /*SIN*/{false},
    /*COS*/{false},
    /*ACOS*/{false},
    /*ASIN*/{false},
    /*FACTORIAL*/{false},
    /*LOG_X*/{false},
    /*SUM*/{true},
    /*PROD*/{true},
    /*SUMPRODUCT*/{true}};

//0 - if 1 or more
constexpr size_t NUMBER_OF_ARGUMENT [int(FUNCTION_OP::SUMPRODUCT)+1] = {
    /*LN*/{1},
    /*LG10*/{1},
    /*EXP*/{1},
    /*SIN*/{1},
    /*COS*/{1},
    /*ACOS*/{1},
    /*ASIN*/{1},
    /*FACTORIAL*/{1},
    /*LOG_X*/{2},
    /*SUM*/{0},
    /*PROD*/{0},
    /*SUMPRODUCT*/{0}};

class FunctionNode:public Node{
    public:
    FunctionNode(FUNCTION_OP op):
    Node((int)NUMBER_OF_ARGUMENT[(int)op]),
    operation_(op),
    array_type_function(ARRAY_TYPE_FUNCTION[int(op)])
    {
        if(array_type_function)
            throw std::runtime_error("Incorrect constructor. Prompt: function is array-type.");
        //std::cout<<(int)NUMBER_OF_ARGUMENT[(int)op]<<std::endl;
    }

    FunctionNode(FUNCTION_OP op, size_t arr_sz):
    Node(arr_sz),
    operation_(op),
    array_type_function(ARRAY_TYPE_FUNCTION[int(op)])
    {
        if(!array_type_function)
            throw std::runtime_error("Incorrect constructor. Prompt: function is not array-type.");
        //std::cout<<(int)NUMBER_OF_ARGUMENT[(int)op]<<std::endl;
    }

    std::shared_ptr<Node> child(size_t id) const;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }

    bool is_array_function() const{
        return array_type_function;
    }

    virtual void insert_back(std::shared_ptr<Node> node) override;

    //insert before value at id
    virtual void insert(int,std::shared_ptr<Node>) override;

    virtual void replace(int,std::shared_ptr<Node>) override;

    virtual Result execute() override;

    virtual Result execute(size_t index) override;

    virtual void print_text(std::ostream& stream) const override;

    virtual void print_result(std::ostream& stream) const override;

    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    FUNCTION_OP operation() const;

    private:
    
    FUNCTION_OP operation_;
    Result cache_;
    bool array_type_function;
};