
// Generated from /home/oster/Electrolisys/grammar/bound_coefs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  bound_coefsLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, SUMPRODUCT = 6, LN = 7, 
    LG = 8, LOG_X = 9, EXP = 10, SQRT = 11, ADD = 12, SUB = 13, MUL = 14, 
    DIV = 15, POW = 16, STRING = 17, VARIABLE = 18, VARIABLE_RANGE = 19, 
    WS = 20, EOL = 21, NUMBER = 22, CONSTANTS = 23, PI = 24
  };

  explicit bound_coefsLexer(antlr4::CharStream *input);

  ~bound_coefsLexer() override;


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

