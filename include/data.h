#pragma once

#include "def.h"
#include "types.h"

class BaseData{
    public:
    const VariableBase* GetVar(const std::string& name) const{
        if(!Exists(name))
            return nullptr;
        else
           return vars_.at(name).has_value()?&vars_.at(name).value():nullptr; 
    };

    bool Exists(const std::string& name) const{
        return vars_.contains(name);
    }

    bool AddVariable(const std::string& name){
        if(!Exists(name)){
            vars_.emplace(name).first;
            return true;
        }
        else return false;
    }

    bool AddVariable(std::string&& name, double value){
        if(!Exists(name)){
            auto ref = vars_.emplace(name).first;
            ref->second.emplace(std::move(VarValue(ref->first,value)));
            return true;
        }
        else return false;
    }

    bool AddVariable(std::string&& name, ValueLong&& value){
        if(!Exists(name)){
            auto ref = vars_.emplace(name).first;
            ref->second.emplace(std::move(VarValueLong(ref->first,std::move(value))));
            return true;
        }
        else return false;
    }

    template<typename... ARGS>
    bool AddVariable(std::string&& name, Function<double(ARGS...)> value(ARGS...)){
        if(!Exists(name)){
            auto ref = vars_.emplace(name).first;
            ref->second.emplace(std::move(VarFunction<ARGS...>(ref->first,value)));
            return true;
        }
        else return false;
    }

    template<typename... ARGS>
    bool AddVariable(std::string&& name, FunctionLong<ValueLong(ARGS...)> value(ARGS...)){
        if(!Exists(name)){
            auto ref = vars_.emplace(name).first;
            ref->second.emplace(std::move(VarFunctionLong<ARGS...>(ref->first,value)));
            return true;
        }
        else return false;
    }

    private:
    std::unordered_map<std::string,std::optional<VariableBase>> vars_; 
};

class TemperatureBound:public BaseData{
    public:

    TemperatureBound(TempBoundName name);

    Temperature GetTempByPressure(Pressure pres) const;

};

class ZoneData:public BaseData{
    public:

    public:

    //string passed by value because the zone-name length is contained essentially by 2-3 chars.
    ZoneData(std::string zone):zone_(zone){
        //init from json
    }

    Pressure GetMinPressure() const{
        return p_min_;
    }

    Pressure GetMaxPressure() const{
        return p_max_;
    }

    Temperature GetMinTemperatureByPressure(Pressure pres) const{
        return 0.;//Bound::temp_boundaries.at(zone_.left_).GetTempByPressure(pres);
    }

    Temperature GetMaxTemperatureByPressure(Pressure pres) const{
        return 0.;//Bound::temp_boundaries.at(zone_.right_).GetTempByPressure(pres);
    }

    // bool operator==(const Zone& other){
    //     return zone_==other.zone_ && p_min_>=other.p_min_ && p_max_<other.p_max_; //this necessairy for getting access to
    //     //zone in u_set and for defining the zone by temperature and pressure parameters
    // }

    struct hash{
        // size_t operator()(const Zone& zone){
        //     return std::hash<ZoneBounds>()(zone.zone_) ^ std::hash<Pressure>()(zone.p_min_) ^ std::hash<Pressure>()(zone.p_max_);
        // }
    };

    private:
    //this should be defined as global zone or by any other zone from which that zone os defined
    //std::shared_ptr<Zone> parent_;

    //these bounds must be defined in every zone and subzone respectively
    std::string zone_; //name of zone/subzone. The name must corresponds to the *.json file name.
    //For example, for zone_="zone3" the filename must be "zone3.json" 
    Pressure p_min_;
    Pressure p_max_;
    
    //maybe empty if this zone is at the end-branch of zone-subzone relation
    //std::unordered_set<Zone, Zone::hash> sub_zones_;
};