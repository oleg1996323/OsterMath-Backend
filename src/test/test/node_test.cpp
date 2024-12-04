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
#include <vector>

using namespace functions::auxiliary;

TEST(Node_test,TestDefaultConstruct){
    //Node()=default;
    Node node;
    EXPECT_TRUE(&node);
}
TEST(Node_test,TestCopyConstruct){
    /*Node(const Node& other){
        *this = other;
    }*/
    {
        Node node_1;
        {
            Node node_2;
            node_1=node_2;
        }
        EXPECT_TRUE(&node_1);
    }
    {
        std::shared_ptr<BaseData> bd = std::make_shared<BaseData>("bd");
        std::shared_ptr<VariableBase> var_A = bd->add_variable("A");
        std::shared_ptr<VariableBase> var_B = bd->add_variable("B");
        std::shared_ptr<ArrayNode> node_1 = std::make_shared<ArrayNode>(10);
        std::vector<std::shared_ptr<ValueNode>> values_1;
        std::vector<std::shared_ptr<ValueNode>> values_2;
        var_A->node()->insert_back(node_1);
        {
            std::shared_ptr<ArrayNode> node_2 = std::make_shared<ArrayNode>(10);
            var_B->node()->insert_back(node_2);
            for(int i=0;i<10;++i){
                values_1.push_back(std::make_shared<ValueNode>(i));
                node_1->insert_back(values_1.at(i));
                values_2.push_back(std::make_shared<ValueNode>(i));
                node_2->insert_back(values_2.at(i));
            }
            
            *node_1.get()=*node_2.get();
        }
        EXPECT_TRUE(&node_1);
        for(size_t i=0;i<values_2.size();++i){
            EXPECT_TRUE(node_1->has_child(i));
            if(node_1->has_child(i)){
                EXPECT_TRUE(node_1->child(i).get()!=values_2.at(i).get());
                EXPECT_TRUE(node_1->child(i)->get_result()==values_2.at(i)->get_result());
                std::cout<<node_1->child(i)->get_result()<<std::endl;
            }
        }
        EXPECT_EQ(node_1->parents().size(),1);
        EXPECT_EQ(*node_1->parents().begin(),bd->get("B")->node().get());
        EXPECT_EQ(bd->get("A")->node()->child(0).get(),nullptr);
    }
}
// TEST(Node_test,TestOperatorCopy){
//     //Node& operator=(const Node& other);
//     EXPECT_TRUE(false);
// }
// TEST(Node_test,TestOperatorMove){
//     //Node& operator=(Node&& other);
//     EXPECT_TRUE(false);
// }
// TEST(Node_test,TestGetTypeVal){
//     //virtual TYPE_VAL type_val() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestGetConstRefChildById){
//     //const std::shared_ptr<Node>& child(size_t id) const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestGetRefChildById){
//     //std::shared_ptr<Node>& child(size_t id);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestChildInfoByIndexes){
//     //INFO_NODE child(const std::vector<size_t>& indexes);
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestChildInfoByIndexesConst){
//     //INFO_NODE child(const std::vector<size_t>& indexes) const;
//     EXPECT_TRUE(false);
// }   
// TEST(NodeTest,TestReleaseChilds){
//     //void release_childs();
//     EXPECT_TRUE(false);
// }
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
//     //bool has_parents() const;
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
//     //const std::set<Node*>& parents() const;
//     EXPECT_TRUE(false);
// }
// TEST(NodeTest,TestParents){
//     //std::set<Node*>& parents();
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