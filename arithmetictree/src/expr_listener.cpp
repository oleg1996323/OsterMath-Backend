#include "types.h"
#include "data.h"
#include "arithmetic_types.h"
#include "expr_listener.h"
#include "exception.h"

using namespace std::string_view_literals;

void BaseListener::enterExpr(ParseRulesParser::ExprContext* ctx){
    mode_.push(MODE::EXPRESSION);
}

void BaseListener::exitExpr(ParseRulesParser::ExprContext* ctx){
    assert(!mode_.empty());
    assert(is_expression_definition());
}

bool BaseListener::is_function_operation() const{
    return !mode_.empty() && mode_.top()==MODE::FUNCTIONOPERATION;
}

bool BaseListener::is_variable_definition() const{
    return !mode_.empty() && mode_.top()==MODE::VARDEF;
}

bool BaseListener::is_range_operation() const{
    return !mode_.empty() && mode_.top()==MODE::RANGEOPERATION;
}

bool BaseListener::is_bounds_definition() const{
    return !mode_.empty() && mode_.top()==MODE::BOUND_DEFINITION;
}

bool BaseListener::is_expression_definition() const{
    return !mode_.empty() && mode_.top()==MODE::EXPRESSION;
}

bool BaseListener::is_array_definition() const{
    return !mode_.empty() && mode_.top()==MODE::ARRAY_DEFINITION;
}

bool BaseListener::is__array_item_definition() const{
    return !mode_.empty() && mode_.top()==MODE::ARRAY_ITEM_DEFINITION;
}

void BaseListener::__insert_to_prec_node__(MODE mode_assert_check){
    assert(mode_.top()==mode_assert_check);
    mode_.pop();
    assert(!anonymous_node_.empty());
    auto node = anonymous_node_.top();
    anonymous_node_.pop();
    assert(!anonymous_node_.empty());
    anonymous_node_.top()->insert(node);
}

BaseData* BaseListener::__insert_new_data_base__(std::string&& name){
    return data_base_->get_pool()->add_data(name);
}

void BaseListener::enterParens(ParseRulesParser::ParensContext* ctx){
    assert(!mode_.empty());
    mode_.push(MODE::EXPRESSION);
    if(ctx)
        anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::PARENS));
    else assert(false);
}

void BaseListener::exitParens(ParseRulesParser::ParensContext* ctx){
    __insert_to_prec_node__(MODE::EXPRESSION);
}

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
    mode_.push(MODE::VALUE);
    BaseData* db_tmp;
    if(ctx->DATABASE())
        db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
    else db_tmp = data_base_;

    VariableBase* ptr = db_tmp->add_variable(ctx->VARIABLE()->getText()).get();
    anonymous_node_.push(ptr->node());

    //unknown how to add node
}

void BaseListener::exitVariable(ParseRulesParser::VariableContext *ctx) {
    __insert_to_prec_node__(MODE::VALUE);
}

void BaseListener::enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) {
    assert(!mode_.empty());
    mode_.push(MODE::EXPRESSION);
    if(ctx->ADD())
        anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::ADD));
    else if(ctx->SUB())
        anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::SUB));
    else assert(false);
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
    __insert_to_prec_node__(MODE::EXPRESSION);
}

void BaseListener::enterLiteral(ParseRulesParser::LiteralContext *ctx) {
    return;
}

void BaseListener::exitLiteral(ParseRulesParser::LiteralContext *ctx) {
    return;
}

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(ParseRulesParser::ConstantContext *ctx) {
    assert(!mode_.empty());
    mode_.push(MODE::VALUE);
    if(ctx->EXP()){
        anonymous_node_.push(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
    }
    else if(ctx->PI()){
        anonymous_node_.push(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
    }
    else
        throw std::runtime_error("Error parsing constant");
    return;
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {
    __insert_to_prec_node__(MODE::VALUE);
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    assert(!mode_.empty());
    mode_.push(MODE::EXPRESSION);
    if(ctx->ADD())
        anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::ADD));
    else if(ctx->SUB())
        anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::SUB));
    else if(ctx->MUL())
        anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::MUL));
    else if(ctx->DIV())
        anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::DIV));
    else
        anonymous_node_.push(std::make_shared<BinaryNode>(BINARY_OP::POW));
    return;
}

void BaseListener::exitBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    __insert_to_prec_node__(MODE::EXPRESSION);
}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(ParseRulesParser::ArrayContext *ctx) {
    assert(!mode_.empty() && current_var_);
    anonymous_node_.push(std::make_shared<ArrayNode>(ctx->input_array().size()));
    mode_.push(MODE::ARRAY_DEFINITION);
}

void BaseListener::exitArray(ParseRulesParser::ArrayContext *ctx) {
    __insert_to_prec_node__(MODE::ARRAY_DEFINITION);
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext* ctx){
    assert(!mode_.empty());
    mode_.push(MODE::VALUE);
    anonymous_node_.push(std::make_shared<ValueNode>(ctx->getText()));
}

void BaseListener::exitNumber(ParseRulesParser::NumberContext* ctx){
    __insert_to_prec_node__(MODE::VALUE);
}

void BaseListener::enterMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    assert(!mode_.empty());
    mode_.push(MODE::MULTIARGFUNCTION);
    if(ctx->PRODUCT())
        anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::PROD,ctx->expr().size()));
    else if(ctx->SUMPRODUCT())
        anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SUMPRODUCT,ctx->expr().size()));
    else if(ctx->SUM())
        anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SUM,ctx->expr().size()));
}

void BaseListener::enterFunction(ParseRulesParser::FunctionContext* ctx){
    assert(!mode_.empty());
    mode_.push(MODE::FUNCTIONOPERATION);
    if(ctx){
        if(ctx->EXP())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::EXP));
        else if(ctx->LG())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LG10));
        else if(ctx->LN())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LN));
        else if(ctx->LOG_X())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LOG_BASE));
        else if(ctx->SIN())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SIN));
        else if(ctx->COS())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::COS));
        else if(ctx->ASIN())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ASIN));
        else if(ctx->ACOS())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ACOS));
        else if(ctx->FACTORIAL())
            anonymous_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::FACTORIAL));
        else throw std::invalid_argument("Unknown input of function context");
    }
}

void BaseListener::enterRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    assert(!mode_.empty());
    mode_.push(MODE::RANGEOPERATION);
    if(ctx->SUM_I())
        anonymous_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::SUM));
    else if(ctx->PRODUCT_I())
        anonymous_node_.push(std::make_shared<RangeOperationNode>(RANGE_OP::PROD));
    else throw std::invalid_argument("Invalid type of function");
}

void BaseListener::exitFunction(ParseRulesParser::FunctionContext* ctx){
    __insert_to_prec_node__(MODE::FUNCTIONOPERATION);
}

void BaseListener::exitMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    __insert_to_prec_node__(MODE::MULTIARGFUNCTION);
}

void BaseListener::exitRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    __insert_to_prec_node__(MODE::RANGEOPERATION);
}

void BaseListener::enterLess(ParseRulesParser::LessContext* ctx){
    assert(!mode_.empty());
    if(ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            //creating in other sheet
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
    }
    else assert(false);

    if(ctx->variable_parameter()){
        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            top_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),TOP_BOUND_T::LESS);
        else assert(false);
    }
    else assert(false);
}

void BaseListener::exitLess(ParseRulesParser::LessContext* ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::BOUND_DEFINITION);
    assert(anonymous_node_.size()==1);
}

void BaseListener::enterLess_equal(ParseRulesParser::Less_equalContext* ctx){
    assert(!mode_.empty());
    if(ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            //creating in other sheet
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
    }
    else assert(false);
    
    if(ctx->variable_parameter()){
        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            top_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),TOP_BOUND_T::LESS_OR_EQUAL);
        else assert(false);
    }
    else assert(false);
}

void BaseListener::exitLess_equal(ParseRulesParser::Less_equalContext* ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::BOUND_DEFINITION);
    assert(anonymous_node_.size()==1);
}

void BaseListener::enterLarger(ParseRulesParser::LargerContext* ctx){
    assert(!mode_.empty());
    if(ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            //creating in other sheet
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
    }
    else assert(false);

    if(ctx->variable_parameter()){
        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            bottom_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),BOTTOM_BOUND_T::LARGER);
        else assert(false);
    }
    else assert(false);
}

void BaseListener::exitLarger(ParseRulesParser::LargerContext* ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::BOUND_DEFINITION);
    assert(anonymous_node_.size()==1);
}

void BaseListener::enterLarger_equal(ParseRulesParser::Larger_equalContext* ctx){
    assert(!mode_.empty());
    if(ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            //creating in other sheet
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
    }
    else assert(false);

    if(ctx->variable_parameter()){
        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            bottom_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),BOTTOM_BOUND_T::LARGER_OR_EQUAL);
        else assert(false);
    }
    else assert(false);
}

void BaseListener::exitLarger_equal(ParseRulesParser::Larger_equalContext* ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::BOUND_DEFINITION);
    assert(anonymous_node_.size()==1);
}

void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
    throw ParsingError("Error input. Prompt: " + node->getText());
}


void BaseListener::enterVardefinition(ParseRulesParser::VardefinitionContext * ctx){
    assert(mode_.empty());
    assert(anonymous_node_.empty());
    mode_.push(MODE::VARDEF);
    //by default the database from which we define variable must exists

    if(ctx->vardef() && ctx->vardef()->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->vardef() && ctx->vardef()->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->vardef()->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->vardef()->VARIABLE()->getText())->node();
    }
    else assert(false);
    current_var_->release_childs();
    anonymous_node_.push(current_var_);
}

void BaseListener::exitVardefinition(ParseRulesParser::VardefinitionContext * ctx){ 
    assert(mode_.top()==MODE::VARDEF);
    assert(anonymous_node_.size()==1);
    current_var_.reset();
    anonymous_node_.pop();
    mode_.pop();
}

void BaseListener::enterItemArray(ParseRulesParser::ItemArrayContext *ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::ARRAY_DEFINITION);
    mode_.push(MODE::ARRAY_ITEM_DEFINITION);
}

void BaseListener::exitItemArray(ParseRulesParser::ItemArrayContext *ctx){
    assert(!mode_.empty());
    assert(mode_.top()==MODE::ARRAY_ITEM_DEFINITION);
    mode_.pop();
}

void BaseListener::enterComparision(ParseRulesParser::ComparisionContext* ctx){
    assert(mode_.empty());
    assert(anonymous_node_.empty());
    mode_.push(MODE::BOUND_DEFINITION);
    anonymous_node_.push(std::make_shared<UnaryNode>(UNARY_OP::PARENS));
}

void BaseListener::exitComparision(ParseRulesParser::ComparisionContext* ctx){
    assert(is_bounds_definition());
    mode_.pop();
    assert(mode_.empty());
    assert(anonymous_node_.size()==1);
    if(bottom_.has_value())
        current_var_->variable()->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,anonymous_node_.top(),bottom_.value().type);
    else if(top_.has_value())
        current_var_->variable()->set_top_bound_value(top_.value().db_name,top_.value().var_name,anonymous_node_.top(),top_.value().type);
    else throw std::runtime_error("Error ");
    anonymous_node_.pop();
}