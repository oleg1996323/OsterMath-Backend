#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>

class Array_val;
class VariableBase;
class ArithmeticTree;
class Array_t;

#include <variant>

using Value_t = boost::multiprecision::cpp_dec_float_50;

//needed for using variables and values in array
using Arr_value = std::variant<std::monostate,Value_t,std::string, VariableBase*, ArithmeticTree>;
using __types__ = std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree>;