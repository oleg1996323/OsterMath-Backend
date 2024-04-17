#include "types.h"
#include "arithmetic_tree.h"

size_t VariableBase::HashVar::operator()(const VariableBase& var){
    return std::hash<std::string_view>()(var.name_);
}

std::ostream& operator<<(std::ostream& stream, const Array_t& arr){
    stream<<'[';
    if(!arr.empty()){
        stream<<arr.front();
        for(size_t i=1;i<arr.size();++i)
            stream<<' '<<arr.at(i);
    }
    stream<<']';
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::monostate empty){
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Variable& var){
    std::visit([&stream](auto const& x) { stream << x; }, var);
    return stream;
}

VariableBase::VariableBase(std::string_view name, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{}

template<typename T>
VariableBase::VariableBase(std::string_view name, T&& value, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{
    this->emplace(std::forward<T>(value));
}

std::string_view VariableBase::name() const{
    return name_;
}

void VariableBase::refresh() const{
    node_->refresh();
}

void VariableBase::set_data_base(BaseData* data_base){
    data_base_=data_base;
}

BaseData* VariableBase::get_data_base() const{
    return data_base_;
}

template<typename T>
void VariableBase::define(T&& value){
    *this=std::forward<T>(value);
}

const VariableBase::variant& VariableBase::get() const{
    return *this;
}

VariableBase::variant& VariableBase::get(){
    return *this;
}

bool VariableBase::is_arithmetic_tree() const{
    return std::holds_alternative<ArithmeticTree>(*this);
}

bool VariableBase::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool VariableBase::is_string() const{
    return std::holds_alternative<std::string>(*this);
}

bool VariableBase::is_array() const{
    return std::holds_alternative<Array_t>(*this);
}