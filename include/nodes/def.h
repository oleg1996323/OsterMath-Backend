#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <events_errors/exception.h>
#include <events_errors/warning.h>
#include <memory>

class VariableNode;
class Node;
class ArrayNode;
class VariableNode;
class AbstractEvent;

#include <variant>

using Value_t = boost::multiprecision::cpp_dec_float_50;//boost::multiprecision::number<boost::multiprecision::cpp_dec_float<10>>;
using Bound_types = std::variant<std::monostate,Node*>;
using Result_t = std::variant<std::monostate,std::string,std::shared_ptr<ArrayNode>, const Node*, std::shared_ptr<AbstractEvent>,Value_t>;

#define ENUM_NAME(p) #p;

enum TYPE_VAL{
    UNKNOWN = 0x00,
    VALUE = 0x01,
    STRING = 0x04,
    ARRAY = 0x08,
    STRING_ARRAY = ARRAY | STRING,
    NUMERIC_ARRAY = ARRAY | VALUE
};

TYPE_VAL operator|(TYPE_VAL lhs,TYPE_VAL rhs);

constexpr const char* NAMES_OF_ARGUMENT[6] = {
    {"Unknown"},
    {"Value"},
    {"String"},
    {"Array"},
    {"String array"},
    {"Numeric array"}
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

    std::ostream& operator<<(std::ostream& os) const;

    bool is_value() const;
    bool is_string() const;
    bool is_node() const;
    bool is_array() const;
    bool has_value() const;
    bool is_event() const;
    bool is_error() const;
    bool is_warning() const;
    bool is_array_result() const;

    Result operator+(const Result& other);
    Result operator-(const Result& other);
    Result operator*(const Result& other);
    Result operator/(const Result& other);
    Result operator^(const Result& other);

    Result& operator+=(const Result& other);
    Result& operator-=(const Result& other);
    Result& operator*=(const Result& other);
    Result& operator/=(const Result& other);
    Result& operator^=(const Result& other);

    inline Value_t get_value() noexcept{
        return get<Value_t>();
    }
    inline std::string get_string() noexcept{
        return get<std::string>();
    }
    inline std::shared_ptr<AbstractEvent> get_event() const noexcept{
        return get<std::shared_ptr<AbstractEvent>>();
    }
    inline std::shared_ptr<exceptions::Exception> get_exception() const noexcept{
        return std::dynamic_pointer_cast<exceptions::Exception>(get<std::shared_ptr<AbstractEvent>>());
    }
    inline std::shared_ptr<warnings::Warning> get_warning() const noexcept{
        return std::dynamic_pointer_cast<warnings::Warning>(get<std::shared_ptr<AbstractEvent>>());
    }
    inline const Node* get_node() noexcept{
        return get<const Node*>();
    }
    inline const ArrayNode* get_array_node() noexcept{
        return reinterpret_cast<const ArrayNode*>(get<const Node*>());
    }
    inline const Value_t& get_value() const noexcept{
        return get<Value_t>();
    }
    inline const std::string& get_string() const noexcept{
        return get<std::string>();
    }
    inline const Node* get_node() const noexcept{
        return get<const Node*>();
    }
    inline const ArrayNode* get_array_node() const noexcept{
        return reinterpret_cast<const ArrayNode*>(get<const Node*>());
    }
    inline std::shared_ptr<ArrayNode> get_array_result() const noexcept{
        return get<std::shared_ptr<ArrayNode>>();
    }
    private:
};

bool operator==(const Value_t& val, const Result& res);
bool operator==(const Result& res,const Value_t& val);
bool operator==(const std::string& val, const Result& res);
bool operator==(const Result& res,const std::string& val);
bool operator==(std::shared_ptr<ArrayNode> val, const Result& res);
bool operator==(const Result& res,std::shared_ptr<ArrayNode> val);

Result operator+(const Result& lhs, const Result& rhs);
Result operator-(const Result& lhs, const Result& rhs);
Result operator*(const Result& lhs, const Result& rhs);
Result operator/(const Result& lhs, const Result& rhs);
Result operator^(const Result& lhs, const Result& rhs);

template<typename T_1, typename T_2>
requires (std::is_same_v<std::decay_t<T_1>,Result> && std::is_fundamental_v<T_2>) || 
    (std::is_same_v<std::decay_t<T_2>,Result> && std::is_fundamental_v<T_1>)
Result operator+(T_1&& lhs, T_2&& rhs){
    if constexpr (std::is_same_v<std::decay_t<T_1>,Result>){
        if(lhs.is_error())
            return lhs;
        else if(!lhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return lhs.get_value()+rhs;
    }
    else{
        if(rhs.is_error())
            return rhs;
        else if(!rhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return rhs.get_value()+lhs;
    }
}
template<typename T_1, typename T_2>
requires (std::is_same_v<std::decay_t<T_1>,Result> && std::is_fundamental_v<T_2>) || 
    (std::is_same_v<std::decay_t<T_2>,Result> && std::is_fundamental_v<T_1>)
Result operator-(T_1&& lhs, T_2&& rhs){
    if constexpr (std::is_same_v<std::decay_t<T_1>,Result>){
        if(lhs.is_error())
            return lhs;
        else if(!lhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return lhs.get_value()-rhs;
    }
    else{
        if(rhs.is_error())
            return rhs;
        else if(!rhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return lhs-rhs.get_value();
    }
}
template<typename T_1, typename T_2>
requires (std::is_same_v<std::decay_t<T_1>,Result> && std::is_fundamental_v<T_2>) || 
    (std::is_same_v<std::decay_t<T_2>,Result> && std::is_fundamental_v<T_1>)
Result operator*(T_1&& lhs, T_2&& rhs){
    if constexpr (std::is_same_v<std::decay_t<T_1>,Result>){
        if(lhs.is_error())
            return lhs;
        else if(!lhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return lhs.get_value()*rhs;
    }
    else{
        if(rhs.is_error())
            return rhs;
        else if(!rhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return rhs.get_value()*lhs;
    }
}
template<typename T_1, typename T_2>
requires (std::is_same_v<std::decay_t<T_1>,Result> && std::is_fundamental_v<T_2>) || 
    (std::is_same_v<std::decay_t<T_2>,Result> && std::is_fundamental_v<T_1>)
Result operator/(T_1&& lhs, T_2&& rhs){
    if constexpr (std::is_same_v<std::decay_t<T_1>,Result>){
        if(lhs.is_error())
            return lhs;
        else if(!lhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else{
            if(rhs==0.)
                return std::make_shared<exceptions::DivisionZero>();
            return lhs.get_value()/rhs;
        }
    }
    else{
        if(rhs.is_error())
            return rhs;
        else if(!rhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else{
            if(rhs.get_value()==0.)
                return std::make_shared<exceptions::DivisionZero>();
            return lhs/rhs.get_value();
        }
    }
}
template<typename T_1, typename T_2>
requires (std::is_same_v<std::decay_t<T_1>,Result> && std::is_fundamental_v<T_2>) || 
    (std::is_same_v<std::decay_t<T_2>,Result> && std::is_fundamental_v<T_1>)
Result operator^(T_1&& lhs, T_2&& rhs){
    if constexpr (std::is_same_v<std::decay_t<T_1>,Result>){
        if(lhs.is_error())
            return lhs;
        else if(!lhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return boost::math::pow(lhs.get_value(),rhs);
    }
    else{
        if(rhs.is_error())
            return rhs;
        else if(!rhs.is_value())
            return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
        else return boost::math::pow(lhs,rhs.get_value());
    }
}
std::ostream& operator<<(std::ostream& os, const Result&);

template<typename T>
T& Result::get(){
    return std::get<T>(*this);
}

template<typename T>
const T& Result::get() const{
    return std::get<T>(*this);
}

struct size_iterator{
    size_iterator(size_t sz):sz_(sz){}
    uint32_t current_iterator_ = 0;
    const uint32_t sz_;
    bool lock = false;
    inline size_iterator& operator++(int);
    inline size_iterator& operator++();
    inline size_iterator& operator--(int);
    inline size_iterator& operator--();
    inline bool is_iterable() const;
    inline bool is_decrement_iterable() const;
};

inline size_iterator& size_iterator::operator++(int){
    current_iterator_>=sz_-1?current_iterator_ = 0:++current_iterator_;
    return *this;
}

inline size_iterator& size_iterator::operator++(){
    current_iterator_>=sz_-1?current_iterator_ = 0:++current_iterator_;
    return *this;
}

inline size_iterator& size_iterator::operator--(int){
    current_iterator_<1?current_iterator_ = sz_-1:current_iterator_--;
    return *this;
}

inline size_iterator& size_iterator::operator--(){
    current_iterator_<1?current_iterator_ = sz_-1:current_iterator_--;
    return *this;
}

inline bool size_iterator::is_iterable() const{
    return current_iterator_<sz_-1;
}

inline bool size_iterator::is_decrement_iterable() const{
    return current_iterator_>=1;
}

class SizeDepthMeasure: private std::vector<size_iterator>{
    public:
    // SizeDepthMeasure()=default;
    // SizeDepthMeasure(const SizeDepthMeasure& other):std::vector<size_iterator>(other){}
    // SizeDepthMeasure(SizeDepthMeasure&& other):std::vector<size_iterator>(other){}
    // SizeDepthMeasure& operator=(const SizeDepthMeasure& other){
    //     if(&other!=this)
    //         std::vector<size_iterator>::operator=(other);
    //     return *this;
    // }
    // SizeDepthMeasure& operator=(SizeDepthMeasure&& other){
    //     if(&other!=this)
    //         std::vector<size_iterator>::operator=(other);
    //     return *this;
    // }
    using std::vector<size_iterator>::begin;
    using std::vector<size_iterator>::end;
    using std::vector<size_iterator>::cend;
    using std::vector<size_iterator>::cbegin;
    void push_depth(size_t new_size);
    void reset_iterator(size_t depth);
    void reset_all_iterators();
    size_t current_iterator(size_t depth) const;
    bool set_iterator(size_t depth, size_t iterator);
    using Index = size_t;
    SizeDepthMeasure& operator++(int);
    SizeDepthMeasure& operator++();
    SizeDepthMeasure& operator--(int);
    SizeDepthMeasure& operator--();
    void lock(size_t depth);
    void unlock(size_t depth);
    bool is_iterable() const;
    bool is_decrement_iterable() const;
    size_t size(size_t depth) const;
    size_t dimensions() const;
    size_t seq_iterator(uint32_t depth = 0) const;
    size_t max_seq_iterator(uint32_t depth = 0) const;
};
