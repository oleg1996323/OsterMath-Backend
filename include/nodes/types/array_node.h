#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "abstract_node.h"

class ArrayNode:public AbstractNode{
    mutable Result cache_;
public:
    typedef std::shared_ptr<AbstractNode> value_type;
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
    template<typename SMART_PTR>
    requires std::is_base_of_v<AbstractNode,typename std::decay_t<SMART_PTR>::element_type>
    static inline std::shared_ptr<ArrayNode> return_from(SMART_PTR&& val){
        std::shared_ptr<ArrayNode> result = std::make_shared<ArrayNode>(0);
        if(val){
            if(val->type()==NODE_TYPE::ARRAY)
                return std::dynamic_pointer_cast<ArrayNode>(val);
            else
                result->insert_back(std::forward<SMART_PTR>(val));
        }
        return result;   
    }

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::ARRAY;
    }
    virtual Result execute() const override;
    inline virtual Result cached_result() const override{
        return cache_;
    }
    size_t size() const;
    bool empty() const;
    std::vector<std::shared_ptr<AbstractNode>>::const_iterator begin() const;
    std::vector<std::shared_ptr<AbstractNode>>::const_iterator end() const;
    std::vector<std::shared_ptr<AbstractNode>>::const_iterator cbegin() const;
    std::vector<std::shared_ptr<AbstractNode>>::const_iterator cend() const;
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