#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>
#include <def.h>
#include <optional>
#include "events_errors/exception.h"
#include <execution>
#include <boost/math/statistics/linear_regression.hpp>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        void init_sz_depth_measure(std::vector<size_t>& sz_depth_measure, ArrayNode* array);
        bool check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays);
        TYPE_VAL getting_arrays_type(const std::vector<ArrayNode*>& arrays);

        bool arrays_numeric(const std::vector<ArrayNode*>& arrays);
        bool arrays_string(const std::vector<ArrayNode*>& arrays);
    }

    namespace Arithmetic{
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays);

        //calculate the summ of production till the defined dimension.
        //For example, if the array present a cubic dimention data for the dimensions = 2 there will be 
        //calculated only the square base of these array. Althought the calculation may depends of arrays order.
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays, size_t dimensions);

        
        Value_t Sum(const std::vector<ArrayNode*>& arrays);
        Value_t Product(const std::vector<ArrayNode*>& arrays);

        template<typename ExecutionPolicy>
        Value_t CorrelationCoefficient(ExecutionPolicy&& exec,const ArrayNode* arr_1, const ArrayNode* arr_2);
        Value_t CorrelationCoefficient(const ArrayNode*, const ArrayNode*);

        size_t pow(size_t base, size_t pow);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}

#include "correlation.h"
#include "array_node.h"

template<typename ExecutionPolicy>
Value_t functions::Arithmetic::CorrelationCoefficient(ExecutionPolicy&& exec,const ArrayNode* arr_1, const ArrayNode* arr_2){
    CovariationMatrix((*arr_1),(*arr_2));
    if(arr_1->is_numeric() && arr_2->is_numeric()){
        if constexpr (std::is_same_v<std::remove_reference_t<decltype(exec)>, decltype(std::execution::seq)>){
            
        }
        else{
            
        }
    }
}