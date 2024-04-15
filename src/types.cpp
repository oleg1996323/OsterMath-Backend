#include "types.h"
#include "arithmetic_tree.h"

struct VariableVisitor{
    void operator()(std::monostate) const{
        throw std::runtime_error("Undefined variable");
    }

    const Value_t& operator()(const Value_t& value) const{
        return value;
    }

    const Array_t& operator()(const Array_t& array) const{
        return array;
    }

    const std::string& operator()(const std::string& string) const{
        return string;
    }

    const ArithmeticTree& operator()(const ArithmeticTree& tree) const{
        return tree;
    }
};

size_t VariableBase::HashVar::operator()(const VariableBase& var){
    return std::hash<std::string_view>()(var.name_);
}

VariableBase::VariableBase(std::string_view name, BaseData* data_pool):
    name_(name),
    data_pool_(data_pool)
{}

template<typename T>
VariableBase::VariableBase(std::string_view name, T&& value, BaseData* data_pool):
    name_(name),
    data_pool_(data_pool)
{
    this->emplace(std::forward<T>(value));
}

std::string_view VariableBase::GetName() const{
    return name_;
}

void VariableBase::Refresh() const{
    node_->refresh();
}

void VariableBase::set_data_pool(BaseData* data_pool){
    data_pool_=data_pool;
}

BaseData* VariableBase::get_data_pool() const{
    return data_pool_;
}

template<typename T>
const T& VariableBase::get() const{
    return std::visit<const T&>(VariableVisitor(), *this);
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