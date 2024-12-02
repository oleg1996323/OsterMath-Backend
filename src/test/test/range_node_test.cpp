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
#include "range_node.h"
#include "aux_functions.h"
#include "types.h"
#include "data.h"

using namespace functions::auxiliary;

TEST(RangeFunctionNode_test,Example_1){
    //SUM_I(PROD_I(#A*10+10^2;#A;1);#A;2)
    std::cout<<"Run test Example 1"<<std::endl;
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<RangeOperationNode> prod_func = std::make_shared<RangeOperationNode>(RANGE_OP::PROD);
    
    sum_func->set_expression(prod_func);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    std::shared_ptr<BinaryNode> multiplication = std::make_shared<BinaryNode>(BINARY_OP::MUL);
    std::shared_ptr<BinaryNode> power = std::make_shared<BinaryNode>(BINARY_OP::POW);

    

    adding->insert_back(multiplication);
    adding->insert_back(power);
    
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");

    //setting reversed order

    multiplication->insert_back(A_var->node());
    multiplication->insert_back(std::make_shared<ValueNode>(10));

    power->insert_back(std::make_shared<ValueNode>(10));
    power->insert_back(std::make_shared<ValueNode>(2));

    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(10);
    int count = 0;
    for(const auto& val:values){
        arr_1->insert_back(arr_2); //same_values
        //if(count<5)
            arr_2->insert_back(std::make_shared<ValueNode>(val));
        ++count;
    }
    A_var->node()->insert_back(arr_1);
    EXPECT_TRUE(sum_func->execute().is_error());

    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    prod_func->set_expression(adding);
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
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<RangeOperationNode> prod_func = std::make_shared<RangeOperationNode>(RANGE_OP::PROD);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    std::shared_ptr<BinaryNode> multiplication = std::make_shared<BinaryNode>(BINARY_OP::MUL);
    
    std::vector<Value_t> values(100);
    std::iota(values.begin(),values.end(),0);
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    std::shared_ptr<VariableBase> B_var = bd->add_variable("B");
    
    adding->insert_back(B_var->node());
    adding->insert_back(prod_func);
    sum_func->set_expression(adding);

    multiplication->insert_back(A_var->node());
    multiplication->insert_back(std::make_shared<ValueNode>(1));

    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(100);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(100);
    int count = 0;
    for(const auto& val:values){
        //if(count<10000)
        arr_1->insert_back(arr_2); //same_values
        arr_2->insert_back(std::make_shared<ValueNode>(val));
        ++count;
    }
    A_var->node()->insert_back(arr_1);
    B_var->node()->insert_back(arr_2);
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    prod_func->set_expression(multiplication);

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
        for(int i=0; i<100;++i){
            for(int j=0;j<100;++j)
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
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    std::shared_ptr<VariableBase> B_var = bd->add_variable("B");
    
    adding->insert_back(B_var->node());
    adding->insert_back(A_var->node());
    sum_func->set_expression(adding);

    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(5);
    int count = 0;
    for(const auto& val:values){
        arr_1->insert_back(arr_2); //same_values
        if(count<5)
            arr_2->insert_back(std::make_shared<ValueNode>(val));
        ++count;
    }
    A_var->node()->insert_back(arr_1);
    B_var->node()->insert_back(arr_2);
    sum_func->set_variable_order(A_var->node(),1);
    sum_func->set_variable_order(B_var->node(),1);
    EXPECT_TRUE(sum_func->execute().is_error());
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,EmptyArrayVar){
    std::cout<<"Run test empty arrays with error result"<<std::endl;
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    adding->insert_back(A_var->node());
    adding->insert_back(std::make_shared<ValueNode>(1));
    sum_func->set_expression(adding);
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(10);
    A_var->node()->insert_back(arr_1);
    for(int count = 0; count<10;++count)
        arr_1->insert_back(arr_2); //same_values
    sum_func->set_variable_order(A_var->node(),1);
    EXPECT_TRUE(sum_func->execute().is_error());
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,TwinEmptyArraysVars){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test twin empty variables"<<std::endl;
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<RangeOperationNode> prod_func = std::make_shared<RangeOperationNode>(RANGE_OP::PROD);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    std::shared_ptr<BinaryNode> multiplication = std::make_shared<BinaryNode>(BINARY_OP::MUL);
    
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    std::shared_ptr<VariableBase> B_var = bd->add_variable("B");
    
    adding->insert_back(B_var->node());
    adding->insert_back(prod_func);
    sum_func->set_expression(adding);

    multiplication->insert_back(A_var->node());
    multiplication->insert_back(std::make_shared<ValueNode>(1));

    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(1000);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(1000);
    std::shared_ptr<ArrayNode> arr_3 = std::make_shared<ArrayNode>(1000);
    for(int i=0;i<1000;++i){
        //if(count<1000)
        arr_1->insert_back(arr_2); //same_values
    }
    A_var->node()->insert_back(arr_1);
    B_var->node()->insert_back(arr_3);
    for(int i=0;i<1000;++i){
        //if(count<1000)
        arr_1->insert_back(arr_2);
        arr_3->insert_back(i); //same_values
    }
    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    prod_func->set_expression(multiplication);
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
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<RangeOperationNode> prod_func = std::make_shared<RangeOperationNode>(RANGE_OP::PROD);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    std::shared_ptr<BinaryNode> multiplication = std::make_shared<BinaryNode>(BINARY_OP::MUL);
    
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    A_var->node()->insert_back(1);
    
    sum_func->set_expression(A_var->node());

    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,NotDefined_1_DimensionsTwinArrayVars){
    //SUM_I(#B+#A;#B;1;#A;1)
    std::cout<<"Run test not defined 1 dimension twin arrays variables"<<std::endl;
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    std::shared_ptr<VariableBase> B_var = bd->add_variable("B");
    
    adding->insert_back(B_var->node());
    adding->insert_back(A_var->node());
    sum_func->set_expression(adding);

    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(10);

    for(int i=0;i<10;++i){
        //if(count<1000)
        arr_1->insert_back(i); //same_values
        arr_2->insert_back(i);
    }
    A_var->node()->insert_back(arr_1);
    B_var->node()->insert_back(arr_2);
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