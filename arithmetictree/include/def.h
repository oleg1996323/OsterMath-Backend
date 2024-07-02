#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>

class VariableNode;
class Node;
class ArrayNode;
class VariableNode;

#include <variant>


using Value_t = boost::multiprecision::cpp_dec_float_50;
using Bound_types = std::variant<std::monostate,Node*>;
using Result_t = std::variant<std::monostate,Value_t,std::string, Node*>;

#define ENUM_NAME(p) #p;

enum TYPE_VAL{
    UNKNOWN,
    STRING_ARRAY,
    NUMERIC_ARRAY,
    VALUE,
    STRING,
    ARRAY
};

class Result:public Result_t{
    public:
    using variant::variant;
    
    Result_t& get();

    const Result_t& get() const;

    template<typename T>
    T& get();

    template<typename T>
    const T& get() const;

    std::ostream& operator<<(std::ostream& os);

    bool is_value() const;

    bool is_string() const;

    bool is_node() const;

    bool is_array() const;

    bool has_value() const;

    private:
};

std::ostream& operator<<(std::ostream& os, const Result&);

template<typename T>
T& Result::get(){
    return std::get<T>(*this);
}

template<typename T>
const T& Result::get() const{
    return std::get<T>(*this);
}

#include <memory>

class ProxySizeDepthMeasure{
    public:
    ProxySizeDepthMeasure(size_t new_size);

    ProxySizeDepthMeasure(size_t new_size, ProxySizeDepthMeasure* parent);

    bool operator++();

    void push(size_t new_size);

    size_t depth();

    void reset_iterator();

    size_t current_iterator(int32_t depth) const;

    bool is_iterable() const;

    size_t size(size_t depth) const;

    size_t seq_iterator(int32_t depth) const;

    size_t total_size_childs() const;

    private:
    void depth(size_t& uppper_depth);

    size_t current_iterator_ref(int32_t& depth) const;

    size_t size_ref(size_t& depth) const;

    size_t seq_iterator_ref(int32_t& depth) const;

    bool increase_iterator();

    std::unique_ptr<ProxySizeDepthMeasure> next_level_;
    ProxySizeDepthMeasure* parent_;
    size_t sz_;
    mutable size_t total_childs_ = 0;
    size_t current_iterator_ = 0;
};
