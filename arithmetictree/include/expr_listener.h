#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <vector>
#include <stack>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "bound.h"

class BaseData;

using namespace std::string_view_literals;

class FunctionNode;
class RangeOperationNode;
class VariableNode;
class Node;

class BaseListener: public ParseRulesBaseListener{
    enum class MODE{
        VARDEF,
        RANGEOPERATION,
        FUNCTIONOPERATION,
        BOUND_DEFINITION,
        ARRAY_DEFINITION,
        ARRAY_ITEM_DEFINITION,
        EXPRESSION
    };

    bool is_range_operation() const;
    bool is_function_operation() const;
    bool is_variable_definition() const;
    bool is_bounds_definition() const;
    bool is_expression_definition() const;
    bool is_array_definition() const;
    bool is__array_item_definition() const;

    void __insert_to_node__(const std::shared_ptr<Node>& node) const;

    BaseData* __insert_new_data_base__(std::string&& name);

    BaseData* data_base_;
    std::shared_ptr<VariableNode> current_var_;
    std::stack<std::shared_ptr<Node>> anonymous_node_;
    std::stack<MODE> mode_;

    template<typename B_T>
    struct Bound{
        std::string_view db_name;
        std::string_view var_name;
        B_T type;
    };

    std::optional<Bound<TOP_BOUND_T>> top_;
    std::optional<Bound<BOTTOM_BOUND_T>> bottom_;

    public:
    BaseListener(BaseData* data_base):
    data_base_(data_base)
    {}

    void enterExpr(ParseRulesParser::ExprContext* ctx);

    void exitExpr(ParseRulesParser::ExprContext* ctx);

    virtual void enterVardefinition(ParseRulesParser::VardefinitionContext * ctx) override;
    
    virtual void exitVardefinition(ParseRulesParser::VardefinitionContext * ctx) override;

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) override;

    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) override;

    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx) override;

    virtual void enterLiteral(ParseRulesParser::LiteralContext *ctx) override;

    virtual void exitLiteral(ParseRulesParser::LiteralContext *ctx) override;
    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx) override;

    virtual void exitParens(ParseRulesParser::ParensContext *ctx) override;

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(ParseRulesParser::ConstantContext *ctx) override;

    virtual void exitConstant(ParseRulesParser::ConstantContext *ctx) override;

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) override;

    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) override;

    virtual void enterItemArray(ParseRulesParser::ItemArrayContext *ctx) override;

    virtual void exitItemArray(ParseRulesParser::ItemArrayContext *ctx) override;

    virtual void enterRangefunction(ParseRulesParser::RangefunctionContext* ctx) override;

    virtual void exitRangefunction(ParseRulesParser::RangefunctionContext* ctx) override;

    virtual void enterNumber(ParseRulesParser::NumberContext* ctx) override;

    virtual void enterMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx) override;

    virtual void exitMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx) override;

    virtual void enterFunction(ParseRulesParser::FunctionContext* ctx) override;

    virtual void exitFunction(ParseRulesParser::FunctionContext* ctx) override;

    virtual void enterComparision(ParseRulesParser::ComparisionContext* ctx) override;

    virtual void exitComparision(ParseRulesParser::ComparisionContext* ctx) override;

    virtual void enterLess(ParseRulesParser::LessContext* ctx) override;

    virtual void exitLess(ParseRulesParser::LessContext* ctx) override;

    virtual void enterLess_equal(ParseRulesParser::Less_equalContext* ctx) override;

    virtual void exitLess_equal(ParseRulesParser::Less_equalContext* ctx) override;

    virtual void enterLarger(ParseRulesParser::LargerContext* ctx) override;

    virtual void exitLarger(ParseRulesParser::LargerContext* ctx) override;

    virtual void enterLarger_equal(ParseRulesParser::Larger_equalContext* ctx) override;

    virtual void exitLarger_equal(ParseRulesParser::Larger_equalContext* ctx) override;

    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};