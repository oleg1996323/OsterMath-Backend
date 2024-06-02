#include <exception.h>
#include <ParseRulesParser.h>
#include <BaseErrorListener.h>
#include <DefaultErrorStrategy.h>

class ParsingStrategy: public antlr4::DefaultErrorStrategy{
    public:
    virtual void recover(antlr4::Parser *recognizer, std::exception_ptr e) override;

    /// Make sure we don't attempt to recover inline; if the parser
    ///  successfully recovers, it won't throw an exception.
    virtual antlr4::Token* recoverInline(antlr4::Parser *recognizer) override;

    /// <summary>
    /// Make sure we don't attempt to recover from problems in subrules. </summary>
    virtual void sync(antlr4::Parser *recognizer) override;

    virtual void reportNoViableAlternative(antlr4::Parser *recognizer, const antlr4::NoViableAltException &e) override;
};



void ParsingStrategy::recover(antlr4::Parser *recognizer, std::exception_ptr e) {
    using namespace antlr4;
    ParserRuleContext *context = recognizer->getContext();
    do {
        context->exception = e;
        if (context->parent == nullptr)
        break;
        context = static_cast<ParserRuleContext *>(context->parent);
    } while (true);

    try {
        std::rethrow_exception(e); // Throw the exception to be able to catch and rethrow nested.
    #if defined(_MSC_FULL_VER) && _MSC_FULL_VER < 190023026
    } catch (RecognitionException &inner) {
        throw ParseCancellationException(inner.what());
    #else
    } catch (RecognitionException & /*inner*/) {
        std::throw_with_nested(ParseCancellationException());
    #endif
    }
}

antlr4::Token* ParsingStrategy::recoverInline(antlr4::Parser *recognizer)  {
    using namespace antlr4;
    InputMismatchException e(recognizer);
    std::exception_ptr exception = std::make_exception_ptr(e);

    ParserRuleContext *context = recognizer->getContext();
    do {
        context->exception = exception;
        if (context->parent == nullptr)
        break;
        context = static_cast<ParserRuleContext *>(context->parent);
    } while (true);

    try {
        throw e;
    #if defined(_MSC_FULL_VER) && _MSC_FULL_VER < 190023026
    } catch (InputMismatchException &inner) {
        throw ParseCancellationException(inner.what());
    #else
    } catch (InputMismatchException & /*inner*/) {
        std::throw_with_nested(ParseCancellationException());
    #endif
    }
}

void ParsingStrategy::sync(antlr4::Parser * parser) {
}

void ParsingStrategy::reportNoViableAlternative(antlr4::Parser *recognizer, const antlr4::NoViableAltException &e){
    using namespace antlr4;
    TokenStream *tokens = recognizer->getTokenStream();
    std::string input;
    if (tokens != nullptr) {
        if (e.getStartToken()->getType() == Token::EOF) {
        input = "<EOF>";
        } else {
        input = tokens->getText(e.getStartToken(), e.getOffendingToken());
        }
    } else {
        input = "<unknown input>";
    }
    std::string msg = "no viable alternative at input " + escapeWSAndQuote(input);
    recognizer->notifyErrorListeners(e.getOffendingToken(), msg, std::make_exception_ptr(e));
}