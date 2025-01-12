#include <type_traits>
#include <iostream>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>
#include "test/test/array_node_test.h"
#include "array_node.h"
#include "val_node.h"
#include "func_node.h"
#include "string_node.h"
#include "bin_node.h"
#include "aux_functions.h"
#include "node_manager.h"

using namespace functions::auxiliary;

#include "include/test/test/fixtures.h"

TEST_F(DataBaseDefault,Insert_Back){
    {
        std::cout<<"Run test insert back"<<std::endl;
        
        std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(10);
        std::vector<Value_t> values(10);
        std::iota(values.begin(),values.end(),0);
        for(const auto& val:values)
            arr->insert_back(std::move(db_->make_node<ValueNode>(val)));
        EXPECT_EQ(arr->childs().size(),10);
        arr->insert_back(std::move(db_->make_node<ValueNode>(values.back()+1)));
        EXPECT_EQ(arr->childs().size(),11);
        root_->insert_back(std::move(arr));
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Insert){
    std::cout<<"Run test insert at position"<<std::endl;
    //TODO need to check construction - destruction
}
TEST_F(DataBaseDefault,Replace){
    std::cout<<"Run test replace at position"<<std::endl;
}
TEST_F(DataBaseDefault,Begins){
    {
    std::cout<<"Run test begin"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(0);
    EXPECT_EQ(arr->childs().begin(), arr->begin());
    arr->insert_back(db_->make_node<ValueNode>(1));
    EXPECT_EQ(arr->childs().begin(), arr->begin());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Ends){
    {
    std::cout<<"Run test begin"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(0);
    EXPECT_EQ(arr->begin(), arr->end());
    arr->insert_back(db_->make_node<ValueNode>(1));
    EXPECT_EQ(arr->begin()+1, arr->end());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,CopyConstructor){
    {
    std::cout<<"Run test copy constructor"<<std::endl;
    //TODO: here error
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    std::unique_ptr<ArrayNode> arr_1 = db_->make_node<ArrayNode>(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1->insert_back(db_->make_node<ValueNode>(val));
    std::unique_ptr<ArrayNode> arr_2 = db_->make_node<ArrayNode>(*arr_1);
    ArrayNode* arr_1_ptr = static_cast<ArrayNode*>(var_1->node()->insert_back(std::move(arr_1)));
    ArrayNode* arr_2_ptr = static_cast<ArrayNode*>(var_2->node()->insert_back(std::move(arr_2)));
    EXPECT_EQ(arr_1_ptr->size(),arr_2_ptr->size());
    for(auto iter = arr_2_ptr->begin();iter!=arr_2_ptr->end();++iter){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1_ptr->child(iter-arr_2_ptr->begin())));
    }
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,MoveConstructor){
    {
    std::cout<<"Run test move constructor"<<std::endl;
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    ArrayNode* arr_1_ptr = static_cast<ArrayNode*>(var_1->node()->insert_back(db_->make_node<ArrayNode>(10)));
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1_ptr->insert_back(db_->make_node<ValueNode>(val));
    ArrayNode* arr_2_ptr = static_cast<ArrayNode*>(var_2->node()->insert_back(db_->make_node<ArrayNode>(10)));
    arr_2_ptr->cut_paste(arr_1_ptr);
    EXPECT_TRUE(arr_1_ptr);
    EXPECT_EQ(arr_1_ptr->size(),0);
    EXPECT_EQ(arr_2_ptr->size(),10);
    for(auto iter = arr_2_ptr->begin();iter!=arr_2_ptr->end();++iter){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_2_ptr->child(iter-arr_2_ptr->begin())));
    }
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Operator_Eq_copy){
    {
    std::cout<<"Run test operator equal copy"<<std::endl;
    EXPECT_TRUE(std::is_copy_constructible_v<ArrayNode>);
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    ArrayNode* arr_1 = static_cast<ArrayNode*>(var_1->node()->insert_back(db_->make_node<ArrayNode>(1)));
    arr_1->insert_back(std::move(db_->make_node<ValueNode>(1)));
    ArrayNode* arr_2 = static_cast<ArrayNode*>(var_2->node()->insert_back(db_->make_node<ArrayNode>(2)));
    arr_2->insert_back(std::move(db_->make_node<ValueNode>(2)));
    arr_2->insert_back(std::move(db_->make_node<ValueNode>(3)));
    arr_1->copy_paste(arr_2);
    EXPECT_TRUE(arr_2);
    EXPECT_EQ(arr_1->size(),2);
    EXPECT_EQ(arr_1->childs().capacity(),2);
    }
    BaseData::get_anonymous_relation_manager()->log_state();
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
}
TEST_F(DataBaseDefault,Operator_Eq_move){
    {
    std::cout<<"Run test operator equal"<<std::endl;
    EXPECT_TRUE(std::is_move_constructible_v<ArrayNode>);
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    ArrayNode* arr_1 = static_cast<ArrayNode*>(var_1->node()->insert_back(db_->make_node<ArrayNode>(1)));
    arr_1->insert_back(db_->make_node<ValueNode>(1));
    AbstractNode* val_2 = arr_1->insert_back(db_->make_node<ValueNode>(2));
    ArrayNode* arr_2 = ArrayNode::implement_by(val_2);
    size_t sz = arr_2->size();
    size_t cap = arr_2->childs().capacity();
    arr_1->copy_paste(arr_2);
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
    EXPECT_TRUE(arr_1);
    EXPECT_EQ(arr_1->size(),sz);
    EXPECT_EQ(arr_1->childs().capacity(),cap);
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Type_Numeric_Array){
    {
    std::cout<<"Run test operator equal"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<ValueNode>(100000000));
    EXPECT_EQ(arr->type_val(),TYPE_VAL::NUMERIC_ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::VALUE);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::NUMERIC_ARRAY);
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Type_String_Array){
    //TODO: develop string node
}
TEST_F(DataBaseDefault,Type_Array){
    //TODO: develop string node
}
TEST_F(DataBaseDefault,ExecuteCorrect){
    {
    std::cout<<"Run test execute with expected correct result"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<ValueNode>(100000000));
    EXPECT_TRUE(arr->execute().is_node());
    EXPECT_EQ(arr.get(),arr->execute().get_node());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,ExecuteError){
    {
    std::cout<<"Run test execute with expected error result"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(0));
    Result res = arr->execute();
    EXPECT_TRUE(res.is_error());
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
    std::cout<<res.get_exception()->get_error()<<std::endl;
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,ExecuteCorrect_id){
    std::cout<<"Run test execute with expected correct result"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<ValueNode>(100000000));
    EXPECT_EQ(100000000,arr->execute().get_array_node()->child(2)->cached_result().get_value());
}
TEST_F(DataBaseDefault,ExecuteError_id){
    std::cout<<"Run test execute with expected error result"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(0));
    Result res = arr->execute();
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
}
TEST_F(DataBaseDefault,Cached_Result_With_Correct){
    std::cout<<"Run test cached result when executed correct"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    EXPECT_TRUE(arr->execute().is_node());
    EXPECT_TRUE(arr->execute().is_array());
    EXPECT_TRUE(arr->cached_result().get_array_node()->child(2)->cached_result().is_value());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
    std::cout<<arr->cached_result()<<std::endl;
    //EXPECT_EQ(arr->cached_result().get_node(),arr.get());
}
TEST_F(DataBaseDefault,Cached_Result_With_Error){
    std::cout<<"Run test cached result when executed with error"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(0));
    EXPECT_TRUE(arr->child(2)->execute().is_error());
    EXPECT_TRUE(arr->execute().is_error());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
    std::cout<<arr->cached_result().get_exception().get()->type()<<std::endl;
    EXPECT_EQ((*arr->cached_result().get_exception().get()),exceptions::DivisionZero(""));
}
TEST_F(DataBaseDefault,Cached_Result_id){
    std::cout<<"Run test cached at id result when executed"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(db_->make_node<ValueNode>(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    EXPECT_TRUE(arr->child(2)->cached_result().is_value());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
}
TEST_F(DataBaseDefault,is_Numeric){
    std::cout<<"Run test cached result when executed"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(Value_t(1));
    arr->insert_back(db_->make_node<ValueNode>(2));
    arr->insert_back(db_->make_node<BinaryNode>(BINARY_OP::DIV));
    arr->child(2)->insert_back(Value_t(100));
    arr->child(2)->insert_back(db_->make_node<ValueNode>(100));
    arr->insert_back(db_->make_node<ArrayNode>(2));
    arr->child(3)->insert_back(Value_t(1));
    arr->child(3)->insert_back(Value_t(2));
    EXPECT_TRUE(arr->is_numeric());
}
TEST_F(DataBaseDefault,is_String){
    std::cout<<"Run test is string array"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    EXPECT_TRUE(arr->is_string());
    arr->insert_back(Value_t("2"));
    EXPECT_FALSE(arr->is_string());
    EXPECT_FALSE(arr->is_numeric());
}
TEST_F(DataBaseDefault,is_Array){
    std::cout<<"Run test cached result when executed"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    EXPECT_TRUE(arr->is_string());
}
TEST_F(DataBaseDefault,Print_Text){
    std::cout<<"Run test print text"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    arr->insert_back(Value_t("2"));
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_text());
    //EXPECT_FALSE(arr->is_string());
    //EXPECT_FALSE(arr->is_numeric());
}
TEST_F(DataBaseDefault,Print_Result){
    std::cout<<"Run test print text"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    arr->insert_back(Value_t("2"));
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
}
TEST_F(DataBaseDefault,StringRectangleF){
    std::cout<<"Run test print text"<<std::endl;
    std::unique_ptr<ArrayNode> arr = db_->make_node<ArrayNode>(3);
    arr->insert_back(std::string("1"));
    arr->insert_back(std::string("2"));
    arr->insert_back(Value_t("2"));
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
}