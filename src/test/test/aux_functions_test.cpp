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
#include "var_node.h"
#include "aux_functions.h"
#include "types.h"

using namespace functions::auxiliary;

class Initial_Complex_Node_1{

public:

    Initial_Complex_Node_1(){
        bd = std::make_shared<BaseData>(bd_name);
        auto var_1_base = bd->add_variable("Var_1_case_1");
        auto var_2_base = bd->add_variable("Var_2_case_1");
        auto var_3_base = bd->add_variable("Var_3_case_1");
        std::unique_ptr<ArrayNode> arr_1 = std::make_unique<ArrayNode>(5);
        std::unique_ptr<ArrayNode> arr_2 = std::make_unique<ArrayNode>(5);
        VariableNode* var_1 = var_1_base->node();
        VariableNode* var_2 = var_2_base->node();
        VariableNode* var_3 = var_3_base->node();
        EXPECT_FALSE(first_node_not_var(var_1));
        auto arr_1_ptr = var_1->insert_back(std::move(arr_1));
        arr_1_ptr->insert_back_ref(var_2);
        auto arr_2_ptr = var_2->insert_back(std::move(arr_2));
        arr_2_ptr->insert_back_ref(var_3);
        var_3->insert_back(var_3->relation_manager()->make_node<ValueNode>(1));
        node_1_ = var_1_base->node();
    }

    VariableNode* node_1(){
        return node_1_;
    }

private:
    std::string bd_name = "bd";
    std::shared_ptr<BaseData> bd;
    VariableNode* node_1_;
};

class Initial_Complex_Node_2{

public:

    Initial_Complex_Node_2(){
        bd_1 = std::make_shared<BaseData>("bd_1");
        bd_2 = std::make_shared<BaseData>("bd_2");
        auto root_1 = bd_1->add_variable("root_1");
        auto root_2 = bd_2->add_variable("root_2");
        auto var_1 = bd_2->add_variable("var_1_case_2");
        auto var_2 = bd_2->add_variable("var_2_case_2");
        auto var_3 = bd_2->add_variable("var_3_case_2");
        node_2_ = static_cast<ArrayNode*>(root_1->node()->insert_back(root_1->node()->relation_manager()->make_node<ArrayNode>(5)));
        node_2_with_vars_ = static_cast<ArrayNode*>(root_2->node()->insert_back(root_2->node()->relation_manager()->make_node<ArrayNode>(5)));
        std::unique_ptr<ArrayNode> subarr_1 = node_2_->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_2 = node_2_with_vars_->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_10 = subarr_1->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_20 = subarr_2->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_11 = subarr_1->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_21 = subarr_2->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_114 = subarr_11->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> subarr_214 = subarr_21->relation_manager()->make_node<ArrayNode>(5);
        ArrayNode* subarr_1_ptr = subarr_1.get();
        ArrayNode* subarr_2_ptr = subarr_2.get();
        ArrayNode* subarr_10_ptr = subarr_10.get();
        ArrayNode* subarr_20_ptr = subarr_20.get();
        ArrayNode* subarr_11_ptr = subarr_11.get();
        ArrayNode* subarr_21_ptr = subarr_21.get();
        ArrayNode* subarr_114_ptr = subarr_114.get();
        ArrayNode* subarr_214_ptr = subarr_214.get();

        for(int i=0;i<5;++i){
            if(i!=4){
                subarr_11_ptr->insert_back(subarr_11_ptr->relation_manager()->make_node<ValueNode>(i));
                subarr_21_ptr->insert_back(subarr_21_ptr->relation_manager()->make_node<ValueNode>(i));
            }
            else{
                if(subarr_114)
                    subarr_11_ptr->insert_back(std::move(subarr_114));
                else
                    subarr_11_ptr->insert_back_ref(std::move(subarr_114_ptr));
                subarr_21_ptr->insert_back_ref(var_3->node());
                if(subarr_214)
                    var_3->node()->insert_back(std::move(subarr_214));
                else var_3->node()->insert_back_ref(subarr_214_ptr);
            }
            if(i!=1 && i!=0){
                node_2_->insert_back(node_2_->relation_manager()->make_node<ValueNode>(i));
                node_2_with_vars_->insert_back(node_2_with_vars_->relation_manager()->make_node<ValueNode>(i));
                subarr_1_ptr->insert_back(subarr_1_ptr->relation_manager()->make_node<ValueNode>(i));
                subarr_2_ptr->insert_back(subarr_2_ptr->relation_manager()->make_node<ValueNode>(i));
            }
            else if(i==1){
                if(subarr_1)
                    node_2_->insert_back(std::move(subarr_1));
                else node_2_->insert_back_ref(subarr_1_ptr);
                node_2_with_vars_->insert_back_ref(var_1->node());
                if(subarr_2)
                    var_1->node()->insert_back(std::move(subarr_2));
                else var_1->node()->insert_back_ref(subarr_2_ptr);
                if(subarr_11)
                    subarr_1_ptr->insert_back(std::move(subarr_11));
                else subarr_1_ptr->insert_back_ref(subarr_11_ptr);
                subarr_2_ptr->insert_back_ref(var_2->node());
                if(subarr_21)
                    var_2->node()->insert_back(std::move(subarr_21));
                else var_2->node()->insert_back_ref(subarr_21_ptr);
            }
            else{
                if(subarr_10)
                    subarr_1_ptr->insert_back(std::move(subarr_10));
                else subarr_1_ptr->insert_back_ref(subarr_10_ptr);
                if(subarr_20)
                    subarr_2_ptr->insert_back(std::move(subarr_20));
                else subarr_2_ptr->insert_back_ref(subarr_20_ptr);
            }
            subarr_114_ptr->insert_back(subarr_114_ptr->relation_manager()->make_node<ValueNode>(i));
            AbstractNode* bin_node = subarr_214_ptr->insert_back(subarr_214_ptr->relation_manager()->make_node<BinaryNode>(BINARY_OP::ADD));
            bin_node->insert_back(bin_node->relation_manager()->make_node<ValueNode>(i));
            bin_node->insert_back(bin_node->relation_manager()->make_node<ValueNode>(i));

        }
    }

    AbstractNode* node_2(){
        return node_2_;
    }

    AbstractNode* node_2_with_vars(){
        return node_2_with_vars_;
    }

    ~Initial_Complex_Node_2(){
        
    }

private:
    ArrayNode* node_2_;
    ArrayNode* node_2_with_vars_;
    std::shared_ptr<BaseData> bd_1;
    std::shared_ptr<BaseData> bd_2;
};

class Initial_Rect_ArrayNode{

public:

    Initial_Rect_ArrayNode(){
        bd = std::make_shared<BaseData>("bd_3");
        auto var_rect_node = bd->add_variable("rect");
        auto var_not_rect_node = bd->add_variable("not rect");
        auto var_1 = bd->add_variable("var_1_case_3");
        rect_node = var_rect_node->node()->insert_back(bd->make_node<ArrayNode>(5));
        not_rect_node = var_not_rect_node->node()->insert_back(bd->make_node<ArrayNode>(5));
        std::unique_ptr<ArrayNode> rect_node_1 = var_1->node()->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> not_rect_node_1 = not_rect_node->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> rect_node_10 = rect_node_1->relation_manager()->make_node<ArrayNode>(5);
        std::unique_ptr<ArrayNode> not_rect_node_10 = bd->make_node<ArrayNode>(5);
        ArrayNode* rect_node_1_ptr = rect_node_1.get();
        ArrayNode* not_rect_node_1_ptr = not_rect_node_1.get();
        ArrayNode* rect_node_10_ptr = rect_node_10.get();
        ArrayNode* not_rect_node_10_ptr = not_rect_node_10.get();
        for(int i=0;i<5;++i){
            if(i!=2){
                rect_node->insert_back_ref(var_1->node());
                if(rect_node_1)
                    var_1->node()->insert_back(std::move(rect_node_1));
                else var_1->node()->insert_back_ref(rect_node_1_ptr);
            }
            if(not_rect_node_1)
                not_rect_node->insert_back(std::move(not_rect_node_1));
            else
                not_rect_node->insert_back_ref(not_rect_node_1_ptr);
            if(i==0){
                if(not_rect_node_10)
                    not_rect_node_1_ptr->insert_back(std::move(not_rect_node_10));
                else not_rect_node_1_ptr->insert_back_ref(not_rect_node_10_ptr);
            }
            else not_rect_node_1_ptr->insert_back(bd->make_node<ValueNode>(i));
            not_rect_node_10_ptr->insert_back(bd->make_node<ValueNode>(i));

            if(rect_node_10)
                rect_node_1_ptr->insert_back(std::move(rect_node_10));
            else 
                rect_node_1_ptr->insert_back_ref(rect_node_10_ptr);

            rect_node_10_ptr->insert_back(bd->make_node<ValueNode>(i));
        }
    }

    AbstractNode* rect_array(){
        return rect_node;
    }

    AbstractNode* not_rect_array(){
        return not_rect_node;
    }

private:
    AbstractNode* rect_node;
    AbstractNode* not_rect_node;
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

TEST_F(ComplexNode_1,Find_first_node_not_variable){
    try{
        auto node = first_node_not_var(node_1_.node_1());
        EXPECT_TRUE(node);
        EXPECT_EQ(node->type(),NODE_TYPE::ARRAY);
        EXPECT_EQ(node,node_1_.node_1()->child(0));
        node = first_node_not_var(node->child(0));
        EXPECT_TRUE(node);
        node = first_node_not_var(node->child(0));
        EXPECT_TRUE(node);
        EXPECT_EQ(node->type(),NODE_TYPE::VALUE);
    }
    catch(const std::exception& err){
        for(auto& [node,childs]:node_1_.node_1()->relation_manager()->childs_){
            std::cerr<<"Type: "<<node->type();
            for(auto& child:childs)
                std::cerr<<"Childs: "<<child->type()<<" ; ";
            std::cerr<<std::endl;
        }
    }
    //var.insert_back()
}

TEST(AuxiliaryFunctions,Find_first_node_not_variable_by_ids){
    std::string bd_name = "bd";
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>(bd_name);
    auto var_1= bd->add_variable("Var_1");
    auto var_2 = bd->add_variable("Var_2");
    auto var_3 = bd->add_variable("Var_3");
    EXPECT_FALSE(first_node_not_var(var_1->node()));
    auto arr_1 = static_cast<ArrayNode*>(var_1->node()->insert_back(std::make_unique<ArrayNode>(5)));
    arr_1->insert_back_ref(var_2->node());
    for(int i = 0;i<4;++i){
        arr_1->insert_back(std::make_unique<ValueNode>(i));
    }
    auto arr_2 = static_cast<ArrayNode*>(var_2->node()->insert_back(std::make_unique<ArrayNode>(5)));
    arr_2->insert_back_ref(var_3->node());
    for(int i = 0;i<4;++i){
        arr_2->insert_back(std::make_unique<ValueNode>(i));
    }
    var_3->node()->insert_back(std::make_unique<ValueNode>(1));
    std::vector<size_t> tmp_1{0,0};
    auto node = first_node_not_var_by_ids(var_1->node(),tmp_1.begin(),tmp_1.end()); //arr_1(initial node) -> arr_2(0) -> arr_2(0) value
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::VALUE);
    tmp_1 = {4};
    node = first_node_not_var_by_ids(var_1->node(),tmp_1.begin(),tmp_1.end()); //arr_1(initial node) -> arr_2(4) value
    EXPECT_TRUE(node);
    EXPECT_TRUE(node->type()==NODE_TYPE::VALUE);
}

TEST_F(ComplexNode_1,CompareArrays_UniversalFunction_1){
    std::vector<AbstractNode*> nodes;
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