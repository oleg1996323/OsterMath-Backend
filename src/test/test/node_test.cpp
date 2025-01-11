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
    EmptyNode node;
    EXPECT_TRUE(&node);
}
TEST(Node_test,TestCopyConstruct){
    /*Node(const Node& other){
        *this = other;
    }*/
    {
        std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
        std::shared_ptr<VariableBase> var_tmp = bd->add_variable("tmp");
        std::shared_ptr<VariableBase> var_A = bd->add_variable("A");
        std::shared_ptr<VariableBase> var_B = bd->add_variable("B");
        std::unique_ptr<ArrayNode> node_1 = bd->make_node<ArrayNode>(10);
        AbstractNode* tmp_node_1_ptr;
        std::vector<ValueNode> values_1;
        std::vector<ValueNode> values_2;
        var_A->node()->insert_back(std::move(node_1));
        {
            std::unique_ptr<ArrayNode> node_2 = bd->make_node<ArrayNode>(10);
            var_B->node()->insert_back(std::move(node_2));
            for(int i=0;i<10;++i){
                if(i<9){
                    values_1.emplace_back(i+10);
                    node_1->insert_back(bd->make_node<ValueNode>(values_1.at(i)));
                }
                values_2.emplace_back(i);
                node_2->insert_back(bd->make_node<ValueNode>(values_2.at(i)));
            }
            tmp_node_1_ptr = var_tmp->node()->insert_back(std::move(std::make_unique<ArrayNode>(*node_1)));
            node_1->copy_from(node_2.get());
        }

        EXPECT_TRUE(&node_1);
        for(size_t i=0;i<values_2.size();++i){
            EXPECT_TRUE(node_1->has_child(i));
            if(node_1->has_child(i)){
                EXPECT_TRUE(node_1->child(i)->get_result()==values_2.at(i).get_result());
                if(i<9){
                    EXPECT_TRUE(node_1->child(i)->get_result()!=values_1.at(i).get_result());
                }
                std::cout<<node_1->child(i)->get_result()<<std::endl;
            }
        }
        EXPECT_EQ(node_1->references().size(),0);
        EXPECT_EQ(node_1->childs().size(),values_2.size());
        EXPECT_EQ(tmp_node_1_ptr->references().size(),1);
        //EXPECT_EQ(tmp_node_1->references().begin()->first,bd->get("A")->node().get());
        EXPECT_EQ(bd->get("A")->node()->child(0),tmp_node_1_ptr);
    }
}
TEST(Node_test,TestGetTypeVal){
    //virtual TYPE_VAL type_val() const;
    EmptyNode node;
    EXPECT_TRUE(node.type_val()==TYPE_VAL::UNKNOWN);
}
#include "unary_node.h"
#include "core/settings.h"
TEST(NodeTest,TestChildInfoByIndexesConst){
    //INFO_NODE child(const std::vector<size_t>::const_iterator& first,const std::vector<size_t>::const_iterator& last) const;
    //VAR(B)->ArrayNode{VAR(A)->ValueNode(3);1+2;-2}
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
    auto A = bd->add_variable("A");
    auto B = bd->add_variable("B");
    auto C = bd->add_variable("C");
    auto D = bd->add_variable("D");
    auto E = bd->add_variable("E");
    auto F = bd->add_variable("F");
    std::unique_ptr<ArrayNode> array_1 = std::make_unique<ArrayNode>(3);
    std::unique_ptr<ValueNode> value_1 = std::make_unique<ValueNode>(1);
    std::unique_ptr<ValueNode> value_2 = std::make_unique<ValueNode>(2);
    std::unique_ptr<ValueNode> value_3 = std::make_unique<ValueNode>(3);
    bd->get("D")->node()->insert_back_ref(bd->get("C")->node());
    bd->get("C")->node()->insert_back_ref(bd->get("A")->node());
    auto value_3_ptr = bd->get("A")->node()->insert_back(std::move(value_3));
    array_1->insert_back_ref(D->node());
    std::unique_ptr<BinaryNode> add = std::make_unique<BinaryNode>(BINARY_OP::ADD);
    add->insert_back(std::move(value_1));
    auto value_2_ptr = add->insert_back(std::move(value_2));
    array_1->insert_back_ref(E->node());
    auto add_ptr = E->node()->insert_back(std::move(add));
    std::unique_ptr<UnaryNode> un_minus = std::make_unique<UnaryNode>(UNARY_OP::SUB);
    un_minus->insert_back_ref(value_2_ptr);
    array_1->insert_back_ref(F->node());
    auto un_minus_ptr = F->node()->insert_back(std::move(un_minus));
    auto array_1_ptr = B->node()->insert_back(std::move(array_1));
    std::vector<int> indexes{0};
    assert(array_1_ptr->childs().size()==3);
    INFO_NODE info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    if(!kernel::settings::Model::show_through_var_nodes()){
        EXPECT_EQ(B->node()->child(0)->child(0),info.node());
        EXPECT_EQ(A->node(),info.node());
        EXPECT_TRUE(info.node()->type()==NODE_TYPE::VARIABLE);
    }
    else{
        EXPECT_EQ(B->node()->child(0)->child(0)->child(0)->child(0)->child(0),info.node());
        EXPECT_EQ(value_3_ptr,info.node());
        EXPECT_TRUE(info.node()->type()!=NODE_TYPE::VARIABLE);
    }

    indexes = {0,1};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_FALSE(info.has_node());

    indexes = {1};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(B->node()->child(0)->child(1)->child(0),add_ptr);
    EXPECT_EQ(B->node()->child(0)->child(1)->child(0),info.node());
    EXPECT_TRUE(info.node()->type()==NODE_TYPE::BINARY);

    indexes = {2};
    info = B->node()->child(indexes.begin(),indexes.end());
    EXPECT_TRUE(info.has_node());
    EXPECT_EQ(B->node()->child(0)->child(2)->child(0),un_minus_ptr);
    EXPECT_EQ(B->node()->child(0)->child(2)->child(0),info.node());
    EXPECT_TRUE(info.node()->type()==NODE_TYPE::UNARY);
}   
TEST(NodeTest,TestReleaseChilds){
    //void release_childs();
    std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
    std::shared_ptr<VariableBase> var_A = bd->add_variable("A");
    std::shared_ptr<VariableBase> var_B = bd->add_variable("B");
    std::shared_ptr<VariableBase> var_C = bd->add_variable("C");
    std::shared_ptr<VariableBase> var_D = bd->add_variable("D");
    std::shared_ptr<VariableBase> var_E = bd->add_variable("E");
    std::shared_ptr<VariableBase> var_F = bd->add_variable("F");
    std::unique_ptr<ValueNode> value_1 = bd->make_node<ValueNode>(1);
    std::unique_ptr<ValueNode> value_2 = bd->make_node<ValueNode>(2);
    std::unique_ptr<ValueNode> value_3 = bd->make_node<ValueNode>(3);
    std::unique_ptr<ArrayNode> array = bd->make_node<ArrayNode>(7);
    array->insert_back_ref(var_A->node());
    array->insert_back_ref(var_B->node());
    array->insert_back_ref(var_C->node());
    array->insert_back_ref(var_D->node());
    array->insert_back_ref(var_E->node());
    var_E->node()->insert_back_ref(var_F->node());
    var_F->node()->insert_back(std::move(value_1));
    array->insert_back(std::move(value_2));
    array->insert_back(std::move(value_3));
    EXPECT_TRUE(var_A->node()->owner()==array.get());
    EXPECT_TRUE(var_B->node()->owner()==array.get());
    EXPECT_TRUE(var_C->node()->owner()==array.get());
    EXPECT_TRUE(var_D->node()->owner()==array.get());
    EXPECT_TRUE(var_E->node()->owner()==array.get());
    EXPECT_TRUE(var_F->node()->owner()==var_E->node());
    EXPECT_TRUE(value_1->owner() == var_F->node());
    EXPECT_TRUE(value_2->owner() == array.get());
    EXPECT_TRUE(value_3->owner() == array.get());
    EXPECT_EQ(array->size(),7);
    array->relation_manager()->release_childs(array.get());
    EXPECT_EQ(array->size(),0);
    EXPECT_FALSE(var_A->node()->owner() == array.get());
    EXPECT_FALSE(var_B->node()->owner() == array.get());
    EXPECT_FALSE(var_C->node()->owner() == array.get());
    EXPECT_FALSE(var_D->node()->owner() == array.get());
    EXPECT_FALSE(var_E->node()->owner() == array.get());
    EXPECT_TRUE(var_F->node()->owner() == var_E->node());
    EXPECT_TRUE(value_1->owner() == var_F->node());
    EXPECT_FALSE(value_2->owner() == array.get());
    EXPECT_FALSE(value_3->owner() == array.get());
}
// TEST(NodeTest,TestNodeType){
//     //virtual NODE_TYPE type() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestExecute){
//     //virtual Result execute() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestExecuteForArrayVariables){
//     //virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestCachedResult){
//     /*inline virtual Result cached_result() const{
//         return std::monostate();
//     }*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestIsNumeric){
//     //virtual bool is_numeric() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestIsString){
//     //virtual bool is_string() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestIsArray){
//     //virtual bool is_array() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestIsEmpty){
//     //virtual bool is_empty() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestInsertBackTemplate){
//     /*template<typename T>
//     requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
//     void insert_back(T&& arg);*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestInsertBack){
//     //virtual void insert_back(std::shared_ptr<Node>);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestInsert){
//     //virtual std::shared_ptr<Node> insert(size_t,std::shared_ptr<Node>);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReplace){
//     //virtual std::shared_ptr<Node> replace(size_t,std::shared_ptr<Node>);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestPrintText){
//     //virtual void print_text(std::ostream& stream) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestPrintResult){
//     //virtual void print_result(std::ostream& stream) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestGetResult){
//     //std::string get_result() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestGetText){
//     //std::string get_text() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestDestructor){
//     /*Node::~Node(){
//         for(Node* parent:parents_){
//             for(std::shared_ptr<Node>& child:parent->childs_)
//                 if(child.get()==this)
//                     child.reset();
//         }
//         release_childs();
//     }*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestAddParent){
//     //void add_parent(Node*);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestHasParents){
//     //bool has_references() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReplaceMoveChildTo){
//     //void replace_move_child_to(Node*,size_t,size_t);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReplaceCopyChildTo){
//     //void replace_copy_child_to(Node*,size_t,size_t);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestRefreshParentsLinks){
//     //void refresh_parent_links() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestRefresh){
//     //void refresh();
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestParentsConst){
//     //const std::set<Node*>& references() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestParents){
//     //std::set<Node*>& references();
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReferTo){
//     //bool refer_to(std::string_view var_name) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestIsNotCycled){
//     //bool is_not_cycled() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReferToVars){
//     //std::set<std::shared_ptr<VariableNode>> refer_to_vars() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestReferToNodeOfType){
//     //std::set<std::shared_ptr<Node>> refer_to_node_of_type(NODE_TYPE) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestCaller){
//     /*inline bool caller() const;*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestHasChilds){
//     /*inline bool has_childs() const;*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestHasChild){
//     /*inline bool has_child(size_t id) const;*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestRecursiveFunctionAppliedToAllChilds){
//     /*template<typename T, typename... U>
//     void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func);*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestCacheTypeValue){
//     /*void cache_type_value() const;*/
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestChilds){
//     //const std::vector<std::shared_ptr<Node>>& childs() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestFlushCache){
//     //virtual void flush_cache() const{}
//     EXPECT_TRUE(false);
// }
// // protected:
// //     //friend class RangeOperationNode;
// //     mutable std::set<Node*> parents_; //is less memory expensive than unordered_set
// //     std::vector<std::shared_ptr<Node>> childs_;
// //     bool caller_ = false;
// //     virtual void __invalidate_type_val__() const;
// //     virtual bool __is_not_cycled__(const Node*) const;
// // private:
// //     template<typename T, typename... U>
// //     void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root);
// //     void __insert_back_string_node__(const std::string& string);
// //     void __insert_back_string_node__(std::string&& string);
// //     void __insert_back_value_node__(const Value_t& val);
// //     void __insert_back_value_node__(Value_t&& val);
// //     INFO_NODE child(const std::vector<size_t>& indexes, const Node* caller) const;
// //     INFO_NODE child(const std::vector<size_t>& indexes, Node* caller);