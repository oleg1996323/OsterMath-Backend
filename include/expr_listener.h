#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include "def.h"
#include "ParseRulesBaseListener.h"
#include "types.h"
#include "data.h"

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

        
    }
    
    virtual void exitVardefinition(ParseRulesParser::VardefinitionContext * ctx) override { 

    }

    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) override{
        if(mode_stack_.top()==BASE_MODE::VARIABLE)
            if(ctx->ADD()){
                mode_stack_.push(BASE_MODE::DEFINITION);
            }
            else{
                if(ctx->SUB())
                mode_stack_.push(BASE_MODE::UNARY_MINUS);
                ctx->is
            }


    }

    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx) override {
        
    }

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) override{
        assert(mode_stack_.top()==BASE_MODE::NONE || mode_stack_.top()==BASE_MODE::HDR);
        if(!data_.AddVariable(ctx->getText()))
            throw VariableAlreadyExists("Variable " + ctx->getText() + " already registred");
        if(mode_stack_.top()==BASE_MODE::HDR)
            header_vars_tmp_.emplace_back(ctx->getText());
        else {
            mode_stack_.push(BASE_MODE::VARIABLE);
            last_var_name_tmp_ = ctx->getText();
        }
    }

    virtual void exitVariable(ParseRulesParser::VariableContext *ctx) override{

    }

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
};

class ZoneListener final: public BaseListener{
    public:
    ZoneListener():BaseListener(){

    }
    
    virtual void enterZone(ParseRulesParser::ZoneContext *ctx) override{

    }

    virtual void exitZone(ParseRulesParser::ZoneContext *ctx) override{

    }

    virtual void enterData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx) override{

    }

    virtual void exitData_bound_zone(ParseRulesParser::Data_bound_zoneContext *ctx) override{

    }

    virtual void enterConst_volume(ParseRulesParser::Const_volumeContext *ctx) override{

    }
    
    virtual void exitConst_volume(ParseRulesParser::Const_volumeContext *ctx) override{

    }

    virtual void enterVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx) override{

    }

    virtual void exitVirial_coefs_volume(ParseRulesParser::Virial_coefs_volumeContext *ctx) override{

    }

    virtual void enterValues_volume(ParseRulesParser::Values_volumeContext *ctx) override{

    }

    virtual void exitValues_volume(ParseRulesParser::Values_volumeContext *ctx) override{

    }

    virtual void enterBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx) override{

    }

    virtual void exitBound_equation_volume(ParseRulesParser::Bound_equation_volumeContext *ctx) override{
        
    }

    virtual void enterBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) override{

    }

    virtual void exitBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) override{

    }

    virtual void enterEquations_bound(ParseRulesParser::Equations_boundContext *ctx) override{

    }

    virtual void exitEquations_bound(ParseRulesParser::Equations_boundContext *ctx) override{

    }

    virtual void enterBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) override{

    }

    virtual void exitBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) override{

    }

    virtual void enterValues_bound(ParseRulesParser::Values_boundContext* ctx) override{

    }

    virtual void exitValues_bound(ParseRulesParser::Values_boundContext *ctx) override{

    }
};

class BoundTempListener final: public BaseListener{
    public:
    BoundTempListener():BaseListener(){

    }

    virtual void enterBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) override{

    }

    virtual void exitBound_temperature(ParseRulesParser::Bound_temperatureContext *ctx) override{

    }

    virtual void enterEquations_bound(ParseRulesParser::Equations_boundContext *ctx) override{

    }

    virtual void exitEquations_bound(ParseRulesParser::Equations_boundContext *ctx) override{

    }

    virtual void enterBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) override{

    }

    virtual void exitBound_coefs(ParseRulesParser::Bound_coefsContext *ctx) override{

    }

    virtual void enterValues_bound(ParseRulesParser::Values_boundContext* ctx) override{

    }

    virtual void exitValues_bound(ParseRulesParser::Values_boundContext *ctx) override{

    }   
};