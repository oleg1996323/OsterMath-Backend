
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"
#include "test/testing.h"

#ifdef DEBUG

int main(){   
    //Testing();

    std::string str = "String number 1.";
    std::string_view str_v = str;

    std::cout<<"String: "<<str_v<<". Lenght: "<<str_v.size()<<std::endl;

    str = "Another string number 1.";
    std::cout<<"String: "<<str_v<<". Lenght: "<<str_v.size()<<std::endl;

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

