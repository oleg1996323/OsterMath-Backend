#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <vector>
#include <stack>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "exception.h"
#include "bound.h"

class BaseData;

using namespace std::string_view_literals;

class ErrorListener: public antlr4::BaseErrorListener {
public:
    void syntaxError(antlr4::Recognizer* /* recognizer */, antlr4::Token* /* offendingSymbol */,
                     size_t /* line */, size_t /* charPositionInLine */, const std::string& msg,
                     std::exception_ptr /* e */
                     ) override {
        throw ParsingError("Error when lexing: " + msg);
    }
};

class VariableBase;
class FunctionNode;
class RangeOperationNode;
class Node;

class BaseListener: public ParseRulesBaseListener{
    enum class MODE{
        VARDEF,
        RANGEOPERATION,
        FUNCTIONOPERATION,
        BOUND_DEFINITION
    };

    bool is_range_operation() const;
    bool is_function_operation() const;
    bool is_variable_definition() const;
    bool is_bounds_definition() const;

    void __insert_to_variable__(const std::shared_ptr<Node>& node) const;
    void __insert_to_variable__(std::string&& node) const;
    void __insert_to_variable__(Value_t&& node) const;
    void __insert_to_range_operation__(const std::shared_ptr<Node>& node) const;
    void __insert_to_function_operation__(const std::shared_ptr<Node>& node) const;

    BaseData* __insert_new_data_base__(std::string&& name);

    BaseData* data_base_;
    VariableBase* current_var_;
    std::stack<std::shared_ptr<FunctionNode>> tmp_function_node_;
    std::stack<std::shared_ptr<RangeOperationNode>> tmp_range_node_;
    std::vector<VariableBase*> hdr_vars_; 
    std::stack<MODE> mode_;
    size_t line_counter_ = 0;
    size_t col_counter_ = 0;

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