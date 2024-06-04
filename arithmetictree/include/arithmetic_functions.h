#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>
#include <def.h>

class ArrayNode;

namespace functions{
    namespace auxiliary{
        bool checking_egal_size_arrays(std::vector<std::shared_ptr<ArrayNode>>& arrays);
        TYPE_VAL getting_arrays_type(std::vector<std::shared_ptr<ArrayNode>>& arrays);
    }

    namespace Arithmetic{
        Value_t SumProduct(std::vector<std::shared_ptr<ArrayNode>>&& arrays);
        Value_t Sum(std::vector<std::shared_ptr<ArrayNode>>&& arrays);
        Value_t Product(std::vector<std::shared_ptr<ArrayNode>>&& arrays);
        bool checking(std::vector<std::shared_ptr<ArrayNode>>& arrays);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}