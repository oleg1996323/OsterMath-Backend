
// Generated from /home/oster/Electrolisys/grammar/regions.g4 by ANTLR 4.13.1


#include "regionsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct RegionsLexerStaticData final {
  RegionsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RegionsLexerStaticData(const RegionsLexerStaticData&) = delete;
  RegionsLexerStaticData(RegionsLexerStaticData&&) = delete;
  RegionsLexerStaticData& operator=(const RegionsLexerStaticData&) = delete;
  RegionsLexerStaticData& operator=(RegionsLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag regionslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
RegionsLexerStaticData *regionslexerLexerStaticData = nullptr;

void regionslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (regionslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(regionslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RegionsLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "SUMPRODUCT", "LN", "LG", 
      "LOG_X", "EXP", "SQRT", "ADD", "SUB", "MUL", "DIV", "POW", "STRING", 
      "VARIABLE", "VARIABLE_RANGE", "WS", "EOL", "INT", "UINT", "EXPONENT", 
      "FLOAT", "NUMBER", "CONSTANTS", "PI"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,24,207,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,
  	1,16,1,16,4,16,110,8,16,11,16,12,16,111,1,16,1,16,1,17,1,17,1,17,1,17,
  	4,17,120,8,17,11,17,12,17,121,1,17,5,17,125,8,17,10,17,12,17,128,9,17,
  	3,17,130,8,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,4,18,139,8,18,11,18,
  	12,18,140,1,18,5,18,144,8,18,10,18,12,18,147,9,18,3,18,149,8,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,19,4,19,159,8,19,11,19,12,19,160,1,19,
  	1,19,1,20,3,20,166,8,20,1,20,1,20,1,21,3,21,171,8,21,1,21,1,21,1,22,4,
  	22,176,8,22,11,22,12,22,177,1,23,1,23,1,23,1,24,1,24,1,24,1,24,3,24,187,
  	8,24,1,25,1,25,3,25,191,8,25,1,25,3,25,194,8,25,1,26,1,26,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,27,1,27,3,27,206,8,27,0,0,28,1,1,3,2,5,3,7,4,9,5,
  	11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,
  	18,37,19,39,20,41,21,43,0,45,0,47,0,49,0,51,22,53,23,55,24,1,0,6,7,0,
  	32,33,44,44,46,46,48,59,63,63,65,90,97,122,4,0,39,39,42,42,65,90,97,122,
  	1,0,48,57,2,0,9,9,32,32,2,0,43,43,45,45,2,0,69,69,101,101,218,0,1,1,0,
  	0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,
  	1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,
  	0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,
  	0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,1,57,1,0,0,0,3,59,1,0,0,0,5,61,1,0,0,0,7,63,1,0,
  	0,0,9,65,1,0,0,0,11,67,1,0,0,0,13,78,1,0,0,0,15,81,1,0,0,0,17,84,1,0,
  	0,0,19,88,1,0,0,0,21,92,1,0,0,0,23,97,1,0,0,0,25,99,1,0,0,0,27,101,1,
  	0,0,0,29,103,1,0,0,0,31,105,1,0,0,0,33,107,1,0,0,0,35,115,1,0,0,0,37,
  	134,1,0,0,0,39,158,1,0,0,0,41,165,1,0,0,0,43,170,1,0,0,0,45,175,1,0,0,
  	0,47,179,1,0,0,0,49,182,1,0,0,0,51,190,1,0,0,0,53,195,1,0,0,0,55,205,
  	1,0,0,0,57,58,5,40,0,0,58,2,1,0,0,0,59,60,5,41,0,0,60,4,1,0,0,0,61,62,
  	5,91,0,0,62,6,1,0,0,0,63,64,5,44,0,0,64,8,1,0,0,0,65,66,5,93,0,0,66,10,
  	1,0,0,0,67,68,5,115,0,0,68,69,5,117,0,0,69,70,5,109,0,0,70,71,5,112,0,
  	0,71,72,5,114,0,0,72,73,5,111,0,0,73,74,5,100,0,0,74,75,5,117,0,0,75,
  	76,5,99,0,0,76,77,5,116,0,0,77,12,1,0,0,0,78,79,5,76,0,0,79,80,5,110,
  	0,0,80,14,1,0,0,0,81,82,5,76,0,0,82,83,5,103,0,0,83,16,1,0,0,0,84,85,
  	5,76,0,0,85,86,5,111,0,0,86,87,5,103,0,0,87,18,1,0,0,0,88,89,5,69,0,0,
  	89,90,5,120,0,0,90,91,5,112,0,0,91,20,1,0,0,0,92,93,5,83,0,0,93,94,5,
  	113,0,0,94,95,5,114,0,0,95,96,5,116,0,0,96,22,1,0,0,0,97,98,5,43,0,0,
  	98,24,1,0,0,0,99,100,5,45,0,0,100,26,1,0,0,0,101,102,5,42,0,0,102,28,
  	1,0,0,0,103,104,5,47,0,0,104,30,1,0,0,0,105,106,5,94,0,0,106,32,1,0,0,
  	0,107,109,5,34,0,0,108,110,7,0,0,0,109,108,1,0,0,0,110,111,1,0,0,0,111,
  	109,1,0,0,0,111,112,1,0,0,0,112,113,1,0,0,0,113,114,5,34,0,0,114,34,1,
  	0,0,0,115,116,5,95,0,0,116,117,5,95,0,0,117,119,1,0,0,0,118,120,7,1,0,
  	0,119,118,1,0,0,0,120,121,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,
  	129,1,0,0,0,123,125,7,2,0,0,124,123,1,0,0,0,125,128,1,0,0,0,126,124,1,
  	0,0,0,126,127,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,129,126,1,0,0,0,
  	129,130,1,0,0,0,130,131,1,0,0,0,131,132,5,95,0,0,132,133,5,95,0,0,133,
  	36,1,0,0,0,134,135,5,95,0,0,135,136,5,95,0,0,136,138,1,0,0,0,137,139,
  	7,1,0,0,138,137,1,0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,
  	0,141,148,1,0,0,0,142,144,7,2,0,0,143,142,1,0,0,0,144,147,1,0,0,0,145,
  	143,1,0,0,0,145,146,1,0,0,0,146,149,1,0,0,0,147,145,1,0,0,0,148,145,1,
  	0,0,0,148,149,1,0,0,0,149,150,1,0,0,0,150,151,5,95,0,0,151,152,5,97,0,
  	0,152,153,5,114,0,0,153,154,5,114,0,0,154,155,5,95,0,0,155,156,5,95,0,
  	0,156,38,1,0,0,0,157,159,7,3,0,0,158,157,1,0,0,0,159,160,1,0,0,0,160,
  	158,1,0,0,0,160,161,1,0,0,0,161,162,1,0,0,0,162,163,6,19,0,0,163,40,1,
  	0,0,0,164,166,5,13,0,0,165,164,1,0,0,0,165,166,1,0,0,0,166,167,1,0,0,
  	0,167,168,5,10,0,0,168,42,1,0,0,0,169,171,7,4,0,0,170,169,1,0,0,0,170,
  	171,1,0,0,0,171,172,1,0,0,0,172,173,3,45,22,0,173,44,1,0,0,0,174,176,
  	7,2,0,0,175,174,1,0,0,0,176,177,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,
  	0,178,46,1,0,0,0,179,180,7,5,0,0,180,181,3,43,21,0,181,48,1,0,0,0,182,
  	183,3,45,22,0,183,184,5,46,0,0,184,186,3,45,22,0,185,187,3,47,23,0,186,
  	185,1,0,0,0,186,187,1,0,0,0,187,50,1,0,0,0,188,191,3,45,22,0,189,191,
  	3,49,24,0,190,188,1,0,0,0,190,189,1,0,0,0,191,193,1,0,0,0,192,194,3,47,
  	23,0,193,192,1,0,0,0,193,194,1,0,0,0,194,52,1,0,0,0,195,196,3,55,27,0,
  	196,54,1,0,0,0,197,198,5,80,0,0,198,206,5,105,0,0,199,200,5,80,0,0,200,
  	206,5,73,0,0,201,202,5,112,0,0,202,203,5,105,0,0,203,204,1,0,0,0,204,
  	206,3,39,19,0,205,197,1,0,0,0,205,199,1,0,0,0,205,201,1,0,0,0,206,56,
  	1,0,0,0,16,0,111,121,126,129,140,145,148,160,165,170,177,186,190,193,
  	205,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  regionslexerLexerStaticData = staticData.release();
}

}

regionsLexer::regionsLexer(CharStream *input) : Lexer(input) {
  regionsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *regionslexerLexerStaticData->atn, regionslexerLexerStaticData->decisionToDFA, regionslexerLexerStaticData->sharedContextCache);
}

regionsLexer::~regionsLexer() {
  delete _interpreter;
}

std::string regionsLexer::getGrammarFileName() const {
  return "regions.g4";
}

const std::vector<std::string>& regionsLexer::getRuleNames() const {
  return regionslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& regionsLexer::getChannelNames() const {
  return regionslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& regionsLexer::getModeNames() const {
  return regionslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& regionsLexer::getVocabulary() const {
  return regionslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView regionsLexer::getSerializedATN() const {
  return regionslexerLexerStaticData->serializedATN;
}

const atn::ATN& regionsLexer::getATN() const {
  return *regionslexerLexerStaticData->atn;
}




void regionsLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  regionslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(regionslexerLexerOnceFlag, regionslexerLexerInitialize);
#endif
}
