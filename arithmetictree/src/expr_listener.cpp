#include "types.h"
#include "data.h"
#include "arithmetic_tree.h"
#include "arithmetic_types.h"
#include "expr_listener.h"

using namespace std::string_view_literals;

void BaseListener::__function_input__(ArithmeticTree& tree_input,ParseRulesParser::FunctionCallContext* func_ctx){
    if(func_ctx->function()){
        if(func_ctx->function()->EXP())
            tree_input.insert(std::make_shared<UnaryNode>(UNARY_OP::EXP));
        else if(func_ctx->function()->LG())
            tree_input.insert(std::make_shared<UnaryNode>(UNARY_OP::LG10));
        else if(func_ctx->function()->LN())
            tree_input.insert(std::make_shared<UnaryNode>(UNARY_OP::LN));
        else throw std::invalid_argument("Unknown input of function context");
    }
    else __assert_fail("func_ctx->function() == nullptr",__FILE__,__LINE__,__func__);
}

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
    auto ptr = data_base_->add_variable(ctx->VARIABLE()->getText()).get();
    if(mode_.top()==MODE::VARDEF){
        if(!tmp_multiarg_node_){
            if(current_var_->is_arithmetic_tree())
                current_var_->get<ArithmeticTree>().insert(ptr->node());
            else if(current_var_->is_undef()){
                current_var_->get() = ArithmeticTree();
                current_var_->get<ArithmeticTree>().insert(ptr->node());
                assert(current_var_->is_arithmetic_tree());
            }
            else if(current_var_->is_value()){
                current_var_->value_to_tree();
                current_var_->get<ArithmeticTree>().insert(ptr->node());
                assert(current_var_->is_arithmetic_tree());
            }
            else if (current_var_->is_array())
                current_var_->get<Array_t>().define_back(data_base_->add_variable(ctx->VARIABLE()->getText()).get());
        }
        else{
            tmp_multiarg_node_->add_child(ptr->node().get());
        }
    }
    else {
        assert(mode_.top()==MODE::HDRDEF);
        //hdr_vars_.push_back(data_base_->add_variable(ctx->VARIABLE()->getSymbol()->getText(), Array_t()).get());
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
        current_var_->get<Array_t>().define_back(ctx->ADD()?1:-1);
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

void BaseListener::enterLiteral(ParseRulesParser::LiteralContext *ctx) {
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        // if(ctx->number()){
        //     if(current_var_->is_undef()){
        //         current_var_->get()=Value_t(ctx->getText());
        //         return;
        //     }
        //     else if(current_var_->is_array())
        //         return;
        //     else if(!current_var_->is_arithmetic_tree()){
        //         throw std::invalid_argument("Invalid type of variable");
        //     }
        //     //std::cout<<ctx->getText()<<std::endl;
        //     current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(ctx->getText()));
        // }
        // else if(ctx->constant()){
        //     if(current_var_->is_undef()){
        //         current_var_->get()=Value_t();
        //         return;
        //     }
        //     else if(current_var_->is_array())
        //         return;
        //     else if(!current_var_->is_arithmetic_tree()){
        //         throw std::invalid_argument("Invalid type of variable");
        //     }
        // }
    }
    return;
}

void BaseListener::exitLiteral(ParseRulesParser::LiteralContext *ctx) {
    return;
}

void BaseListener::enterParens(ParseRulesParser::ParensContext *ctx) {
    return;
}

void BaseListener::exitParens(ParseRulesParser::ParensContext *ctx) {
    return;
}

/*
__I__=[__A__,__B__]
__A__=sumproduct(__C__,__D__)
__B__=2
__C__=[2,2,2]
__D__=[2,2,2]
*/

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(ParseRulesParser::ConstantContext *ctx) {
    //std::cout<<ctx->getText()<<std::endl;
    if(current_var_->is_value()){
        if(ctx->EXP())
            current_var_->get()=boost::math::constants::e<Value_t>();
        else if(ctx->PI())
            current_var_->get()=boost::math::constants::pi<Value_t>();
        return;
    }
    else if(current_var_->is_arithmetic_tree()){
        if(ctx->EXP())
            current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
        else if(ctx->PI())
            current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
        return;
    }
    else if(current_var_->is_array()){
        if(ctx->EXP())
            current_var_->get<Array_t>().define_back(boost::math::constants::e<Value_t>());
        else if(ctx->PI())
            current_var_->get<Array_t>().define_back(boost::math::constants::pi<Value_t>());
        return;
    }
    else
        throw std::runtime_error("Error parsing constant");
    return;
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {
    return;
}

//a function parser for definition any callback function for further calculations
//{for example: Lg(sumproduct(__Ivs__, __n__))}
void BaseListener::enterFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    assert(!mode_.empty() && current_var_);
    if(!tmp_range_node_.empty()){
        __function_input__(tmp_range_node_.top()->expression(),ctx);
    }

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
    if(ctx->function()){
        __function_input__(current_var_->get<ArithmeticTree>(),ctx);
    }
    else if(ctx->multiargfunction()){
        if(ctx->multiargfunction()->SUMPRODUCT())
            tmp_multiarg_node_ = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::SUMPRODUCT);
        else if(ctx->multiargfunction()->LOG_X())
            tmp_multiarg_node_ = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::LOG_BASE);
        return;
    }
}

void BaseListener::exitFunctionCall(ParseRulesParser::FunctionCallContext *ctx) {
    if(ctx->multiargfunction() && tmp_multiarg_node_){
        current_var_->get<ArithmeticTree>().insert(tmp_multiarg_node_);
        tmp_multiarg_node_.reset();
    }
    return;
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    assert(!mode_.empty() && current_var_);

    //entering in the arithmetictree of range_function
    if(!tmp_range_node_.empty()){
        if(ctx->ADD())
            tmp_range_node_.top()->expression().insert(std::make_shared<BinaryNode>(BINARY_OP::ADD));
        else if(ctx->SUB())
            tmp_range_node_.top()->expression().insert(std::make_shared<BinaryNode>(BINARY_OP::SUB));
        else if(ctx->MUL())
            tmp_range_node_.top()->expression().insert(std::make_shared<BinaryNode>(BINARY_OP::MUL));
        else if(ctx->DIV())
            tmp_range_node_.top()->expression().insert(std::make_shared<BinaryNode>(BINARY_OP::DIV));
        else
            tmp_range_node_.top()->expression().insert(std::make_shared<BinaryNode>(BINARY_OP::POW));
        return;
    }

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

/*
__I__=SUMPRODUCT(__A__,__B__)
__A__=[2,2,2]
__B__=[2,2,2]*/

void BaseListener::enterItemArray(ParseRulesParser::ItemArrayContext *ctx){
    assert(!mode_.empty());
    if(mode_.top()==MODE::VARDEF){
        assert(current_var_->is_array());
            current_var_->get<Array_t>().push_back(Array_val());
        return;
    }
}

void BaseListener::exitItemArray(ParseRulesParser::ItemArrayContext *ctx){

}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(ParseRulesParser::ArrayContext *ctx) {
    assert(!mode_.empty() && current_var_);
    if(mode_.top()==MODE::VARDEF){
        if(current_var_->is_undef())
            current_var_->get()=Array_t(current_var_);
        else throw std::invalid_argument("Invalid type of variable");
    }
    return;
}

void BaseListener::exitArray(ParseRulesParser::ArrayContext *ctx) {
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

void BaseListener::enterRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    if(ctx->SUM_I())
        tmp_range_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::SUM));
    else if(ctx->SUMPRODUCT_I())
        tmp_range_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::SUMPRODUCT));
    else if(ctx->PRODUCT_I())
        tmp_range_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::PROD));
    else throw std::invalid_argument("Invalid type of function");
}

void BaseListener::exitRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    assert(!tmp_range_node_.empty() && current_var_);
    if(tmp_range_node_.size()>1){ //if the range function in other range function
        std::shared_ptr<RangeOperationNode>& node = tmp_range_node_.top();
        tmp_range_node_.pop();
        tmp_range_node_.top()->expression().insert(node);
    }
    else{   //if the range function in variable definition or array input
        if(current_var_->is_undef())
            current_var_->get() = ArithmeticTree();

        if(current_var_->is_arithmetic_tree())
            current_var_->get<ArithmeticTree>().insert(tmp_range_node_.top());
        else if(current_var_->is_value()){
            current_var_->value_to_tree();
            current_var_->get<ArithmeticTree>().insert(tmp_range_node_.top());
        }
        else if (current_var_->is_array()){
            if(current_var_->get<Array_t>().back().is_expression())
            current_var_->get<Array_t>().back().get<ArithmeticTree>().insert(tmp_range_node_.top());
        } //может быть выражением
        tmp_range_node_.pop();
    }
}

void BaseListener::enterVariable_range_input(ParseRulesParser::Variable_range_inputContext* ctx){
    
}

void BaseListener::exitVariable_range_input(ParseRulesParser::Variable_range_inputContext* ctx){

}

void BaseListener::enterNumber(ParseRulesParser::NumberContext* ctx){
    //entering in the arithmetictree of range_function
    if(!tmp_range_node_.empty()){
        tmp_range_node_.top()->expression().insert(std::make_shared<ValueNode>(ctx->getText()));
        return;
    }

    //entering in simple var definition
    if(current_var_->is_undef()){
        current_var_->get()=Value_t(ctx->getText());
        return;
    }
    else if(current_var_->is_arithmetic_tree()){
            current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(ctx->getText()));
        return;
    }
    else if(current_var_->is_array()){
        if(current_var_->get<Array_t>().back().is_undef())
            current_var_->get<Array_t>().back() = Value_t(ctx->getText());
        else if(current_var_->get<Array_t>().back().is_expression())
            current_var_->get<Array_t>().back().get<ArithmeticTree>().insert(std::make_shared<ValueNode>(ctx->getText()));
        else assert(false);
        return;
    }
    else
        throw std::runtime_error("Error parsing constant");
    return;
}

void BaseListener::exitNumber(ParseRulesParser::NumberContext* ctx){

}