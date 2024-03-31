#include <map>
#include <set>
#include <unordered_set>
#include <memory>
#include "zonebound.h"

enum class ZoneNum{
    _1,_2,_3,_4,_5
};

enum class SubZoneName{
    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
};

struct ZoneBounds{
    Bound::TempBoundName left_; //left side temperature bound
    Bound::TempBoundName right_; //right side temperature bound

    bool operator==(ZoneBounds other){
        return left_>=other.left_ && right_<other.right_;
    }

};

template<>
struct std::hash<ZoneBounds> {
    size_t operator()(const ZoneBounds& bounds) const {
        return std::hash<int>()(static_cast<int>(bounds.left_)) ^ std::hash<int>()(static_cast<int>(bounds.right_));
    }
};

// static const std::map<ZoneNum,std::map<SubZoneName, ZoneBounds>> zones_{
//     {ZoneNum::_1,{}},
//     {ZoneNum::_2,{}},
//     {ZoneNum::_3,{
//     {SubZoneName::a,{Bound::TempName::crt_t,Bound::TempName::ab}},
//     {SubZoneName::b,{Bound::TempName::ab,Bound::TempName::B23}},
//     {SubZoneName::c,{Bound::TempName::crt_t,Bound::TempName::cd}},
//     {SubZoneName::d,{Bound::TempName::cd,Bound::TempName::ab}},
//     {SubZoneName::e,{Bound::TempName::ab,Bound::TempName::ef}},
//     {SubZoneName::f,{Bound::TempName::ef,Bound::TempName::B23}},
//     {SubZoneName::g,{Bound::TempName::cd,Bound::TempName::gh}},
//     {SubZoneName::h,{Bound::TempName::gh,Bound::TempName::ef}},
//     {SubZoneName::i,{Bound::TempName::ef,Bound::TempName::ij}},
//     {SubZoneName::j,{Bound::TempName::ij,Bound::TempName::jk}},
//     {SubZoneName::k,{Bound::TempName::jk,Bound::TempName::B23}},
//     {SubZoneName::l,{Bound::TempName::cd,Bound::TempName::gh}},
//     {SubZoneName::m,{Bound::TempName::gh,Bound::TempName::mn}},
//     {SubZoneName::n,{Bound::TempName::mn,Bound::TempName::ef}},
//     {SubZoneName::o,{Bound::TempName::ef,Bound::TempName::op}},
//     {SubZoneName::p,{Bound::TempName::op,Bound::TempName::ij}},
//     {SubZoneName::q,{Bound::TempName::cd,Bound::TempName::qu}},
//     {SubZoneName::r,{Bound::TempName::rx,Bound::TempName::jk}},
//     {SubZoneName::s,{Bound::TempName::cd,Bound::TempName::sat_t}},
//     {SubZoneName::t,{Bound::TempName::jk,Bound::TempName::B23}},
//     {SubZoneName::u,{Bound::TempName::qu,Bound::TempName::sat_t}},
//     {SubZoneName::v,{Bound::TempName::uv,Bound::TempName::ef}},
//     {SubZoneName::w,{Bound::TempName::ef,Bound::TempName::wx}},
//     {SubZoneName::x,{Bound::TempName::sat_t,Bound::TempName::rx}},
//     {SubZoneName::y,{Bound::TempName::uv,Bound::TempName::ef}},
//     {SubZoneName::z,{Bound::TempName::ef,Bound::TempName::wx}}}},
//     {ZoneNum::_4,{}},
//     {ZoneNum::_5,{}}
// };

class Zone{
    public:

    public:

    //string passed by value because the zone-name length is contained essentially by 2-3 chars.
    Zone(std::string zone):zone_(zone){
        //init from json
    }

    void AddSubZone(std::string zone){
        sub_zones_.insert(Zone(zone));
    }

    Pressure GetMinPressure() const{
        return p_min_;
    }

    Pressure GetMaxPressure() const{
        return p_max_;
    }

    Temperature GetMinTemperatureByPressure(Pressure pres) const{
        return Bound::temp_boundaries.at(zone_.left_).GetTempByPressure(pres);
    }

    Temperature GetMaxTemperatureByPressure(Pressure pres) const{
        return Bound::temp_boundaries.at(zone_.right_).GetTempByPressure(pres);
    }

    bool operator==(const Zone& other){
        return zone_==other.zone_ && p_min_>=other.p_min_ && p_max_<other.p_max_; //this necessairy for getting access to
        //zone in u_set and for defining the zone by temperature and pressure parameters
    }

    struct hash{
        size_t operator()(const Zone& zone){
            return std::hash<ZoneBounds>()(zone.zone_) ^ std::hash<Pressure>()(zone.p_min_) ^ std::hash<Pressure>()(zone.p_max_);
        }
    };

    private:
    //this should be defined as global zone or by any other zone from which that zone os defined
    std::shared_ptr<Zone> parent_;

    //these bounds must be defined in every zone and subzone respectively
    std::string zone_; //name of zone/subzone. The name must corresponds to the *.json file name.
    //For example, for zone_="zone3" the filename must be "zone3.json" 
    Pressure p_min_;
    Pressure p_max_;
    
    //maybe empty if this zone is at the end-branch of zone-subzone relation
    std::unordered_set<Zone, Zone::hash> sub_zones_;
};
