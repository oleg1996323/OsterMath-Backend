#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "def.h"
#include "exception.h"
#include "data.h"
#include "arithmetic_tree.h"
#include "format.h"

class VariableNode;
class VariableBase;
class Array_val;

struct Variable_ref{
    std::string_view var_name_;
    std::string_view db_name_;
};

enum class TYPE{
    UNKNOWN,
    STRING,
    NUMERIC
};

class Array_val:private Arr_value{
    using variant::variant;
    public:
    bool is_undef() const;

    bool is_variable() const;

    bool is_value() const;

    bool is_numeric() const;

    bool is_string() const;

    bool is_expression() const;

    template<typename T>
    const T& get() const{
        return std::get<T>(*this);
    }

    template<typename T>
    T& get(){
        return std::get<T>(*this);
    }

    Arr_value& get(){
        return *this;
    }

    const Arr_value& get() const{
        return *this;
    }
};

class Array_t : public std::vector<Array_val>{
    public:

    Array_t(VariableBase* parent):parent_(parent){}

    void define_back(const Array_val& val);

    VariableBase* parent() const{
        return parent_;
    }

    TYPE type() const{
        TYPE type = TYPE::UNKNOWN;
        for(auto& val:*this)
            if(val.is_numeric()){
                if(type==TYPE::UNKNOWN)
                    type=TYPE::NUMERIC;
            }
            else if(val.is_string()){
                if(type==TYPE::UNKNOWN)
                    type=TYPE::STRING;
            }
            else throw std::invalid_argument("Incorrect array type");
        return type;
    }

    private:
    VariableBase* parent_; 
};

using Variable_t = std::variant<std::monostate,Value_t,std::string, Array_t, ArithmeticTree>;

using namespace std::string_literals;
using namespace std::string_view_literals;

class VariableBase: private Variable_t, public FormattingData{
    using variant::variant;

    public:
    struct HashVar{
        size_t operator()(const VariableBase& var);
    };

    virtual ~VariableBase();

    explicit VariableBase(std::string_view name, BaseData* data_base);

    template<typename T>
    VariableBase(std::string_view name, T&& value, BaseData* data_base);

    template<typename T>
    void define(T&& value);

    std::string_view name() const;
    void refresh() const;

    const Variable_t& get() const;
    Variable_t& get();

    void value_to_tree();

    void tree_to_value();

    template<typename T>
    const T& get() const;

    template<typename T>
    T& get();

    const std::shared_ptr<VariableNode>& node() const;
    const std::shared_ptr<VariableNode>& node();

    bool is_arithmetic_tree() const;
    bool is_value() const;
    bool is_string() const;
    bool is_array() const;
    bool is_undef() const;
    bool is_numeric() const;

    std::ostream& operator<<(std::ostream& stream);

    void print();

    protected:
    void set_data_base(BaseData* data_pool);
    BaseData* get_data_base() const;

    private:
    std::shared_ptr<VariableNode> node_; //shared, так как может быть передан в любое арифметическое дерево
    std::string_view name_;
    BaseData* data_base_;
    TYPE type_;
};

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree);

std::ostream& operator<<(std::ostream& stream, const Array_t& arr);

std::ostream& operator<<(std::ostream& stream, std::monostate empty);

std::ostream& operator<<(std::ostream& stream, const Variable_t& var);

std::ostream& operator<<(std::ostream& stream, const Array_val& val);

template<typename T>
T& VariableBase::get(){
    return std::get<T>(get());
}

template<typename T>
const T& VariableBase::get() const{
    return std::get<T>(get());
}

template<typename T>
void VariableBase::define(T&& value){
    get()=std::forward<T>(value);
}

template<typename T>
VariableBase::VariableBase(std::string_view name, T&& value, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{
    node_=std::make_shared<VariableNode>(this);
    get()=std::forward<T>(value);
}