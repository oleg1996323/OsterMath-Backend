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
#include "range_node.h"
#include "aux_functions.h"
#include "types.h"
#include "data.h"

using namespace functions::auxiliary;

TEST(RangeFunctionNode_test,Example_1){
    //SUM_I(PROD_I(#A*10+10^2;#A;1);#A;2)
    std::cout<<"Run test Example 1"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);
    RangeOperationNode* prod_func = sum_func->set_expression<RangeOperationNode>(RANGE_OP::PROD);
    
    BinaryNode* adding = prod_func->set_expression<BinaryNode>(BINARY_OP::ADD);
    BinaryNode* multiplication = adding->insert_back<BinaryNode>(BINARY_OP::MUL);
    BinaryNode* power = adding->insert_back<BinaryNode>(BINARY_OP::POW);
    
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    VariableBase* A_var = bd->add_variable("A");

    //setting reversed order

    multiplication->insert_back_ref(A_var->node());
    multiplication->insert_back<ValueNode>(10);

    power->insert_back<ValueNode>(10);
    power->insert_back<ValueNode>(2);

    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = nullptr;
    int count = 0;
    for(const auto& val:values){
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(10); //same_values
        else arr_1->insert_back_ref(arr_2);
        //if(count<5)
            arr_2->insert_back<ValueNode>(val);
        ++count;
    }

    EXPECT_TRUE(sum_func->execute().is_error());

    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    
    EXPECT_TRUE(sum_func->execute().is_value());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    Value_t result_1=0;
    Value_t result_2=1;
    for(int i=0; i<10;++i){
        for(int j=0;j<10;++j){
            result_2*= Value_t(i)*10+pow(10,2);
        }
        result_1+=result_2;
        result_2=1;
    }
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
    EXPECT_EQ(sum_func->cached_result(),result_1);
}

#include "test/log_duration.h"

TEST(RangeFunctionNode_test,Example_2){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test Example 2"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    const int node_count = 100;
    
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);
    BinaryNode* adding = sum_func->set_expression<BinaryNode>(BINARY_OP::ADD);

    VariableBase* B_var = bd->add_variable("B");
    adding->insert_back_ref(B_var->node());

    RangeOperationNode* prod_func = adding->insert_back<RangeOperationNode>(RANGE_OP::PROD);
    
    BinaryNode* multiplication = prod_func->set_expression<BinaryNode>(BINARY_OP::MUL);
    
    VariableBase* A_var = bd->add_variable("A");
    multiplication->insert_back_ref(A_var->node());
    multiplication->insert_back<ValueNode>(1);

    std::vector<Value_t> values(node_count);
    std::iota(values.begin(),values.end(),0);

    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(node_count);
    ArrayNode* arr_2 = nullptr;
    int count = 0;
    for(const auto& val:values){
        //if(count<10000)
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(node_count); //same_values
        else arr_1->insert_back_ref(arr_2);
        arr_2->insert_back<ValueNode>(val);
        ++count;
    }
    B_var->node()->insert_back_ref(arr_2);
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);

    //not defined index for B variable
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
    //is correct execution
    sum_func->set_variable_order(B_var->node(),1);
    {
        LOG_DURATION("Test cycle");
        EXPECT_TRUE(sum_func->execute().is_value());
    }
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    Value_t result_1=0;
    Value_t result_2=1;
    {
        LOG_DURATION("Test cycle");
        for(int i=0; i<node_count;++i){
            for(int j=0;j<node_count;++j)
                result_2*= Value_t(i)*1;
            result_1+=(result_2+Value_t(i));
            result_2=1;
        }
    }
    if(sum_func->cached_result().is_value()){
        EXPECT_EQ(sum_func->cached_result(),result_1);
        std::cout<<sum_func->cached_result()<<std::endl;
        std::cout<<result_1<<std::endl;
    }
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;

    EXPECT_EQ(sum_func->cached_result(),result_1);
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,DifferentSizeVars){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test different size arrays var with result error"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);
    
    BinaryNode* adding = sum_func->set_expression<BinaryNode>(BINARY_OP::ADD);
    
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);

    VariableBase* A_var = bd->add_variable("A");
    VariableBase* B_var = bd->add_variable("B");
    
    adding->insert_back_ref(B_var->node());
    adding->insert_back_ref(A_var->node());

    
    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = nullptr;
    int count = 0;
    for(const auto& val:values){
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(5); //same_values
        else arr_1->insert_back_ref(arr_2);
        if(count<5)
            arr_2->insert_back<ValueNode>(val);
        ++count;
    }
    B_var->node()->insert_back_ref(arr_2);
    sum_func->set_variable_order(A_var->node(),1);
    sum_func->set_variable_order(B_var->node(),1);
    EXPECT_TRUE(sum_func->execute().is_error());
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,EmptyArrayVar){
    std::cout<<"Run test empty arrays with error result"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);
    BinaryNode* adding = sum_func->set_expression<BinaryNode>(BINARY_OP::ADD);

    VariableBase* A_var = bd->add_variable("A");
    adding->insert_back_ref(A_var->node());
    adding->insert_back<ValueNode>(1);
    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = nullptr;
    for(int count = 0; count<10;++count)
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(10); //same_values
        else arr_1->insert_back_ref(arr_2);
    sum_func->set_variable_order(A_var->node(),1);
    EXPECT_TRUE(sum_func->execute().is_error());
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,TwinEmptyArraysVars){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test twin empty variables"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);
    BinaryNode* adding = sum_func->set_expression<BinaryNode>(BINARY_OP::ADD);

    VariableBase* B_var = bd->add_variable("B");
    adding->insert_back_ref(B_var->node());
    RangeOperationNode* prod_func = adding->insert_back<RangeOperationNode>(RANGE_OP::PROD);
    
    BinaryNode* multiplication = prod_func->set_expression<BinaryNode>(BINARY_OP::MUL);
    VariableBase* A_var = bd->add_variable("A");
    multiplication->insert_back_ref(A_var->node());
    multiplication->insert_back<ValueNode>(1);

    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(1000);
    ArrayNode* arr_2 = nullptr;
    ArrayNode* arr_3 = B_var->node()->insert_back<ArrayNode>(1000);
    for(int i=0;i<1000;++i){
        //if(count<1000)
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(1000); //same_values
        else arr_1->insert_back_ref(arr_2);
    }
    for(int i=0;i<1000;++i){
        //if(count<1000)
        if(!arr_2)
            arr_2 = arr_1->insert_back<ArrayNode>(1000);
        else arr_1->insert_back_ref(arr_2);
        arr_3->insert_back<ValueNode>(i); //same_values
    }
    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    
    sum_func->set_variable_order(B_var->node(),1);
    //not defined index for B variable
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,NotArrayVar){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test not array variable"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::unique_ptr<RangeOperationNode> sum_func = bd->make_node<RangeOperationNode>(RANGE_OP::SUM);
    std::unique_ptr<RangeOperationNode> prod_func = bd->make_node<RangeOperationNode>(RANGE_OP::PROD);
    
    std::unique_ptr<BinaryNode> adding = bd->make_node<BinaryNode>(BINARY_OP::ADD);
    std::unique_ptr<BinaryNode> multiplication = bd->make_node<BinaryNode>(BINARY_OP::MUL);
    

    VariableBase* A_var = bd->add_variable("A");
    A_var->node()->insert_back<ValueNode>(1);
    
    sum_func->set_expression(A_var->node());

    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,NotDefined_1_DimensionsTwinArrayVars){
    //SUM_I(#B+#A;#B;1;#A;1)
    std::cout<<"Run test not defined 1 dimension twin arrays variables"<<std::endl;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    auto root_ = bd->add_variable("root");
    RangeOperationNode* sum_func = root_->node()->insert_back<RangeOperationNode>(RANGE_OP::SUM);    
    BinaryNode* adding = sum_func->set_expression<BinaryNode>(BINARY_OP::ADD);
    
    VariableBase* A_var = bd->add_variable("A");
    VariableBase* B_var = bd->add_variable("B");
    
    adding->insert_back_ref(B_var->node());
    adding->insert_back_ref(A_var->node());

    ArrayNode* arr_1 = A_var->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B_var->node()->insert_back<ArrayNode>(10);

    for(int i=0;i<10;++i){
        //if(count<1000)
        arr_1->insert_back<ValueNode>(i); //same_values
        arr_2->insert_back<ValueNode>(i);
    }
    
    sum_func->set_variable_order(A_var->node());
    sum_func->set_variable_order(B_var->node());

    //not defined index for B variable
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;

    sum_func->set_variable_order(A_var->node(),1);
    sum_func->set_variable_order(B_var->node(),1);

    size_t result = 0;
    for(size_t i=0;i<10;++i)
        result+=2*i;

    EXPECT_TRUE(sum_func->execute().is_value());
    EXPECT_EQ(sum_func->cached_result(),result);
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}