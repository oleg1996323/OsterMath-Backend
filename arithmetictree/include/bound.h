#pragma once
#include <unordered_map>
#include <string_view>
#include <memory>
#include <optional>
#include "def.h"

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
    mutable std::shared_ptr<Node> value_;
    T type_;

    bool is_defined() const;

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
    
    void set_bound_value(std::shared_ptr<Node> value, BOTTOM_BOUND_T type);

    void set_bound_value(std::shared_ptr<Node> value, TOP_BOUND_T type);

    void unset_bottom_bound();

    void unset_top_bound();

    private:
    std::unique_ptr<Bound_T<BOTTOM_BOUND_T>> bottom_bound_;
    std::unique_ptr<Bound_T<TOP_BOUND_T>> top_bound_;
};