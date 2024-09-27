#include "detectorListener.h"
#include "detector.h"

using namespace std::string_view_literals;

namespace detail{

#ifdef DEBUG
    uint16_t BaseListener::enter_count = 0;
    uint16_t BaseListener::exit_count = 0;
#endif

BaseListener::BaseListener():
info(new ItemsParsingInfo(nullptr))
{}
BaseListener::~BaseListener(){
    if(info)
        delete info;
}
ItemsParsingInfo* BaseListener::get_info() const{
    return info;
}
void BaseListener::swap_info(ItemsParsingInfo** other){
    ItemsParsingInfo* buf = *other;
    *other = info;
    info = buf;
}
bool BaseListener::is_root() const noexcept{
    assert(info);
    return !info->prev_;
}
void BaseListener::child_containing_item(){
    if(is_root())
        info = info->push_back_next(new ItemsParsingInfo(info));
    else
        info = info->push_back_child(new ItemsParsingInfo(info));
}
void BaseListener::terminal_item(){
    assert(info);
    info = info->push_back_child(new ItemsParsingInfo(info));
}
void BaseListener::enterParens(detect_type_function::ParensContext* ctx){
    assert(info);
    assert(ctx);
    child_containing_item();
}
void BaseListener::exitParens(detect_type_function::ParensContext* ctx){}
void BaseListener::enterVariable(detect_type_function::VariableContext *ctx) {
    assert(info);
    assert(ctx);
    assert(info->type_!=item::ITEM_TYPE::VARIABLE && 
    info->type_!=item::ITEM_TYPE::VALUE && 
    info->type_!=item::ITEM_TYPE::STRING);
    terminal_item();
    info->type_ = item::ITEM_TYPE::VARIABLE;
}
void BaseListener::exitVariable(detect_type_function::VariableContext *ctx) {}
void BaseListener::enterUnaryOp(detect_type_function::UnaryOpContext *ctx) {
    assert(info);
    assert(ctx);
    child_containing_item();
    info->type_=item::ITEM_TYPE::UNARY;
}
void BaseListener::exitUnaryOp(detect_type_function::UnaryOpContext* ctx)  {}
//binary operator {for example: Expr + Expr or Expr / Expr}
void BaseListener::enterBinaryOp(detect_type_function::BinaryOpContext *ctx) {
    assert(ctx);
    assert(info);
    assert(ctx->children.size()==2);
    child_containing_item();
    info->type_=item::ITEM_TYPE::BINARY;
}
void BaseListener::exitBinaryOp(detect_type_function::BinaryOpContext *ctx) {}
void BaseListener::enterArray(detect_type_function::ArrayContext *ctx) {
    assert(ctx);
    assert(info);
    child_containing_item();
    info->type_=item::ITEM_TYPE::ARRAY;
}
void BaseListener::exitArray(detect_type_function::ArrayContext *ctx) {}
void BaseListener::enterLiteral(detect_type_function::LiteralContext *ctx){
    assert(ctx);
    assert(info);
    assert(info->type_!=item::ITEM_TYPE::VARIABLE && 
    info->type_!=item::ITEM_TYPE::VALUE && 
    info->type_!=item::ITEM_TYPE::STRING);
    terminal_item();
    info->type_=item::ITEM_TYPE::LITERAL;
}
void BaseListener::exitLiteral(detect_type_function::LiteralContext *ctx){}
void BaseListener::enterMultiargfunction(detect_type_function::MultiargfunctionContext* ctx){
    assert(ctx);
    assert(info);
    assert(info->type_!=item::ITEM_TYPE::VARIABLE && 
        info->type_!=item::ITEM_TYPE::VALUE && 
        info->type_!=item::ITEM_TYPE::STRING);
    child_containing_item();
    info->type_=item::ITEM_TYPE::FUNCTION;
    if(ctx->PRODUCT()) //here emplace the function type to info
        info->func_ = item::FUNCTION::PRODUCT;
    else if(ctx->SUMPRODUCT())
        info->func_ = item::FUNCTION::SUMPRODUCT;
    else if(ctx->SUM()){
        info->func_ = item::FUNCTION::SUM;
    }
}
void BaseListener::enterFunction(detect_type_function::FunctionContext* ctx){
    assert(ctx);
    assert(info);
    child_containing_item();
    info->type_=item::ITEM_TYPE::FUNCTION;
    if(ctx->LN()){ //here emplace the function type to info
        info->func_ = item::FUNCTION::LN;
    }
    else if(ctx->ACOS()){
        info->func_ = item::FUNCTION::ACOS;
    }
    else if(ctx->ASIN()){
        info->func_ = item::FUNCTION::ASIN;
    }
    else if(ctx->FACTORIAL()){
        info->func_ = item::FUNCTION::FACTORIAL;
    }
    else if(ctx->COS()){
        info->func_ = item::FUNCTION::COS;
    }
    else if(ctx->SIN()){
        info->func_ = item::FUNCTION::SIN;
    }
    else if(ctx->EXP()){
        info->func_ = item::FUNCTION::EXP;
    }
    else if(ctx->LOG_X()){
        info->func_ = item::FUNCTION::LOG_X;
    }
    else if(ctx->LG()){
        info->func_ = item::FUNCTION::LG;
    }
    else if(ctx->SQRT()){
        info->func_ = item::FUNCTION::SQRT;
    }
    else assert(true);
}
void BaseListener::enterRangefunction(detect_type_function::RangefunctionContext* ctx){
    assert(ctx);
    assert(info);
    child_containing_item();
    info->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    if(ctx->PRODUCT_I())//here emplace the function type to info
        info->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    else if(ctx->SUM_I())
        info->type_=item::ITEM_TYPE::RANGE_FUNCTION;
    else assert(true);
}
void BaseListener::exitFunction(detect_type_function::FunctionContext* ctx){}
void BaseListener::exitMultiargfunction(detect_type_function::MultiargfunctionContext* ctx){}
void BaseListener::exitRangefunction(detect_type_function::RangefunctionContext* ctx){}
void BaseListener::visitErrorNode(antlr4::tree::ErrorNode* node){
    std::cerr<<"Error parsing occured"<<std::endl;
}
void BaseListener::enterString(detect_type_function::StringContext* ctx){
    assert(ctx);
    assert(info);
    assert(info->type_!=item::ITEM_TYPE::VARIABLE && 
    info->type_!=item::ITEM_TYPE::VALUE && 
    info->type_!=item::ITEM_TYPE::STRING);
    terminal_item();
    info->type_=item::ITEM_TYPE::STRING;
}
void BaseListener::exitString(detect_type_function::StringContext* ctx){}
void BaseListener::enterEveryRule(antlr4::ParserRuleContext* ctx){
    assert(info);
    #ifdef DEBUG
        ++enter_count;
    #endif
    //std::cout<<"Item enter: "<<ctx->getText()<<std::endl;
}
void BaseListener::exitEveryRule(antlr4::ParserRuleContext* ctx){
    #ifdef DEBUG
        ++exit_count;
    #endif
    if(ctx){
        if(!dynamic_cast<detect_type_function::ExprContext*>(ctx) &&
        !dynamic_cast<detect_type_function::Node_accessContext*>(ctx)){
            assert(info);
            //std::cout<<"Item exit: "<<ctx->getText()<<std::endl;
            info->init(
                ctx->getStart()->getStartIndex(),
                ctx->getStop()->getStopIndex());
            if(!is_root())
                info = info->prev_;
        }
    }
}
}