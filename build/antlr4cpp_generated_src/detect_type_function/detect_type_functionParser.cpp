
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1


#include "detect_type_functionListener.h"

#include "detect_type_functionParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Detect_type_functionParserStaticData final {
  Detect_type_functionParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Detect_type_functionParserStaticData(const Detect_type_functionParserStaticData&) = delete;
  Detect_type_functionParserStaticData(Detect_type_functionParserStaticData&&) = delete;
  Detect_type_functionParserStaticData& operator=(const Detect_type_functionParserStaticData&) = delete;
  Detect_type_functionParserStaticData& operator=(Detect_type_functionParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag detect_type_functionParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
Detect_type_functionParserStaticData *detect_type_functionParserStaticData = nullptr;

void detect_type_functionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (detect_type_functionParserStaticData != nullptr) {
    return;
  }
#else
  assert(detect_type_functionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Detect_type_functionParserStaticData>(
    std::vector<std::string>{
      "value_type", "line_input", "node_access", "variable", "expr", "array", 
      "number", "constant", "function", "multiargfunction", "rangefunction", 
      "string"
    },
    std::vector<std::string>{
      "", "'('", "')'", "';'", "'VAR('", "'['", "']'", "'\"'", "", "", "'>'", 
      "", "'='", "", "'<'", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", 
      "'^'", "'''"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "VARIABLE", "DATABASE", "LARGER", 
      "LARGER_EQUAL", "EQUAL", "LESS", "LESS_EQUAL", "SUMPRODUCT", "SUMPRODUCT_I", 
      "SUM", "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", "LOG_X", "EXP", 
      "SQRT", "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", "STRING", 
      "WS", "EOL", "UINT", "ADD", "SUB", "MUL", "DIV", "POW", "QUOTE", "ASTERISK", 
      "EXPONENT", "FLOAT", "ID_NUMBER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,680,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,3,0,28,8,0,1,1,
  	1,1,3,1,32,8,1,1,2,5,2,35,8,2,10,2,12,2,38,9,2,1,2,1,2,5,2,42,8,2,10,
  	2,12,2,45,9,2,1,2,1,2,1,2,5,2,50,8,2,10,2,12,2,53,9,2,1,2,1,2,5,2,57,
  	8,2,10,2,12,2,60,9,2,1,2,1,2,1,2,5,2,65,8,2,10,2,12,2,68,9,2,1,2,1,2,
  	5,2,72,8,2,10,2,12,2,75,9,2,1,2,1,2,5,2,79,8,2,10,2,12,2,82,9,2,1,2,5,
  	2,85,8,2,10,2,12,2,88,9,2,1,2,5,2,91,8,2,10,2,12,2,94,9,2,1,2,1,2,1,2,
  	5,2,99,8,2,10,2,12,2,102,9,2,3,2,104,8,2,1,3,5,3,107,8,3,10,3,12,3,110,
  	9,3,1,3,1,3,5,3,114,8,3,10,3,12,3,117,9,3,1,3,1,3,1,3,5,3,122,8,3,10,
  	3,12,3,125,9,3,1,3,5,3,128,8,3,10,3,12,3,131,9,3,1,3,1,3,5,3,135,8,3,
  	10,3,12,3,138,9,3,3,3,140,8,3,1,3,1,3,3,3,144,8,3,1,3,1,3,3,3,148,8,3,
  	3,3,150,8,3,1,3,5,3,153,8,3,10,3,12,3,156,9,3,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,3,4,167,8,4,1,4,1,4,3,4,171,8,4,1,4,1,4,5,4,175,8,4,10,4,
  	12,4,178,9,4,1,4,3,4,181,8,4,1,4,1,4,1,4,1,4,1,4,5,4,188,8,4,10,4,12,
  	4,191,9,4,1,4,1,4,5,4,195,8,4,10,4,12,4,198,9,4,1,4,1,4,1,4,5,4,203,8,
  	4,10,4,12,4,206,9,4,1,4,1,4,5,4,210,8,4,10,4,12,4,213,9,4,1,4,5,4,216,
  	8,4,10,4,12,4,219,9,4,1,5,1,5,5,5,223,8,5,10,5,12,5,226,9,5,1,5,1,5,3,
  	5,230,8,5,1,5,5,5,233,8,5,10,5,12,5,236,9,5,1,5,1,5,5,5,240,8,5,10,5,
  	12,5,243,9,5,1,5,1,5,3,5,247,8,5,5,5,249,8,5,10,5,12,5,252,9,5,1,5,1,
  	5,1,6,1,6,1,7,1,7,1,8,5,8,261,8,8,10,8,12,8,264,9,8,1,8,1,8,1,8,5,8,269,
  	8,8,10,8,12,8,272,9,8,1,8,1,8,5,8,276,8,8,10,8,12,8,279,9,8,1,8,1,8,5,
  	8,283,8,8,10,8,12,8,286,9,8,1,8,5,8,289,8,8,10,8,12,8,292,9,8,1,8,1,8,
  	1,8,5,8,297,8,8,10,8,12,8,300,9,8,1,8,1,8,5,8,304,8,8,10,8,12,8,307,9,
  	8,1,8,1,8,5,8,311,8,8,10,8,12,8,314,9,8,1,8,5,8,317,8,8,10,8,12,8,320,
  	9,8,1,8,1,8,1,8,5,8,325,8,8,10,8,12,8,328,9,8,1,8,1,8,5,8,332,8,8,10,
  	8,12,8,335,9,8,1,8,1,8,5,8,339,8,8,10,8,12,8,342,9,8,1,8,5,8,345,8,8,
  	10,8,12,8,348,9,8,1,8,1,8,1,8,5,8,353,8,8,10,8,12,8,356,9,8,1,8,1,8,5,
  	8,360,8,8,10,8,12,8,363,9,8,1,8,1,8,5,8,367,8,8,10,8,12,8,370,9,8,1,8,
  	5,8,373,8,8,10,8,12,8,376,9,8,1,8,1,8,1,8,5,8,381,8,8,10,8,12,8,384,9,
  	8,1,8,1,8,5,8,388,8,8,10,8,12,8,391,9,8,1,8,1,8,5,8,395,8,8,10,8,12,8,
  	398,9,8,1,8,5,8,401,8,8,10,8,12,8,404,9,8,1,8,1,8,1,8,5,8,409,8,8,10,
  	8,12,8,412,9,8,1,8,1,8,5,8,416,8,8,10,8,12,8,419,9,8,1,8,1,8,5,8,423,
  	8,8,10,8,12,8,426,9,8,1,8,5,8,429,8,8,10,8,12,8,432,9,8,1,8,1,8,1,8,5,
  	8,437,8,8,10,8,12,8,440,9,8,1,8,1,8,5,8,444,8,8,10,8,12,8,447,9,8,1,8,
  	1,8,5,8,451,8,8,10,8,12,8,454,9,8,1,8,5,8,457,8,8,10,8,12,8,460,9,8,1,
  	8,1,8,1,8,5,8,465,8,8,10,8,12,8,468,9,8,1,8,1,8,5,8,472,8,8,10,8,12,8,
  	475,9,8,1,8,1,8,5,8,479,8,8,10,8,12,8,482,9,8,1,8,5,8,485,8,8,10,8,12,
  	8,488,9,8,1,8,1,8,1,8,5,8,493,8,8,10,8,12,8,496,9,8,1,8,1,8,5,8,500,8,
  	8,10,8,12,8,503,9,8,1,8,1,8,5,8,507,8,8,10,8,12,8,510,9,8,1,8,5,8,513,
  	8,8,10,8,12,8,516,9,8,1,8,1,8,1,8,5,8,521,8,8,10,8,12,8,524,9,8,1,8,1,
  	8,5,8,528,8,8,10,8,12,8,531,9,8,1,8,1,8,5,8,535,8,8,10,8,12,8,538,9,8,
  	1,8,1,8,5,8,542,8,8,10,8,12,8,545,9,8,1,8,1,8,5,8,549,8,8,10,8,12,8,552,
  	9,8,3,8,554,8,8,1,9,5,9,557,8,9,10,9,12,9,560,9,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,5,9,569,8,9,10,9,12,9,572,9,9,1,9,1,9,1,9,5,9,577,8,9,10,9,12,
  	9,580,9,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,589,8,9,10,9,12,9,592,9,9,1,
  	9,1,9,1,9,5,9,597,8,9,10,9,12,9,600,9,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,
  	9,609,8,9,10,9,12,9,612,9,9,1,9,1,9,3,9,616,8,9,1,10,5,10,619,8,10,10,
  	10,12,10,622,9,10,1,10,1,10,1,10,5,10,627,8,10,10,10,12,10,630,9,10,1,
  	10,1,10,5,10,634,8,10,10,10,12,10,637,9,10,1,10,1,10,5,10,641,8,10,10,
  	10,12,10,644,9,10,1,10,5,10,647,8,10,10,10,12,10,650,9,10,1,10,1,10,1,
  	10,5,10,655,8,10,10,10,12,10,658,9,10,1,10,1,10,5,10,662,8,10,10,10,12,
  	10,665,9,10,1,10,1,10,5,10,669,8,10,10,10,12,10,672,9,10,3,10,674,8,10,
  	1,11,1,11,1,11,1,11,1,11,0,1,8,12,0,2,4,6,8,10,12,14,16,18,20,22,0,4,
  	1,0,36,37,1,0,38,39,2,0,35,35,44,44,2,0,24,24,26,26,781,0,27,1,0,0,0,
  	2,31,1,0,0,0,4,103,1,0,0,0,6,108,1,0,0,0,8,180,1,0,0,0,10,220,1,0,0,0,
  	12,255,1,0,0,0,14,257,1,0,0,0,16,553,1,0,0,0,18,615,1,0,0,0,20,673,1,
  	0,0,0,22,675,1,0,0,0,24,28,3,10,5,0,25,28,3,8,4,0,26,28,3,22,11,0,27,
  	24,1,0,0,0,27,25,1,0,0,0,27,26,1,0,0,0,28,1,1,0,0,0,29,32,3,10,5,0,30,
  	32,3,8,4,0,31,29,1,0,0,0,31,30,1,0,0,0,32,3,1,0,0,0,33,35,5,33,0,0,34,
  	33,1,0,0,0,35,38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,39,1,0,0,0,38,
  	36,1,0,0,0,39,43,5,1,0,0,40,42,5,33,0,0,41,40,1,0,0,0,42,45,1,0,0,0,43,
  	41,1,0,0,0,43,44,1,0,0,0,44,46,1,0,0,0,45,43,1,0,0,0,46,104,5,2,0,0,47,
  	51,5,1,0,0,48,50,5,33,0,0,49,48,1,0,0,0,50,53,1,0,0,0,51,49,1,0,0,0,51,
  	52,1,0,0,0,52,54,1,0,0,0,53,51,1,0,0,0,54,58,5,35,0,0,55,57,5,33,0,0,
  	56,55,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,1,0,0,0,
  	60,58,1,0,0,0,61,104,5,2,0,0,62,66,5,1,0,0,63,65,5,33,0,0,64,63,1,0,0,
  	0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,69,1,0,0,0,68,66,1,0,0,
  	0,69,73,5,35,0,0,70,72,5,33,0,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,
  	0,0,73,74,1,0,0,0,74,86,1,0,0,0,75,73,1,0,0,0,76,80,5,3,0,0,77,79,5,33,
  	0,0,78,77,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,83,1,0,
  	0,0,82,80,1,0,0,0,83,85,5,35,0,0,84,76,1,0,0,0,85,88,1,0,0,0,86,84,1,
  	0,0,0,86,87,1,0,0,0,87,92,1,0,0,0,88,86,1,0,0,0,89,91,5,33,0,0,90,89,
  	1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,95,1,0,0,0,94,92,
  	1,0,0,0,95,96,5,2,0,0,96,100,1,0,0,0,97,99,5,33,0,0,98,97,1,0,0,0,99,
  	102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,104,1,0,0,0,102,100,1,
  	0,0,0,103,36,1,0,0,0,103,47,1,0,0,0,103,62,1,0,0,0,104,5,1,0,0,0,105,
  	107,5,33,0,0,106,105,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,
  	1,0,0,0,109,149,1,0,0,0,110,108,1,0,0,0,111,139,5,4,0,0,112,114,5,33,
  	0,0,113,112,1,0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,
  	118,1,0,0,0,117,115,1,0,0,0,118,119,5,9,0,0,119,123,5,8,0,0,120,122,5,
  	33,0,0,121,120,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,
  	0,124,140,1,0,0,0,125,123,1,0,0,0,126,128,5,33,0,0,127,126,1,0,0,0,128,
  	131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,132,1,0,0,0,131,129,1,
  	0,0,0,132,136,5,8,0,0,133,135,5,33,0,0,134,133,1,0,0,0,135,138,1,0,0,
  	0,136,134,1,0,0,0,136,137,1,0,0,0,137,140,1,0,0,0,138,136,1,0,0,0,139,
  	115,1,0,0,0,139,129,1,0,0,0,140,141,1,0,0,0,141,143,5,2,0,0,142,144,3,
  	4,2,0,143,142,1,0,0,0,143,144,1,0,0,0,144,150,1,0,0,0,145,147,5,8,0,0,
  	146,148,3,4,2,0,147,146,1,0,0,0,147,148,1,0,0,0,148,150,1,0,0,0,149,111,
  	1,0,0,0,149,145,1,0,0,0,150,154,1,0,0,0,151,153,5,33,0,0,152,151,1,0,
  	0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,7,1,0,0,0,156,
  	154,1,0,0,0,157,158,6,4,-1,0,158,159,5,1,0,0,159,160,3,8,4,0,160,161,
  	5,2,0,0,161,181,1,0,0,0,162,181,3,6,3,0,163,167,3,16,8,0,164,167,3,18,
  	9,0,165,167,3,20,10,0,166,163,1,0,0,0,166,164,1,0,0,0,166,165,1,0,0,0,
  	167,181,1,0,0,0,168,171,3,12,6,0,169,171,3,14,7,0,170,168,1,0,0,0,170,
  	169,1,0,0,0,171,181,1,0,0,0,172,176,7,0,0,0,173,175,5,33,0,0,174,173,
  	1,0,0,0,175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,
  	0,178,176,1,0,0,0,179,181,3,8,4,4,180,157,1,0,0,0,180,162,1,0,0,0,180,
  	166,1,0,0,0,180,170,1,0,0,0,180,172,1,0,0,0,181,217,1,0,0,0,182,183,10,
  	3,0,0,183,184,5,40,0,0,184,216,3,8,4,4,185,189,10,2,0,0,186,188,5,33,
  	0,0,187,186,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,
  	192,1,0,0,0,191,189,1,0,0,0,192,196,7,1,0,0,193,195,5,33,0,0,194,193,
  	1,0,0,0,195,198,1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,199,1,0,0,
  	0,198,196,1,0,0,0,199,216,3,8,4,3,200,204,10,1,0,0,201,203,5,33,0,0,202,
  	201,1,0,0,0,203,206,1,0,0,0,204,202,1,0,0,0,204,205,1,0,0,0,205,207,1,
  	0,0,0,206,204,1,0,0,0,207,211,7,0,0,0,208,210,5,33,0,0,209,208,1,0,0,
  	0,210,213,1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,214,1,0,0,0,213,
  	211,1,0,0,0,214,216,3,8,4,2,215,182,1,0,0,0,215,185,1,0,0,0,215,200,1,
  	0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,9,1,0,0,0,219,
  	217,1,0,0,0,220,224,5,5,0,0,221,223,5,33,0,0,222,221,1,0,0,0,223,226,
  	1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,229,1,0,0,0,226,224,1,0,0,
  	0,227,230,3,8,4,0,228,230,3,10,5,0,229,227,1,0,0,0,229,228,1,0,0,0,230,
  	234,1,0,0,0,231,233,5,33,0,0,232,231,1,0,0,0,233,236,1,0,0,0,234,232,
  	1,0,0,0,234,235,1,0,0,0,235,250,1,0,0,0,236,234,1,0,0,0,237,241,5,3,0,
  	0,238,240,5,33,0,0,239,238,1,0,0,0,240,243,1,0,0,0,241,239,1,0,0,0,241,
  	242,1,0,0,0,242,246,1,0,0,0,243,241,1,0,0,0,244,247,3,8,4,0,245,247,3,
  	10,5,0,246,244,1,0,0,0,246,245,1,0,0,0,247,249,1,0,0,0,248,237,1,0,0,
  	0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,1,0,0,0,252,
  	250,1,0,0,0,253,254,5,6,0,0,254,11,1,0,0,0,255,256,7,2,0,0,256,13,1,0,
  	0,0,257,258,7,3,0,0,258,15,1,0,0,0,259,261,5,33,0,0,260,259,1,0,0,0,261,
  	264,1,0,0,0,262,260,1,0,0,0,262,263,1,0,0,0,263,265,1,0,0,0,264,262,1,
  	0,0,0,265,266,5,21,0,0,266,270,5,1,0,0,267,269,5,33,0,0,268,267,1,0,0,
  	0,269,272,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,271,273,1,0,0,0,272,
  	270,1,0,0,0,273,277,3,8,4,0,274,276,5,33,0,0,275,274,1,0,0,0,276,279,
  	1,0,0,0,277,275,1,0,0,0,277,278,1,0,0,0,278,280,1,0,0,0,279,277,1,0,0,
  	0,280,284,5,2,0,0,281,283,5,33,0,0,282,281,1,0,0,0,283,286,1,0,0,0,284,
  	282,1,0,0,0,284,285,1,0,0,0,285,554,1,0,0,0,286,284,1,0,0,0,287,289,5,
  	33,0,0,288,287,1,0,0,0,289,292,1,0,0,0,290,288,1,0,0,0,290,291,1,0,0,
  	0,291,293,1,0,0,0,292,290,1,0,0,0,293,294,5,22,0,0,294,298,5,1,0,0,295,
  	297,5,33,0,0,296,295,1,0,0,0,297,300,1,0,0,0,298,296,1,0,0,0,298,299,
  	1,0,0,0,299,301,1,0,0,0,300,298,1,0,0,0,301,305,3,8,4,0,302,304,5,33,
  	0,0,303,302,1,0,0,0,304,307,1,0,0,0,305,303,1,0,0,0,305,306,1,0,0,0,306,
  	308,1,0,0,0,307,305,1,0,0,0,308,312,5,2,0,0,309,311,5,33,0,0,310,309,
  	1,0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,554,1,0,0,
  	0,314,312,1,0,0,0,315,317,5,33,0,0,316,315,1,0,0,0,317,320,1,0,0,0,318,
  	316,1,0,0,0,318,319,1,0,0,0,319,321,1,0,0,0,320,318,1,0,0,0,321,322,5,
  	24,0,0,322,326,5,1,0,0,323,325,5,33,0,0,324,323,1,0,0,0,325,328,1,0,0,
  	0,326,324,1,0,0,0,326,327,1,0,0,0,327,329,1,0,0,0,328,326,1,0,0,0,329,
  	333,3,8,4,0,330,332,5,33,0,0,331,330,1,0,0,0,332,335,1,0,0,0,333,331,
  	1,0,0,0,333,334,1,0,0,0,334,336,1,0,0,0,335,333,1,0,0,0,336,340,5,2,0,
  	0,337,339,5,33,0,0,338,337,1,0,0,0,339,342,1,0,0,0,340,338,1,0,0,0,340,
  	341,1,0,0,0,341,554,1,0,0,0,342,340,1,0,0,0,343,345,5,33,0,0,344,343,
  	1,0,0,0,345,348,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,349,1,0,0,
  	0,348,346,1,0,0,0,349,350,5,25,0,0,350,354,5,1,0,0,351,353,5,33,0,0,352,
  	351,1,0,0,0,353,356,1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,0,355,357,1,
  	0,0,0,356,354,1,0,0,0,357,361,3,8,4,0,358,360,5,33,0,0,359,358,1,0,0,
  	0,360,363,1,0,0,0,361,359,1,0,0,0,361,362,1,0,0,0,362,364,1,0,0,0,363,
  	361,1,0,0,0,364,368,5,2,0,0,365,367,5,33,0,0,366,365,1,0,0,0,367,370,
  	1,0,0,0,368,366,1,0,0,0,368,369,1,0,0,0,369,554,1,0,0,0,370,368,1,0,0,
  	0,371,373,5,33,0,0,372,371,1,0,0,0,373,376,1,0,0,0,374,372,1,0,0,0,374,
  	375,1,0,0,0,375,377,1,0,0,0,376,374,1,0,0,0,377,378,5,27,0,0,378,382,
  	5,1,0,0,379,381,5,33,0,0,380,379,1,0,0,0,381,384,1,0,0,0,382,380,1,0,
  	0,0,382,383,1,0,0,0,383,385,1,0,0,0,384,382,1,0,0,0,385,389,3,8,4,0,386,
  	388,5,33,0,0,387,386,1,0,0,0,388,391,1,0,0,0,389,387,1,0,0,0,389,390,
  	1,0,0,0,390,392,1,0,0,0,391,389,1,0,0,0,392,396,5,2,0,0,393,395,5,33,
  	0,0,394,393,1,0,0,0,395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,
  	554,1,0,0,0,398,396,1,0,0,0,399,401,5,33,0,0,400,399,1,0,0,0,401,404,
  	1,0,0,0,402,400,1,0,0,0,402,403,1,0,0,0,403,405,1,0,0,0,404,402,1,0,0,
  	0,405,406,5,28,0,0,406,410,5,1,0,0,407,409,5,33,0,0,408,407,1,0,0,0,409,
  	412,1,0,0,0,410,408,1,0,0,0,410,411,1,0,0,0,411,413,1,0,0,0,412,410,1,
  	0,0,0,413,417,3,8,4,0,414,416,5,33,0,0,415,414,1,0,0,0,416,419,1,0,0,
  	0,417,415,1,0,0,0,417,418,1,0,0,0,418,420,1,0,0,0,419,417,1,0,0,0,420,
  	424,5,2,0,0,421,423,5,33,0,0,422,421,1,0,0,0,423,426,1,0,0,0,424,422,
  	1,0,0,0,424,425,1,0,0,0,425,554,1,0,0,0,426,424,1,0,0,0,427,429,5,33,
  	0,0,428,427,1,0,0,0,429,432,1,0,0,0,430,428,1,0,0,0,430,431,1,0,0,0,431,
  	433,1,0,0,0,432,430,1,0,0,0,433,434,5,30,0,0,434,438,5,1,0,0,435,437,
  	5,33,0,0,436,435,1,0,0,0,437,440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,
  	0,0,439,441,1,0,0,0,440,438,1,0,0,0,441,445,3,8,4,0,442,444,5,33,0,0,
  	443,442,1,0,0,0,444,447,1,0,0,0,445,443,1,0,0,0,445,446,1,0,0,0,446,448,
  	1,0,0,0,447,445,1,0,0,0,448,452,5,2,0,0,449,451,5,33,0,0,450,449,1,0,
  	0,0,451,454,1,0,0,0,452,450,1,0,0,0,452,453,1,0,0,0,453,554,1,0,0,0,454,
  	452,1,0,0,0,455,457,5,33,0,0,456,455,1,0,0,0,457,460,1,0,0,0,458,456,
  	1,0,0,0,458,459,1,0,0,0,459,461,1,0,0,0,460,458,1,0,0,0,461,462,5,29,
  	0,0,462,466,5,1,0,0,463,465,5,33,0,0,464,463,1,0,0,0,465,468,1,0,0,0,
  	466,464,1,0,0,0,466,467,1,0,0,0,467,469,1,0,0,0,468,466,1,0,0,0,469,473,
  	3,8,4,0,470,472,5,33,0,0,471,470,1,0,0,0,472,475,1,0,0,0,473,471,1,0,
  	0,0,473,474,1,0,0,0,474,476,1,0,0,0,475,473,1,0,0,0,476,480,5,2,0,0,477,
  	479,5,33,0,0,478,477,1,0,0,0,479,482,1,0,0,0,480,478,1,0,0,0,480,481,
  	1,0,0,0,481,554,1,0,0,0,482,480,1,0,0,0,483,485,5,33,0,0,484,483,1,0,
  	0,0,485,488,1,0,0,0,486,484,1,0,0,0,486,487,1,0,0,0,487,489,1,0,0,0,488,
  	486,1,0,0,0,489,490,5,31,0,0,490,494,5,1,0,0,491,493,5,33,0,0,492,491,
  	1,0,0,0,493,496,1,0,0,0,494,492,1,0,0,0,494,495,1,0,0,0,495,497,1,0,0,
  	0,496,494,1,0,0,0,497,501,3,8,4,0,498,500,5,33,0,0,499,498,1,0,0,0,500,
  	503,1,0,0,0,501,499,1,0,0,0,501,502,1,0,0,0,502,504,1,0,0,0,503,501,1,
  	0,0,0,504,508,5,2,0,0,505,507,5,33,0,0,506,505,1,0,0,0,507,510,1,0,0,
  	0,508,506,1,0,0,0,508,509,1,0,0,0,509,554,1,0,0,0,510,508,1,0,0,0,511,
  	513,5,33,0,0,512,511,1,0,0,0,513,516,1,0,0,0,514,512,1,0,0,0,514,515,
  	1,0,0,0,515,517,1,0,0,0,516,514,1,0,0,0,517,518,5,23,0,0,518,522,5,1,
  	0,0,519,521,5,33,0,0,520,519,1,0,0,0,521,524,1,0,0,0,522,520,1,0,0,0,
  	522,523,1,0,0,0,523,525,1,0,0,0,524,522,1,0,0,0,525,529,3,8,4,0,526,528,
  	5,33,0,0,527,526,1,0,0,0,528,531,1,0,0,0,529,527,1,0,0,0,529,530,1,0,
  	0,0,530,532,1,0,0,0,531,529,1,0,0,0,532,536,5,3,0,0,533,535,5,33,0,0,
  	534,533,1,0,0,0,535,538,1,0,0,0,536,534,1,0,0,0,536,537,1,0,0,0,537,539,
  	1,0,0,0,538,536,1,0,0,0,539,543,3,8,4,0,540,542,5,33,0,0,541,540,1,0,
  	0,0,542,545,1,0,0,0,543,541,1,0,0,0,543,544,1,0,0,0,544,546,1,0,0,0,545,
  	543,1,0,0,0,546,550,5,2,0,0,547,549,5,33,0,0,548,547,1,0,0,0,549,552,
  	1,0,0,0,550,548,1,0,0,0,550,551,1,0,0,0,551,554,1,0,0,0,552,550,1,0,0,
  	0,553,262,1,0,0,0,553,290,1,0,0,0,553,318,1,0,0,0,553,346,1,0,0,0,553,
  	374,1,0,0,0,553,402,1,0,0,0,553,430,1,0,0,0,553,458,1,0,0,0,553,486,1,
  	0,0,0,553,514,1,0,0,0,554,17,1,0,0,0,555,557,5,33,0,0,556,555,1,0,0,0,
  	557,560,1,0,0,0,558,556,1,0,0,0,558,559,1,0,0,0,559,561,1,0,0,0,560,558,
  	1,0,0,0,561,562,5,15,0,0,562,563,5,1,0,0,563,564,3,8,4,0,564,565,5,3,
  	0,0,565,570,3,8,4,0,566,567,5,3,0,0,567,569,3,8,4,0,568,566,1,0,0,0,569,
  	572,1,0,0,0,570,568,1,0,0,0,570,571,1,0,0,0,571,573,1,0,0,0,572,570,1,
  	0,0,0,573,574,5,2,0,0,574,616,1,0,0,0,575,577,5,33,0,0,576,575,1,0,0,
  	0,577,580,1,0,0,0,578,576,1,0,0,0,578,579,1,0,0,0,579,581,1,0,0,0,580,
  	578,1,0,0,0,581,582,5,17,0,0,582,583,5,1,0,0,583,584,3,8,4,0,584,585,
  	5,3,0,0,585,590,3,8,4,0,586,587,5,3,0,0,587,589,3,8,4,0,588,586,1,0,0,
  	0,589,592,1,0,0,0,590,588,1,0,0,0,590,591,1,0,0,0,591,593,1,0,0,0,592,
  	590,1,0,0,0,593,594,5,2,0,0,594,616,1,0,0,0,595,597,5,33,0,0,596,595,
  	1,0,0,0,597,600,1,0,0,0,598,596,1,0,0,0,598,599,1,0,0,0,599,601,1,0,0,
  	0,600,598,1,0,0,0,601,602,5,19,0,0,602,603,5,1,0,0,603,604,3,8,4,0,604,
  	605,5,3,0,0,605,610,3,8,4,0,606,607,5,3,0,0,607,609,3,8,4,0,608,606,1,
  	0,0,0,609,612,1,0,0,0,610,608,1,0,0,0,610,611,1,0,0,0,611,613,1,0,0,0,
  	612,610,1,0,0,0,613,614,5,2,0,0,614,616,1,0,0,0,615,558,1,0,0,0,615,578,
  	1,0,0,0,615,598,1,0,0,0,616,19,1,0,0,0,617,619,5,33,0,0,618,617,1,0,0,
  	0,619,622,1,0,0,0,620,618,1,0,0,0,620,621,1,0,0,0,621,623,1,0,0,0,622,
  	620,1,0,0,0,623,624,5,18,0,0,624,628,5,1,0,0,625,627,5,33,0,0,626,625,
  	1,0,0,0,627,630,1,0,0,0,628,626,1,0,0,0,628,629,1,0,0,0,629,631,1,0,0,
  	0,630,628,1,0,0,0,631,635,3,8,4,0,632,634,5,33,0,0,633,632,1,0,0,0,634,
  	637,1,0,0,0,635,633,1,0,0,0,635,636,1,0,0,0,636,638,1,0,0,0,637,635,1,
  	0,0,0,638,642,5,2,0,0,639,641,5,33,0,0,640,639,1,0,0,0,641,644,1,0,0,
  	0,642,640,1,0,0,0,642,643,1,0,0,0,643,674,1,0,0,0,644,642,1,0,0,0,645,
  	647,5,33,0,0,646,645,1,0,0,0,647,650,1,0,0,0,648,646,1,0,0,0,648,649,
  	1,0,0,0,649,651,1,0,0,0,650,648,1,0,0,0,651,652,5,20,0,0,652,656,5,1,
  	0,0,653,655,5,33,0,0,654,653,1,0,0,0,655,658,1,0,0,0,656,654,1,0,0,0,
  	656,657,1,0,0,0,657,659,1,0,0,0,658,656,1,0,0,0,659,663,3,8,4,0,660,662,
  	5,33,0,0,661,660,1,0,0,0,662,665,1,0,0,0,663,661,1,0,0,0,663,664,1,0,
  	0,0,664,666,1,0,0,0,665,663,1,0,0,0,666,670,5,2,0,0,667,669,5,33,0,0,
  	668,667,1,0,0,0,669,672,1,0,0,0,670,668,1,0,0,0,670,671,1,0,0,0,671,674,
  	1,0,0,0,672,670,1,0,0,0,673,620,1,0,0,0,673,648,1,0,0,0,674,21,1,0,0,
  	0,675,676,5,7,0,0,676,677,5,32,0,0,677,678,5,7,0,0,678,23,1,0,0,0,98,
  	27,31,36,43,51,58,66,73,80,86,92,100,103,108,115,123,129,136,139,143,
  	147,149,154,166,170,176,180,189,196,204,211,215,217,224,229,234,241,246,
  	250,262,270,277,284,290,298,305,312,318,326,333,340,346,354,361,368,374,
  	382,389,396,402,410,417,424,430,438,445,452,458,466,473,480,486,494,501,
  	508,514,522,529,536,543,550,553,558,570,578,590,598,610,615,620,628,635,
  	642,648,656,663,670,673
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  detect_type_functionParserStaticData = staticData.release();
}

}

detect_type_functionParser::detect_type_functionParser(TokenStream *input) : detect_type_functionParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

detect_type_functionParser::detect_type_functionParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  detect_type_functionParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *detect_type_functionParserStaticData->atn, detect_type_functionParserStaticData->decisionToDFA, detect_type_functionParserStaticData->sharedContextCache, options);
}

detect_type_functionParser::~detect_type_functionParser() {
  delete _interpreter;
}

const atn::ATN& detect_type_functionParser::getATN() const {
  return *detect_type_functionParserStaticData->atn;
}

std::string detect_type_functionParser::getGrammarFileName() const {
  return "detect_type_function.g4";
}

const std::vector<std::string>& detect_type_functionParser::getRuleNames() const {
  return detect_type_functionParserStaticData->ruleNames;
}

const dfa::Vocabulary& detect_type_functionParser::getVocabulary() const {
  return detect_type_functionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView detect_type_functionParser::getSerializedATN() const {
  return detect_type_functionParserStaticData->serializedATN;
}


//----------------- Value_typeContext ------------------------------------------------------------------

detect_type_functionParser::Value_typeContext::Value_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::ArrayContext* detect_type_functionParser::Value_typeContext::array() {
  return getRuleContext<detect_type_functionParser::ArrayContext>(0);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::Value_typeContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}

detect_type_functionParser::StringContext* detect_type_functionParser::Value_typeContext::string() {
  return getRuleContext<detect_type_functionParser::StringContext>(0);
}


size_t detect_type_functionParser::Value_typeContext::getRuleIndex() const {
  return detect_type_functionParser::RuleValue_type;
}

void detect_type_functionParser::Value_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_type(this);
}

void detect_type_functionParser::Value_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_type(this);
}

detect_type_functionParser::Value_typeContext* detect_type_functionParser::value_type() {
  Value_typeContext *_localctx = _tracker.createInstance<Value_typeContext>(_ctx, getState());
  enterRule(_localctx, 0, detect_type_functionParser::RuleValue_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(27);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        array();
        break;
      }

      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::SUMPRODUCT:
      case detect_type_functionParser::SUM:
      case detect_type_functionParser::SUM_I:
      case detect_type_functionParser::PRODUCT:
      case detect_type_functionParser::PRODUCT_I:
      case detect_type_functionParser::LN:
      case detect_type_functionParser::LG:
      case detect_type_functionParser::LOG_X:
      case detect_type_functionParser::EXP:
      case detect_type_functionParser::SQRT:
      case detect_type_functionParser::PI:
      case detect_type_functionParser::COS:
      case detect_type_functionParser::SIN:
      case detect_type_functionParser::ASIN:
      case detect_type_functionParser::ACOS:
      case detect_type_functionParser::FACTORIAL:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
      case detect_type_functionParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        expr(0);
        break;
      }

      case detect_type_functionParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(26);
        string();
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

//----------------- Line_inputContext ------------------------------------------------------------------

detect_type_functionParser::Line_inputContext::Line_inputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::ArrayContext* detect_type_functionParser::Line_inputContext::array() {
  return getRuleContext<detect_type_functionParser::ArrayContext>(0);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::Line_inputContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}


size_t detect_type_functionParser::Line_inputContext::getRuleIndex() const {
  return detect_type_functionParser::RuleLine_input;
}

void detect_type_functionParser::Line_inputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine_input(this);
}

void detect_type_functionParser::Line_inputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine_input(this);
}

detect_type_functionParser::Line_inputContext* detect_type_functionParser::line_input() {
  Line_inputContext *_localctx = _tracker.createInstance<Line_inputContext>(_ctx, getState());
  enterRule(_localctx, 2, detect_type_functionParser::RuleLine_input);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(29);
        array();
        break;
      }

      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::SUMPRODUCT:
      case detect_type_functionParser::SUM:
      case detect_type_functionParser::SUM_I:
      case detect_type_functionParser::PRODUCT:
      case detect_type_functionParser::PRODUCT_I:
      case detect_type_functionParser::LN:
      case detect_type_functionParser::LG:
      case detect_type_functionParser::LOG_X:
      case detect_type_functionParser::EXP:
      case detect_type_functionParser::SQRT:
      case detect_type_functionParser::PI:
      case detect_type_functionParser::COS:
      case detect_type_functionParser::SIN:
      case detect_type_functionParser::ASIN:
      case detect_type_functionParser::ACOS:
      case detect_type_functionParser::FACTORIAL:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
      case detect_type_functionParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(30);
        expr(0);
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

//----------------- Node_accessContext ------------------------------------------------------------------

detect_type_functionParser::Node_accessContext::Node_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> detect_type_functionParser::Node_accessContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::Node_accessContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::Node_accessContext::UINT() {
  return getTokens(detect_type_functionParser::UINT);
}

tree::TerminalNode* detect_type_functionParser::Node_accessContext::UINT(size_t i) {
  return getToken(detect_type_functionParser::UINT, i);
}


size_t detect_type_functionParser::Node_accessContext::getRuleIndex() const {
  return detect_type_functionParser::RuleNode_access;
}

void detect_type_functionParser::Node_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_access(this);
}

void detect_type_functionParser::Node_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_access(this);
}

detect_type_functionParser::Node_accessContext* detect_type_functionParser::node_access() {
  Node_accessContext *_localctx = _tracker.createInstance<Node_accessContext>(_ctx, getState());
  enterRule(_localctx, 4, detect_type_functionParser::RuleNode_access);
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
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(33);
        match(detect_type_functionParser::WS);
        setState(38);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(39);
      match(detect_type_functionParser::T__0);
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(40);
        match(detect_type_functionParser::WS);
        setState(45);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(46);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      match(detect_type_functionParser::T__0);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(48);
        match(detect_type_functionParser::WS);
        setState(53);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(54);
      match(detect_type_functionParser::UINT);
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(55);
        match(detect_type_functionParser::WS);
        setState(60);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(61);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(62);
      match(detect_type_functionParser::T__0);
      setState(66);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(63);
        match(detect_type_functionParser::WS);
        setState(68);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(69);
      match(detect_type_functionParser::UINT);
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(70);
          match(detect_type_functionParser::WS); 
        }
        setState(75);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      }
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(76);
        match(detect_type_functionParser::T__2);
        setState(80);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == detect_type_functionParser::WS) {
          setState(77);
          match(detect_type_functionParser::WS);
          setState(82);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(83);
        match(detect_type_functionParser::UINT);
        setState(88);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(89);
        match(detect_type_functionParser::WS);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(95);
      match(detect_type_functionParser::T__1);
      setState(100);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(97);
          match(detect_type_functionParser::WS); 
        }
        setState(102);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

detect_type_functionParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> detect_type_functionParser::VariableContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::VariableContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

tree::TerminalNode* detect_type_functionParser::VariableContext::VARIABLE() {
  return getToken(detect_type_functionParser::VARIABLE, 0);
}

tree::TerminalNode* detect_type_functionParser::VariableContext::DATABASE() {
  return getToken(detect_type_functionParser::DATABASE, 0);
}

detect_type_functionParser::Node_accessContext* detect_type_functionParser::VariableContext::node_access() {
  return getRuleContext<detect_type_functionParser::Node_accessContext>(0);
}


size_t detect_type_functionParser::VariableContext::getRuleIndex() const {
  return detect_type_functionParser::RuleVariable;
}

void detect_type_functionParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void detect_type_functionParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

detect_type_functionParser::VariableContext* detect_type_functionParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 6, detect_type_functionParser::RuleVariable);
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
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(105);
      match(detect_type_functionParser::WS);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3: {
        setState(111);
        match(detect_type_functionParser::T__3);
        setState(139);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(115);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(112);
            match(detect_type_functionParser::WS);
            setState(117);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(118);
          match(detect_type_functionParser::DATABASE);
          setState(119);
          match(detect_type_functionParser::VARIABLE);
          setState(123);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(120);
            match(detect_type_functionParser::WS);
            setState(125);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(129);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(126);
            match(detect_type_functionParser::WS);
            setState(131);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(132);
          match(detect_type_functionParser::VARIABLE);
          setState(136);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(133);
            match(detect_type_functionParser::WS);
            setState(138);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(141);
        match(detect_type_functionParser::T__1);
        setState(143);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          setState(142);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case detect_type_functionParser::VARIABLE: {
        setState(145);
        match(detect_type_functionParser::VARIABLE);
        setState(147);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(146);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(154);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(151);
        match(detect_type_functionParser::WS); 
      }
      setState(156);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

detect_type_functionParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t detect_type_functionParser::ExprContext::getRuleIndex() const {
  return detect_type_functionParser::RuleExpr;
}

void detect_type_functionParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

detect_type_functionParser::ExprContext* detect_type_functionParser::UnaryOpContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}

tree::TerminalNode* detect_type_functionParser::UnaryOpContext::ADD() {
  return getToken(detect_type_functionParser::ADD, 0);
}

tree::TerminalNode* detect_type_functionParser::UnaryOpContext::SUB() {
  return getToken(detect_type_functionParser::SUB, 0);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::UnaryOpContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::UnaryOpContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

detect_type_functionParser::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void detect_type_functionParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- ParensContext ------------------------------------------------------------------

detect_type_functionParser::ExprContext* detect_type_functionParser::ParensContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}

detect_type_functionParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void detect_type_functionParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

detect_type_functionParser::NumberContext* detect_type_functionParser::LiteralContext::number() {
  return getRuleContext<detect_type_functionParser::NumberContext>(0);
}

detect_type_functionParser::ConstantContext* detect_type_functionParser::LiteralContext::constant() {
  return getRuleContext<detect_type_functionParser::ConstantContext>(0);
}

detect_type_functionParser::LiteralContext::LiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void detect_type_functionParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

detect_type_functionParser::FunctionContext* detect_type_functionParser::FunctionCallContext::function() {
  return getRuleContext<detect_type_functionParser::FunctionContext>(0);
}

detect_type_functionParser::MultiargfunctionContext* detect_type_functionParser::FunctionCallContext::multiargfunction() {
  return getRuleContext<detect_type_functionParser::MultiargfunctionContext>(0);
}

detect_type_functionParser::RangefunctionContext* detect_type_functionParser::FunctionCallContext::rangefunction() {
  return getRuleContext<detect_type_functionParser::RangefunctionContext>(0);
}

detect_type_functionParser::FunctionCallContext::FunctionCallContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void detect_type_functionParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}
//----------------- VariableInExprContext ------------------------------------------------------------------

detect_type_functionParser::VariableContext* detect_type_functionParser::VariableInExprContext::variable() {
  return getRuleContext<detect_type_functionParser::VariableContext>(0);
}

detect_type_functionParser::VariableInExprContext::VariableInExprContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::VariableInExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInExpr(this);
}
void detect_type_functionParser::VariableInExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInExpr(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<detect_type_functionParser::ExprContext *> detect_type_functionParser::BinaryOpContext::expr() {
  return getRuleContexts<detect_type_functionParser::ExprContext>();
}

detect_type_functionParser::ExprContext* detect_type_functionParser::BinaryOpContext::expr(size_t i) {
  return getRuleContext<detect_type_functionParser::ExprContext>(i);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::POW() {
  return getToken(detect_type_functionParser::POW, 0);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::MUL() {
  return getToken(detect_type_functionParser::MUL, 0);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::DIV() {
  return getToken(detect_type_functionParser::DIV, 0);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::BinaryOpContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::ADD() {
  return getToken(detect_type_functionParser::ADD, 0);
}

tree::TerminalNode* detect_type_functionParser::BinaryOpContext::SUB() {
  return getToken(detect_type_functionParser::SUB, 0);
}

detect_type_functionParser::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void detect_type_functionParser::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::expr() {
   return expr(0);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  detect_type_functionParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  detect_type_functionParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, detect_type_functionParser::RuleExpr, precedence);

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
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(158);
      match(detect_type_functionParser::T__0);
      setState(159);
      expr(0);
      setState(160);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(162);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(166);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(163);
        function();
        break;
      }

      case 2: {
        setState(164);
        multiargfunction();
        break;
      }

      case 3: {
        setState(165);
        rangefunction();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(170);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_functionParser::UINT:
        case detect_type_functionParser::FLOAT: {
          setState(168);
          number();
          break;
        }

        case detect_type_functionParser::EXP:
        case detect_type_functionParser::PI: {
          setState(169);
          constant();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<UnaryOpContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(172);
      _la = _input->LA(1);
      if (!(_la == detect_type_functionParser::ADD

      || _la == detect_type_functionParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(176);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(173);
          match(detect_type_functionParser::WS); 
        }
        setState(178);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      }
      setState(179);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(182);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(183);
          match(detect_type_functionParser::POW);
          setState(184);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(185);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(189);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(186);
            match(detect_type_functionParser::WS);
            setState(191);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(192);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::MUL

          || _la == detect_type_functionParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(196);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(193);
              match(detect_type_functionParser::WS); 
            }
            setState(198);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
          }
          setState(199);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(200);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(204);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(201);
            match(detect_type_functionParser::WS);
            setState(206);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(207);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::ADD

          || _la == detect_type_functionParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(211);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(208);
              match(detect_type_functionParser::WS); 
            }
            setState(213);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
          }
          setState(214);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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

detect_type_functionParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<detect_type_functionParser::ExprContext *> detect_type_functionParser::ArrayContext::expr() {
  return getRuleContexts<detect_type_functionParser::ExprContext>();
}

detect_type_functionParser::ExprContext* detect_type_functionParser::ArrayContext::expr(size_t i) {
  return getRuleContext<detect_type_functionParser::ExprContext>(i);
}

std::vector<detect_type_functionParser::ArrayContext *> detect_type_functionParser::ArrayContext::array() {
  return getRuleContexts<detect_type_functionParser::ArrayContext>();
}

detect_type_functionParser::ArrayContext* detect_type_functionParser::ArrayContext::array(size_t i) {
  return getRuleContext<detect_type_functionParser::ArrayContext>(i);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::ArrayContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::ArrayContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}


size_t detect_type_functionParser::ArrayContext::getRuleIndex() const {
  return detect_type_functionParser::RuleArray;
}

void detect_type_functionParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void detect_type_functionParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

detect_type_functionParser::ArrayContext* detect_type_functionParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 10, detect_type_functionParser::RuleArray);
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
    setState(220);
    match(detect_type_functionParser::T__4);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(221);
        match(detect_type_functionParser::WS); 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::SUMPRODUCT:
      case detect_type_functionParser::SUM:
      case detect_type_functionParser::SUM_I:
      case detect_type_functionParser::PRODUCT:
      case detect_type_functionParser::PRODUCT_I:
      case detect_type_functionParser::LN:
      case detect_type_functionParser::LG:
      case detect_type_functionParser::LOG_X:
      case detect_type_functionParser::EXP:
      case detect_type_functionParser::SQRT:
      case detect_type_functionParser::PI:
      case detect_type_functionParser::COS:
      case detect_type_functionParser::SIN:
      case detect_type_functionParser::ASIN:
      case detect_type_functionParser::ACOS:
      case detect_type_functionParser::FACTORIAL:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
      case detect_type_functionParser::FLOAT: {
        setState(227);
        expr(0);
        break;
      }

      case detect_type_functionParser::T__4: {
        setState(228);
        array();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(231);
      match(detect_type_functionParser::WS);
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::T__2) {
      setState(237);
      match(detect_type_functionParser::T__2);
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(238);
          match(detect_type_functionParser::WS); 
        }
        setState(243);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      }
      setState(246);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_functionParser::T__0:
        case detect_type_functionParser::T__3:
        case detect_type_functionParser::VARIABLE:
        case detect_type_functionParser::SUMPRODUCT:
        case detect_type_functionParser::SUM:
        case detect_type_functionParser::SUM_I:
        case detect_type_functionParser::PRODUCT:
        case detect_type_functionParser::PRODUCT_I:
        case detect_type_functionParser::LN:
        case detect_type_functionParser::LG:
        case detect_type_functionParser::LOG_X:
        case detect_type_functionParser::EXP:
        case detect_type_functionParser::SQRT:
        case detect_type_functionParser::PI:
        case detect_type_functionParser::COS:
        case detect_type_functionParser::SIN:
        case detect_type_functionParser::ASIN:
        case detect_type_functionParser::ACOS:
        case detect_type_functionParser::FACTORIAL:
        case detect_type_functionParser::WS:
        case detect_type_functionParser::UINT:
        case detect_type_functionParser::ADD:
        case detect_type_functionParser::SUB:
        case detect_type_functionParser::FLOAT: {
          setState(244);
          expr(0);
          break;
        }

        case detect_type_functionParser::T__4: {
          setState(245);
          array();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(253);
    match(detect_type_functionParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

detect_type_functionParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::NumberContext::UINT() {
  return getToken(detect_type_functionParser::UINT, 0);
}

tree::TerminalNode* detect_type_functionParser::NumberContext::FLOAT() {
  return getToken(detect_type_functionParser::FLOAT, 0);
}


size_t detect_type_functionParser::NumberContext::getRuleIndex() const {
  return detect_type_functionParser::RuleNumber;
}

void detect_type_functionParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void detect_type_functionParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

detect_type_functionParser::NumberContext* detect_type_functionParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 12, detect_type_functionParser::RuleNumber);
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
    setState(255);
    _la = _input->LA(1);
    if (!(_la == detect_type_functionParser::UINT

    || _la == detect_type_functionParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

detect_type_functionParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::ConstantContext::PI() {
  return getToken(detect_type_functionParser::PI, 0);
}

tree::TerminalNode* detect_type_functionParser::ConstantContext::EXP() {
  return getToken(detect_type_functionParser::EXP, 0);
}


size_t detect_type_functionParser::ConstantContext::getRuleIndex() const {
  return detect_type_functionParser::RuleConstant;
}

void detect_type_functionParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void detect_type_functionParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

detect_type_functionParser::ConstantContext* detect_type_functionParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 14, detect_type_functionParser::RuleConstant);
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
    setState(257);
    _la = _input->LA(1);
    if (!(_la == detect_type_functionParser::EXP

    || _la == detect_type_functionParser::PI)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

detect_type_functionParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::LN() {
  return getToken(detect_type_functionParser::LN, 0);
}

std::vector<detect_type_functionParser::ExprContext *> detect_type_functionParser::FunctionContext::expr() {
  return getRuleContexts<detect_type_functionParser::ExprContext>();
}

detect_type_functionParser::ExprContext* detect_type_functionParser::FunctionContext::expr(size_t i) {
  return getRuleContext<detect_type_functionParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::FunctionContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::LG() {
  return getToken(detect_type_functionParser::LG, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::EXP() {
  return getToken(detect_type_functionParser::EXP, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::SQRT() {
  return getToken(detect_type_functionParser::SQRT, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::COS() {
  return getToken(detect_type_functionParser::COS, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::SIN() {
  return getToken(detect_type_functionParser::SIN, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::ACOS() {
  return getToken(detect_type_functionParser::ACOS, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::ASIN() {
  return getToken(detect_type_functionParser::ASIN, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::FACTORIAL() {
  return getToken(detect_type_functionParser::FACTORIAL, 0);
}

tree::TerminalNode* detect_type_functionParser::FunctionContext::LOG_X() {
  return getToken(detect_type_functionParser::LOG_X, 0);
}


size_t detect_type_functionParser::FunctionContext::getRuleIndex() const {
  return detect_type_functionParser::RuleFunction;
}

void detect_type_functionParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void detect_type_functionParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

detect_type_functionParser::FunctionContext* detect_type_functionParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 16, detect_type_functionParser::RuleFunction);
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
    setState(553);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(259);
        match(detect_type_functionParser::WS);
        setState(264);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(265);
      match(detect_type_functionParser::LN);
      setState(266);
      match(detect_type_functionParser::T__0);
      setState(270);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(267);
          match(detect_type_functionParser::WS); 
        }
        setState(272);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      }
      setState(273);
      expr(0);
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(274);
        match(detect_type_functionParser::WS);
        setState(279);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(280);
      match(detect_type_functionParser::T__1);
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(281);
          match(detect_type_functionParser::WS); 
        }
        setState(286);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(290);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(287);
        match(detect_type_functionParser::WS);
        setState(292);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(293);
      match(detect_type_functionParser::LG);
      setState(294);
      match(detect_type_functionParser::T__0);
      setState(298);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(295);
          match(detect_type_functionParser::WS); 
        }
        setState(300);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
      }
      setState(301);
      expr(0);
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(302);
        match(detect_type_functionParser::WS);
        setState(307);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(308);
      match(detect_type_functionParser::T__1);
      setState(312);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(309);
          match(detect_type_functionParser::WS); 
        }
        setState(314);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(318);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(315);
        match(detect_type_functionParser::WS);
        setState(320);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(321);
      match(detect_type_functionParser::EXP);
      setState(322);
      match(detect_type_functionParser::T__0);
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(323);
          match(detect_type_functionParser::WS); 
        }
        setState(328);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
      }
      setState(329);
      expr(0);
      setState(333);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(330);
        match(detect_type_functionParser::WS);
        setState(335);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(336);
      match(detect_type_functionParser::T__1);
      setState(340);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(337);
          match(detect_type_functionParser::WS); 
        }
        setState(342);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(343);
        match(detect_type_functionParser::WS);
        setState(348);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(349);
      match(detect_type_functionParser::SQRT);
      setState(350);
      match(detect_type_functionParser::T__0);
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(351);
          match(detect_type_functionParser::WS); 
        }
        setState(356);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(357);
      expr(0);
      setState(361);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(358);
        match(detect_type_functionParser::WS);
        setState(363);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(364);
      match(detect_type_functionParser::T__1);
      setState(368);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(365);
          match(detect_type_functionParser::WS); 
        }
        setState(370);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(371);
        match(detect_type_functionParser::WS);
        setState(376);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(377);
      match(detect_type_functionParser::COS);
      setState(378);
      match(detect_type_functionParser::T__0);
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(379);
          match(detect_type_functionParser::WS); 
        }
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
      }
      setState(385);
      expr(0);
      setState(389);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(386);
        match(detect_type_functionParser::WS);
        setState(391);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(392);
      match(detect_type_functionParser::T__1);
      setState(396);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(393);
          match(detect_type_functionParser::WS); 
        }
        setState(398);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(399);
        match(detect_type_functionParser::WS);
        setState(404);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(405);
      match(detect_type_functionParser::SIN);
      setState(406);
      match(detect_type_functionParser::T__0);
      setState(410);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(407);
          match(detect_type_functionParser::WS); 
        }
        setState(412);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
      }
      setState(413);
      expr(0);
      setState(417);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(414);
        match(detect_type_functionParser::WS);
        setState(419);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(420);
      match(detect_type_functionParser::T__1);
      setState(424);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(421);
          match(detect_type_functionParser::WS); 
        }
        setState(426);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(430);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(427);
        match(detect_type_functionParser::WS);
        setState(432);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(433);
      match(detect_type_functionParser::ACOS);
      setState(434);
      match(detect_type_functionParser::T__0);
      setState(438);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(435);
          match(detect_type_functionParser::WS); 
        }
        setState(440);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
      }
      setState(441);
      expr(0);
      setState(445);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(442);
        match(detect_type_functionParser::WS);
        setState(447);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(448);
      match(detect_type_functionParser::T__1);
      setState(452);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(449);
          match(detect_type_functionParser::WS); 
        }
        setState(454);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(458);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(455);
        match(detect_type_functionParser::WS);
        setState(460);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(461);
      match(detect_type_functionParser::ASIN);
      setState(462);
      match(detect_type_functionParser::T__0);
      setState(466);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(463);
          match(detect_type_functionParser::WS); 
        }
        setState(468);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      }
      setState(469);
      expr(0);
      setState(473);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(470);
        match(detect_type_functionParser::WS);
        setState(475);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(476);
      match(detect_type_functionParser::T__1);
      setState(480);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(477);
          match(detect_type_functionParser::WS); 
        }
        setState(482);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(486);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(483);
        match(detect_type_functionParser::WS);
        setState(488);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(489);
      match(detect_type_functionParser::FACTORIAL);
      setState(490);
      match(detect_type_functionParser::T__0);
      setState(494);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(491);
          match(detect_type_functionParser::WS); 
        }
        setState(496);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
      }
      setState(497);
      expr(0);
      setState(501);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(498);
        match(detect_type_functionParser::WS);
        setState(503);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(504);
      match(detect_type_functionParser::T__1);
      setState(508);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(505);
          match(detect_type_functionParser::WS); 
        }
        setState(510);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(514);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(511);
        match(detect_type_functionParser::WS);
        setState(516);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(517);
      match(detect_type_functionParser::LOG_X);
      setState(518);
      match(detect_type_functionParser::T__0);
      setState(522);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(519);
          match(detect_type_functionParser::WS); 
        }
        setState(524);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
      }
      setState(525);
      expr(0);
      setState(529);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(526);
        match(detect_type_functionParser::WS);
        setState(531);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(532);
      match(detect_type_functionParser::T__2);
      setState(536);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(533);
          match(detect_type_functionParser::WS); 
        }
        setState(538);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
      }
      setState(539);
      expr(0);
      setState(543);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(540);
        match(detect_type_functionParser::WS);
        setState(545);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(546);
      match(detect_type_functionParser::T__1);
      setState(550);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(547);
          match(detect_type_functionParser::WS); 
        }
        setState(552);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiargfunctionContext ------------------------------------------------------------------

detect_type_functionParser::MultiargfunctionContext::MultiargfunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::MultiargfunctionContext::SUMPRODUCT() {
  return getToken(detect_type_functionParser::SUMPRODUCT, 0);
}

std::vector<detect_type_functionParser::ExprContext *> detect_type_functionParser::MultiargfunctionContext::expr() {
  return getRuleContexts<detect_type_functionParser::ExprContext>();
}

detect_type_functionParser::ExprContext* detect_type_functionParser::MultiargfunctionContext::expr(size_t i) {
  return getRuleContext<detect_type_functionParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::MultiargfunctionContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::MultiargfunctionContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

tree::TerminalNode* detect_type_functionParser::MultiargfunctionContext::SUM() {
  return getToken(detect_type_functionParser::SUM, 0);
}

tree::TerminalNode* detect_type_functionParser::MultiargfunctionContext::PRODUCT() {
  return getToken(detect_type_functionParser::PRODUCT, 0);
}


size_t detect_type_functionParser::MultiargfunctionContext::getRuleIndex() const {
  return detect_type_functionParser::RuleMultiargfunction;
}

void detect_type_functionParser::MultiargfunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiargfunction(this);
}

void detect_type_functionParser::MultiargfunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiargfunction(this);
}

detect_type_functionParser::MultiargfunctionContext* detect_type_functionParser::multiargfunction() {
  MultiargfunctionContext *_localctx = _tracker.createInstance<MultiargfunctionContext>(_ctx, getState());
  enterRule(_localctx, 18, detect_type_functionParser::RuleMultiargfunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(615);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(558);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(555);
        match(detect_type_functionParser::WS);
        setState(560);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(561);
      match(detect_type_functionParser::SUMPRODUCT);
      setState(562);
      match(detect_type_functionParser::T__0);
      setState(563);
      expr(0);
      setState(564);
      match(detect_type_functionParser::T__2);
      setState(565);
      expr(0);
      setState(570);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(566);
        match(detect_type_functionParser::T__2);
        setState(567);
        expr(0);
        setState(572);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(573);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(578);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(575);
        match(detect_type_functionParser::WS);
        setState(580);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(581);
      match(detect_type_functionParser::SUM);
      setState(582);
      match(detect_type_functionParser::T__0);
      setState(583);
      expr(0);
      setState(584);
      match(detect_type_functionParser::T__2);
      setState(585);
      expr(0);
      setState(590);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(586);
        match(detect_type_functionParser::T__2);
        setState(587);
        expr(0);
        setState(592);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(593);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(598);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(595);
        match(detect_type_functionParser::WS);
        setState(600);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(601);
      match(detect_type_functionParser::PRODUCT);
      setState(602);
      match(detect_type_functionParser::T__0);
      setState(603);
      expr(0);
      setState(604);
      match(detect_type_functionParser::T__2);
      setState(605);
      expr(0);
      setState(610);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(606);
        match(detect_type_functionParser::T__2);
        setState(607);
        expr(0);
        setState(612);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(613);
      match(detect_type_functionParser::T__1);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangefunctionContext ------------------------------------------------------------------

detect_type_functionParser::RangefunctionContext::RangefunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::RangefunctionContext::SUM_I() {
  return getToken(detect_type_functionParser::SUM_I, 0);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::RangefunctionContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::RangefunctionContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::RangefunctionContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

tree::TerminalNode* detect_type_functionParser::RangefunctionContext::PRODUCT_I() {
  return getToken(detect_type_functionParser::PRODUCT_I, 0);
}


size_t detect_type_functionParser::RangefunctionContext::getRuleIndex() const {
  return detect_type_functionParser::RuleRangefunction;
}

void detect_type_functionParser::RangefunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangefunction(this);
}

void detect_type_functionParser::RangefunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangefunction(this);
}

detect_type_functionParser::RangefunctionContext* detect_type_functionParser::rangefunction() {
  RangefunctionContext *_localctx = _tracker.createInstance<RangefunctionContext>(_ctx, getState());
  enterRule(_localctx, 20, detect_type_functionParser::RuleRangefunction);
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
    setState(673);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(620);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(617);
        match(detect_type_functionParser::WS);
        setState(622);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(623);
      match(detect_type_functionParser::SUM_I);
      setState(624);
      match(detect_type_functionParser::T__0);
      setState(628);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(625);
          match(detect_type_functionParser::WS); 
        }
        setState(630);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
      }
      setState(631);
      expr(0);
      setState(635);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(632);
        match(detect_type_functionParser::WS);
        setState(637);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(638);
      match(detect_type_functionParser::T__1);
      setState(642);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(639);
          match(detect_type_functionParser::WS); 
        }
        setState(644);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(648);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(645);
        match(detect_type_functionParser::WS);
        setState(650);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(651);
      match(detect_type_functionParser::PRODUCT_I);
      setState(652);
      match(detect_type_functionParser::T__0);
      setState(656);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(653);
          match(detect_type_functionParser::WS); 
        }
        setState(658);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
      }
      setState(659);
      expr(0);
      setState(663);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(660);
        match(detect_type_functionParser::WS);
        setState(665);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(666);
      match(detect_type_functionParser::T__1);
      setState(670);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(667);
          match(detect_type_functionParser::WS); 
        }
        setState(672);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

detect_type_functionParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::StringContext::STRING() {
  return getToken(detect_type_functionParser::STRING, 0);
}


size_t detect_type_functionParser::StringContext::getRuleIndex() const {
  return detect_type_functionParser::RuleString;
}

void detect_type_functionParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void detect_type_functionParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

detect_type_functionParser::StringContext* detect_type_functionParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 22, detect_type_functionParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(675);
    match(detect_type_functionParser::T__6);
    setState(676);
    match(detect_type_functionParser::STRING);
    setState(677);
    match(detect_type_functionParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool detect_type_functionParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool detect_type_functionParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void detect_type_functionParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  detect_type_functionParserInitialize();
#else
  ::antlr4::internal::call_once(detect_type_functionParserOnceFlag, detect_type_functionParserInitialize);
#endif
}
