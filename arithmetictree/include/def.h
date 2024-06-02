#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>

class Array_val;
class VariableBase;
class ArithmeticTree;
class Array_t;

#include <variant>

using Value_t = boost::multiprecision::cpp_dec_float_50;
using Bound_types = std::variant<std::monostate,Value_t, ArithmeticTree, VariableBase*>;
using Arr_value = std::variant<std::monostate,Value_t,std::string, VariableBase*, ArithmeticTree>;
