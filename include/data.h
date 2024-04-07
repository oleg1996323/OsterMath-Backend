#pragma once

#include "def.h"
#include "types.h"

class Data{
    public:
    VariableBase const* GetVar(const std::string& name) const{
        if(!Exists(name))
            return nullptr;
        else
            
    };

    bool Exists(const std::string& name) const{
        return var_names_.find(name)!=var_names_.end();
    }

    bool AddVariable(std::string&& name){
        if(!Exists(name)){
            
            return true;
        }
    }

    bool AddVariable(std::string&& name, double value){

    }

    bool AddVariable(std::string&& name, ValueLong value){

    }

    template<typename... ARGS>
    bool AddVariable(std::string&& name, Function<double(ARGS...)> value()){

    }

    template<typename... ARGS>
    bool AddVariable(std::string&& name, FunctionLong<ValueLong(ARGS...)> value()){

    }

    private:
    std::unordered_map<std::string,const VariableBase&> var_names_; 
    std::unordered_set<VariableBase,VariableBase::HashVar> vars_;
};