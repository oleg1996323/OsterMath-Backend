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
    else if(func_ctx->multiargfunction()){
        if(func_ctx->multiargfunction()->SUMPRODUCT())
            tmp_multiarg_node_.top() = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::SUMPRODUCT);
        else if(func_ctx->multiargfunction()->LOG_X())
            tmp_multiarg_node_.top() = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::LOG_BASE);
        else if(func_ctx->multiargfunction()->SUM())
            tmp_multiarg_node_.top() = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::SUM);
        else if(func_ctx->multiargfunction()->PRODUCT())
            tmp_multiarg_node_.top() = std::make_shared<MultiArgumentNode>(MULTI_ARG_OP::PROD);
        tree_input.insert(tmp_multiarg_node_.top());
        return;
    }
    else __assert_fail("func_ctx->function() == nullptr",__FILE__,__LINE__,__func__);
}

bool BaseListener::is_header_definition() const{
    return !mode_.empty() && mode_.top()==MODE::HDRDEF;
}

bool BaseListener::is_multiarg_operation() const{
    return !mode_.empty() && mode_.top()==MODE::MULTIARGOPERATION;
}

bool BaseListener::is_table_values_definition() const{
    return !mode_.empty() && mode_.top()==MODE::TABVALDEF;
}

bool BaseListener::is_variable_definition() const{
    return !mode_.empty() && mode_.top()==MODE::VARDEF;
}

bool BaseListener::is_range_operation() const{
    return !mode_.empty() && mode_.top()==MODE::RANGEOPERATION;
}

void BaseListener::__insert_to_variable__(const std::shared_ptr<Node>& node) const{
    if(current_var_->is_undef())
        current_var_->get() = ArithmeticTree();

    if(current_var_->is_arithmetic_tree())
        current_var_->get<ArithmeticTree>().insert(node);
    else if(current_var_->is_value()){
        current_var_->value_to_tree();
        current_var_->get<ArithmeticTree>().insert(node);
    }
    else if (current_var_->is_array()){
        current_var_->get<Array_t>().define_back(node);
    } //может быть выражением
}

void BaseListener::__insert_to_variable__(std::string&& node) const{
    if(current_var_->is_undef())
        current_var_->get()=node;
    else throw std::runtime_error("Variable already defined");
}

void BaseListener::__insert_to_variable__(Value_t&& val) const{
    if(current_var_->is_undef())
        current_var_->get()=val;
    else if(current_var_->is_arithmetic_tree())
        __insert_to_variable__(std::make_shared<ValueNode>(val));
    else if(current_var_->is_array())
        current_var_->get<Array_t>().define_back(val);
    else
        throw std::runtime_error("Variable already defined");
    
}

void BaseListener::__insert_to_range_operation__(const std::shared_ptr<Node>& node) const{
    tmp_range_node_.top()->expression().insert(node);
}

void BaseListener::__insert_to_multiarg_operation__(const std::shared_ptr<Node>& node) const{
    tmp_multiarg_node_.top()->add_child(node.get());
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

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
    VariableBase* ptr = data_base_->add_variable(ctx->VARIABLE()->getText()).get();
    if(is_variable_definition()){
        __insert_to_variable__(ptr->node());
    }
    else if(is_range_operation()){
        __insert_to_range_operation__(ptr->node());
        tmp_range_node_.top()->add_child(ptr->node().get());
    }
    else if(is_multiarg_operation()){
        __insert_to_multiarg_operation__(ptr->node());
    }
    else throw std::runtime_error("Error when variable inserted");
}

void BaseListener::enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) {
    assert(!mode_.empty());
    if(is_variable_definition()){
        if(current_var_->is_arithmetic_tree())
            current_var_->get<ArithmeticTree>().insert(std::make_shared<UnaryNode>(ctx->ADD()?UNARY_OP::ADD:UNARY_OP::SUB));
        else throw std::runtime_error("Error when unary operator added to expression");
    }
    else if(is_table_values_definition()){
        assert(current_var_->is_array());
        current_var_->get<Array_t>().define_back(ctx->ADD()?1:-1);
    }
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
    if(is_variable_definition()){
        if(current_var_->is_value()){
            current_var_->get<Value_t>()*=ctx->ADD()?1:-1;
            assert(current_var_->is_value());
        }
    }
    return;
}

void BaseListener::enterLiteral(ParseRulesParser::LiteralContext *ctx) {
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

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(ParseRulesParser::ConstantContext *ctx) {
    if(is_variable_definition()){
        if(current_var_->is_value()){
            if(ctx->EXP()){
                if(current_var_->is_value())
                    current_var_->get()=boost::math::constants::e<Value_t>();
                else if(current_var_->is_arithmetic_tree())
                    current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
                else if(current_var_->is_array())
                    current_var_->get<Array_t>().define_back(boost::math::constants::e<Value_t>());
            }
            else if(ctx->PI()){
                if(current_var_->is_value())
                    current_var_->get()=boost::math::constants::pi<Value_t>();
                else if(current_var_->is_arithmetic_tree())
                    current_var_->get<ArithmeticTree>().insert(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
                else if(current_var_->is_array())
                    current_var_->get<Array_t>().define_back(boost::math::constants::pi<Value_t>());
            }
            else
                throw std::runtime_error("Error parsing constant");
            return;
        }
    }
    else if(is_range_operation()){
        if(ctx->EXP()){
            __insert_to_range_operation__(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
        }
        else if(ctx->PI()){
            __insert_to_range_operation__(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
        }
        else throw std::runtime_error("Error when constant added to range expression");
    }
    else throw std::runtime_error("Error when added constant value");
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {
    return;
}

//a function parser for definition any callback function for further calculations
//{for example: Lg(sumproduct(__Ivs__, __n__))}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    //entering in the arithmetictree of range_function
    if(is_range_operation()){
        if(ctx->ADD())
            __insert_to_range_operation__(std::make_shared<BinaryNode>(BINARY_OP::ADD));
        else if(ctx->SUB())
            __insert_to_range_operation__(std::make_shared<BinaryNode>(BINARY_OP::SUB));
        else if(ctx->MUL())
            __insert_to_range_operation__(std::make_shared<BinaryNode>(BINARY_OP::MUL));
        else if(ctx->DIV())
            __insert_to_range_operation__(std::make_shared<BinaryNode>(BINARY_OP::DIV));
        else
            __insert_to_range_operation__(std::make_shared<BinaryNode>(BINARY_OP::POW));
        return;
    }
    else if(is_variable_definition()){
        if(ctx->ADD())
            __insert_to_variable__(std::make_shared<BinaryNode>(BINARY_OP::ADD));
        else if(ctx->SUB())
            __insert_to_variable__(std::make_shared<BinaryNode>(BINARY_OP::SUB));
        else if(ctx->MUL())
            __insert_to_variable__(std::make_shared<BinaryNode>(BINARY_OP::MUL));
        else if(ctx->DIV())
            __insert_to_variable__(std::make_shared<BinaryNode>(BINARY_OP::DIV));
        else
            __insert_to_variable__(std::make_shared<BinaryNode>(BINARY_OP::POW));
        return;
    }
    else throw std::runtime_error("Invalid input binary operation");
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
    if(is_variable_definition()){
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
    assert(ctx);
    mode_.push(MODE::RANGEOPERATION);
    if(ctx->SUM_I())
        tmp_range_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::SUM));
    else if(ctx->PRODUCT_I())
        tmp_range_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::PROD));
    else throw std::invalid_argument("Invalid type of function");
    assert(tmp_range_node_.top()->type()==ARITHM_NODE_TYPE::RANGEOP);
}

void BaseListener::exitRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    assert(!tmp_range_node_.empty());
    assert(!mode_.empty());
    assert(mode_.top()==MODE::RANGEOPERATION);
    mode_.pop();
    std::shared_ptr<RangeOperationNode> ptr = tmp_range_node_.top();
    assert(ptr->type()==ARITHM_NODE_TYPE::RANGEOP);
    tmp_range_node_.pop();
    assert(ptr->type()==ARITHM_NODE_TYPE::RANGEOP);
    if(is_variable_definition()){
        assert(!mode_.empty() && mode_.top()==MODE::VARDEF);
        assert(ptr->type()==ARITHM_NODE_TYPE::RANGEOP);
        __insert_to_variable__(ptr);
    }
    else if(is_range_operation()){
        assert(!mode_.empty() && mode_.top()==MODE::RANGEOPERATION);
        __insert_to_range_operation__(ptr);
    }
    else if(is_multiarg_operation()){
        assert(!mode_.empty() && mode_.top()==MODE::MULTIARGOPERATION);
        __insert_to_multiarg_operation__(ptr);
    }
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext* ctx){
    if(is_range_operation()){
        __insert_to_range_operation__(std::make_shared<ValueNode>(ctx->getText()));
        return;
    }
    else if(is_variable_definition())
        __insert_to_variable__(std::move(Value_t(ctx->getText())));
    else if(is_multiarg_operation() && !tmp_multiarg_node_.top()->is_array_function())
        __insert_to_multiarg_operation__(std::make_shared<ValueNode>(ctx->getText()));
    else throw std::runtime_error("Unknown parsing type");
    return;
}

void BaseListener::enterMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    mode_.push(MODE::MULTIARGOPERATION);
    if(ctx->LOG_X())
        tmp_multiarg_node_.push(std::make_unique<MultiArgumentNode>(MULTI_ARG_OP::LOG_BASE));
    else if(ctx->PRODUCT())
        tmp_multiarg_node_.push(std::make_unique<MultiArgumentNode>(MULTI_ARG_OP::PROD));
    else if(ctx->SUMPRODUCT())
        tmp_multiarg_node_.push(std::make_unique<MultiArgumentNode>(MULTI_ARG_OP::SUMPRODUCT));
    else if(ctx->SUM())
        tmp_multiarg_node_.push(std::make_unique<MultiArgumentNode>(MULTI_ARG_OP::SUM));
}

void BaseListener::exitMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    mode_.pop();
    std::shared_ptr<MultiArgumentNode> ptr = tmp_multiarg_node_.top();
    tmp_multiarg_node_.pop();
    if(is_variable_definition())
        __insert_to_variable__(ptr);
    else if(is_range_operation())
        __insert_to_range_operation__(ptr);
    else if(is_multiarg_operation())
        __insert_to_multiarg_operation__(ptr);
}

void BaseListener::exitNumber(ParseRulesParser::NumberContext* ctx){

}