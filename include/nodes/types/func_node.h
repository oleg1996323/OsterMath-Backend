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
    SUMPRODUCT,
    CONCAT,
    SEARCH_TEXT,
    CONTAIN_TEXT,
    WEIBULL_DIST,
    GAUSS,
    STD_NORM_DISTRIB,
    NORM_DISTRIB,
    PEARSON,
    GAMMA,
    GAMMA_REV,
    ROOT_MEAN_SQUARE,
    ROOT_MEAN_SQUARE_ERROR,
    AVERAGE,
    MEDIAN
};

constexpr bool ARRAY_TYPE_FUNCTION [int(FUNCTION_OP::MEDIAN)+1] =
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
    /*SUMPRODUCT*/{true},
    /*CONCAT*/{true},
    /*SEARCH_STRING*/{true},
    /*CONTAIN_TEXT*/{true},
    /*WEIBULL_DIST*/{false},
    /*GAUSS*/{false},
    /*STD_NORM_DISTRIB*/{false},
    /*NORM_DISTRIB*/{false},
    /*PEARSON*/{false},
    /*GAMMA*/{false},
    /*GAMMA_REV*/{false},
    /*ROOT_MEAN_SQUARE*/{true},
    /*ROOT_MEAN_SQUARE_ERROR*/{true},
    /*AVERAGE*/{true},
    /*MEDIAN*/{true}
};


//0 - if 1 or more
constexpr size_t NUMBER_OF_ARGUMENT [int(FUNCTION_OP::MEDIAN)+1] = {
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
    /*SUMPRODUCT*/{0},
    /*CONCAT*/{0},
    /*SEARCH_STRING*/{0},
    /*CONTAIN_TEXT*/{0},
    /*WEIBULL_DIST*/{4},
    /*GAUSS*/{1},
    /*STD_NORM_DISTRIB*/{2},
    /*NORM_DISTRIB*/{4},
    /*PEARSON*/{2},
    /*GAMMA*/{1},
    /*GAMMA_REV*/{3},
    /*ROOT_MEAN_SQUARE*/{0},
    /*ROOT_MEAN_SQUARE_ERROR*/{0},
    /*AVERAGE*/{0},
    /*MEDIAN*/{0}
    };


struct TYPE_ARGS{
    TYPE_ARGS(std::initializer_list<size_t> args):
    ARGS_(args){}
    const std::vector<size_t> ARGS_;
};

const std::vector<TYPE_ARGS> TYPE_OF_ARGUMENTS = {
    /*LN*/{TYPE_VAL::VALUE},
    /*LG10*/{TYPE_VAL::VALUE},
    /*EXP*/{TYPE_VAL::VALUE},
    /*SIN*/{TYPE_VAL::VALUE},
    /*COS*/{TYPE_VAL::VALUE},
    /*ACOS*/{TYPE_VAL::VALUE},
    /*ASIN*/{TYPE_VAL::VALUE},
    /*FACTORIAL*/{TYPE_VAL::VALUE},
    /*LOG_X*/{TYPE_VAL::VALUE,TYPE_VAL::VALUE},
    /*SUM*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*PROD*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*SUMPRODUCT*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*CONCAT*/{TYPE_VAL::STRING | TYPE_VAL::STRING_ARRAY},
    /*SEARCH_STRING*/{TYPE_VAL::STRING | TYPE_VAL::STRING_ARRAY},
    /*CONTAIN_TEXT*/{TYPE_VAL::STRING | TYPE_VAL::STRING_ARRAY},
    /*WEIBULL_DIST*/{TYPE_VAL::VALUE,TYPE_VAL::VALUE,TYPE_VAL::VALUE,TYPE_VAL::VALUE},
    /*GAUSS*/{TYPE_VAL::VALUE},
    /*STD_NORM_DISTRIB*/{TYPE_VAL::VALUE,TYPE_VAL::VALUE},
    /*NORM_DISTRIB*/{TYPE_VAL::VALUE,TYPE_VAL::VALUE,TYPE_VAL::VALUE,TYPE_VAL::VALUE},
    /*PEARSON*/{TYPE_VAL::NUMERIC_ARRAY,TYPE_VAL::NUMERIC_ARRAY},
    /*GAMMA*/{TYPE_VAL::VALUE},
    /*GAMMA_REV*/{TYPE_VAL::VALUE,TYPE_VAL::VALUE,TYPE_VAL::VALUE},
    /*ROOT_MEAN_SQUARE*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*ROOT_MEAN_SQUARE_ERROR*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*AVERAGE*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY},
    /*MEDIAN*/{TYPE_VAL::VALUE | TYPE_VAL::NUMERIC_ARRAY}
    };

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

    FunctionNode(const FunctionNode& other);
    FunctionNode(FunctionNode&&) = delete;

    std::shared_ptr<Node> child(size_t id) const;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::FUNCTION;
    }

    bool is_array_function() const{
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
};