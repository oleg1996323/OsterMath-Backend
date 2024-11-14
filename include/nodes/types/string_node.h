#pragma once
#include <iostream>
#include "def.h"
#include "node.h"

class StringNode:public Node{
    public:
    inline StringNode()=default;
    inline StringNode(Value_t&& value):str_(value.str()){}
    inline StringNode(const Value_t& value):str_(value.str()){}
    inline StringNode(const std::string& str):str_(str){}
    inline StringNode(std::string&& str):str_(str){}
    inline StringNode(const StringNode& other);
    StringNode(StringNode&&) = delete;

    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::VALUE;
    }
    inline virtual Result execute() override{
        return str_;
    }
    inline virtual Result execute(size_t index) override{
        return str_;
    }
    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
    private:
    std::string str_;
};