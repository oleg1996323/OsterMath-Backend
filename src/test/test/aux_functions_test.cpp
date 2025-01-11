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
        auto var_1_base = bd->add_variable("Var_1");
        auto var_2_base = bd->add_variable("Var_2");
        auto var_3_base = bd->add_variable("Var_3");
        std::unique_ptr<ArrayNode> arr_1 = std::make_unique<ArrayNode>(5);
        std::unique_ptr<ArrayNode> arr_2 = std::make_unique<ArrayNode>(5);
        VariableNode* var_1 = var_1_base->node();
        VariableNode* var_2 = var_2_base->node();
        VariableNode* var_3 = var_3_base->node();
        EXPECT_FALSE(first_node_not_var(var_1));
        var_1->insert_back(std::move(arr_1));
        arr_1->insert_back_ref(var_2);
        var_2->insert_back(std::move(arr_2));
        arr_2->insert_back_ref(var_3);
        var_3->insert_back(std::make_unique<ValueNode>(1));
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
        bd = std::make_shared<BaseData>("bd");
        auto root_1 = bd->add_variable("root_1");
        auto root_2 = bd->add_variable("root_2");
        auto var_1 = bd->add_variable("var_1");
        auto var_2 = bd->add_variable("var_2");
        auto var_3 = bd->add_variable("var_3");
        node_2_ = static_cast<ArrayNode*>(root_1->node()->insert_back(std::move(std::make_unique<ArrayNode>(5))));
        node_2_with_vars_ = static_cast<ArrayNode*>(root_2->node()->insert_back(std::move(std::make_unique<ArrayNode>(5))));
        ArrayNode* subarr_1;
        ArrayNode* subarr_2;
        ArrayNode* subarr_10;
        ArrayNode* subarr_20;
        ArrayNode* subarr_11;
        ArrayNode* subarr_21;
        ArrayNode* subarr_114;
        ArrayNode* subarr_214;
        for(int i=0;i<5;++i){
            if(i!=4){
                subarr_11->insert_back(std::make_unique<ValueNode>(i));
                subarr_21->insert_back(std::make_unique<ValueNode>(i));
            }
            else{
                if(!subarr_114)
                    subarr_114 = static_cast<ArrayNode*>(subarr_11->insert_back(std::make_unique<ArrayNode>(5)));
                else subarr_11->insert_back_ref(subarr_114);
                subarr_21->insert_back_ref(var_3->node());
                if(!subarr_214)
                    subarr_214 = static_cast<ArrayNode*>(var_3->node()->insert_back(std::make_unique<ArrayNode>(5)));
                else var_3->node()->insert_back_ref(subarr_214);
            }
            if(i!=1 && i!=0){
                node_2_->insert_back(std::make_unique<ValueNode>(i));
                node_2_with_vars_->insert_back(std::make_unique<ValueNode>(i));
                subarr_1->insert_back(std::make_unique<ValueNode>(i));
                subarr_2->insert_back(std::make_unique<ValueNode>(i));
            }
            else if(i==1){
                subarr_1 = static_cast<ArrayNode*>(node_2_->insert_back(std::make_unique<ArrayNode>(5)));
                node_2_with_vars_->insert_back_ref(var_1->node());
                var_1->node()->insert_back_ref(subarr_2);
                subarr_1->insert_back_ref(subarr_11);
                subarr_2->insert_back_ref(var_2->node());
                var_2->node()->insert_back_ref(subarr_21);
            }
            else{
                if(!subarr_10)
                    subarr_10 = static_cast<ArrayNode*>(subarr_1->insert_back(std::make_unique<ArrayNode>(5)));
                else subarr_1->insert_back_ref(subarr_10);
                if(subarr_20)
                    subarr_20 = static_cast<ArrayNode*>(subarr_2->insert_back(std::make_unique<ArrayNode>(5)));
                else subarr_2->insert_back_ref(subarr_20);
            }
            subarr_114->insert_back(std::make_unique<ValueNode>(i));
            auto bin_node = std::make_unique<BinaryNode>(BINARY_OP::ADD);
            bin_node->insert_back(std::make_unique<ValueNode>(i));
            bin_node->insert_back(std::make_unique<ValueNode>(i));
            subarr_214->insert_back(std::move(bin_node));
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
    AbstractNode* node_2_;
    AbstractNode* node_2_with_vars_;
    std::shared_ptr<BaseData> bd;
};

class Initial_Rect_ArrayNode{

public:

    Initial_Rect_ArrayNode(){
        bd = std::make_shared<BaseData>("bd_3");
        auto var_rect_node = bd->add_variable("rect");
        auto var_not_rect_node = bd->add_variable("not rect");
        auto var_1 = bd->add_variable("var_1");
        auto var_2 = bd->add_variable("var_2");
        auto var_3 = bd->add_variable("var_3");
        rect_node = var_rect_node->node()->insert_back(bd->make_node<ArrayNode>(5));
        not_rect_node = var_not_rect_node->node()->insert_back(bd->make_node<ArrayNode>(5));
        ArrayNode* rect_node_1;
        ArrayNode* not_rect_node_1;
        ArrayNode* rect_node_10;
        ArrayNode* not_rect_node_10;
        for(int i=0;i<5;++i){
            if(i!=2){
                rect_node->insert_back_ref(var_1->node());
                if(!rect_node_1)
                    rect_node_1 = static_cast<ArrayNode*>(var_1->node()->insert_back(bd->make_node<ArrayNode>(5)));
                else var_1->node()->insert_back_ref(rect_node_1);
            }
            not_rect_node->insert_back(bd->make_node<ArrayNode>(5));
            if(i==0)
                not_rect_node_10 = static_cast<ArrayNode*>(not_rect_node_1->insert_back(bd->make_node<ArrayNode>(5)));
            else not_rect_node_1->insert_back(bd->make_node<ValueNode>(i));
            not_rect_node_10->insert_back(bd->make_node<ValueNode>(i));

            if(!rect_node_10)
                rect_node_10 = static_cast<ArrayNode*>(rect_node_1->insert_back(bd->make_node<ArrayNode>(5)));
            else 
                rect_node_1->insert_back_ref(rect_node_10);

            rect_node_10->insert_back(bd->make_node<ValueNode>(i));
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