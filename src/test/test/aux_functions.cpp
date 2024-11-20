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

class Initial_Complex_Node_1{

public:

    Initial_Complex_Node_1(){
        bd = std::make_shared<BaseData>(bd_name);
        auto var_1_base = bd->add_variable("Var_1");
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
        node_1_ = var_1_base->node();
    }

    std::shared_ptr<VariableNode> node_1(){
        return node_1_;
    }

private:
    std::string bd_name = "bd";
    std::shared_ptr<BaseData> bd;
    std::shared_ptr<VariableNode> node_1_;
};

class Initial_Complex_Node_2{

public:

    Initial_Complex_Node_2(){
        bd = std::make_shared<BaseData>("bd");
        bd->add_variable("var_1");
        bd->add_variable("var_2");
        bd->add_variable("var_3");
        node_2_ = std::make_shared<ArrayNode>(5);
        node_2_with_vars_ = std::make_shared<ArrayNode>(5);
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
                subarr_21->insert_back(bd->get("var_3")->node());
                bd->get("var_3")->node()->insert_back(subarr_214);
            }
            if(i!=1 && i!=0){
                node_2_->insert_back(std::make_shared<ValueNode>(i));
                node_2_with_vars_->insert_back(std::make_shared<ValueNode>(i));
                subarr_1->insert_back(std::make_shared<ValueNode>(i));
                subarr_2->insert_back(std::make_shared<ValueNode>(i));
            }
            else if(i==1){
                node_2_->insert_back(subarr_1);
                node_2_with_vars_->insert_back(bd->get("var_1")->node());
                bd->get("var_1")->node()->insert_back(subarr_2);
                subarr_1->insert_back(subarr_11);
                subarr_2->insert_back(bd->get("var_2")->node());
                bd->get("var_2")->node()->insert_back(subarr_21);
            }
            else{
                subarr_1->insert_back(subarr_10);
                subarr_2->insert_back(subarr_20);
            }
            subarr_114->insert_back(std::make_shared<ValueNode>(i));
            auto bin_node = std::make_shared<BinaryNode>(BINARY_OP::ADD);
            bin_node->insert_back(std::make_shared<ValueNode>(i));
            bin_node->insert_back(std::make_shared<ValueNode>(i));
            subarr_214->insert_back(bin_node);
        }
    }

    std::shared_ptr<Node> node_2(){
        return node_2_;
    }

    std::shared_ptr<Node> node_2_with_vars(){
        return node_2_with_vars_;
    }

private:
    std::shared_ptr<Node> node_2_;
    std::shared_ptr<Node> node_2_with_vars_;
    std::shared_ptr<BaseData> bd;
};

class Initial_Rect_ArrayNode{

public:

    Initial_Rect_ArrayNode(){
        bd = std::make_shared<BaseData>("bd");
        bd->add_variable("var_1");
        bd->add_variable("var_2");
        bd->add_variable("var_3");
        rect_node = std::make_shared<ArrayNode>(5);
        not_rect_node = std::make_shared<ArrayNode>(5);
        std::shared_ptr<ArrayNode> rect_node_1 = std::make_shared<ArrayNode>(5);
        std::shared_ptr<ArrayNode> not_rect_node_1 = std::make_shared<ArrayNode>(5);
        std::shared_ptr<ArrayNode> rect_node_10 = std::make_shared<ArrayNode>(5);
        std::shared_ptr<ArrayNode> not_rect_node_10 = std::make_shared<ArrayNode>(5);
        for(int i=0;i<5;++i){
            if(i!=2){
                rect_node->insert_back(bd->get("var_1")->node());
                bd->get("var_1")->node()->insert_back(rect_node_1);
            }
            not_rect_node->insert_back(not_rect_node_1);
            if(i==0)
                not_rect_node_1->insert_back(not_rect_node_10);
            else not_rect_node_1->insert_back(std::make_shared<ValueNode>(i));
            not_rect_node_10->insert_back(std::make_shared<ValueNode>(i));
            rect_node_1->insert_back(rect_node_10);
            rect_node_10->insert_back(std::make_shared<ValueNode>(i));
        }
    }

    std::shared_ptr<Node> rect_array(){
        return rect_node;
    }

    std::shared_ptr<Node> not_rect_array(){
        return not_rect_node;
    }

private:
    std::shared_ptr<Node> rect_node;
    std::shared_ptr<Node> not_rect_node;
    std::shared_ptr<BaseData> bd;
};

class ComplexNode_1 : public ::testing::Test
{
protected:
	void SetUp()
	{	}
	void TearDown()
	{	}
    Initial_Complex_Node_1 node_1_;
    Initial_Complex_Node_2 node_2_;
    Initial_Rect_ArrayNode rect_nodes_;
};

/*class Complex_node_2 : public ::testing::Test
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
};*/

TEST_F(ComplexNode_1,Find_first_node_not_variable){
    auto node = first_node_not_var(node_1_.node_1());
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::ARRAY);
    EXPECT_TRUE(node.get()==node_1_.node_1()->child(0).get());
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

TEST_F(ComplexNode_1,CompareArrays_UniversalFunction_1){
    std::vector<std::shared_ptr<Node>> nodes;
    nodes.push_back(node_2_.node_2());
    nodes.push_back(node_2_.node_2_with_vars());
    EXPECT_TRUE(equal_morphology_nodes(nodes));
    nodes.push_back(node_1_.node_1());
    EXPECT_FALSE(equal_morphology_nodes(nodes));
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    nodes.clear();
    nodes.push_back(bd->add_variable("var_1")->node());
    nodes.push_back(bd->add_variable("var_2")->node());
    EXPECT_FALSE(equal_morphology_nodes(nodes));
}

TEST_F(ComplexNode_1,IsRectNodeMorphology){
    EXPECT_TRUE(is_rectangle_array_node(rect_nodes_.rect_array()));
    EXPECT_FALSE(is_rectangle_array_node(rect_nodes_.not_rect_array()));
}