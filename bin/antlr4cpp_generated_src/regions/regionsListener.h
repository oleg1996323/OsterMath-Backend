
// Generated from /home/oster/Electrolisys/grammar/regions.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "regionsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by regionsParser.
 */
class  regionsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(regionsParser::FileContext *ctx) = 0;
  virtual void exitFile(regionsParser::FileContext *ctx) = 0;

  virtual void enterHdr(regionsParser::HdrContext *ctx) = 0;
  virtual void exitHdr(regionsParser::HdrContext *ctx) = 0;

  virtual void enterData_bound(regionsParser::Data_boundContext *ctx) = 0;
  virtual void exitData_bound(regionsParser::Data_boundContext *ctx) = 0;

  virtual void enterConst_zone(regionsParser::Const_zoneContext *ctx) = 0;
  virtual void exitConst_zone(regionsParser::Const_zoneContext *ctx) = 0;

  virtual void enterVirial_coefs(regionsParser::Virial_coefsContext *ctx) = 0;
  virtual void exitVirial_coefs(regionsParser::Virial_coefsContext *ctx) = 0;

  virtual void enterValues(regionsParser::ValuesContext *ctx) = 0;
  virtual void exitValues(regionsParser::ValuesContext *ctx) = 0;

  virtual void enterBound_equation(regionsParser::Bound_equationContext *ctx) = 0;
  virtual void exitBound_equation(regionsParser::Bound_equationContext *ctx) = 0;

  virtual void enterTempbound(regionsParser::TempboundContext *ctx) = 0;
  virtual void exitTempbound(regionsParser::TempboundContext *ctx) = 0;

  virtual void enterMain(regionsParser::MainContext *ctx) = 0;
  virtual void exitMain(regionsParser::MainContext *ctx) = 0;

  virtual void enterUnaryOp(regionsParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(regionsParser::UnaryOpContext *ctx) = 0;

  virtual void enterVariable(regionsParser::VariableContext *ctx) = 0;
  virtual void exitVariable(regionsParser::VariableContext *ctx) = 0;

  virtual void enterNumber(regionsParser::NumberContext *ctx) = 0;
  virtual void exitNumber(regionsParser::NumberContext *ctx) = 0;

  virtual void enterParens(regionsParser::ParensContext *ctx) = 0;
  virtual void exitParens(regionsParser::ParensContext *ctx) = 0;

  virtual void enterArrayDef(regionsParser::ArrayDefContext *ctx) = 0;
  virtual void exitArrayDef(regionsParser::ArrayDefContext *ctx) = 0;

  virtual void enterConstant(regionsParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(regionsParser::ConstantContext *ctx) = 0;

  virtual void enterFunctionCall(regionsParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(regionsParser::FunctionCallContext *ctx) = 0;

  virtual void enterPowerOp(regionsParser::PowerOpContext *ctx) = 0;
  virtual void exitPowerOp(regionsParser::PowerOpContext *ctx) = 0;

  virtual void enterBinaryOp(regionsParser::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(regionsParser::BinaryOpContext *ctx) = 0;

  virtual void enterArray(regionsParser::ArrayContext *ctx) = 0;
  virtual void exitArray(regionsParser::ArrayContext *ctx) = 0;

  virtual void enterPares(regionsParser::ParesContext *ctx) = 0;
  virtual void exitPares(regionsParser::ParesContext *ctx) = 0;

  virtual void enterNatlog(regionsParser::NatlogContext *ctx) = 0;
  virtual void exitNatlog(regionsParser::NatlogContext *ctx) = 0;

  virtual void enterDeclog(regionsParser::DeclogContext *ctx) = 0;
  virtual void exitDeclog(regionsParser::DeclogContext *ctx) = 0;

  virtual void enterBaselog(regionsParser::BaselogContext *ctx) = 0;
  virtual void exitBaselog(regionsParser::BaselogContext *ctx) = 0;

  virtual void enterExponent(regionsParser::ExponentContext *ctx) = 0;
  virtual void exitExponent(regionsParser::ExponentContext *ctx) = 0;

  virtual void enterSquareroot(regionsParser::SquarerootContext *ctx) = 0;
  virtual void exitSquareroot(regionsParser::SquarerootContext *ctx) = 0;

  virtual void enterSumproduct(regionsParser::SumproductContext *ctx) = 0;
  virtual void exitSumproduct(regionsParser::SumproductContext *ctx) = 0;


};

