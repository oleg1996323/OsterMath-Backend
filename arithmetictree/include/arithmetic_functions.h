#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "types.h"

bool Checking_Egal_Size_Arrays(std::initializer_list<const Array_t>& arrays);

Value_t SumProduct(std::initializer_list<const Array_t>& arrays);