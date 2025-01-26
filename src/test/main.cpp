
#include <iostream>
#include <string>
#include <string_view>
#include "data.h"
#include "arithmetic_types.h"
#include "test/testing.h"
#include "include/test/test_log.h"

#include <gtest/gtest.h>
#include "string_node.h"
#include "core/settings.h"
#include "core/system.h"
#ifdef DEBUG

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



int main(int argc, char **argv){
    //std::cout<<sizeof(char)<<std::endl;
    std::cout<<"Multimap size : "<<sizeof(std::map<EmptyNode*,std::vector<int>>)<<std::endl;
    std::cout<<"Current set size : "<<sizeof(std::set<INFO_NODE,INFO_NODE_Comparator>)<<std::endl;
    std::cout<<"Maximum cores accessible: "<<kernel::System::get_accessible_cores()<<std::endl;
    std::cout<<"SizeDepthMeasure: "<<sizeof(SizeDepthMeasure)<<std::endl;
    std::cout<<"Value_t: "<<sizeof(Value_t)<<std::endl;
    std::cout<<"std::string: "<<sizeof(std::string)<<std::endl;
    std::cout<<"Result: "<<sizeof(Result)<<std::endl;
    std::cout<<"std::vector<Result>: "<<sizeof(std::vector<Result>)<<std::endl;
    std::cout<<"Bound_types: "<<sizeof(Bound_types)<<std::endl;
    std::cout<<"Node: "<<sizeof(EmptyNode)<<std::endl;
    std::cout<<"BinaryNode: "<<sizeof(BinaryNode)<<std::endl;
    std::cout<<"UnaryNode: "<<sizeof(UnaryNode)<<std::endl;
    std::cout<<"RangeOperationNode: "<<sizeof(RangeOperationNode)<<std::endl;
    std::cout<<"FunctionNode: "<<sizeof(FunctionNode)<<std::endl;
    std::cout<<"ArrayNode: "<<sizeof(ArrayNode)<<std::endl;
    std::cout<<"ValueNode: "<<sizeof(ValueNode)<<std::endl;
    std::cout<<"StringNode: "<<sizeof(StringNode)<<std::endl;
    std::cout<<"VariableNode: "<<sizeof(VariableNode)<<std::endl;
    std::cout<<"std::unordered_set<Node*>: "<<sizeof(std::unordered_set<EmptyNode*>)<<std::endl;
    std::cout<<"std::set<Node*>: "<<sizeof(std::set<EmptyNode*>)<<std::endl;
    std::cout<<"std::list<Node*>: "<<sizeof(std::list<EmptyNode*>)<<std::endl;
    std::cout<<"std::vector<std::shared_ptr<Node>>: "<<sizeof(std::vector<std::shared_ptr<EmptyNode>>)<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

// This sample shows how to use Google Test listener API to implement
// an alternative console output and how to use the UnitTest reflection API
// to enumerate test cases and tests and to inspect their results.


#else 

int main(int argc, char **argv){
    // DataPool pool("main");
    // pool.add_data("any");
    // BaseData* data = pool.get("any");
    // data->setstream(std::cin);
    // //data->get("__I__")->get<ArithmeticTree>().print();
    // try{
    //     data->get("I")->set_stream(std::cout);
    //     data->get("I")->print_result();
    //     std::cout<<std::endl;
    // }
    // catch(const std::invalid_argument& err){
    //     std::cout<<err.what()<<std::endl;
    // }
    // return 0;
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

#endif

