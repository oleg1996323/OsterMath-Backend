
// Generated from /home/oster/Electrolisys/grammar/bound_coefs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bound_coefsListener.h"


/**
 * This class provides an empty implementation of bound_coefsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  bound_coefsBaseListener : public bound_coefsListener {
public:

  virtual void enterFile(bound_coefsParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(bound_coefsParser::FileContext * /*ctx*/) override { }

  virtual void enterEq(bound_coefsParser::EqContext * /*ctx*/) override { }
  virtual void exitEq(bound_coefsParser::EqContext * /*ctx*/) override { }

  virtual void enterHdr(bound_coefsParser::HdrContext * /*ctx*/) override { }
  virtual void exitHdr(bound_coefsParser::HdrContext * /*ctx*/) override { }

  virtual void enterValues(bound_coefsParser::ValuesContext * /*ctx*/) override { }
  virtual void exitValues(bound_coefsParser::ValuesContext * /*ctx*/) override { }

  virtual void enterBound_coefs(bound_coefsParser::Bound_coefsContext * /*ctx*/) override { }
  virtual void exitBound_coefs(bound_coefsParser::Bound_coefsContext * /*ctx*/) override { }

  virtual void enterMain(bound_coefsParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(bound_coefsParser::MainContext * /*ctx*/) override { }

  virtual void enterUnaryOp(bound_coefsParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(bound_coefsParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterVariable(bound_coefsParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(bound_coefsParser::VariableContext * /*ctx*/) override { }

  virtual void enterNumber(bound_coefsParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(bound_coefsParser::NumberContext * /*ctx*/) override { }

  virtual void enterParens(bound_coefsParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(bound_coefsParser::ParensContext * /*ctx*/) override { }

  virtual void enterArrayDef(bound_coefsParser::ArrayDefContext * /*ctx*/) override { }
  virtual void exitArrayDef(bound_coefsParser::ArrayDefContext * /*ctx*/) override { }

  virtual void enterConstant(bound_coefsParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(bound_coefsParser::ConstantContext * /*ctx*/) override { }

  virtual void enterFunctionCall(bound_coefsParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(bound_coefsParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterPowerOp(bound_coefsParser::PowerOpContext * /*ctx*/) override { }
  virtual void exitPowerOp(bound_coefsParser::PowerOpContext * /*ctx*/) override { }

  virtual void enterBinaryOp(bound_coefsParser::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(bound_coefsParser::BinaryOpContext * /*ctx*/) override { }

  virtual void enterArray(bound_coefsParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(bound_coefsParser::ArrayContext * /*ctx*/) override { }

  virtual void enterPares(bound_coefsParser::ParesContext * /*ctx*/) override { }
  virtual void exitPares(bound_coefsParser::ParesContext * /*ctx*/) override { }

  virtual void enterNatlog(bound_coefsParser::NatlogContext * /*ctx*/) override { }
  virtual void exitNatlog(bound_coefsParser::NatlogContext * /*ctx*/) override { }

  virtual void enterDeclog(bound_coefsParser::DeclogContext * /*ctx*/) override { }
  virtual void exitDeclog(bound_coefsParser::DeclogContext * /*ctx*/) override { }

  virtual void enterBaselog(bound_coefsParser::BaselogContext * /*ctx*/) override { }
  virtual void exitBaselog(bound_coefsParser::BaselogContext * /*ctx*/) override { }

  virtual void enterExponent(bound_coefsParser::ExponentContext * /*ctx*/) override { }
  virtual void exitExponent(bound_coefsParser::ExponentContext * /*ctx*/) override { }

  virtual void enterSquareroot(bound_coefsParser::SquarerootContext * /*ctx*/) override { }
  virtual void exitSquareroot(bound_coefsParser::SquarerootContext * /*ctx*/) override { }

  virtual void enterSumproduct(bound_coefsParser::SumproductContext * /*ctx*/) override { }
  virtual void exitSumproduct(bound_coefsParser::SumproductContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

