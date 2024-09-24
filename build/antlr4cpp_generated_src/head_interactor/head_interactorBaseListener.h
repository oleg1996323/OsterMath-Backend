
// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "head_interactorListener.h"


/**
 * This class provides an empty implementation of head_interactorListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  head_interactorBaseListener : public head_interactorListener {
public:

  virtual void enterValue_type(head_interactorParser::Value_typeContext * /*ctx*/) override { }
  virtual void exitValue_type(head_interactorParser::Value_typeContext * /*ctx*/) override { }

  virtual void enterComparator(head_interactorParser::ComparatorContext * /*ctx*/) override { }
  virtual void exitComparator(head_interactorParser::ComparatorContext * /*ctx*/) override { }

  virtual void enterInput(head_interactorParser::InputContext * /*ctx*/) override { }
  virtual void exitInput(head_interactorParser::InputContext * /*ctx*/) override { }

  virtual void enterLine_input(head_interactorParser::Line_inputContext * /*ctx*/) override { }
  virtual void exitLine_input(head_interactorParser::Line_inputContext * /*ctx*/) override { }

  virtual void enterNode_access(head_interactorParser::Node_accessContext * /*ctx*/) override { }
  virtual void exitNode_access(head_interactorParser::Node_accessContext * /*ctx*/) override { }

  virtual void enterVariable(head_interactorParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(head_interactorParser::VariableContext * /*ctx*/) override { }

  virtual void enterVardefinition(head_interactorParser::VardefinitionContext * /*ctx*/) override { }
  virtual void exitVardefinition(head_interactorParser::VardefinitionContext * /*ctx*/) override { }

  virtual void enterComparision(head_interactorParser::ComparisionContext * /*ctx*/) override { }
  virtual void exitComparision(head_interactorParser::ComparisionContext * /*ctx*/) override { }

  virtual void enterLhs_comp(head_interactorParser::Lhs_compContext * /*ctx*/) override { }
  virtual void exitLhs_comp(head_interactorParser::Lhs_compContext * /*ctx*/) override { }

  virtual void enterRhs_comp(head_interactorParser::Rhs_compContext * /*ctx*/) override { }
  virtual void exitRhs_comp(head_interactorParser::Rhs_compContext * /*ctx*/) override { }

  virtual void enterExpr_comp(head_interactorParser::Expr_compContext * /*ctx*/) override { }
  virtual void exitExpr_comp(head_interactorParser::Expr_compContext * /*ctx*/) override { }

  virtual void enterUnaryOp(head_interactorParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(head_interactorParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterParens(head_interactorParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(head_interactorParser::ParensContext * /*ctx*/) override { }

  virtual void enterLiteral(head_interactorParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(head_interactorParser::LiteralContext * /*ctx*/) override { }

  virtual void enterFunctionCall(head_interactorParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(head_interactorParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVariableInExpr(head_interactorParser::VariableInExprContext * /*ctx*/) override { }
  virtual void exitVariableInExpr(head_interactorParser::VariableInExprContext * /*ctx*/) override { }

  virtual void enterBinaryOp(head_interactorParser::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(head_interactorParser::BinaryOpContext * /*ctx*/) override { }

  virtual void enterArray(head_interactorParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(head_interactorParser::ArrayContext * /*ctx*/) override { }

  virtual void enterItemArray(head_interactorParser::ItemArrayContext * /*ctx*/) override { }
  virtual void exitItemArray(head_interactorParser::ItemArrayContext * /*ctx*/) override { }

  virtual void enterNumber(head_interactorParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(head_interactorParser::NumberContext * /*ctx*/) override { }

  virtual void enterConstant(head_interactorParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(head_interactorParser::ConstantContext * /*ctx*/) override { }

  virtual void enterFunction(head_interactorParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(head_interactorParser::FunctionContext * /*ctx*/) override { }

  virtual void enterMultiargfunction(head_interactorParser::MultiargfunctionContext * /*ctx*/) override { }
  virtual void exitMultiargfunction(head_interactorParser::MultiargfunctionContext * /*ctx*/) override { }

  virtual void enterRangefunction(head_interactorParser::RangefunctionContext * /*ctx*/) override { }
  virtual void exitRangefunction(head_interactorParser::RangefunctionContext * /*ctx*/) override { }

  virtual void enterString(head_interactorParser::StringContext * /*ctx*/) override { }
  virtual void exitString(head_interactorParser::StringContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

