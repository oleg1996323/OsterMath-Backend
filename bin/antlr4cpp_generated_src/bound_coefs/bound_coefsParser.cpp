
// Generated from /home/oster/Electrolisys/grammar/bound_coefs.g4 by ANTLR 4.13.1


#include "bound_coefsListener.h"

#include "bound_coefsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Bound_coefsParserStaticData final {
  Bound_coefsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Bound_coefsParserStaticData(const Bound_coefsParserStaticData&) = delete;
  Bound_coefsParserStaticData(Bound_coefsParserStaticData&&) = delete;
  Bound_coefsParserStaticData& operator=(const Bound_coefsParserStaticData&) = delete;
  Bound_coefsParserStaticData& operator=(Bound_coefsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag bound_coefsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
Bound_coefsParserStaticData *bound_coefsParserStaticData = nullptr;

void bound_coefsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (bound_coefsParserStaticData != nullptr) {
    return;
  }
#else
  assert(bound_coefsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Bound_coefsParserStaticData>(
    std::vector<std::string>{
      "file", "eq", "hdr", "values", "bound_coefs", "main", "expr", "array", 
      "functions"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'['", "','", "']'", "'sumproduct'", "'Ln'", "'Lg'", 
      "'Log'", "'Exp'", "'Sqrt'", "'+'", "'-'", "'*'", "'/'", "'^'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "SUMPRODUCT", "LN", "LG", "LOG_X", "EXP", 
      "SQRT", "ADD", "SUB", "MUL", "DIV", "POW", "STRING", "VARIABLE", "VARIABLE_RANGE", 
      "WS", "EOL", "NUMBER", "CONSTANTS", "PI"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,24,192,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,1,0,1,0,1,0,1,0,1,1,1,1,3,1,25,8,1,1,1,1,1,1,1,4,1,30,8,
  	1,11,1,12,1,31,1,2,1,2,3,2,36,8,2,4,2,38,8,2,11,2,12,2,39,1,3,1,3,1,3,
  	1,3,3,3,46,8,3,4,3,48,8,3,11,3,12,3,49,1,3,1,3,4,3,54,8,3,11,3,12,3,55,
  	4,3,58,8,3,11,3,12,3,59,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,81,8,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,5,6,92,8,6,10,6,12,6,95,9,6,1,7,1,7,1,7,1,7,1,7,1,7,4,7,103,8,
  	7,11,7,12,7,104,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,116,8,8,1,8,1,
  	8,3,8,120,8,8,1,8,1,8,1,8,1,8,1,8,3,8,127,8,8,1,8,1,8,3,8,131,8,8,1,8,
  	1,8,1,8,1,8,1,8,3,8,138,8,8,1,8,1,8,3,8,142,8,8,1,8,1,8,3,8,146,8,8,1,
  	8,1,8,3,8,150,8,8,1,8,1,8,1,8,1,8,1,8,3,8,157,8,8,1,8,1,8,3,8,161,8,8,
  	1,8,1,8,1,8,1,8,1,8,3,8,168,8,8,1,8,1,8,3,8,172,8,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,5,8,183,8,8,10,8,12,8,186,9,8,1,8,1,8,3,8,190,8,8,1,
  	8,0,1,12,9,0,2,4,6,8,10,12,14,16,0,4,1,1,21,21,1,0,12,13,1,0,14,15,2,
  	0,18,18,22,23,221,0,18,1,0,0,0,2,29,1,0,0,0,4,37,1,0,0,0,6,57,1,0,0,0,
  	8,61,1,0,0,0,10,65,1,0,0,0,12,80,1,0,0,0,14,96,1,0,0,0,16,189,1,0,0,0,
  	18,19,3,2,1,0,19,20,5,21,0,0,20,21,3,8,4,0,21,1,1,0,0,0,22,24,5,18,0,
  	0,23,25,5,20,0,0,24,23,1,0,0,0,24,25,1,0,0,0,25,26,1,0,0,0,26,27,3,12,
  	6,0,27,28,5,21,0,0,28,30,1,0,0,0,29,22,1,0,0,0,30,31,1,0,0,0,31,29,1,
  	0,0,0,31,32,1,0,0,0,32,3,1,0,0,0,33,35,5,18,0,0,34,36,5,20,0,0,35,34,
  	1,0,0,0,35,36,1,0,0,0,36,38,1,0,0,0,37,33,1,0,0,0,38,39,1,0,0,0,39,37,
  	1,0,0,0,39,40,1,0,0,0,40,5,1,0,0,0,41,42,5,18,0,0,42,53,5,21,0,0,43,45,
  	3,12,6,0,44,46,5,20,0,0,45,44,1,0,0,0,45,46,1,0,0,0,46,48,1,0,0,0,47,
  	43,1,0,0,0,48,49,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,51,1,0,0,0,51,
  	52,7,0,0,0,52,54,1,0,0,0,53,47,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,
  	56,1,0,0,0,56,58,1,0,0,0,57,41,1,0,0,0,58,59,1,0,0,0,59,57,1,0,0,0,59,
  	60,1,0,0,0,60,7,1,0,0,0,61,62,3,4,2,0,62,63,5,21,0,0,63,64,3,6,3,0,64,
  	9,1,0,0,0,65,66,3,12,6,0,66,67,5,0,0,1,67,11,1,0,0,0,68,69,6,6,-1,0,69,
  	70,5,1,0,0,70,71,3,12,6,0,71,72,5,2,0,0,72,81,1,0,0,0,73,74,7,1,0,0,74,
  	81,3,12,6,9,75,81,3,16,8,0,76,81,3,14,7,0,77,81,5,18,0,0,78,81,5,22,0,
  	0,79,81,5,23,0,0,80,68,1,0,0,0,80,73,1,0,0,0,80,75,1,0,0,0,80,76,1,0,
  	0,0,80,77,1,0,0,0,80,78,1,0,0,0,80,79,1,0,0,0,81,93,1,0,0,0,82,83,10,
  	8,0,0,83,84,7,2,0,0,84,92,3,12,6,9,85,86,10,7,0,0,86,87,7,1,0,0,87,92,
  	3,12,6,8,88,89,10,6,0,0,89,90,5,16,0,0,90,92,3,12,6,7,91,82,1,0,0,0,91,
  	85,1,0,0,0,91,88,1,0,0,0,92,95,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,
  	13,1,0,0,0,95,93,1,0,0,0,96,97,5,3,0,0,97,102,7,3,0,0,98,99,5,4,0,0,99,
  	103,5,18,0,0,100,103,5,22,0,0,101,103,5,23,0,0,102,98,1,0,0,0,102,100,
  	1,0,0,0,102,101,1,0,0,0,103,104,1,0,0,0,104,102,1,0,0,0,104,105,1,0,0,
  	0,105,106,1,0,0,0,106,107,5,5,0,0,107,15,1,0,0,0,108,109,5,1,0,0,109,
  	110,3,16,8,0,110,111,5,2,0,0,111,190,1,0,0,0,112,113,5,7,0,0,113,115,
  	5,1,0,0,114,116,5,20,0,0,115,114,1,0,0,0,115,116,1,0,0,0,116,117,1,0,
  	0,0,117,119,3,12,6,0,118,120,5,20,0,0,119,118,1,0,0,0,119,120,1,0,0,0,
  	120,121,1,0,0,0,121,122,5,2,0,0,122,190,1,0,0,0,123,124,5,8,0,0,124,126,
  	5,1,0,0,125,127,5,20,0,0,126,125,1,0,0,0,126,127,1,0,0,0,127,128,1,0,
  	0,0,128,130,3,12,6,0,129,131,5,20,0,0,130,129,1,0,0,0,130,131,1,0,0,0,
  	131,132,1,0,0,0,132,133,5,2,0,0,133,190,1,0,0,0,134,135,5,9,0,0,135,137,
  	5,1,0,0,136,138,5,20,0,0,137,136,1,0,0,0,137,138,1,0,0,0,138,139,1,0,
  	0,0,139,141,3,12,6,0,140,142,5,20,0,0,141,140,1,0,0,0,141,142,1,0,0,0,
  	142,143,1,0,0,0,143,145,5,4,0,0,144,146,5,20,0,0,145,144,1,0,0,0,145,
  	146,1,0,0,0,146,147,1,0,0,0,147,149,3,12,6,0,148,150,5,20,0,0,149,148,
  	1,0,0,0,149,150,1,0,0,0,150,151,1,0,0,0,151,152,5,2,0,0,152,190,1,0,0,
  	0,153,154,5,10,0,0,154,156,5,1,0,0,155,157,5,20,0,0,156,155,1,0,0,0,156,
  	157,1,0,0,0,157,158,1,0,0,0,158,160,3,12,6,0,159,161,5,20,0,0,160,159,
  	1,0,0,0,160,161,1,0,0,0,161,162,1,0,0,0,162,163,5,2,0,0,163,190,1,0,0,
  	0,164,165,5,11,0,0,165,167,5,1,0,0,166,168,5,20,0,0,167,166,1,0,0,0,167,
  	168,1,0,0,0,168,169,1,0,0,0,169,171,3,12,6,0,170,172,5,20,0,0,171,170,
  	1,0,0,0,171,172,1,0,0,0,172,173,1,0,0,0,173,174,5,2,0,0,174,190,1,0,0,
  	0,175,176,5,6,0,0,176,177,5,1,0,0,177,178,3,12,6,0,178,179,5,4,0,0,179,
  	184,3,12,6,0,180,181,5,4,0,0,181,183,3,12,6,0,182,180,1,0,0,0,183,186,
  	1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,187,1,0,0,0,186,184,1,0,0,
  	0,187,188,5,2,0,0,188,190,1,0,0,0,189,108,1,0,0,0,189,112,1,0,0,0,189,
  	123,1,0,0,0,189,134,1,0,0,0,189,153,1,0,0,0,189,164,1,0,0,0,189,175,1,
  	0,0,0,190,17,1,0,0,0,27,24,31,35,39,45,49,55,59,80,91,93,102,104,115,
  	119,126,130,137,141,145,149,156,160,167,171,184,189
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  bound_coefsParserStaticData = staticData.release();
}

}

bound_coefsParser::bound_coefsParser(TokenStream *input) : bound_coefsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

bound_coefsParser::bound_coefsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  bound_coefsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *bound_coefsParserStaticData->atn, bound_coefsParserStaticData->decisionToDFA, bound_coefsParserStaticData->sharedContextCache, options);
}

bound_coefsParser::~bound_coefsParser() {
  delete _interpreter;
}

const atn::ATN& bound_coefsParser::getATN() const {
  return *bound_coefsParserStaticData->atn;
}

std::string bound_coefsParser::getGrammarFileName() const {
  return "bound_coefs.g4";
}

const std::vector<std::string>& bound_coefsParser::getRuleNames() const {
  return bound_coefsParserStaticData->ruleNames;
}

const dfa::Vocabulary& bound_coefsParser::getVocabulary() const {
  return bound_coefsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView bound_coefsParser::getSerializedATN() const {
  return bound_coefsParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

bound_coefsParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bound_coefsParser::EqContext* bound_coefsParser::FileContext::eq() {
  return getRuleContext<bound_coefsParser::EqContext>(0);
}

tree::TerminalNode* bound_coefsParser::FileContext::EOL() {
  return getToken(bound_coefsParser::EOL, 0);
}

bound_coefsParser::Bound_coefsContext* bound_coefsParser::FileContext::bound_coefs() {
  return getRuleContext<bound_coefsParser::Bound_coefsContext>(0);
}


size_t bound_coefsParser::FileContext::getRuleIndex() const {
  return bound_coefsParser::RuleFile;
}

void bound_coefsParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void bound_coefsParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

bound_coefsParser::FileContext* bound_coefsParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, bound_coefsParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    eq();
    setState(19);
    match(bound_coefsParser::EOL);
    setState(20);
    bound_coefs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqContext ------------------------------------------------------------------

bound_coefsParser::EqContext::EqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bound_coefsParser::EqContext::VARIABLE() {
  return getTokens(bound_coefsParser::VARIABLE);
}

tree::TerminalNode* bound_coefsParser::EqContext::VARIABLE(size_t i) {
  return getToken(bound_coefsParser::VARIABLE, i);
}

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::EqContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::EqContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::EqContext::EOL() {
  return getTokens(bound_coefsParser::EOL);
}

tree::TerminalNode* bound_coefsParser::EqContext::EOL(size_t i) {
  return getToken(bound_coefsParser::EOL, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::EqContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::EqContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}


size_t bound_coefsParser::EqContext::getRuleIndex() const {
  return bound_coefsParser::RuleEq;
}

void bound_coefsParser::EqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq(this);
}

void bound_coefsParser::EqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq(this);
}

bound_coefsParser::EqContext* bound_coefsParser::eq() {
  EqContext *_localctx = _tracker.createInstance<EqContext>(_ctx, getState());
  enterRule(_localctx, 2, bound_coefsParser::RuleEq);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      match(bound_coefsParser::VARIABLE);
      setState(24);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bound_coefsParser::WS) {
        setState(23);
        match(bound_coefsParser::WS);
      }
      setState(26);
      expr(0);
      setState(27);
      match(bound_coefsParser::EOL);
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == bound_coefsParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HdrContext ------------------------------------------------------------------

bound_coefsParser::HdrContext::HdrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bound_coefsParser::HdrContext::VARIABLE() {
  return getTokens(bound_coefsParser::VARIABLE);
}

tree::TerminalNode* bound_coefsParser::HdrContext::VARIABLE(size_t i) {
  return getToken(bound_coefsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::HdrContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::HdrContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}


size_t bound_coefsParser::HdrContext::getRuleIndex() const {
  return bound_coefsParser::RuleHdr;
}

void bound_coefsParser::HdrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHdr(this);
}

void bound_coefsParser::HdrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHdr(this);
}

bound_coefsParser::HdrContext* bound_coefsParser::hdr() {
  HdrContext *_localctx = _tracker.createInstance<HdrContext>(_ctx, getState());
  enterRule(_localctx, 4, bound_coefsParser::RuleHdr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(33);
      match(bound_coefsParser::VARIABLE);
      setState(35);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bound_coefsParser::WS) {
        setState(34);
        match(bound_coefsParser::WS);
      }
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == bound_coefsParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuesContext ------------------------------------------------------------------

bound_coefsParser::ValuesContext::ValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bound_coefsParser::ValuesContext::VARIABLE() {
  return getTokens(bound_coefsParser::VARIABLE);
}

tree::TerminalNode* bound_coefsParser::ValuesContext::VARIABLE(size_t i) {
  return getToken(bound_coefsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ValuesContext::EOL() {
  return getTokens(bound_coefsParser::EOL);
}

tree::TerminalNode* bound_coefsParser::ValuesContext::EOL(size_t i) {
  return getToken(bound_coefsParser::EOL, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ValuesContext::EOF() {
  return getTokens(bound_coefsParser::EOF);
}

tree::TerminalNode* bound_coefsParser::ValuesContext::EOF(size_t i) {
  return getToken(bound_coefsParser::EOF, i);
}

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::ValuesContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::ValuesContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ValuesContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::ValuesContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}


size_t bound_coefsParser::ValuesContext::getRuleIndex() const {
  return bound_coefsParser::RuleValues;
}

void bound_coefsParser::ValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValues(this);
}

void bound_coefsParser::ValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValues(this);
}

bound_coefsParser::ValuesContext* bound_coefsParser::values() {
  ValuesContext *_localctx = _tracker.createInstance<ValuesContext>(_ctx, getState());
  enterRule(_localctx, 6, bound_coefsParser::RuleValues);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(57); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(41);
      match(bound_coefsParser::VARIABLE);
      setState(42);
      match(bound_coefsParser::EOL);
      setState(53); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(47); 
                _errHandler->sync(this);
                _la = _input->LA(1);
                do {
                  setState(43);
                  expr(0);
                  setState(45);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (_la == bound_coefsParser::WS) {
                    setState(44);
                    match(bound_coefsParser::WS);
                  }
                  setState(49); 
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                } while ((((_la & ~ 0x3fULL) == 0) &&
                  ((1ULL << _la) & 12861386) != 0));
                setState(51);
                _la = _input->LA(1);
                if (!(_la == bound_coefsParser::EOF

                || _la == bound_coefsParser::EOL)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(55); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(59); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == bound_coefsParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bound_coefsContext ------------------------------------------------------------------

bound_coefsParser::Bound_coefsContext::Bound_coefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bound_coefsParser::HdrContext* bound_coefsParser::Bound_coefsContext::hdr() {
  return getRuleContext<bound_coefsParser::HdrContext>(0);
}

tree::TerminalNode* bound_coefsParser::Bound_coefsContext::EOL() {
  return getToken(bound_coefsParser::EOL, 0);
}

bound_coefsParser::ValuesContext* bound_coefsParser::Bound_coefsContext::values() {
  return getRuleContext<bound_coefsParser::ValuesContext>(0);
}


size_t bound_coefsParser::Bound_coefsContext::getRuleIndex() const {
  return bound_coefsParser::RuleBound_coefs;
}

void bound_coefsParser::Bound_coefsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBound_coefs(this);
}

void bound_coefsParser::Bound_coefsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBound_coefs(this);
}

bound_coefsParser::Bound_coefsContext* bound_coefsParser::bound_coefs() {
  Bound_coefsContext *_localctx = _tracker.createInstance<Bound_coefsContext>(_ctx, getState());
  enterRule(_localctx, 8, bound_coefsParser::RuleBound_coefs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    hdr();
    setState(62);
    match(bound_coefsParser::EOL);
    setState(63);
    values();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

bound_coefsParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bound_coefsParser::ExprContext* bound_coefsParser::MainContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

tree::TerminalNode* bound_coefsParser::MainContext::EOF() {
  return getToken(bound_coefsParser::EOF, 0);
}


size_t bound_coefsParser::MainContext::getRuleIndex() const {
  return bound_coefsParser::RuleMain;
}

void bound_coefsParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void bound_coefsParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}

bound_coefsParser::MainContext* bound_coefsParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 10, bound_coefsParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    expr(0);
    setState(66);
    match(bound_coefsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

bound_coefsParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bound_coefsParser::ExprContext::getRuleIndex() const {
  return bound_coefsParser::RuleExpr;
}

void bound_coefsParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

bound_coefsParser::ExprContext* bound_coefsParser::UnaryOpContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

tree::TerminalNode* bound_coefsParser::UnaryOpContext::ADD() {
  return getToken(bound_coefsParser::ADD, 0);
}

tree::TerminalNode* bound_coefsParser::UnaryOpContext::SUB() {
  return getToken(bound_coefsParser::SUB, 0);
}

bound_coefsParser::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void bound_coefsParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::VariableContext::VARIABLE() {
  return getToken(bound_coefsParser::VARIABLE, 0);
}

bound_coefsParser::VariableContext::VariableContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void bound_coefsParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}
//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::NumberContext::NUMBER() {
  return getToken(bound_coefsParser::NUMBER, 0);
}

bound_coefsParser::NumberContext::NumberContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}
void bound_coefsParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}
//----------------- ParensContext ------------------------------------------------------------------

bound_coefsParser::ExprContext* bound_coefsParser::ParensContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

bound_coefsParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void bound_coefsParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- ArrayDefContext ------------------------------------------------------------------

bound_coefsParser::ArrayContext* bound_coefsParser::ArrayDefContext::array() {
  return getRuleContext<bound_coefsParser::ArrayContext>(0);
}

bound_coefsParser::ArrayDefContext::ArrayDefContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::ArrayDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDef(this);
}
void bound_coefsParser::ArrayDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDef(this);
}
//----------------- ConstantContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::ConstantContext::CONSTANTS() {
  return getToken(bound_coefsParser::CONSTANTS, 0);
}

bound_coefsParser::ConstantContext::ConstantContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}
void bound_coefsParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

bound_coefsParser::FunctionsContext* bound_coefsParser::FunctionCallContext::functions() {
  return getRuleContext<bound_coefsParser::FunctionsContext>(0);
}

bound_coefsParser::FunctionCallContext::FunctionCallContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void bound_coefsParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}
//----------------- PowerOpContext ------------------------------------------------------------------

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::PowerOpContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::PowerOpContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

tree::TerminalNode* bound_coefsParser::PowerOpContext::POW() {
  return getToken(bound_coefsParser::POW, 0);
}

bound_coefsParser::PowerOpContext::PowerOpContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::PowerOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerOp(this);
}
void bound_coefsParser::PowerOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerOp(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::BinaryOpContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::BinaryOpContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

tree::TerminalNode* bound_coefsParser::BinaryOpContext::MUL() {
  return getToken(bound_coefsParser::MUL, 0);
}

tree::TerminalNode* bound_coefsParser::BinaryOpContext::DIV() {
  return getToken(bound_coefsParser::DIV, 0);
}

tree::TerminalNode* bound_coefsParser::BinaryOpContext::ADD() {
  return getToken(bound_coefsParser::ADD, 0);
}

tree::TerminalNode* bound_coefsParser::BinaryOpContext::SUB() {
  return getToken(bound_coefsParser::SUB, 0);
}

bound_coefsParser::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void bound_coefsParser::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

bound_coefsParser::ExprContext* bound_coefsParser::expr() {
   return expr(0);
}

bound_coefsParser::ExprContext* bound_coefsParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  bound_coefsParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  bound_coefsParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, bound_coefsParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(69);
      match(bound_coefsParser::T__0);
      setState(70);
      expr(0);
      setState(71);
      match(bound_coefsParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(73);
      _la = _input->LA(1);
      if (!(_la == bound_coefsParser::ADD

      || _la == bound_coefsParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(74);
      expr(9);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(75);
      functions();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ArrayDefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      array();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(77);
      match(bound_coefsParser::VARIABLE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(78);
      match(bound_coefsParser::NUMBER);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(79);
      match(bound_coefsParser::CONSTANTS);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(93);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(91);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(82);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(83);
          _la = _input->LA(1);
          if (!(_la == bound_coefsParser::MUL

          || _la == bound_coefsParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(84);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(85);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(86);
          _la = _input->LA(1);
          if (!(_la == bound_coefsParser::ADD

          || _la == bound_coefsParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(87);
          expr(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PowerOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(88);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(89);
          match(bound_coefsParser::POW);
          setState(90);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(95);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

bound_coefsParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bound_coefsParser::ArrayContext::VARIABLE() {
  return getTokens(bound_coefsParser::VARIABLE);
}

tree::TerminalNode* bound_coefsParser::ArrayContext::VARIABLE(size_t i) {
  return getToken(bound_coefsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ArrayContext::NUMBER() {
  return getTokens(bound_coefsParser::NUMBER);
}

tree::TerminalNode* bound_coefsParser::ArrayContext::NUMBER(size_t i) {
  return getToken(bound_coefsParser::NUMBER, i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ArrayContext::CONSTANTS() {
  return getTokens(bound_coefsParser::CONSTANTS);
}

tree::TerminalNode* bound_coefsParser::ArrayContext::CONSTANTS(size_t i) {
  return getToken(bound_coefsParser::CONSTANTS, i);
}


size_t bound_coefsParser::ArrayContext::getRuleIndex() const {
  return bound_coefsParser::RuleArray;
}

void bound_coefsParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void bound_coefsParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

bound_coefsParser::ArrayContext* bound_coefsParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 14, bound_coefsParser::RuleArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(bound_coefsParser::T__2);
    setState(97);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12845056) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(102); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bound_coefsParser::T__3: {
          setState(98);
          match(bound_coefsParser::T__3);
          setState(99);
          match(bound_coefsParser::VARIABLE);
          break;
        }

        case bound_coefsParser::NUMBER: {
          setState(100);
          match(bound_coefsParser::NUMBER);
          break;
        }

        case bound_coefsParser::CONSTANTS: {
          setState(101);
          match(bound_coefsParser::CONSTANTS);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(104); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12582928) != 0));
    setState(106);
    match(bound_coefsParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionsContext ------------------------------------------------------------------

bound_coefsParser::FunctionsContext::FunctionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bound_coefsParser::FunctionsContext::getRuleIndex() const {
  return bound_coefsParser::RuleFunctions;
}

void bound_coefsParser::FunctionsContext::copyFrom(FunctionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SumproductContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::SumproductContext::SUMPRODUCT() {
  return getToken(bound_coefsParser::SUMPRODUCT, 0);
}

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::SumproductContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::SumproductContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

bound_coefsParser::SumproductContext::SumproductContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::SumproductContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSumproduct(this);
}
void bound_coefsParser::SumproductContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSumproduct(this);
}
//----------------- NatlogContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::NatlogContext::LN() {
  return getToken(bound_coefsParser::LN, 0);
}

bound_coefsParser::ExprContext* bound_coefsParser::NatlogContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> bound_coefsParser::NatlogContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::NatlogContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}

bound_coefsParser::NatlogContext::NatlogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::NatlogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNatlog(this);
}
void bound_coefsParser::NatlogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNatlog(this);
}
//----------------- ExponentContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::ExponentContext::EXP() {
  return getToken(bound_coefsParser::EXP, 0);
}

bound_coefsParser::ExprContext* bound_coefsParser::ExponentContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> bound_coefsParser::ExponentContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::ExponentContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}

bound_coefsParser::ExponentContext::ExponentContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::ExponentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExponent(this);
}
void bound_coefsParser::ExponentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExponent(this);
}
//----------------- DeclogContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::DeclogContext::LG() {
  return getToken(bound_coefsParser::LG, 0);
}

bound_coefsParser::ExprContext* bound_coefsParser::DeclogContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> bound_coefsParser::DeclogContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::DeclogContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}

bound_coefsParser::DeclogContext::DeclogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::DeclogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclog(this);
}
void bound_coefsParser::DeclogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclog(this);
}
//----------------- BaselogContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::BaselogContext::LOG_X() {
  return getToken(bound_coefsParser::LOG_X, 0);
}

std::vector<bound_coefsParser::ExprContext *> bound_coefsParser::BaselogContext::expr() {
  return getRuleContexts<bound_coefsParser::ExprContext>();
}

bound_coefsParser::ExprContext* bound_coefsParser::BaselogContext::expr(size_t i) {
  return getRuleContext<bound_coefsParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> bound_coefsParser::BaselogContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::BaselogContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}

bound_coefsParser::BaselogContext::BaselogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::BaselogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaselog(this);
}
void bound_coefsParser::BaselogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaselog(this);
}
//----------------- ParesContext ------------------------------------------------------------------

bound_coefsParser::FunctionsContext* bound_coefsParser::ParesContext::functions() {
  return getRuleContext<bound_coefsParser::FunctionsContext>(0);
}

bound_coefsParser::ParesContext::ParesContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::ParesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPares(this);
}
void bound_coefsParser::ParesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPares(this);
}
//----------------- SquarerootContext ------------------------------------------------------------------

tree::TerminalNode* bound_coefsParser::SquarerootContext::SQRT() {
  return getToken(bound_coefsParser::SQRT, 0);
}

bound_coefsParser::ExprContext* bound_coefsParser::SquarerootContext::expr() {
  return getRuleContext<bound_coefsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> bound_coefsParser::SquarerootContext::WS() {
  return getTokens(bound_coefsParser::WS);
}

tree::TerminalNode* bound_coefsParser::SquarerootContext::WS(size_t i) {
  return getToken(bound_coefsParser::WS, i);
}

bound_coefsParser::SquarerootContext::SquarerootContext(FunctionsContext *ctx) { copyFrom(ctx); }

void bound_coefsParser::SquarerootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSquareroot(this);
}
void bound_coefsParser::SquarerootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bound_coefsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSquareroot(this);
}
bound_coefsParser::FunctionsContext* bound_coefsParser::functions() {
  FunctionsContext *_localctx = _tracker.createInstance<FunctionsContext>(_ctx, getState());
  enterRule(_localctx, 16, bound_coefsParser::RuleFunctions);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bound_coefsParser::T__0: {
        _localctx = _tracker.createInstance<bound_coefsParser::ParesContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(108);
        match(bound_coefsParser::T__0);
        setState(109);
        functions();
        setState(110);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::LN: {
        _localctx = _tracker.createInstance<bound_coefsParser::NatlogContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(112);
        match(bound_coefsParser::LN);
        setState(113);
        match(bound_coefsParser::T__0);
        setState(115);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(114);
          match(bound_coefsParser::WS);
        }
        setState(117);
        expr(0);
        setState(119);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(118);
          match(bound_coefsParser::WS);
        }
        setState(121);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::LG: {
        _localctx = _tracker.createInstance<bound_coefsParser::DeclogContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(123);
        match(bound_coefsParser::LG);
        setState(124);
        match(bound_coefsParser::T__0);
        setState(126);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(125);
          match(bound_coefsParser::WS);
        }
        setState(128);
        expr(0);
        setState(130);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(129);
          match(bound_coefsParser::WS);
        }
        setState(132);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::LOG_X: {
        _localctx = _tracker.createInstance<bound_coefsParser::BaselogContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(134);
        match(bound_coefsParser::LOG_X);
        setState(135);
        match(bound_coefsParser::T__0);
        setState(137);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(136);
          match(bound_coefsParser::WS);
        }
        setState(139);
        expr(0);
        setState(141);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(140);
          match(bound_coefsParser::WS);
        }
        setState(143);
        match(bound_coefsParser::T__3);
        setState(145);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(144);
          match(bound_coefsParser::WS);
        }
        setState(147);
        expr(0);
        setState(149);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(148);
          match(bound_coefsParser::WS);
        }
        setState(151);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::EXP: {
        _localctx = _tracker.createInstance<bound_coefsParser::ExponentContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(153);
        match(bound_coefsParser::EXP);
        setState(154);
        match(bound_coefsParser::T__0);
        setState(156);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(155);
          match(bound_coefsParser::WS);
        }
        setState(158);
        expr(0);
        setState(160);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(159);
          match(bound_coefsParser::WS);
        }
        setState(162);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::SQRT: {
        _localctx = _tracker.createInstance<bound_coefsParser::SquarerootContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(164);
        match(bound_coefsParser::SQRT);
        setState(165);
        match(bound_coefsParser::T__0);
        setState(167);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(166);
          match(bound_coefsParser::WS);
        }
        setState(169);
        expr(0);
        setState(171);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bound_coefsParser::WS) {
          setState(170);
          match(bound_coefsParser::WS);
        }
        setState(173);
        match(bound_coefsParser::T__1);
        break;
      }

      case bound_coefsParser::SUMPRODUCT: {
        _localctx = _tracker.createInstance<bound_coefsParser::SumproductContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(175);
        match(bound_coefsParser::SUMPRODUCT);
        setState(176);
        match(bound_coefsParser::T__0);
        setState(177);
        expr(0);
        setState(178);
        match(bound_coefsParser::T__3);
        setState(179);
        expr(0);
        setState(184);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bound_coefsParser::T__3) {
          setState(180);
          match(bound_coefsParser::T__3);
          setState(181);
          expr(0);
          setState(186);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(187);
        match(bound_coefsParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool bound_coefsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool bound_coefsParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void bound_coefsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  bound_coefsParserInitialize();
#else
  ::antlr4::internal::call_once(bound_coefsParserOnceFlag, bound_coefsParserInitialize);
#endif
}
