#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "node.h"

class ArrayNode:public Node{
    mutable Result cache_;
    mutable std::optional<TYPE_VAL> type_val_;
    mutable std::optional<bool> rectangle_;
public:
    using Node::operator=;
    using Node::insert_back;

    typedef std::shared_ptr<Node> value_type;
    ArrayNode(size_t sz);

    inline ArrayNode(const ArrayNode& arr):Node(arr){
        if(this!=&arr){
            Node::operator=(arr);
            cache_ = arr.cache_;
            type_val_ = arr.type_val_;
            rectangle_ = arr.rectangle_;
        }
    }

    inline ArrayNode(ArrayNode&& arr):Node(arr){
        if(this!=&arr){
            Node::operator=(std::move(arr));
            std::swap(cache_,arr.cache_);
            type_val_ = arr.type_val_;
            rectangle_ = arr.rectangle_;
        }
    }

    template<typename SMART_PTR>
    requires std::is_base_of_v<Node,typename std::decay_t<SMART_PTR>::element_type>
    static inline std::shared_ptr<ArrayNode> return_from(SMART_PTR&& val){
        std::shared_ptr<ArrayNode> result = std::make_shared<ArrayNode>(0);
        if(val)
            if(val->type()==NODE_TYPE::ARRAY)
                return std::dynamic_pointer_cast<ArrayNode>(val);
            else
                insert_back(std::forward<SMART_PTR>(val));
        else
            return result;
    }

    virtual NODE_TYPE type() const override;
    virtual Result execute() const override;
    inline virtual Result cached_result() const override{
        return cache_;
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
    virtual TYPE_VAL type_val() const override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    virtual void flush_cache() const override{
        cache_ = std::monostate();
    }
    bool is_rectangle() const;
    private:
    inline virtual void __invalidate_type_val__() const override{
        type_val_.reset();
        Node::__invalidate_type_val__();
    }
};