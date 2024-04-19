#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
#include "def.h"
#include "expr_parser.h"

class VariableBase;
class Parser;

class BaseData{
    public:
    BaseData(std::string_view);

    VariableBase* get(std::string_view name);

    const VariableBase* get(std::string_view name) const;

    bool exists(std::string_view name) const;

    bool defined(std::string_view name) const;

    std::shared_ptr<VariableBase>& add_variable(std::string&& name);

    template<typename T>
    std::shared_ptr<VariableBase>& add_variable(std::string&& name, T&& value);

    template<typename T>
    void define(std::string_view name, T&& value);

    void erase(std::string_view var_name);

    void setstream(std::istream& stream);

    void parse_entry();

    std::ostream& print(std::ostream& stream, std::string_view name);

    private:
    std::unordered_set<std::string> var_names_;
    std::unordered_map<std::string_view,std::shared_ptr<VariableBase>> vars_;
    std::unique_ptr<Parser> parser_; 
    std::string_view name_;
};

class DataPool{
    public:
    DataPool(const std::string& name);

    void add_data(const std::string& name);

    std::string_view name();

    BaseData* get(std::string_view name_data) const;

    bool exists(const std::string& name) const;

    void erase(const std::string& name);

    void replace(const std::string& name) noexcept;

    private:
    std::string name_;
    std::unordered_set<std::string> data_names_;
    std::unordered_map<std::string_view,BaseData> data_bases_;
};