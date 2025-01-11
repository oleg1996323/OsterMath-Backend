#include "def.h"
#include "abstract_node.h"
#include "arithmetic_types.h"
#include "events_errors/abstract_event.h"
#include "events_errors/warning.h"
#include "events_errors/exception.h"
#include <string>

TYPE_VAL operator|(TYPE_VAL lhs,TYPE_VAL rhs){
    return static_cast<TYPE_VAL>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

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
    return std::holds_alternative<const AbstractNode*>(*this);
}

bool Result::is_array() const{
    return is_node() && get<const AbstractNode*>()->is_array();
}

bool Result::has_value() const{
    return !std::holds_alternative<std::monostate>(*this);
}

bool Result::is_event() const{
    return std::holds_alternative<std::shared_ptr<AbstractEvent>>(*this);
}

bool Result::is_error() const{
    return is_event()?(dynamic_cast<exceptions::Exception*>(get<std::shared_ptr<AbstractEvent>>().get())?true:false):false;
}

bool Result::is_warning() const{
    return is_event()?(dynamic_cast<warnings::Warning*>(get<std::shared_ptr<AbstractEvent>>().get())?true:false):false;
}

Result Result::operator+(const Result& other){
    if(is_error())
        return this->get_exception();
    if(other.is_error())
        return other.get_exception();
    if(is_value() && other.is_value())
        return get_value()+other.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result Result::operator-(const Result& other){
    if(is_error())
        return this->get_exception();
    if(other.is_error())
        return other.get_exception();
    if(is_value() && other.is_value())
        return get_value()-other.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result Result::operator*(const Result& other){
    if(is_error())
        return this->get_exception();
    if(other.is_error())
        return other.get_exception();
    if(is_value() && other.is_value())
        return get_value()*other.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}

Result Result::operator/(const Result& other){
    if(is_error())
        return this->get_exception();
    if(other.is_error())
        return other.get_exception();
    if(is_value() && other.is_value()){
        if(other.get_value()==0.)
            return std::make_shared<exceptions::DivisionZero>();
        return get_value()/other.get_value();
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result Result::operator^(const Result& other){
    using namespace boost::multiprecision;
    using namespace std;
    if(is_error())
        return this->get_exception();
    if(other.is_error())
        return other.get_exception();
    if(is_value() && other.is_value()){
        return pow(get_value(),other.get_value());
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}

Result& Result::operator+=(const Result& other){
    *this = *this+other;
    return *this;
}
Result& Result::operator-=(const Result& other){
    *this = *this-other;
    return *this;
}
Result& Result::operator*=(const Result& other){
    *this = *this*other;
    return *this;
}
Result& Result::operator/=(const Result& other){
    *this = *this/other;
    return *this;
}
Result& Result::operator^=(const Result& other){
    *this = *this^other;
    return *this;
}

Result operator+(const Result& lhs, const Result& rhs){
    if(lhs.is_error())
        return lhs.get_exception();
    if(rhs.is_error())
        return rhs.get_exception();
    if(lhs.is_value() && rhs.is_value())
        return lhs.get_value()+rhs.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result operator-(const Result& lhs, const Result& rhs){
    if(lhs.is_error())
        return lhs.get_exception();
    if(rhs.is_error())
        return rhs.get_exception();
    if(lhs.is_value() && rhs.is_value())
        return lhs.get_value()-rhs.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result operator*(const Result& lhs, const Result& rhs){
    if(lhs.is_error())
        return lhs.get_exception();
    if(rhs.is_error())
        return rhs.get_exception();
    if(lhs.is_value() && rhs.is_value())
        return lhs.get_value()*rhs.get_value();
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result operator/(const Result& lhs, const Result& rhs){
    if(lhs.is_error())
        return lhs.get_exception();
    if(rhs.is_error())
        return rhs.get_exception();
    if(lhs.is_value() && rhs.is_value()){
        if(rhs.get_value()==0.)
            return std::make_shared<exceptions::DivisionZero>();
        return lhs.get_value()/rhs.get_value();
    }
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}
Result operator^(const Result& lhs, const Result& rhs){
    if(lhs.is_error())
        return lhs.get_exception();
    if(rhs.is_error())
        return rhs.get_exception();
    if(lhs.is_value() && rhs.is_value())
        return pow(lhs.get_value(),rhs.get_value());
    else return std::make_shared<exceptions::InvalidTypeOfArgument>("numeric value");
}

#include "aux_functions.h"

bool operator==(const Value_t& val, const Result& res){
    return res.is_value() && val == res.get_value();
}
bool operator==(const Result& res,const Value_t& val){
    return res.is_value() && val == res.get_value();
}
bool operator==(const std::string& val, const Result& res){
    return res.is_string() && val == res.get_string();
}
bool operator==(const Result& res,const std::string& val){
    return res.is_string() && val == res.get_string();
}
// bool operator==(std::shared_ptr<ArrayNode> val, const Result& res){
//     return res.is_array_result() && ::functions::auxiliary::equal_morphology_nodes(std::vector<std::shared_ptr<AbstractNode>>{val,res.get_array_result()});
// }
// bool operator==(const Result& res,std::shared_ptr<ArrayNode> val){
//     return res.is_array_result() && ::functions::auxiliary::equal_morphology_nodes(std::vector<std::shared_ptr<AbstractNode>>{val,res.get_array_result()});
// }

std::ostream& Result::operator<<(std::ostream& os) const
{
    std::visit([this,&os](auto arg) {
        if(this->is_node())
            this->get_node()->print_result(os);
        else if(this->is_array())
            this->get_array_node()->print_result(os);
        else if(!this->has_value())
            os << "#NaN!";
        else if(this->is_error())
            os << this->get_exception()->error_abbr();
        else
            os << arg;
    }, *this);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Result& res){
    return res.operator<<(os);
}

void SizeDepthMeasure::push_depth(size_t new_size){
    if(new_size>0)
        std::vector<size_iterator>::emplace_back(new_size);
    else throw std::invalid_argument("Size cannot be 0");
}

void SizeDepthMeasure::reset_iterator(size_t depth){
    if(std::vector<size_iterator>::size()<=depth)
        throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
    at(depth).current_iterator_ = 0;
}

void SizeDepthMeasure::reset_all_iterators(){
    for(auto& index:*this)
        index.current_iterator_ = 0;
}

size_t SizeDepthMeasure::current_iterator(size_t depth) const{
    if(std::vector<size_iterator>::size()<=depth)
        throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
    return at(depth).current_iterator_;
}

bool SizeDepthMeasure::set_iterator(size_t depth, size_t iterator){
    if(depth>=dimensions())
        return false;
    else {
        if(iterator>=at(depth).sz_){
            return false;
        }
        at(depth).current_iterator_ = iterator;
        return true;
    }
}

void SizeDepthMeasure::lock(size_t depth){
    if(depth>=dimensions())
        throw std::invalid_argument("depth have to be less than dimensions size");
    else at(depth).lock = true;
}
void SizeDepthMeasure::unlock(size_t depth){
    if(depth>=dimensions())
        throw std::invalid_argument("depth have to be less than dimensions size");
    else at(depth).lock = false;
}

SizeDepthMeasure& SizeDepthMeasure::operator++(int){
    for(std::vector<size_iterator>::reverse_iterator index = rbegin();
        index<rend();++index){
        if(index->lock)
            continue;
        if(index->is_iterable()){
            ++(*index);
            break;
        }
        else{
            index->current_iterator_=0;
        }
    }
    return *this;
}

SizeDepthMeasure& SizeDepthMeasure::operator++(){
    for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
        index!=std::vector<size_iterator>::rend();++index){
        if(index->lock)
            continue;
        if(index->is_iterable()){
            ++(*index);
            break;
        }
        else{
            index->current_iterator_=0;
        }
    }
    return *this;
}

SizeDepthMeasure& SizeDepthMeasure::operator--(int){
    for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
        index!=std::vector<size_iterator>::rend();++index){
        if(index->lock)
            continue;
        if(index->is_decrement_iterable()){
            --(*index);
            break;
        }
        else{
            index->current_iterator_=index->sz_-1;
        }
    }
    return *this;
}

SizeDepthMeasure& SizeDepthMeasure::operator--(){
    for(std::vector<size_iterator>::reverse_iterator index = std::vector<size_iterator>::rbegin();
        index!=std::vector<size_iterator>::rend();++index){
        if(index->lock)
            continue;
        if(index->is_decrement_iterable()){
            --(*index);
            break;
        }
        else{
            index->current_iterator_=index->sz_-1;
        }
    }
    return *this;
}

bool SizeDepthMeasure::is_iterable() const{
    for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
        index!=std::vector<size_iterator>::rend();++index){
        if(index->is_iterable() && !index->lock)
            return true;
    }
    return false;
}

bool SizeDepthMeasure::is_decrement_iterable() const{
    for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
        index!=std::vector<size_iterator>::rend();++index){
        if(index->is_decrement_iterable() && !index->lock)
            return true;
    }
    return false;
}

size_t SizeDepthMeasure::size(size_t depth) const{
    if(std::vector<size_iterator>::size()<=depth)
        throw std::invalid_argument((std::string()+"Depth must be not bigger than "+std::to_string(std::vector<size_iterator>::size())).c_str());
    return at(depth).sz_;
}

size_t SizeDepthMeasure::dimensions() const{
    return std::vector<size_iterator>::size();
}

size_t SizeDepthMeasure::seq_iterator(uint32_t depth) const{
    size_t result = 0;
    size_t sz_ex_depths = 1;
    for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
        index<std::vector<size_iterator>::rend()-depth;++index){
        result+=index->current_iterator_*sz_ex_depths;
        sz_ex_depths*=index->sz_;
    }
    return result;
}

size_t SizeDepthMeasure::max_seq_iterator(uint32_t depth) const{
    size_t result = 0;
    size_t sz_ex_depths = 1;
    for(std::vector<size_iterator>::const_reverse_iterator index = std::vector<size_iterator>::rbegin();
        index<std::vector<size_iterator>::rend()-depth;++index){
        result+=index->sz_*sz_ex_depths;
        sz_ex_depths*=index->sz_;
    }
    return result;
}