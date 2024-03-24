#include <vector>
#include <map>
#include <fstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/serialization/serialization.hpp>

using Temperature = double; //K
using Pressure = double; //MPa
using boost::multiprecision::cpp_dec_float_50;


// class Properties{
//     public:
//     class SpecificVolume{ //interface
//         public:
//         double GetValue(Pressure pressure, Temperature temperature){

//             return 0.;
//         }

//         private:
//         ZoneName DefineZone(Pressure pressure, Temperature temperature){
//             return ZoneName::a;
//         }
//         //before zone definition bounds must be defined

//         struct Parameters{
//             int8_t Ii;
//             int8_t Ji;
//             cpp_dec_float_50 ni;
//         };

//         using Collection = std::vector<Parameters>; //index = i

//         Collection data_;
//     };

//     //other properties classes
// };

// class PropertiesManager{
//     public:

    
//     private:
//     using Zones = std::map<ZoneName,SubZone>;

//     Zones zones;
// };