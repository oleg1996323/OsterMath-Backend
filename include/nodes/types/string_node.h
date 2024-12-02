#pragma once
#include <iostream>
#include "def.h"
#include "node.h"
#include "range_node/def.h"

class StringNode:public Node{
    std::string cache_;
    public:
    inline StringNode()=default;
    inline StringNode(Value_t&& value){
        cache_ = value.str();
    }
    inline StringNode(const Value_t& value){
        cache_ = value.str();
    }
    inline StringNode(const std::string& str){
        cache_ = str;
    }
    inline StringNode(std::string&& str){
        cache_ = str;
    }
    inline StringNode(const StringNode& other);
    StringNode(StringNode&&) = delete;

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::STRING;
    }
    inline virtual Result execute() const override{
        return cache_;
    }
    inline virtual Result cached_result() const override{
        return cache_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    inline virtual bool __is_not_cycled__(const Node*) const override{
        return true;
    }
};