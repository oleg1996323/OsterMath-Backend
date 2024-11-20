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
using Result_t = std::variant<std::monostate,std::string, const Node*, std::shared_ptr<AbstractEvent>,Value_t>;

#define ENUM_NAME(p) #p;

enum TYPE_VAL{
    UNKNOWN = 0x00,
    VALUE = 0x01,
    STRING = 0x04,
    ARRAY = 0x08,
    STRING_ARRAY = ARRAY | STRING,
    NUMERIC_ARRAY = ARRAY | VALUE
};

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

    std::ostream& operator<<(std::ostream& os);

    bool is_value() const;
    bool is_string() const;
    bool is_node() const;
    bool is_array() const;
    bool has_value() const;
    bool is_event() const;
    bool is_error() const;
    bool is_warning() const;

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

    // //add definition
    // inline std::vector<Value_t> get_array_values() noexcept{

    // }

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

// class ProxySizeDepthMeasure{
//     public:
//     ProxySizeDepthMeasure(size_t new_size);

//     ProxySizeDepthMeasure(size_t new_size, ProxySizeDepthMeasure* parent);

//     bool operator++();

//     void push(size_t new_size);

//     size_t depth();

//     void reset_iterator();

//     size_t current_iterator(int32_t depth) const;

//     bool is_iterable() const;

//     size_t size(size_t depth) const;

//     size_t seq_iterator(int32_t depth) const;

//     size_t total_size_childs() const;

//     private:
//     void depth(size_t& uppper_depth);

//     size_t current_iterator_ref(int32_t& depth) const;

//     size_t size_ref(size_t& depth) const;

//     size_t seq_iterator_ref(int32_t& depth) const;

//     bool increase_iterator();

//     std::unique_ptr<ProxySizeDepthMeasure> next_level_;
//     ProxySizeDepthMeasure* parent_;
//     size_t sz_;
//     mutable size_t total_childs_ = 0;
//     size_t current_iterator_ = 0;
// };

struct size_iterator{
    size_iterator(size_t sz):sz_(sz){}
    uint32_t current_iterator_ = 0;
    const uint32_t sz_;

    size_iterator& operator++(int){
        current_iterator_>=sz_-1?current_iterator_ = 0:++current_iterator_;
        return *this;
    }

    size_iterator& operator++(){
        current_iterator_>=sz_-1?current_iterator_ = 0:++current_iterator_;
        return *this;
    }

    size_iterator& operator--(int){
        current_iterator_<1?current_iterator_ = sz_-1:current_iterator_--;
        return *this;
    }

    size_iterator& operator--(){
        current_iterator_<1?current_iterator_ = sz_-1:current_iterator_--;
        return *this;
    }

    bool is_iterable() const{
        return current_iterator_<sz_-1;
    }

    bool is_decrement_iterable() const{
        return current_iterator_>=1;
    }
};

class SizeDepthMeasure: private std::vector<size_iterator>{
    public:
    void push_depth(size_t new_size){
        if(new_size>0)
            std::vector<size_iterator>::emplace_back(new_size);
        else throw std::invalid_argument("Size cannot be 0");
    }

    void reset_iterator(size_t depth){
        if(std::vector<size_iterator>::size()<=depth)
            throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
        at(depth).current_iterator_ = 0;
    }

    void reset_all_iterators(){
        for(auto& index:*this)
            index.current_iterator_ = 0;
    }

    size_t current_iterator(size_t depth) const{
        if(std::vector<size_iterator>::size()<=depth)
            throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
        return at(depth).current_iterator_;
    }

    using Index = size_t;
    SizeDepthMeasure& operator++(int){
        for(std::vector<size_iterator>::reverse_iterator index = rbegin();
            index<rend();++index){
            if(index->is_iterable()){
                ++(*index);
                break;
            }
            else{
                index->current_iterator_=0;
            }
        }
        return *this;
    }

    SizeDepthMeasure& operator++(){
        for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
            index!=std::vector<size_iterator>::rend();++index){
            if(index->is_iterable()){
                ++(*index);
                break;
            }
            else{
                index->current_iterator_=0;
            }
        }
        return *this;
    }

    SizeDepthMeasure& operator--(int){
        for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
            index!=std::vector<size_iterator>::rend();++index){
            if(index->is_decrement_iterable()){
                --(*index);
                break;
            }
            else{
                index->current_iterator_=index->sz_-1;
            }
        }
        return *this;
    }

    SizeDepthMeasure& operator--(){
        for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
            index!=std::vector<size_iterator>::rend();++index){
            if(index->is_decrement_iterable()){
                --(*index);
                break;
            }
            else{
                index->current_iterator_=index->sz_-1;
            }
        }
        return *this;
    }

    bool is_iterable() const{
        for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
            index!=std::vector<size_iterator>::rend();++index){
            if(index->is_iterable())
                return true;
        }
        return false;
    }

    bool is_decrement_iterable() const{

        for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
            index!=std::vector<size_iterator>::rend();++index){
            if(index->is_decrement_iterable())
                return true;
        }
        return false;
    }

    size_t size(size_t depth) const{
        if(std::vector<size_iterator>::size()<=depth)
            throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
        return at(depth).sz_;
    }

    size_t dimensions() const{
        return std::vector<size_iterator>::size();
    }

    size_t seq_iterator(uint32_t depth = 0) const{
        size_t result = 0;
        size_t sz_ex_depths = 1;
        for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
            index<std::vector<size_iterator>::rend()-depth;++index){
            result+=index->current_iterator_*sz_ex_depths;
            sz_ex_depths*=index->sz_;
        }
        return result;
    }

    size_t max_seq_iterator(uint32_t depth = 0) const{
        size_t result = 0;
        size_t sz_ex_depths = 1;
        for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
            index<std::vector<size_iterator>::rend()-depth;++index){
            result+=index->sz_*sz_ex_depths;
            sz_ex_depths*=index->sz_;
        }
        return result;
    }
};