
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"

int main()
{   
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    data->setstream(std::cin);
    while(std::cin)
        data->parse_entry();
    std::cout<<"Hello"<<std::endl;
    return 0;
}
