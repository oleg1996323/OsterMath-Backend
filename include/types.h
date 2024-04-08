#pragma once

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

using ValueLong = boost::multiprecision::cpp_dec_float_50;
using Array = std::vector<double>;
using ArrayLong = std::vector<ValueLong>;

template<typename... ARGS>
using Function = std::function<double(ARGS...)>;

template<typename... ARGS>
using FunctionLong = std::function<ValueLong(ARGS...)>;

class VariableBase{
    public:
    struct HashVar{
        size_t operator()(const VariableBase& var){
            return std::hash<std::string_view>()(var.name_);
        }
    };

    protected:
    explicit VariableBase(std::string_view name):
        name_(name)
    {}

    std::string_view name_;

    private:

    virtual void SetValue(double value){}

    virtual void SetValueLong(ValueLong&& value){}
    
    virtual void SetArray(Array&& value){}

    virtual void SetArrayLong(ArrayLong&& value){}

    virtual double GetValue() const{
        throw std::runtime_error("Not value. Base class method called.");
    }

    virtual const ValueLong& GetValueLong() const{
        throw std::runtime_error("Not value-long. Base class method called.");
    }

    virtual const Array& GetArray() const{
        throw std::runtime_error("Not array. Base class method called.");
    }

    virtual const ArrayLong& GetArrayLong() const{
        throw std::runtime_error("Not array-long. Base class method called.");
    }
};

class VarValue: public VariableBase{
    public:
    explicit VarValue(std::string_view name, double value):VariableBase(name)
    {}

    void SetValue(double value) override{
        cache_.emplace(value);
    }

    virtual double GetValue() const override{
        if(cache_.has_value()){
            return cache_.value();
        }
        else
            throw std::logic_error("Unavailable value from " + std::string(name_));
    }

    private:

    mutable std::optional<double> cache_;
};

class VarValueLong: public VariableBase{
    public:
    explicit VarValueLong(std::string_view name, ValueLong&& value)
        :VariableBase(name),
        cache_(std::move(value))
    {}
    
    void SetValueLong(ValueLong&& value) override{
        cache_.emplace(std::move(value));
    }

    virtual const ValueLong& GetValueLong() const override{
        if(cache_.has_value()){
            return cache_.value();
        }
        else
            throw EmptyVal("Unavailable value from " + std::string(name_));
    }

    private:

    mutable std::optional<ValueLong> cache_;
};

#include <initializer_list>

class VarArray: public VariableBase{
    public:
    VarArray(std::string_view name, Array&& value)
        :VariableBase(name),
        val_(std::move(value))
    {}

    void SetArray(Array&& value) override{
        val_ = std::move(value);
    }

    virtual const Array& GetArray() const override{
        if(!val_.empty())
            return val_;
        else throw EmptyArray("Variable-array "+std::string(name_)+" not initialized");
    }

    void Append(double value){
        val_.push_back(value);
    }

    void Erase(size_t pos){
        val_.erase(val_.begin()+pos);
    }
    
    double SumProduct(std::initializer_list<const Array>& arrays){
        double result = 0.;
        if(checking_egal_size_arrays(arrays)){
            for(size_t i=0;i<arrays.begin()->size();++i){
                double product = 1.;
                for(const Array& arr: arrays)
                    product *= arr.at(i);
                result+=product;
            }
        }
        return result;      
    }

    Array val_;
    std::function<bool(std::initializer_list<const Array>&)> checking_egal_size_arrays = [](std::initializer_list<const Array>& arrays){
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

class VarArrayLong: public VariableBase{
    public:
    VarArrayLong(std::string_view name, ArrayLong&& value)
        :VariableBase(name),
        val_(std::move(value))
    {}

    void SetArrayLong(ArrayLong&& value) override{
        val_ = std::move(value);
    }

    virtual const ArrayLong& GetArrayLong() const override{
        if(!val_.empty())
            return val_;
        else
            throw EmptyArray("Variable-array "+std::string(name_)+" not initialized");
    }

    void Append(double value){
        val_.push_back(value);
    }

    void Erase(size_t pos){
        val_.erase(val_.begin()+pos);
    }
    
    ValueLong SumProduct(std::initializer_list<const ArrayLong>& arrays){
        ValueLong result = 0.;
        if(checking_egal_size_arrays(arrays)){
            for(size_t i=0;i<arrays.begin()->size();++i){
                ValueLong product = 1.;
                for(const ArrayLong& arr: arrays)
                    product *= arr.at(i);
                result+=product;
            }
        }
        return result;      
    }

    ArrayLong val_;
    std::function<bool(std::initializer_list<const ArrayLong>&)> checking_egal_size_arrays = [](std::initializer_list<const ArrayLong>& arrays){
        size_t fst_arr_sz;
        if(arrays.size()!=0 && !arrays.begin()->empty())
            fst_arr_sz = arrays.begin()->size();
        for(const ArrayLong& arr: arrays){
            if(arr.size()!=fst_arr_sz)
                return false;
        }
        return true;
    };
};

#include <optional>

template<typename... ARGS>
class VarFunction: public VariableBase{
    public:
    VarFunction(std::string_view name, Function<double(ARGS...)> function)
        :VariableBase(name),
        function_(function)
    {}

    void SetFunction(Function<double(ARGS...)> value) override{
        this->val_ = value;
    }

    auto& GetFunction() const{
        if(function_)
            return function_;
        else throw UndefinedFunction("Function of variable " +std::string(name_)+ " not defined");
    }

    double operator()(ARGS&&... args) const{
        if(!cache_)
            cache_.emplace(val_(std::forward<ARGS...>(args...)));
        return cache_.value();
    }

    private:
    Function<double(ARGS...)> function_;
    mutable std::optional<double> cache_;
};

template<typename... ARGS>
class VarFunctionLong: public VariableBase{
    public:
    VarFunctionLong(std::string_view name, FunctionLong<ValueLong(ARGS...)> function)
        :VariableBase(name),
        function_(function)
    {}

    void SetFunction(Function<ValueLong(ARGS...)> value) override{
        function_ = value;
    }

    FunctionLong<ValueLong(ARGS...)> operator()(ARGS&&... args){
        return function_(std::forward<ARGS...>(args...));
    }

    ValueLong operator()(ARGS&&... args) const{
        if(!cache_)
            cache_.emplace(function_(std::forward<ARGS...>(args...)));
        return cache_.value();
    }

    private:
    FunctionLong<ValueLong(ARGS...)> function_;
    mutable std::optional<ValueLong> cache_;
};