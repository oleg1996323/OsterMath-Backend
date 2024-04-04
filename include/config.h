#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <string_view>
#include <boost/static_string/static_string.hpp>

#ifdef unix
    static const std::string ROOT_DIR = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("/"));
#else
    static const std::string ROOT_DIR = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("\\"));
#endif

using namespace boost::json;

class JsonConfigInit{
    public:
    JsonConfigInit(){
        boost::json::object paths;
        paths.emplace();
    }
};