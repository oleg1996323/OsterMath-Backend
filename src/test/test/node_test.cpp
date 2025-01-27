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
#include <vector>
#include "node_manager.h"
#include "empty_node.h"
using namespace functions::auxiliary;

TEST(Node_test,TestDefaultConstruct){
    //Node()=default;
    EmptyNode node(nullptr);
    EXPECT_TRUE(&node);
}
TEST(Node_test,TestCopyConstruct){
    /*Node(const Node& other){
        *this = other;
    }*/
    {
        std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
        VariableBase* var_tmp = bd->add_variable("tmp");
        VariableBase* var_A = bd->add_variable("A");
        VariableBase* var_B = bd->add_variable("B");
        ArrayNode* tmp_node_1_ptr = nullptr;
        std::vector<Value_t> values_1;
        std::vector<Value_t> values_2;
        ArrayNode* node_1_ptr = var_A->node()->insert_back<ArrayNode>(10);
        ArrayNode* node_2_ptr;
        {
            node_2_ptr = var_B->node()->insert_back<ArrayNode>(10);
            for(int i=0;i<10;++i){
                if(i<9){
                    values_1.emplace_back(i+10);
                    node_1_ptr->insert_back<ValueNode>(values_1.back());
                }
                values_2.emplace_back(i);
                node_2_ptr->insert_back<ValueNode>(values_2.back());
            }
            tmp_node_1_ptr = var_tmp->node()->insert_back<ArrayNode>(*node_1_ptr);
            node_2_ptr->copy_paste(node_1_ptr);
        }

        EXPECT_TRUE(node_1_ptr);
        for(size_t i=0;i<values_2.size();++i){
            EXPECT_TRUE(node_1_ptr->has_child(i));
            if(node_1_ptr->has_child(i)){
                EXPECT_EQ(node_1_ptr->child(i)->cached_result(),values_2.at(i));
                if(i<9){
                    EXPECT_NE(node_1_ptr->child(i)->cached_result(),values_1.at(i));
                }
                std::cout<<node_1_ptr->child(i)->cached_result()<<std::endl;
            }
        }
        EXPECT_EQ(node_1_ptr->references().size(),0);
        EXPECT_EQ(node_1_ptr->childs().size(),values_2.size());
        EXPECT_EQ(tmp_node_1_ptr->references().size(),0);
        EXPECT_TRUE(tmp_node_1_ptr->has_owner());
        //EXPECT_EQ(tmp_node_1->references().begin()->first,bd->get("A")->node().get());
        EXPECT_EQ(var_A->node()->child(0),node_1_ptr);
        EXPECT_EQ(var_tmp->node()->child(0),tmp_node_1_ptr);
    }
}
TEST(Node_test,TestGetTypeVal){
    //virtual TYPE_VAL type_val() const;
    EmptyNode node;
    EXPECT_EQ(node.type_val(),TYPE_VAL::UNKNOWN);
}
#include "unary_node.h"
#include "core/settings.h"
TEST(NodeTest,TestChildInfoByIndexesConst){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
    auto A = bd->add_variable("A");
    auto B = bd->add_variable("B");
    auto C = bd->add_variable("C");
    auto D = bd->add_variable("D");
    auto E = bd->add_variable("E");
    auto F = bd->add_variable("F");
    ArrayNode* array_1 = B->node()->insert_back<ArrayNode>(3);
    INFO_NODE info;
    D->node()->insert_back_ref(C->node());
    C->node()->insert_back_ref(A->node());

    A->node()->insert_back<ValueNode>(3);

    array_1->insert_back_ref(D->node());
    BinaryNode* add = E->node()->insert_back<BinaryNode>(BINARY_OP::ADD);
    UnaryNode* un_minus = F->node()->insert_back<UnaryNode>(UNARY_OP::SUB);
    add->insert_back<ValueNode>(1);
    ValueNode* value_2 = add->insert_back<ValueNode>(2);
    array_1->insert_back_ref(E->node());

    un_minus->insert_back_ref(value_2);
    array_1->insert_back_ref(F->node());

    std::vector<int> indexes{0};
    assert(array_1->childs().size()==3);
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(info.node()->type(),NODE_TYPE::REF);
    EXPECT_EQ(info.node(),B->node()->child(0)->child<ReferenceNode>(0));
    EXPECT_EQ(info.node()->child<VariableNode>(0),D->node());
    indexes = {0,0};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_FALSE(info.has_node());

    indexes = {0,1};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_FALSE(info.has_node());

    indexes = {1};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(info.node()->type(),NODE_TYPE::REF);
    EXPECT_EQ(info.node()->child<VariableNode>(0),E->node());

    indexes = {2};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(B->node()->child(0)->child(2),info.node());
    EXPECT_EQ(F->node(),info.node()->child<VariableNode>(0));
}
TEST(NodeTest,TestChildInfoByIndexesConst_2){
    const int array_sz = 3;
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
    auto A = bd->add_variable("A");
    auto B = bd->add_variable("B");
    ArrayNode* array_1 = A->node()->insert_back<ArrayNode>(array_sz);
    ArrayNode* array_2 = B->node()->insert_back<ArrayNode>(array_sz);
    for(int i=0;i<array_sz;++i){
        ArrayNode* arr_tmp = array_2->insert_back<ArrayNode>(array_sz);
        array_1->insert_back_ref(arr_tmp);
        for(int j=0;j<array_sz;++j)
            arr_tmp->insert_back<ValueNode>(j);
    }
    INFO_NODE info;

    std::vector<int> indexes{0};
    assert(array_1->childs().size()==array_sz);
    info = A->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(info.node()->type(),NODE_TYPE::REF);
    EXPECT_EQ(info.node()->child(0),array_2->child<ArrayNode>(0));
    indexes = {0,0};
    info = A->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(info.node()->type(),NODE_TYPE::VALUE);
    EXPECT_EQ(info.node(),array_1->child<ReferenceNode>(0)->child<ArrayNode>(0)->child<ValueNode>(0));
    indexes = {0,0};
    INFO_NODE info_1 = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info_1.has_node());
    EXPECT_EQ(info_1.node()->type(),NODE_TYPE::VALUE);
    EXPECT_EQ(info_1.node(),array_2->child(0)->child<ValueNode>(0));
}
TEST(NodeTest,TestReleaseChilds){
    //void release_childs();
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
    auto root_ = bd->add_variable("root");
    VariableBase* var_A = bd->add_variable("A");
    VariableBase* var_B = bd->add_variable("B");
    VariableBase* var_C = bd->add_variable("C");
    VariableBase* var_D = bd->add_variable("D");
    VariableBase* var_E = bd->add_variable("E");
    VariableBase* var_F = bd->add_variable("F");

    ArrayNode* array = root_->node()->insert_back<ArrayNode>(7);
    array->insert_back_ref(var_A->node());
    array->insert_back_ref(var_B->node());
    array->insert_back_ref(var_C->node());
    array->insert_back_ref(var_D->node());
    array->insert_back_ref(var_E->node());
    var_E->node()->insert_back_ref(var_F->node());
    ValueNode* value_1 = var_F->node()->insert_back<ValueNode>(1);
    ValueNode* value_2 = array->insert_back<ValueNode>(2);
    ValueNode* value_3 = array->insert_back<ValueNode>(3);
    EXPECT_TRUE(var_A->node()->is_refered_by(array));
    EXPECT_TRUE(var_B->node()->is_refered_by(array));
    EXPECT_TRUE(var_C->node()->is_refered_by(array));
    EXPECT_TRUE(var_D->node()->is_refered_by(array));
    EXPECT_TRUE(var_E->node()->is_refered_by(array));
    EXPECT_TRUE(var_F->node()->is_refered_by(var_E->node()));
    EXPECT_TRUE(value_1->owner() == var_F->node());
    EXPECT_TRUE(value_2->owner() == array);
    EXPECT_TRUE(value_3->owner() == array);
    EXPECT_EQ(array->size(),7);
    array->relation_manager()->release_childs(array);
    EXPECT_EQ(array->size(),0);
    EXPECT_FALSE(var_A->node()->is_refered_by(array));
    EXPECT_FALSE(var_B->node()->is_refered_by(array));
    EXPECT_FALSE(var_C->node()->is_refered_by(array));
    EXPECT_FALSE(var_D->node()->is_refered_by(array));
    EXPECT_FALSE(var_E->node()->is_refered_by(array));
    EXPECT_TRUE(var_F->node()->is_refered_by(var_E->node()));
    EXPECT_FALSE(array->has_childs());
}
TEST(NodeTest,TestEraseChilds){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    B->node()->insert_back<ValueNode>(10);
    ArrayNode* arr = A->node()->insert_back<ArrayNode>(20);
    for(int i = 0;i<20;++i){
        if(i==10)
            arr->insert_back_ref(B->node());
        else
            arr->insert_back<ValueNode>(i);
    }
    EXPECT_TRUE(arr->has_childs());
    EXPECT_EQ(arr->childs().size(),20);
    EXPECT_EQ(arr->relation_manager()->nodes().size(),22);
    EXPECT_EQ(B->node()->references().size(),1);
    arr->erase_childs(5,10);
    EXPECT_TRUE(arr->has_childs());
    EXPECT_EQ(arr->childs().size(),15);
    EXPECT_EQ(arr->relation_manager()->nodes().size(),17);
    EXPECT_EQ(B->node()->references().size(),1);
    arr->erase_childs(5,6);
    EXPECT_TRUE(arr->has_childs());
    EXPECT_EQ(arr->childs().size(),14);
    EXPECT_EQ(arr->relation_manager()->nodes().size(),16);
    EXPECT_EQ(B->node()->references().size(),0);
}
TEST(NodeTest,TestInsert_at_end){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
    }
    size_t nodes_before = bd->relation_manager()->nodes().size();
    for(int i=9;i>=0;--i){
        arr_1->insert<ValueNode>(arr_1->size(),i);
    }
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after-10);
    EXPECT_EQ(arr_1->child(0)->execute(),arr_1->child(arr_1->size()-1)->execute());
    EXPECT_EQ(arr_1->childs().size(),20);
    for(int i=10;i<20;++i)
        EXPECT_EQ(arr_1->child(i)->owner().parent,arr_1);
    arr_1->print_text(std::cout);
}
TEST(NodeTest,TestInsert_1){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
    }
    size_t nodes_before = bd->relation_manager()->nodes().size();
    for(int i=9;i>=0;--i){
        arr_1->insert<ValueNode>(arr_1->size()/2,i);
    }
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after-10);
    EXPECT_EQ(arr_1->childs().size(),20);
    for(int i=10;i<20;++i)
        EXPECT_EQ(arr_1->child(i)->owner().parent,arr_1);
    arr_1->print_text(std::cout);
}
TEST(NodeTest,TestInsert_move_1){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    size_t nodes_before = bd->relation_manager()->nodes().size();
    insert_move(arr_1,5,arr_2->child(9));
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after);
    EXPECT_EQ(arr_1->child(5)->execute(),9);
    EXPECT_EQ(arr_2->childs().size(),9);
    EXPECT_EQ(arr_1->childs().size(),11);
}
TEST(NodeTest,TestInsert_move_2){
    std::shared_ptr<BaseData> bd_A = std::make_shared<BaseData>("A");
    std::shared_ptr<BaseData> bd_B = std::make_shared<BaseData>("B");
    VariableBase* A = bd_A->add_variable("A");
    VariableBase* B = bd_B->add_variable("B");
    VariableBase* C = bd_B->add_variable("C");
    C->node()->insert_back_ref(B->node());
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        if(i!=9)
            arr_2->insert_back<ValueNode>(i);
        else arr_2->insert_back_ref(C->node());
    }
    size_t nodes_before = bd_A->relation_manager()->nodes().size()+bd_B->relation_manager()->nodes().size();
    insert_move(arr_1,5,arr_2->child(9));
    size_t nodes_after = bd_A->relation_manager()->nodes().size()+bd_B->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after);
    EXPECT_EQ(arr_1->child(5)->execute(),C->node()->execute());
    EXPECT_EQ(arr_1->child(5)->type(),NODE_TYPE::REF);
    EXPECT_EQ(arr_2->childs().size(),9);
    EXPECT_EQ(arr_1->childs().size(),11);
}
TEST(NodeTest,TestInsert_copy_1){
        std::shared_ptr<BaseData> bd_A = std::make_shared<BaseData>("A");
    std::shared_ptr<BaseData> bd_B = std::make_shared<BaseData>("B");
    VariableBase* A = bd_A->add_variable("A");
    VariableBase* B = bd_B->add_variable("B");
    VariableBase* C = bd_B->add_variable("C");
    C->node()->insert_back_ref(B->node());
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        if(i!=9)
            arr_2->insert_back<ValueNode>(i);
        else arr_2->insert_back_ref(C->node());
    }
    size_t nodes_before = bd_A->relation_manager()->nodes().size()+bd_B->relation_manager()->nodes().size();
    insert_copy(arr_1,5,arr_2->child(9));
    size_t nodes_after = bd_A->relation_manager()->nodes().size()+bd_B->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after);
    EXPECT_EQ(arr_1->child(5)->execute(),C->node()->execute());
    EXPECT_EQ(arr_1->child(5)->type(),NODE_TYPE::REF);
    EXPECT_EQ(arr_2->childs().size(),10);
    EXPECT_EQ(arr_1->childs().size(),11);
}
TEST(NodeTest,TestInsert_copy_2){
    
}
TEST(NodeTest,TestReplace_move_1){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    size_t nodes_before = bd->relation_manager()->nodes().size();
    replace_move(arr_1,5,arr_2->child(9));
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after+1); // 1 ValueNode is deleted (replaced by another)
    EXPECT_EQ(arr_1->child(5)->execute(),9);
    EXPECT_EQ(arr_2->childs().size(),9);
    EXPECT_EQ(arr_1->childs().size(),10);
}
TEST(NodeTest,TestReplace_move_2){
    
}
TEST(NodeTest,TestReplace_copy_1){
    
}
TEST(NodeTest,TestReplace_copy_2){
    
}
TEST(NodeTest,TestInsert_ref){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    VariableBase* C = bd->add_variable("C");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
    }
    size_t nodes_before = bd->relation_manager()->nodes().size();
    arr_1->insert_ref(5,B->node());
    arr_1->insert_ref(5,C->node());
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after-2);
    EXPECT_EQ(arr_1->child<ReferenceNode>(5)->child(0),C->node());
    EXPECT_EQ(arr_1->child<ReferenceNode>(6)->child(0),B->node());
    EXPECT_EQ(arr_1->childs().size(),12);
    for(int i=0;i<12;++i)
        EXPECT_EQ(arr_1->child(i)->owner().parent,arr_1);
    arr_1->print_text(std::cout);
}
TEST(NodeTest,TestInsert_back_ref_cyclic){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    VariableBase* C = bd->add_variable("C");
    size_t nodes_before = bd->relation_manager()->nodes().size();
    A->node()->insert_back_ref(B->node());
    B->node()->insert_back_ref(C->node());
    C->node()->insert_back_ref(A->node());
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before,nodes_after-3);
    EXPECT_EQ(A->node()->child<ReferenceNode>(0)->child(0),B->node());
    EXPECT_EQ(B->node()->child<ReferenceNode>(0)->child(0),C->node());
    EXPECT_EQ(C->node()->child<ReferenceNode>(0)->child(0),A->node());
    EXPECT_FALSE(A->node()->is_not_cycled());
    EXPECT_FALSE(B->node()->is_not_cycled());
    EXPECT_FALSE(C->node()->is_not_cycled());
}
TEST(NodeTest,TestInsert_back_move_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    insert_back_move(arr_1,arr_2->begin(),arr_2->end());
    EXPECT_TRUE(arr_2);
    EXPECT_EQ(arr_2->childs().size(),0);
}
TEST(NodeTest,TestInsert_back_copy_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    insert_back_copy(arr_1,arr_2->begin(),arr_2->end());
}
TEST(NodeTest,TestInsert_move_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    insert_move(arr_1,5, arr_2->begin(),arr_2->end());
}
TEST(NodeTest,TestInsert_copy_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    insert_copy(arr_1,5, arr_2->begin(),arr_2->end());
}
TEST(NodeTest,TestReplace_move_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    std::vector<Result> arr_1_res;
    std::vector<Result> arr_2_res;
    for(int i=0;i<10;++i){
        auto val_1 = arr_1->insert_back<ValueNode>(i);
        arr_1_res.push_back(val_1->execute());
        auto val_2 = arr_2->insert_back<ValueNode>(i);
        arr_2_res.push_back(val_2->execute());
    }
    const size_t id_at = 5;
    size_t nodes_before = bd->relation_manager()->nodes().size();
    size_t arr_1_sz_before = arr_1->size();
    replace_move(arr_1,id_at, arr_2->begin(),arr_2->end());
    EXPECT_EQ(arr_1->childs().size(),nodes_before-bd->variables().size()-(arr_1_sz_before-id_at));
    for(size_t i=0;i<nodes_before-bd->variables().size()-(arr_1_sz_before-id_at);++i){
        if(i<id_at)
            EXPECT_EQ(arr_1->child(i)->execute(),arr_1_res.at(i));
        else EXPECT_EQ(arr_1->child(i)->execute(),arr_2_res.at(i-id_at));
        arr_1->print_result(std::cout);
        std::cout<<std::endl;
    }
    EXPECT_FALSE(arr_2->has_childs());
    size_t nodes_after = bd->relation_manager()->nodes().size();
    EXPECT_EQ(nodes_before-5,nodes_after);
}
TEST(NodeTest,TestReplace_copy_range){
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("any");
    VariableBase* A = bd->add_variable("A");
    VariableBase* B = bd->add_variable("B");
    ArrayNode* arr_1 = A->node()->insert_back<ArrayNode>(10);
    ArrayNode* arr_2 = B->node()->insert_back<ArrayNode>(10);
    for(int i=0;i<10;++i){
        arr_1->insert_back<ValueNode>(i);
        arr_2->insert_back<ValueNode>(i);
    }
    replace_copy(arr_1,5,arr_2->begin(),arr_2->end());
}