#include "types.h"
#include "data.h"
#include "arithmetic_tree.h"
#include "arithmetic_types.h"
#include "expr_listener.h"

using namespace std::string_view_literals;

void BaseListener::enterVardefinition(ParseRulesParser::VardefinitionContext * ctx){
    mode_.push(MODE::VARDEF);
    current_var_ = data_base_->add_variable(ctx->VARIABLE()->getText()).get();
}

void BaseListener::exitVardefinition(ParseRulesParser::VardefinitionContext * ctx){ 
    assert(mode_.top()==MODE::VARDEF);
    current_var_=nullptr;
    mode_.pop();
}

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        auto ptr = data_base_->add_variable(ctx->VARIABLE()->getSymbol()->getText()).get();
        if(current_var_->is_arithmetic_tree())
            current_var_->get<ArithmeticTree>().insert(std::shared_ptr<VariableNode>(ptr));
        else if(current_var_->is_undef()){
            current_var_->get() = ArithmeticTree();
            current_var_->get<ArithmeticTree>().insert(std::shared_ptr<VariableNode>(ptr));
            assert(current_var_->is_arithmetic_tree());
        }
        else if(current_var_->is_value()){

        }
        else assert(false);
        // else if(current_var_->is_value()){
        //     //Value_t val_buf;
        //     //current_var_->get() = ArithmeticTree();
        //     //assert(current_var_->is_arithmetic_tree());
        //     assert(false);
        //     //current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(std::move(val_buf)));
        // }
    }
    else {
        assert(mode_.top()==MODE::HDRDEF);
        hdr_vars_.push_back(data_base_->add_variable(ctx->VARIABLE()->getSymbol()->getText(), Array_t()).get());
    }
}

void BaseListener::enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        if(current_var_->is_arithmetic_tree())
            current_var_->get<ArithmeticTree>().insert(std::make_shared<UnaryNode>(ctx->ADD()?UNARY_OP::ADD:UNARY_OP::SUB));
        else if(current_var_->is_undef()){
            current_var_->get() = ctx->ADD()?1:-1;
            assert(current_var_->is_value());
        }
        else assert(false);
        // else if(current_var_->is_value()){
        //     //Value_t val_buf;
        //     //current_var_->get() = ArithmeticTree();
        //     //assert(current_var_->is_arithmetic_tree());
        //     assert(false);
        //     //current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(std::move(val_buf)));
        // }
    }
    else if(mode_.top()==MODE::TABVALDEF){
        assert(current_var_->is_array());
        current_var_->get<Array_t>().push_back(ctx->ADD()?1:-1);
    }
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
    return;
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext *ctx) {
    assert(!mode_.empty());
    // if(current_var_->is_arithmetic_tree())
    //         current_var_->get<ArithmeticTree>().insert(std::make_shared<UnaryNode>(ctx->ADD()?UNARY_OP::ADD:UNARY_OP::SUB));
    //     else if(current_var_->is_undef()){
    //         current_var_->get() = ctx->ADD()?1:-1;
    //         assert(current_var_->is_value());
    //     }
    //     else assert(false);
    //     // else if(current_var_->is_value()){
    //     //     //Value_t val_buf;
    //     //     //current_var_->get() = ArithmeticTree();
    //     //     //assert(current_var_->is_arithmetic_tree());
    //     //     assert(false);
    //     //     //current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(std::move(val_buf)));
    //     // }
    // else if(mode_.top()==MODE::TABVALDEF){
    //     assert(current_var_->is_array());
    //     current_var_->get<Array_t>().push_back(ctx->ADD()?1:-1);
    // }
}

void BaseListener::exitNumber(ParseRulesParser::NumberContext *ctx) {
    return;
}

void BaseListener::enterParens(ParseRulesParser::ParensContext *ctx) {
    return;
}

void BaseListener::exitParens(ParseRulesParser::ParensContext *ctx) {
    return;
}

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(ParseRulesParser::ConstantContext *ctx) {
    return;
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {
    return;
}

//a function parser for definition any callback function for further calculations
//{for example: Lg(sumproduct(__Ivs__, __n__))}
void BaseListener::enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    return;
}

void BaseListener::exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    return;
}

//power operator {for example: __Ivs__^__j12__}
void BaseListener::enterPowerOp(ParseRulesParser::PowerOpContext *ctx) {
    return;
}

void BaseListener::exitPowerOp(ParseRulesParser::PowerOpContext *ctx) {
    return;
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    if(ctx->ADD())
        return;
}

void BaseListener::exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    return;
}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(ParseRulesParser::ArrayContext *ctx) {
    //unnamed variable
    return;
}

void BaseListener::exitArray(ParseRulesParser::ArrayContext *ctx) {
    //unnamed variable
    return;
}

//natural logarithm function {for example: Ln(Expr)}
void BaseListener::enterNatlog(ParseRulesParser::NatlogContext *ctx) {
    return;
}

void BaseListener::exitNatlog(ParseRulesParser::NatlogContext *ctx) {
    return;
}

//decimal logarithm function {for example: Lg(Expr)}
void BaseListener::enterDeclog(ParseRulesParser::DeclogContext *ctx) {
    return;
}

void BaseListener::exitDeclog(ParseRulesParser::DeclogContext *ctx) {
    return;
}

//based logarithm function {for example: Log(Expr, Expr)}
void BaseListener::enterBaselog(ParseRulesParser::BaselogContext *ctx) {
    return;
}

void BaseListener::exitBaselog(ParseRulesParser::BaselogContext *ctx) {
    return;
}

//exponent function {for example: Exp(Expr)}
void BaseListener::enterExponent(ParseRulesParser::ExponentContext *ctx) {
    return;
}

void BaseListener::exitExponent(ParseRulesParser::ExponentContext *ctx) {
    return;
}

//root square function {for example: Sqrt(Expr)}
void BaseListener::enterSquareroot(ParseRulesParser::SquarerootContext *ctx) {
    return;
}

void BaseListener::exitSquareroot(ParseRulesParser::SquarerootContext *ctx) {
    return;
}

//sum of production (for arrays) {for example: sumproduct(Expr, Expr, ...)}.
//Variables are accepted, if are implemented as arrays.
void BaseListener::enterSumproduct(ParseRulesParser::SumproductContext *ctx) {
    return;
}

void BaseListener::exitSumproduct(ParseRulesParser::SumproductContext *ctx) {
    return;
}

void BaseListener::enterTable_definition(ParseRulesParser::Table_definitionContext* ctx) {
    mode_.push(MODE::TABLEDEF);
    assert(line_counter_==0);
}

void BaseListener::exitTable_definition(ParseRulesParser::Table_definitionContext* ctx) {
    assert(mode_.top()==MODE::TABLEDEF);
    assert(line_counter_!=0);
    mode_.pop();
    line_counter_=0;
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
    assert(mode_.top()==MODE::TABLEDEF || mode_.top()==MODE::TABVALDEF);
    assert(col_counter_==0);
    if(mode_.top()==MODE::TABLEDEF)
        mode_.push(MODE::TABVALDEF);
    ++line_counter_;
}

void BaseListener::exitNumbers_line(ParseRulesParser::Numbers_lineContext* ctx) {
    assert(mode_.top()==MODE::TABVALDEF);
    assert(col_counter_==hdr_vars_.size()-1);
    mode_.pop();
}