#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "data.h"
#include "def.h"
#include "exception.h"
#include "arithmetic_tree.h"

class ArithmeticTree;
class Node;

using namespace std::string_literals;
using namespace std::string_view_literals;

struct VariableVisitor{
    void operator()(std::monostate) const{
        throw std::runtime_error("Undefined variable");
    }

    const Value_t& operator()(const Value_t& value) const{
        return value;
    }

    const Array_t& operator()(const Array_t& array) const{
        return array;
    }

    const std::string& operator()(const std::string& string) const{
        return string;
    }

    const ArithmeticTree& operator()(const ArithmeticTree& tree) const{
        return tree;
    }
};

using Variable = std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree>;

std::ostream& operator<<(std::ostream& stream, Variable);

class VariableBase: private Variable {
    using variant::variant;

    public:
    struct HashVar{
        size_t operator()(const VariableBase& var);
    };
    virtual ~VariableBase(){}
    explicit VariableBase(std::string_view name, BaseData* data_base);

    template<typename T>
    VariableBase(std::string_view name, T&& value, BaseData* data_base);

    template<typename T>
    void define(T&& value);

    std::string_view name() const;
    void refresh() const;

    const variant& get() const;
    variant& get();
    bool is_arithmetic_tree() const;
    bool is_value() const;
    bool is_string() const;
    bool is_array() const;

    protected:
    void set_data_base(BaseData* data_pool);
    BaseData* get_data_base() const;

    private:
    Node* node_;
    std::string_view name_;
    BaseData* data_base_;
};