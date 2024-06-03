#pragma once
#include <cassert>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <string>
#include <unordered_set>
#include <variant>
#include "def.h"
#include "data.h"
#include "format.h"
#include "bound.h"
#include "serialize.h"

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

using Arr_value = std::variant<std::monostate,Value_t,std::string, VariableBase*, ArithmeticTree>;

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

    void define_back(const std::shared_ptr<Node> & node);

    VariableBase* parent() const{
        return parent_;
    }

    const std::unordered_set<VariableNode*>& get_dependencies() const;

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
    mutable std::unordered_set<VariableNode*> var_dependence_;
    void __value_to_tree_for_last__();
};

using namespace std::string_literals;
using namespace std::string_view_literals;

class VariableBase: public FormattingData{

    public:

    virtual ~VariableBase();

    explicit VariableBase(std::string_view name, BaseData* data_base);

    template<typename T>
    VariableBase(std::string_view name, T&& value, BaseData* data_base);

    template<typename T>
    void define(T&& value);

    std::string_view name() const;
    void refresh() const;

    const std::shared_ptr<VariableNode>& node() const;
    const std::shared_ptr<VariableNode>& node();

    bool is_expression() const;
    bool is_value() const;
    bool is_string() const;
    bool is_array() const;
    bool is_undef() const;
    bool is_numeric() const;

    std::ostream& operator<<(std::ostream& stream);

    void print();

    template<typename T>
    void set_bottom_bound_value(std::string_view,std::string_view,T&& value, BOTTOM_BOUND_T type);

    template<typename T>
    void set_top_bound_value(std::string_view,std::string_view,T&& value, TOP_BOUND_T type);

    bool is_in_bounds(std::string_view,std::string_view) const;

    std::optional<Value_t> get_top_bound(std::string_view,std::string_view);

    std::optional<Value_t> get_bottom_bound(std::string_view,std::string_view);

    std::string_view get_data_base_name() const;
    
    void serialize(std::ostream& stream){
        using namespace serialization;
        serialization::serialize(stream,data_base_->name());
        serialization::serialize(stream,name_);
        serialization::serialize(stream,text_);
        serialization::serialize(stream,show_reinterpret_);
        node_->serialize(stream);
    }

    void deserialize(std::istream& stream);

    protected:
    void set_data_base(BaseData* data_pool);
    BaseData* get_data_base() const;

    private:
    std::unordered_map<std::string_view,std::unordered_map<std::string_view,VariableBounds>> bounds_;
    std::string text_;
    std::shared_ptr<VariableNode> node_; //shared, так как может быть передан в любое арифметическое дерево
    std::string_view name_;
    bool show_reinterpret_=true; //show a reinterpreted formula
    BaseData* data_base_;
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

template<typename T>
void VariableBase::set_bottom_bound_value(std::string_view data_base,std::string_view var_name,T&& value, BOTTOM_BOUND_T type){
    bounds_[data_base][var_name].set_bound_value(std::forward<T>(value),type);
    #ifdef DEBUG
    std::cout << var_name<<' ';
    if(type == BOTTOM_BOUND_T::LARGER)
        std::cout<<"larger than ";
    else std::cout<<"larger or equal than ";
    std::cout<<value<<" in "<<name()<<std::endl;
    #endif
}

template<typename T>
void VariableBase::set_top_bound_value(std::string_view data_base,std::string_view var_name,T&& value, TOP_BOUND_T type){
    bounds_[data_base][var_name].set_bound_value(std::forward<T>(value),type);
    #ifdef DEBUG
    std::cout << var_name<<' ';
    if(type == TOP_BOUND_T::LESS)
        std::cout<<"less than ";
    else std::cout<<"less or equal than ";
    std::cout<<value<<" in "<<name()<<std::endl;
    #endif
}