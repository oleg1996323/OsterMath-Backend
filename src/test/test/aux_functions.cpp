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

class Complex_Different_Nodes{

public:

    Complex_Different_Nodes(){
        bd = std::make_shared<BaseData>(bd_name);
        var_1_base = bd->add_variable("Var_1");
        auto var_2_base = bd->add_variable("Var_2");
        auto var_3_base = bd->add_variable("Var_3");
        std::shared_ptr<ArrayNode> arr_1 = std::make_shared<ArrayNode>(5);
        std::shared_ptr<ArrayNode> arr_2 = std::make_shared<ArrayNode>(5);
        std::shared_ptr<VariableNode> var_1 = var_1_base->node();
        std::shared_ptr<VariableNode> var_2 = var_2_base->node();
        std::shared_ptr<VariableNode> var_3 = var_3_base->node();
        EXPECT_FALSE(first_node_not_var(var_1));
        EXPECT_FALSE(first_node_not_var(var_1.get()));
        var_1->insert_back(arr_1);
        arr_1->insert_back(var_2);
        var_2->insert_back(arr_2);
        arr_2->insert_back(var_3);
        var_3->insert_back(std::make_shared<ValueNode>(1));
    }

    std::shared_ptr<VariableBase> get_var_1_node(){
        return var_1_base;
    }

private:
    std::string bd_name = "bd";
    std::shared_ptr<BaseData> bd;
    std::shared_ptr<VariableBase> var_1_base;
};

//TODO
class Complex_Same_Nodes{

};

class ComplexNode_1 : public ::testing::Test
{
protected:
	void SetUp()
	{
        
	}
	void TearDown()
	{
		
	}
    Complex_Different_Nodes nodes;
};

class Complex_nodes_2 : public ::testing::Test
{
protected:
    void SetUp()
    {
        arr_1 = std::make_shared<ArrayNode>(5);
        arr_2 = std::make_shared<ArrayNode>(5);
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
    }

    void TearDown()
    {

    }

    std::shared_ptr<Node> arr_1;
    std::shared_ptr<Node> arr_2;
};



TEST_F(ComplexNode_1,Find_first_node_not_variable){
    auto node = first_node_not_var(nodes.get_var_1_node()->node());
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::ARRAY);
    EXPECT_TRUE(node.get()==nodes.get_var_1_node()->node()->child(0).get());
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

TEST_F(Complex_nodes_2,CompareArrays_UniversalFunction_1){
    std::vector<std::shared_ptr<Node>> nodes;
    nodes.push_back(arr_1);
    nodes.push_back(arr_2);
    EXPECT_TRUE(check_sizes_arrays(nodes));
}

TEST_F(Complex_Different_Nodes,CompareArrays_UniversalFunction_2){
    std::vector<std::shared_ptr<Node>> complex_nodes;
    complex_nodes.push_back(nodes.get_var_1_node()->node());
    complex_nodes.push_back(var_1_base->node());
    EXPECT_TRUE(check_sizes_arrays(nodes));
}