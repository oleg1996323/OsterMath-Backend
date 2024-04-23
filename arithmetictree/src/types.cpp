#include "def.h"
#include "types.h"
#include "arithmetic_tree.h"
#include "data.h"

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

std::ostream& operator<<(std::ostream& stream, Variable var){
    std::visit([&stream](const auto& x) { stream << x; }, var);
    return stream;
}

VariableBase::VariableBase(std::string_view name, BaseData* data_base):
    name_(name),
    data_base_(data_base)
{
    node_=std::make_shared<VariableNode>(this);
}

std::string_view VariableBase::name() const{
    return name_;
}

#include "arithmetic_types.h"

void VariableBase::refresh() const{
    node_->refresh();
}

void VariableBase::set_data_base(BaseData* data_base){
    data_base_=data_base;
}

BaseData* VariableBase::get_data_base() const{
    return data_base_;
}

Variable& VariableBase::get(){
    return *this;
}

const Variable& VariableBase::get() const{
    return *this;
}

const std::shared_ptr<VariableNode>& VariableBase::node() const{
    return node_;
}

bool VariableBase::is_arithmetic_tree() const{
    return std::holds_alternative<ArithmeticTree>(get());
}

bool VariableBase::is_value() const{
    return std::holds_alternative<Value_t>(get());
}

bool VariableBase::is_string() const{
    return std::holds_alternative<std::string>(get());
}

bool VariableBase::is_array() const{
    return std::holds_alternative<Array_t>(get());
}

bool VariableBase::is_undef() const{
    return std::holds_alternative<std::monostate>(get());
}

void VariableBase::value_to_tree(){
    if(is_value()){
        ArithmeticTree tree;
        tree.insert(std::make_shared<ValueNode>(std::move(get<Value_t>())));
        this->get()=std::move(tree);
    }
}

void VariableBase::tree_to_value(){
    if(is_arithmetic_tree())
        get() = get<ArithmeticTree>().execute();
}

VariableBase::~VariableBase(){

}