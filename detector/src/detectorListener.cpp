#include "detectorListener.h"
#include "detector.h"

using namespace std::string_view_literals;

namespace detail{

ItemsParsingInfo* get_info_ptr(void* info){
    return static_cast<ItemsParsingInfo*>(info);
}
BaseListener::~BaseListener(){
    if(info)
        delete(ItemsParsingInfo*) info;
}
void* BaseListener::get_info() const{
    return info;
}
void BaseListener::enterParens(detect_type_functionParser::ParensContext* ctx){
    ctx->getStart()->getStartIndex();
}
void BaseListener::exitParens(detect_type_functionParser::ParensContext* ctx){
    ctx->getStop()->getStopIndex();
}
void BaseListener::enterVariable(detect_type_functionParser::VariableContext *ctx) {
    ctx->getStart()->getStartIndex();
    //if(ctx->)
}
void BaseListener::exitVariable(detect_type_functionParser::VariableContext *ctx) {
    ctx->getStop()->getStopIndex();
}
void BaseListener::enterUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) {
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::UNARY;
}
void BaseListener::exitUnaryOp(detect_type_functionParser::UnaryOpContext* ctx)  {
    
}
//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) {
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::BINARY;
}
void BaseListener::exitBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) {
    
}
//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(detect_type_functionParser::ArrayContext *ctx) {
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::ARRAY;
}
void BaseListener::exitArray(detect_type_functionParser::ArrayContext *ctx) {
    
}
void BaseListener::enterLiteral(detect_type_functionParser::LiteralContext *ctx){
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::LITERAL;
}
void BaseListener::exitLiteral(detect_type_functionParser::LiteralContext *ctx){

}
void BaseListener::enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx){
    assert(ctx);
    assert(info);
    ItemsParsingInfo* info_ptr = get_info_ptr(info);
    info_ptr->type_=item::ITEM_TYPE::FUNCTION;
    if(ctx->PRODUCT()) //here emplace the function type to info
        info_ptr->func_ = item::FUNCTION::PRODUCT;
    else if(ctx->SUMPRODUCT())
        info_ptr->func_ = item::FUNCTION::SUMPRODUCT;
    else if(ctx->SUM()){
        info_ptr->func_ = item::FUNCTION::SUM;
    }
}
void BaseListener::enterFunction(detect_type_functionParser::FunctionContext* ctx){
    assert(ctx);
    assert(info);
    ItemsParsingInfo* info_ptr = get_info_ptr(info);
    info_ptr->type_=item::ITEM_TYPE::FUNCTION;
    if(ctx->LN()){ //here emplace the function type to info
        info_ptr->func_ = item::FUNCTION::LN;
    }
    else if(ctx->ACOS()){
        info_ptr->func_ = item::FUNCTION::ACOS;
    }
    else if(ctx->ASIN()){
        info_ptr->func_ = item::FUNCTION::ASIN;
    }
    else if(ctx->FACTORIAL()){
        info_ptr->func_ = item::FUNCTION::FACTORIAL;
    }
    else if(ctx->COS()){
        info_ptr->func_ = item::FUNCTION::COS;
    }
    else if(ctx->SIN()){
        info_ptr->func_ = item::FUNCTION::SIN;
    }
    else if(ctx->EXP()){
        info_ptr->func_ = item::FUNCTION::EXP;
    }
    else if(ctx->LOG_X()){
        info_ptr->func_ = item::FUNCTION::LOG_X;
    }
    else if(ctx->LG()){
        info_ptr->func_ = item::FUNCTION::LG;
    }
    else if(ctx->SQRT()){
        info_ptr->func_ = item::FUNCTION::SQRT;
    }
    else assert(true);
}
void BaseListener::enterRangefunction(detect_type_functionParser::RangefunctionContext* ctx){
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    if(ctx->PRODUCT_I())//here emplace the function type to info
        get_info_ptr(info)->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    else if(ctx->SUM_I())
        get_info_ptr(info)->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    else assert(true);
}
void BaseListener::exitFunction(detect_type_functionParser::FunctionContext* ctx){
    
}
void BaseListener::exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx){
    
}
void BaseListener::exitRangefunction(detect_type_functionParser::RangefunctionContext* ctx){
    
}
void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
    
}
void BaseListener::enterString(detect_type_functionParser::StringContext* ctx){
    assert(ctx);
    assert(info);
    get_info_ptr(info)->type_=item::ITEM_TYPE::STRING;
}
void BaseListener::exitString(detect_type_functionParser::StringContext* ctx){
    
}
void BaseListener::enterEveryRule(antlr4::ParserRuleContext* ctx){
    if(ctx){
        if(!info)
            info = new ItemsParsingInfo(nullptr);
        else{
            get_info_ptr(info)->push_back(new ItemsParsingInfo(get_info_ptr(info)));
        }
    }
}
void BaseListener::exitEveryRule(antlr4::ParserRuleContext* ctx){
    if(ctx){
        assert(info);
        get_info_ptr(info)->init(
            ctx->getStart()->getStartIndex(),
            ctx->getStop()->getStopIndex());
    }
}
}