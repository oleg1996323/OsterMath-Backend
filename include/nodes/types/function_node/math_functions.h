#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/statistics/linear_regression.hpp>
#include <optional>
#include <execution>
#include "include/nodes/def.h"
#include "events_errors/exception.h"
#include "types.h"
#include "aux_functions.h"

class ArrayNode;

namespace node_function::functions{
    namespace math{
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

#include "correlation.h"
#include "array_node.h"

        template<typename ExecutionPolicy>
        Value_t CorrelationCoefficient(ExecutionPolicy&& exec,const ArrayNode* arr_1, const ArrayNode* arr_2){
            CovariationMatrix((*arr_1),(*arr_2));
            if(arr_1->is_numeric() && arr_2->is_numeric()){
                if constexpr (std::is_same_v<std::remove_reference_t<decltype(exec)>, decltype(std::execution::seq)>){
                    
                }
                else{
                    
                }
            }
        }
    }
}