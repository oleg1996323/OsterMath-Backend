#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <string>
#include <boost/static_string/static_string.hpp>
#include <map>
#include <filesystem>
#include <fstream>
#include <boost/math/differentiation/autodiff.hpp>
//#include <boost/json/parse.hpp>
#include "def.h"

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

    const std::filesystem::path& GetPath(TypeFile type){
        boost::json::object paths;
        std::ifstream config_stream(ROOT_DIR+"/Data/config.json");
        boost::json::parse(config_stream,paths);
    }

    private:
    std::map<std::string,std::string> paths_dir_data_;
};