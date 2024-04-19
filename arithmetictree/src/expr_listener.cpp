#include "types.h"
#include "data.h"
#include "arithmetic_tree.h"
#include "arithmetic_types.h"
#include "expr_listener.h"

using namespace std::string_view_literals;

void BaseListener::enterVardefinition(ParseRulesParser::VardefinitionContext * ctx){
    mode_.push(MODE::VARDEF);
}

void BaseListener::exitVardefinition(ParseRulesParser::VardefinitionContext * ctx){ 
    assert(mode_.top()==MODE::VARDEF);
    current_var_=""sv;
    mode_.pop();
}

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF)
        current_var_ = data_base_->add_variable(ctx->VARIABLE()->getSymbol()->getText())->name();
    else {
        assert(mode_.top()==MODE::HDRDEF);
        hdr_vars_.push_back(data_base_->add_variable(ctx->VARIABLE()->getSymbol()->getText())->name());

    }
}

void BaseListener::enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) {
    assert(!mode_.empty());
    if(ctx->ADD()){
        if(mode_.top()==MODE::VARDEF)
            if(data_base_->get(current_var_)->is_arithmetic_tree())
                data_base_->get(current_var_)->get<ArithmeticTree>().insert(std::make_shared<UnaryNode>(UNARY_OP::ADD));
    }
    else{

    }
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
    
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext *ctx) {

}

void BaseListener::exitNumber(ParseRulesParser::NumberContext *ctx) {
    
}

void BaseListener::enterParens(ParseRulesParser::ParensContext *ctx) {

}

void BaseListener::exitParens(ParseRulesParser::ParensContext *ctx) {
    
}

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(ParseRulesParser::ConstantContext *ctx) {
    
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {

}

//a function parser for definition any callback function for further calculations
//{for example: Lg(sumproduct(__Ivs__, __n__))}
void BaseListener::enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    
}

void BaseListener::exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    
}

//power operator {for example: __Ivs__^__j12__}
void BaseListener::enterPowerOp(ParseRulesParser::PowerOpContext *ctx) {

}

void BaseListener::exitPowerOp(ParseRulesParser::PowerOpContext *ctx) {
    
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    if(ctx->ADD())
        return;
}

void BaseListener::exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {

}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(ParseRulesParser::ArrayContext *ctx) {
    //unnamed variable
}

void BaseListener::exitArray(ParseRulesParser::ArrayContext *ctx) {
    //unnamed variable
}

//natural logarithm function {for example: Ln(Expr)}
void BaseListener::enterNatlog(ParseRulesParser::NatlogContext *ctx) {

}

void BaseListener::exitNatlog(ParseRulesParser::NatlogContext *ctx) {

}

//decimal logarithm function {for example: Lg(Expr)}
void BaseListener::enterDeclog(ParseRulesParser::DeclogContext *ctx) {

}

void BaseListener::exitDeclog(ParseRulesParser::DeclogContext *ctx) {
    
}

//based logarithm function {for example: Log(Expr, Expr)}
void BaseListener::enterBaselog(ParseRulesParser::BaselogContext *ctx) {
    
}

void BaseListener::exitBaselog(ParseRulesParser::BaselogContext *ctx) {
    
}

//exponent function {for example: Exp(Expr)}
void BaseListener::enterExponent(ParseRulesParser::ExponentContext *ctx) {

}

void BaseListener::exitExponent(ParseRulesParser::ExponentContext *ctx) {
    
}

//root square function {for example: Sqrt(Expr)}
void BaseListener::enterSquareroot(ParseRulesParser::SquarerootContext *ctx) {
    
}

void BaseListener::exitSquareroot(ParseRulesParser::SquarerootContext *ctx) {

}

//sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
//Variables are accepted, if are implemented as arrays.
void BaseListener::enterSumproduct(ParseRulesParser::SumproductContext *ctx) {

}

void BaseListener::exitSumproduct(ParseRulesParser::SumproductContext *ctx) {

}

void BaseListener::enterTable_definition(ParseRulesParser::Table_definitionContext* ctx) {
    mode_.push(MODE::TABLEDEF);
}

void BaseListener::exitTable_definition(ParseRulesParser::Table_definitionContext* ctx) {
    assert(mode_.top()==MODE::TABLEDEF);
    mode_.pop();
}

//a typical header whitespace or tab separated. Only Variables are accepted and then defined
//by corespondent parser rule.
void BaseListener::enterHdr(ParseRulesParser::HdrContext *ctx) {
    assert(mode_.top()==MODE::TABLEDEF);
    mode_.push(MODE::HDRDEF);
}

void BaseListener::exitHdr(ParseRulesParser::HdrContext *ctx) {
    assert(mode_.top()==MODE::HDRDEF);
    mode_.pop();
}

void BaseListener::enterNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) {
    assert(mode_.top()==MODE::TABLEDEF);
    mode_.push(MODE::TABVALDEF);
}

void BaseListener::exitNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) {
    assert(mode_.top()==MODE::TABVALDEF);
    mode_.pop();
}