#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "abstract_node.h"
#include "func_node.h"

class ArrayNode:public AbstractNode{
    mutable Result cache_;
public:
    typedef AbstractNode* value_type;
    ArrayNode(size_t sz);

    inline ArrayNode(const ArrayNode& arr):AbstractNode(arr){
        ArrayNode::operator=(arr);
    }

    inline ArrayNode(ArrayNode&& arr):AbstractNode(arr){
        ArrayNode::operator=(arr);
    }

    inline ArrayNode& operator=(const ArrayNode& arr){
        if(this!=&arr){
            AbstractNode::operator=(arr);
            cache_ = arr.cache_;
        }
        return *this;
    }

    inline ArrayNode& operator=(ArrayNode&& arr){
        if(this!=&arr){
            AbstractNode::operator=(arr);
            std::swap(cache_,arr.cache_);
        }
        return *this;
    }
    ~ArrayNode();

    //return the replaced ArrayNode pointer
    template<typename T>
    requires (
        std::is_same_v<StringNode,T> || 
        std::is_same_v<ValueNode,T> ||
        std::is_same_v<RangeOperationNode,T> ||
        std::is_same_v<FunctionNode,T> ||
        std::is_same_v<ReferenceNode,T>)
    static AbstractNode* replace_in_owner_by_array(T* val);

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::ARRAY;
    }
    virtual Result execute() const override;
    inline virtual Result cached_result() const override{
        return cache_;
    }
    size_t size() const;
    bool empty() const;
    Childs_t::const_iterator begin() const;
    Childs_t::const_iterator end() const;
    Childs_t::const_iterator cbegin() const;
    Childs_t::const_iterator cend() const;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual bool is_empty() const override;
    virtual TYPE_VAL type_val() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }
};