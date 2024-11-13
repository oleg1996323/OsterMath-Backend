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
    std::cout<<"Run test begin"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(0);
    EXPECT_EQ(arr->begin(), arr->end());
    arr->insert_back(std::make_shared<ValueNode>(1));
    EXPECT_EQ(arr->begin()+1, arr->end());
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
    ArrayNode arr_1(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1.insert_back(std::make_shared<ValueNode>(val));
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(std::move(arr_1));
    EXPECT_EQ(arr_1.size(),arr_2->size());
    for(auto iter = arr_2->begin();iter!=arr_2->end();++iter){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1.child(iter-arr_2->begin())));
    }
}
TEST(ArrayNode_test,Move_SharedPtrVal_Constructor){
    std::cout<<"Run test move sharedptr constructor"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(1));
    std::shared_ptr<ValueNode> val = std::make_shared<ValueNode>(100);
    arr = std::make_shared<ArrayNode>(std::move(val));
    EXPECT_EQ(arr->child(0)->execute().get_value(),100.);
    EXPECT_EQ(val.get(),nullptr);
}
TEST(ArrayNode_test,Copy_SharedPtrVal_Constructor){
    std::cout<<"Run test copy sharedptr constructor"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(1));
    std::shared_ptr<ValueNode> val = std::make_shared<ValueNode>(100);
    arr = std::make_shared<ArrayNode>(val);
    EXPECT_EQ(arr->child(0)->execute().get_value(),100.);
    EXPECT_EQ(val.get(),arr->child(0).get());
}
TEST(ArrayNode_test,Operator_Eq_copy){
    std::cout<<"Run test operator equal copy"<<std::endl;
    EXPECT_TRUE(std::is_copy_assignable_v<ArrayNode>);
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(1);
    arr_1->insert_back(std::make_shared<ValueNode>(1));
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(2);
    arr_2->insert_back(std::make_shared<ValueNode>(2));
    arr_2->insert_back(std::make_shared<ValueNode>(3));
    *arr_1.get() = *arr_2.get();
    EXPECT_EQ(arr_1->size(),2);
    EXPECT_EQ(arr_1->childs().capacity(),2);
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
}
TEST(ArrayNode_test,Operator_Eq_move){
    std::cout<<"Run test operator equal"<<std::endl;
    EXPECT_TRUE(std::is_move_assignable_v<ArrayNode>);
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(1);
    arr_1->insert_back(std::make_shared<ValueNode>(1));
    arr_1->insert_back(std::make_shared<ValueNode>(2));
    ArrayNode arr_2(std::make_shared<ValueNode>(2));
    size_t sz = arr_2.size();
    size_t cap = arr_2.childs().capacity();
    *arr_1.get() = std::move(arr_2);
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
    EXPECT_EQ(arr_1->size(),sz);
    EXPECT_EQ(arr_1->childs().capacity(),cap);
}
TEST(ArrayNode_test,Type_Numeric_Array){
    std::cout<<"Run test operator equal"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<ValueNode>(100000000));
    EXPECT_EQ(arr->type_val(),TYPE_VAL::NUMERIC_ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::VALUE);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::NUMERIC_ARRAY);
}
TEST(ArrayNode_test,Type_String_Array){
    //TODO: develop string node
}
TEST(ArrayNode_test,Type_Array){
    //TODO: develop string node
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
