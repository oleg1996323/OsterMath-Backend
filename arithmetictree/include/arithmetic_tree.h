#pragma once
#include <iostream>
#include <stdexcept>
#include <memory>
#include <optional>
#include "def.h"

class Node;
class ArithmeticTree{
    public:
    using type = Value_t;

    ArithmeticTree() = default;

    ArithmeticTree(const ArithmeticTree& other);

    ArithmeticTree(ArithmeticTree&& other) noexcept;

    ArithmeticTree& operator=(const ArithmeticTree& other);

    ArithmeticTree& operator=(ArithmeticTree&& other) noexcept;

    virtual Value_t execute() const;

    virtual const Value_t& value() const;

    void insert(const std::shared_ptr<Node>& node);

    bool is_ready() const;

    const std::shared_ptr<Node>& root() const;

    Node* last() const{
        return last_incomplete_;
    }

    #ifdef DEBUG
    void print() const;
    #endif

    protected:
    std::shared_ptr<Node> root_;
    mutable Node* last_incomplete_;
    mutable std::optional<Value_t> cache_;
};

namespace ranges{

class ArithmeticTree:public ::ArithmeticTree{
    public:
    using type = Value_t;

    Value_t execute(size_t index) const;

    const Value_t& value(size_t index) const;
};
}