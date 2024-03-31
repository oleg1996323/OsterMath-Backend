
// Generated from /home/oster/Electrolisys/grammar/bound_coefs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bound_coefsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by bound_coefsParser.
 */
class  bound_coefsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(bound_coefsParser::FileContext *ctx) = 0;
  virtual void exitFile(bound_coefsParser::FileContext *ctx) = 0;

  virtual void enterEq(bound_coefsParser::EqContext *ctx) = 0;
  virtual void exitEq(bound_coefsParser::EqContext *ctx) = 0;

  virtual void enterHdr(bound_coefsParser::HdrContext *ctx) = 0;
  virtual void exitHdr(bound_coefsParser::HdrContext *ctx) = 0;

  virtual void enterValues(bound_coefsParser::ValuesContext *ctx) = 0;
  virtual void exitValues(bound_coefsParser::ValuesContext *ctx) = 0;

  virtual void enterBound_coefs(bound_coefsParser::Bound_coefsContext *ctx) = 0;
  virtual void exitBound_coefs(bound_coefsParser::Bound_coefsContext *ctx) = 0;

  virtual void enterMain(bound_coefsParser::MainContext *ctx) = 0;
  virtual void exitMain(bound_coefsParser::MainContext *ctx) = 0;

  virtual void enterUnaryOp(bound_coefsParser::UnaryOpContext *ctx) = 0;
  virtual void exitUnaryOp(bound_coefsParser::UnaryOpContext *ctx) = 0;

  virtual void enterVariable(bound_coefsParser::VariableContext *ctx) = 0;
  virtual void exitVariable(bound_coefsParser::VariableContext *ctx) = 0;

  virtual void enterNumber(bound_coefsParser::NumberContext *ctx) = 0;
  virtual void exitNumber(bound_coefsParser::NumberContext *ctx) = 0;

  virtual void enterParens(bound_coefsParser::ParensContext *ctx) = 0;
  virtual void exitParens(bound_coefsParser::ParensContext *ctx) = 0;

  virtual void enterArrayDef(bound_coefsParser::ArrayDefContext *ctx) = 0;
  virtual void exitArrayDef(bound_coefsParser::ArrayDefContext *ctx) = 0;

  virtual void enterConstant(bound_coefsParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(bound_coefsParser::ConstantContext *ctx) = 0;

  virtual void enterFunctionCall(bound_coefsParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(bound_coefsParser::FunctionCallContext *ctx) = 0;

  virtual void enterPowerOp(bound_coefsParser::PowerOpContext *ctx) = 0;
  virtual void exitPowerOp(bound_coefsParser::PowerOpContext *ctx) = 0;

  virtual void enterBinaryOp(bound_coefsParser::BinaryOpContext *ctx) = 0;
  virtual void exitBinaryOp(bound_coefsParser::BinaryOpContext *ctx) = 0;

  virtual void enterArray(bound_coefsParser::ArrayContext *ctx) = 0;
  virtual void exitArray(bound_coefsParser::ArrayContext *ctx) = 0;

  virtual void enterPares(bound_coefsParser::ParesContext *ctx) = 0;
  virtual void exitPares(bound_coefsParser::ParesContext *ctx) = 0;

  virtual void enterNatlog(bound_coefsParser::NatlogContext *ctx) = 0;
  virtual void exitNatlog(bound_coefsParser::NatlogContext *ctx) = 0;

  virtual void enterDeclog(bound_coefsParser::DeclogContext *ctx) = 0;
  virtual void exitDeclog(bound_coefsParser::DeclogContext *ctx) = 0;

  virtual void enterBaselog(bound_coefsParser::BaselogContext *ctx) = 0;
  virtual void exitBaselog(bound_coefsParser::BaselogContext *ctx) = 0;

  virtual void enterExponent(bound_coefsParser::ExponentContext *ctx) = 0;
  virtual void exitExponent(bound_coefsParser::ExponentContext *ctx) = 0;

  virtual void enterSquareroot(bound_coefsParser::SquarerootContext *ctx) = 0;
  virtual void exitSquareroot(bound_coefsParser::SquarerootContext *ctx) = 0;

  virtual void enterSumproduct(bound_coefsParser::SumproductContext *ctx) = 0;
  virtual void exitSumproduct(bound_coefsParser::SumproductContext *ctx) = 0;


};

