
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  detect_type_function : public antlr4::Parser {
public:
  enum {
    VAR_TAG = 1, BEG_ARR = 2, END_ARR = 3, DOUBLE_QUOTE = 4, VARIABLE = 5, 
    DATABASE = 6, LARGER = 7, LARGER_EQUAL = 8, EQUAL = 9, LESS = 10, LESS_EQUAL = 11, 
    SUMPRODUCT = 12, SUMPRODUCT_I = 13, SUM = 14, SUM_I = 15, PRODUCT = 16, 
    PRODUCT_I = 17, LN = 18, LG = 19, LOG_X = 20, EXP = 21, SQRT = 22, PI = 23, 
    COS = 24, SIN = 25, ASIN = 26, ACOS = 27, FACTORIAL = 28, STRING = 29, 
    WS = 30, EOL = 31, UINT = 32, Lb = 33, Rb = 34, COL = 35, SEPAR = 36, 
    ADD = 37, SUB = 38, MUL = 39, DIV = 40, POW = 41, QUOTE = 42, ASTERISK = 43, 
    EXPONENT = 44, FLOAT = 45, ID_NUMBER = 46
  };

  enum {
    RuleLine_input = 0, RuleNode_access = 1, RuleVariable = 2, RuleExpr = 3, 
    RuleArray = 4, RuleNumber = 5, RuleConstant = 6, RuleFunction = 7, RuleMultiargfunction = 8, 
    RuleRangefunction = 9, RuleString = 10
  };

  explicit detect_type_function(antlr4::TokenStream *input);

  detect_type_function(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~detect_type_function() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Line_inputContext;
  class Node_accessContext;
  class VariableContext;
  class ExprContext;
  class ArrayContext;
  class NumberContext;
  class ConstantContext;
  class FunctionContext;
  class MultiargfunctionContext;
  class RangefunctionContext;
  class StringContext; 

  class  Line_inputContext : public antlr4::ParserRuleContext {
  public:
    Line_inputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    ArrayContext *array();
    ExprContext *expr();
    StringContext *string();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *EOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Line_inputContext* line_input();

  class  Node_accessContext : public antlr4::ParserRuleContext {
  public:
    Node_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Lb();
    antlr4::tree::TerminalNode *Rb();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UINT();
    antlr4::tree::TerminalNode* UINT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEPAR();
    antlr4::tree::TerminalNode* SEPAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Node_accessContext* node_access();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *VAR_TAG();
    antlr4::tree::TerminalNode *Lb();
    antlr4::tree::TerminalNode *Rb();
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *DATABASE();
    Node_accessContext *node_access();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryOpContext : public ExprContext {
  public:
    UnaryOpContext(ExprContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ParensContext : public ExprContext {
  public:
    ParensContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *Lb();
    ExprContext *expr();
    antlr4::tree::TerminalNode *Rb();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LiteralContext : public ExprContext {
  public:
    LiteralContext(ExprContext *ctx);

    NumberContext *number();
    ConstantContext *constant();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FunctionCallContext : public ExprContext {
  public:
    FunctionCallContext(ExprContext *ctx);

    FunctionContext *function();
    MultiargfunctionContext *multiargfunction();
    RangefunctionContext *rangefunction();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VariableInExprContext : public ExprContext {
  public:
    VariableInExprContext(ExprContext *ctx);

    VariableContext *variable();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BinaryOpContext : public ExprContext {
  public:
    BinaryOpContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ArrayContext : public antlr4::ParserRuleContext {
  public:
    ArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEG_ARR();
    antlr4::tree::TerminalNode *END_ARR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<ArrayContext *> array();
    ArrayContext* array(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEPAR();
    antlr4::tree::TerminalNode* SEPAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayContext* array();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberContext* number();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PI();
    antlr4::tree::TerminalNode *EXP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstantContext* constant();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LN();
    antlr4::tree::TerminalNode *Lb();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *Rb();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *LG();
    antlr4::tree::TerminalNode *EXP();
    antlr4::tree::TerminalNode *SQRT();
    antlr4::tree::TerminalNode *COS();
    antlr4::tree::TerminalNode *SIN();
    antlr4::tree::TerminalNode *ACOS();
    antlr4::tree::TerminalNode *ASIN();
    antlr4::tree::TerminalNode *FACTORIAL();
    antlr4::tree::TerminalNode *LOG_X();
    antlr4::tree::TerminalNode *SEPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  MultiargfunctionContext : public antlr4::ParserRuleContext {
  public:
    MultiargfunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUMPRODUCT();
    antlr4::tree::TerminalNode *Lb();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEPAR();
    antlr4::tree::TerminalNode* SEPAR(size_t i);
    antlr4::tree::TerminalNode *Rb();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *SUM();
    antlr4::tree::TerminalNode *PRODUCT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiargfunctionContext* multiargfunction();

  class  RangefunctionContext : public antlr4::ParserRuleContext {
  public:
    RangefunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUM_I();
    antlr4::tree::TerminalNode *Lb();
    ExprContext *expr();
    antlr4::tree::TerminalNode *Rb();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *PRODUCT_I();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangefunctionContext* rangefunction();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DOUBLE_QUOTE();
    antlr4::tree::TerminalNode* DOUBLE_QUOTE(size_t i);
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringContext* string();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

