
#include <iostream>
#include <string>
#include <string_view>
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
    std::cout<<data->get("__I__")->get()<<std::endl;
    return 0;
}

#endif

