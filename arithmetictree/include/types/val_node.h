#pragma once
#include "def.h"
#include "node.h"

class ValueNode:public Node{
    public:
    ValueNode(Value_t&& value):val_(std::move(value)){}

    ValueNode(const Value_t& value):val_(value){}

    ValueNode(std::string&& value):val_(value){}

    virtual NODE_TYPE type() const override{
        return NODE_TYPE::VALUE;
    }

    virtual Node* first_undefined_child_node() override{
        return nullptr;
    }

    virtual Result execute() override{
        return val_;
    }

    virtual Result execute(size_t index) override{
        return val_;
    }

    const Value_t& get() const;

    virtual void insert(std::shared_ptr<Node> node) override;

    virtual void printText() const;

    virtual std::ostream& operator<<(std::ostream& stream) override;

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    private:
    Value_t val_;
};
