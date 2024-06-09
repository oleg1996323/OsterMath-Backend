#include "def.h"
#include "types.h"
#include "arithmetic_types.h"
#include "data.h"

void VariableBase::print_result(){
    get_stream()<<result()<<std::endl;
}

void VariableBase::print_text(){
    get_stream()<<text()<<std::endl;
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

Result VariableBase::result(){
    return node_->execute();
}

Result VariableBase::result() const{
    return node_->execute();
}

std::string VariableBase::text(){
    std::ostringstream stream;
    node_->print_text(stream);
    stream<<" = ";
    if(node_->has_childs()){
        node_->child(0)->print_text(stream);
    }
    else stream<<"#NAN";
    return stream.str();
}

std::string VariableBase::text() const{
    std::ostringstream stream;
    node_->print_text(stream);
    return stream.str();
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
    return node_->has_childs() && node_->is_numeric();
}

bool VariableBase::is_string() const{
    return node_->has_childs() && node_->is_string();
}

bool VariableBase::is_array() const{
    return node_->has_childs() && node_->is_array();
}

bool VariableBase::is_undef() const{
    return !node_->has_childs();
}

bool VariableBase::is_numeric() const{
    return node_->is_numeric();
}

VariableBase::~VariableBase(){}

bool VariableBase::is_in_bounds(std::string_view data_base,std::string_view name) const{
    if(bounds_.contains(data_base))
        if(bounds_.at(data_base).contains(name)){
            VariableBase* var = data_base_->get_pool()->get(data_base)->get(name);
            if(var->is_numeric() && !var->is_array())
                return bounds_.at(data_base).at(name).is_in_bounds(var->result().get<Value_t>());
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

void VariableBase::set_bottom_bound_value(std::string_view data_base,std::string_view var_name,std::shared_ptr<Node> value, BOTTOM_BOUND_T type){
    bounds_[data_base][var_name].set_bound_value(value,type);
    #ifdef DEBUG
    std::cout << var_name<<' ';
    if(type == BOTTOM_BOUND_T::LARGER)
        std::cout<<"larger than ";
    else std::cout<<"larger or equal than ";
    std::cout<<value->execute()<<" in "<<name()<<std::endl;
    #endif
}

void VariableBase::set_top_bound_value(std::string_view data_base,std::string_view var_name,std::shared_ptr<Node> value, TOP_BOUND_T type){
    bounds_[data_base][var_name].set_bound_value(value,type);
    #ifdef DEBUG
    std::cout << var_name<<' ';
    if(type == TOP_BOUND_T::LESS)
        std::cout<<"less than ";
    else std::cout<<"less or equal than ";
    std::cout<<value->execute()<<" in "<<name()<<std::endl;
    #endif
}