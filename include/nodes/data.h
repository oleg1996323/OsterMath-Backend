#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <deque>
#include "def.h"
#include "expr_parser.h"
#include "types.h"


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

    void set_name(std::string_view name);

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

    void rename_var(const std::string& current_name,const std::string& new_name);

    void serialize(serialization::SerialData& serial_data);

    void deserialize(serialization::SerialData& serial_data);

    void serialize_header(serialization::SerialData& serial_data) const;

    void deserialize_header(serialization::SerialData& serial_data);

    const std::unordered_map<std::string_view,std::shared_ptr<VariableBase>> variables() const;

    void remove_variables();

    std::shared_ptr<VariableBase> get_buffer() const;

    uint16_t id() const;

    private:
    std::unordered_set<std::string> var_names_;
    std::unordered_map<std::string_view,std::shared_ptr<VariableBase>> vars_;
    std::string_view name_;
    std::unique_ptr<Parser> parser_;
    mutable std::shared_ptr<VariableBase> buffer_;
    DataPool* pool_;
    std::string generate_hash_name();
    static uint16_t counter;
    uint16_t data_count;
};

class DataPool{
    public:
    DataPool(const std::string& name);

    BaseData* add_data(const std::string& name);

    std::string_view name();

    void rename_database(const std::string&, const std::string&);

    void set_name(const std::string& name);

    const BaseData* get(std::string_view name_data) const noexcept;

    BaseData* get(std::string_view name_data) noexcept;

    bool exists(std::string_view name) const;

    void erase(std::string_view name);

    size_t size() const;

    void serialize(serialization::SerialData& serial_data);

    void deserialize(serialization::SerialData& serial_data);

    const std::deque<std::shared_ptr<BaseData>>& data_bases() const;

    private:
    std::string name_;
    std::unordered_set<std::string> data_names_;
    std::deque<std::shared_ptr<BaseData>> data_bases_;
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