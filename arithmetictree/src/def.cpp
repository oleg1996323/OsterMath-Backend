#include "def.h"
#include "node.h"
#include "arithmetic_functions.h"
#include "arithmetic_types.h"
#include <string>

Result_t& Result::get(){
    return *this;
}

const Result_t& Result::get() const{
    return *this;
}

bool Result::is_value() const{
    return std::holds_alternative<Value_t>(*this);
}

bool Result::is_string() const{
    return std::holds_alternative<std::string>(*this);
}

bool Result::is_node() const{
    return std::holds_alternative<Node*>(*this);
}

bool Result::is_array() const{
    return is_node() && get<Node*>()->is_array();
}

bool Result::has_value() const{
    return !std::holds_alternative<std::monostate>(*this);
}

std::ostream& Result::operator<<(std::ostream& os)
{
    std::visit([this,&os](auto&& arg) {
        if(this->is_node())
            this->get<Node*>()->print_result(os);
        os << arg;
    }, *this);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Result& res){
    if(res.is_node())
        res.get<Node*>()->print_result(os);
    else std::visit([&os](auto&& arg) {
        os << arg;
    },res);
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

bool ProxySizeDepthMeasure::operator++(){
    if(next_level_)
        return ++(*next_level_.get());
    else return increase_iterator();
}

bool ProxySizeDepthMeasure::is_iterable() const{
    if(current_iterator_+1<sz_)
        return true;
    else if(next_level_ && next_level_->is_iterable())
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

void ProxySizeDepthMeasure::depth(size_t& uppper_depth){
    ++uppper_depth;
    if(next_level_)
        next_level_->depth(uppper_depth);
    else return;
}

void ProxySizeDepthMeasure::reset_iterator(){
    current_iterator_ = 0;
    if(next_level_)
        next_level_->reset_iterator();
}

size_t ProxySizeDepthMeasure::current_iterator(int32_t depth) const{
    if(depth>=0){
        if(depth>0){
            if(next_level_){
                --depth;
                return next_level_->current_iterator_ref(depth);
            }
            else 
                throw std::invalid_argument("Unavailable depth");
        }
        else if(depth==0)
            return current_iterator_;
        else
            throw std::invalid_argument("Unavailable depth");
        return current_iterator_;
    }
    else throw std::invalid_argument("Argument cannot be less than 0");
}

size_t ProxySizeDepthMeasure::current_iterator_ref(int32_t& depth) const{
    if(depth>=0){
        if(depth>0){
            if(next_level_){
                --depth;
                return next_level_->current_iterator_ref(depth);
            }
            else 
                throw std::invalid_argument("Unavailable depth");
        }
        else if(depth==0)
            return current_iterator_;
        else
            throw std::invalid_argument("Unavailable depth");
        return current_iterator_;
    }
    else throw std::invalid_argument("Argument cannot be less than 0");
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

size_t ProxySizeDepthMeasure::seq_iterator(int32_t depth) const{
    if(depth>=0){
        if(depth>0){
            if(next_level_){
                --depth;
                //std::cout<<"Total size childs: "<<total_size_childs()<<std::endl;
                return next_level_->total_size_childs()*current_iterator_+next_level_->seq_iterator_ref(depth);
            }
            else 
                throw std::invalid_argument("Unavailable depth");
        }
        else if(depth==0)
            return current_iterator_;
        else
            throw std::invalid_argument("Unavailable depth");
        return current_iterator_;
    }
    else throw std::invalid_argument("Argument cannot be less than 0");
}

size_t ProxySizeDepthMeasure::seq_iterator_ref(int32_t& depth) const{
    if(depth>=0){
        if(depth>0){
            if(next_level_){
                --depth;
                return next_level_->total_size_childs()*current_iterator_+next_level_->seq_iterator_ref(depth);
            }
            else 
                throw std::invalid_argument("Unavailable depth");
        }
        else if(depth==0)
            return current_iterator_;
        else
            throw std::invalid_argument("Unavailable depth");
        return current_iterator_;
    }
    else throw std::invalid_argument("Argument cannot be less than 0");
}

bool ProxySizeDepthMeasure::increase_iterator(){
    if(++current_iterator_<sz_)
        return true;
    else {
        if(parent_){
            current_iterator_ = 0;
            return parent_->increase_iterator();
        }
        else return false;
    }
}

size_t ProxySizeDepthMeasure::total_size_childs() const{
    if(total_childs_==0){
        if(next_level_){
            total_childs_ = sz_*next_level_->total_size_childs();
        }
        else total_childs_ = sz_;
    }
    return total_childs_;
}