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

using Value = boost::multiprecision::cpp_dec_float_50;
using Array = std::vector<Value>;

template<typename... ARGS>
using Function = std::function<Value(ARGS...)>;

/*
class StorageBase{
    public:
    virtual ~StorageBase(){

    }

    virtual void Print(ostream& out) const =0;
};


template<typename T_VALUE>
class Storage:public StorageBase{
    public:
    template<typename S>
    Storage(S&& val):data_(std::forward<S>(val)){}

    void Print(ostream& out) const override{
        out<<data_;
    }

    private:
    T_VALUE data_;
};

class Any{
    public:

    template<typename T>
    Any(T&& val){
        using Initial = std::remove_reference_t<T>;
        value = std::make_unique<Storage<Initial>>(std::forward<T>(val));
    }

    void Print(ostream& out) const {
        return value->Print(out);
    }

    private:
    std::unique_ptr<StorageBase> value;
};

*/

class VariableBase{
    public:
    struct HashVar{
        size_t operator()(const VariableBase& var){
            return std::hash<std::string_view>()(var.name_);
        }
    };

    explicit VariableBase(std::string_view name):
        name_(name)
    {}

    virtual ~VariableBase(){}

    protected:
    std::string_view name_;
};

class VarValue: public VariableBase{
    public:
    explicit VarValue(std::string_view name, Value&& value):
    VariableBase(name),
    val_(std::make_unique<Value>(std::move(value)))
    {}

    private:
    std::unique_ptr<Value> val_;
};

#include <initializer_list>
#include <type_traits>

class VarArray: public VariableBase 
    {
    public:
    VarArray(std::string_view name, Array&& value)
        :VariableBase(name),
        val_(std::make_unique<Array>(std::move(value)))
    {}

    void SetArray(Array&& value){
        if(!val_)
            val_ = std::make_unique<Array>(std::move(value));
        else
            throw std::runtime_error(std::string(name_)+" already initialized.");
    }

    const Array* GetArray() const{
        if(!val_)
            return val_.get();
        else{
            static Array* empty = nullptr;
            return empty;
        }
    }

    void Append(Value value) noexcept{
        this->GetArray()->push_back(value);
    }

    void Erase(size_t pos) noexcept{
        if(!(this->GetArray()->size()>pos))
            this->GetArray()->erase(this->GetArray()->begin()+pos);
    }

    void PopBack() noexcept{
        if(!this->GetArray()->empty())
            Erase(this->GetArray()->size()-1);
    }
    
    Value SumProduct(std::initializer_list<const Array>& arrays){
        Value result = 0.;
        if(Checking_Egal_Size_Arrays(arrays)){
            for(size_t i=0;i<arrays.begin()->size();++i){
                Value product = 1.;
                for(const Array& arr: arrays)
                    product *= arr.at(i);
                result+=product;
            }
        }
        return result;      
    }

    bool Checking_Egal_Size_Arrays(std::initializer_list<const Array>& arrays){
        size_t fst_arr_sz;
        if(arrays.size()!=0 && !arrays.begin()->empty())
            fst_arr_sz = arrays.begin()->size();
        for(const Array& arr: arrays){
            if(arr.size()!=fst_arr_sz)
                return false;
        }
        return true;
    };

    private:
    std::unique_ptr<Array> val_;

    Array* GetArray(){
        if(!val_)
            return val_.get();
        else{
            static Array* empty = nullptr;
            return empty;
        }
    }
};

class VarString: public VariableBase{
    public:
    VarString(std::string_view name, std::string&& text)
        :VariableBase(name),
        val_(std::make_unique<std::string>(std::move(text)))
    {}

    private:
    std::unique_ptr<std::string> val_;
};

#include <optional>

template<typename... ARGS>
class VarFunction: public VariableBase{
    public:
    VarFunction(std::string_view name, Function<ARGS...> function)
        :VariableBase(name),
        function_(std::make_unique<decltype(function)>(function))
    {}

    Value operator()(ARGS&&... args) const{
        if(!cache_)
            cache_.emplace(this->val_(std::forward<ARGS...>(args...)));
        return cache_.value();
    }

    private:
    mutable std::optional<Value> cache_;
    std::unique_ptr<Function<ARGS...>> function_;
};

