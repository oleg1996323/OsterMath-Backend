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
        
        ArrayNode* arr = root_->insert_back<ArrayNode>(10);
        std::vector<Value_t> values(10);
        std::iota(values.begin(),values.end(),0);
        for(const auto& val:values)
            arr->insert_back<ValueNode>(val);
        EXPECT_EQ(arr->childs().size(),10);
        arr->insert_back<ValueNode>(values.back()+1);
        EXPECT_EQ(arr->childs().size(),11);
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
    ArrayNode* arr = root_->insert_back<ArrayNode>(0);
    EXPECT_EQ(arr->childs().begin(), arr->begin());
    arr->insert_back<ValueNode>(1);
    EXPECT_EQ(arr->childs().begin(), arr->begin());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Ends){
    {
    std::cout<<"Run test begin"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(0);
    EXPECT_EQ(arr->begin(), arr->end());
    arr->insert_back<ValueNode>(1);
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
    ArrayNode* arr_1 = var_1->node()->insert_back<ArrayNode>(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1->insert_back<ValueNode>(val);
    ArrayNode* arr_2 = var_2->node()->insert_back<ArrayNode>(*arr_1);
    EXPECT_EQ(arr_1->size(),arr_2->size());
    for(auto iter = arr_2->begin();iter!=arr_2->end();++iter){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1->child(iter-arr_2->begin())));
    }
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,MoveConstructor){
    {
    std::cout<<"Run test move constructor"<<std::endl;
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    ArrayNode* arr_1 = var_1->node()->insert_back<ArrayNode>(10);
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    for(const auto& val:values)
        arr_1->insert_back<ValueNode>(val);
    ArrayNode* arr_2 = var_2->node()->insert_back<ArrayNode>(10);
    for(int i =10;i<100;i+=10){
        arr_2->insert_back<ValueNode>(i);
    }
    cut_paste(arr_1,arr_2);
    EXPECT_TRUE(arr_1);
    EXPECT_FALSE(var_1->node()->child(0));
    EXPECT_EQ(arr_1->size(),10);
    EXPECT_FALSE(var_1->node()->child(0));
    EXPECT_EQ(var_2->node()->child(0),arr_1);
    int i = 0;
    for(AbstractNode* child:*arr_1){
        EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,child));
        EXPECT_EQ(child->execute().get_value(),i);
        ++i;
    }
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Copy_paste_1){
    {
    std::cout<<"Run test operator equal copy"<<std::endl;
    EXPECT_TRUE(std::is_copy_constructible_v<ArrayNode>);
    auto var_1 = db_->add_variable("arr_1");
    auto var_2 = db_->add_variable("arr_2");
    ArrayNode* arr_1 = var_1->node()->insert_back<ArrayNode>(1);
    arr_1->insert_back<ValueNode>(1);
    ArrayNode* arr_2 = var_2->node()->insert_back<ArrayNode>(2);
    arr_2->insert_back<ValueNode>(2);
    arr_2->insert_back<ValueNode>(3);
    copy_paste(arr_1,arr_2);
    EXPECT_TRUE(arr_2);
    EXPECT_EQ(arr_1->size(),1);
    EXPECT_EQ(arr_2->size(),1);
    EXPECT_EQ(arr_1->childs().capacity(),1);
    EXPECT_EQ(arr_2->childs().capacity(),1);
    EXPECT_NE(arr_2->child(0),arr_1->child(0));
    EXPECT_EQ(arr_2->child(0)->execute().get_value(),arr_1->child(0)->execute().get_value());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
}
TEST_F(DataBaseDefault,Copy_paste_2){
    {
    std::cout<<"Run test operator equal"<<std::endl;
    EXPECT_TRUE(std::is_move_constructible_v<ArrayNode>);
    VariableBase* var = db_->add_variable("arr_2");
    ArrayNode* arr_1 = root_->insert_back<ArrayNode>(1);
    arr_1->insert_back<ValueNode>(1);
    arr_1->insert_back<ValueNode>(2);
    ArrayNode* arr_2 = var->node()->insert_back<ArrayNode>(2);
    arr_2->insert_back<ValueNode>(1);
    size_t sz = arr_1->size();
    size_t cap = arr_2->childs().capacity();
    copy_paste(arr_1,arr_2);
    EXPECT_EQ(arr_1->child(0)->execute().get_value(),arr_2->child(0)->execute().get_value());
    EXPECT_TRUE(arr_1);
    EXPECT_EQ(arr_1->size(),sz);
    EXPECT_EQ(arr_1->childs().capacity(),cap);
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Cut_paste){
    {
    std::cout<<"Run test operator equal"<<std::endl;
    EXPECT_TRUE(std::is_move_constructible_v<ArrayNode>);
    VariableBase* var = db_->add_variable("arr_2");
    ArrayNode* arr_1 = root_->insert_back<ArrayNode>(1);
    arr_1->insert_back<ValueNode>(1);
    arr_1->insert_back<ValueNode>(2);
    ArrayNode* arr_2 = var->node()->insert_back<ArrayNode>(2);
    arr_2->insert_back<ValueNode>(10);
    size_t sz = arr_1->size();
    size_t cap = arr_1->childs().capacity();
    cut_paste(arr_1,arr_2);
    EXPECT_FALSE(!var->node()->has_childs());
    EXPECT_FALSE(root_->child(0));
    EXPECT_EQ(var->node()->child(0)->child(0)->execute(),arr_1->child(0)->execute());
    EXPECT_EQ(var->node()->child<ArrayNode>(0)->size(),sz);
    EXPECT_EQ(var->node()->child<ArrayNode>(0)->childs().capacity(),cap);
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,Array_implement_by){
    ArrayNode* arr_1 = root_->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i)
        arr_1->insert_back<ValueNode>(i);
    size_t sz_1 = arr_1->size();
    ValueNode* val = arr_1->child<ValueNode>(5);
    ArrayNode* arr_2 = ArrayNode::implement_by(val);
    size_t sz_2 = arr_1->size();
    EXPECT_EQ(sz_1,sz_2);
    EXPECT_EQ(arr_2->size(),1);
    EXPECT_EQ(arr_2->owner().parent,arr_1);
    size_t cap = arr_2->childs().capacity();
    size_t nodes_before = arr_1->relation_manager()->nodes().size();
    cut_paste(arr_2,arr_1); //delete arr_1 + 9 his childs (except the arr_2 which is implemented by val)
    EXPECT_EQ(nodes_before - sz_2,arr_2->relation_manager()->nodes().size());
    EXPECT_EQ(arr_2->relation_manager()->nodes().find(arr_1),arr_2->relation_manager()->nodes().end());
    //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
    EXPECT_EQ(arr_2->childs().size(),1);
    EXPECT_EQ(arr_2->childs().capacity(),cap);
    EXPECT_EQ(arr_2->owner().parent,root_);
}
TEST_F(DataBaseDefault,Type_Numeric_Array){
    std::cout<<"Run test operator equal"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<ValueNode>(100000000);
    EXPECT_EQ(arr->type_val(),TYPE_VAL::NUMERIC_ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::VALUE);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::ARRAY);
    EXPECT_TRUE(arr->type_val()&TYPE_VAL::NUMERIC_ARRAY);
    BaseData::get_anonymous_relation_manager()->log_state();
    db_.reset();
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
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<ValueNode>(100000000);
    EXPECT_TRUE(arr->execute().is_node());
    EXPECT_EQ(arr,arr->execute().get_node());
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,ExecuteError){
    {
    std::cout<<"Run test execute with expected error result"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(0);
    Result res = arr->execute();
    EXPECT_TRUE(res.is_error());
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
    std::cout<<res.get_exception()->get_error()<<std::endl;
    }
    BaseData::get_anonymous_relation_manager()->log_state();
}
TEST_F(DataBaseDefault,ExecuteCorrect_id){
    std::cout<<"Run test execute with expected correct result"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    ValueNode* val = arr->insert_back<ValueNode>(100000000);
    EXPECT_EQ(val->cached_result().get_value(),arr->execute().get_array_node()->child(2)->cached_result().get_value());
}
TEST_F(DataBaseDefault,ExecuteError_id){
    std::cout<<"Run test execute with expected error result"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(0);
    Result res = arr->execute();
    EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
}
TEST_F(DataBaseDefault,Cached_Result_With_Correct){
    std::cout<<"Run test cached result when executed correct"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(100);
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
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(0);
    EXPECT_TRUE(arr->child(2)->execute().is_error());
    EXPECT_TRUE(arr->execute().is_error());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
    std::cout<<arr->cached_result().get_exception().get()->type()<<std::endl;
    EXPECT_EQ((*arr->cached_result().get_exception().get()),exceptions::DivisionZero(""));
}
TEST_F(DataBaseDefault,Cached_Result_id){
    std::cout<<"Run test cached at id result when executed"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(100);
    EXPECT_TRUE(arr->child(2)->cached_result().is_value());
    Result res = arr->execute();
    EXPECT_EQ(res,arr->cached_result());
}
TEST_F(DataBaseDefault,is_Numeric){
    std::cout<<"Run test cached result when executed"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<ValueNode>(1);
    arr->insert_back<ValueNode>(2);
    arr->insert_back<BinaryNode>(BINARY_OP::DIV);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->child(2)->insert_back<ValueNode>(100);
    arr->insert_back<ArrayNode>(2);
    arr->child(3)->insert_back<ValueNode>(1);
    arr->child(3)->insert_back<ValueNode>(2);
    EXPECT_TRUE(arr->is_numeric());
}
TEST_F(DataBaseDefault,is_String){
    std::cout<<"Run test is string array"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<StringNode>("1");
    arr->insert_back<StringNode>("2");
    EXPECT_TRUE(arr->is_string());
    arr->insert_back<ValueNode>("2");
    EXPECT_FALSE(arr->is_string());
    EXPECT_FALSE(arr->is_numeric());
}
TEST_F(DataBaseDefault,is_Array){
    std::cout<<"Run test cached result when executed"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<StringNode>("1");
    arr->insert_back<StringNode>("2");
    EXPECT_TRUE(arr->is_string());
}
TEST_F(DataBaseDefault,Print_Text){
    std::cout<<"Run test print text"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<StringNode>("1");
    arr->insert_back<StringNode>("2");
    arr->insert_back<ValueNode>("2");
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_text());
    //EXPECT_FALSE(arr->is_string());
    //EXPECT_FALSE(arr->is_numeric());
}
TEST_F(DataBaseDefault,Print_Result){
    std::cout<<"Run test print text"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<StringNode>("1");
    arr->insert_back<StringNode>("2");
    arr->insert_back<ValueNode>("2");
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
}
TEST_F(DataBaseDefault,StringRectangleF){
    std::cout<<"Run test print text"<<std::endl;
    ArrayNode* arr = root_->insert_back<ArrayNode>(3);
    arr->insert_back<StringNode>("1");
    arr->insert_back<StringNode>("2");
    arr->insert_back<ValueNode>("2");
    arr->print_result(std::cout);
    EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
}
//TODO: add test for discard