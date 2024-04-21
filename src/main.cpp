
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
    std::cout<<data->get("__I__")<<std::endl;
    return 0;
}
