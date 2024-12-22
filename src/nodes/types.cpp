#include "def.h"
#include "types.h"
#include "arithmetic_types.h"
#include "data.h"

void VariableBase::print_result(){
    get_stream()<<result();
}

void VariableBase::print_text(){
    get_stream()<<text();
}

VariableBase::VariableBase(std::string_view name, BaseData* data_base):
    node_(std::make_unique<VariableNode>(this)),
    domains_(node_.get()),
    name_(name),
    data_base_(data_base)
{}

std::string VariableBase::name() const{
    return std::string(name_);
}

void VariableBase::set_name(std::string_view name){
    name_=name;
}

#include "arithmetic_types.h"

void VariableBase::refresh() const{
    node_->refresh_parent_links();
    node_->refresh();
}

void VariableBase::set_data_base(BaseData* data_base){
    data_base_=data_base;
}

const BaseData* VariableBase::get_data_base() const{
    return data_base_;
}

Result VariableBase::result(){
    return domains_.execute();
}

Result VariableBase::result() const{
    return domains_.execute();
}

std::string VariableBase::text(){
    std::ostringstream stream;
    #ifndef USER_INTERFACE
    node_->print_text(stream);
    #endif
    stream<<" = ";
    if(node_->has_childs()){
        node_->child(0)->print_text(stream);
    }
    else stream<<"#NAN";
    std::string str = stream.str();
    return stream.str();
}

std::string VariableBase::text() const{
    std::ostringstream stream;
    node_->print_text(stream);
    return stream.str();
}

const VariableNode* VariableBase::node() const{
    return node_.get();
}

VariableNode* VariableBase::node(){
    return node_.get();
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

TYPE_VAL VariableBase::type() const{
    if(node_->has_childs()){
        return node_->type_val();
    }
    else
        return TYPE_VAL::UNKNOWN;
}

VariableBase::~VariableBase(){}

void VariableBase::add_domain(Domain&& domain){
    domains_.add_domain(std::move(domain));
}

VariableDomain& VariableBase::get_domains(){
    return domains_;
}

const VariableDomain& VariableBase::get_domains() const{
    return domains_;
}

std::string VariableBase::get_data_base_name() const{
    return std::string(data_base_->name());
}

std::string VariableBase::full_name() const{
    std::string str;
    std::stringstream sstream(str);
    node_->print_text(sstream);
    return sstream.str();
}