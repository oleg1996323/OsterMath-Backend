
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"
#include "test/testing.h"
#include "exception/exception.h"

#ifdef DEBUG

exceptions::EXCEPTION_TYPE exception_handler(std::function<void()> function){
    try{
        function();
        return exceptions::NOEXCEPT;
    }
    catch(const exceptions::Exception& err){
        std::cout<<"Warning exception: "<<err.get_error()<<"Prompt: "<<err.get_prompt()<<std::endl;
        return err.type();
    }
}

int main(){   
    //Testing();
    DataPool pool("main");
    pool.add_data("any");
    BaseData* data = pool.get("any");
    std::string first = R"(VAR(#A)=[[2],2,2]
VAR(#B)=[[2],2,2]
VAR(#C)=sumproduct(#A,#B)
)";
//,[[2,2,2],[2,2,2]]

    {
        std::stringstream stream(first);
        data->setstream(stream);
        std::stringstream result;
        exception_handler([&](){
            data->read_new();
            data->get("C")->set_stream(result);
            data->get("C")->refresh();
            data->get("C")->print_result();
        });

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

