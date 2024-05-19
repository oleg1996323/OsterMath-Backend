#pragma once
#include <unordered_map>
#include <string_view>
#include <memory>
#include "arithmetic_tree.h"
#include "def.h"

using Bound_types = std::variant<std::monostate,Value_t, ArithmeticTree, VariableBase*>;

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
    mutable Bound_types value_ = 0;
    T type_;

    bool is_expression() const;

    bool is_value() const;

    bool is_variable() const;

    Value_t get() const;
};

class VariableBounds{
    public:
    std::optional<Value_t> get_bottom_bound_value() const;

    std::optional<Value_t> get_top_bound_value() const;

    bool is_in_bounds(Value_t&&) const;

    bool is_in_bounds(const Value_t&) const;

    bool is_in_bounds(const VariableBase&) const;

    bool is_in_bounds(const ArithmeticTree&) const;
    
    template<typename T>
    void set_bound_value(T&& value, BOTTOM_BOUND_T type);

    template<typename T>
    void set_bound_value(T&& value, TOP_BOUND_T type);

    void unset_bottom_bound();

    void unset_top_bound();

    private:
    std::unique_ptr<Bound_T<BOTTOM_BOUND_T>> bottom_bound_;
    std::unique_ptr<Bound_T<TOP_BOUND_T>> top_bound_;
};

template<typename T>
void VariableBounds::set_bound_value(T&& value, BOTTOM_BOUND_T type){
    if(bottom_bound_){
        bottom_bound_->type_=type;
        bottom_bound_->value_=std::forward<T>(value);
    }
    else {
        bottom_bound_ = std::make_unique<Bound_T<BOTTOM_BOUND_T>>();
        bottom_bound_->type_=type;
        bottom_bound_->value_=std::forward<T>(value);
    }
}

template<typename T>
void VariableBounds::set_bound_value(T&& value, TOP_BOUND_T type){
    if(top_bound_){
        top_bound_->type_=type;
        top_bound_->value_=std::forward<T>(value);
    }
    else {
        top_bound_ = std::make_unique<Bound_T<TOP_BOUND_T>>();
        top_bound_->type_=type;
        top_bound_->value_=std::forward<T>(value);
    }
}