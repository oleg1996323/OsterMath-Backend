#include "types.h"
#include "data.h"
#include "arithmetic_tree.h"
#include "arithmetic_types.h"
#include "expr_listener.h"

using namespace std::string_view_literals;

void BaseListener::enterVardefinition(ParseRulesParser::VardefinitionContext * ctx){
    mode_.push(MODE::VARDEF);
    current_var_ = data_base_->add_variable(ctx->VARIABLE()->getText()).get();
    if(!current_var_->is_undef())
        current_var_->get()=std::monostate();
}

void BaseListener::exitVardefinition(ParseRulesParser::VardefinitionContext * ctx){ 
    assert(mode_.top()==MODE::VARDEF);
    current_var_=nullptr;
    mode_.pop();
}

// __I__=__J__+__C__
// __J__=__C__+2000
// __C__=__A__
// __C__=__A__^2
// __A__=100

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        auto ptr = data_base_->add_variable(ctx->VARIABLE()->getText()).get();
        if(current_var_->is_arithmetic_tree())
            current_var_->get<ArithmeticTree>().insert(ptr->node());
        else if(current_var_->is_undef()){
            current_var_->get() = ArithmeticTree();
            current_var_->get<ArithmeticTree>().insert(ptr->node());
            assert(current_var_->is_arithmetic_tree());
        }
        else if(current_var_->is_value()){

        }
        else assert(false);
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
    }
    else if(mode_.top()==MODE::TABVALDEF){
        assert(current_var_->is_array());
        current_var_->get<Array_t>().push_back(ctx->ADD()?1:-1);
    }
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
    if(mode_.top()==MODE::VARDEF){
        if(current_var_->is_value()){
            current_var_->get<Value_t>()*=ctx->ADD()?1:-1;
            assert(current_var_->is_value());
        }
    }
    return;
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        if(current_var_->is_undef()){
            current_var_->get()=Value_t(ctx->getText());
            return;
        }
        else if(!current_var_->is_arithmetic_tree()){
            throw std::invalid_argument("Invalid type of variable");
        }
        current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(Value_t(ctx->getText())));
    }
    return;
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

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    std::cout<<ctx->getText()<<std::endl;
    for(auto i:ctx->expr()){
        std::cout<<i->getText()<<std::endl;
    }
    assert(!mode_.empty() && current_var_);
    if(current_var_->is_value()){
        current_var_->value_to_tree();
        assert(current_var_->is_arithmetic_tree());
    }
    else if(current_var_->is_undef()){
        current_var_->get()=ArithmeticTree();
    }
    else if(!current_var_->is_arithmetic_tree()){
        throw std::invalid_argument("Invalid type of variable");
    }
    if(ctx->ADD())
        current_var_->get<ArithmeticTree>().insert(std::make_shared<BinaryNode>(BINARY_OP::ADD));
    else if(ctx->SUB())
        current_var_->get<ArithmeticTree>().insert(std::make_shared<BinaryNode>(BINARY_OP::SUB));
    else if(ctx->MUL())
        current_var_->get<ArithmeticTree>().insert(std::make_shared<BinaryNode>(BINARY_OP::MUL));
    else if(ctx->DIV())
        current_var_->get<ArithmeticTree>().insert(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    else
        current_var_->get<ArithmeticTree>().insert(std::make_shared<BinaryNode>(BINARY_OP::POW));
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