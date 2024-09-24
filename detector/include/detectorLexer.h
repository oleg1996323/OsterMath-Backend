#pragma once
#include "def.h"
#include "detect_type_functionLexer.h"

namespace expression{

class Lexer: public detect_type_functionLexer{
public:
    Lexer(antlr4::ANTLRInputStream& stream):detect_type_functionLexer(&stream)
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
}