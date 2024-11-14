
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"
#include "arithmetic_types.h"
#include "test/testing.h"

#ifdef DEBUG

struct STRUCT_SECTION{
    STRUCT_SECTION(STRUCT_SECTION* parent = nullptr):parent_(parent){}

    void update_max_size_depth(){
        if(parent_ && parent_->max_size_depth<=max_size_depth)
            parent_->max_size_depth=max_size_depth+1;
    }

    std::vector<STRUCT_SECTION> childs_;
    STRUCT_SECTION* parent_;
    size_t size_=0;
    size_t max_size_depth = 0;
};

void define_section_subelements(STRUCT_SECTION& section_sizes, ArrayNode* array){
    if(array->has_childs()){
        section_sizes.size_=array->childs().size();
        for(std::shared_ptr<Node> child:*array){
            if(child->is_array()){
                section_sizes.childs_.push_back(STRUCT_SECTION(&section_sizes));
                define_section_subelements(section_sizes.childs_.back(), reinterpret_cast<ArrayNode*>(child->execute().get<Node*>()));
                section_sizes.childs_.back().update_max_size_depth();
            }
        }
    }
}

// int main(){
//     DataPool pool("main");
//     pool.add_data("any");
//     BaseData* data = pool.get("any");
//     std::string string = R"(VAR(#A)=#A
// )";
// //,[[2,2,2],[2,2,2]]

//     {
//         std::stringstream stream(string);
//         data->setstream(stream);
//         data->read_new();
//     }
//     STRUCT_SECTION section_sizes;
//     if(data->get("A")->is_array())
//         define_section_subelements(section_sizes,reinterpret_cast<ArrayNode*>(data->get("A")->node()->execute().get<Node*>()));
//     else data->get("A")->node()->execute().get<Value_t>();
//     std::cout<<"Max depth: "<<section_sizes.max_size_depth<<std::endl;
//     return 0;
// }

exceptions::EXCEPTION_TYPE exception_handler(std::function<void()> function){
    try{
        function();
        return exceptions::EXCEPTION_TYPE::NOEXCEPT;
    }
    catch(const exceptions::Exception& err){
        std::cout<<"Warning exception: "<<err.get_error()<<"Prompt: "<<err.get_prompt()<<std::endl;
        return err.type();
    }
}

#include <gtest/gtest.h>

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    //LOG_DURATION("Tests");   
    //Testing();
//     DataPool pool("main");
//     pool.add_data("any");
//     BaseData* data = pool.get("any");
//     std::string first = R"(VAR(#A)=1+#A
// )";
// //,[[2,2,2],[2,2,2]]

//     {
//         std::stringstream stream(first);
//         data->setstream(stream);
//         std::stringstream result;
//         exception_handler([&](){
//             data->read_new();
//             // data->get("C")->set_stream(result);
//             data->get("A")->refresh();
//             // data->get("C")->print_result();
//         });

//         // std::cout<<result.str()<<std::endl;
//     }
    
    return RUN_ALL_TESTS();
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

