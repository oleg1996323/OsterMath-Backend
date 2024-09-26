
// Generated from /home/oster/OsterMath-Backend/grammar/main_lexics.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  main_lexics : public antlr4::Lexer {
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

  explicit main_lexics(antlr4::CharStream *input);

  ~main_lexics() override;


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

