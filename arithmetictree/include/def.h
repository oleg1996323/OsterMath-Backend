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

#include <optional>

class ProxySizeDepthMeasure{
    public:
    ProxySizeDepthMeasure(size_t new_size):
        sz_(new_size),
        parent_(nullptr){
        
    }

    void operator++(){
        if(next_level_.has_value())
            ++next_level_;
        else increase_iterator();
    }

    void push(size_t new_size){
        if(next_level_.has_value())
            next_level_->push(new_size);
        else next_level_.emplace(new_size,this);
    }

    size_t depth(){
        size_t depth = 1;
        if(next_level_.has_value())
            next_level_->depth(depth);
        return depth; 
    }

    void reset_iterator(){
        current_iterator = 0;
        if(next_level_.has_value())
            next_level_->reset_iterator();
    }

    size_t current_iterator() const{
        return current_iterator_;
    }

    private:
    ProxySizeDepthMeasure(size_t new_size, ProxySizeDepthMeasure* parent):
        sz_(new_size),
        parent_(parent){}


    void depth(size_t& uppper_sz){
        ++uppper_sz;
        if(next_level.has_value())
            depth(uppper_sz);
        else return;
    }

    void increase_iterator(){
        if(current_iterator_<sz_-1)
            ++current_iterator_;
        else {
            current_iterator_ = 0;
            if(parent_)
                parent_->increase_iterator();
        }
    }

    std::optional<ProxySizeDepthMeasure> next_level_;
    ProxySizeDepthMeasure* parent_;
    size_t sz_;
    size_t current_iterator_ = 0;
}