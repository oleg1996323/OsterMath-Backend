#pragma once
#include <cassert>

#include "def.h"
#include "exception.h"
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <hash_map>
#include <stdexcept>
#include <cstdarg>

using namespace std::string_literals;
using namespace std::string_view_literals;

enum class VAR_TYPE{
    VALUE,
    ARRAY,
    FUNCTION,
    STRING,
    UNKNOWN
};

using Value_t = boost::multiprecision::cpp_dec_float_50;

class VariableBase{
    public:
    struct HashVar{
        size_t operator()(const VariableBase& var){
            return std::hash<std::string_view>()(var.name_);
        }
    };

    ~VariableBase(){}

    explicit VariableBase(std::string_view name):
        name_(name)
    {}

    std::string_view GetName() const{
        return name_;
    }

    protected:
    VAR_TYPE type_ = VAR_TYPE::UNKNOWN;

    private:
    std::string_view name_;
};

class Value:public VariableBase{
    public:
    Value(std::string_view name):
    VariableBase(name)
    {
        this->type_ = VAR_TYPE::VALUE;
    }

    template<typename T>
    Value(std::string_view name, T&& value):
    VariableBase(name),
    val_(std::make_unique<Value_t>(std::forward<T>(value)))
    {
        type_ = VAR_TYPE::VALUE;
    }

    private:
    std::unique_ptr<Value_t> val_;
};

class String: public std::string, public VariableBase{
    public:
    String(std::string_view name):
    VariableBase(name)
    {
        type_ = VAR_TYPE::STRING;
    }

    template<typename T>
    String(std::string_view name, T&& text)
        :std::string(std::forward<T>(text)),
        VariableBase(name)
    {
        type_ = VAR_TYPE::STRING;
    }
};

#include <initializer_list>

using Array_t = std::vector<Value_t>;

class Array: public std::vector<Value_t>, public VariableBase{
    public:
    Array(std::string_view name):
    VariableBase(name)
    {
        type_ = VAR_TYPE::ARRAY;
    }

    template<typename T>
    Array(std::string_view name, T&& array):
    std::vector<Value_t>(std::forward<std::remove_reference<T>>(array)),
    VariableBase(name)
    {
        type_ = VAR_TYPE::ARRAY;
    }

    static Value_t SumProduct(std::initializer_list<const Array>& arrays){
        Value_t result = 0.;
        if(Checking_Egal_Size_Arrays(arrays)){
            for(size_t i=0;i<arrays.begin()->size();++i){
                Value_t product = 1.;
                for(const Array& arr: arrays)
                    product *= arr.at(i);
                result+=product;
            }
        }
        return result;      
    }

    static bool Checking_Egal_Size_Arrays(std::initializer_list<const Array>& arrays){
        size_t fst_arr_sz;
        if(arrays.size()!=0 && !arrays.begin()->empty())
            fst_arr_sz = arrays.begin()->size();
        for(const Array& arr: arrays){
            if(arr.size()!=fst_arr_sz)
                return false;
        }
        return true;
    };
};

#include <optional>
#include <functional>

template<typename... ARGS>
using Function_t = std::function<Value_t(ARGS&&...)>;

class Function: public VariableBase{
    public:
    Function(std::string_view name):
    VariableBase(name)
    {
        type_ = VAR_TYPE::FUNCTION;
    }

    #define TYPE_ARGS typename std::enable_if<all_same<ARGS...>::value, void>::type

    template<typename... ARGS>
    Function(std::string_view name, Function_t<TYPE_ARGS> value):
    VariableBase(name),
    function_(std::forward<TYPE_ARGS>(value))
    {
        type_ = VAR_TYPE::FUNCTION;
    }

    template<typename... ARGS>
    Value_t operator()(TYPE_ARGS&& args...) const{
        if(!cache_)
            cache_.emplace(this->function_(std::forward<TYPE_ARGS>(args)));
        return cache_.value();
    }

    template<typename... ARGS>
    Value_t GetValue(TYPE_ARGS&& args...) const {
        return (*this)(std::forward<TYPE_ARGS>(args));
    }

    private:
    Function_t<VariableBase> function_;
    mutable std::optional<Value_t> cache_;
};

