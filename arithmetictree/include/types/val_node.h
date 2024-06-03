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

    virtual bool is_defined() const override{
        return true;
    }

    virtual void insert(std::shared_ptr<Node> node) override;

    #ifdef DEBUG
    virtual void print() const;
    #endif

    virtual void serialize(std::ostream& stream) override;

    virtual void deserialize(std::ostream& stream) override;

    private:
    Value_t val_;
};