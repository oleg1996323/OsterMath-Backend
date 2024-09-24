#pragma once
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <optional>
#include <vector>
#include <stack>
#include "def.h"
#include "detect_type_functionListener.h"
#include "domain.h"

class BaseData;

using namespace std::string_view_literals;

class FunctionNode;
class RangeOperationNode;
class VariableNode;
class Node;

namespace expression{

class BaseListener: public detect_type_functionListener{
    struct PARSING_INFO{
        uint32_t start_ = 0;
        uint32_t stop_ = 0-1;
        item::ITEM_TYPE;
    }
    
    DataPool* pool_;

    public:
    BaseListener(DataPool* pool):
    pool_(pool)
    {}

    virtual void enterParens(detect_type_functionParser::ParensContext* ctx) override;

    virtual void exitParens(detect_type_functionParser::ParensContext* ctx) override;

    virtual void enterVardefinition(detect_type_functionParser::VardefinitionContext * ctx) override;
    
    virtual void exitVardefinition(detect_type_functionParser::VardefinitionContext * ctx) override;

    virtual void enterVariable(detect_type_functionParser::VariableContext *ctx) override;

    virtual void exitVariable(detect_type_functionParser::VariableContext *ctx) override;

    virtual void enterUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) override;

    virtual void exitUnaryOp(detect_type_functionParser::UnaryOpContext* ctx) override;

    virtual void enterLiteral(detect_type_functionParser::LiteralContext *ctx) override;

    virtual void exitLiteral(detect_type_functionParser::LiteralContext *ctx) override;

    //a connstant definition {for example: Lg(Expr)}
    virtual void enterConstant(detect_type_functionParser::ConstantContext *ctx) override;

    virtual void exitConstant(detect_type_functionParser::ConstantContext *ctx) override;

    //binary operator {for example: Expr + Expr or Expr / Expr}
    virtual void enterBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) override;

    virtual void exitBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) override;

    //an array definition {for example: [1,2,3,...]}
    virtual void enterArray(detect_type_functionParser::ArrayContext *ctx) override;

    virtual void exitArray(detect_type_functionParser::ArrayContext *ctx) override;

    virtual void enterItemArray(detect_type_functionParser::ItemArrayContext *ctx) override;

    virtual void exitItemArray(detect_type_functionParser::ItemArrayContext *ctx) override;

    virtual void enterRangefunction(detect_type_functionParser::RangefunctionContext* ctx) override;

    virtual void exitRangefunction(detect_type_functionParser::RangefunctionContext* ctx) override;

    virtual void enterNumber(detect_type_functionParser::NumberContext* ctx) override;

    virtual void exitNumber(detect_type_functionParser::NumberContext* ctx) override;

    virtual void enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx) override;

    virtual void exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext* ctx) override;

    virtual void enterFunction(detect_type_functionParser::FunctionContext* ctx) override;

    virtual void exitFunction(detect_type_functionParser::FunctionContext* ctx) override;

    virtual void enterComparision(detect_type_functionParser::ComparisionContext* ctx) override;

    virtual void exitComparision(detect_type_functionParser::ComparisionContext* ctx) override;

    virtual void enterLhs_comp(detect_type_functionParser::Lhs_compContext* ctx) override;

    virtual void exitLhs_comp(detect_type_functionParser::Lhs_compContext* ctx) override;

    virtual void enterRhs_comp(detect_type_functionParser::Rhs_compContext* ctx) override;

    virtual void exitRhs_comp(detect_type_functionParser::Rhs_compContext* ctx) override;

    virtual void enterExpr_comp(detect_type_functionParser::Expr_compContext* ctx) override;

    virtual void exitExpr_comp(detect_type_functionParser::Expr_compContext* ctx) override;

    virtual void enterString(detect_type_functionParser::StringContext * ctx) override;

    virtual void exitString(detect_type_functionParser::StringContext * ctx) override;

    virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;

};
}