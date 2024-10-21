
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

  virtual void enterValue_type(head_interactor::Value_typeContext * /*ctx*/) override { }
  virtual void exitValue_type(head_interactor::Value_typeContext * /*ctx*/) override { }

  virtual void enterInput(head_interactor::InputContext * /*ctx*/) override { }
  virtual void exitInput(head_interactor::InputContext * /*ctx*/) override { }

  virtual void enterLine_input(head_interactor::Line_inputContext * /*ctx*/) override { }
  virtual void exitLine_input(head_interactor::Line_inputContext * /*ctx*/) override { }

  virtual void enterVardefinition(head_interactor::VardefinitionContext * /*ctx*/) override { }
  virtual void exitVardefinition(head_interactor::VardefinitionContext * /*ctx*/) override { }

  virtual void enterComparator(head_interactor::ComparatorContext * /*ctx*/) override { }
  virtual void exitComparator(head_interactor::ComparatorContext * /*ctx*/) override { }

  virtual void enterComparision(head_interactor::ComparisionContext * /*ctx*/) override { }
  virtual void exitComparision(head_interactor::ComparisionContext * /*ctx*/) override { }

  virtual void enterLhs_comp(head_interactor::Lhs_compContext * /*ctx*/) override { }
  virtual void exitLhs_comp(head_interactor::Lhs_compContext * /*ctx*/) override { }

  virtual void enterRhs_comp(head_interactor::Rhs_compContext * /*ctx*/) override { }
  virtual void exitRhs_comp(head_interactor::Rhs_compContext * /*ctx*/) override { }

  virtual void enterExpr_comp(head_interactor::Expr_compContext * /*ctx*/) override { }
  virtual void exitExpr_comp(head_interactor::Expr_compContext * /*ctx*/) override { }

  virtual void enterArray(head_interactor::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(head_interactor::ArrayContext * /*ctx*/) override { }

  virtual void enterItemArray(head_interactor::ItemArrayContext * /*ctx*/) override { }
  virtual void exitItemArray(head_interactor::ItemArrayContext * /*ctx*/) override { }

  virtual void enterNode_access(head_interactor::Node_accessContext * /*ctx*/) override { }
  virtual void exitNode_access(head_interactor::Node_accessContext * /*ctx*/) override { }

  virtual void enterVariable(head_interactor::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(head_interactor::VariableContext * /*ctx*/) override { }

  virtual void enterUnaryOp(head_interactor::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(head_interactor::UnaryOpContext * /*ctx*/) override { }

  virtual void enterParens(head_interactor::ParensContext * /*ctx*/) override { }
  virtual void exitParens(head_interactor::ParensContext * /*ctx*/) override { }

  virtual void enterLiteral(head_interactor::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(head_interactor::LiteralContext * /*ctx*/) override { }

  virtual void enterFunctionCall(head_interactor::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(head_interactor::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVariableInExpr(head_interactor::VariableInExprContext * /*ctx*/) override { }
  virtual void exitVariableInExpr(head_interactor::VariableInExprContext * /*ctx*/) override { }

  virtual void enterBinaryOp(head_interactor::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(head_interactor::BinaryOpContext * /*ctx*/) override { }

  virtual void enterNumber(head_interactor::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(head_interactor::NumberContext * /*ctx*/) override { }

  virtual void enterConstant(head_interactor::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(head_interactor::ConstantContext * /*ctx*/) override { }

  virtual void enterFunction(head_interactor::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(head_interactor::FunctionContext * /*ctx*/) override { }

  virtual void enterMultiargfunction(head_interactor::MultiargfunctionContext * /*ctx*/) override { }
  virtual void exitMultiargfunction(head_interactor::MultiargfunctionContext * /*ctx*/) override { }

  virtual void enterRangefunction(head_interactor::RangefunctionContext * /*ctx*/) override { }
  virtual void exitRangefunction(head_interactor::RangefunctionContext * /*ctx*/) override { }

  virtual void enterString(head_interactor::StringContext * /*ctx*/) override { }
  virtual void exitString(head_interactor::StringContext * /*ctx*/) override { }

  virtual void enterString_arg(head_interactor::String_argContext * /*ctx*/) override { }
  virtual void exitString_arg(head_interactor::String_argContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

