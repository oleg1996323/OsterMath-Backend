#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>
#include <def.h>
#include <optional>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        std::optional<std::invalid_argument> check_sizes_arrays(std::vector<size_t>& sz_depth_measure,const std::vector<ArrayNode*>& arrays);
        TYPE_VAL getting_arrays_type(const std::vector<ArrayNode*>& arrays);

        std::optional<std::invalid_argument> arrays_numeric(const std::vector<ArrayNode*>& arrays);
        std::optional<std::invalid_argument> arrays_string(const std::vector<ArrayNode*>& arrays);
    }

    namespace Arithmetic{
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays);

        //calculate the summ of production till the defined dimension.
        //For example, if the array present a cubic dimention data for the dimensions = 2 there will be 
        //calculated only the square base of these array. Althought the calculation may depends of arrays order.
        Value_t SumProduct(const std::vector<ArrayNode*>& arrays, size_t dimensions);

        
        Value_t Sum(const std::vector<ArrayNode*>& arrays);
        Value_t Product(const std::vector<ArrayNode*>& arrays);

        size_t pow(size_t base, size_t pow);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}