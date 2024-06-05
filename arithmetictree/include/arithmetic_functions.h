#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>
#include <def.h>
#include <optional>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        std::optional<std::invalid_argument> check_sizes_arrays(std::vector<size_t>& sz_depth_measure,std::vector<std::shared_ptr<ArrayNode>>& arrays);
        TYPE_VAL getting_arrays_type(std::vector<std::shared_ptr<ArrayNode>>& arrays);

        std::optional<std::invalid_argument> arrays_numeric(std::vector<std::shared_ptr<ArrayNode>>& arrays);
        std::optional<std::invalid_argument> arrays_string(std::vector<std::shared_ptr<ArrayNode>>& arrays);
    }

    namespace Arithmetic{
        Value_t SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays);

        //calculate the summ of production till the defined dimension.
        //For example, if the array present a cubic dimention data for the dimensions = 2 there will be 
        //calculated only the square base of these array. Althought the calculation may depends of arrays order.
        Value_t SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays, size_t dimensions);

        
        Value_t Sum(std::vector<std::shared_ptr<ArrayNode>>&& arrays);
        Value_t Product(std::vector<std::shared_ptr<ArrayNode>>&& arrays);

        size_t pow(size_t base, size_t pow);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}