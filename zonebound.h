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
#include "constants.h"

namespace Bound{

using namespace std::string_view_literals;

const static std::filesystem::path bound_file_dir = std::filesystem::path("./Data/boundaries"sv);

using boost::multiprecision::cpp_dec_float_50;

enum class TempName{
    crt_t,ab,ef,op,cd,gh,ij,jk,mn,qu,rx,uv,wx,B23,sat_t
};

struct Parameters{
    std::vector<int8_t> Ii;
    std::vector<double> ni;
};

Temperature TempFunc_1(Pressure pres, const Parameters& param); //pres in MPa

Temperature TempFunc_2(Pressure pres, const Parameters& param); //pres in MPa

Temperature TempFunc_3(Pressure pres, const Parameters& param);//pres in MPa

const static std::map<TempName,std::function<Temperature(Pressure,const Parameters&)>> equations=
{
    {TempName::ab,TempFunc_2},
    {TempName::op,TempFunc_2},

    {TempName::ef,TempFunc_3},  

    {TempName::cd,TempFunc_1},
    {TempName::gh,TempFunc_1},
    {TempName::ij,TempFunc_1},
    {TempName::jk,TempFunc_1},
    {TempName::mn,TempFunc_1},
    {TempName::op,TempFunc_1},
    {TempName::qu,TempFunc_1},
    {TempName::rx,TempFunc_1}
};

const static std::map<TempName,std::string> paths = {
    {TempName::ab,"./Data/boundaries/ab.txt"},
    {TempName::op,"./Data/boundaries/op.txt"},
    {TempName::ef,"./Data/boundaries/ef.txt"},  
    {TempName::cd,"./Data/boundaries/cd.txt"},
    {TempName::gh,"./Data/boundaries/gh.txt"},
    {TempName::ij,"./Data/boundaries/ij.txt"},
    {TempName::jk,"./Data/boundaries/jk.txt"},
    {TempName::mn,"./Data/boundaries/mn.txt"},
    {TempName::op,"./Data/boundaries/op.txt"},
    {TempName::qu,"./Data/boundaries/qu.txt"},
    {TempName::rx,"./Data/boundaries/rx.txt"}
};

class TemperatureBound{
    public:

    TemperatureBound(TempName name);

    Temperature GetTempByPressure(Pressure pres) const;

    private:

    void Init();

    Parameters param_;
    TempName name_;
};

inline const std::map<TempName, TemperatureBound> temp_boundaries{
    {TempName::ab,TemperatureBound(TempName::ab)},
    {TempName::op,TemperatureBound(TempName::op)},

    {TempName::ef,TemperatureBound(TempName::ef)},  

    {TempName::cd,TemperatureBound(TempName::cd)},
    {TempName::gh,TemperatureBound(TempName::gh)},
    {TempName::ij,TemperatureBound(TempName::ij)},
    {TempName::jk,TemperatureBound(TempName::jk)},
    {TempName::mn,TemperatureBound(TempName::mn)},
    {TempName::op,TemperatureBound(TempName::op)},
    {TempName::qu,TemperatureBound(TempName::qu)},
    {TempName::rx,TemperatureBound(TempName::rx)}
};

}