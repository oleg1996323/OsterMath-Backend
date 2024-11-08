#pragma once
#include "def.h"
#include "node.h"
#include "types.h"
#include <vector>
#include <memory>

class ArrayNode:public Node{
    public:
    typedef std::shared_ptr<Node> value_type;
    ArrayNode(size_t sz);
    ArrayNode(const ArrayNode& other);
    ArrayNode(ArrayNode&&) = delete;
    ArrayNode(std::shared_ptr<ValueNode>&& val);
    ArrayNode(const std::shared_ptr<ValueNode>& val);
    virtual NODE_TYPE type() const override;
    virtual Result execute() override;
    virtual Result execute(size_t index) override;
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
};