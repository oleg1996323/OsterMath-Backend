#include <node.h>
#include "bound.h"
#include "types.h"
#include "arithmetic_types.h"

template<>
bool Bound_T<TOP_BOUND_T>::is_defined() const{
    return value_.get()!=nullptr;
}

template<>
bool Bound_T<TOP_BOUND_T>::is_value() const{
    return is_defined() && value_->type()==NODE_TYPE::VALUE;
}

template<>
bool Bound_T<TOP_BOUND_T>::is_variable() const{
    return is_defined() && value_->type()==NODE_TYPE::VARIABLE;
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_defined() const{
    return value_.get()!=nullptr;
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_value() const{
    return is_defined() && value_->type()==NODE_TYPE::VALUE;
}

template<>
bool Bound_T<BOTTOM_BOUND_T>::is_variable() const{
    return is_defined() && value_->type()==NODE_TYPE::VARIABLE;
}

template<>
Value_t Bound_T<TOP_BOUND_T>::get() const{
    return value_->execute().get<Value_t>();
}

template<>
Value_t Bound_T<BOTTOM_BOUND_T>::get() const{
    return value_->execute().get<Value_t>();
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

void VariableBounds::set_bound_value(std::shared_ptr<Node> value, BOTTOM_BOUND_T type){
    if(bottom_bound_){
        bottom_bound_->type_=type;
        bottom_bound_->value_=value;
    }
    else {
        bottom_bound_ = std::make_unique<Bound_T<BOTTOM_BOUND_T>>();
        bottom_bound_->type_=type;
        bottom_bound_->value_=value;
    }
}

void VariableBounds::set_bound_value(std::shared_ptr<Node> value, TOP_BOUND_T type){
    if(top_bound_){
        top_bound_->type_=type;
        top_bound_->value_=value;
    }
    else {
        top_bound_ = std::make_unique<Bound_T<TOP_BOUND_T>>();
        top_bound_->type_=type;
        top_bound_->value_=value;
    }
}

// bool VariableBounds::is_in_bounds(const VariableBase& var) const{
//     if(var.is_arithmetic_tree())
//         return is_in_bounds(var.get<ArithmeticTree>());
//     else if(var.is_value())
//         return is_in_bounds(var.get<Value_t>());
//     else return true;
// }

// bool VariableBounds::is_in_bounds(const ArithmeticTree& tree) const{
//     return is_in_bounds(tree.value());
// }