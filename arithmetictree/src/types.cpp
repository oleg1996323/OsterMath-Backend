#include "def.h"
#include "types.h"
#include "arithmetic_types.h"
#include "data.h"

std::ostream& VariableBase::operator<<(std::ostream& stream){
    if(get_type()!=FormattingData::OUTPUT_TYPE::DEFAULT){
        stream<<std::setprecision(get_precision());
        if(get_type()==FormattingData::OUTPUT_TYPE::SCIENTIFIC)
            stream<<std::scientific;
        else if(get_type()==FormattingData::OUTPUT_TYPE::FIXED)
            stream<<std::fixed;
        else throw std::runtime_error("Unknown format");
    }
    stream<<*this;
    return stream;
}

void VariableBase::print(){
    get_stream()<<*this<<std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Arr_value& val){
    std::visit([&stream](const auto& x) { stream << x; }, val);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::monostate empty){
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Variable_t& var){
    std::visit([&stream](const auto& x) { stream << std::defaultfloat<<x; }, var);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const ArithmeticTree& tree){
    stream<<std::defaultfloat<<tree.value();
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

const std::shared_ptr<VariableNode>& VariableBase::node(){
    return node_;
}

bool VariableBase::is_expression() const{
    return node_->has_childs() && (node_->type() == NODE_TYPE::UNARY || node_->type() == NODE_TYPE::BINARY);
}

bool VariableBase::is_value() const{
    return node_->has_childs() && node_->type() == NODE_TYPE::VALUE;
}

bool VariableBase::is_string() const{
    return node_->has_childs() && node_->type() == NODE_TYPE::STRING;
}

bool VariableBase::is_array() const{
    return node_->has_childs() && node_->type() == NODE_TYPE::ARRAY;
}

bool VariableBase::is_undef() const{
    return !node_->has_childs();
}

bool VariableBase::is_numeric() const{
    return !is_undef() && !is_string() && !(is_array() && this->get<Array_t>().type()!=TYPE::STRING);
}

void VariableBase::value_to_tree(){
    if(is_value()){
        ArithmeticTree tree(this);
        tree.insert(std::make_shared<ValueNode>(std::move(get<Value_t>())));
        this->get()=std::move(tree);
    }
}

void VariableBase::tree_to_value(){
    if(is_arithmetic_tree())
        get() = get<ArithmeticTree>().value();
}

VariableBase::~VariableBase(){}

bool VariableBase::is_in_bounds(std::string_view data_base,std::string_view name) const{
    if(bounds_.contains(data_base))
        if(bounds_.at(data_base).contains(name)){
            const VariableBase& var = *data_base_->get_pool()->get(data_base)->get(name);
            if(var.is_arithmetic_tree())
                return bounds_.at(data_base).at(name).is_in_bounds(var);
            else if(var.is_value())
                return bounds_.at(data_base).at(name).is_in_bounds(var);
            else return true;
        }
        else return true;
    else return true;
}

std::optional<Value_t> VariableBase::get_top_bound(std::string_view data_base,std::string_view var_name){
    if(bounds_.contains(data_base)){
        if(bounds_.at(data_base).contains(var_name)){
            return bounds_.at(data_base).at(var_name).get_top_bound_value();
        }
        else return std::nullopt;
    }
    else return std::nullopt;
}

std::optional<Value_t> VariableBase::get_bottom_bound(std::string_view data_base,std::string_view var_name){
    if(bounds_.contains(data_base)){
        if(bounds_.at(data_base).contains(var_name)){
            return bounds_.at(data_base).at(var_name).get_bottom_bound_value();
        }
        else return std::nullopt;
    }
    else return std::nullopt;
}

std::string_view VariableBase::get_data_base_name() const{
    return data_base_->name();
}

const std::unordered_set<VariableNode*>& Array_t::get_dependencies() const{
    return var_dependence_;
}
