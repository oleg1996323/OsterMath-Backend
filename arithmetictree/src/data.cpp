#include "data.h"
#include "def.h"
#include "types.h"
#include "expr_parser.h"

using namespace std::string_literals;

BaseData::BaseData(std::string_view name):name_(name){}

VariableBase* BaseData::get(std::string_view name){
    if(!exists(name))
        return nullptr;
    else
        return vars_.at(name)?vars_.at(name).get():nullptr; 
};

const VariableBase* BaseData::get(std::string_view name) const{
    return get(name); 
};

bool BaseData::exists(std::string_view name) const{
    return vars_.contains(name);
}

bool BaseData::defined(std::string_view name) const{
    if(exists(name)){
        if(vars_.at(name))
            return true;
        else return false;
    }
    else return false;
}

std::shared_ptr<VariableBase>& BaseData::add_variable(std::string&& name){
    if(!exists(name)){
        auto str_name = var_names_.emplace(name).first;
        return vars_.emplace(
            *str_name,
            std::make_shared<VariableBase>(*str_name,this)).first->second;
    }
    else return vars_.find(name)->second;
}

void BaseData::erase(std::string_view var_name){
    vars_.erase(var_name);
}

#include <iostream>
#include "expr_parser.h"

void BaseData::setstream(std::istream& stream){
    parser_=std::make_unique<Parser>(stream, this);
}

void BaseData::parse_entry(){
    return parser_->parse_entry();
}

std::ostream& BaseData::print(std::ostream& stream, std::string_view name){
    stream<<get(name)->get();
    return stream;
}

DataPool::DataPool(const std::string& name):name_(name){}

std::string_view DataPool::name(){
    return name_;
}

void DataPool::add_data(const std::string& name){
    if(!exists(name)){
        std::string_view name_sv = *(data_names_.emplace(name).first);
        data_bases_.emplace(name_sv,name_sv);
    }
    return;
}

bool DataPool::exists(std::string_view name) const{
    return data_bases_.contains(name);
}

void DataPool::erase(std::string_view name){
    if(exists(name)){
        data_bases_.erase(name);
        data_names_.erase(std::string(name));
    }
}

void DataPool::replace(const std::string& name) noexcept{
    if(exists(name)){
        data_bases_.at(name) = BaseData(*data_names_.find(name));
    }
}

BaseData* DataPool::get(std::string_view name_data) noexcept{
    if(exists(name_data))
        return &data_bases_.at(name_data);
    else return nullptr;
}