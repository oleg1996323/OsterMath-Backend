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

class Result:public Result_t{
    public:
    using variant::variant;
    
    Result_t& get();

    const Result_t& get() const;

    template<typename T>
    T& get();

    std::ostream& operator<<(std::ostream& os);

    template<typename T>
    const T& get() const;

    bool is_array() const;

    bool is_value() const;

    bool is_string() const;

    bool is_variable() const;

    bool has_value() const;

    private:
    struct ResultVisitor{
        
    };
};

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

    ProxySizeDepthMeasure& operator++();

    void push(size_t new_size);

    size_t depth();

    void reset_iterator();

    size_t current_iterator(size_t depth) const;

    bool is_iterable() const;

    size_t size(size_t depth) const;

    size_t seq_iterator(size_t depth) const;

    size_t total_size_childs() const;

    private:
    void depth(size_t& uppper_depth);

    size_t current_iterator_ref(size_t& depth) const;

    size_t size_ref(size_t& depth) const;

    size_t seq_iterator_ref(size_t& depth) const;

    ProxySizeDepthMeasure& increase_iterator();

    std::unique_ptr<ProxySizeDepthMeasure> next_level_;
    ProxySizeDepthMeasure* parent_;
    size_t sz_;
    size_t current_iterator_ = 0;
};
