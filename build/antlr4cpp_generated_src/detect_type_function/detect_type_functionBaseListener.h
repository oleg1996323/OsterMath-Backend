
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "detect_type_functionListener.h"


/**
 * This class provides an empty implementation of detect_type_functionListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  detect_type_functionBaseListener : public detect_type_functionListener {
public:

  virtual void enterLine_input(detect_type_function::Line_inputContext * /*ctx*/) override { }
  virtual void exitLine_input(detect_type_function::Line_inputContext * /*ctx*/) override { }

  virtual void enterArray(detect_type_function::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(detect_type_function::ArrayContext * /*ctx*/) override { }

  virtual void enterNode_access(detect_type_function::Node_accessContext * /*ctx*/) override { }
  virtual void exitNode_access(detect_type_function::Node_accessContext * /*ctx*/) override { }

  virtual void enterVariable(detect_type_function::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(detect_type_function::VariableContext * /*ctx*/) override { }

  virtual void enterUnaryOp(detect_type_function::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(detect_type_function::UnaryOpContext * /*ctx*/) override { }

  virtual void enterParens(detect_type_function::ParensContext * /*ctx*/) override { }
  virtual void exitParens(detect_type_function::ParensContext * /*ctx*/) override { }

  virtual void enterLiteral(detect_type_function::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(detect_type_function::LiteralContext * /*ctx*/) override { }

  virtual void enterFunctionCall(detect_type_function::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(detect_type_function::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVariableInExpr(detect_type_function::VariableInExprContext * /*ctx*/) override { }
  virtual void exitVariableInExpr(detect_type_function::VariableInExprContext * /*ctx*/) override { }

  virtual void enterBinaryOp(detect_type_function::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(detect_type_function::BinaryOpContext * /*ctx*/) override { }

  virtual void enterNumber(detect_type_function::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(detect_type_function::NumberContext * /*ctx*/) override { }

  virtual void enterConstant(detect_type_function::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(detect_type_function::ConstantContext * /*ctx*/) override { }

  virtual void enterFunction(detect_type_function::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(detect_type_function::FunctionContext * /*ctx*/) override { }

  virtual void enterMultiargfunction(detect_type_function::MultiargfunctionContext * /*ctx*/) override { }
  virtual void exitMultiargfunction(detect_type_function::MultiargfunctionContext * /*ctx*/) override { }

  virtual void enterRangefunction(detect_type_function::RangefunctionContext * /*ctx*/) override { }
  virtual void exitRangefunction(detect_type_function::RangefunctionContext * /*ctx*/) override { }

  virtual void enterString(detect_type_function::StringContext * /*ctx*/) override { }
  virtual void exitString(detect_type_function::StringContext * /*ctx*/) override { }

  virtual void enterString_arg(detect_type_function::String_argContext * /*ctx*/) override { }
  virtual void exitString_arg(detect_type_function::String_argContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

