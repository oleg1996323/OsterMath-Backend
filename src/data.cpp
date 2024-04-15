#include "data.h"

    const VariableBase* BaseData::GetVar(const std::string& name) const{
        if(!Exists(name))
            return nullptr;
        else
           return vars_.at(name).has_value()?&vars_.at(name).value():nullptr; 
    };

    bool BaseData::Exists(const std::string& name) const{
        return vars_.contains(name);
    }

    bool BaseData::Defined(const std::string& name) const{
        if(Exists(name)){
            return vars_.at(name).has_value();
        }
        else return false;
    }

    bool BaseData::AddVariable(const std::string& name){
        if(!Exists(name)){
            vars_.emplace(name,std::nullopt).first;
            return true;
        }
        else return false;
    }

    template<typename T>
    bool BaseData::AddVariable(std::string&& name, T&& value){
        if(!Exists(name)){
            auto ref = vars_.emplace(name,std::nullopt).first;
            ref->second.emplace(std::move(String(ref->first,std::forward<T>(value))));
            return true;
        }
        else return false;
    }

    template<typename T>
    void BaseData::Define(std::string&& name, T&& value){
        if(Exists(name)){
            if(!Defined(name)){
                auto ref = vars_.find(name);
                ref->second.emplace(std::forward<T>(value));
                return;
            }
            else
                throw std::logic_error("Variable "+name+" already defined.");
        }
        else throw std::logic_error("Variable "+name+" don't exists.");
    }

    void BaseData::Erase(const std::string& var_name){
        vars_.erase(var_name);
    }