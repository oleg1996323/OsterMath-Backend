
// Generated from /home/oster/OsterMath-Backend/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "detect_type_function.h"


/**
 * This interface defines an abstract listener for a parse tree produced by detect_type_function.
 */
class  detect_type_functionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterValue_type(detect_type_function::Value_typeContext *ctx) = 0;
  virtual void exitValue_type(detect_type_function::Value_typeContext *ctx) = 0;

  virtual void enterLine_input(detect_type_function::Line_inputContext *ctx) = 0;
  virtual void exitLine_input(detect_type_function::Line_inputContext *ctx) = 0;

  virtual void enterNode_access(detect_type_function::Node_accessContext *ctx) = 0;
  virtual void exitNode_access(detect_type_function::Node_accessContext *ctx) = 0;

  virtual void enterVariable(detect_type_function::VariableContext *ctx) = 0;
  virtual void exitVariable(detect_type_function::VariableContext *ctx) = 0;

  virtual void enterUnaryOp(detect_type_function::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(detect_type_function::UnaryOpContext *ctx) = 0;

  virtual void enterParens(detect_type_function::ParensContext *ctx) = 0;
  virtual void exitParens(detect_type_function::ParensContext *ctx) = 0;

  virtual void enterLiteral(detect_type_function::LiteralContext *ctx) = 0;
  virtual void exitLiteral(detect_type_function::LiteralContext *ctx) = 0;

  virtual void enterFunctionCall(detect_type_function::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(detect_type_function::FunctionCallContext *ctx) = 0;

  virtual void enterVariableInExpr(detect_type_function::VariableInExprContext *ctx) = 0;
  virtual void exitVariableInExpr(detect_type_function::VariableInExprContext *ctx) = 0;

  virtual void enterBinaryOp(detect_type_function::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(detect_type_function::BinaryOpContext *ctx) = 0;

  virtual void enterArray(detect_type_function::ArrayContext *ctx) = 0;
  virtual void exitArray(detect_type_function::ArrayContext *ctx) = 0;

  virtual void enterNumber(detect_type_function::NumberContext *ctx) = 0;
  virtual void exitNumber(detect_type_function::NumberContext *ctx) = 0;

  virtual void enterConstant(detect_type_function::ConstantContext *ctx) = 0;
  virtual void exitConstant(detect_type_function::ConstantContext *ctx) = 0;

  virtual void enterFunction(detect_type_function::FunctionContext *ctx) = 0;
  virtual void exitFunction(detect_type_function::FunctionContext *ctx) = 0;

  virtual void enterMultiargfunction(detect_type_function::MultiargfunctionContext *ctx) = 0;
  virtual void exitMultiargfunction(detect_type_function::MultiargfunctionContext *ctx) = 0;

  virtual void enterRangefunction(detect_type_function::RangefunctionContext *ctx) = 0;
  virtual void exitRangefunction(detect_type_function::RangefunctionContext *ctx) = 0;

  virtual void enterString(detect_type_function::StringContext *ctx) = 0;
  virtual void exitString(detect_type_function::StringContext *ctx) = 0;


};

