#pragma once
#include "def.h"
#include "node.h"
#include "range_node/def.h"
#include <unordered_set>

class ValueNode:public Node{
    Value_t cache_;
    public:
    inline ValueNode()=default;
    inline ValueNode(Value_t&& value){
        cache_ = std::move(value);
    }
    inline ValueNode(const Value_t& value){
        cache_ = value;
    }
    inline ValueNode(std::string&& value){
        cache_ = Value_t(value);
    }
    inline ValueNode(const ValueNode& other);
    ValueNode(ValueNode&&) = delete;
    inline virtual NODE_TYPE type() const override{
        return NODE_TYPE::VALUE;
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
    inline virtual Result execute_for_array_variables(const RangeNodeExecuteStruct& variables) const override{
        return cache_;
    }
};