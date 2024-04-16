#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "types.h"
#include "data.h"

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

class BaseListener: public ParseRulesBaseListener{
    enum class MODE{
        VARDEF,
        HDRDEF,
        TABLEDEF,
        TABVALDEF
    };

    BaseData* data_base_;
    mutable std::string_view current_var_;
    std::vector<std::string_view> hdr_vars_; 
    std::stack<MODE> mode_;

    public:
    BaseListener(BaseData* data_base):
    data_base_(data_base)
    {}

    private:
    virtual void enterVardefinition(ParseRulesParser::VardefinitionContext * ctx) override {
        mode_.push(MODE::VARDEF);
    }
    
    virtual void exitVardefinition(ParseRulesParser::VardefinitionContext * ctx) override { 
        assert(mode_.top()==MODE::VARDEF);
        current_var_=""sv;
        mode_.pop();
    }

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) override{
        assert(!mode_.empty());
        if(mode_.top()==MODE::VARDEF)
            current_var_ = data_base_->AddVariable(ctx->VARIABLE()->getSymbol()->getText())->GetName();
        else {
            assert(mode_.top()==MODE::HDRDEF);
            hdr_vars_.push_back(data_base_->AddVariable(ctx->VARIABLE()->getSymbol()->getText())->GetName());

        }
    }

    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) override{
        assert(!mode_.empty());
        if(ctx->ADD()){
            if(mode_.top()==MODE::VARDEF)
                if(data_base_->GetVar(current_var_)->is_arithmetic_tree())
                data_base_->GetVar()->;
        }
        else{

        }
    }

    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx) override {
        
    }

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx) override{

    }

    virtual void exitNumber(ParseRulesParser::NumberContext *ctx) override{
        
    }
    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx) override{

    }

    virtual void exitParens(ParseRulesParser::ParensContext *ctx) override{
        
    }

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(ParseRulesParser::ConstantContext *ctx) override{
        
    }

    virtual void exitConstant(ParseRulesParser::ConstantContext *ctx) override{

    }

    //a function parser for definition any callback function for further calculations
    //{for example: Lg(sumproduct(__Ivs__, __n__))}
    virtual void enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override{
        
    }

    virtual void exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) override{
        
    }

    //power operator {for example: __Ivs__^__j12__}
    virtual void enterPowerOp(ParseRulesParser::PowerOpContext *ctx) override{

    }

    virtual void exitPowerOp(ParseRulesParser::PowerOpContext *ctx) override{
        
    }

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override{
        iif(ctx->ADD())

    }

    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override{

    }

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) override{
        //unnamed variable
    }

    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) override{
        //unnamed variable
    }

    //natural logarithm function {for example: Ln(Expr)}
    virtual void enterNatlog(ParseRulesParser::NatlogContext *ctx) override{

    }

    virtual void exitNatlog(ParseRulesParser::NatlogContext *ctx) override{

    }

    //decimal logarithm function {for example: Lg(Expr)}
    virtual void enterDeclog(ParseRulesParser::DeclogContext *ctx) override{

    }

    virtual void exitDeclog(ParseRulesParser::DeclogContext *ctx) override{
        
    }

    //based logarithm function {for example: Log(Expr, Expr)}
    virtual void enterBaselog(ParseRulesParser::BaselogContext *ctx) override{
        
    }

    virtual void exitBaselog(ParseRulesParser::BaselogContext *ctx) override{
        
    }

    //exponent function {for example: Exp(Expr)}
    virtual void enterExponent(ParseRulesParser::ExponentContext *ctx) override{

    }

    virtual void exitExponent(ParseRulesParser::ExponentContext *ctx) override{
        
    }

    //root square function {for example: Sqrt(Expr)}
    virtual void enterSquareroot(ParseRulesParser::SquarerootContext *ctx) override{
        
    }

    virtual void exitSquareroot(ParseRulesParser::SquarerootContext *ctx) override{

    }

    //sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
    //Variables are accepted, if are implemented as arrays.
    virtual void enterSumproduct(ParseRulesParser::SumproductContext *ctx) override{

    }

    virtual void exitSumproduct(ParseRulesParser::SumproductContext *ctx) override{

    }

    virtual void enterTable_definition(ParseRulesParser::Table_definitionContext* ctx) override{
        mode_.push(MODE::TABLEDEF);
    }

    virtual void exitTable_definition(ParseRulesParser::Table_definitionContext* ctx) override{
        assert(mode_.top()==MODE::TABLEDEF);
        mode_.pop();
    }

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx) override{
        assert(mode_.top()==MODE::TABLEDEF);
        mode_.push(MODE::HDRDEF);
    }

    virtual void exitHdr(ParseRulesParser::HdrContext *ctx) override{
        assert(mode_.top()==MODE::HDRDEF);
        mode_.pop();
    }

    virtual void enterNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override{
        assert(mode_.top()==MODE::TABLEDEF);
        mode_.push(MODE::TABVALDEF);
    }

    virtual void exitNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) override{
        assert(mode_.top()==MODE::TABVALDEF);
        mode_.pop();
    }
};