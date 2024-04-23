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

    Value_t execute() const;

    const Value_t& value() const;

    void insert(const std::shared_ptr<Node>& node);

    bool is_ready() const;

    const std::shared_ptr<Node>& root() const;

    private:
    std::shared_ptr<Node> root_;
    mutable Node* last_incomplete_;
    mutable std::optional<Value_t> cache_;
};