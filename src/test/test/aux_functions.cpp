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
#include "var_node.h"
#include "aux_functions.h"
#include "types.h"

using namespace functions::auxiliary;

TEST(AuxiliaryFunctions,Find_first_node_not_variable){
    std::string bd_name = "bd";
    BaseData bd(bd_name);
    std::string var_1_name = "Var_1";
    std::string var_2_name = "Var_2";
    std::string var_3_name = "Var_2";
    VariableBase var_1_base(var_1_name,&bd);
    VariableBase var_2_base(var_1_name,&bd);
    VariableBase var_3_base(var_1_name,&bd);
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<VariableNode> var_1 = std::make_shared<VariableNode>(&var_1_base);
    std::shared_ptr<VariableNode> var_2 = std::make_shared<VariableNode>(&var_2_base);
    std::shared_ptr<VariableNode> var_3 = std::make_shared<VariableNode>(&var_3_base);
    EXPECT_FALSE(first_node_not_var(var_1));
    EXPECT_FALSE(first_node_not_var(var_1.get()));
    var_1->insert_back(arr_1);
    arr_1->insert_back(var_2);
    var_2->insert_back(arr_2);
    arr_2->insert_back(var_3);
    var_3->insert_back(std::make_shared<ValueNode>(1));
    auto node = first_node_not_var(var_1);
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::ARRAY);
    EXPECT_TRUE(node.get()==var_1->child(0).get());
    node = first_node_not_var(node->child(0));
    EXPECT_TRUE(node);
    node = first_node_not_var(node->child(0));
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::VALUE);
    //var.insert_back()
}

TEST(AuxiliaryFunctions,Find_first_node_not_variable_by_ids){
        std::string bd_name = "bd";
    BaseData bd(bd_name);
    std::string var_1_name = "Var_1";
    std::string var_2_name = "Var_2";
    std::string var_3_name = "Var_2";
    VariableBase var_1_base(var_1_name,&bd);
    VariableBase var_2_base(var_1_name,&bd);
    VariableBase var_3_base(var_1_name,&bd);
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<VariableNode> var_1 = std::make_shared<VariableNode>(&var_1_base);
    std::shared_ptr<VariableNode> var_2 = std::make_shared<VariableNode>(&var_2_base);
    std::shared_ptr<VariableNode> var_3 = std::make_shared<VariableNode>(&var_3_base);
    EXPECT_FALSE(first_node_not_var(var_1));
    EXPECT_FALSE(first_node_not_var(var_1.get()));
    var_1->insert_back(arr_1);
    arr_1->insert_back(var_2);
    for(int i = 0;i<4;++i){
        arr_1->insert_back(std::make_shared<ValueNode>(i));
    }
    var_2->insert_back(arr_2);
    arr_2->insert_back(var_3);
    for(int i = 0;i<4;++i){
        arr_2->insert_back(std::make_shared<ValueNode>(i));
    }
    var_3->insert_back(std::make_shared<ValueNode>(1));
    auto node = first_node_not_var_by_ids(var_1,{0,0}); //arr_1(initial node) -> arr_2(0) -> arr_2(0) value
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::VALUE);
    node = first_node_not_var_by_ids(var_1,{4}); //arr_1(initial node) -> arr_2(4) value
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::VALUE);
}

TEST(AuxiliaryFunctions,CompareArrays_UniversalFunction){
    std::vector<std::shared_ptr<Node>> nodes;
    std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_1 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_2 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_10 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_20 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_11 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_21 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_114 = std::make_shared<ArrayNode>(5);
    std::shared_ptr<ArrayNode> subarr_214 = std::make_shared<ArrayNode>(5);
    for(int i=0;i<5;++i){
        if(i!=4){
            subarr_11->insert_back(std::make_shared<ValueNode>(i));
            subarr_21->insert_back(std::make_shared<ValueNode>(i));
        }
        else{
            subarr_11->insert_back(subarr_114);
            subarr_21->insert_back(subarr_214);
        }
        if(i!=1 && i!=0){
            subarr_1->insert_back(std::make_shared<ValueNode>(i));
            subarr_2->insert_back(std::make_shared<ValueNode>(i));
        }
        else if(i==1){
            arr_1->insert_back(subarr_1);
            arr_2->insert_back(subarr_2);
            subarr_1->insert_back(subarr_11);
            subarr_2->insert_back(subarr_21);
        }
        else{
            arr_1->insert_back(std::make_shared<ValueNode>(i));
            arr_2->insert_back(std::make_shared<ValueNode>(i));
            subarr_1->insert_back(subarr_10);
            subarr_2->insert_back(subarr_20);
        }
        subarr_114->insert_back(std::make_shared<ValueNode>(i));
        subarr_214->insert_back(std::make_shared<ValueNode>(i));
    }
    nodes.push_back(arr_1);
    nodes.push_back(arr_2);
    // nodes.push_back(subarr_114);
    // nodes.push_back(subarr_214);
    std::cout<<"Array 1: "<<arr_1->get_text()<<std::endl;
    std::cout<<"Array 2: "<<arr_2->get_text()<<std::endl;
    EXPECT_TRUE(check_sizes_arrays(nodes));
}