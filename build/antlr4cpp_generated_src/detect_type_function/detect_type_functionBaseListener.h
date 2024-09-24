
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

  virtual void enterValue_type(detect_type_functionParser::Value_typeContext * /*ctx*/) override { }
  virtual void exitValue_type(detect_type_functionParser::Value_typeContext * /*ctx*/) override { }

  virtual void enterComparator(detect_type_functionParser::ComparatorContext * /*ctx*/) override { }
  virtual void exitComparator(detect_type_functionParser::ComparatorContext * /*ctx*/) override { }

  virtual void enterInput(detect_type_functionParser::InputContext * /*ctx*/) override { }
  virtual void exitInput(detect_type_functionParser::InputContext * /*ctx*/) override { }

  virtual void enterLine_input(detect_type_functionParser::Line_inputContext * /*ctx*/) override { }
  virtual void exitLine_input(detect_type_functionParser::Line_inputContext * /*ctx*/) override { }

  virtual void enterNode_access(detect_type_functionParser::Node_accessContext * /*ctx*/) override { }
  virtual void exitNode_access(detect_type_functionParser::Node_accessContext * /*ctx*/) override { }

  virtual void enterVariable(detect_type_functionParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(detect_type_functionParser::VariableContext * /*ctx*/) override { }

  virtual void enterVardefinition(detect_type_functionParser::VardefinitionContext * /*ctx*/) override { }
  virtual void exitVardefinition(detect_type_functionParser::VardefinitionContext * /*ctx*/) override { }

  virtual void enterComparision(detect_type_functionParser::ComparisionContext * /*ctx*/) override { }
  virtual void exitComparision(detect_type_functionParser::ComparisionContext * /*ctx*/) override { }

  virtual void enterLhs_comp(detect_type_functionParser::Lhs_compContext * /*ctx*/) override { }
  virtual void exitLhs_comp(detect_type_functionParser::Lhs_compContext * /*ctx*/) override { }

  virtual void enterRhs_comp(detect_type_functionParser::Rhs_compContext * /*ctx*/) override { }
  virtual void exitRhs_comp(detect_type_functionParser::Rhs_compContext * /*ctx*/) override { }

  virtual void enterExpr_comp(detect_type_functionParser::Expr_compContext * /*ctx*/) override { }
  virtual void exitExpr_comp(detect_type_functionParser::Expr_compContext * /*ctx*/) override { }

  virtual void enterUnaryOp(detect_type_functionParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(detect_type_functionParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterParens(detect_type_functionParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(detect_type_functionParser::ParensContext * /*ctx*/) override { }

  virtual void enterLiteral(detect_type_functionParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(detect_type_functionParser::LiteralContext * /*ctx*/) override { }

  virtual void enterFunctionCall(detect_type_functionParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(detect_type_functionParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVariableInExpr(detect_type_functionParser::VariableInExprContext * /*ctx*/) override { }
  virtual void exitVariableInExpr(detect_type_functionParser::VariableInExprContext * /*ctx*/) override { }

  virtual void enterBinaryOp(detect_type_functionParser::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(detect_type_functionParser::BinaryOpContext * /*ctx*/) override { }

  virtual void enterArray(detect_type_functionParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(detect_type_functionParser::ArrayContext * /*ctx*/) override { }

  virtual void enterItemArray(detect_type_functionParser::ItemArrayContext * /*ctx*/) override { }
  virtual void exitItemArray(detect_type_functionParser::ItemArrayContext * /*ctx*/) override { }

  virtual void enterNumber(detect_type_functionParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(detect_type_functionParser::NumberContext * /*ctx*/) override { }

  virtual void enterConstant(detect_type_functionParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(detect_type_functionParser::ConstantContext * /*ctx*/) override { }

  virtual void enterFunction(detect_type_functionParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(detect_type_functionParser::FunctionContext * /*ctx*/) override { }

  virtual void enterMultiargfunction(detect_type_functionParser::MultiargfunctionContext * /*ctx*/) override { }
  virtual void exitMultiargfunction(detect_type_functionParser::MultiargfunctionContext * /*ctx*/) override { }

  virtual void enterRangefunction(detect_type_functionParser::RangefunctionContext * /*ctx*/) override { }
  virtual void exitRangefunction(detect_type_functionParser::RangefunctionContext * /*ctx*/) override { }

  virtual void enterString(detect_type_functionParser::StringContext * /*ctx*/) override { }
  virtual void exitString(detect_type_functionParser::StringContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

