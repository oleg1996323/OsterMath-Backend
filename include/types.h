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

class VariableBase: private std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree> {
    using variant::variant;

    public:
    struct HashVar{
        size_t operator()(const VariableBase& var);
    };
    virtual ~VariableBase(){}
    explicit VariableBase(std::string_view name, BaseData* data_base);

    template<typename T>
    VariableBase(std::string_view name, T&& value, BaseData* data_base);

    std::string_view GetName() const;
    void Refresh() const;

    template<typename T>
    const T& get() const;
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