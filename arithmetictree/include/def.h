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

#include <unordered_map>
#include <string_view>

enum class BOTTOM_BOUND_T{
    LARGER_OR_EQUAL,
    LARGER
};

enum class TOP_BOUND_T{
    LESS,
    LESS_OR_EQUAL,
};

template<typename T>
struct Bound_T{
    Value_t value_;
    T type_;
};

class VariableBounds{
    public:
    const Value_t& get_bottom_bound_value() const{
        return bottom_bound_.value_;
    }

    const Value_t& get_top_bound_value() const{
        return top_bound_.value_;
    }

    bool is_in_bounds(Value_t&& value) const{
        if(bottom_bound_.type_==BOTTOM_BOUND_T::LARGER)
            if(top_bound_.type_==TOP_BOUND_T::LESS)
                return bottom_bound_.value_<value && top_bound_.value_>value;
            else return bottom_bound_.value_<value && top_bound_.value_>=value;
        else
            if(top_bound_.type_==TOP_BOUND_T::LESS)
                return bottom_bound_.value_<=value && top_bound_.value_>value;
            else return bottom_bound_.value_<=value && top_bound_.value_>=value;
    }

    void set_bottom_bound_value(Value_t&& value, BOTTOM_BOUND_T type){
        bottom_bound_.type_=type;
        bottom_bound_.value_=value;
    }

    void set_top_bound_value(Value_t&& value, TOP_BOUND_T type){
        top_bound_.type_=type;
        top_bound_.value_=value;
    }

    void set_bottom_bound_value(const Value_t& value, BOTTOM_BOUND_T type){
        bottom_bound_.type_=type;
        bottom_bound_.value_=value;
    }

    void set_top_bound_value(const Value_t& value, TOP_BOUND_T type){
        top_bound_.type_=type;
        top_bound_.value_=value;
    }

    private:
    Bound_T<BOTTOM_BOUND_T> bottom_bound_;
    Bound_T<TOP_BOUND_T> top_bound_;
};