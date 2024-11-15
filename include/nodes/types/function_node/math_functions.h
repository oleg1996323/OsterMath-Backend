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
class FunctionNode;

namespace node_function::functions{
    namespace math{
        Result SumProduct(const FunctionNode*);

        //calculate the summ of production till the defined dimension.
        //For example, if the array present a cubic dimention data for the dimensions = 2 there will be 
        //calculated only the square base of these array. Althought the calculation may depends of arrays order.
        Result SumProduct(const FunctionNode*, size_t dimensions);
        Result Sum(const FunctionNode*);
        Result Product(const FunctionNode*);

        template<typename ExecutionPolicy>
        Result CorrelationCoefficient(ExecutionPolicy&& exec,
                                    const std::shared_ptr<ArrayNode>&, 
                                    const std::shared_ptr<ArrayNode>&);
        Result CorrelationCoefficient(const std::shared_ptr<ArrayNode>&,
                                    const std::shared_ptr<ArrayNode>&);
        size_t pow(size_t base, size_t pow);

#include "correlation.h"
#include "array_node.h"

        
    }
}

template<typename ExecutionPolicy>
Result node_function::functions::math::CorrelationCoefficient(ExecutionPolicy&& exec,const std::shared_ptr<ArrayNode>& arr_1, 
        const std::shared_ptr<ArrayNode>& arr_2){
    CovariationMatrix((*arr_1),(*arr_2));
    if(arr_1->is_numeric() && arr_2->is_numeric()){
        if constexpr (std::is_same_v<std::remove_reference_t<decltype(exec)>, decltype(std::execution::seq)>){
            
        }
        else{
            
        }
    }
}