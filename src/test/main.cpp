
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

void define_section_subelements(STRUCT_SECTION& section_sizes, const ArrayNode* array){
    if(array->has_childs()){
        section_sizes.size_=array->childs().size();
        for(std::shared_ptr<Node> child:*array){
            if(child->is_array()){
                section_sizes.childs_.push_back(STRUCT_SECTION(&section_sizes));
                define_section_subelements(section_sizes.childs_.back(), child->execute().get_array_node());
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
#include "string_node.h"

int main(int argc, char **argv){
    // std::cout<<sizeof(char)<<std::endl;
    std::cout<<"SizeDepthMeasure: "<<sizeof(SizeDepthMeasure)<<std::endl;
    // std::cout<<"Value_t: "<<sizeof(Value_t)<<std::endl;
    // std::cout<<"std::string: "<<sizeof(std::string)<<std::endl;
    // std::cout<<"Result: "<<sizeof(Result)<<std::endl;
    // std::cout<<"std::vector<Result>: "<<sizeof(std::vector<Result>)<<std::endl;
    // std::cout<<"Bound_types: "<<sizeof(Bound_types)<<std::endl;
    // std::cout<<"Node: "<<sizeof(Node)<<std::endl;
    // std::cout<<"BinaryNode: "<<sizeof(BinaryNode)<<std::endl;
    // std::cout<<"UnaryNode: "<<sizeof(UnaryNode)<<std::endl;
    // std::cout<<"RangeOperationNode: "<<sizeof(RangeOperationNode)<<std::endl;
    // std::cout<<"FunctionNode: "<<sizeof(FunctionNode)<<std::endl;
    // std::cout<<"ArrayNode: "<<sizeof(ArrayNode)<<std::endl;
    // std::cout<<"ValueNode: "<<sizeof(ValueNode)<<std::endl;
    // std::cout<<"StringNode: "<<sizeof(StringNode)<<std::endl;
    // std::cout<<"VariableNode: "<<sizeof(VariableNode)<<std::endl;
    // std::cout<<"std::unordered_set<Node*>: "<<sizeof(std::unordered_set<Node*>)<<std::endl;
    // std::cout<<"std::set<Node*>: "<<sizeof(std::set<Node*>)<<std::endl;
    // std::cout<<"std::list<Node*>: "<<sizeof(std::list<Node*>)<<std::endl;
    // std::cout<<"std::vector<std::shared_ptr<Node>>: "<<sizeof(std::vector<std::shared_ptr<Node>>)<<std::endl;
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

