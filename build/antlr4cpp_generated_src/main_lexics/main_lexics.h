
// Generated from /home/oster/Electrolisys/grammar/main_lexics.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  main_lexics : public antlr4::Lexer {
public:
  enum {
    VAR_TAG = 1, BEG_ARR = 2, END_ARR = 3, DOUBLE_QUOTE = 4, ESCAPED_DOUBLE_QUOTE = 5, 
    VARIABLE = 6, DATABASE = 7, LARGER = 8, LARGER_EQUAL = 9, EQUAL = 10, 
    LESS = 11, LESS_EQUAL = 12, SUMPRODUCT = 13, SUMPRODUCT_I = 14, SUM = 15, 
    SUM_I = 16, PRODUCT = 17, PRODUCT_I = 18, LN = 19, LG = 20, LOG_X = 21, 
    EXP = 22, SQRT = 23, PI = 24, COS = 25, SIN = 26, ASIN = 27, ACOS = 28, 
    FACTORIAL = 29, SEARCH_STRING = 30, CONTAIN_TEXT = 31, CONCAT = 32, 
    WEIBULL_DISTRIB = 33, GAUSS = 34, STD_NORM_DISTRIB = 35, NORM_DISTRIB = 36, 
    GAMMA = 37, GAMMA_REV = 38, ROOT_MEAN_SQUARE = 39, ROOT_MEAN_SQUARE_ERROR = 40, 
    AVERAGE = 41, MEDIAN = 42, PEARSON = 43, STRING_ARG = 44, STRING = 45, 
    WS = 46, EOL = 47, UINT = 48, Lb = 49, Rb = 50, COL = 51, SEPAR = 52, 
    ADD = 53, SUB = 54, MUL = 55, DIV = 56, POW = 57, QUOTE = 58, ASTERISK = 59, 
    EXPONENT = 60, FLOAT = 61, ID_NUMBER = 62
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
  void ESCAPED_DOUBLE_QUOTEAction(antlr4::RuleContext *context, size_t actionIndex);
  void VARIABLEAction(antlr4::RuleContext *context, size_t actionIndex);
  void DATABASEAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ARGAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

