#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>

class VariableNode;
class ExpressionNode;
class Node;
class ArrayNode;
class VariableNode;

#include <variant>


using Value_t = boost::multiprecision::cpp_dec_float_50;
using Bound_types = std::variant<std::monostate,Value_t, std::shared_ptr<ExpressionNode>, std::shared_ptr<VariableNode>>;
using Result_t = std::variant<std::monostate,Value_t, std::string, std::shared_ptr<ArrayNode>, std::shared_ptr<VariableNode>>;

#define ENUM_NAME(p) #p;

enum class TYPE_VAL{
    UNKNOWN,
    STRING,
    NUMERIC
};

class Result:private Result_t{
    public:
    using variant::variant;
    
    Result_t& get();

    const Result_t& get() const;

    template<typename T>
    T& get();

    template<typename T>
    const T& get() const;

    bool is_array() const;

    bool is_value() const;

    bool is_string() const;

    bool is_variable() const;

    bool has_value() const;    
};

template<typename T>
T& Result::get(){
    return std::get<T>(*this);
}

template<typename T>
const T& Result::get() const{
    return std::get<T>(*this);
}