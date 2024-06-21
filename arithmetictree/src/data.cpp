#include "data.h"
#include "def.h"
#include "types.h"
#include "expr_parser.h"
#include "arithmetic_types.h"

using namespace std::string_literals;

uint16_t BaseData::counter = 0;

BaseData::BaseData(std::string_view name):name_(name), data_count(counter++){}

VariableBase* BaseData::get(std::string_view name){
    if(!exists(name))
        throw std::invalid_argument("Variable "s + std::string(name) + " don't exists.\n");
    else
        return vars_.at(name)?vars_.at(name).get():nullptr; 
};

const VariableBase* BaseData::get(std::string_view name) const{
    return get(name); 
};

bool BaseData::exists(std::string_view name) const{
    return vars_.contains(name);
}

std::string_view BaseData::name() const{
    return name_;
}

void BaseData::set_name(std::string_view name){
    name_ = name;
}

bool BaseData::defined(std::string_view name) const{
    if(exists(name)){
        if(vars_.at(name))
            return true;
        else return false;
    }
    else return false;
}

void BaseData::rename_var(const std::string& current_name,const std::string& new_name){
    if(exists(current_name)){
        auto var = vars_.at(current_name);
        vars_.erase(current_name);
        var_names_.erase(current_name);
        var_names_.insert(new_name);
        var->set_name(vars_.emplace(new_name, var).first->first);
    }
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


#include <chrono>

std::string BaseData::generate_hash_name(){
    using namespace std::chrono;
    std::time_t time = system_clock::to_time_t(system_clock::now());
    std::string current_time = std::string(std::ctime(&time));
    return std::to_string(std::hash<std::string>()(current_time) | std::hash<std::string_view>()(name_));
}

void BaseData::erase(std::string_view var_name){
    vars_.erase(var_name);
}

#include <iostream>
#include "expr_parser.h"

void BaseData::setstream(std::istream& stream){
    if(parser_)
        parser_->set_stream(stream);
    else{
        parser_=std::make_unique<Parser>(stream,this);
    }
}

void BaseData::read_new(){
    if(parser_)
        parser_->parse_entry();
}

void BaseData::parse_entry(){
    return parser_->parse_entry();
}

void BaseData::set_pool(DataPool* pool){
    pool_ = pool;
}

const DataPool* BaseData::get_pool() const{
    return pool_;
}

DataPool* BaseData::get_pool(){
    return pool_;
}

const std::unordered_map<std::string_view,std::shared_ptr<VariableBase>> BaseData::variables() const{
    return vars_;
}

DataPool::DataPool(const std::string& name):name_(name){
    add_data("anon"s);
}

std::string_view DataPool::name(){
    return name_;
}

void DataPool::rename_database(const std::string& current_name, const std::string& new_name){
    if(exists(current_name)){
        BaseData* data = get(current_name);
        data->set_name(new_name);
        data_names_.erase(current_name);
        data_names_.insert(new_name);
    }
}

void DataPool::set_name(const std::string& name){
    name_ = name;
}

BaseData* DataPool::add_data(const std::string& name){
    if(!exists(name)){
        std::string_view name_sv = *(data_names_.emplace(name).first);
        data_bases_.emplace_back(std::make_shared<BaseData>(name_sv))->set_pool(this);
    }
    return get(name);
}

bool DataPool::exists(std::string_view name) const{
    auto result = std::find_if(data_bases_.begin(),data_bases_.end(),[name](const std::shared_ptr<BaseData>& data){
        return data->name()==name;
    });
    if(result!=data_bases_.end())
        return true;
    else return false;
}

void DataPool::erase(std::string_view name){
    auto result = std::find_if(data_bases_.begin(),data_bases_.end(),[name](const std::shared_ptr<BaseData>& data){
        return data->name()==name;
    });
    if(result!=data_bases_.end())
        data_bases_.erase(result);
    data_names_.erase(std::string(name));
}

size_t DataPool::size() const{
    return data_names_.size();
}

const BaseData* DataPool::get(std::string_view name_data) const noexcept{
    return get(name_data);
}

BaseData* DataPool::get(std::string_view name_data) noexcept{
    auto result = std::find_if(data_bases_.begin(),data_bases_.end(),[name_data](const std::shared_ptr<BaseData>& data){
        return data->name()==name_data;
    });
    return result!=data_bases_.end() && *result?result->get():nullptr;
}

const std::list<std::shared_ptr<BaseData>>& DataPool::data_bases() const{
    return data_bases_;
}

uint16_t BaseData::id() const{
    return data_count;
}