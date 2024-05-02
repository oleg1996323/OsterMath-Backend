#include "def.h"
#include "types.h"
#include "arithmetic_tree.h"
#include "data.h"

bool Array_val::is_undef() const{
    return std::holds_alternative<std::monostate>(*this) || (is_variable() && get<VariableBase*>());
}

bool Array_val::is_variable() const{
    return std::holds_alternative<VariableBase*>(*this);
}

bool Array_val::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool Array_val::is_numeric() const{
    if(is_variable()){
        auto ptr = get<VariableBase*>();
        if(ptr && (ptr->is_arithmetic_tree() || ptr->is_value())){
            return true;
        }
    }
    return is_value() || is_expression();
}

bool Array_val::is_string() const{
    if(is_variable()){
        auto ptr = get<VariableBase*>();
        if(ptr && ptr->is_string()){
            return true;
        }
    }
    return std::holds_alternative<std::string>(*this);
}

bool Array_val::is_expression() const{
    return std::holds_alternative<ArithmeticTree>(*this);
}

void Array_t::define_back(const Array_val& val){
    if(!back().is_undef()){
        throw std::invalid_argument("Array item already defined");
        return;
    }
    if(val.is_variable())
        val.get<VariableBase*>()->node()->add_parent(parent_->node());

    if(type_!=TYPE::UNKNOWN){
        if(type_==TYPE::NUMERIC && !val.is_numeric()){
            throw std::invalid_argument("Input value type don't correspond numeric type of array");
            return;
        }
        else if(type_==TYPE::STRING && !val.is_string()){
            throw std::invalid_argument("Input value type don't correspond string type of array");
            return;
        }
    }


    back() = val; //при вводе неопределённой переменной тип определяется неверно
    if(val.is_string())
        type_=TYPE::STRING;
    else if(val.is_numeric())
        type_=TYPE::NUMERIC;
}

size_t VariableBase::HashVar::operator()(const VariableBase& var){
    return std::hash<std::string_view>()(var.name_);
}

std::ostream& VariableBase::operator<<(std::ostream& stream){
    stream<<*this;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Arr_value& val){
    std::visit([&stream](const auto& x) { stream << x; }, val);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Array_t& arr){
    stream<<'[';
    if(!arr.empty()){
        if(arr.front().is_variable() && arr.front().get<VariableBase*>()!=nullptr)
            stream<<arr.front().get<VariableBase*>()->get();
        else
            stream<<arr.front().get();
        for(size_t i=1;i<arr.size();++i){
            if(arr.at(i).is_variable() && arr.at(i).get<VariableBase*>()!=nullptr)
                stream<<' '<<arr.at(i).get<VariableBase*>()->get();
            else
            stream<<' '<<arr.at(i).get();
        }
    }
    stream<<']';
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::monostate empty){
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Variable_t& var){
    std::visit([&stream](const auto& x) { stream << x; }, var);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree){
    stream<<tree.value();
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

Variable_t& VariableBase::get(){
    return *this;
}

const Variable_t& VariableBase::get() const{
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
        get() = get<ArithmeticTree>().value();
}

VariableBase::~VariableBase(){

}