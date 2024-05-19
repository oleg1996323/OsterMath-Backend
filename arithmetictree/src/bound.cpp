#include "bound.h"
#include "types.h"
#include "arithmetic_types.h"

template<>
bool Bound_T<TOP_BOUND_T>::is_expression() const{
    return std::holds_alternative<ArithmeticTree>(value_);
}

template<>
bool Bound_T<TOP_BOUND_T>::is_value() const{
    return std::holds_alternative<Value_t>(value_);
}

template<>
bool Bound_T<TOP_BOUND_T>::is_variable() const{
    return std::holds_alternative<VariableBase*>(value_);
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_expression() const{
    return std::holds_alternative<ArithmeticTree>(value_);
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_value() const{
    return std::holds_alternative<Value_t>(value_);
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_variable() const{
    return std::holds_alternative<VariableBase*>(value_);
}

template<>
Value_t Bound_T<TOP_BOUND_T>::get() const{
    if(is_value())
        return std::get<Value_t>(value_);
    else if(is_expression())
        return std::get<ArithmeticTree>(value_).execute();
    else if(is_variable()){
        if(std::get<VariableBase*>(value_))
            return std::get<VariableBase*>(value_)->node()->execute();
        else {
            value_ = Value_t(0);
            return std::get<Value_t>(value_);
        }
    }
    else throw std::runtime_error("Bound error");
}

template<>
Value_t Bound_T<BOTTOM_BOUND_T>::get() const{
    if(is_value())
        return std::get<Value_t>(value_);
    else if(is_expression())
        return std::get<ArithmeticTree>(value_).execute();
    else if(is_variable()){
        if(std::get<VariableBase*>(value_))
            return std::get<VariableBase*>(value_)->node()->execute();
        else {
            value_ = Value_t(0);
            return std::get<Value_t>(value_);
        }
    }
    else throw std::runtime_error("Bound error");
}

std::optional<Value_t> VariableBounds::get_bottom_bound_value() const{
    if(bottom_bound_)
        return bottom_bound_->get();
    else return std::nullopt;
}

std::optional<Value_t> VariableBounds::get_top_bound_value() const{
    if(top_bound_)
        return top_bound_->get();
    else return std::nullopt;
}

void VariableBounds::unset_bottom_bound(){
    bottom_bound_.reset();
}

void VariableBounds::unset_top_bound(){
    top_bound_.reset();
}

bool VariableBounds::is_in_bounds(Value_t&& value) const{
    return is_in_bounds(value);
}

bool VariableBounds::is_in_bounds(const Value_t& value) const{
    bool in = true;
    if(bottom_bound_){
        if(bottom_bound_->type_==BOTTOM_BOUND_T::LARGER)
            in = in & (bottom_bound_->get()<value);
        else /*LARGER_OR_EQUAL*/
            in = in & (bottom_bound_->get()<=value);
    }
    if(top_bound_){
        if(top_bound_->type_==TOP_BOUND_T::LESS)
            in = in & (top_bound_->get()>value);
        else /*LESS_OR_EQUAL*/
            in = in & (top_bound_->get()>=value);
    }
    return in;
}

bool VariableBounds::is_in_bounds(const VariableBase& var) const{
    if(var.is_arithmetic_tree())
        return is_in_bounds(var.get<ArithmeticTree>());
    else if(var.is_value())
        return is_in_bounds(var.get<Value_t>());
    else return true;
}

bool VariableBounds::is_in_bounds(const ArithmeticTree& tree) const{
    return is_in_bounds(tree.value());
}