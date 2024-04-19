#pragma once
#include <stdint.h>
#include <functional>
#include <map>
#include <limits>
#include <vector>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <string_view>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <memory>
#include "def.h"


namespace Bound{

using namespace std::string_view_literals;

const static std::filesystem::path bound_file_dir = std::filesystem::path("./Data/boundaries"sv);

//using boost::multiprecision::cpp_dec_float_50;

const static std::map<TempBoundName,std::string> paths = {
    {TempBoundName::ab,"./Data/boundaries/ab.txt"},
    {TempBoundName::op,"./Data/boundaries/op.txt"},
    {TempBoundName::ef,"./Data/boundaries/ef.txt"},  
    {TempBoundName::cd,"./Data/boundaries/cd.txt"},
    {TempBoundName::gh,"./Data/boundaries/gh.txt"},
    {TempBoundName::ij,"./Data/boundaries/ij.txt"},
    {TempBoundName::jk,"./Data/boundaries/jk.txt"},
    {TempBoundName::mn,"./Data/boundaries/mn.txt"},
    {TempBoundName::op,"./Data/boundaries/op.txt"},
    {TempBoundName::qu,"./Data/boundaries/qu.txt"},
    {TempBoundName::rx,"./Data/boundaries/rx.txt"}
};

class TemperatureBound{
    public:

    TemperatureBound(TempBoundName name);

    Temperature GetTempByPressure(Pressure pres) const;

    struct Parameters{
        std::vector<int8_t> Ii;
        std::vector<double> ni;
    };

    private:

    void Init();

    Parameters param_;
    TempBoundName name_;
};

inline const std::map<TempBoundName, TemperatureBound> temp_boundaries{
    {TempBoundName::ab,TemperatureBound(TempBoundName::ab)},
    {TempBoundName::op,TemperatureBound(TempBoundName::op)},

    {TempBoundName::ef,TemperatureBound(TempBoundName::ef)},  

    {TempBoundName::cd,TemperatureBound(TempBoundName::cd)},
    {TempBoundName::gh,TemperatureBound(TempBoundName::gh)},
    {TempBoundName::ij,TemperatureBound(TempBoundName::ij)},
    {TempBoundName::jk,TemperatureBound(TempBoundName::jk)},
    {TempBoundName::mn,TemperatureBound(TempBoundName::mn)},
    {TempBoundName::op,TemperatureBound(TempBoundName::op)},
    {TempBoundName::qu,TemperatureBound(TempBoundName::qu)},
    {TempBoundName::rx,TemperatureBound(TempBoundName::rx)}
};

Temperature TempFunc_1(Pressure pres, const TemperatureBound::Parameters& param){ //pres in MPa
    Temperature result = 0.;
    for(int i=0;i<param.Ii.size();++i){
        result+=pow(pres,param.Ii[i])*param.ni[i];
    }

    return result;
}

Temperature TempFunc_2(Pressure pres, const TemperatureBound::Parameters& param){ //pres in MPa
    Temperature result = 0.;
    for(int i=0;i<param.Ii.size();++i){
        result+=pow(std::log(pres),param.Ii[i])*param.ni[i];
    }

    return result;
}

Temperature TempFunc_3(Pressure pres, const TemperatureBound::Parameters& param){ //pres in MPa
    return sat_deriv*(pres-crit_pres)+crit_temp;
}

const static std::map<TempBoundName,std::function<Temperature(Pressure,const TemperatureBound::Parameters&)>> equations=
{
    {TempBoundName::ab,TempFunc_2},
    {TempBoundName::op,TempFunc_2},

    {TempBoundName::ef,TempFunc_3},  

    {TempBoundName::cd,TempFunc_1},
    {TempBoundName::gh,TempFunc_1},
    {TempBoundName::ij,TempFunc_1},
    {TempBoundName::jk,TempFunc_1},
    {TempBoundName::mn,TempFunc_1},
    {TempBoundName::op,TempFunc_1},
    {TempBoundName::qu,TempFunc_1},
    {TempBoundName::rx,TempFunc_1}
};

}