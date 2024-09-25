
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  detect_type_functionLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    VARIABLE = 8, DATABASE = 9, WS = 10, EOL = 11, UINT = 12, ADD = 13, 
    SUB = 14, MUL = 15, DIV = 16, POW = 17, SUMPRODUCT = 18, SUMPRODUCT_I = 19, 
    SUM = 20, SUM_I = 21, PRODUCT = 22, PRODUCT_I = 23, LN = 24, LG = 25, 
    LOG_X = 26, EXP = 27, SQRT = 28, PI = 29, COS = 30, SIN = 31, ASIN = 32, 
    ACOS = 33, FACTORIAL = 34, QUOTE = 35, ASTERISK = 36, EXPONENT = 37, 
    FLOAT = 38, ID_NUMBER = 39, STRING = 40
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

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

