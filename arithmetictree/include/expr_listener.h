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

class BaseListener: public ParseRulesBaseListener{
    enum class MODE{
        VARDEF,
        HDRDEF,
        TABLEDEF,
        TABVALDEF
    };

    BaseData* data_base_;
    mutable VariableBase* current_var_;
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

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx) override;

    virtual void exitNumber(ParseRulesParser::NumberContext *ctx) override;
    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx) override;

    virtual void exitParens(ParseRulesParser::ParensContext *ctx) override;

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(ParseRulesParser::ConstantContext *ctx) override;

    virtual void exitConstant(ParseRulesParser::ConstantContext *ctx) override;

    //a function parser for definition any callback function for further calculations
    //{for example: Lg(sumproduct(__Ivs__, __n__))}
    virtual void enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override;

    virtual void exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override;

    //power operator {for example: __Ivs__^__j12__}
    virtual void enterPowerOp(ParseRulesParser::PowerOpContext *ctx) override;

    virtual void exitPowerOp(ParseRulesParser::PowerOpContext *ctx) override;

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override;

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) override;

    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) override;

    //natural logarithm function {for example: Ln(Expr)}
    virtual void enterNatlog(ParseRulesParser::NatlogContext *ctx) override;

    virtual void exitNatlog(ParseRulesParser::NatlogContext *ctx) override;

    //decimal logarithm function {for example: Lg(Expr)}
    virtual void enterDeclog(ParseRulesParser::DeclogContext *ctx) override;

    virtual void exitDeclog(ParseRulesParser::DeclogContext *ctx) override;

    //based logarithm function {for example: Log(Expr, Expr)}
    virtual void enterBaselog(ParseRulesParser::BaselogContext *ctx) override;

    virtual void exitBaselog(ParseRulesParser::BaselogContext *ctx) override;

    //exponent function {for example: Exp(Expr)}
    virtual void enterExponent(ParseRulesParser::ExponentContext *ctx) override;

    virtual void exitExponent(ParseRulesParser::ExponentContext *ctx) override;

    //root square function {for example: Sqrt(Expr)}
    virtual void enterSquareroot(ParseRulesParser::SquarerootContext *ctx) override;

    virtual void exitSquareroot(ParseRulesParser::SquarerootContext *ctx) override;

    //sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
    //Variables are accepted, if are implemented as arrays.
    virtual void enterSumproduct(ParseRulesParser::SumproductContext *ctx) override;

    virtual void exitSumproduct(ParseRulesParser::SumproductContext *ctx) override;

    virtual void enterTable_definition(ParseRulesParser::Table_definitionContext* ctx) override;

    virtual void exitTable_definition(ParseRulesParser::Table_definitionContext* ctx) override;

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx) override;

    virtual void exitHdr(ParseRulesParser::HdrContext *ctx) override;

    virtual void enterNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override;

    virtual void exitNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override;
};