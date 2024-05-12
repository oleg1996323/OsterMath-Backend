#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include <types.h>

namespace functions{
    namespace auxiliary{
        bool checking_egal_size_arrays(std::vector<std::reference_wrapper<const Array_t>>& arrays);

        TYPE getting_arrays_type(std::vector<std::reference_wrapper<const Array_t>>& arrays);

    }

    namespace Arithmetic{
        Value_t SumProduct(std::vector<std::reference_wrapper<const Array_t>>&& arrays);
        Value_t Sum(std::vector<std::reference_wrapper<const Array_t>>&& arrays);
        Value_t Product(std::vector<std::reference_wrapper<const Array_t>>&& arrays);
        bool checking(std::vector<std::reference_wrapper<const Array_t>>& arrays);

        namespace Ranges{
            Value_t SumProduct();
            Value_t Sum();
            Value_t Product();
            bool checking();
        }
    }

}