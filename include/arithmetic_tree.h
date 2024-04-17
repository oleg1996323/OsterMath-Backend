#pragma once
#include <iostream>
#include <stdexcept>
#include <memory>
#include <optional>
#include "arithmetic_types.h"

class Node;

class ArithmeticTree{
    public:

    ArithmeticTree() = default;

    ArithmeticTree(const ArithmeticTree& other);

    ArithmeticTree(ArithmeticTree&& other) noexcept;

    ArithmeticTree& operator=(const ArithmeticTree& other);

    Value_t execute() const;

    const Value_t& value() const;

    void insert(Node* node);

    bool is_ready() const;

    private:
    std::shared_ptr<Node> root_;
    mutable Node* last_incomplete_;
    Value_t cache_ = 0.;
};