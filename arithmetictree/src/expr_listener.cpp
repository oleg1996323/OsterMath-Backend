#include "types.h"
#include "data.h"
#include "arithmetic_types.h"
#include "expr_listener.h"
#include "exception.h"

using namespace std::string_view_literals;

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

void BaseListener::__insert_to_variable__(const std::shared_ptr<Node>& node) const{
    current_var_->insert(node);
}

void BaseListener::__insert_to_anonymous_node__(const std::shared_ptr<Node>& node) const{
    anonymous_node_->insert(node);
}

BaseData* BaseListener::__insert_new_data_base__(std::string&& name){
    return data_base_->get_pool()->add_data(name);
}

void BaseListener::enterVardefinition(ParseRulesParser::VardefinitionContext * ctx){
    assert(mode_.empty());
    mode_.push(MODE::VARDEF);
    //by default the database from which we define variable must exists

    if(ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();
    }
    else assert(false);
    current_var_->release_childs();
}

void BaseListener::exitVardefinition(ParseRulesParser::VardefinitionContext * ctx){ 
    assert(mode_.top()==MODE::VARDEF);
    current_var_.reset();
    mode_.pop();
}

void BaseListener::enterVariable(ParseRulesParser::VariableContext *ctx) {
    assert(!mode_.empty());
            
    BaseData* db_tmp;
    if(ctx->DATABASE())
        db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
    else db_tmp = data_base_;

    VariableBase* ptr = db_tmp->add_variable(ctx->VARIABLE()->getText()).get();
    if(is_variable_definition()){
        __insert_to_variable__(ptr->node());
    }
    else if(is_bounds_definition()){
        if(bottom_.has_value())
            current_var_->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,ptr,bottom_.value().type);
        else if(top_.has_value())
            current_var_->set_top_bound_value(top_.value().db_name,top_.value().var_name,ptr,top_.value().type);
    }
    else throw std::runtime_error("Error when variable inserted");
}

void BaseListener::enterUnaryOp(ParseRulesParser::UnaryOpContext *ctx) {
    assert(!mode_.empty());
    if(is_variable_definition()){
        current_var_->insert(std::make_shared<UnaryNode>(ctx->ADD()?UNARY_OP::ADD:UNARY_OP::SUB));
    }
    else assert(false);
}

void BaseListener::exitUnaryOp(ParseRulesParser::UnaryOpContext* ctx)  {
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
        if(ctx->EXP()){
            current_var_->insert(std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()));
        }
        else if(ctx->PI()){
            current_var_->insert(std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()));
        }
        else
            throw std::runtime_error("Error parsing constant");
        return;
    }
    else if(is_bounds_definition()){
        if(ctx->EXP()){
            if(bottom_.has_value())
                current_var_->variable()->set_bottom_bound_value(bottom_.value().db_name,
                bottom_.value().var_name,
                std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()),
                bottom_.value().type);
            else if(top_.has_value())
                current_var_->variable()->set_top_bound_value(top_.value().db_name,
                top_.value().var_name,
                std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()),
                top_.value().type);
        }
        else if(ctx->PI()){
            if(bottom_.has_value())
                current_var_->variable()->set_bottom_bound_value(bottom_.value().db_name,
                bottom_.value().var_name,
                std::make_shared<ValueNode>(boost::math::constants::pi<Value_t>()),
                bottom_.value().type);
            else if(top_.has_value())
                current_var_->variable()->set_top_bound_value(top_.value().db_name,
                top_.value().var_name,
                std::make_shared<ValueNode>(boost::math::constants::e<Value_t>()),
                top_.value().type);
        }
    }
    else throw std::runtime_error("Error when added constant value");
}

void BaseListener::exitConstant(ParseRulesParser::ConstantContext *ctx) {
    return;
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(ParseRulesParser::BinaryOpContext *ctx) {
    //entering in the arithmetictree of range_function
    if(is_variable_definition()){
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

void BaseListener::enterItemArray(ParseRulesParser::ItemArrayContext *ctx){
    return;
}

void BaseListener::exitItemArray(ParseRulesParser::ItemArrayContext *ctx){
    return;
}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(ParseRulesParser::ArrayContext *ctx) {
    assert(!mode_.empty() && current_var_);
    if(is_variable_definition()){
        __insert_to_variable__(std::make_shared<ArrayNode>(ctx->input_array().size()));
        mode_.push(MODE::ARRAY_DEFINITION);
    }
    return;
}

void BaseListener::exitArray(ParseRulesParser::ArrayContext *ctx) {
    assert(mode_.top()==MODE::ARRAY_DEFINITION);
    mode_.pop();
    array_node_.reset();
    return;
}

void BaseListener::enterNumber(ParseRulesParser::NumberContext* ctx){
    if(is_range_operation())
        __insert_to_range_operation__(std::make_shared<ValueNode>(ctx->getText()));
    else if(is_variable_definition())
        __insert_to_variable__(std::move(Value_t(ctx->getText())));
    else if(is_function_operation() && !tmp_function_node_.top()->is_array_function())
        __insert_to_function_operation__(std::make_shared<ValueNode>(ctx->getText()));
    else if(is_bounds_definition()){
        if(bottom_.has_value())
            current_var_->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,std::move(Value_t(ctx->getText())),bottom_.value().type);
        else if(top_.has_value())
            current_var_->set_top_bound_value(top_.value().db_name,top_.value().var_name,std::move(Value_t(ctx->getText())),top_.value().type);
    }
    else throw std::runtime_error("Unknown parsing type");
    return;
}

void BaseListener::enterMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    mode_.push(MODE::FUNCTIONOPERATION);
    if(ctx->PRODUCT())
        tmp_function_node_.push(std::make_unique<FunctionNode>(FUNCTION_OP::PROD));
    else if(ctx->SUMPRODUCT())
        tmp_function_node_.push(std::make_unique<FunctionNode>(FUNCTION_OP::SUMPRODUCT));
    else if(ctx->SUM())
        tmp_function_node_.push(std::make_unique<FunctionNode>(FUNCTION_OP::SUM));
}

void BaseListener::enterFunction(ParseRulesParser::FunctionContext* ctx){
    mode_.push(MODE::FUNCTIONOPERATION);
    if(ctx){
        if(ctx->EXP())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::EXP));
        else if(ctx->LG())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LG10));
        else if(ctx->LN())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LN));
        else if(ctx->LOG_X())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::LOG_BASE));
        else if(ctx->SIN())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::SIN));
        else if(ctx->COS())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::COS));
        else if(ctx->ASIN())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ASIN));
        else if(ctx->ACOS())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::ACOS));
        else if(ctx->FACTORIAL())
            tmp_function_node_.push(std::make_shared<FunctionNode>(FUNCTION_OP::FACTORIAL));
        else throw std::invalid_argument("Unknown input of function context");
    }
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

void BaseListener::exitFunction(ParseRulesParser::FunctionContext* ctx){
    mode_.pop();
    std::shared_ptr<FunctionNode> ptr = tmp_function_node_.top();
    tmp_function_node_.pop();
    if(is_variable_definition())
        __insert_to_variable__(ptr);
    else if(is_range_operation())
        __insert_to_range_operation__(ptr);
    else if(is_function_operation())
        __insert_to_function_operation__(ptr);
    else if(is_bounds_definition()){
        ArithmeticTree tree(current_var_);
        tree.insert(ptr);
        if(bottom_.has_value())
            current_var_->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,std::move(tree),bottom_.value().type);
        else if(top_.has_value())
            current_var_->set_top_bound_value(top_.value().db_name,top_.value().var_name,std::move(tree),top_.value().type);
    }
}

void BaseListener::exitMultiargfunction(ParseRulesParser::MultiargfunctionContext* ctx){
    mode_.pop();
    std::shared_ptr<FunctionNode> ptr = tmp_function_node_.top();
    tmp_function_node_.pop();
    if(is_variable_definition())
        __insert_to_variable__(ptr);
    else if(is_range_operation())
        __insert_to_range_operation__(ptr);
    else if(is_function_operation())
        __insert_to_function_operation__(ptr);
    else if(is_bounds_definition()){
        ArithmeticTree tree(current_var_);
        tree.insert(ptr);
        if(bottom_.has_value())
            current_var_->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,std::move(tree),bottom_.value().type);
        else if(top_.has_value())
            current_var_->set_top_bound_value(top_.value().db_name,top_.value().var_name,std::move(tree),top_.value().type);
    }
}

void BaseListener::exitRangefunction(ParseRulesParser::RangefunctionContext* ctx){
    assert(!tmp_range_node_.empty());
    assert(!mode_.empty());
    mode_.pop();
    std::shared_ptr<RangeOperationNode> ptr = tmp_range_node_.top();
    tmp_range_node_.pop();
    if(is_variable_definition()){
        __insert_to_variable__(ptr);
    }
    else if(is_range_operation()){
        __insert_to_range_operation__(ptr);
    }
    else if(is_function_operation()){
        __insert_to_function_operation__(ptr);
    }
    else if(is_bounds_definition()){
        ArithmeticTree tree(current_var_);
        tree.insert(ptr);
        if(bottom_.has_value())
            current_var_->set_bottom_bound_value(bottom_.value().db_name,bottom_.value().var_name,std::move(tree),bottom_.value().type);
        else if(top_.has_value())
            current_var_->set_top_bound_value(top_.value().db_name,top_.value().var_name,std::move(tree),top_.value().type);
    }
}

void BaseListener::enterLess(ParseRulesParser::LessContext* ctx){
    assert(mode_.empty());
    if(ctx->variable_parameter() && ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText()).get();

        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            top_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),TOP_BOUND_T::LESS);
        else assert(false);

        mode_.push(MODE::BOUND_DEFINITION);
    }
    else assert(false);
}

void BaseListener::exitLess(ParseRulesParser::LessContext* ctx){
    top_.reset();
    mode_.pop();
    assert(mode_.empty());
    current_var_ = nullptr;
}

void BaseListener::enterLess_equal(ParseRulesParser::Less_equalContext* ctx){
    assert(mode_.empty());
    if(ctx->variable_parameter() && ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText()).get();

        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            top_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),TOP_BOUND_T::LESS_OR_EQUAL);
        else assert(false);
        mode_.push(MODE::BOUND_DEFINITION);
    }
    else assert(false);
}

void BaseListener::exitLess_equal(ParseRulesParser::Less_equalContext* ctx){
    top_.reset();
    mode_.pop();
    assert(mode_.empty());
    current_var_ = nullptr;
}

void BaseListener::enterLarger(ParseRulesParser::LargerContext* ctx){
    assert(mode_.empty());
    if(ctx->variable_parameter() && ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText())->node();

        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            bottom_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),BOTTOM_BOUND_T::LARGER);
        else assert(false);
        mode_.push(MODE::BOUND_DEFINITION);
    }
    else assert(false);
}

void BaseListener::exitLarger(ParseRulesParser::LargerContext* ctx){
    bottom_.reset();
    mode_.pop();
    assert(mode_.empty());
    current_var_ = nullptr;
}

void BaseListener::enterLarger_equal(ParseRulesParser::Larger_equalContext* ctx){
    assert(mode_.empty());
    if(ctx->variable_parameter() && ctx->VARIABLE()){
        //creating in active sheet
        BaseData* c_var_db_tmp;
        if(ctx->DATABASE())
            c_var_db_tmp = __insert_new_data_base__(ctx->DATABASE()->getText());
        else c_var_db_tmp = data_base_;
        current_var_ = c_var_db_tmp->add_variable(ctx->VARIABLE()->getText()).get();

        BaseData* db_tmp;
        if(ctx->variable_parameter()->DATABASE())
            db_tmp = __insert_new_data_base__(ctx->variable_parameter()->DATABASE()->getText());
        else db_tmp = data_base_;

        if(ctx->variable_parameter()->VARIABLE())
            bottom_.emplace(db_tmp->name(),db_tmp->add_variable(ctx->variable_parameter()->VARIABLE()->getText()).get()->name(),BOTTOM_BOUND_T::LARGER_OR_EQUAL);
        else assert(false);
        mode_.push(MODE::BOUND_DEFINITION);
    }
    else assert(false);
}

void BaseListener::exitLarger_equal(ParseRulesParser::Larger_equalContext* ctx){
    bottom_.reset();
    mode_.pop();
    assert(mode_.empty());
    current_var_ = nullptr;
}

void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
    throw ParsingError("Error input. Prompt: " + node->getText());
}