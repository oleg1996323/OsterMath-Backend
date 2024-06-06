#include "def.h"
#include "arithmetic_types.h"
#include "arithmetic_functions.h"
#include <string>

Result_t& Result::get(){
    return *this;
}

const Result_t& Result::get() const{
    return *this;
}

bool Result::is_array() const{
    return std::holds_alternative<std::shared_ptr<ArrayNode>>(*this);
}

bool Result::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool Result::is_string() const{
    return std::holds_alternative<std::string>(*this);
}

bool Result::is_variable() const{
    return std::holds_alternative<std::shared_ptr<VariableNode>>(*this);
}

bool Result::has_value() const{
    return !std::holds_alternative<std::monostate>(*this);
}

std::ostream& Result::operator<<(std::ostream& os)
{
    std::visit([&os](auto&& arg) {
        os << arg;
    }, *this);
    return os;
}

ProxySizeDepthMeasure::ProxySizeDepthMeasure(size_t new_size):
    parent_(nullptr),
    sz_(new_size>0?new_size:throw std::invalid_argument("Argument cannot be 0"))
    {}

ProxySizeDepthMeasure::ProxySizeDepthMeasure(size_t new_size, ProxySizeDepthMeasure* parent):
    parent_(parent),
    sz_(new_size>0?new_size:throw std::invalid_argument("Argument cannot be 0"))
    {}

ProxySizeDepthMeasure& ProxySizeDepthMeasure::operator++(){
    if(next_level_)
        return ++(*next_level_.get());
    else return increase_iterator();
}

bool ProxySizeDepthMeasure::is_iterable() const{
    if(current_iterator_<sz_ || (next_level_ && next_level_->is_iterable()))
        return true;
    else return false;
}

void ProxySizeDepthMeasure::push(size_t new_size){
    if(new_size>0){
        if(next_level_)
            next_level_->push(new_size);
        else next_level_=std::make_unique<ProxySizeDepthMeasure>(new_size,this);
    }
    else throw std::invalid_argument("Argument cannot be 0");
}

size_t ProxySizeDepthMeasure::depth(){
    size_t depth = 1;
    if(next_level_)
        next_level_->depth(depth);
    return depth; 
}

void ProxySizeDepthMeasure::reset_iterator(){
    current_iterator_ = 0;
    if(next_level_)
        next_level_->reset_iterator();
}

size_t ProxySizeDepthMeasure::current_iterator(size_t depth) const{
    if(depth>0){
        --depth;
        if(next_level_ && depth!=0)
            return next_level_->current_iterator_ref(depth);
        if(depth!=0)
            throw std::invalid_argument("Unavailable depth");
        return current_iterator_;
    }
    else throw std::invalid_argument("Argument cannot be 0");
}

size_t ProxySizeDepthMeasure::current_iterator_ref(size_t& depth) const{
    --depth;
    if(next_level_ && depth!=0)
        return next_level_->current_iterator_ref(depth);
    if(depth!=0)
        throw std::invalid_argument("Unavailable depth");
    return current_iterator_;
}

void ProxySizeDepthMeasure::depth(size_t& uppper_depth){
    ++uppper_depth;
    if(next_level_)
        depth(uppper_depth);
    else return;
}

size_t ProxySizeDepthMeasure::size(size_t depth) const{
    if(depth>0){
        --depth;
        if(next_level_ && depth!=0)
            return next_level_->size_ref(depth);
        if(depth!=0)
            throw std::invalid_argument("Unavailable depth");
        return sz_;
    }
    else throw std::invalid_argument("Argument cannot be 0");
}

size_t ProxySizeDepthMeasure::size_ref(size_t& depth) const{
    --depth;
    if(next_level_ && depth!=0)
        return next_level_->size_ref(depth);
    if(depth!=0)
        throw std::invalid_argument("Unavailable depth");
    return sz_;
}

size_t ProxySizeDepthMeasure::seq_iterator(size_t depth) const{
    if(depth>0){
        --depth;
        if(next_level_ && depth!=0){
            return total_size_childs()*current_iterator_+next_level_->seq_iterator_ref(depth);
        }
        if(depth!=0)
            throw std::invalid_argument("Unavailable depth");
        return sz_;
    }
    else throw std::invalid_argument("Argument cannot be 0");
}

size_t ProxySizeDepthMeasure::seq_iterator_ref(size_t& depth) const{
    --depth;
    if(next_level_ && depth!=0){
        return total_size_childs()*current_iterator_+next_level_->seq_iterator_ref(depth);
    }
    if(depth!=0)
        throw std::invalid_argument("Unavailable depth");
    return sz_;
}

ProxySizeDepthMeasure& ProxySizeDepthMeasure::increase_iterator(){
    if(current_iterator_<sz_-1){
        ++current_iterator_;
        return *this;
    }
    else {
        current_iterator_ = 0;
        if(parent_)
            parent_->increase_iterator();
        return *this;
    }
}

size_t ProxySizeDepthMeasure::total_size_childs() const{
    if(next_level_)
        return next_level_->total_size_childs();
    else return sz_;
}