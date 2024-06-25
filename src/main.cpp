
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"
#include "test/testing.h"

#ifdef DEBUG

int main(){   
    //Testing();
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string first = R"(VAR(#I)=1+1)";
    std::string second = R"(VAR(#I)=2+2)";
    {
        std::stringstream stream(first);
        data->setstream(stream);
        data->read_new();
        std::stringstream result;
        data->get("I")->set_stream(result);
        data->get("I")->print_result();
        std::cout<<result.str()<<std::endl;
    }
    {
        std::stringstream stream(second);
        data->setstream(stream);
        data->read_new();
        std::stringstream result;
        data->get("I")->set_stream(result);
        data->get("I")->print_result();
        std::cout<<result.str()<<std::endl;
    }
    return 0;
}

#else 

int main(){
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    data->setstream(std::cin);
    //data->get("__I__")->get<ArithmeticTree>().print();
    try{
        data->get("I")->set_stream(std::cout);
        data->get("I")->print_result();
        std::cout<<std::endl;
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

#endif

