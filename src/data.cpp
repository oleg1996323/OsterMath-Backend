#include "data.h"

    const VariableBase* BaseData::GetVar(const std::string& name) const{
        if(!Exists(name))
            return nullptr;
        else
           return vars_.at(name)?vars_.at(name).get():nullptr; 
    };

    bool BaseData::Exists(const std::string& name) const{
        return vars_.contains(name);
    }

    bool BaseData::Defined(const std::string& name) const{
        if(Exists(name)){
            if(vars_.at(name))
                return true;
            else return false;
        }
        else return false;
    }

    std::shared_ptr<VariableBase>& BaseData::AddVariable(const std::string& name){
        if(!Exists(name)){
            return vars_.emplace(name,std::nullopt).first->second;
        }
        else return vars_.find(name)->second;
    }

    template<typename T>
    std::shared_ptr<VariableBase>& BaseData::AddVariable(std::string&& name, T&& value){
        if(!Exists(name)){
            auto ref = vars_.emplace(name,std::nullopt).first;
            ref->second = std::make_shared<VariableBase>(std::move(ref->first,std::forward<T>(value)));
            return ref->second;
        }
        else return vars_.find(name)->second;
    }

    template<typename T>
    void BaseData::Define(std::string&& name, T&& value){
        if(Exists(name)){
            if(!Defined(name)){
                auto ref = vars_.find(name);
                ref->second = std::shared_ptr<VariableBase>(ref->first,std::forward<T>(value));
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