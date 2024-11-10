#pragma once
#include <vector>
#include <memory>
#include <type_traits>
#include "node.h"

class ArrayNode:public Node{
    public:
    typedef std::shared_ptr<Node> value_type;
    ArrayNode(size_t sz);
    ArrayNode(const ArrayNode& other);
    ArrayNode(ArrayNode&&) = delete;
    ArrayNode(std::shared_ptr<ValueNode>&& val);
    ArrayNode(const std::shared_ptr<ValueNode>& val);

    template<typename T>
    requires (!std::is_same_v<T,ArrayNode>)
    ArrayNode operator=(std::shared_ptr<T>&& val);
    virtual NODE_TYPE type() const override;
    virtual Result execute() override;
    inline virtual Result execute() const override{
        return execute();
    }
    virtual Result execute(size_t index) override;
    virtual Result execute(size_t index) const override{
        return execute(index);
    }
    inline virtual Result cached_result() const{
        return cache_;
    }
    inline virtual Result cached_result(size_t index){
        if(has_child(index))
        return child(index)->cached_result();
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
    private:
    Result cache_;
};

template<typename T>
requires (!std::is_same_v<T,ArrayNode>)
ArrayNode ArrayNode::operator=(std::shared_ptr<T>&& val){
    return ArrayNode().insert_back(std::forward<T>(val));
}