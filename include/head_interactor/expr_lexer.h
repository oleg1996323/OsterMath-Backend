#pragma once
#include "def.h"
#include "main_lexics.h"

class Lexer: public main_lexics{
public:
    Lexer(antlr4::ANTLRInputStream& stream):main_lexics(&stream)
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
};