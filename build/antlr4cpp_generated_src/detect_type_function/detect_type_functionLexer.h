
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  detect_type_functionLexer : public antlr4::Lexer {
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

  explicit detect_type_functionLexer(antlr4::CharStream *input);

  ~detect_type_functionLexer() override;


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

