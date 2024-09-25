
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "detect_type_functionParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by detect_type_functionParser.
 */
class  detect_type_functionListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterValue_type(detect_type_functionParser::Value_typeContext *ctx) = 0;
  virtual void exitValue_type(detect_type_functionParser::Value_typeContext *ctx) = 0;

  virtual void enterInput(detect_type_functionParser::InputContext *ctx) = 0;
  virtual void exitInput(detect_type_functionParser::InputContext *ctx) = 0;

  virtual void enterLine_input(detect_type_functionParser::Line_inputContext *ctx) = 0;
  virtual void exitLine_input(detect_type_functionParser::Line_inputContext *ctx) = 0;

  virtual void enterNode_access(detect_type_functionParser::Node_accessContext *ctx) = 0;
  virtual void exitNode_access(detect_type_functionParser::Node_accessContext *ctx) = 0;

  virtual void enterVariable(detect_type_functionParser::VariableContext *ctx) = 0;
  virtual void exitVariable(detect_type_functionParser::VariableContext *ctx) = 0;

  virtual void enterUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(detect_type_functionParser::UnaryOpContext *ctx) = 0;

  virtual void enterParens(detect_type_functionParser::ParensContext *ctx) = 0;
  virtual void exitParens(detect_type_functionParser::ParensContext *ctx) = 0;

  virtual void enterLiteral(detect_type_functionParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(detect_type_functionParser::LiteralContext *ctx) = 0;

  virtual void enterFunctionCall(detect_type_functionParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(detect_type_functionParser::FunctionCallContext *ctx) = 0;

  virtual void enterVariableInExpr(detect_type_functionParser::VariableInExprContext *ctx) = 0;
  virtual void exitVariableInExpr(detect_type_functionParser::VariableInExprContext *ctx) = 0;

  virtual void enterBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(detect_type_functionParser::BinaryOpContext *ctx) = 0;

  virtual void enterArray(detect_type_functionParser::ArrayContext *ctx) = 0;
  virtual void exitArray(detect_type_functionParser::ArrayContext *ctx) = 0;

  virtual void enterItemArray(detect_type_functionParser::ItemArrayContext *ctx) = 0;
  virtual void exitItemArray(detect_type_functionParser::ItemArrayContext *ctx) = 0;

  virtual void enterNumber(detect_type_functionParser::NumberContext *ctx) = 0;
  virtual void exitNumber(detect_type_functionParser::NumberContext *ctx) = 0;

  virtual void enterConstant(detect_type_functionParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(detect_type_functionParser::ConstantContext *ctx) = 0;

  virtual void enterFunction(detect_type_functionParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(detect_type_functionParser::FunctionContext *ctx) = 0;

  virtual void enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext *ctx) = 0;
  virtual void exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext *ctx) = 0;

  virtual void enterRangefunction(detect_type_functionParser::RangefunctionContext *ctx) = 0;
  virtual void exitRangefunction(detect_type_functionParser::RangefunctionContext *ctx) = 0;

  virtual void enterString(detect_type_functionParser::StringContext *ctx) = 0;
  virtual void exitString(detect_type_functionParser::StringContext *ctx) = 0;


};

