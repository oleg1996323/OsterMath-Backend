#pragma once
#include <string>
#include <vector>
#include "def.h"
#include "range_node/def.h"
#include "node/def.h"
#include "node/hash.h"

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

constexpr const char* nodes_types[(size_t)NODE_TYPE::CUSTOM+1] = {
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

//TODO: create class AbstractNodeNMProxy for copying and moving childs

using namespace node_range_operation;
class AbstractNode{
public:
    AbstractNode();
    AbstractNode(const std::shared_ptr<BaseData>& bd);
    AbstractNode(NodeManager* rel_mng);

    AbstractNode(const AbstractNode& other);
    AbstractNode(AbstractNode&& other);
    AbstractNode* copy_paste(const AbstractNode* other);
    AbstractNode* cut_paste(AbstractNode* other) noexcept;

    AbstractNode* child(size_t id) const;
    AbstractNode* child(size_t id);
    INFO_NODE child(const std::vector<int>::const_iterator& first,const std::vector<int>::const_iterator& last);
    
    template<typename T>
    requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
    AbstractNode* insert_back(T&& arg);
    // template<typename T>
    // requires (std::is_base_of_v<AbstractNode,T>)
    // inline void insert_back(std::unique_ptr<T>&& arg){
    //     __rel_tmp_forward_insert_back__(std::move(arg));
    // }
    AbstractNode* insert_back(std::unique_ptr<AbstractNode>&& new_child);
    //insert before value at id
    AbstractNode* insert(size_t,std::unique_ptr<AbstractNode>&& new_child);
    AbstractNode* replace(size_t,std::unique_ptr<AbstractNode>&& new_child);

    AbstractNode* insert_back_ref(AbstractNode* ref_child);
    //insert before value at id
    AbstractNode* insert_ref(size_t,AbstractNode* new_child);
    AbstractNode* replace_ref(size_t,AbstractNode* new_child);

    std::string get_result() const;
    std::string get_text() const;
    
    bool has_references() const;
    bool has_owner() const;
    INFO_NODE owner() const;

    //void replace_move_child_to(Node*,size_t,size_t);
    //void replace_copy_child_to(Node*,size_t,size_t);
    void refresh_parent_links() const;
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
    void erase_child(size_t id) const;
    void set_relation_manager(const NodeManager* manager){
        rel_mng_ = const_cast<NodeManager*>(manager);
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
    mutable NodeManager* rel_mng_; //parent, which own this node
    mutable bool caller_ = false;
    AbstractNode(size_t sz);
    virtual bool __is_not_cycled__(const AbstractNode*) const;
private:
    AbstractNode* __insert_back_string_node__(const std::string& string);
    AbstractNode* __insert_back_string_node__(std::string&& string);
    AbstractNode* __insert_back_value_node__(const Value_t& val);
    AbstractNode* __insert_back_value_node__(Value_t&& val);
    INFO_NODE child(const std::vector<size_t>& indexes, const AbstractNode* caller) const;
    INFO_NODE child(const std::vector<size_t>& indexes, AbstractNode* caller);
    void __rel_tmp_forward_insert_back__(std::unique_ptr<AbstractNode>&& node);
};

template<typename T>
requires (std::is_same_v<T,std::string> || std::is_same_v<T,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
AbstractNode* AbstractNode::insert_back(T&& arg){
    if constexpr (std::is_same_v<std::decay_t<T>,Value_t> || std::is_convertible_v<std::decay_t<T>,Value_t>)
        return __insert_back_value_node__(std::forward<T>(arg));
    else if constexpr(std::is_same_v<std::decay_t<T>,std::string>)
        return __insert_back_string_node__(std::forward<T>(arg));
}