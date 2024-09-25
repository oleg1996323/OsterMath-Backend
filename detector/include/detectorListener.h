#pragma once
#include "detect_type_functionBaseListener.h"

using namespace std::string_view_literals;
namespace detail{
class BaseListener: public detect_type_functionBaseListener{
    public:
    void* info;
    ~BaseListener();
    void* get_info() const;
    virtual void enterParens(detect_type_functionParser::ParensContext* ctx) override;
    virtual void exitParens(detect_type_functionParser::ParensContext* ctx) override;
    virtual void enterVariable(detect_type_functionParser::VariableContext *ctx) override;
    virtual void exitVariable(detect_type_functionParser::VariableContext *ctx) override;
    virtual void enterUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) override;
    virtual void exitUnaryOp(detect_type_functionParser::UnaryOpContext* ctx) override;
    virtual void enterLiteral(detect_type_functionParser::LiteralContext *ctx) override;
    virtual void exitLiteral(detect_type_functionParser::LiteralContext *ctx) override;
    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) override;
    virtual void exitBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) override;
    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(detect_type_functionParser::ArrayContext *ctx) override;
    virtual void exitArray(detect_type_functionParser::ArrayContext *ctx) override;
    virtual void enterRangefunction(detect_type_functionParser::RangefunctionContext* ctx) override;
    virtual void exitRangefunction(detect_type_functionParser::RangefunctionContext* ctx) override;
    virtual void enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx) override;
    virtual void exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx) override;
    virtual void enterFunction(detect_type_functionParser::FunctionContext* ctx) override;
    virtual void exitFunction(detect_type_functionParser::FunctionContext* ctx) override;
    virtual void enterString(detect_type_functionParser::StringContext * ctx) override;
    virtual void exitString(detect_type_functionParser::StringContext * ctx) override;
    virtual void enterEveryRule(antlr4::ParserRuleContext * ) override;
    virtual void exitEveryRule(antlr4::ParserRuleContext * ) override;
    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};
}