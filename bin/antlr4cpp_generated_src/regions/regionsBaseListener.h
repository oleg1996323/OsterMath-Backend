
// Generated from /home/oster/Electrolisys/grammar/regions.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "regionsListener.h"


/**
 * This class provides an empty implementation of regionsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  regionsBaseListener : public regionsListener {
public:

  virtual void enterFile(regionsParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(regionsParser::FileContext * /*ctx*/) override { }

  virtual void enterHdr(regionsParser::HdrContext * /*ctx*/) override { }
  virtual void exitHdr(regionsParser::HdrContext * /*ctx*/) override { }

  virtual void enterData_bound(regionsParser::Data_boundContext * /*ctx*/) override { }
  virtual void exitData_bound(regionsParser::Data_boundContext * /*ctx*/) override { }

  virtual void enterConst_zone(regionsParser::Const_zoneContext * /*ctx*/) override { }
  virtual void exitConst_zone(regionsParser::Const_zoneContext * /*ctx*/) override { }

  virtual void enterVirial_coefs(regionsParser::Virial_coefsContext * /*ctx*/) override { }
  virtual void exitVirial_coefs(regionsParser::Virial_coefsContext * /*ctx*/) override { }

  virtual void enterValues(regionsParser::ValuesContext * /*ctx*/) override { }
  virtual void exitValues(regionsParser::ValuesContext * /*ctx*/) override { }

  virtual void enterBound_equation(regionsParser::Bound_equationContext * /*ctx*/) override { }
  virtual void exitBound_equation(regionsParser::Bound_equationContext * /*ctx*/) override { }

  virtual void enterTempbound(regionsParser::TempboundContext * /*ctx*/) override { }
  virtual void exitTempbound(regionsParser::TempboundContext * /*ctx*/) override { }

  virtual void enterMain(regionsParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(regionsParser::MainContext * /*ctx*/) override { }

  virtual void enterUnaryOp(regionsParser::UnaryOpContext * /*ctx*/) override { }
  virtual void exitUnaryOp(regionsParser::UnaryOpContext * /*ctx*/) override { }

  virtual void enterVariable(regionsParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(regionsParser::VariableContext * /*ctx*/) override { }

  virtual void enterNumber(regionsParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(regionsParser::NumberContext * /*ctx*/) override { }

  virtual void enterParens(regionsParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(regionsParser::ParensContext * /*ctx*/) override { }

  virtual void enterArrayDef(regionsParser::ArrayDefContext * /*ctx*/) override { }
  virtual void exitArrayDef(regionsParser::ArrayDefContext * /*ctx*/) override { }

  virtual void enterConstant(regionsParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(regionsParser::ConstantContext * /*ctx*/) override { }

  virtual void enterFunctionCall(regionsParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(regionsParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterPowerOp(regionsParser::PowerOpContext * /*ctx*/) override { }
  virtual void exitPowerOp(regionsParser::PowerOpContext * /*ctx*/) override { }

  virtual void enterBinaryOp(regionsParser::BinaryOpContext * /*ctx*/) override { }
  virtual void exitBinaryOp(regionsParser::BinaryOpContext * /*ctx*/) override { }

  virtual void enterArray(regionsParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(regionsParser::ArrayContext * /*ctx*/) override { }

  virtual void enterPares(regionsParser::ParesContext * /*ctx*/) override { }
  virtual void exitPares(regionsParser::ParesContext * /*ctx*/) override { }

  virtual void enterNatlog(regionsParser::NatlogContext * /*ctx*/) override { }
  virtual void exitNatlog(regionsParser::NatlogContext * /*ctx*/) override { }

  virtual void enterDeclog(regionsParser::DeclogContext * /*ctx*/) override { }
  virtual void exitDeclog(regionsParser::DeclogContext * /*ctx*/) override { }

  virtual void enterBaselog(regionsParser::BaselogContext * /*ctx*/) override { }
  virtual void exitBaselog(regionsParser::BaselogContext * /*ctx*/) override { }

  virtual void enterExponent(regionsParser::ExponentContext * /*ctx*/) override { }
  virtual void exitExponent(regionsParser::ExponentContext * /*ctx*/) override { }

  virtual void enterSquareroot(regionsParser::SquarerootContext * /*ctx*/) override { }
  virtual void exitSquareroot(regionsParser::SquarerootContext * /*ctx*/) override { }

  virtual void enterSumproduct(regionsParser::SumproductContext * /*ctx*/) override { }
  virtual void exitSumproduct(regionsParser::SumproductContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

