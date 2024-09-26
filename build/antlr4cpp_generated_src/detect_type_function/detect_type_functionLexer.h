
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  detect_type_functionLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    VARIABLE = 8, DATABASE = 9, LARGER = 10, LARGER_EQUAL = 11, EQUAL = 12, 
    LESS = 13, LESS_EQUAL = 14, SUMPRODUCT = 15, SUMPRODUCT_I = 16, SUM = 17, 
    SUM_I = 18, PRODUCT = 19, PRODUCT_I = 20, LN = 21, LG = 22, LOG_X = 23, 
    EXP = 24, SQRT = 25, PI = 26, COS = 27, SIN = 28, ASIN = 29, ACOS = 30, 
    FACTORIAL = 31, STRING = 32, WS = 33, EOL = 34, UINT = 35, ADD = 36, 
    SUB = 37, MUL = 38, DIV = 39, POW = 40, QUOTE = 41, ASTERISK = 42, EXPONENT = 43, 
    FLOAT = 44, ID_NUMBER = 45
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

