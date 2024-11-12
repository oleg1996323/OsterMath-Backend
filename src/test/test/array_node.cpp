#include <type_traits>
#include <iostream>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>
#include "test/test/array_node.h"
#include "array_node.h"
#include "val_node.h"
#include "aux_functions.h"

using namespace functions::auxiliary;

TEST(ArrayNode_test,SizeConstructor){
    std::cout<<"Run test size constructor"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
    EXPECT_TRUE((std::convertible_to<decltype(arr->size()),size_t>));
    EXPECT_EQ(arr->size(),0);
    EXPECT_EQ(arr->childs().capacity(),10);
}
TEST(ArrayNode_test,Insert_Back){
    std::cout<<"Run test insert back"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr->insert_back(std::make_shared<ValueNode>(val));
    EXPECT_EQ(arr->childs().size(),10);
    arr->insert_back(std::make_shared<ValueNode>(values.back()+1));
    EXPECT_EQ(arr->childs().size(),11);
}
TEST(ArrayNode_test,Insert){
    std::cout<<"Run test insert at position"<<std::endl;
}
TEST(ArrayNode_test,Replace){
    std::cout<<"Run test replace at position"<<std::endl;
}
TEST(ArrayNode_test,Begins){
    std::cout<<"Run test begin"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(0);
    EXPECT_EQ(arr->childs().begin(), arr->begin());
    arr->insert_back(std::make_shared<ValueNode>(1));
    EXPECT_EQ(arr->childs().begin(), arr->begin());
}
TEST(ArrayNode_test,Ends){
    
}
TEST(ArrayNode_test,CopyConstructor){
    std::cout<<"Run test copy constructor"<<std::endl;
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1->insert_back(std::make_shared<ValueNode>(val));
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(*arr_1.get());
    EXPECT_EQ(arr_1->size(),arr_2->size());
    for(auto iter = arr_2->begin();iter!=arr_2->end();++iter){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1->child(iter-arr_2->begin())));
    }
}
TEST(ArrayNode_test,MoveConstructor){
    std::cout<<"Run test move constructor"<<std::endl;
    EXPECT_FALSE(std::is_move_constructible_v<ArrayNode>);
}
TEST(ArrayNode_test,Move_SharedPtrVal_Constructor){
    std::cout<<"Run test move sharedptr constructor"<<std::endl;    
}
TEST(ArrayNode_test,Copy_SharedPtrVal_Constructor){
    std::cout<<"Run test copy sharedptr constructor"<<std::endl;
}
TEST(ArrayNode_test,Operator_Eq){
    
}
TEST(ArrayNode_test,Type){
    
}
TEST(ArrayNode_test,Execute){
    
}
TEST(ArrayNode_test,Execute_id){
    
}
TEST(ArrayNode_test,Cached_Result){
    
}
TEST(ArrayNode_test,Cached_Result_id){
    
}
TEST(ArrayNode_test,is_Numeric){
    
}
TEST(ArrayNode_test,is_String){
    
}
TEST(ArrayNode_test,is_Array){
    
}
TEST(ArrayNode_test,Print_Text){
    
}
TEST(ArrayNode_test,Print_Result){
    
}
