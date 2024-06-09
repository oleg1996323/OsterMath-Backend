#include "data.h"
#include "def.h"
#include "types.h"
#include "expr_parser.h"
#include "arithmetic_types.h"

using namespace std::string_literals;

BaseData::BaseData(std::string_view name):name_(name){}

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

void BaseData::set_name(const std::string& name){
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

DataPool::DataPool(const std::string& name):name_(name){
    add_data("anon"s);
}

std::string_view DataPool::name(){
    return name_;
}

void DataPool::set_name(const std::string& name){
    name_ = name;
}

BaseData* DataPool::add_data(const std::string& name){
    if(!exists(name)){
        std::string_view name_sv = *(data_names_.emplace(name).first);
        data_bases_.emplace(name_sv,name_sv).first->second.set_pool(this);
    }
    return &data_bases_.at(name);
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

size_t DataPool::size() const{
    return data_names_.size();
}

const BaseData* DataPool::get(std::string_view name_data) const noexcept{
    if(exists(name_data))
        return &data_bases_.at(name_data);
    else return nullptr;
}

BaseData* DataPool::get(std::string_view name_data) noexcept{
    if(exists(name_data))
        return &data_bases_.at(name_data);
    else return nullptr;
}

#include "serialize.h"

void BaseData::serialize(serialization::SerialData& serial_data){
    serial_data.data_stream_.write("#SHEETNAME_", 11);
    serial_data.data_stream_.write(name_.begin(), name_.size());
    serial_data.data_stream_.write("\n",1);
    serial_data.data_stream_.write("#DATAPOOL_", 10);
    serial_data.data_stream_.write(pool_->name().begin(),pool_->name().size());
    serial_data.data_stream_.write("#VARIABLES", 10);
    for(auto var_data:vars_){
        stream.write(var_data.first.begin(), var_data.first.size()); //name
        stream<<std::endl; //control symbol
        var_data.second->serialize(stream);
    }
}

void BaseData::serialize_header(serialization::SerialData& serial_data) const{
    //access every nodes of BaseData variables (including the comparing structures)
    for(auto& [name,var_base]:vars_){
        serial_data.insert_node(reinterpret_cast<const std::shared_ptr<Node>&>(var_base->node()));
        var_base->node()->deserialize_header(serial_data,var_base->node());
    }

    for(const std::shared_ptr<Node>& node:serial_data.)
}

void BaseData::deserialize(serialization::SerialData& serial_data){
    
}

void DataPool::serialize(serialization::SerialData& serial_data){
    serial_data.data_stream_.write("#BOOKMATHNAME_", 14);
    serial_data.data_stream_.write(name_.c_str(), name_.size());
    serial_data.data_stream_.write("\n",1);
    for(auto& data:data_bases_)
        data.second.serialize_header(serial_data);

    for(auto& data:data_bases_)
        data.second.serialize(serial_data);
}

void DataPool::deserialize(serialization::SerialData& serial_data){

}