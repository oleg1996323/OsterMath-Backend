#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>

class Array_val;
class VariableBase;
class ArithmeticTree;
class Array_t;
class Node;

#include <variant>

using Value_t = boost::multiprecision::cpp_dec_float_50;
using Bound_types = std::variant<std::monostate,Value_t, ArithmeticTree, VariableBase*>;
using Result_t = std::variant<Value_t,std::string, std::vector<std::shared_ptr<Node>>>;

#define ENUM_NAME(p) #p;



class Result:private std::variant<std::monostate,Value_t,std::string, std::vector<std::shared_ptr<Node>>>{
    using variant::variant;
    public:
    
    bool is_array() const{
        return std::holds_alternative<std::vector<std::shared_ptr<Node>>>(*this);
    }

    bool is_value() const{
        return std::holds_alternative<Value_t>(*this);
    }

    bool is_string() const{
        return std::holds_alternative<std::string>(*this);
    }

    bool has_value() const{
        return !std::holds_alternative<std::monostate>(*this);
    }
};