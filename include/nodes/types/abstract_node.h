#pragma once
#include <string>
#include <vector>
#include "def.h"
#include "range_node/def.h"
#include "node/def.h"
#include "node/hash.h"
#ifdef DEBUG
#include "include/test/test_log.h"
#endif

class EmptyNode;
class UnaryNode;
class BinaryNode;
class ValueNode;
class VariableNode;
class MultiArgumentNode;
class RangeOperationNode;
class StringNode;
class NodeManager;
class BaseData;

typedef std::pair<Childs_t::const_iterator, Childs_t::const_iterator> Childs_Iter_t;

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

constexpr std::array<const char*,(size_t)NODE_TYPE::CUSTOM+1> nodes_types = {
    "Unary",
    "Binary",
    "Value",
    "Variable",
    "RangeOp",
    "Function",
    "Array",
    "String",
    "Undef",
    "Ref",
    "Custom"
};

class AbstractNodeNMProxy{
    friend AbstractNode;
    template<typename T, typename... ARGS>
    static AbstractNode* __insert_back_internal__(AbstractNode* node, ARGS&&... val);

    template<typename T, typename... ARGS>
    static AbstractNode* __insert_internal__(AbstractNode* node, size_t id, ARGS&&... val);

    template<typename T, typename... ARGS>
    static AbstractNode* __replace_internal__(AbstractNode* node, size_t id, ARGS&&... val);

    static AbstractNode* __insert_back_internal__(AbstractNode* node, std::unique_ptr<AbstractNode>&& val);
    //insert before value at id
    static AbstractNode* __insert_internal__(AbstractNode* node, size_t,std::unique_ptr<AbstractNode>&& new_child);
    static AbstractNode* __replace_internal__(AbstractNode* node, size_t,std::unique_ptr<AbstractNode>&& new_child);
    static void __reserve_childs_internal__(AbstractNode*, size_t id);
};

using namespace node_range_operation;
class AbstractNode{
public:
    AbstractNode() = default;
    AbstractNode(const std::shared_ptr<BaseData>& bd);
    AbstractNode(NodeManager* rel_mng);

    AbstractNode(const AbstractNode& other, NodeManager* mng);
    AbstractNode(AbstractNode&& other, NodeManager* mng);
    void copy_paste(const AbstractNode* other);
    void cut_paste(AbstractNode* other);

    AbstractNode* child(size_t id) const;
    AbstractNode* child(size_t id);
    template<typename T>
    T* child(size_t id);
    template<typename T>
    const T* child(size_t id) const;
    INFO_NODE child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last);

    template<typename T, typename... ARGS>
    requires (std::is_base_of_v<AbstractNode,T> &&
    !std::is_same_v<T,VariableNode> 
    #ifndef DEBUG
    //&&
    //!std::is_same_v<T,UnaryNode> &&
    //!std::is_same_v<T,BinaryNode>
    #endif
    )
    T* insert_back(ARGS&&... arg);

    template<typename T, typename... ARGS>
    requires (std::is_base_of_v<AbstractNode,T> &&
    !std::is_same_v<T,VariableNode> 
    #ifndef DEBUG
    //&&
    //!std::is_same_v<T,UnaryNode> &&
    //!std::is_same_v<T,BinaryNode>
    #endif
    )
    T* insert(size_t id,ARGS&&... arg);

    template<typename T, typename... ARGS>
    requires (std::is_base_of_v<AbstractNode,T> &&
    !std::is_same_v<T,VariableNode> 
    #ifndef DEBUG
    //&&
    //!std::is_same_v<T,UnaryNode> &&
    //!std::is_same_v<T,BinaryNode>
    #endif
    )
    T* replace(size_t id,ARGS&&... arg);

    AbstractNode* insert_back_ref(AbstractNode* ref_child);
    //insert before value at id
    AbstractNode* insert_ref(size_t,AbstractNode* new_child);
    AbstractNode* replace_ref(size_t,AbstractNode* new_child);

    std::string get_result() const;
    std::string get_text() const;
    
    bool has_references() const;
    bool has_owner() const;
    INFO_NODE owner() const;

    void refresh() const;
    const References_t& references() const;
    bool refer_to_var(std::string_view var_name) const;
    bool is_reference_of(AbstractNode* node) const;
    bool is_not_cycled() const;
    std::set<const VariableNode*> refer_to_vars() const;
    std::set<const AbstractNode*> refer_to_node_of_type(NODE_TYPE) const;
    inline bool caller() const{
        return caller_;
    }
    bool has_childs() const noexcept;
    bool has_child(size_t id) const noexcept;
    const Childs_t& childs() const;
    void cache_type_value() const;
    NodeManager* relation_manager() const{
        return rel_mng_;
    }
    void erase_child(size_t id);
    void erase_childs(size_t first_id, size_t last_id);
    void set_relation_manager(NodeManager* manager) const{
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
    bool is_refered_by(const AbstractNode* ref_owner) noexcept;
protected:

    mutable NodeManager* rel_mng_ = nullptr; //parent, which own this node
    mutable bool caller_ = false;
    AbstractNode(size_t, NodeManager*);
    virtual bool __is_not_cycled__(const AbstractNode*) const;
private:
friend AbstractNode* insert_back_move(AbstractNode* at_insertion, AbstractNode* to_insert) noexcept;
friend AbstractNode* insert_back_copy(AbstractNode* at_insertion,AbstractNode* to_insert);
friend AbstractNode* insert_move(AbstractNode* at_insertion, size_t id, AbstractNode* to_insert) noexcept;
friend AbstractNode* insert_copy(AbstractNode* at_insertion, size_t id,AbstractNode* to_insert);
friend AbstractNode* replace_move(AbstractNode* at_replace, size_t id, AbstractNode* to_replace) noexcept;
friend AbstractNode* replace_copy(AbstractNode* at_replace, size_t id,AbstractNode* to_replace);
friend Childs_Iter_t insert_back_move(AbstractNode* at_insertion,Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
friend Childs_Iter_t insert_back_copy(AbstractNode* at_insertion,Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
friend Childs_Iter_t insert_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
friend Childs_Iter_t insert_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
friend Childs_Iter_t replace_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
friend Childs_Iter_t replace_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
    AbstractNode* __insert_back__(std::unique_ptr<AbstractNode>&& new_child);
    //insert before value at id
    AbstractNode* __insert__(size_t,std::unique_ptr<AbstractNode>&& new_child);
    AbstractNode* __replace__(size_t,std::unique_ptr<AbstractNode>&& new_child);
    INFO_NODE __child__(const std::vector<size_t>& indexes, const AbstractNode* caller) const;
    INFO_NODE __child__(const std::vector<size_t>& indexes, AbstractNode* caller);
};

#include "function_node/def.h"
class FunctionNode;
class RangeOperationNode;

void copy_paste(AbstractNode* copy_from, AbstractNode* paste_to);
void cut_paste(AbstractNode* cut_from, AbstractNode* paste_to);
AbstractNode* insert_back_move(AbstractNode* at_insertion, AbstractNode* to_insert) noexcept;
AbstractNode* insert_back_copy(AbstractNode* at_insertion,AbstractNode* to_insert);
AbstractNode* insert_move(AbstractNode* at_insertion, size_t id, AbstractNode* to_insert) noexcept;
AbstractNode* insert_copy(AbstractNode* at_insertion, size_t id,AbstractNode* to_insert);
AbstractNode* replace_move(AbstractNode* at_replace, size_t id, AbstractNode* to_replace) noexcept;
AbstractNode* replace_copy(AbstractNode* at_replace, size_t id,AbstractNode* to_replace);
Childs_Iter_t insert_back_move(AbstractNode* at_insertion,Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
Childs_Iter_t insert_back_copy(AbstractNode* at_insertion,Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
Childs_Iter_t insert_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
Childs_Iter_t insert_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);
Childs_Iter_t replace_move(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_move_first,Childs_t::const_iterator to_move_last);
Childs_Iter_t replace_copy(AbstractNode* at_insertion,size_t id, Childs_t::const_iterator to_copy_first,Childs_t::const_iterator to_copy_last);

template<typename T, typename... ARGS>
AbstractNode* AbstractNodeNMProxy::__insert_back_internal__(AbstractNode* node, ARGS&&... val){
    std::unique_ptr<T> tmp;
    if constexpr (std::is_same_v<FunctionNode,T>){
        auto func_op = std::get<0>(std::forward_as_tuple(std::forward<ARGS>(val)...));
        if(NUMBER_OF_ARGUMENT[(int)func_op]>-1)
            tmp = std::make_unique<T>(std::forward<ARGS>(val)...,NUMBER_OF_ARGUMENT[(int)func_op]);
        else tmp = std::make_unique<T>(std::forward<ARGS>(val)...);
    }
    else tmp = std::make_unique<T>(std::forward<ARGS>(val)...);
    tmp->set_relation_manager(node->relation_manager());
    return __insert_back_internal__(node,std::move(tmp));
}
template<typename T, typename... ARGS>
AbstractNode* AbstractNodeNMProxy::__insert_internal__(AbstractNode* node, size_t id, ARGS&&... val){
    std::unique_ptr<T> tmp = std::make_unique<T>(std::forward<ARGS>(val)...);
    tmp->set_relation_manager(node->relation_manager());
    return __insert_internal__(node,id,std::move(tmp));
}
template<typename T, typename... ARGS>
AbstractNode* AbstractNodeNMProxy::__replace_internal__(AbstractNode* node, size_t id, ARGS&&... val){
    std::unique_ptr<T> tmp = std::make_unique<T>(std::forward<ARGS>(val)...);
    tmp->set_relation_manager(node->relation_manager());
    return __replace_internal__(node,id,std::move(tmp));
}

template<typename T, typename... ARGS>
requires (std::is_base_of_v<AbstractNode,T> &&
!std::is_same_v<T,VariableNode> 
#ifndef DEBUG
    //&&
    //!std::is_same_v<T,UnaryNode> &&
    //!std::is_same_v<T,BinaryNode>
#endif
)
T* AbstractNode::insert_back(ARGS&&... arg){
    return static_cast<T*>(AbstractNodeNMProxy::__insert_back_internal__<T,ARGS...>(this,std::forward<ARGS>(arg)...,rel_mng_));
}

template<typename T, typename... ARGS>
requires (std::is_base_of_v<AbstractNode,T> &&
!std::is_same_v<T,VariableNode>
#ifndef DEBUG
//&&
//!std::is_same_v<T,UnaryNode> &&
//!std::is_same_v<T,BinaryNode>
#endif
)
T* AbstractNode::insert(size_t id,ARGS&&... arg){
    return static_cast<T*>(AbstractNodeNMProxy::__insert_internal__<T,ARGS...>(this,id,std::forward<ARGS>(arg)...,rel_mng_));
}

template<typename T, typename... ARGS>
requires (std::is_base_of_v<AbstractNode,T> &&
!std::is_same_v<T,VariableNode>
#ifndef DEBUG
//&&
//!std::is_same_v<T,UnaryNode> &&
//!std::is_same_v<T,BinaryNode>
#endif
)
T* AbstractNode::replace(size_t id,ARGS&&... arg){
    return static_cast<T*>(AbstractNodeNMProxy::__replace_internal__<T,ARGS...>(this,id,std::forward<ARGS>(arg)...,rel_mng_));
}

template<typename T>
T* AbstractNode::child(size_t id){
    T* res = dynamic_cast<T*>(child(id));
    if(res)
        return res;
    else return nullptr;
}
template<typename T>
const T* AbstractNode::child(size_t id) const{
    const T* res = dynamic_cast<const T*>(child(id));
    if(res)
        return res;
    else return nullptr;
}