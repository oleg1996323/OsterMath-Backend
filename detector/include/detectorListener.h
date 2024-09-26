#pragma once
#include "detect_type_functionBaseListener.h"
#include "detector.h"

using namespace std::string_view_literals;
namespace detail{
class BaseListener: public detect_type_functionBaseListener{
    public:
    ItemsParsingInfo* info;
    BaseListener();
    ~BaseListener();
    ItemsParsingInfo* get_info() const;
    void swap_info(ItemsParsingInfo**);
    bool is_root() const noexcept;
    void child_containing_item();
    void terminal_item();
    virtual void enterParens(detect_type_function::ParensContext* ctx) override;
    virtual void exitParens(detect_type_function::ParensContext* ctx) override;
    virtual void enterVariable(detect_type_function::VariableContext *ctx) override;
    virtual void exitVariable(detect_type_function::VariableContext *ctx) override;
    virtual void enterUnaryOp(detect_type_function::UnaryOpContext *ctx) override;
    virtual void exitUnaryOp(detect_type_function::UnaryOpContext* ctx) override;
    virtual void enterLiteral(detect_type_function::LiteralContext *ctx) override;
    virtual void exitLiteral(detect_type_function::LiteralContext *ctx) override;
    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(detect_type_function::BinaryOpContext *ctx) override;
    virtual void exitBinaryOp(detect_type_function::BinaryOpContext *ctx) override;
    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(detect_type_function::ArrayContext *ctx) override;
    virtual void exitArray(detect_type_function::ArrayContext *ctx) override;
    virtual void enterRangefunction(detect_type_function::RangefunctionContext* ctx) override;
    virtual void exitRangefunction(detect_type_function::RangefunctionContext* ctx) override;
    virtual void enterMultiargfunction(detect_type_function::MultiargfunctionContext* ctx) override;
    virtual void exitMultiargfunction(detect_type_function::MultiargfunctionContext* ctx) override;
    virtual void enterFunction(detect_type_function::FunctionContext* ctx) override;
    virtual void exitFunction(detect_type_function::FunctionContext* ctx) override;
    virtual void enterString(detect_type_function::StringContext * ctx) override;
    virtual void exitString(detect_type_function::StringContext * ctx) override;
    virtual void enterEveryRule(antlr4::ParserRuleContext * ) override;
    virtual void exitEveryRule(antlr4::ParserRuleContext * ) override;
    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};
}