#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include <deque>
#include "def.h"
#include "expr_parser.h"
#include "types.h"
#include "node_manager.h"

class VariableBase;
class Parser;
class DataPool;

namespace serialization{
    class SerialData;
}

class BaseData{
    public:
    BaseData(std::string_view);
    ~BaseData();
    VariableBase* get(std::string_view name);
    const VariableBase* get(std::string_view name) const;
    std::string_view name() const;
    void set_name(std::string_view name);
    bool exists(std::string_view name) const;
    bool defined(std::string_view name) const;
    VariableBase* add_variable(std::string&& name);
    template<typename T>
    VariableBase* add_variable(std::string&& name, T&& value);
    VariableBase* add_anonymous_var();
    template<typename T>
    VariableBase* add_anonymous_var(T&& value);
    //template<typename T>
    //void define(std::string_view name, T&& value);
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
    const std::unordered_map<std::string_view,std::unique_ptr<VariableBase>>& variables() const;
    void remove_variables();
    VariableBase* get_buffer() const;
    uint16_t id() const;
    template<typename T>
    static std::unique_ptr<T> make_node(T&& node_val,NodeManager* rel_mng){
        node_val.set_relation_manager(rel_mng);
        return std::make_unique<T>(std::forward<T>(node_val));
    }
    template<typename T>
    static std::unique_ptr<T> make_node(T&& node_val,BaseData* bd){
        node_val.set_relation_manager(&bd->rel_mng_);
        return std::make_unique<T>(std::forward<T>(node_val));
    }
    template<typename T, typename... ARGS>
    std::unique_ptr<T> make_node(ARGS&&... node_val) const{
        std::unique_ptr<T> n_res = std::make_unique<T>(std::forward<ARGS>(node_val)...,&rel_mng_);
        n_res->set_relation_manager(relation_manager());
        return n_res;
    }
    static NodeManager* get_anonymous_relation_manager(){
        return &anonymous_nodes;
    }
    NodeManager* relation_manager() const{
        return &rel_mng_;
    }
    private:
    mutable NodeManager rel_mng_;
    std::unordered_map<std::string_view,std::unique_ptr<VariableBase>> vars_;
    std::unordered_set<std::string> var_names_;
    std::string_view name_;
    //std::unique_ptr<Parser> parser_;
    mutable std::unique_ptr<VariableBase> buffer_;
    DataPool* pool_;
    std::string generate_hash_name();
    uint16_t data_count;
    static NodeManager anonymous_nodes;
    static uint16_t counter;
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
VariableBase* BaseData::add_variable(std::string&& name, T&& value){
    if(!exists(name)){
        auto str_name = var_names_.emplace(name).first;
        auto tmp_u_var = std::make_unique<VariableBase>(*str_name,std::forward<T>(value),this);
        auto var = tmp_u_var.get();
        vars_[*str_name]=std::move(tmp_u_var);
        return var;
    }
    else return vars_.at(name).get();
}

// template<typename T>
// void BaseData::define(std::string_view name, T&& value){
//     if(exists(name)){
//         if(!defined(name)){
//             auto ref = vars_.find(name);
//             ref->second = std::shared_ptr<VariableBase>(ref->first,std::forward<T>(value));

//             return;
//         }
//         else
//             throw std::logic_error("Variable "s+std::string(name)+" already defined."s);
//     }
//     else throw std::logic_error("Variable "s+std::string(name)+" don't exists."s);
// }