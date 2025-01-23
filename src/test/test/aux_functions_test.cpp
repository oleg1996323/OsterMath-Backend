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
        VariableNode* var_1 = var_1_base->node();
        VariableNode* var_2 = var_2_base->node();
        VariableNode* var_3 = var_3_base->node();
        EXPECT_FALSE(first_node_not_var(var_1));
        ArrayNode* arr_1 = var_1->insert_back<ArrayNode>(5);
        arr_1->insert_back_ref(var_2);
        ArrayNode* arr_2 = var_2->insert_back<ArrayNode>(5);
        arr_2->insert_back_ref(var_3);
        var_3->insert_back<ValueNode>(1);
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
        arr = root_1->node()->insert_back<ArrayNode>(5);
        arr_with_vars_ = root_2->node()->insert_back<ArrayNode>(5);
        ArrayNode* subarr_1 = nullptr;
        ArrayNode* subarr_2 = nullptr;
        ArrayNode* subarr_10 = nullptr;
        ArrayNode* subarr_20 = nullptr;
        ArrayNode* subarr_11 = nullptr;
        ArrayNode* subarr_21 = nullptr;
        ArrayNode* subarr_114 = nullptr;
        ArrayNode* subarr_214 = nullptr;

        for(int i=0;i<5;++i){
            if(i!=1 && i!=0){
                arr->insert_back<ValueNode>(i);
                arr_with_vars_->insert_back<ValueNode>(i);
                subarr_1->insert_back<ValueNode>(i);
                subarr_2->insert_back<ValueNode>(i);
            }
            else if(i==1){
                if(!subarr_1)
                    subarr_1 = arr->insert_back<ArrayNode>(5);
                else arr->insert_back_ref(subarr_1);
                arr_with_vars_->insert_back_ref(var_1->node());
                if(!subarr_2)
                    subarr_2 = var_1->node()->insert_back<ArrayNode>(5);
                else var_1->node()->insert_back_ref(subarr_2);
            }
        }

        for(int i=0;i<5;++i){
            if(i==0){
                if(!subarr_10)
                    subarr_10 = subarr_1->insert_back<ArrayNode>(5);
                else subarr_1->insert_back_ref(subarr_10);
                if(!subarr_20)
                    subarr_20 = subarr_2->insert_back<ArrayNode>(5);
                else subarr_2->insert_back_ref(subarr_20);
            }
            if(i==1){
                if(!subarr_11)
                    subarr_11 = subarr_1->insert_back<ArrayNode>(5);
                else subarr_1->insert_back_ref(subarr_11);
                subarr_2->insert_back_ref(var_2->node());
                if(!subarr_21)
                    subarr_21 = var_2->node()->insert_back<ArrayNode>(5);
                else var_2->node()->insert_back_ref(subarr_21);
            }
        }

        for(int i=0;i<5;++i){
            if(i!=4){
                subarr_11->insert_back<ValueNode>(i);
                subarr_21->insert_back<ValueNode>(i);
            }
            else{
                if(!subarr_114)
                    subarr_114 = subarr_11->insert_back<ArrayNode>(5);
                else
                    subarr_11->insert_back_ref(subarr_114);
                subarr_21->insert_back_ref(var_3->node());
                if(!subarr_214)
                    subarr_214 = var_3->node()->insert_back<ArrayNode>(5);
                else var_3->node()->insert_back_ref(subarr_214);
            }
        }

        for(int i=0;i<5;++i){            
            subarr_114->insert_back<ValueNode>(i);
            BinaryNode* bin_node = subarr_214->insert_back<BinaryNode>(BINARY_OP::ADD);
            bin_node->insert_back<ValueNode>(i);
            bin_node->insert_back<ValueNode>(i);

        }
    }

    AbstractNode* node_2(){
        return arr;
    }

    AbstractNode* node_2_with_vars(){
        return arr_with_vars_;
    }

    ~Initial_Complex_Node_2(){
        
    }

private:
    ArrayNode* arr;
    ArrayNode* arr_with_vars_;
    std::shared_ptr<BaseData> bd_1;
    std::shared_ptr<BaseData> bd_2;
};

class Initial_Rect_ArrayNode_1{

public:

    Initial_Rect_ArrayNode_1(){
        bd = std::make_shared<BaseData>("bd_3");
        auto var_rect_node = bd->add_variable("rect");
        auto var_not_rect_node = bd->add_variable("not rect");
        auto var_1 = bd->add_variable("var_1_case_3");
        rect_node = var_rect_node->node()->insert_back<ArrayNode>(5);
        not_rect_node = var_not_rect_node->node()->insert_back<ArrayNode>(5);
        ArrayNode* rect_node_1 = nullptr;
        ArrayNode* not_rect_node_1 = nullptr;
        ArrayNode* rect_node_10 = nullptr;
        ArrayNode* not_rect_node_10 = nullptr;
        for(int i=0;i<5;++i){
            if(i!=2){
                rect_node->insert_back_ref(var_1->node());
                if(!rect_node_1)
                    rect_node_1 = var_1->node()->insert_back<ArrayNode>(5);
            }
            if(!not_rect_node_1)
                not_rect_node_1 = not_rect_node->insert_back<ArrayNode>(5);
            else
                not_rect_node->insert_back_ref(not_rect_node_1); //
            if(i==0){
                if(!not_rect_node_10)
                    not_rect_node_10 = not_rect_node_1->insert_back<ArrayNode>(5);
                else not_rect_node_1->insert_back_ref(not_rect_node_10);
            }
            else not_rect_node_1->insert_back<ValueNode>(i);
            not_rect_node_10->insert_back<ValueNode>(i);

            if(!rect_node_10)
                rect_node_10 = rect_node_1->insert_back<ArrayNode>(5);
            else 
                rect_node_1->insert_back_ref(rect_node_10);

            rect_node_10->insert_back<ValueNode>(i);
        }
    }

    AbstractNode* rect_array(){
        return rect_node;
    }

    AbstractNode* not_rect_array(){
        return not_rect_node;
    }

private:
    AbstractNode* rect_node = nullptr;
    AbstractNode* not_rect_node = nullptr;
    std::shared_ptr<BaseData> bd;
};

class Initial_Rect_ArrayNode_2{

public:

    Initial_Rect_ArrayNode_2(){
        const int nodes = 3;
        const int at_exclude = 2;
        bd = std::make_shared<BaseData>("bd_3");
        auto var_rect_node = bd->add_variable("rect");
        auto var_not_rect_node = bd->add_variable("not rect");
        rect_node = var_rect_node->node()->insert_back<ArrayNode>(nodes);
        not_rect_node = var_not_rect_node->node()->insert_back<ArrayNode>(nodes);
        for(int i=0;i<nodes;++i){
            ArrayNode* rect_arr_1 = rect_node->insert_back<ArrayNode>(nodes);
            ArrayNode* not_rect_arr_2 = not_rect_node->insert_back<ArrayNode>(nodes);
            for(int j=0;j<nodes;++j){
                ArrayNode* not_rect_arr_22 = not_rect_arr_2->insert_back<ArrayNode>(nodes);
                ArrayNode* rect_arr_11 = rect_arr_1->insert_back<ArrayNode>(nodes);
                for(int k=0;k<nodes;++k){
                    ArrayNode* not_rect_arr_222;
                    if(k==at_exclude)
                        not_rect_arr_222 = not_rect_arr_22->insert_back<ArrayNode>(at_exclude);
                    else not_rect_arr_222 = not_rect_arr_22->insert_back<ArrayNode>(nodes);
                    ArrayNode* rect_arr_111 = rect_arr_11->insert_back<ArrayNode>(nodes);
                    for(int m=0;m<nodes;++m){
                        if(k==at_exclude){
                            if(m<at_exclude)
                                not_rect_arr_222->insert_back<ValueNode>(m);
                        }
                        else
                            not_rect_arr_222->insert_back<ValueNode>(m);
                        rect_arr_111->insert_back<ValueNode>(m);
                    }
                }
            }
        }
    }

    AbstractNode* rect_array(){
        return rect_node;
    }

    AbstractNode* not_rect_array(){
        return not_rect_node;
    }

private:
    AbstractNode* rect_node = nullptr;
    AbstractNode* not_rect_node = nullptr;
    std::shared_ptr<BaseData> bd;
};

class Initial_Rect_ArrayNode_3{

public:

    Initial_Rect_ArrayNode_3(){
        const int nodes = 3;
        const int at_exclude = 2;
        bd = std::make_shared<BaseData>("bd_3");
        auto var_rect_node = bd->add_variable("rect");
        auto var_not_rect_node = bd->add_variable("not rect");
        rect_node = var_rect_node->node()->insert_back<ArrayNode>(nodes);
        not_rect_node = var_not_rect_node->node()->insert_back<ArrayNode>(nodes);
        for(int i=0;i<nodes;++i){
            ArrayNode* rect_arr_1 = rect_node->insert_back<ArrayNode>(nodes);
            ArrayNode* not_rect_arr_2 = not_rect_node->insert_back<ArrayNode>(nodes);
            for(int j=0;j<nodes;++j){
                
                ArrayNode* not_rect_arr_22;
                FunctionNode* func_n;
                ArrayNode* rect_arr_11 = rect_arr_1->insert_back<ArrayNode>(nodes);
                if(j==at_exclude){
                    func_n = not_rect_arr_2->insert_back<FunctionNode>(FUNCTION_OP::SUM);
                }
                else{
                    not_rect_arr_22 = not_rect_arr_2->insert_back<ArrayNode>(nodes);
                }
                for(int k=0;k<nodes;++k){
                    ArrayNode* not_rect_arr_222;
                    if(j==at_exclude)
                        not_rect_arr_222 = func_n->insert_back<ArrayNode>(nodes);
                    else not_rect_arr_222 = not_rect_arr_22->insert_back<ArrayNode>(nodes);
                    ArrayNode* rect_arr_111 = rect_arr_11->insert_back<ArrayNode>(nodes);
                    for(int m=0;m<nodes;++m){
                        not_rect_arr_222->insert_back<ValueNode>(m);
                        rect_arr_111->insert_back<ValueNode>(m);
                    }
                }
            }
        }
    }

    AbstractNode* rect_array(){
        return rect_node;
    }

    AbstractNode* not_rect_array(){
        return not_rect_node;
    }

private:
    AbstractNode* rect_node = nullptr;
    AbstractNode* not_rect_node = nullptr;
    std::shared_ptr<BaseData> bd;
};

class Initial_Filled_ArrayNode{

public:

    Initial_Filled_ArrayNode(){
        const int nodes = 3;
        const int at_exclude = 2;
        bd = std::make_shared<BaseData>("bd_3");
        auto var_filled_array_node = bd->add_variable("rect");
        auto var_not_filled_array_node = bd->add_variable("not rect");
        filled_array_node = var_filled_array_node->node()->insert_back<ArrayNode>(nodes);
        not_filled_array_node = var_not_filled_array_node->node()->insert_back<ArrayNode>(nodes);
        for(int i=0;i<nodes;++i){
            ArrayNode* rect_arr_1 = filled_array_node->insert_back<ArrayNode>(nodes);
            ArrayNode* not_rect_arr_2 = not_filled_array_node->insert_back<ArrayNode>(nodes);
            for(int j=0;j<nodes;++j){
                ArrayNode* not_rect_arr_22 = not_rect_arr_2->insert_back<ArrayNode>(nodes);
                ArrayNode* rect_arr_11 = rect_arr_1->insert_back<ArrayNode>(nodes);
                for(int k=0;k<nodes;++k){
                    ArrayNode* not_rect_arr_222;
                    if(k==at_exclude)
                        not_rect_arr_222 = not_rect_arr_22->insert_back<ArrayNode>(2);
                    else not_rect_arr_222 = not_rect_arr_22->insert_back<ArrayNode>(nodes);
                    ArrayNode* rect_arr_111 = rect_arr_11->insert_back<ArrayNode>(nodes);
                    for(int m=0;m<nodes;++m){
                        if(k==at_exclude){}
                        else
                            not_rect_arr_222->insert_back<ValueNode>(m);
                        rect_arr_111->insert_back<ValueNode>(m);
                    }
                }
            }
        }
    }

    AbstractNode* filled_array(){
        return filled_array_node;
    }

    AbstractNode* not_filled_array(){
        return not_filled_array_node;
    }

private:
    AbstractNode* filled_array_node = nullptr;
    AbstractNode* not_filled_array_node = nullptr;
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
};

class RectNode_1: public ::testing::Test
{
protected:
    void SetUp()
	{	}
	void TearDown()
	{	}
    Initial_Rect_ArrayNode_1 fixture_;
};

class RectNode_2: public ::testing::Test
{
protected:
    void SetUp()
	{	}
	void TearDown()
	{	}
    Initial_Rect_ArrayNode_2 fixture_;
};

class RectNode_3: public ::testing::Test
{
protected:
    void SetUp()
	{	}
	void TearDown()
	{	}
    Initial_Rect_ArrayNode_3 fixture_;
};

class FilledArrayNode: public ::testing::Test
{
protected:
    void SetUp()
	{	}
	void TearDown()
	{	}
    Initial_Filled_ArrayNode fixture_;
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
    ArrayNode* arr_1 = var_1->node()->insert_back<ArrayNode>(5);
    arr_1->insert_back_ref(var_2->node());
    for(int i = 0;i<4;++i){
        arr_1->insert_back<ValueNode>(i);
    }
    ArrayNode* arr_2 = var_2->node()->insert_back<ArrayNode>(5);
    arr_2->insert_back_ref(var_3->node());
    for(int i = 0;i<4;++i){
        arr_2->insert_back<ValueNode>(i);
    }
    var_3->node()->insert_back<ValueNode>(1);
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

TEST_F(RectNode_1,IsRectNodeMorphology_1){
    EXPECT_TRUE(is_rectangle_array_node(fixture_.rect_array()));
    EXPECT_FALSE(is_rectangle_array_node(fixture_.not_rect_array()));
}

TEST_F(RectNode_2,IsRectNodeMorphology_2){
    EXPECT_TRUE(is_rectangle_array_node(fixture_.rect_array()));
    EXPECT_FALSE(is_rectangle_array_node(fixture_.not_rect_array()));
}

TEST_F(RectNode_3,IsRectNodeMorphology_3){
    EXPECT_TRUE(is_rectangle_array_node(fixture_.rect_array()));
    EXPECT_FALSE(is_rectangle_array_node(fixture_.not_rect_array()));
}

TEST_F(FilledArrayNode,IsFilledArrayNode_1){
    EXPECT_TRUE(is_filled_array_node(fixture_.filled_array()));
    fixture_.filled_array()->print_text(std::cout);
    std::cout<<std::endl;
    EXPECT_FALSE(is_filled_array_node(fixture_.not_filled_array()));
    fixture_.not_filled_array()->print_text(std::cout);
    std::cout<<std::endl;
}