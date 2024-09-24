#include "types.h"
#include "arithmetic_types.h"
#include "detectorListener"

using namespace std::string_view_literals;

namespace expression{
void BaseListener::enterParens(detect_type_functionParser::ParensContext* ctx){
    ctx->getStart()->getStartIndex();
}

void BaseListener::exitParens(detect_type_functionParser::ParensContext* ctx){
    ctx->getStop()->getStopIndex();
}

void BaseListener::enterVariable(detect_type_functionParser::VariableContext *ctx) {
    ctx->getStart()->getStartIndex();
    if(ctx->)
}

void BaseListener::exitVariable(detect_type_functionParser::VariableContext *ctx) {
    ctx->getStop()->getStopIndex();
}

void BaseListener::enterUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) {
    
}

void BaseListener::exitUnaryOp(detect_type_functionParser::UnaryOpContext* ctx)  {
    
}

void BaseListener::enterLiteral(detect_type_functionParser::LiteralContext *ctx) {
    return;
}

void BaseListener::exitLiteral(detect_type_functionParser::LiteralContext *ctx) {
    return;
}

//a connstant definition {for example: Lg(Expr)}
void BaseListener::enterConstant(detect_type_functionParser::ConstantContext *ctx) {
    
}

void BaseListener::exitConstant(detect_type_functionParser::ConstantContext *ctx) {
    
}

//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) {
    
}

void BaseListener::exitBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) {
    
}

//an array definition {for example: [1,2,3,...]}
void BaseListener::enterArray(detect_type_functionParser::ArrayContext *ctx) {
    
}

void BaseListener::exitArray(detect_type_functionParser::ArrayContext *ctx) {
    
}

void BaseListener::enterNumber(detect_type_functionParser::NumberContext* ctx){
    
}

void BaseListener::exitNumber(detect_type_functionParser::NumberContext* ctx){
    
}

void BaseListener::enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx){
    
}

void BaseListener::enterFunction(detect_type_functionParser::FunctionContext* ctx){
    
}

void BaseListener::enterRangefunction(detect_type_functionParser::RangefunctionContext* ctx){
    
}

void BaseListener::exitFunction(detect_type_functionParser::FunctionContext* ctx){
    
}

void BaseListener::exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx){
    
}

void BaseListener::exitRangefunction(detect_type_functionParser::RangefunctionContext* ctx){
    
}

void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
    
}

void BaseListener::enterLhs_comp(detect_type_functionParser::Lhs_compContext* ctx){
    
}

void BaseListener::exitLhs_comp(detect_type_functionParser::Lhs_compContext* ctx){
    
}

void BaseListener::enterRhs_comp(detect_type_functionParser::Rhs_compContext* ctx){
    
}

void BaseListener::exitRhs_comp(detect_type_functionParser::Rhs_compContext* ctx){
    
}

void BaseListener::enterExpr_comp(detect_type_functionParser::Expr_compContext* ctx){
    
}

void BaseListener::exitExpr_comp(detect_type_functionParser::Expr_compContext* ctx){
    
}

void BaseListener::enterVardefinition(detect_type_functionParser::VardefinitionContext * ctx){
    
}

void BaseListener::exitVardefinition(detect_type_functionParser::VardefinitionContext * ctx){ 

}

void BaseListener::enterItemArray(detect_type_functionParser::ItemArrayContext *ctx){

}

void BaseListener::exitItemArray(detect_type_functionParser::ItemArrayContext *ctx){

}

void BaseListener::enterComparision(detect_type_functionParser::ComparisionContext* ctx){
    
}

void BaseListener::exitComparision(detect_type_functionParser::ComparisionContext* ctx){
    
}

void BaseListener::enterString(detect_type_functionParser::StringContext* ctx){

}

void BaseListener::exitString(detect_type_functionParser::StringContext* ctx){
    
}
}