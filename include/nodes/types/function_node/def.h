#pragma once
#include <vector>
#include "include/nodes/def.h"

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
constexpr int NUMBER_OF_ARGUMENT [int(FUNCTION_OP::MEDIAN)+1] = {
    /*LN*/{1},
    /*LG10*/{1},
    /*EXP*/{1},
    /*SIN*/{1},
    /*COS*/{1},
    /*ACOS*/{1},
    /*ASIN*/{1},
    /*FACTORIAL*/{1},
    /*LOG_X*/{2},
    /*SUM*/{-1},
    /*PROD*/{-1},
    /*SUMPRODUCT*/{-1},
    /*CONCAT*/{-1},
    /*SEARCH_STRING*/{-1},
    /*CONTAIN_TEXT*/{-1},
    /*WEIBULL_DIST*/{4},
    /*GAUSS*/{1},
    /*STD_NORM_DISTRIB*/{2},
    /*NORM_DISTRIB*/{4},
    /*PEARSON*/{2},
    /*GAMMA*/{1},
    /*GAMMA_REV*/{3},
    /*ROOT_MEAN_SQUARE*/{-1},
    /*ROOT_MEAN_SQUARE_ERROR*/{-1},
    /*AVERAGE*/{-1},
    /*MEDIAN*/{-1}
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