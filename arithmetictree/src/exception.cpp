

// 'void ParsingStrategy::recover(antlr4::Parser *recognizer, std::exception_ptr e) {
//     using namespace antlr4;
//     ParserRuleContext *context = recognizer->getContext();
//     do {
//         context->exception = e;
//         if (context->parent == nullptr)
//         break;
//         context = static_cast<ParserRuleContext *>(context->parent);
//     } while (true);

//     try {
//         std::rethrow_exception(e); // Throw the exception to be able to catch and rethrow nested.
//     #if defined(_MSC_FULL_VER) && _MSC_FULL_VER < 190023026
//     } catch (RecognitionException &inner) {
//         throw ParseCancellationException(inner.what());
//     #else
//     } catch (RecognitionException & /*inner*/) {
//         std::throw_with_nested(ParseCancellationException());
//     #endif
//     }
// }

// antlr4::Token* ParsingStrategy::recoverInline(antlr4::Parser *recognizer)  {
//     using namespace antlr4;
//     InputMismatchException e(recognizer);
//     std::exception_ptr exception = std::make_exception_ptr(e);

//     ParserRuleContext *context = recognizer->getContext();
//     do {
//         context->exception = exception;
//         if (context->parent == nullptr)
//         break;
//         context = static_cast<ParserRuleContext *>(context->parent);
//     } while (true);

//     try {
//         throw e;
//     #if defined(_MSC_FULL_VER) && _MSC_FULL_VER < 190023026
//     } catch (InputMismatchException &inner) {
//         throw ParseCancellationException(inner.what());
//     #else
//     } catch (InputMismatchException & /*inner*/) {
//         std::throw_with_nested(ParseCancellationException());
//     #endif
//     }
// }

// void ParsingStrategy::sync(antlr4::Parser * parser) {
// }'