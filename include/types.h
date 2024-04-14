#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <hash_map>
#include <stdexcept>
#include <cstdarg>
#include "def.h"
#include "exception.h"

using namespace std::string_literals;
using namespace std::string_view_literals;

class BaseData;

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

    explicit VariableBase(std::string_view name, BaseData* data_pool):
        name_(name),
        data_pool_(data_pool)
    {}

    std::string_view GetName() const{
        return name_;
    }

    virtual VAR_TYPE type(){
        return VAR_TYPE::UNKNOWN;
    }

    protected:
    void set_data_pool(BaseData* data_pool){
        data_pool_=data_pool;
    }

    BaseData* get_data_pool() const{
        return data_pool_;    
    }

    private:
    std::string_view name_;
    BaseData* data_pool_;
};

class String: public std::string, public VariableBase{
    public:
    String(std::string_view name, BaseData* data_pool):
    VariableBase(name, data_pool)
    {}

    template<typename T>
    String(std::string_view name, T&& text, BaseData* data_pool)
        :std::string(std::forward<T>(text)),
        VariableBase(name, data_pool)
    {}

    virtual VAR_TYPE type() override{
        return VAR_TYPE::STRING;
    }
};

#include <initializer_list>

using Array_t = std::vector<Value_t>;

class Array: public std::vector<Value_t>, public VariableBase{
    public:
    Array(std::string_view name, BaseData* data_pool):
    VariableBase(name, data_pool)
    {}

    template<typename T>
    Array(std::string_view name, T&& array, BaseData* data_pool):
    std::vector<Value_t>(std::forward<std::remove_reference<T>>(array)),
    VariableBase(name, data_pool)
    {}

    virtual VAR_TYPE type() override{
        return VAR_TYPE::ARRAY;
    }
};

#include <optional>
#include "arithmetic_tree.h"

class Variable: public VariableBase{
    public:
    Variable(std::string_view name, BaseData* data_pool):
    VariableBase(name, data_pool)
    {}

    template<typename TREE>
    Variable(std::string_view name, TREE&& tree, BaseData* data_pool):
    VariableBase(name, data_pool),
    function(std::forward<ArithmeticTree>(tree))
    {}

    explicit Variable(const Variable& var, BaseData* data_pool = nullptr):
    VariableBase(var.GetName(),!data_pool?var.get_data_pool():data_pool){
        this->function = var.function;
        vars_dependence_ = var.vars_dependence_;
        cache_ = var.cache_;
        if(data_pool)
            set_data_pool(data_pool);
    }

    Value_t execute() const{
        return function.execute();
    }

    private:
    ArithmeticTree function;
    std::unordered_set<std::string_view> vars_dependence_; //если обнаруживается взаимная зависимость переменных, то выбрасывается исключение
    mutable std::optional<Value_t> cache_;
};

