#include "data.h"

using namespace std::string_literals;

const VariableBase* BaseData::get(std::string_view name) const{
    if(!exists(name))
        return nullptr;
    else
        return vars_.at(name)?vars_.at(name).get():nullptr; 
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

template<typename T>
std::shared_ptr<VariableBase>& BaseData::add_variable(std::string&& name, T&& value){
    if(!exists(name)){
        auto str_name = var_names_.emplace(name).first;
        return vars_.emplace(
            *str_name,
            std::make_shared<VariableBase>(*str_name,std::forward<T>(value),this)).first->second;
    }
    else return vars_.find(name)->second;
}

template<typename T>
void BaseData::define(std::string_view name, T&& value){
    if(exists(name)){
        if(!defined(name)){
            auto ref = vars_.find(name);
            ref->second = std::shared_ptr<VariableBase>(ref->first,std::forward<T>(value));
            return;
        }
        else
            throw std::logic_error("Variable "s+std::string(name)+" already defined."s);
    }
    else throw std::logic_error("Variable "s+std::string(name)+" don't exists."s);
}

void BaseData::erase(std::string_view var_name){
    vars_.erase(var_name);
}

#include "expr_parser.h"

void BaseData::setstream(std::iostream& stream){
    parser_=std::make_unique<Parser>(stream);
}

std::ostream& BaseData::print(std::ostream& stream, std::string_view name){
    stream<<get(name)->get();
    return stream;
}

DataPool::DataPool(const std::string& name):name_(name){}

std::string_view DataPool::name(){
    return name_;
}