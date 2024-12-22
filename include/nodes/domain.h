#pragma once
#include <unordered_map>
#include <string_view>
#include <memory>
#include <optional>
#include <list>
#include "node.h"
#include "val_node.h"
#include "def.h"

enum class COMP_T{
    LARGER_OR_EQUAL,
    LARGER,
    LESS,
    LESS_OR_EQUAL,
    EQUAL
};

struct Domain{
    mutable AbstractNode* lhs_;
    mutable AbstractNode* rhs_;
    std::unique_ptr<AbstractNode> value_if_true_ = std::make_unique<ValueNode>(0);
    COMP_T type_;

    bool is() const;
    void set_expression_if_true(std::unique_ptr<AbstractNode>&& value_if_true);
    void print_text(std::ostream&) const;
};

class VariableDomain{
    public:
    VariableDomain(const VariableNode* var_node);

    void add_domain(Domain&&);

    // std::optional<Domain> get_domain(size_t id);

    // std::optional<Domain> get_domain(size_t id) const;

    void unset_domain(size_t id);

    void clear();

    Result execute() const;

    void print_text(std::ostream&) const;

    const std::list<Domain>& get_domains() const;

    std::list<Domain>& get_domains();

    private:
    std::list<Domain> domains_;
    const VariableNode* default_expression_;
};