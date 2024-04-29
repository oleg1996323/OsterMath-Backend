#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <vector>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "exception.h"

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
class MultiArgumentNode;

class BaseListener: public ParseRulesBaseListener{
    enum class MODE{
        VARDEF,
        HDRDEF,
        TABLEDEF,
        TABVALDEF
    };

    BaseData* data_base_;
    VariableBase* current_var_;
    std::shared_ptr<MultiArgumentNode> tmp_node_;
    std::vector<VariableBase*> hdr_vars_; 
    std::stack<MODE> mode_;
    size_t line_counter_ = 0;
    size_t col_counter_ = 0;

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

    //a function parser for definition any callback function for further calculations
    //{for example: Lg(sumproduct(__Ivs__, __n__))}
    virtual void enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override;

    virtual void exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override;

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) override;

    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) override;

    virtual void enterItemArray(ParseRulesParser::ItemArrayContext *ctx) override;

    virtual void exitItemArray(ParseRulesParser::ItemArrayContext *ctx) override;

    virtual void enterTable_definition(ParseRulesParser::Table_definitionContext* ctx) override;

    virtual void exitTable_definition(ParseRulesParser::Table_definitionContext* ctx) override;

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx) override;

    virtual void exitHdr(ParseRulesParser::HdrContext *ctx) override;

    virtual void enterNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override;

    virtual void exitNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override;
};