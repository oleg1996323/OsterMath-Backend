
// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  head_interactorParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, VARIABLE = 9, DATABASE = 10, WS = 11, EOL = 12, LARGER = 13, 
    LARGER_EQUAL = 14, EQUAL = 15, LESS = 16, LESS_EQUAL = 17, UINT = 18, 
    ADD = 19, SUB = 20, MUL = 21, DIV = 22, POW = 23, SUMPRODUCT = 24, SUMPRODUCT_I = 25, 
    SUM = 26, SUM_I = 27, PRODUCT = 28, PRODUCT_I = 29, LN = 30, LG = 31, 
    LOG_X = 32, EXP = 33, SQRT = 34, PI = 35, COS = 36, SIN = 37, ASIN = 38, 
    ACOS = 39, FACTORIAL = 40, QUOTE = 41, ASTERISK = 42, EXPONENT = 43, 
    FLOAT = 44, ID_NUMBER = 45, STRING = 46
  };

  enum {
    RuleValue_type = 0, RuleComparator = 1, RuleInput = 2, RuleLine_input = 3, 
    RuleNode_access = 4, RuleVariable = 5, RuleVardefinition = 6, RuleComparision = 7, 
    RuleLhs_comp = 8, RuleRhs_comp = 9, RuleExpr_comp = 10, RuleExpr = 11, 
    RuleArray = 12, RuleInput_array = 13, RuleNumber = 14, RuleConstant = 15, 
    RuleFunction = 16, RuleMultiargfunction = 17, RuleRangefunction = 18, 
    RuleString = 19
  };

  explicit head_interactorParser(antlr4::TokenStream *input);

  head_interactorParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~head_interactorParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Value_typeContext;
  class ComparatorContext;
  class InputContext;
  class Line_inputContext;
  class Node_accessContext;
  class VariableContext;
  class VardefinitionContext;
  class ComparisionContext;
  class Lhs_compContext;
  class Rhs_compContext;
  class Expr_compContext;
  class ExprContext;
  class ArrayContext;
  class Input_arrayContext;
  class NumberContext;
  class ConstantContext;
  class FunctionContext;
  class MultiargfunctionContext;
  class RangefunctionContext;
  class StringContext; 

  class  Value_typeContext : public antlr4::ParserRuleContext {
  public:
    Value_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayContext *array();
    ExprContext *expr();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Value_typeContext* value_type();

  class  ComparatorContext : public antlr4::ParserRuleContext {
  public:
    ComparatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LARGER();
    antlr4::tree::TerminalNode *LARGER_EQUAL();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_EQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparatorContext* comparator();

  class  InputContext : public antlr4::ParserRuleContext {
  public:
    InputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Line_inputContext *> line_input();
    Line_inputContext* line_input(size_t i);
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InputContext* input();

  class  Line_inputContext : public antlr4::ParserRuleContext {
  public:
    Line_inputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VardefinitionContext *vardefinition();
    ComparisionContext *comparision();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Line_inputContext* line_input();

  class  Node_accessContext : public antlr4::ParserRuleContext {
  public:
    Node_accessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UINT();
    antlr4::tree::TerminalNode* UINT(size_t i);

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
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *DATABASE();
    Node_accessContext *node_access();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  VardefinitionContext : public antlr4::ParserRuleContext {
  public:
    VardefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *EOL();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    Value_typeContext *value_type();
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *DATABASE();
    Node_accessContext *node_access();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VardefinitionContext* vardefinition();

  class  ComparisionContext : public antlr4::ParserRuleContext {
  public:
    ComparisionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lhs_compContext *lhs_comp();
    ComparatorContext *comparator();
    Rhs_compContext *rhs_comp();
    antlr4::tree::TerminalNode *EOL();
    antlr4::tree::TerminalNode *VARIABLE();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    Expr_compContext *expr_comp();
    antlr4::tree::TerminalNode *DATABASE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ComparisionContext* comparision();

  class  Lhs_compContext : public antlr4::ParserRuleContext {
  public:
    Lhs_compContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lhs_compContext* lhs_comp();

  class  Rhs_compContext : public antlr4::ParserRuleContext {
  public:
    Rhs_compContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rhs_compContext* rhs_comp();

  class  Expr_compContext : public antlr4::ParserRuleContext {
  public:
    Expr_compContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr_compContext* expr_comp();

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

    ExprContext *expr();
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
    std::vector<Input_arrayContext *> input_array();
    Input_arrayContext* input_array(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayContext* array();

  class  Input_arrayContext : public antlr4::ParserRuleContext {
  public:
    Input_arrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Input_arrayContext() = default;
    void copyFrom(Input_arrayContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ItemArrayContext : public Input_arrayContext {
  public:
    ItemArrayContext(Input_arrayContext *ctx);

    ArrayContext *array();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Input_arrayContext* input_array();

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
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  MultiargfunctionContext : public antlr4::ParserRuleContext {
  public:
    MultiargfunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUMPRODUCT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
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
    ExprContext *expr();
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

