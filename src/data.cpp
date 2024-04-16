#include "data.h"

    using namespace std::string_literals;

    const VariableBase* BaseData::GetVar(std::string_view name) const{
        if(!Exists(name))
            return nullptr;
        else
           return vars_.at(name)?vars_.at(name).get():nullptr; 
    };

    bool BaseData::Exists(std::string_view name) const{
        return vars_.contains(name);
    }

    bool BaseData::Defined(std::string_view name) const{
        if(Exists(name)){
            if(vars_.at(name))
                return true;
            else return false;
        }
        else return false;
    }

    std::shared_ptr<VariableBase>& BaseData::AddVariable(std::string&& name){
        if(!Exists(name)){
            return vars_.emplace(
                *var_names_.emplace(name).first,
                std::nullopt).first->second;
        }
        else return vars_.find(name)->second;
    }

    template<typename T>
    std::shared_ptr<VariableBase>& BaseData::AddVariable(std::string&& name, T&& value){
        if(!Exists(name)){
            auto ref = vars_.emplace(
                *var_names_.emplace(name).first,
                std::nullopt).first;
            ref->second = std::make_shared<VariableBase>(
                std::move(ref->first,
                std::forward<T>(value)));
            return ref->second;
        }
        else return vars_.find(name)->second;
    }

    template<typename T>
    void BaseData::Define(std::string_view name, T&& value){
        if(Exists(name)){
            if(!Defined(name)){
                auto ref = vars_.find(name);
                ref->second = std::shared_ptr<VariableBase>(ref->first,std::forward<T>(value));
                return;
            }
            else
                throw std::logic_error("Variable "s+std::string(name.)+" already defined."s);
        }
        else throw std::logic_error("Variable "s+std::string(name)+" don't exists."s);
    }

    void BaseData::Erase(std::string_view var_name){
        vars_.erase(var_name);
    }