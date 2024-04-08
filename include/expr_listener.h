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
    enum class ModeBase{
        IN_FUNCTION,
        IN_VAR,
        IN_NUMBER,
        IN_CONST
    };

    public:

    protected:
    virtual void enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) override{

    }

    virtual void exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx) override {
        
    }

    virtual void enterVariable(ParseRulesParser::VariableContext *ctx) override{
        if(!data_.Exists(ctx->getText()))
            data_.AddVariable(ctx->getText());
        else throw VariableAlreadyExists("Variable " + ctx->getText() + " already registred");
    }

    virtual void exitVariable(ParseRulesParser::VariableContext *ctx) override{
        
    }

    virtual void enterNumber(ParseRulesParser::NumberContext *ctx) override{
        
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

    uint8_t parens_count = 0;
    
    std::unordered_set<std::string_view> var_names_;

    BaseData data_;
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