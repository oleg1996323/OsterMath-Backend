
// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  head_interactorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, VARIABLE = 9, DATABASE = 10, LARGER = 11, LARGER_EQUAL = 12, 
    EQUAL = 13, LESS = 14, LESS_EQUAL = 15, SUMPRODUCT = 16, SUMPRODUCT_I = 17, 
    SUM = 18, SUM_I = 19, PRODUCT = 20, PRODUCT_I = 21, LN = 22, LG = 23, 
    LOG_X = 24, EXP = 25, SQRT = 26, PI = 27, COS = 28, SIN = 29, ASIN = 30, 
    ACOS = 31, FACTORIAL = 32, STRING = 33, WS = 34, EOL = 35, UINT = 36, 
    ADD = 37, SUB = 38, MUL = 39, DIV = 40, POW = 41, QUOTE = 42, ASTERISK = 43, 
    EXPONENT = 44, FLOAT = 45, ID_NUMBER = 46
  };

  explicit head_interactorLexer(antlr4::CharStream *input);

  ~head_interactorLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void VARIABLEAction(antlr4::RuleContext *context, size_t actionIndex);
  void DATABASEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

