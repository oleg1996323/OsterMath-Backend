#pragma once
#include "def.h"
#include "node.h"

class ValueNode:public Node{
    public:
    ValueNode()=default;
    ValueNode(Value_t&& value):val_(std::move(value)){}
    ValueNode(const Value_t& value):val_(value){}
    ValueNode(std::string&& value):val_(value){}
    ValueNode(const ValueNode& other);
    ValueNode(ValueNode&&) = delete;

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::VALUE;
    }

    virtual Result execute() override{
        return val_;
    }

    virtual Result execute(size_t index) override{
        return val_;
    }
    
    virtual bool is_numeric() const override;

    virtual bool is_string() const override;

    virtual bool is_array() const override;

    virtual void insert_back(std::shared_ptr<Node> node) override;

    virtual void print_text(std::ostream& stream) const override;

    virtual void print_result(std::ostream& stream) const override;

    private:
    Value_t val_;
};