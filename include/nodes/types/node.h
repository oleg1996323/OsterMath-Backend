#pragma once
#include <memory>
#include <optional>
#include <vector>
#include <functional>
#include <string>
#include <set>
#include <unordered_set>
#include "def.h"
#include "range_node/def.h"
#include "node/def.h"

class Node;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;
class RangeOperationNode;
class StringNode;

enum class NODE_TYPE{
    UNARY,
    BINARY,
    VALUE,
    VARIABLE,
    RANGEOP,
    FUNCTION,
    ARRAY,
    STRING,
    UNDEF,
    CUSTOM
};

#include <optional>

using namespace node_range_operation;
class Node{
public:
    Node()=default;
    Node(const Node& other){
        *this = other;
    }

    Node& operator=(const Node& other);
    Node& operator=(Node&& other);
    virtual TYPE_VAL type_val() const;
    const std::shared_ptr<Node>& child(size_t id) const;
    std::shared_ptr<Node>& child(size_t id);
    INFO_NODE child(const std::vector<size_t>& indexes);
    INFO_NODE child(const std::vector<size_t>& indexes) const;
    void release_childs();
    virtual NODE_TYPE type() const;
    virtual Result execute() const;
    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const;
    inline virtual Result cached_result() const{
        return std::monostate();
    }
    virtual bool is_numeric() const;
    virtual bool is_string() const;
    virtual bool is_array() const;
    virtual bool is_empty() const;
    
    template<typename T>
    requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
    void insert_back(T&& arg);
    virtual void insert_back(std::shared_ptr<Node>);
    //insert before value at id
    virtual std::shared_ptr<Node> insert(size_t,std::shared_ptr<Node>);
    virtual std::shared_ptr<Node> replace(size_t,std::shared_ptr<Node>);
    virtual void print_text(std::ostream& stream) const;
    virtual void print_result(std::ostream& stream) const;
    std::string get_result() const;
    std::string get_text() const;
    virtual ~Node();
    void add_parent(Node*, int);
    bool has_parents() const;
    //virtual void get_array_childs(std::vector<std::shared_ptr<Node>>& childs) const;
    void replace_move_child_to(Node*,size_t,size_t);
    void replace_copy_child_to(Node*,size_t,size_t);
    void refresh_parent_links();
    void refresh();
    const std::set<INFO_NODE,INFO_NODE_Comparator>& parents() const;
    std::set<INFO_NODE,INFO_NODE_Comparator>& parents();
    bool refer_to(std::string_view var_name) const;
    bool is_not_cycled() const;
    std::set<std::shared_ptr<VariableNode>> refer_to_vars() const;
    std::set<std::shared_ptr<Node>> refer_to_node_of_type(NODE_TYPE) const;
    inline bool caller() const{
        return caller_;
    }
    inline bool has_childs() const noexcept{
        return !childs_.empty();
    }
    inline bool has_child(size_t id) const noexcept{
        return childs_.size()>id;
    }
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func);
    const std::vector<std::shared_ptr<Node>>& childs() const;
    void cache_type_value() const;
    virtual void flush_cache() const{}
protected:
    //friend class RangeOperationNode;
    mutable std::set<INFO_NODE,INFO_NODE_Comparator> parents_; //is less memory expensive than unordered_set
    std::vector<std::shared_ptr<Node>> childs_;
    bool caller_ = false;
    Node(size_t sz);
    virtual void __invalidate_type_val__() const;
    virtual bool __is_not_cycled__(const Node*) const;
private:
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root);
    void __insert_back_string_node__(const std::string& string);
    void __insert_back_string_node__(std::string&& string);
    void __insert_back_value_node__(const Value_t& val);
    void __insert_back_value_node__(Value_t&& val);
    INFO_NODE child(const std::vector<size_t>& indexes, const Node* caller) const;
    INFO_NODE child(const std::vector<size_t>& indexes, Node* caller);
};

template<typename T, typename... U>
void Node::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func){
    for(auto& child:childs_){
        if(child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
    }
}

template<typename T, typename... U>
void Node::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<Node>&,U...)> func, Node* root){
    for(auto& child:childs_)
        if(child.get()!=root && child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
}

template<typename T>
requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
void Node::insert_back(T&& arg){
    if constexpr (std::is_same_v<std::decay_t<T>,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
        __insert_back_value_node__(std::forward<T>(arg));
    else if constexpr(std::is_same_v<std::decay_t<T>,std::string>)
        __insert_back_string_node__(std::forward<T>(arg));
}