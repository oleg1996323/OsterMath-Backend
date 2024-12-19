#pragma once
#include <string>
#include <vector>
#include "def.h"
#include "range_node/def.h"
#include "node/def.h"

class EmptyNode;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;
class RangeOperationNode;
class StringNode;
class RelationManager;
class BaseData;

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
    REF,
    CUSTOM
};

using namespace node_range_operation;
class AbstractNode{
public:
    AbstractNode();
    AbstractNode(const std::shared_ptr<BaseData>& bd);
    AbstractNode(RelationManager* rel_mng);

    AbstractNode(const AbstractNode& other);
    AbstractNode(AbstractNode&& other);
    AbstractNode& operator=(const AbstractNode& other);
    AbstractNode& operator=(AbstractNode&& other);


    const std::shared_ptr<AbstractNode>& child(size_t id) const;
    std::shared_ptr<AbstractNode>& child(size_t id);
    INFO_NODE child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last);
    
    template<typename T>
    requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
    void insert_back(T&& arg);
    template<typename T>
    requires (std::is_base_of_v<AbstractNode,T>)
    inline void insert_back(std::shared_ptr<T> arg){
        __rel_tmp_forward_insert_back__(arg);
    }
    void insert_back(std::shared_ptr<AbstractNode>);
    //insert before value at id
    std::shared_ptr<AbstractNode> insert(size_t,std::shared_ptr<AbstractNode>);
    std::shared_ptr<AbstractNode> replace(size_t,std::shared_ptr<AbstractNode>);

    std::string get_result() const;
    std::string get_text() const;
    
    bool has_references() const;
    bool has_owner() const;
    AbstractNode* owner() const;

    std::shared_ptr<AbstractNode> get_this() const;
    //void replace_move_child_to(Node*,size_t,size_t);
    //void replace_copy_child_to(Node*,size_t,size_t);
    void refresh_parent_links() const;
    void refresh() const;
    const References_t& references() const;
    bool refer_to(std::string_view var_name) const;
    bool is_not_cycled() const;
    std::set<std::shared_ptr<VariableNode>> refer_to_vars() const;
    std::set<std::shared_ptr<AbstractNode>> refer_to_node_of_type(NODE_TYPE) const;
    inline bool caller() const{
        return caller_;
    }
    bool has_childs() const noexcept;
    bool has_child(size_t id) const noexcept;
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<AbstractNode>&,U...)> func);
    const Childs_t& childs() const;
    void cache_type_value() const;
    RelationManager* relation_manager() const{
        return rel_mng_;
    }
    void erase_child(size_t id) const;
    void set_relation_manager(RelationManager* manager){
        rel_mng_ = manager;
    }

    virtual Result execute_for_array_variables(const execute_for_array_variables_t&) const;

    virtual ~AbstractNode() = default;
    virtual TYPE_VAL type_val() const;
    virtual NODE_TYPE type() const = 0;
    virtual Result execute() const = 0;
    virtual Result cached_result() const = 0;
    virtual bool is_numeric() const = 0;
    virtual bool is_string() const = 0;
    virtual bool is_array() const = 0;
    virtual bool is_empty() const = 0;
    virtual void print_text(std::ostream& stream) const = 0;
    virtual void print_result(std::ostream& stream) const = 0;
    virtual void flush_cache() const{};
protected:
    mutable RelationManager* rel_mng_; //parent, which own this node
    mutable bool caller_ = false;
    AbstractNode(size_t sz);
    virtual bool __is_not_cycled__(const AbstractNode*) const;
private:
    template<typename T, typename... U>
    void recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<AbstractNode>&,U...)> func, AbstractNode* root);
    void __insert_back_string_node__(const std::string& string);
    void __insert_back_string_node__(std::string&& string);
    void __insert_back_value_node__(const Value_t& val);
    void __insert_back_value_node__(Value_t&& val);
    INFO_NODE child(const std::vector<size_t>& indexes, const AbstractNode* caller) const;
    INFO_NODE child(const std::vector<size_t>& indexes, AbstractNode* caller);
    void __rel_tmp_forward_insert_back__(std::shared_ptr<AbstractNode> node);
};

template<typename T, typename... U>
void AbstractNode::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<AbstractNode>&,U...)> func){
    for(auto& child:childs()){
        if(child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
    }
}

template<typename T, typename... U>
void AbstractNode::recursive_function_applied_to_all_childs(std::function<T(const std::shared_ptr<AbstractNode>&,U...)> func, AbstractNode* root){
    for(auto& child:childs())
        if(child.get()!=root && child->type()!=NODE_TYPE::VARIABLE){
            func(child);
            child->recursive_function_applied_to_all_childs(func,this);
        }
}

template<typename T>
requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
void AbstractNode::insert_back(T&& arg){
    if constexpr (std::is_same_v<std::decay_t<T>,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
        __insert_back_value_node__(std::forward<T>(arg));
    else if constexpr(std::is_same_v<std::decay_t<T>,std::string>)
        __insert_back_string_node__(std::forward<T>(arg));
}