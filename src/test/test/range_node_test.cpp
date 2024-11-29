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
    std::cout<<"Run test insert back"<<std::endl;
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
TEST(RangeFunctionNode_test,Example_2){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test insert back"<<std::endl;
    std::shared_ptr<RangeOperationNode> sum_func = std::make_shared<RangeOperationNode>(RANGE_OP::SUM);
    std::shared_ptr<RangeOperationNode> prod_func = std::make_shared<RangeOperationNode>(RANGE_OP::PROD);
    
    std::shared_ptr<BinaryNode> adding = std::make_shared<BinaryNode>(BINARY_OP::ADD);
    std::shared_ptr<BinaryNode> multiplication = std::make_shared<BinaryNode>(BINARY_OP::MUL);
    
    std::vector<Value_t> values(10);
    std::iota(values.begin(),values.end(),0);
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("BD");
    std::shared_ptr<VariableBase> A_var = bd->add_variable("A");
    std::shared_ptr<VariableBase> B_var = bd->add_variable("B");
    
    adding->insert_back(B_var->node());
    adding->insert_back(prod_func);
    sum_func->set_expression(adding);

    multiplication->insert_back(A_var->node());
    multiplication->insert_back(std::make_shared<ValueNode>(1));

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
    B_var->node()->insert_back(arr_2);
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    sum_func->set_variable_order(A_var->node(),2);
    prod_func->set_variable_order(A_var->node(),1);
    prod_func->set_expression(multiplication);

    //not defined index for B variable
    EXPECT_TRUE(sum_func->execute().is_error());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    //is correct execution
    sum_func->set_variable_order(B_var->node(),1);
    EXPECT_TRUE(sum_func->execute().is_value());
    std::cout<<"Range_Node result: "<<sum_func->get_result()<<std::endl;
    Value_t result_1=0;
    Value_t result_2=1;
    for(int i=0; i<10;++i){
        for(int j=0;j<10;++j)
            result_2*= Value_t(i)*1;
        result_1+=(result_2+Value_t(i));
        result_2=1;
    }
    if(sum_func->cached_result().is_value()){
        EXPECT_NEAR(sum_func->cached_result().get_value().convert_to<double>(),result_1.convert_to<double>(),1);
        std::cout<<sum_func->cached_result().get_value().convert_to<double>()<<std::endl;
        std::cout<<result_1.convert_to<double>()<<std::endl;
    }
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;

    EXPECT_EQ(sum_func->cached_result(),result_1);
    if(sum_func->cached_result().is_error())
        std::cout<<sum_func->cached_result().get_exception()->get_prompt()<<std::endl;
}
TEST(RangeFunctionNode_test,DifferentSizeVars){
    //SUM_I(#B+PROD_I(#A*1;#A;1);#A;2;#B;1)
    std::cout<<"Run test insert back"<<std::endl;
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
    
    std::cout<<"Run test insert at position"<<std::endl;
}
// TEST(RangeFunctionNode_test,Replace){
//     std::cout<<"Run test replace at position"<<std::endl;
// }
// TEST(RangeFunctionNode_test,Begins){
//     std::cout<<"Run test begin"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(0);
//     EXPECT_EQ(arr->childs().begin(), arr->begin());
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     EXPECT_EQ(arr->childs().begin(), arr->begin());
// }
// TEST(RangeFunctionNode_test,Ends){
//     std::cout<<"Run test begin"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(0);
//     EXPECT_EQ(arr->begin(), arr->end());
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     EXPECT_EQ(arr->begin()+1, arr->end());
// }
// TEST(RangeFunctionNode_test,CopyConstructor){
//     std::cout<<"Run test copy constructor"<<std::endl;
//     std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(10);
//     std::vector<Value_t> values(10);
//     std::iota(values.begin(),values.end(),0);
//     for(const auto& val:values)
//         arr_1->insert_back(std::make_shared<ValueNode>(val));
//     std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(*arr_1.get());
//     EXPECT_EQ(arr_1->size(),arr_2->size());
//     for(auto iter = arr_2->begin();iter!=arr_2->end();++iter){
//         EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1->child(iter-arr_2->begin())));
//     }
// }
// TEST(RangeFunctionNode_test,MoveConstructor){
//     std::cout<<"Run test move constructor"<<std::endl;
//     ArrayNode arr_1(10);
//     std::vector<Value_t> values(10);
//     std::iota(values.begin(),values.end(),0);
//     for(const auto& val:values)
//         arr_1.insert_back(std::make_shared<ValueNode>(val));
//     std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(std::move(arr_1));
//     EXPECT_EQ(arr_1.size(),arr_2->size());
//     for(auto iter = arr_2->begin();iter!=arr_2->end();++iter){
//         EXPECT_TRUE(check_arguments(TYPE_VAL::VALUE,arr_1.child(iter-arr_2->begin())));
//     }
// }
// TEST(RangeFunctionNode_test,Move_SharedPtrVal_Constructor){
//     std::cout<<"Run test move sharedptr constructor"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     std::shared_ptr<ValueNode> val = std::make_shared<ValueNode>(100);
//     arr = std::make_shared<ArrayNode>(std::move(val));
//     EXPECT_EQ(arr->child(0)->execute().get_value(),100.);
//     EXPECT_EQ(val.get(),nullptr);
// }
// TEST(RangeFunctionNode_test,Copy_SharedPtrVal_Constructor){
//     std::cout<<"Run test copy sharedptr constructor"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(10);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     std::shared_ptr<ValueNode> val = std::make_shared<ValueNode>(100);
//     arr = std::make_shared<ArrayNode>(val);
//     EXPECT_EQ(arr->child(0)->execute().get_value(),100.);
//     EXPECT_EQ(val.get(),arr->child(0).get());
// }
// TEST(RangeFunctionNode_test,Operator_Eq_copy){
//     std::cout<<"Run test operator equal copy"<<std::endl;
//     EXPECT_TRUE(std::is_copy_assignable_v<ArrayNode>);
//     std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(1);
//     arr_1->insert_back(std::make_shared<ValueNode>(1));
//     std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(2);
//     arr_2->insert_back(std::make_shared<ValueNode>(2));
//     arr_2->insert_back(std::make_shared<ValueNode>(3));
//     *arr_1.get() = *arr_2.get();
//     EXPECT_EQ(arr_1->size(),2);
//     EXPECT_EQ(arr_1->childs().capacity(),2);
//     //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
// }
// TEST(RangeFunctionNode_test,Operator_Eq_move){
//     std::cout<<"Run test operator equal"<<std::endl;
//     EXPECT_TRUE(std::is_move_assignable_v<ArrayNode>);
//     std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(1);
//     arr_1->insert_back(std::make_shared<ValueNode>(1));
//     arr_1->insert_back(std::make_shared<ValueNode>(2));
//     ArrayNode arr_2(std::make_shared<ValueNode>(2));
//     size_t sz = arr_2.size();
//     size_t cap = arr_2.childs().capacity();
//     *arr_1.get() = std::move(arr_2);
//     //EXPECT_EQ(arr_1->child(0)->execute().get_value(),2);
//     EXPECT_EQ(arr_1->size(),sz);
//     EXPECT_EQ(arr_1->childs().capacity(),cap);
// }
// TEST(RangeFunctionNode_test,Type_Numeric_Array){
//     std::cout<<"Run test operator equal"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<ValueNode>(100000000));
//     EXPECT_EQ(arr->type_val(),TYPE_VAL::NUMERIC_ARRAY);
//     EXPECT_TRUE(arr->type_val()&TYPE_VAL::VALUE);
//     EXPECT_TRUE(arr->type_val()&TYPE_VAL::ARRAY);
//     EXPECT_TRUE(arr->type_val()&TYPE_VAL::NUMERIC_ARRAY);
// }
// TEST(RangeFunctionNode_test,Type_String_Array){
//     //TODO: develop string node
// }
// TEST(RangeFunctionNode_test,Type_Array){
//     //TODO: develop string node
// }
// TEST(RangeFunctionNode_test,ExecuteCorrect){
//     std::cout<<"Run test execute with expected correct result"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<ValueNode>(100000000));
//     EXPECT_TRUE(arr->execute().is_node());
//     EXPECT_EQ(arr.get(),arr->execute().get_node());
// }
// TEST(RangeFunctionNode_test,ExecuteError){
//     std::cout<<"Run test execute with expected error result"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
//     Result res = arr->execute();
//     EXPECT_TRUE(res.is_error());
//     EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
//     std::cout<<res.get_exception()->get_error()<<std::endl;
// }
// TEST(RangeFunctionNode_test,ExecuteCorrect_id){
//     std::cout<<"Run test execute with expected correct result"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<ValueNode>(100000000));
//     EXPECT_TRUE(arr->execute(2).is_value());
//     EXPECT_EQ(100000000,arr->execute(2).get_value());
// }
// TEST(RangeFunctionNode_test,ExecuteError_id){
//     std::cout<<"Run test execute with expected error result"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
//     EXPECT_TRUE(arr->execute(2).is_error());
//     Result res = arr->execute();
//     EXPECT_EQ(exceptions::EXCEPTION_TYPE::DIVISION_ZERO,res.get_exception()->type());
// }
// TEST(RangeFunctionNode_test,Cached_Result_With_Correct){
//     std::cout<<"Run test cached result when executed correct"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     EXPECT_TRUE(arr->execute().is_node());
//     EXPECT_TRUE(arr->execute(2).is_value());
//     Result res = arr->execute();
//     EXPECT_EQ(res,arr->cached_result());
//     EXPECT_EQ(arr->cached_result().get_node(),arr.get());
// }
// TEST(RangeFunctionNode_test,Cached_Result_With_Error){
//     std::cout<<"Run test cached result when executed with error"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(0));
//     EXPECT_TRUE(arr->execute(2).is_error());
//     EXPECT_TRUE(arr->execute().is_error());
//     Result res = arr->execute();
//     EXPECT_EQ(res,arr->cached_result());
//     *arr->cached_result().get_exception().get()==exceptions::DivisionZero();
//     EXPECT_EQ((*arr->cached_result().get_exception().get()),exceptions::DivisionZero(""));
// }
// TEST(RangeFunctionNode_test,Cached_Result_id){
//     std::cout<<"Run test cached at id result when executed"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::make_shared<ValueNode>(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     EXPECT_TRUE(arr->execute(2).is_value());
//     Result res = arr->execute();
//     EXPECT_EQ(res,arr->cached_result());
// }
// TEST(RangeFunctionNode_test,is_Numeric){
//     std::cout<<"Run test cached result when executed"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(Value_t(1));
//     arr->insert_back(std::make_shared<ValueNode>(2));
//     arr->insert_back(std::make_shared<BinaryNode>(BINARY_OP::DIV));
//     arr->child(2)->insert_back(Value_t(100));
//     arr->child(2)->insert_back(std::make_shared<ValueNode>(100));
//     arr->insert_back(std::make_shared<ArrayNode>(2));
//     arr->child(3)->insert_back(Value_t(1));
//     arr->child(3)->insert_back(Value_t(2));
//     EXPECT_TRUE(arr->is_numeric());
// }
// TEST(RangeFunctionNode_test,is_String){
//     std::cout<<"Run test is string array"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::string("1"));
//     arr->insert_back(std::string("2"));
//     EXPECT_TRUE(arr->is_string());
//     arr->insert_back(Value_t("2"));
//     EXPECT_FALSE(arr->is_string());
//     EXPECT_FALSE(arr->is_numeric());
// }
// TEST(RangeFunctionNode_test,is_Array){
//     std::cout<<"Run test cached result when executed"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::string("1"));
//     arr->insert_back(std::string("2"));
//     EXPECT_TRUE(arr->is_string());
// }
// TEST(RangeFunctionNode_test,Print_Text){
//     std::cout<<"Run test print text"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::string("1"));
//     arr->insert_back(std::string("2"));
//     arr->insert_back(Value_t("2"));
//     arr->print_result(std::cout);
//     EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_text());
//     //EXPECT_FALSE(arr->is_string());
//     //EXPECT_FALSE(arr->is_numeric());
// }
// TEST(RangeFunctionNode_test,Print_Result){
//     std::cout<<"Run test print text"<<std::endl;
//     std::shared_ptr<ArrayNode> arr = std::make_shared<ArrayNode>(3);
//     arr->insert_back(std::string("1"));
//     arr->insert_back(std::string("2"));
//     arr->insert_back(Value_t("2"));
//     arr->print_result(std::cout);
//     EXPECT_EQ("[\"1\"; \"2\"; 2]",arr->get_result());
// }
