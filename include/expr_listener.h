#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "types.h"
#include "data.h"
#include "function_proxy.h"

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
    FunctionProxy cur_function_;

    protected:

    enum class BASE_MODE{
        NONE,
        ADD,
        SUB,
        MUL,
        DIV,
        HDR,
        SUMPRODUCT,
        SQUAREROOT,
        EXPONENT,
        BASELOG,
        DECLOG,
        NATLOG,
        ARRAY,
        BINARY,
        POWER,
        FUNCTION,
        CONSTANT,
        NUMBER,
        VARIABLE,
        DEFINITION,
        UNARY_MINUS
    };

    public:

    BaseListener():mode_stack_({BASE_MODE::NONE}){}

    protected:
    virtual void enterVardefinition(ParseRulesParser::VardefinitionContext * ctx) override {
        mode_stack_.push(BASE_MODE::DEFINITION);
        //then enterVariable
        //then if not STRING, then enterFunction or enterConstant or enterNumber or enterParens or enterUnary
    }
    
    virtual void exitVardefinition(ParseRulesParser::VardefinitionContext * ctx) override { 
        if(ctx->STRING())
            data_.AddVariable(ctx->VARIABLE()->getText(),std::move(ctx->STRING()->getText()));
    }

    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) override{
        if(mode_stack_.top()==BASE_MODE::DEFINITION){
            if(ctx->ADD()){
                auto childs = ctx->children;
                if(childs.empty())
                    throw std::invalid_argument("Invalid definition "+std::string(last_var_name_tmp_));
                else
                    data_.Define(last_var_name_tmp_,[](){
                        
                    });
            }
            else{
                if(ctx->SUB())
                mode_stack_.push(BASE_MODE::UNARY_MINUS);
                
            }
        }
    }

    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx) override {
        
    }

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) override{
        assert(mode_stack_.top()==BASE_MODE::HDR || mode_stack_.top()==BASE_MODE::DEFINITION);
        data_.AddVariable(ctx->getText());

        if(data_.Defined(ctx->getText()) && mode_stack_.top()==BASE_MODE::DEFINITION)
            throw VariableAlreadyExists("Variable " + ctx->getText() + " already defined");

        if(mode_stack_.top()==BASE_MODE::HDR)
            header_vars_tmp_.emplace_back(ctx->getText());
        else {
            assert(last_var_name_tmp_.empty());
            last_var_name_tmp_ = ctx->getText();
        }
    }

    // virtual void exitVariable(ParseRulesParser::VariableContext *ctx) override{
        
    // }

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx) override{
        if(mode_stack_.top()==BASE_MODE::VARIABLE)
            
    }

    virtual void exitNumber(ParseRulesParser::NumberContext *ctx) override{
        
    }
    
    virtual void enterParens(ParseRulesParser::ParensContext *ctx) override{
        ++parens_count;
    }

    virtual void exitParens(ParseRulesParser::ParensContext *ctx) override{
        --parens_count;
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

    }

    virtual void exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) override{

    }

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(ParseRulesParser::ArrayContext *ctx) override{

    }

    virtual void exitArray(ParseRulesParser::ArrayContext *ctx) override{
        
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
        if(mode_stack_.top()==BASE_MODE::DEFINITION)

    }

    //based logarithm function {for example: Log(Expr, Expr)}
    virtual void enterBaselog(ParseRulesParser::BaselogContext *ctx) override{
        auto val_base = ctx->expr();
        if(val_base.size()!=2 )
            throw std::invalid_argument("Invalid input parameters");
        std::log(val_base.at(0), val_base.at(1));
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

    //a typical header whitespace or tab separated. Only Variables are accepted and then defined
    //by corespondent parser rule.
    virtual void enterHdr(ParseRulesParser::HdrContext *ctx) override{
        assert(!parens_count);
        assert(header_vars_tmp_.empty());
        mode_stack_.push(BASE_MODE::HDR);
    }

    virtual void exitHdr(ParseRulesParser::HdrContext *ctx) override{
        assert(!parens_count);
        assert(mode_stack_.top()==BASE_MODE::HDR);
    }

    //this methode permits to distingue the separation between any rules like variable-function match
    //or anything else
    virtual void enterEndLine(ParseRulesParser::EndLineContext *ctx) override {
        
    }

    virtual void exitEndLine(ParseRulesParser::EndLineContext *ctx) override {

    }

    uint8_t parens_count = 0;
    
    std::unordered_set<std::string_view> var_names_;

    BaseData data_;
    std::vector<VariableBase> header_vars_tmp_;
    std::stack<BASE_MODE> mode_stack_;
    std::string_view last_var_name_tmp_;
    std::optional<FunctionProxy> active_function_;
    //сделать как в spreadsheet
    
};