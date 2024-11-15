#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "node.h"

class ArrayNode:public Node{
    mutable Result cache_;
    public:
    using Node::operator=;
    using Node::insert_back;

    typedef std::shared_ptr<Node> value_type;
    ArrayNode(size_t sz);
    template<typename T>
    requires std::is_same_v<typename std::decay_t<T>,ArrayNode>
    inline ArrayNode(T&& other):Node(std::forward<T>(other)){
        *this = other;
    }

    template<typename SMART_PTR>
    requires (std::is_base_of_v<Node,typename std::decay_t<SMART_PTR>::element_type> && 
    !std::is_same_v<typename std::decay_t<SMART_PTR>::element_type,ArrayNode>)
    inline ArrayNode(SMART_PTR&& val);

    inline ArrayNode& operator=(const ArrayNode& arr){
        Node::operator=(arr);
        cache_ = arr.cache_;
        return *this;
    }

    inline ArrayNode& operator=(ArrayNode&& arr){
        Node::operator=(std::move(arr));
        std::swap(cache_,arr.cache_);
        return *this;
    }
    virtual NODE_TYPE type() const override;
    virtual Result execute() const override;
    virtual Result execute(size_t index) const override;
    inline virtual Result cached_result(){
        return cache_;
    }
    inline virtual Result cached_result(size_t index) override{
        if(has_child(index))
            return child(index)->cached_result();
        else
            throw std::invalid_argument("Incorrect child's id");
    }
    virtual void insert_back(std::shared_ptr<Node> node) override;
    //insert before value at id
    virtual std::shared_ptr<Node> insert(size_t,std::shared_ptr<Node>) override;
    virtual std::shared_ptr<Node> replace(size_t,std::shared_ptr<Node>) override;
    size_t size() const;
    bool empty() const;
    std::vector<std::shared_ptr<Node>>::const_iterator begin() const;
    std::vector<std::shared_ptr<Node>>::iterator begin();
    std::vector<std::shared_ptr<Node>>::const_iterator end() const;
    std::vector<std::shared_ptr<Node>>::iterator end();
    std::vector<std::shared_ptr<Node>>::const_iterator cbegin() const;
    std::vector<std::shared_ptr<Node>>::const_iterator cend() const;
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }
};

template<typename SMART_PTR>
requires (std::is_base_of_v<Node,typename std::decay_t<SMART_PTR>::element_type> && 
!std::is_same_v<typename std::decay_t<SMART_PTR>::element_type,ArrayNode>)
inline ArrayNode::ArrayNode(SMART_PTR&& val){
    childs_.resize(0);
    insert_back(std::forward<SMART_PTR>(val));
}