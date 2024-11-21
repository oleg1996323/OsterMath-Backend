#pragma once
#include <iostream>
#include "def.h"
#include "node.h"

class StringNode:public Node{
    std::string cache_;
    inline virtual Result execute(const std::vector<std::shared_ptr<VariableNode>>& variables, const std::vector<size_t>& order = std::vector<size_t>()) const override{
        return cache_;
    }
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
        return NODE_TYPE::VALUE;
    }
    inline virtual Result execute() const override{
        return cache_;
    }
    inline virtual Result cached_result() override{
        return cache_;
    }

    virtual bool is_numeric() const override;
    virtual bool is_string() const override;
    virtual bool is_array() const override;
    virtual void insert_back(std::shared_ptr<Node> node) override;
    virtual void print_text(std::ostream& stream) const override;
    virtual void print_result(std::ostream& stream) const override;
};