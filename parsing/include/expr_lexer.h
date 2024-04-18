#pragma once
#include "def.h"
#include "ParseRulesLexer.h"

class Lexer: public ParseRulesLexer{
public:
    Lexer(antlr4::ANTLRInputStream& stream):ParseRulesLexer(&stream)
    {
        token_stream_ = std::make_unique<antlr4::CommonTokenStream>(this);
    }

    void SetStdInputStream(antlr4::ANTLRInputStream& stream){
        this->setInputStream(&stream); 
    }

    antlr4::CommonTokenStream* GetCommonTokenStream() const{
        return token_stream_.get();
    }

private:
    std::unique_ptr<antlr4::CommonTokenStream> token_stream_;
    TypeFile type_;
};