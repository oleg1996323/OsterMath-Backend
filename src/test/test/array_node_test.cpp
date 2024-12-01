#include <type_traits>
#include <iostream>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>
#include "test/test/array_node.h"
#include "array_node.h"
#include "val_node.h"
#include "func_node.h"
#include "string_node.h"
#include "bin_node.h"
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
TEST(ArrayNode_test,ExecuteCorrect){
    std::cout<<"Run test execute with expected correct result"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<ValueNode>(100000000));
    EXPECT_TRUE(arr->execute().is_node());
    EXPECT_EQ(arr.get(),arr->execute().get_node());
}
TEST(ArrayNode_test,ExecuteError){
    std::cout<<"Run test execute with expected error result"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
    Result res = arr->execute();
    EXPECT_TRUE(res.is_error());
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
    std::cout<<res.get_exception()->get_error()<<std::endl;
}
TEST(ArrayNode_test,ExecuteCorrect_id){
    std::cout<<"Run test execute with expected correct result"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<ValueNode>(100000000));
    EXPECT_EQ(100000000,arr->execute().get_array_node()->child(2)->cached_result().get_value());
}
TEST(ArrayNode_test,ExecuteError_id){
    std::cout<<"Run test execute with expected error result"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
    Result res = arr->execute();
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
}
TEST(ArrayNode_test,Cached_Result_With_Correct){
    std::cout<<"Run test cached result when executed correct"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    EXPECT_TRUE(arr->execute().is_node());
    EXPECT_TRUE(arr->execute().is_array());
    EXPECT_TRUE(arr->cached_result().get_array_node()->child(2)->cached_result().is_value());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
    std::cout<<arr->cached_result()<<std::endl;
    //EXPECT_EQ(arr->cached_result().get_node(),arr.get());
}
TEST(ArrayNode_test,Cached_Result_With_Error){
    std::cout<<"Run test cached result when executed with error"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
    EXPECT_TRUE(arr->child(2)->execute().is_error());
    EXPECT_TRUE(arr->execute().is_error());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
    std::cout<<arr->cached_result().get_exception().get()->type()<<std::endl;
    EXPECT_EQ((*arr->cached_result().get_exception().get()),exceptions::DivisionZero(""));
}
TEST(ArrayNode_test,Cached_Result_id){
    std::cout<<"Run test cached at id result when executed"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::make_shared<ValueNode>(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    EXPECT_TRUE(arr->child(2)->cached_result().is_value());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
}
TEST(ArrayNode_test,is_Numeric){
    std::cout<<"Run test cached result when executed"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(Value_t(1));
    arr->insert_back(std::make_shared<ValueNode>(2));
    arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(Value_t(100));
    arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
    arr->insert_back(std::make_shared<ArrayNode>(2));
    arr->child(3)->insert_back(Value_t(1));
    arr->child(3)->insert_back(Value_t(2));
    EXPECT_TRUE(arr->is_numeric());
}
TEST(ArrayNode_test,is_String){
    std::cout<<"Run test is string array"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    EXPECT_TRUE(arr->is_string());
    arr->insert_back(Value_t("2"));
    EXPECT_FALSE(arr->is_string());
    EXPECT_FALSE(arr->is_numeric());
}
TEST(ArrayNode_test,is_Array){
    std::cout<<"Run test cached result when executed"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    EXPECT_TRUE(arr->is_string());
}
TEST(ArrayNode_test,Print_Text){
    std::cout<<"Run test print text"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    arr->insert_back(Value_t("2"));
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_text());
    //EXPECT_FALSE(arr->is_string());
    //EXPECT_FALSE(arr->is_numeric());
}
TEST(ArrayNode_test,Print_Result){
    std::cout<<"Run test print text"<<std::endl;
    std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    arr->insert_back(Value_t("2"));
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
}
