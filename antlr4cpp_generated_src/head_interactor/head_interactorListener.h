
// Generated from /home/oster/OsterMath-Backend/grammar/head_interactor.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "head_interactor.h"


/**
 * This interface defines an abstract listener for a parse tree produced by head_interactor.
 */
class  head_interactorListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterValue_type(head_interactor::Value_typeContext *ctx) = 0;
  virtual void exitValue_type(head_interactor::Value_typeContext *ctx) = 0;

  virtual void enterComparator(head_interactor::ComparatorContext *ctx) = 0;
  virtual void exitComparator(head_interactor::ComparatorContext *ctx) = 0;

  virtual void enterInput(head_interactor::InputContext *ctx) = 0;
  virtual void exitInput(head_interactor::InputContext *ctx) = 0;

  virtual void enterLine_input(head_interactor::Line_inputContext *ctx) = 0;
  virtual void exitLine_input(head_interactor::Line_inputContext *ctx) = 0;

  virtual void enterNode_access(head_interactor::Node_accessContext *ctx) = 0;
  virtual void exitNode_access(head_interactor::Node_accessContext *ctx) = 0;

  virtual void enterVariable(head_interactor::VariableContext *ctx) = 0;
  virtual void exitVariable(head_interactor::VariableContext *ctx) = 0;

  virtual void enterVardefinition(head_interactor::VardefinitionContext *ctx) = 0;
  virtual void exitVardefinition(head_interactor::VardefinitionContext *ctx) = 0;

  virtual void enterComparision(head_interactor::ComparisionContext *ctx) = 0;
  virtual void exitComparision(head_interactor::ComparisionContext *ctx) = 0;

  virtual void enterLhs_comp(head_interactor::Lhs_compContext *ctx) = 0;
  virtual void exitLhs_comp(head_interactor::Lhs_compContext *ctx) = 0;

  virtual void enterRhs_comp(head_interactor::Rhs_compContext *ctx) = 0;
  virtual void exitRhs_comp(head_interactor::Rhs_compContext *ctx) = 0;

  virtual void enterExpr_comp(head_interactor::Expr_compContext *ctx) = 0;
  virtual void exitExpr_comp(head_interactor::Expr_compContext *ctx) = 0;

  virtual void enterUnaryOp(head_interactor::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(head_interactor::UnaryOpContext *ctx) = 0;

  virtual void enterParens(head_interactor::ParensContext *ctx) = 0;
  virtual void exitParens(head_interactor::ParensContext *ctx) = 0;

  virtual void enterLiteral(head_interactor::LiteralContext *ctx) = 0;
  virtual void exitLiteral(head_interactor::LiteralContext *ctx) = 0;

  virtual void enterFunctionCall(head_interactor::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(head_interactor::FunctionCallContext *ctx) = 0;

  virtual void enterVariableInExpr(head_interactor::VariableInExprContext *ctx) = 0;
  virtual void exitVariableInExpr(head_interactor::VariableInExprContext *ctx) = 0;

  virtual void enterBinaryOp(head_interactor::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(head_interactor::BinaryOpContext *ctx) = 0;

  virtual void enterArray(head_interactor::ArrayContext *ctx) = 0;
  virtual void exitArray(head_interactor::ArrayContext *ctx) = 0;

  virtual void enterItemArray(head_interactor::ItemArrayContext *ctx) = 0;
  virtual void exitItemArray(head_interactor::ItemArrayContext *ctx) = 0;

  virtual void enterNumber(head_interactor::NumberContext *ctx) = 0;
  virtual void exitNumber(head_interactor::NumberContext *ctx) = 0;

  virtual void enterConstant(head_interactor::ConstantContext *ctx) = 0;
  virtual void exitConstant(head_interactor::ConstantContext *ctx) = 0;

  virtual void enterFunction(head_interactor::FunctionContext *ctx) = 0;
  virtual void exitFunction(head_interactor::FunctionContext *ctx) = 0;

  virtual void enterMultiargfunction(head_interactor::MultiargfunctionContext *ctx) = 0;
  virtual void exitMultiargfunction(head_interactor::MultiargfunctionContext *ctx) = 0;

  virtual void enterRangefunction(head_interactor::RangefunctionContext *ctx) = 0;
  virtual void exitRangefunction(head_interactor::RangefunctionContext *ctx) = 0;

  virtual void enterString(head_interactor::StringContext *ctx) = 0;
  virtual void exitString(head_interactor::StringContext *ctx) = 0;


};

