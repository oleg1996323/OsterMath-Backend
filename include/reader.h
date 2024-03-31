#include "def.h"
#include "ParseRulesLexer.h"
#include "ParseRulesListener.h"
#include "ParseRulesParser.h"

class Parser: public ParseRulesParser{
    Parser(antlr4::TokenStream* input):ParseRulesParser(input){

    }
};

class Lexer: public ParseRulesLexer{
    public:
    Lexer(antlr4::CharStream* input):ParseRulesLexer(input){

    }

    
};

class Listener: public ParseRulesListener{
    
};