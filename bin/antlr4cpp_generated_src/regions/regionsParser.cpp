
// Generated from /home/oster/Electrolisys/grammar/regions.g4 by ANTLR 4.13.1


#include "regionsListener.h"

#include "regionsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct RegionsParserStaticData final {
  RegionsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RegionsParserStaticData(const RegionsParserStaticData&) = delete;
  RegionsParserStaticData(RegionsParserStaticData&&) = delete;
  RegionsParserStaticData& operator=(const RegionsParserStaticData&) = delete;
  RegionsParserStaticData& operator=(RegionsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag regionsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
RegionsParserStaticData *regionsParserStaticData = nullptr;

void regionsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (regionsParserStaticData != nullptr) {
    return;
  }
#else
  assert(regionsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RegionsParserStaticData>(
    std::vector<std::string>{
      "file", "hdr", "data_bound", "const_zone", "virial_coefs", "values", 
      "bound_equation", "tempbound", "main", "expr", "array", "functions"
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
  	4,1,24,206,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,5,1,33,8,1,10,1,12,1,36,9,1,4,1,38,8,1,11,1,12,1,39,1,2,1,2,5,2,44,
  	8,2,10,2,12,2,47,9,2,1,2,1,2,4,2,51,8,2,11,2,12,2,52,1,3,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,5,1,5,5,5,65,8,5,10,5,12,5,68,9,5,4,5,70,8,5,11,5,12,
  	5,71,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,3,9,95,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,
  	9,106,8,9,10,9,12,9,109,9,9,1,10,1,10,1,10,1,10,1,10,1,10,4,10,117,8,
  	10,11,10,12,10,118,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	130,8,11,1,11,1,11,3,11,134,8,11,1,11,1,11,1,11,1,11,1,11,3,11,141,8,
  	11,1,11,1,11,3,11,145,8,11,1,11,1,11,1,11,1,11,1,11,3,11,152,8,11,1,11,
  	1,11,3,11,156,8,11,1,11,1,11,3,11,160,8,11,1,11,1,11,3,11,164,8,11,1,
  	11,1,11,1,11,1,11,1,11,3,11,171,8,11,1,11,1,11,3,11,175,8,11,1,11,1,11,
  	1,11,1,11,1,11,3,11,182,8,11,1,11,1,11,3,11,186,8,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,5,11,197,8,11,10,11,12,11,200,9,11,1,11,1,
  	11,3,11,204,8,11,1,11,0,1,18,12,0,2,4,6,8,10,12,14,16,18,20,22,0,4,2,
  	0,17,17,22,22,1,0,12,13,1,0,14,15,2,0,18,18,22,23,230,0,24,1,0,0,0,2,
  	37,1,0,0,0,4,50,1,0,0,0,6,54,1,0,0,0,8,58,1,0,0,0,10,69,1,0,0,0,12,75,
  	1,0,0,0,14,77,1,0,0,0,16,79,1,0,0,0,18,94,1,0,0,0,20,110,1,0,0,0,22,203,
  	1,0,0,0,24,25,3,4,2,0,25,26,5,21,0,0,26,27,3,6,3,0,27,28,5,21,0,0,28,
  	29,3,8,4,0,29,1,1,0,0,0,30,34,5,18,0,0,31,33,5,20,0,0,32,31,1,0,0,0,33,
  	36,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,0,35,38,1,0,0,0,36,34,1,0,0,0,37,
  	30,1,0,0,0,38,39,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,3,1,0,0,0,41,
  	45,5,18,0,0,42,44,5,20,0,0,43,42,1,0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,
  	45,46,1,0,0,0,46,48,1,0,0,0,47,45,1,0,0,0,48,49,7,0,0,0,49,51,5,21,0,
  	0,50,41,1,0,0,0,51,52,1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,53,5,1,0,0,
  	0,54,55,3,2,1,0,55,56,5,21,0,0,56,57,3,10,5,0,57,7,1,0,0,0,58,59,3,2,
  	1,0,59,60,5,21,0,0,60,61,3,10,5,0,61,9,1,0,0,0,62,66,5,22,0,0,63,65,5,
  	20,0,0,64,63,1,0,0,0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,70,
  	1,0,0,0,68,66,1,0,0,0,69,62,1,0,0,0,70,71,1,0,0,0,71,69,1,0,0,0,71,72,
  	1,0,0,0,72,73,1,0,0,0,73,74,5,21,0,0,74,11,1,0,0,0,75,76,3,22,11,0,76,
  	13,1,0,0,0,77,78,1,0,0,0,78,15,1,0,0,0,79,80,3,18,9,0,80,81,5,0,0,1,81,
  	17,1,0,0,0,82,83,6,9,-1,0,83,84,5,1,0,0,84,85,3,18,9,0,85,86,5,2,0,0,
  	86,95,1,0,0,0,87,88,7,1,0,0,88,95,3,18,9,9,89,95,3,22,11,0,90,95,3,20,
  	10,0,91,95,5,18,0,0,92,95,5,22,0,0,93,95,5,23,0,0,94,82,1,0,0,0,94,87,
  	1,0,0,0,94,89,1,0,0,0,94,90,1,0,0,0,94,91,1,0,0,0,94,92,1,0,0,0,94,93,
  	1,0,0,0,95,107,1,0,0,0,96,97,10,8,0,0,97,98,7,2,0,0,98,106,3,18,9,9,99,
  	100,10,7,0,0,100,101,7,1,0,0,101,106,3,18,9,8,102,103,10,6,0,0,103,104,
  	5,16,0,0,104,106,3,18,9,7,105,96,1,0,0,0,105,99,1,0,0,0,105,102,1,0,0,
  	0,106,109,1,0,0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,19,1,0,0,0,109,
  	107,1,0,0,0,110,111,5,3,0,0,111,116,7,3,0,0,112,113,5,4,0,0,113,117,5,
  	18,0,0,114,117,5,22,0,0,115,117,5,23,0,0,116,112,1,0,0,0,116,114,1,0,
  	0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,
  	120,1,0,0,0,120,121,5,5,0,0,121,21,1,0,0,0,122,123,5,1,0,0,123,124,3,
  	22,11,0,124,125,5,2,0,0,125,204,1,0,0,0,126,127,5,7,0,0,127,129,5,1,0,
  	0,128,130,5,20,0,0,129,128,1,0,0,0,129,130,1,0,0,0,130,131,1,0,0,0,131,
  	133,3,18,9,0,132,134,5,20,0,0,133,132,1,0,0,0,133,134,1,0,0,0,134,135,
  	1,0,0,0,135,136,5,2,0,0,136,204,1,0,0,0,137,138,5,8,0,0,138,140,5,1,0,
  	0,139,141,5,20,0,0,140,139,1,0,0,0,140,141,1,0,0,0,141,142,1,0,0,0,142,
  	144,3,18,9,0,143,145,5,20,0,0,144,143,1,0,0,0,144,145,1,0,0,0,145,146,
  	1,0,0,0,146,147,5,2,0,0,147,204,1,0,0,0,148,149,5,9,0,0,149,151,5,1,0,
  	0,150,152,5,20,0,0,151,150,1,0,0,0,151,152,1,0,0,0,152,153,1,0,0,0,153,
  	155,3,18,9,0,154,156,5,20,0,0,155,154,1,0,0,0,155,156,1,0,0,0,156,157,
  	1,0,0,0,157,159,5,4,0,0,158,160,5,20,0,0,159,158,1,0,0,0,159,160,1,0,
  	0,0,160,161,1,0,0,0,161,163,3,18,9,0,162,164,5,20,0,0,163,162,1,0,0,0,
  	163,164,1,0,0,0,164,165,1,0,0,0,165,166,5,2,0,0,166,204,1,0,0,0,167,168,
  	5,10,0,0,168,170,5,1,0,0,169,171,5,20,0,0,170,169,1,0,0,0,170,171,1,0,
  	0,0,171,172,1,0,0,0,172,174,3,18,9,0,173,175,5,20,0,0,174,173,1,0,0,0,
  	174,175,1,0,0,0,175,176,1,0,0,0,176,177,5,2,0,0,177,204,1,0,0,0,178,179,
  	5,11,0,0,179,181,5,1,0,0,180,182,5,20,0,0,181,180,1,0,0,0,181,182,1,0,
  	0,0,182,183,1,0,0,0,183,185,3,18,9,0,184,186,5,20,0,0,185,184,1,0,0,0,
  	185,186,1,0,0,0,186,187,1,0,0,0,187,188,5,2,0,0,188,204,1,0,0,0,189,190,
  	5,6,0,0,190,191,5,1,0,0,191,192,3,18,9,0,192,193,5,4,0,0,193,198,3,18,
  	9,0,194,195,5,4,0,0,195,197,3,18,9,0,196,194,1,0,0,0,197,200,1,0,0,0,
  	198,196,1,0,0,0,198,199,1,0,0,0,199,201,1,0,0,0,200,198,1,0,0,0,201,202,
  	5,2,0,0,202,204,1,0,0,0,203,122,1,0,0,0,203,126,1,0,0,0,203,137,1,0,0,
  	0,203,148,1,0,0,0,203,167,1,0,0,0,203,178,1,0,0,0,203,189,1,0,0,0,204,
  	23,1,0,0,0,25,34,39,45,52,66,71,94,105,107,116,118,129,133,140,144,151,
  	155,159,163,170,174,181,185,198,203
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  regionsParserStaticData = staticData.release();
}

}

regionsParser::regionsParser(TokenStream *input) : regionsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

regionsParser::regionsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  regionsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *regionsParserStaticData->atn, regionsParserStaticData->decisionToDFA, regionsParserStaticData->sharedContextCache, options);
}

regionsParser::~regionsParser() {
  delete _interpreter;
}

const atn::ATN& regionsParser::getATN() const {
  return *regionsParserStaticData->atn;
}

std::string regionsParser::getGrammarFileName() const {
  return "regions.g4";
}

const std::vector<std::string>& regionsParser::getRuleNames() const {
  return regionsParserStaticData->ruleNames;
}

const dfa::Vocabulary& regionsParser::getVocabulary() const {
  return regionsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView regionsParser::getSerializedATN() const {
  return regionsParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

regionsParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

regionsParser::Data_boundContext* regionsParser::FileContext::data_bound() {
  return getRuleContext<regionsParser::Data_boundContext>(0);
}

std::vector<tree::TerminalNode *> regionsParser::FileContext::EOL() {
  return getTokens(regionsParser::EOL);
}

tree::TerminalNode* regionsParser::FileContext::EOL(size_t i) {
  return getToken(regionsParser::EOL, i);
}

regionsParser::Const_zoneContext* regionsParser::FileContext::const_zone() {
  return getRuleContext<regionsParser::Const_zoneContext>(0);
}

regionsParser::Virial_coefsContext* regionsParser::FileContext::virial_coefs() {
  return getRuleContext<regionsParser::Virial_coefsContext>(0);
}


size_t regionsParser::FileContext::getRuleIndex() const {
  return regionsParser::RuleFile;
}

void regionsParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void regionsParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

regionsParser::FileContext* regionsParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, regionsParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    data_bound();
    setState(25);
    match(regionsParser::EOL);
    setState(26);
    const_zone();
    setState(27);
    match(regionsParser::EOL);
    setState(28);
    virial_coefs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HdrContext ------------------------------------------------------------------

regionsParser::HdrContext::HdrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> regionsParser::HdrContext::VARIABLE() {
  return getTokens(regionsParser::VARIABLE);
}

tree::TerminalNode* regionsParser::HdrContext::VARIABLE(size_t i) {
  return getToken(regionsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> regionsParser::HdrContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::HdrContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}


size_t regionsParser::HdrContext::getRuleIndex() const {
  return regionsParser::RuleHdr;
}

void regionsParser::HdrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHdr(this);
}

void regionsParser::HdrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHdr(this);
}

regionsParser::HdrContext* regionsParser::hdr() {
  HdrContext *_localctx = _tracker.createInstance<HdrContext>(_ctx, getState());
  enterRule(_localctx, 2, regionsParser::RuleHdr);
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
      setState(30);
      match(regionsParser::VARIABLE);
      setState(34);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == regionsParser::WS) {
        setState(31);
        match(regionsParser::WS);
        setState(36);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == regionsParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Data_boundContext ------------------------------------------------------------------

regionsParser::Data_boundContext::Data_boundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> regionsParser::Data_boundContext::VARIABLE() {
  return getTokens(regionsParser::VARIABLE);
}

tree::TerminalNode* regionsParser::Data_boundContext::VARIABLE(size_t i) {
  return getToken(regionsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> regionsParser::Data_boundContext::EOL() {
  return getTokens(regionsParser::EOL);
}

tree::TerminalNode* regionsParser::Data_boundContext::EOL(size_t i) {
  return getToken(regionsParser::EOL, i);
}

std::vector<tree::TerminalNode *> regionsParser::Data_boundContext::STRING() {
  return getTokens(regionsParser::STRING);
}

tree::TerminalNode* regionsParser::Data_boundContext::STRING(size_t i) {
  return getToken(regionsParser::STRING, i);
}

std::vector<tree::TerminalNode *> regionsParser::Data_boundContext::NUMBER() {
  return getTokens(regionsParser::NUMBER);
}

tree::TerminalNode* regionsParser::Data_boundContext::NUMBER(size_t i) {
  return getToken(regionsParser::NUMBER, i);
}

std::vector<tree::TerminalNode *> regionsParser::Data_boundContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::Data_boundContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}


size_t regionsParser::Data_boundContext::getRuleIndex() const {
  return regionsParser::RuleData_bound;
}

void regionsParser::Data_boundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterData_bound(this);
}

void regionsParser::Data_boundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitData_bound(this);
}

regionsParser::Data_boundContext* regionsParser::data_bound() {
  Data_boundContext *_localctx = _tracker.createInstance<Data_boundContext>(_ctx, getState());
  enterRule(_localctx, 4, regionsParser::RuleData_bound);
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
    setState(50); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(41);
      match(regionsParser::VARIABLE);
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == regionsParser::WS) {
        setState(42);
        match(regionsParser::WS);
        setState(47);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(48);
      _la = _input->LA(1);
      if (!(_la == regionsParser::STRING

      || _la == regionsParser::NUMBER)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(49);
      match(regionsParser::EOL);
      setState(52); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == regionsParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_zoneContext ------------------------------------------------------------------

regionsParser::Const_zoneContext::Const_zoneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

regionsParser::HdrContext* regionsParser::Const_zoneContext::hdr() {
  return getRuleContext<regionsParser::HdrContext>(0);
}

tree::TerminalNode* regionsParser::Const_zoneContext::EOL() {
  return getToken(regionsParser::EOL, 0);
}

regionsParser::ValuesContext* regionsParser::Const_zoneContext::values() {
  return getRuleContext<regionsParser::ValuesContext>(0);
}


size_t regionsParser::Const_zoneContext::getRuleIndex() const {
  return regionsParser::RuleConst_zone;
}

void regionsParser::Const_zoneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_zone(this);
}

void regionsParser::Const_zoneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_zone(this);
}

regionsParser::Const_zoneContext* regionsParser::const_zone() {
  Const_zoneContext *_localctx = _tracker.createInstance<Const_zoneContext>(_ctx, getState());
  enterRule(_localctx, 6, regionsParser::RuleConst_zone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    hdr();
    setState(55);
    match(regionsParser::EOL);
    setState(56);
    values();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Virial_coefsContext ------------------------------------------------------------------

regionsParser::Virial_coefsContext::Virial_coefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

regionsParser::HdrContext* regionsParser::Virial_coefsContext::hdr() {
  return getRuleContext<regionsParser::HdrContext>(0);
}

tree::TerminalNode* regionsParser::Virial_coefsContext::EOL() {
  return getToken(regionsParser::EOL, 0);
}

regionsParser::ValuesContext* regionsParser::Virial_coefsContext::values() {
  return getRuleContext<regionsParser::ValuesContext>(0);
}


size_t regionsParser::Virial_coefsContext::getRuleIndex() const {
  return regionsParser::RuleVirial_coefs;
}

void regionsParser::Virial_coefsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVirial_coefs(this);
}

void regionsParser::Virial_coefsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVirial_coefs(this);
}

regionsParser::Virial_coefsContext* regionsParser::virial_coefs() {
  Virial_coefsContext *_localctx = _tracker.createInstance<Virial_coefsContext>(_ctx, getState());
  enterRule(_localctx, 8, regionsParser::RuleVirial_coefs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    hdr();
    setState(59);
    match(regionsParser::EOL);
    setState(60);
    values();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuesContext ------------------------------------------------------------------

regionsParser::ValuesContext::ValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* regionsParser::ValuesContext::EOL() {
  return getToken(regionsParser::EOL, 0);
}

std::vector<tree::TerminalNode *> regionsParser::ValuesContext::NUMBER() {
  return getTokens(regionsParser::NUMBER);
}

tree::TerminalNode* regionsParser::ValuesContext::NUMBER(size_t i) {
  return getToken(regionsParser::NUMBER, i);
}

std::vector<tree::TerminalNode *> regionsParser::ValuesContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::ValuesContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}


size_t regionsParser::ValuesContext::getRuleIndex() const {
  return regionsParser::RuleValues;
}

void regionsParser::ValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValues(this);
}

void regionsParser::ValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValues(this);
}

regionsParser::ValuesContext* regionsParser::values() {
  ValuesContext *_localctx = _tracker.createInstance<ValuesContext>(_ctx, getState());
  enterRule(_localctx, 10, regionsParser::RuleValues);
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
    setState(69); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      match(regionsParser::NUMBER);
      setState(66);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == regionsParser::WS) {
        setState(63);
        match(regionsParser::WS);
        setState(68);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(71); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == regionsParser::NUMBER);
    setState(73);
    match(regionsParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bound_equationContext ------------------------------------------------------------------

regionsParser::Bound_equationContext::Bound_equationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

regionsParser::FunctionsContext* regionsParser::Bound_equationContext::functions() {
  return getRuleContext<regionsParser::FunctionsContext>(0);
}


size_t regionsParser::Bound_equationContext::getRuleIndex() const {
  return regionsParser::RuleBound_equation;
}

void regionsParser::Bound_equationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBound_equation(this);
}

void regionsParser::Bound_equationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBound_equation(this);
}

regionsParser::Bound_equationContext* regionsParser::bound_equation() {
  Bound_equationContext *_localctx = _tracker.createInstance<Bound_equationContext>(_ctx, getState());
  enterRule(_localctx, 12, regionsParser::RuleBound_equation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    functions();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempboundContext ------------------------------------------------------------------

regionsParser::TempboundContext::TempboundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t regionsParser::TempboundContext::getRuleIndex() const {
  return regionsParser::RuleTempbound;
}

void regionsParser::TempboundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTempbound(this);
}

void regionsParser::TempboundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTempbound(this);
}

regionsParser::TempboundContext* regionsParser::tempbound() {
  TempboundContext *_localctx = _tracker.createInstance<TempboundContext>(_ctx, getState());
  enterRule(_localctx, 14, regionsParser::RuleTempbound);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

regionsParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

regionsParser::ExprContext* regionsParser::MainContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

tree::TerminalNode* regionsParser::MainContext::EOF() {
  return getToken(regionsParser::EOF, 0);
}


size_t regionsParser::MainContext::getRuleIndex() const {
  return regionsParser::RuleMain;
}

void regionsParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void regionsParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}

regionsParser::MainContext* regionsParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 16, regionsParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    expr(0);
    setState(80);
    match(regionsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

regionsParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t regionsParser::ExprContext::getRuleIndex() const {
  return regionsParser::RuleExpr;
}

void regionsParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

regionsParser::ExprContext* regionsParser::UnaryOpContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

tree::TerminalNode* regionsParser::UnaryOpContext::ADD() {
  return getToken(regionsParser::ADD, 0);
}

tree::TerminalNode* regionsParser::UnaryOpContext::SUB() {
  return getToken(regionsParser::SUB, 0);
}

regionsParser::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void regionsParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::VariableContext::VARIABLE() {
  return getToken(regionsParser::VARIABLE, 0);
}

regionsParser::VariableContext::VariableContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void regionsParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}
//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::NumberContext::NUMBER() {
  return getToken(regionsParser::NUMBER, 0);
}

regionsParser::NumberContext::NumberContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}
void regionsParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}
//----------------- ParensContext ------------------------------------------------------------------

regionsParser::ExprContext* regionsParser::ParensContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

regionsParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void regionsParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- ArrayDefContext ------------------------------------------------------------------

regionsParser::ArrayContext* regionsParser::ArrayDefContext::array() {
  return getRuleContext<regionsParser::ArrayContext>(0);
}

regionsParser::ArrayDefContext::ArrayDefContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::ArrayDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDef(this);
}
void regionsParser::ArrayDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDef(this);
}
//----------------- ConstantContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::ConstantContext::CONSTANTS() {
  return getToken(regionsParser::CONSTANTS, 0);
}

regionsParser::ConstantContext::ConstantContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}
void regionsParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

regionsParser::FunctionsContext* regionsParser::FunctionCallContext::functions() {
  return getRuleContext<regionsParser::FunctionsContext>(0);
}

regionsParser::FunctionCallContext::FunctionCallContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void regionsParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}
//----------------- PowerOpContext ------------------------------------------------------------------

std::vector<regionsParser::ExprContext *> regionsParser::PowerOpContext::expr() {
  return getRuleContexts<regionsParser::ExprContext>();
}

regionsParser::ExprContext* regionsParser::PowerOpContext::expr(size_t i) {
  return getRuleContext<regionsParser::ExprContext>(i);
}

tree::TerminalNode* regionsParser::PowerOpContext::POW() {
  return getToken(regionsParser::POW, 0);
}

regionsParser::PowerOpContext::PowerOpContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::PowerOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerOp(this);
}
void regionsParser::PowerOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerOp(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<regionsParser::ExprContext *> regionsParser::BinaryOpContext::expr() {
  return getRuleContexts<regionsParser::ExprContext>();
}

regionsParser::ExprContext* regionsParser::BinaryOpContext::expr(size_t i) {
  return getRuleContext<regionsParser::ExprContext>(i);
}

tree::TerminalNode* regionsParser::BinaryOpContext::MUL() {
  return getToken(regionsParser::MUL, 0);
}

tree::TerminalNode* regionsParser::BinaryOpContext::DIV() {
  return getToken(regionsParser::DIV, 0);
}

tree::TerminalNode* regionsParser::BinaryOpContext::ADD() {
  return getToken(regionsParser::ADD, 0);
}

tree::TerminalNode* regionsParser::BinaryOpContext::SUB() {
  return getToken(regionsParser::SUB, 0);
}

regionsParser::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void regionsParser::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void regionsParser::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

regionsParser::ExprContext* regionsParser::expr() {
   return expr(0);
}

regionsParser::ExprContext* regionsParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  regionsParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  regionsParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, regionsParser::RuleExpr, precedence);

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
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(83);
      match(regionsParser::T__0);
      setState(84);
      expr(0);
      setState(85);
      match(regionsParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      _la = _input->LA(1);
      if (!(_la == regionsParser::ADD

      || _la == regionsParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(88);
      expr(9);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(89);
      functions();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ArrayDefContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(90);
      array();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(91);
      match(regionsParser::VARIABLE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(92);
      match(regionsParser::NUMBER);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(93);
      match(regionsParser::CONSTANTS);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(107);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(105);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(96);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(97);
          _la = _input->LA(1);
          if (!(_la == regionsParser::MUL

          || _la == regionsParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(98);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(99);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(100);
          _la = _input->LA(1);
          if (!(_la == regionsParser::ADD

          || _la == regionsParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(101);
          expr(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PowerOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(102);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(103);
          match(regionsParser::POW);
          setState(104);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(109);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

regionsParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> regionsParser::ArrayContext::VARIABLE() {
  return getTokens(regionsParser::VARIABLE);
}

tree::TerminalNode* regionsParser::ArrayContext::VARIABLE(size_t i) {
  return getToken(regionsParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> regionsParser::ArrayContext::NUMBER() {
  return getTokens(regionsParser::NUMBER);
}

tree::TerminalNode* regionsParser::ArrayContext::NUMBER(size_t i) {
  return getToken(regionsParser::NUMBER, i);
}

std::vector<tree::TerminalNode *> regionsParser::ArrayContext::CONSTANTS() {
  return getTokens(regionsParser::CONSTANTS);
}

tree::TerminalNode* regionsParser::ArrayContext::CONSTANTS(size_t i) {
  return getToken(regionsParser::CONSTANTS, i);
}


size_t regionsParser::ArrayContext::getRuleIndex() const {
  return regionsParser::RuleArray;
}

void regionsParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void regionsParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

regionsParser::ArrayContext* regionsParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 20, regionsParser::RuleArray);
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
    setState(110);
    match(regionsParser::T__2);
    setState(111);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12845056) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(116); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(116);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case regionsParser::T__3: {
          setState(112);
          match(regionsParser::T__3);
          setState(113);
          match(regionsParser::VARIABLE);
          break;
        }

        case regionsParser::NUMBER: {
          setState(114);
          match(regionsParser::NUMBER);
          break;
        }

        case regionsParser::CONSTANTS: {
          setState(115);
          match(regionsParser::CONSTANTS);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(118); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12582928) != 0));
    setState(120);
    match(regionsParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionsContext ------------------------------------------------------------------

regionsParser::FunctionsContext::FunctionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t regionsParser::FunctionsContext::getRuleIndex() const {
  return regionsParser::RuleFunctions;
}

void regionsParser::FunctionsContext::copyFrom(FunctionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SumproductContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::SumproductContext::SUMPRODUCT() {
  return getToken(regionsParser::SUMPRODUCT, 0);
}

std::vector<regionsParser::ExprContext *> regionsParser::SumproductContext::expr() {
  return getRuleContexts<regionsParser::ExprContext>();
}

regionsParser::ExprContext* regionsParser::SumproductContext::expr(size_t i) {
  return getRuleContext<regionsParser::ExprContext>(i);
}

regionsParser::SumproductContext::SumproductContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::SumproductContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSumproduct(this);
}
void regionsParser::SumproductContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSumproduct(this);
}
//----------------- NatlogContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::NatlogContext::LN() {
  return getToken(regionsParser::LN, 0);
}

regionsParser::ExprContext* regionsParser::NatlogContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> regionsParser::NatlogContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::NatlogContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}

regionsParser::NatlogContext::NatlogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::NatlogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNatlog(this);
}
void regionsParser::NatlogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNatlog(this);
}
//----------------- ExponentContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::ExponentContext::EXP() {
  return getToken(regionsParser::EXP, 0);
}

regionsParser::ExprContext* regionsParser::ExponentContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> regionsParser::ExponentContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::ExponentContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}

regionsParser::ExponentContext::ExponentContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::ExponentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExponent(this);
}
void regionsParser::ExponentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExponent(this);
}
//----------------- DeclogContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::DeclogContext::LG() {
  return getToken(regionsParser::LG, 0);
}

regionsParser::ExprContext* regionsParser::DeclogContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> regionsParser::DeclogContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::DeclogContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}

regionsParser::DeclogContext::DeclogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::DeclogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclog(this);
}
void regionsParser::DeclogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclog(this);
}
//----------------- BaselogContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::BaselogContext::LOG_X() {
  return getToken(regionsParser::LOG_X, 0);
}

std::vector<regionsParser::ExprContext *> regionsParser::BaselogContext::expr() {
  return getRuleContexts<regionsParser::ExprContext>();
}

regionsParser::ExprContext* regionsParser::BaselogContext::expr(size_t i) {
  return getRuleContext<regionsParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> regionsParser::BaselogContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::BaselogContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}

regionsParser::BaselogContext::BaselogContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::BaselogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaselog(this);
}
void regionsParser::BaselogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaselog(this);
}
//----------------- ParesContext ------------------------------------------------------------------

regionsParser::FunctionsContext* regionsParser::ParesContext::functions() {
  return getRuleContext<regionsParser::FunctionsContext>(0);
}

regionsParser::ParesContext::ParesContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::ParesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPares(this);
}
void regionsParser::ParesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPares(this);
}
//----------------- SquarerootContext ------------------------------------------------------------------

tree::TerminalNode* regionsParser::SquarerootContext::SQRT() {
  return getToken(regionsParser::SQRT, 0);
}

regionsParser::ExprContext* regionsParser::SquarerootContext::expr() {
  return getRuleContext<regionsParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> regionsParser::SquarerootContext::WS() {
  return getTokens(regionsParser::WS);
}

tree::TerminalNode* regionsParser::SquarerootContext::WS(size_t i) {
  return getToken(regionsParser::WS, i);
}

regionsParser::SquarerootContext::SquarerootContext(FunctionsContext *ctx) { copyFrom(ctx); }

void regionsParser::SquarerootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSquareroot(this);
}
void regionsParser::SquarerootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<regionsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSquareroot(this);
}
regionsParser::FunctionsContext* regionsParser::functions() {
  FunctionsContext *_localctx = _tracker.createInstance<FunctionsContext>(_ctx, getState());
  enterRule(_localctx, 22, regionsParser::RuleFunctions);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case regionsParser::T__0: {
        _localctx = _tracker.createInstance<regionsParser::ParesContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(122);
        match(regionsParser::T__0);
        setState(123);
        functions();
        setState(124);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::LN: {
        _localctx = _tracker.createInstance<regionsParser::NatlogContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(126);
        match(regionsParser::LN);
        setState(127);
        match(regionsParser::T__0);
        setState(129);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(128);
          match(regionsParser::WS);
        }
        setState(131);
        expr(0);
        setState(133);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(132);
          match(regionsParser::WS);
        }
        setState(135);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::LG: {
        _localctx = _tracker.createInstance<regionsParser::DeclogContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(137);
        match(regionsParser::LG);
        setState(138);
        match(regionsParser::T__0);
        setState(140);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(139);
          match(regionsParser::WS);
        }
        setState(142);
        expr(0);
        setState(144);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(143);
          match(regionsParser::WS);
        }
        setState(146);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::LOG_X: {
        _localctx = _tracker.createInstance<regionsParser::BaselogContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(148);
        match(regionsParser::LOG_X);
        setState(149);
        match(regionsParser::T__0);
        setState(151);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(150);
          match(regionsParser::WS);
        }
        setState(153);
        expr(0);
        setState(155);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(154);
          match(regionsParser::WS);
        }
        setState(157);
        match(regionsParser::T__3);
        setState(159);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(158);
          match(regionsParser::WS);
        }
        setState(161);
        expr(0);
        setState(163);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(162);
          match(regionsParser::WS);
        }
        setState(165);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::EXP: {
        _localctx = _tracker.createInstance<regionsParser::ExponentContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(167);
        match(regionsParser::EXP);
        setState(168);
        match(regionsParser::T__0);
        setState(170);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(169);
          match(regionsParser::WS);
        }
        setState(172);
        expr(0);
        setState(174);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(173);
          match(regionsParser::WS);
        }
        setState(176);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::SQRT: {
        _localctx = _tracker.createInstance<regionsParser::SquarerootContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(178);
        match(regionsParser::SQRT);
        setState(179);
        match(regionsParser::T__0);
        setState(181);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(180);
          match(regionsParser::WS);
        }
        setState(183);
        expr(0);
        setState(185);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == regionsParser::WS) {
          setState(184);
          match(regionsParser::WS);
        }
        setState(187);
        match(regionsParser::T__1);
        break;
      }

      case regionsParser::SUMPRODUCT: {
        _localctx = _tracker.createInstance<regionsParser::SumproductContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(189);
        match(regionsParser::SUMPRODUCT);
        setState(190);
        match(regionsParser::T__0);
        setState(191);
        expr(0);
        setState(192);
        match(regionsParser::T__3);
        setState(193);
        expr(0);
        setState(198);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == regionsParser::T__3) {
          setState(194);
          match(regionsParser::T__3);
          setState(195);
          expr(0);
          setState(200);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(201);
        match(regionsParser::T__1);
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

bool regionsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool regionsParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void regionsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  regionsParserInitialize();
#else
  ::antlr4::internal::call_once(regionsParserOnceFlag, regionsParserInitialize);
#endif
}
