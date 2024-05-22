
#include <iostream>
#include <string>
#include <string_view>
#include "def.h"
#include "data.h"
#include "test/testing.h"

#ifdef DEBUG

int main(){   
    Testing();
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
        std::cout<<data->get("I")->get()<<std::endl;
    }
    catch(const std::invalid_argument& err){
        std::cout<<err.what()<<std::endl;
    }
    return 0;
}

#endif

