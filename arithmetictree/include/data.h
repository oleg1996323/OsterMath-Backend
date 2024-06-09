#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include "def.h"
#include "expr_parser.h"


class VariableBase;
class Parser;
class DataPool;

namespace serialization{
    class SerialData;
}

class BaseData{
    public:
    BaseData(std::string_view);

    VariableBase* get(std::string_view name);

    const VariableBase* get(std::string_view name) const;

    std::string_view name() const;

    void set_name(const std::string& name);

    bool exists(std::string_view name) const;

    bool defined(std::string_view name) const;

    std::shared_ptr<VariableBase>& add_variable(std::string&& name);

    template<typename T>
    std::shared_ptr<VariableBase>& add_variable(std::string&& name, T&& value);

    std::shared_ptr<VariableBase>& add_anonymous_var();

    template<typename T>
    std::shared_ptr<VariableBase>& add_anonymous_var(T&& value);

    template<typename T>
    void define(std::string_view name, T&& value);

    void erase(std::string_view var_name);

    void setstream(std::istream& stream);

    void set_pool(DataPool* pool);

    const DataPool* get_pool() const;

    DataPool* get_pool();

    void read_new();

    void parse_entry();

    void serialize(serialization::SerialData& serial_data);

    void deserialize(serialization::SerialData& serial_data);

    void serialize_header(serialization::SerialData& serial_data) const;

    void deserialize_header(serialization::SerialData& serial_data);

    private:
    std::unordered_set<std::string> var_names_;
    std::unordered_map<std::string_view,std::shared_ptr<VariableBase>> vars_;
    std::string_view name_;
    std::unique_ptr<Parser> parser_;
    DataPool* pool_;
    std::string generate_hash_name();
};

class DataPool{
    public:
    DataPool(const std::string& name);

    BaseData* add_data(const std::string& name);

    std::string_view name();

    void set_name(const std::string& name);

    const BaseData* get(std::string_view name_data) const noexcept;

    BaseData* get(std::string_view name_data) noexcept;

    bool exists(std::string_view name) const;

    void erase(std::string_view name);

    void replace(const std::string& name) noexcept;

    size_t size() const;

    void serialize(serialization::SerialData& serial_data);

    void deserialize(serialization::SerialData& serial_data);

    private:
    std::string name_;
    std::unordered_set<std::string> data_names_;
    std::unordered_map<std::string_view,BaseData> data_bases_;
};

using namespace std::string_view_literals;
using namespace std::string_literals;

#include "types.h"

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