#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <list>
#include "types.h"

bool checking_egal_size_arrays(std::vector<std::reference_wrapper<const Array_t>>& arrays);

Array_t::TYPE getting_arrays_type(std::vector<std::reference_wrapper<const Array_t>>& arrays);

Value_t SumProduct(std::vector<std::reference_wrapper<const Array_t>>&& arrays);

