#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "def.h"
#include "exception.h"
#include "data.h"
#include "types.h"
#include "arithmetic_tree.h"

using Variable = std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree>;

using namespace std::string_literals;
using namespace std::string_view_literals;

class ArithmeticTree;

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

    const Variable& get() const;
    Variable& get();

    template<typename T>
    const T& get() const;

    template<typename T>
    T& get();

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

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree);

std::ostream& operator<<(std::ostream& stream, const Array_t& arr);

std::ostream& operator<<(std::ostream& stream, std::monostate empty);

std::ostream& operator<<(std::ostream& stream, Variable var);

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

template<typename T>
T& VariableBase::get(){
    return std::get<T>(*this);
}

template<typename T>
const T& VariableBase::get() const{
    return std::get<const T>(*this);
}

template<typename T>
void VariableBase::define(T&& value){
    *this=std::forward<T>(value);
}

template<typename T>
VariableBase::VariableBase(std::string_view name, T&& value, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{
    this->emplace(std::forward<T>(value));
}