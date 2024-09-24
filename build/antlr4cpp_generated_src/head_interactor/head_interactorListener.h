
// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "head_interactorParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by head_interactorParser.
 */
class  head_interactorListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterValue_type(head_interactorParser::Value_typeContext *ctx) = 0;
  virtual void exitValue_type(head_interactorParser::Value_typeContext *ctx) = 0;

  virtual void enterComparator(head_interactorParser::ComparatorContext *ctx) = 0;
  virtual void exitComparator(head_interactorParser::ComparatorContext *ctx) = 0;

  virtual void enterInput(head_interactorParser::InputContext *ctx) = 0;
  virtual void exitInput(head_interactorParser::InputContext *ctx) = 0;

  virtual void enterLine_input(head_interactorParser::Line_inputContext *ctx) = 0;
  virtual void exitLine_input(head_interactorParser::Line_inputContext *ctx) = 0;

  virtual void enterNode_access(head_interactorParser::Node_accessContext *ctx) = 0;
  virtual void exitNode_access(head_interactorParser::Node_accessContext *ctx) = 0;

  virtual void enterVariable(head_interactorParser::VariableContext *ctx) = 0;
  virtual void exitVariable(head_interactorParser::VariableContext *ctx) = 0;

  virtual void enterVardefinition(head_interactorParser::VardefinitionContext *ctx) = 0;
  virtual void exitVardefinition(head_interactorParser::VardefinitionContext *ctx) = 0;

  virtual void enterComparision(head_interactorParser::ComparisionContext *ctx) = 0;
  virtual void exitComparision(head_interactorParser::ComparisionContext *ctx) = 0;

  virtual void enterLhs_comp(head_interactorParser::Lhs_compContext *ctx) = 0;
  virtual void exitLhs_comp(head_interactorParser::Lhs_compContext *ctx) = 0;

  virtual void enterRhs_comp(head_interactorParser::Rhs_compContext *ctx) = 0;
  virtual void exitRhs_comp(head_interactorParser::Rhs_compContext *ctx) = 0;

  virtual void enterExpr_comp(head_interactorParser::Expr_compContext *ctx) = 0;
  virtual void exitExpr_comp(head_interactorParser::Expr_compContext *ctx) = 0;

  virtual void enterUnaryOp(head_interactorParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(head_interactorParser::UnaryOpContext *ctx) = 0;

  virtual void enterParens(head_interactorParser::ParensContext *ctx) = 0;
  virtual void exitParens(head_interactorParser::ParensContext *ctx) = 0;

  virtual void enterLiteral(head_interactorParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(head_interactorParser::LiteralContext *ctx) = 0;

  virtual void enterFunctionCall(head_interactorParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(head_interactorParser::FunctionCallContext *ctx) = 0;

  virtual void enterVariableInExpr(head_interactorParser::VariableInExprContext *ctx) = 0;
  virtual void exitVariableInExpr(head_interactorParser::VariableInExprContext *ctx) = 0;

  virtual void enterBinaryOp(head_interactorParser::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(head_interactorParser::BinaryOpContext *ctx) = 0;

  virtual void enterArray(head_interactorParser::ArrayContext *ctx) = 0;
  virtual void exitArray(head_interactorParser::ArrayContext *ctx) = 0;

  virtual void enterItemArray(head_interactorParser::ItemArrayContext *ctx) = 0;
  virtual void exitItemArray(head_interactorParser::ItemArrayContext *ctx) = 0;

  virtual void enterNumber(head_interactorParser::NumberContext *ctx) = 0;
  virtual void exitNumber(head_interactorParser::NumberContext *ctx) = 0;

  virtual void enterConstant(head_interactorParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(head_interactorParser::ConstantContext *ctx) = 0;

  virtual void enterFunction(head_interactorParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(head_interactorParser::FunctionContext *ctx) = 0;

  virtual void enterMultiargfunction(head_interactorParser::MultiargfunctionContext *ctx) = 0;
  virtual void exitMultiargfunction(head_interactorParser::MultiargfunctionContext *ctx) = 0;

  virtual void enterRangefunction(head_interactorParser::RangefunctionContext *ctx) = 0;
  virtual void exitRangefunction(head_interactorParser::RangefunctionContext *ctx) = 0;

  virtual void enterString(head_interactorParser::StringContext *ctx) = 0;
  virtual void exitString(head_interactorParser::StringContext *ctx) = 0;


};

