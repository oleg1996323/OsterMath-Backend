
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
      "value_type", "input", "line_input", "node_access", "variable", "expr", 
      "array", "input_array", "number", "constant", "function", "multiargfunction", 
      "rangefunction", "string"
    },
    std::vector<std::string>{
      "", "'('", "')'", "';'", "'VAR('", "'['", "']'", "'\"'", "", "", "", 
      "", "", "'+'", "'-'", "'*'", "'/'", "'^'", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "'''"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "VARIABLE", "DATABASE", "WS", "EOL", 
      "UINT", "ADD", "SUB", "MUL", "DIV", "POW", "SUMPRODUCT", "SUMPRODUCT_I", 
      "SUM", "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", "LOG_X", "EXP", 
      "SQRT", "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", "QUOTE", 
      "ASTERISK", "EXPONENT", "FLOAT", "ID_NUMBER", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,690,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,3,0,32,8,0,1,1,4,1,35,8,1,11,1,12,1,36,1,1,3,1,40,8,1,1,2,1,2,3,2,
  	44,8,2,1,3,5,3,47,8,3,10,3,12,3,50,9,3,1,3,1,3,5,3,54,8,3,10,3,12,3,57,
  	9,3,1,3,1,3,1,3,5,3,62,8,3,10,3,12,3,65,9,3,1,3,1,3,5,3,69,8,3,10,3,12,
  	3,72,9,3,1,3,1,3,1,3,5,3,77,8,3,10,3,12,3,80,9,3,1,3,1,3,5,3,84,8,3,10,
  	3,12,3,87,9,3,1,3,1,3,5,3,91,8,3,10,3,12,3,94,9,3,1,3,5,3,97,8,3,10,3,
  	12,3,100,9,3,1,3,5,3,103,8,3,10,3,12,3,106,9,3,1,3,1,3,1,3,5,3,111,8,
  	3,10,3,12,3,114,9,3,3,3,116,8,3,1,4,5,4,119,8,4,10,4,12,4,122,9,4,1,4,
  	1,4,5,4,126,8,4,10,4,12,4,129,9,4,1,4,1,4,1,4,5,4,134,8,4,10,4,12,4,137,
  	9,4,1,4,5,4,140,8,4,10,4,12,4,143,9,4,1,4,1,4,5,4,147,8,4,10,4,12,4,150,
  	9,4,3,4,152,8,4,1,4,1,4,3,4,156,8,4,1,4,1,4,3,4,160,8,4,3,4,162,8,4,1,
  	4,5,4,165,8,4,10,4,12,4,168,9,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,
  	5,179,8,5,1,5,1,5,3,5,183,8,5,1,5,1,5,5,5,187,8,5,10,5,12,5,190,9,5,1,
  	5,3,5,193,8,5,1,5,1,5,1,5,1,5,1,5,5,5,200,8,5,10,5,12,5,203,9,5,1,5,1,
  	5,5,5,207,8,5,10,5,12,5,210,9,5,1,5,1,5,1,5,5,5,215,8,5,10,5,12,5,218,
  	9,5,1,5,1,5,5,5,222,8,5,10,5,12,5,225,9,5,1,5,5,5,228,8,5,10,5,12,5,231,
  	9,5,1,6,1,6,5,6,235,8,6,10,6,12,6,238,9,6,1,6,1,6,5,6,242,8,6,10,6,12,
  	6,245,9,6,1,6,1,6,5,6,249,8,6,10,6,12,6,252,9,6,1,6,5,6,255,8,6,10,6,
  	12,6,258,9,6,1,6,1,6,1,7,1,7,3,7,264,8,7,1,8,1,8,1,9,1,9,1,10,5,10,271,
  	8,10,10,10,12,10,274,9,10,1,10,1,10,1,10,5,10,279,8,10,10,10,12,10,282,
  	9,10,1,10,1,10,5,10,286,8,10,10,10,12,10,289,9,10,1,10,1,10,5,10,293,
  	8,10,10,10,12,10,296,9,10,1,10,5,10,299,8,10,10,10,12,10,302,9,10,1,10,
  	1,10,1,10,5,10,307,8,10,10,10,12,10,310,9,10,1,10,1,10,5,10,314,8,10,
  	10,10,12,10,317,9,10,1,10,1,10,5,10,321,8,10,10,10,12,10,324,9,10,1,10,
  	5,10,327,8,10,10,10,12,10,330,9,10,1,10,1,10,1,10,5,10,335,8,10,10,10,
  	12,10,338,9,10,1,10,1,10,5,10,342,8,10,10,10,12,10,345,9,10,1,10,1,10,
  	5,10,349,8,10,10,10,12,10,352,9,10,1,10,5,10,355,8,10,10,10,12,10,358,
  	9,10,1,10,1,10,1,10,5,10,363,8,10,10,10,12,10,366,9,10,1,10,1,10,5,10,
  	370,8,10,10,10,12,10,373,9,10,1,10,1,10,5,10,377,8,10,10,10,12,10,380,
  	9,10,1,10,5,10,383,8,10,10,10,12,10,386,9,10,1,10,1,10,1,10,5,10,391,
  	8,10,10,10,12,10,394,9,10,1,10,1,10,5,10,398,8,10,10,10,12,10,401,9,10,
  	1,10,1,10,5,10,405,8,10,10,10,12,10,408,9,10,1,10,5,10,411,8,10,10,10,
  	12,10,414,9,10,1,10,1,10,1,10,5,10,419,8,10,10,10,12,10,422,9,10,1,10,
  	1,10,5,10,426,8,10,10,10,12,10,429,9,10,1,10,1,10,5,10,433,8,10,10,10,
  	12,10,436,9,10,1,10,5,10,439,8,10,10,10,12,10,442,9,10,1,10,1,10,1,10,
  	5,10,447,8,10,10,10,12,10,450,9,10,1,10,1,10,5,10,454,8,10,10,10,12,10,
  	457,9,10,1,10,1,10,5,10,461,8,10,10,10,12,10,464,9,10,1,10,5,10,467,8,
  	10,10,10,12,10,470,9,10,1,10,1,10,1,10,5,10,475,8,10,10,10,12,10,478,
  	9,10,1,10,1,10,5,10,482,8,10,10,10,12,10,485,9,10,1,10,1,10,5,10,489,
  	8,10,10,10,12,10,492,9,10,1,10,5,10,495,8,10,10,10,12,10,498,9,10,1,10,
  	1,10,1,10,5,10,503,8,10,10,10,12,10,506,9,10,1,10,1,10,5,10,510,8,10,
  	10,10,12,10,513,9,10,1,10,1,10,5,10,517,8,10,10,10,12,10,520,9,10,1,10,
  	5,10,523,8,10,10,10,12,10,526,9,10,1,10,1,10,1,10,5,10,531,8,10,10,10,
  	12,10,534,9,10,1,10,1,10,5,10,538,8,10,10,10,12,10,541,9,10,1,10,1,10,
  	5,10,545,8,10,10,10,12,10,548,9,10,1,10,1,10,5,10,552,8,10,10,10,12,10,
  	555,9,10,1,10,1,10,5,10,559,8,10,10,10,12,10,562,9,10,3,10,564,8,10,1,
  	11,5,11,567,8,11,10,11,12,11,570,9,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,5,11,579,8,11,10,11,12,11,582,9,11,1,11,1,11,1,11,5,11,587,8,11,10,
  	11,12,11,590,9,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,599,8,11,10,
  	11,12,11,602,9,11,1,11,1,11,1,11,5,11,607,8,11,10,11,12,11,610,9,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,619,8,11,10,11,12,11,622,9,11,1,
  	11,1,11,3,11,626,8,11,1,12,5,12,629,8,12,10,12,12,12,632,9,12,1,12,1,
  	12,1,12,5,12,637,8,12,10,12,12,12,640,9,12,1,12,1,12,5,12,644,8,12,10,
  	12,12,12,647,9,12,1,12,1,12,5,12,651,8,12,10,12,12,12,654,9,12,1,12,5,
  	12,657,8,12,10,12,12,12,660,9,12,1,12,1,12,1,12,5,12,665,8,12,10,12,12,
  	12,668,9,12,1,12,1,12,5,12,672,8,12,10,12,12,12,675,9,12,1,12,1,12,5,
  	12,679,8,12,10,12,12,12,682,9,12,3,12,684,8,12,1,13,1,13,1,13,1,13,1,
  	13,0,1,10,14,0,2,4,6,8,10,12,14,16,18,20,22,24,26,0,4,1,0,13,14,1,0,15,
  	16,2,0,12,12,38,38,2,0,27,27,29,29,790,0,31,1,0,0,0,2,39,1,0,0,0,4,43,
  	1,0,0,0,6,115,1,0,0,0,8,120,1,0,0,0,10,192,1,0,0,0,12,232,1,0,0,0,14,
  	263,1,0,0,0,16,265,1,0,0,0,18,267,1,0,0,0,20,563,1,0,0,0,22,625,1,0,0,
  	0,24,683,1,0,0,0,26,685,1,0,0,0,28,32,3,12,6,0,29,32,3,10,5,0,30,32,3,
  	26,13,0,31,28,1,0,0,0,31,29,1,0,0,0,31,30,1,0,0,0,32,1,1,0,0,0,33,35,
  	3,4,2,0,34,33,1,0,0,0,35,36,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,40,
  	1,0,0,0,38,40,5,0,0,1,39,34,1,0,0,0,39,38,1,0,0,0,40,3,1,0,0,0,41,44,
  	3,12,6,0,42,44,3,10,5,0,43,41,1,0,0,0,43,42,1,0,0,0,44,5,1,0,0,0,45,47,
  	5,10,0,0,46,45,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,51,
  	1,0,0,0,50,48,1,0,0,0,51,55,5,1,0,0,52,54,5,10,0,0,53,52,1,0,0,0,54,57,
  	1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,58,1,0,0,0,57,55,1,0,0,0,58,116,
  	5,2,0,0,59,63,5,1,0,0,60,62,5,10,0,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,
  	1,0,0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,70,5,12,0,0,67,69,
  	5,10,0,0,68,67,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,73,
  	1,0,0,0,72,70,1,0,0,0,73,116,5,2,0,0,74,78,5,1,0,0,75,77,5,10,0,0,76,
  	75,1,0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,
  	78,1,0,0,0,81,85,5,12,0,0,82,84,5,10,0,0,83,82,1,0,0,0,84,87,1,0,0,0,
  	85,83,1,0,0,0,85,86,1,0,0,0,86,98,1,0,0,0,87,85,1,0,0,0,88,92,5,3,0,0,
  	89,91,5,10,0,0,90,89,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,
  	0,93,95,1,0,0,0,94,92,1,0,0,0,95,97,5,12,0,0,96,88,1,0,0,0,97,100,1,0,
  	0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,104,1,0,0,0,100,98,1,0,0,0,101,103,
  	5,10,0,0,102,101,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,0,104,105,1,0,
  	0,0,105,107,1,0,0,0,106,104,1,0,0,0,107,108,5,2,0,0,108,112,1,0,0,0,109,
  	111,5,10,0,0,110,109,1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,
  	1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,115,48,1,0,0,0,115,59,1,0,0,0,
  	115,74,1,0,0,0,116,7,1,0,0,0,117,119,5,10,0,0,118,117,1,0,0,0,119,122,
  	1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,161,1,0,0,0,122,120,1,0,0,
  	0,123,151,5,4,0,0,124,126,5,10,0,0,125,124,1,0,0,0,126,129,1,0,0,0,127,
  	125,1,0,0,0,127,128,1,0,0,0,128,130,1,0,0,0,129,127,1,0,0,0,130,131,5,
  	9,0,0,131,135,5,8,0,0,132,134,5,10,0,0,133,132,1,0,0,0,134,137,1,0,0,
  	0,135,133,1,0,0,0,135,136,1,0,0,0,136,152,1,0,0,0,137,135,1,0,0,0,138,
  	140,5,10,0,0,139,138,1,0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,
  	1,0,0,0,142,144,1,0,0,0,143,141,1,0,0,0,144,148,5,8,0,0,145,147,5,10,
  	0,0,146,145,1,0,0,0,147,150,1,0,0,0,148,146,1,0,0,0,148,149,1,0,0,0,149,
  	152,1,0,0,0,150,148,1,0,0,0,151,127,1,0,0,0,151,141,1,0,0,0,152,153,1,
  	0,0,0,153,155,5,2,0,0,154,156,3,6,3,0,155,154,1,0,0,0,155,156,1,0,0,0,
  	156,162,1,0,0,0,157,159,5,8,0,0,158,160,3,6,3,0,159,158,1,0,0,0,159,160,
  	1,0,0,0,160,162,1,0,0,0,161,123,1,0,0,0,161,157,1,0,0,0,162,166,1,0,0,
  	0,163,165,5,10,0,0,164,163,1,0,0,0,165,168,1,0,0,0,166,164,1,0,0,0,166,
  	167,1,0,0,0,167,9,1,0,0,0,168,166,1,0,0,0,169,170,6,5,-1,0,170,171,5,
  	1,0,0,171,172,3,10,5,0,172,173,5,2,0,0,173,193,1,0,0,0,174,193,3,8,4,
  	0,175,179,3,20,10,0,176,179,3,22,11,0,177,179,3,24,12,0,178,175,1,0,0,
  	0,178,176,1,0,0,0,178,177,1,0,0,0,179,193,1,0,0,0,180,183,3,16,8,0,181,
  	183,3,18,9,0,182,180,1,0,0,0,182,181,1,0,0,0,183,193,1,0,0,0,184,188,
  	7,0,0,0,185,187,5,10,0,0,186,185,1,0,0,0,187,190,1,0,0,0,188,186,1,0,
  	0,0,188,189,1,0,0,0,189,191,1,0,0,0,190,188,1,0,0,0,191,193,3,10,5,4,
  	192,169,1,0,0,0,192,174,1,0,0,0,192,178,1,0,0,0,192,182,1,0,0,0,192,184,
  	1,0,0,0,193,229,1,0,0,0,194,195,10,3,0,0,195,196,5,17,0,0,196,228,3,10,
  	5,4,197,201,10,2,0,0,198,200,5,10,0,0,199,198,1,0,0,0,200,203,1,0,0,0,
  	201,199,1,0,0,0,201,202,1,0,0,0,202,204,1,0,0,0,203,201,1,0,0,0,204,208,
  	7,1,0,0,205,207,5,10,0,0,206,205,1,0,0,0,207,210,1,0,0,0,208,206,1,0,
  	0,0,208,209,1,0,0,0,209,211,1,0,0,0,210,208,1,0,0,0,211,228,3,10,5,3,
  	212,216,10,1,0,0,213,215,5,10,0,0,214,213,1,0,0,0,215,218,1,0,0,0,216,
  	214,1,0,0,0,216,217,1,0,0,0,217,219,1,0,0,0,218,216,1,0,0,0,219,223,7,
  	0,0,0,220,222,5,10,0,0,221,220,1,0,0,0,222,225,1,0,0,0,223,221,1,0,0,
  	0,223,224,1,0,0,0,224,226,1,0,0,0,225,223,1,0,0,0,226,228,3,10,5,2,227,
  	194,1,0,0,0,227,197,1,0,0,0,227,212,1,0,0,0,228,231,1,0,0,0,229,227,1,
  	0,0,0,229,230,1,0,0,0,230,11,1,0,0,0,231,229,1,0,0,0,232,236,5,5,0,0,
  	233,235,5,10,0,0,234,233,1,0,0,0,235,238,1,0,0,0,236,234,1,0,0,0,236,
  	237,1,0,0,0,237,239,1,0,0,0,238,236,1,0,0,0,239,243,3,14,7,0,240,242,
  	5,10,0,0,241,240,1,0,0,0,242,245,1,0,0,0,243,241,1,0,0,0,243,244,1,0,
  	0,0,244,256,1,0,0,0,245,243,1,0,0,0,246,250,5,3,0,0,247,249,5,10,0,0,
  	248,247,1,0,0,0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,
  	1,0,0,0,252,250,1,0,0,0,253,255,3,14,7,0,254,246,1,0,0,0,255,258,1,0,
  	0,0,256,254,1,0,0,0,256,257,1,0,0,0,257,259,1,0,0,0,258,256,1,0,0,0,259,
  	260,5,6,0,0,260,13,1,0,0,0,261,264,3,12,6,0,262,264,3,10,5,0,263,261,
  	1,0,0,0,263,262,1,0,0,0,264,15,1,0,0,0,265,266,7,2,0,0,266,17,1,0,0,0,
  	267,268,7,3,0,0,268,19,1,0,0,0,269,271,5,10,0,0,270,269,1,0,0,0,271,274,
  	1,0,0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,275,1,0,0,0,274,272,1,0,0,
  	0,275,276,5,24,0,0,276,280,5,1,0,0,277,279,5,10,0,0,278,277,1,0,0,0,279,
  	282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,283,1,0,0,0,282,280,1,
  	0,0,0,283,287,3,10,5,0,284,286,5,10,0,0,285,284,1,0,0,0,286,289,1,0,0,
  	0,287,285,1,0,0,0,287,288,1,0,0,0,288,290,1,0,0,0,289,287,1,0,0,0,290,
  	294,5,2,0,0,291,293,5,10,0,0,292,291,1,0,0,0,293,296,1,0,0,0,294,292,
  	1,0,0,0,294,295,1,0,0,0,295,564,1,0,0,0,296,294,1,0,0,0,297,299,5,10,
  	0,0,298,297,1,0,0,0,299,302,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,
  	303,1,0,0,0,302,300,1,0,0,0,303,304,5,25,0,0,304,308,5,1,0,0,305,307,
  	5,10,0,0,306,305,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,
  	0,0,309,311,1,0,0,0,310,308,1,0,0,0,311,315,3,10,5,0,312,314,5,10,0,0,
  	313,312,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,0,316,318,
  	1,0,0,0,317,315,1,0,0,0,318,322,5,2,0,0,319,321,5,10,0,0,320,319,1,0,
  	0,0,321,324,1,0,0,0,322,320,1,0,0,0,322,323,1,0,0,0,323,564,1,0,0,0,324,
  	322,1,0,0,0,325,327,5,10,0,0,326,325,1,0,0,0,327,330,1,0,0,0,328,326,
  	1,0,0,0,328,329,1,0,0,0,329,331,1,0,0,0,330,328,1,0,0,0,331,332,5,27,
  	0,0,332,336,5,1,0,0,333,335,5,10,0,0,334,333,1,0,0,0,335,338,1,0,0,0,
  	336,334,1,0,0,0,336,337,1,0,0,0,337,339,1,0,0,0,338,336,1,0,0,0,339,343,
  	3,10,5,0,340,342,5,10,0,0,341,340,1,0,0,0,342,345,1,0,0,0,343,341,1,0,
  	0,0,343,344,1,0,0,0,344,346,1,0,0,0,345,343,1,0,0,0,346,350,5,2,0,0,347,
  	349,5,10,0,0,348,347,1,0,0,0,349,352,1,0,0,0,350,348,1,0,0,0,350,351,
  	1,0,0,0,351,564,1,0,0,0,352,350,1,0,0,0,353,355,5,10,0,0,354,353,1,0,
  	0,0,355,358,1,0,0,0,356,354,1,0,0,0,356,357,1,0,0,0,357,359,1,0,0,0,358,
  	356,1,0,0,0,359,360,5,28,0,0,360,364,5,1,0,0,361,363,5,10,0,0,362,361,
  	1,0,0,0,363,366,1,0,0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,367,1,0,0,
  	0,366,364,1,0,0,0,367,371,3,10,5,0,368,370,5,10,0,0,369,368,1,0,0,0,370,
  	373,1,0,0,0,371,369,1,0,0,0,371,372,1,0,0,0,372,374,1,0,0,0,373,371,1,
  	0,0,0,374,378,5,2,0,0,375,377,5,10,0,0,376,375,1,0,0,0,377,380,1,0,0,
  	0,378,376,1,0,0,0,378,379,1,0,0,0,379,564,1,0,0,0,380,378,1,0,0,0,381,
  	383,5,10,0,0,382,381,1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,
  	1,0,0,0,385,387,1,0,0,0,386,384,1,0,0,0,387,388,5,30,0,0,388,392,5,1,
  	0,0,389,391,5,10,0,0,390,389,1,0,0,0,391,394,1,0,0,0,392,390,1,0,0,0,
  	392,393,1,0,0,0,393,395,1,0,0,0,394,392,1,0,0,0,395,399,3,10,5,0,396,
  	398,5,10,0,0,397,396,1,0,0,0,398,401,1,0,0,0,399,397,1,0,0,0,399,400,
  	1,0,0,0,400,402,1,0,0,0,401,399,1,0,0,0,402,406,5,2,0,0,403,405,5,10,
  	0,0,404,403,1,0,0,0,405,408,1,0,0,0,406,404,1,0,0,0,406,407,1,0,0,0,407,
  	564,1,0,0,0,408,406,1,0,0,0,409,411,5,10,0,0,410,409,1,0,0,0,411,414,
  	1,0,0,0,412,410,1,0,0,0,412,413,1,0,0,0,413,415,1,0,0,0,414,412,1,0,0,
  	0,415,416,5,31,0,0,416,420,5,1,0,0,417,419,5,10,0,0,418,417,1,0,0,0,419,
  	422,1,0,0,0,420,418,1,0,0,0,420,421,1,0,0,0,421,423,1,0,0,0,422,420,1,
  	0,0,0,423,427,3,10,5,0,424,426,5,10,0,0,425,424,1,0,0,0,426,429,1,0,0,
  	0,427,425,1,0,0,0,427,428,1,0,0,0,428,430,1,0,0,0,429,427,1,0,0,0,430,
  	434,5,2,0,0,431,433,5,10,0,0,432,431,1,0,0,0,433,436,1,0,0,0,434,432,
  	1,0,0,0,434,435,1,0,0,0,435,564,1,0,0,0,436,434,1,0,0,0,437,439,5,10,
  	0,0,438,437,1,0,0,0,439,442,1,0,0,0,440,438,1,0,0,0,440,441,1,0,0,0,441,
  	443,1,0,0,0,442,440,1,0,0,0,443,444,5,33,0,0,444,448,5,1,0,0,445,447,
  	5,10,0,0,446,445,1,0,0,0,447,450,1,0,0,0,448,446,1,0,0,0,448,449,1,0,
  	0,0,449,451,1,0,0,0,450,448,1,0,0,0,451,455,3,10,5,0,452,454,5,10,0,0,
  	453,452,1,0,0,0,454,457,1,0,0,0,455,453,1,0,0,0,455,456,1,0,0,0,456,458,
  	1,0,0,0,457,455,1,0,0,0,458,462,5,2,0,0,459,461,5,10,0,0,460,459,1,0,
  	0,0,461,464,1,0,0,0,462,460,1,0,0,0,462,463,1,0,0,0,463,564,1,0,0,0,464,
  	462,1,0,0,0,465,467,5,10,0,0,466,465,1,0,0,0,467,470,1,0,0,0,468,466,
  	1,0,0,0,468,469,1,0,0,0,469,471,1,0,0,0,470,468,1,0,0,0,471,472,5,32,
  	0,0,472,476,5,1,0,0,473,475,5,10,0,0,474,473,1,0,0,0,475,478,1,0,0,0,
  	476,474,1,0,0,0,476,477,1,0,0,0,477,479,1,0,0,0,478,476,1,0,0,0,479,483,
  	3,10,5,0,480,482,5,10,0,0,481,480,1,0,0,0,482,485,1,0,0,0,483,481,1,0,
  	0,0,483,484,1,0,0,0,484,486,1,0,0,0,485,483,1,0,0,0,486,490,5,2,0,0,487,
  	489,5,10,0,0,488,487,1,0,0,0,489,492,1,0,0,0,490,488,1,0,0,0,490,491,
  	1,0,0,0,491,564,1,0,0,0,492,490,1,0,0,0,493,495,5,10,0,0,494,493,1,0,
  	0,0,495,498,1,0,0,0,496,494,1,0,0,0,496,497,1,0,0,0,497,499,1,0,0,0,498,
  	496,1,0,0,0,499,500,5,34,0,0,500,504,5,1,0,0,501,503,5,10,0,0,502,501,
  	1,0,0,0,503,506,1,0,0,0,504,502,1,0,0,0,504,505,1,0,0,0,505,507,1,0,0,
  	0,506,504,1,0,0,0,507,511,3,10,5,0,508,510,5,10,0,0,509,508,1,0,0,0,510,
  	513,1,0,0,0,511,509,1,0,0,0,511,512,1,0,0,0,512,514,1,0,0,0,513,511,1,
  	0,0,0,514,518,5,2,0,0,515,517,5,10,0,0,516,515,1,0,0,0,517,520,1,0,0,
  	0,518,516,1,0,0,0,518,519,1,0,0,0,519,564,1,0,0,0,520,518,1,0,0,0,521,
  	523,5,10,0,0,522,521,1,0,0,0,523,526,1,0,0,0,524,522,1,0,0,0,524,525,
  	1,0,0,0,525,527,1,0,0,0,526,524,1,0,0,0,527,528,5,26,0,0,528,532,5,1,
  	0,0,529,531,5,10,0,0,530,529,1,0,0,0,531,534,1,0,0,0,532,530,1,0,0,0,
  	532,533,1,0,0,0,533,535,1,0,0,0,534,532,1,0,0,0,535,539,3,10,5,0,536,
  	538,5,10,0,0,537,536,1,0,0,0,538,541,1,0,0,0,539,537,1,0,0,0,539,540,
  	1,0,0,0,540,542,1,0,0,0,541,539,1,0,0,0,542,546,5,3,0,0,543,545,5,10,
  	0,0,544,543,1,0,0,0,545,548,1,0,0,0,546,544,1,0,0,0,546,547,1,0,0,0,547,
  	549,1,0,0,0,548,546,1,0,0,0,549,553,3,10,5,0,550,552,5,10,0,0,551,550,
  	1,0,0,0,552,555,1,0,0,0,553,551,1,0,0,0,553,554,1,0,0,0,554,556,1,0,0,
  	0,555,553,1,0,0,0,556,560,5,2,0,0,557,559,5,10,0,0,558,557,1,0,0,0,559,
  	562,1,0,0,0,560,558,1,0,0,0,560,561,1,0,0,0,561,564,1,0,0,0,562,560,1,
  	0,0,0,563,272,1,0,0,0,563,300,1,0,0,0,563,328,1,0,0,0,563,356,1,0,0,0,
  	563,384,1,0,0,0,563,412,1,0,0,0,563,440,1,0,0,0,563,468,1,0,0,0,563,496,
  	1,0,0,0,563,524,1,0,0,0,564,21,1,0,0,0,565,567,5,10,0,0,566,565,1,0,0,
  	0,567,570,1,0,0,0,568,566,1,0,0,0,568,569,1,0,0,0,569,571,1,0,0,0,570,
  	568,1,0,0,0,571,572,5,18,0,0,572,573,5,1,0,0,573,574,3,10,5,0,574,575,
  	5,3,0,0,575,580,3,10,5,0,576,577,5,3,0,0,577,579,3,10,5,0,578,576,1,0,
  	0,0,579,582,1,0,0,0,580,578,1,0,0,0,580,581,1,0,0,0,581,583,1,0,0,0,582,
  	580,1,0,0,0,583,584,5,2,0,0,584,626,1,0,0,0,585,587,5,10,0,0,586,585,
  	1,0,0,0,587,590,1,0,0,0,588,586,1,0,0,0,588,589,1,0,0,0,589,591,1,0,0,
  	0,590,588,1,0,0,0,591,592,5,20,0,0,592,593,5,1,0,0,593,594,3,10,5,0,594,
  	595,5,3,0,0,595,600,3,10,5,0,596,597,5,3,0,0,597,599,3,10,5,0,598,596,
  	1,0,0,0,599,602,1,0,0,0,600,598,1,0,0,0,600,601,1,0,0,0,601,603,1,0,0,
  	0,602,600,1,0,0,0,603,604,5,2,0,0,604,626,1,0,0,0,605,607,5,10,0,0,606,
  	605,1,0,0,0,607,610,1,0,0,0,608,606,1,0,0,0,608,609,1,0,0,0,609,611,1,
  	0,0,0,610,608,1,0,0,0,611,612,5,22,0,0,612,613,5,1,0,0,613,614,3,10,5,
  	0,614,615,5,3,0,0,615,620,3,10,5,0,616,617,5,3,0,0,617,619,3,10,5,0,618,
  	616,1,0,0,0,619,622,1,0,0,0,620,618,1,0,0,0,620,621,1,0,0,0,621,623,1,
  	0,0,0,622,620,1,0,0,0,623,624,5,2,0,0,624,626,1,0,0,0,625,568,1,0,0,0,
  	625,588,1,0,0,0,625,608,1,0,0,0,626,23,1,0,0,0,627,629,5,10,0,0,628,627,
  	1,0,0,0,629,632,1,0,0,0,630,628,1,0,0,0,630,631,1,0,0,0,631,633,1,0,0,
  	0,632,630,1,0,0,0,633,634,5,21,0,0,634,638,5,1,0,0,635,637,5,10,0,0,636,
  	635,1,0,0,0,637,640,1,0,0,0,638,636,1,0,0,0,638,639,1,0,0,0,639,641,1,
  	0,0,0,640,638,1,0,0,0,641,645,3,10,5,0,642,644,5,10,0,0,643,642,1,0,0,
  	0,644,647,1,0,0,0,645,643,1,0,0,0,645,646,1,0,0,0,646,648,1,0,0,0,647,
  	645,1,0,0,0,648,652,5,2,0,0,649,651,5,10,0,0,650,649,1,0,0,0,651,654,
  	1,0,0,0,652,650,1,0,0,0,652,653,1,0,0,0,653,684,1,0,0,0,654,652,1,0,0,
  	0,655,657,5,10,0,0,656,655,1,0,0,0,657,660,1,0,0,0,658,656,1,0,0,0,658,
  	659,1,0,0,0,659,661,1,0,0,0,660,658,1,0,0,0,661,662,5,23,0,0,662,666,
  	5,1,0,0,663,665,5,10,0,0,664,663,1,0,0,0,665,668,1,0,0,0,666,664,1,0,
  	0,0,666,667,1,0,0,0,667,669,1,0,0,0,668,666,1,0,0,0,669,673,3,10,5,0,
  	670,672,5,10,0,0,671,670,1,0,0,0,672,675,1,0,0,0,673,671,1,0,0,0,673,
  	674,1,0,0,0,674,676,1,0,0,0,675,673,1,0,0,0,676,680,5,2,0,0,677,679,5,
  	10,0,0,678,677,1,0,0,0,679,682,1,0,0,0,680,678,1,0,0,0,680,681,1,0,0,
  	0,681,684,1,0,0,0,682,680,1,0,0,0,683,630,1,0,0,0,683,658,1,0,0,0,684,
  	25,1,0,0,0,685,686,5,7,0,0,686,687,5,40,0,0,687,688,5,7,0,0,688,27,1,
  	0,0,0,99,31,36,39,43,48,55,63,70,78,85,92,98,104,112,115,120,127,135,
  	141,148,151,155,159,161,166,178,182,188,192,201,208,216,223,227,229,236,
  	243,250,256,263,272,280,287,294,300,308,315,322,328,336,343,350,356,364,
  	371,378,384,392,399,406,412,420,427,434,440,448,455,462,468,476,483,490,
  	496,504,511,518,524,532,539,546,553,560,563,568,580,588,600,608,620,625,
  	630,638,645,652,658,666,673,680,683
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
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(28);
        array();
        break;
      }

      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
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
      case detect_type_functionParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(29);
        expr(0);
        break;
      }

      case detect_type_functionParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(30);
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

//----------------- InputContext ------------------------------------------------------------------

detect_type_functionParser::InputContext::InputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<detect_type_functionParser::Line_inputContext *> detect_type_functionParser::InputContext::line_input() {
  return getRuleContexts<detect_type_functionParser::Line_inputContext>();
}

detect_type_functionParser::Line_inputContext* detect_type_functionParser::InputContext::line_input(size_t i) {
  return getRuleContext<detect_type_functionParser::Line_inputContext>(i);
}

tree::TerminalNode* detect_type_functionParser::InputContext::EOF() {
  return getToken(detect_type_functionParser::EOF, 0);
}


size_t detect_type_functionParser::InputContext::getRuleIndex() const {
  return detect_type_functionParser::RuleInput;
}

void detect_type_functionParser::InputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInput(this);
}

void detect_type_functionParser::InputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInput(this);
}

detect_type_functionParser::InputContext* detect_type_functionParser::input() {
  InputContext *_localctx = _tracker.createInstance<InputContext>(_ctx, getState());
  enterRule(_localctx, 2, detect_type_functionParser::RuleInput);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::T__4:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
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
      case detect_type_functionParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(34); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(33);
          line_input();
          setState(36); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 309236888882) != 0));
        break;
      }

      case detect_type_functionParser::EOF: {
        enterOuterAlt(_localctx, 2);
        setState(38);
        match(detect_type_functionParser::EOF);
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
  enterRule(_localctx, 4, detect_type_functionParser::RuleLine_input);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(41);
        array();
        break;
      }

      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
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
      case detect_type_functionParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(42);
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
  enterRule(_localctx, 6, detect_type_functionParser::RuleNode_access);
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
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(45);
        match(detect_type_functionParser::WS);
        setState(50);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(51);
      match(detect_type_functionParser::T__0);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(52);
        match(detect_type_functionParser::WS);
        setState(57);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(58);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(59);
      match(detect_type_functionParser::T__0);
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(60);
        match(detect_type_functionParser::WS);
        setState(65);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(66);
      match(detect_type_functionParser::UINT);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(67);
        match(detect_type_functionParser::WS);
        setState(72);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(73);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      match(detect_type_functionParser::T__0);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(75);
        match(detect_type_functionParser::WS);
        setState(80);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(81);
      match(detect_type_functionParser::UINT);
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(82);
          match(detect_type_functionParser::WS); 
        }
        setState(87);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(88);
        match(detect_type_functionParser::T__2);
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
        match(detect_type_functionParser::UINT);
        setState(100);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(101);
        match(detect_type_functionParser::WS);
        setState(106);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(107);
      match(detect_type_functionParser::T__1);
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(109);
          match(detect_type_functionParser::WS); 
        }
        setState(114);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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
  enterRule(_localctx, 8, detect_type_functionParser::RuleVariable);
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
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(117);
      match(detect_type_functionParser::WS);
      setState(122);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3: {
        setState(123);
        match(detect_type_functionParser::T__3);
        setState(151);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(127);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(124);
            match(detect_type_functionParser::WS);
            setState(129);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(130);
          match(detect_type_functionParser::DATABASE);
          setState(131);
          match(detect_type_functionParser::VARIABLE);
          setState(135);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(132);
            match(detect_type_functionParser::WS);
            setState(137);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(141);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(138);
            match(detect_type_functionParser::WS);
            setState(143);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(144);
          match(detect_type_functionParser::VARIABLE);
          setState(148);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(145);
            match(detect_type_functionParser::WS);
            setState(150);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(153);
        match(detect_type_functionParser::T__1);
        setState(155);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(154);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case detect_type_functionParser::VARIABLE: {
        setState(157);
        match(detect_type_functionParser::VARIABLE);
        setState(159);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(158);
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
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(163);
        match(detect_type_functionParser::WS); 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, detect_type_functionParser::RuleExpr, precedence);

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
    setState(192);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(170);
      match(detect_type_functionParser::T__0);
      setState(171);
      expr(0);
      setState(172);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(174);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(178);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
      case 1: {
        setState(175);
        function();
        break;
      }

      case 2: {
        setState(176);
        multiargfunction();
        break;
      }

      case 3: {
        setState(177);
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
      setState(182);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_functionParser::UINT:
        case detect_type_functionParser::FLOAT: {
          setState(180);
          number();
          break;
        }

        case detect_type_functionParser::EXP:
        case detect_type_functionParser::PI: {
          setState(181);
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
      setState(184);
      _la = _input->LA(1);
      if (!(_la == detect_type_functionParser::ADD

      || _la == detect_type_functionParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(188);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(185);
          match(detect_type_functionParser::WS); 
        }
        setState(190);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      }
      setState(191);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(229);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(227);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(195);
          match(detect_type_functionParser::POW);
          setState(196);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(197);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(201);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(198);
            match(detect_type_functionParser::WS);
            setState(203);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(204);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::MUL

          || _la == detect_type_functionParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(208);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(205);
              match(detect_type_functionParser::WS); 
            }
            setState(210);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
          }
          setState(211);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(212);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(216);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(213);
            match(detect_type_functionParser::WS);
            setState(218);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(219);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::ADD

          || _la == detect_type_functionParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(223);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(220);
              match(detect_type_functionParser::WS); 
            }
            setState(225);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
          }
          setState(226);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(231);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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

std::vector<detect_type_functionParser::Input_arrayContext *> detect_type_functionParser::ArrayContext::input_array() {
  return getRuleContexts<detect_type_functionParser::Input_arrayContext>();
}

detect_type_functionParser::Input_arrayContext* detect_type_functionParser::ArrayContext::input_array(size_t i) {
  return getRuleContext<detect_type_functionParser::Input_arrayContext>(i);
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
  enterRule(_localctx, 12, detect_type_functionParser::RuleArray);
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
    setState(232);
    match(detect_type_functionParser::T__4);
    setState(236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(233);
        match(detect_type_functionParser::WS); 
      }
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(239);
    input_array();
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(240);
      match(detect_type_functionParser::WS);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(256);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::T__2) {
      setState(246);
      match(detect_type_functionParser::T__2);
      setState(250);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(247);
          match(detect_type_functionParser::WS); 
        }
        setState(252);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      }
      setState(253);
      input_array();
      setState(258);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(259);
    match(detect_type_functionParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Input_arrayContext ------------------------------------------------------------------

detect_type_functionParser::Input_arrayContext::Input_arrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t detect_type_functionParser::Input_arrayContext::getRuleIndex() const {
  return detect_type_functionParser::RuleInput_array;
}

void detect_type_functionParser::Input_arrayContext::copyFrom(Input_arrayContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemArrayContext ------------------------------------------------------------------

detect_type_functionParser::ArrayContext* detect_type_functionParser::ItemArrayContext::array() {
  return getRuleContext<detect_type_functionParser::ArrayContext>(0);
}

detect_type_functionParser::ExprContext* detect_type_functionParser::ItemArrayContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}

detect_type_functionParser::ItemArrayContext::ItemArrayContext(Input_arrayContext *ctx) { copyFrom(ctx); }

void detect_type_functionParser::ItemArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItemArray(this);
}
void detect_type_functionParser::ItemArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItemArray(this);
}
detect_type_functionParser::Input_arrayContext* detect_type_functionParser::input_array() {
  Input_arrayContext *_localctx = _tracker.createInstance<Input_arrayContext>(_ctx, getState());
  enterRule(_localctx, 14, detect_type_functionParser::RuleInput_array);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__4: {
        _localctx = _tracker.createInstance<detect_type_functionParser::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(261);
        array();
        break;
      }

      case detect_type_functionParser::T__0:
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS:
      case detect_type_functionParser::UINT:
      case detect_type_functionParser::ADD:
      case detect_type_functionParser::SUB:
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
      case detect_type_functionParser::FLOAT: {
        _localctx = _tracker.createInstance<detect_type_functionParser::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(262);
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
  enterRule(_localctx, 16, detect_type_functionParser::RuleNumber);
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
    setState(265);
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
  enterRule(_localctx, 18, detect_type_functionParser::RuleConstant);
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
    setState(267);
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
  enterRule(_localctx, 20, detect_type_functionParser::RuleFunction);
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
    setState(563);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(269);
        match(detect_type_functionParser::WS);
        setState(274);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(275);
      match(detect_type_functionParser::LN);
      setState(276);
      match(detect_type_functionParser::T__0);
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(277);
          match(detect_type_functionParser::WS); 
        }
        setState(282);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      }
      setState(283);
      expr(0);
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(284);
        match(detect_type_functionParser::WS);
        setState(289);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(290);
      match(detect_type_functionParser::T__1);
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(291);
          match(detect_type_functionParser::WS); 
        }
        setState(296);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(297);
        match(detect_type_functionParser::WS);
        setState(302);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(303);
      match(detect_type_functionParser::LG);
      setState(304);
      match(detect_type_functionParser::T__0);
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(305);
          match(detect_type_functionParser::WS); 
        }
        setState(310);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      }
      setState(311);
      expr(0);
      setState(315);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(312);
        match(detect_type_functionParser::WS);
        setState(317);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(318);
      match(detect_type_functionParser::T__1);
      setState(322);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(319);
          match(detect_type_functionParser::WS); 
        }
        setState(324);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(328);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(325);
        match(detect_type_functionParser::WS);
        setState(330);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(331);
      match(detect_type_functionParser::EXP);
      setState(332);
      match(detect_type_functionParser::T__0);
      setState(336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(333);
          match(detect_type_functionParser::WS); 
        }
        setState(338);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
      }
      setState(339);
      expr(0);
      setState(343);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(340);
        match(detect_type_functionParser::WS);
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(346);
      match(detect_type_functionParser::T__1);
      setState(350);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(347);
          match(detect_type_functionParser::WS); 
        }
        setState(352);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(353);
        match(detect_type_functionParser::WS);
        setState(358);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(359);
      match(detect_type_functionParser::SQRT);
      setState(360);
      match(detect_type_functionParser::T__0);
      setState(364);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(361);
          match(detect_type_functionParser::WS); 
        }
        setState(366);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
      }
      setState(367);
      expr(0);
      setState(371);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(368);
        match(detect_type_functionParser::WS);
        setState(373);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(374);
      match(detect_type_functionParser::T__1);
      setState(378);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(375);
          match(detect_type_functionParser::WS); 
        }
        setState(380);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(384);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(381);
        match(detect_type_functionParser::WS);
        setState(386);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(387);
      match(detect_type_functionParser::COS);
      setState(388);
      match(detect_type_functionParser::T__0);
      setState(392);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(389);
          match(detect_type_functionParser::WS); 
        }
        setState(394);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(395);
      expr(0);
      setState(399);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(396);
        match(detect_type_functionParser::WS);
        setState(401);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(402);
      match(detect_type_functionParser::T__1);
      setState(406);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(403);
          match(detect_type_functionParser::WS); 
        }
        setState(408);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(412);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(409);
        match(detect_type_functionParser::WS);
        setState(414);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(415);
      match(detect_type_functionParser::SIN);
      setState(416);
      match(detect_type_functionParser::T__0);
      setState(420);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(417);
          match(detect_type_functionParser::WS); 
        }
        setState(422);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      }
      setState(423);
      expr(0);
      setState(427);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(424);
        match(detect_type_functionParser::WS);
        setState(429);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(430);
      match(detect_type_functionParser::T__1);
      setState(434);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(431);
          match(detect_type_functionParser::WS); 
        }
        setState(436);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(440);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(437);
        match(detect_type_functionParser::WS);
        setState(442);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(443);
      match(detect_type_functionParser::ACOS);
      setState(444);
      match(detect_type_functionParser::T__0);
      setState(448);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(445);
          match(detect_type_functionParser::WS); 
        }
        setState(450);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      setState(451);
      expr(0);
      setState(455);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(452);
        match(detect_type_functionParser::WS);
        setState(457);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(458);
      match(detect_type_functionParser::T__1);
      setState(462);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(459);
          match(detect_type_functionParser::WS); 
        }
        setState(464);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(468);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(465);
        match(detect_type_functionParser::WS);
        setState(470);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(471);
      match(detect_type_functionParser::ASIN);
      setState(472);
      match(detect_type_functionParser::T__0);
      setState(476);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(473);
          match(detect_type_functionParser::WS); 
        }
        setState(478);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      }
      setState(479);
      expr(0);
      setState(483);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(480);
        match(detect_type_functionParser::WS);
        setState(485);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(486);
      match(detect_type_functionParser::T__1);
      setState(490);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(487);
          match(detect_type_functionParser::WS); 
        }
        setState(492);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(496);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(493);
        match(detect_type_functionParser::WS);
        setState(498);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(499);
      match(detect_type_functionParser::FACTORIAL);
      setState(500);
      match(detect_type_functionParser::T__0);
      setState(504);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(501);
          match(detect_type_functionParser::WS); 
        }
        setState(506);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      setState(507);
      expr(0);
      setState(511);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(508);
        match(detect_type_functionParser::WS);
        setState(513);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(514);
      match(detect_type_functionParser::T__1);
      setState(518);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(515);
          match(detect_type_functionParser::WS); 
        }
        setState(520);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(524);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(521);
        match(detect_type_functionParser::WS);
        setState(526);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(527);
      match(detect_type_functionParser::LOG_X);
      setState(528);
      match(detect_type_functionParser::T__0);
      setState(532);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(529);
          match(detect_type_functionParser::WS); 
        }
        setState(534);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      }
      setState(535);
      expr(0);
      setState(539);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(536);
        match(detect_type_functionParser::WS);
        setState(541);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(542);
      match(detect_type_functionParser::T__2);
      setState(546);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(543);
          match(detect_type_functionParser::WS); 
        }
        setState(548);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
      setState(549);
      expr(0);
      setState(553);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(550);
        match(detect_type_functionParser::WS);
        setState(555);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(556);
      match(detect_type_functionParser::T__1);
      setState(560);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(557);
          match(detect_type_functionParser::WS); 
        }
        setState(562);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
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
  enterRule(_localctx, 22, detect_type_functionParser::RuleMultiargfunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(625);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(568);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(565);
        match(detect_type_functionParser::WS);
        setState(570);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(571);
      match(detect_type_functionParser::SUMPRODUCT);
      setState(572);
      match(detect_type_functionParser::T__0);
      setState(573);
      expr(0);
      setState(574);
      match(detect_type_functionParser::T__2);
      setState(575);
      expr(0);
      setState(580);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(576);
        match(detect_type_functionParser::T__2);
        setState(577);
        expr(0);
        setState(582);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(583);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(588);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(585);
        match(detect_type_functionParser::WS);
        setState(590);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(591);
      match(detect_type_functionParser::SUM);
      setState(592);
      match(detect_type_functionParser::T__0);
      setState(593);
      expr(0);
      setState(594);
      match(detect_type_functionParser::T__2);
      setState(595);
      expr(0);
      setState(600);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(596);
        match(detect_type_functionParser::T__2);
        setState(597);
        expr(0);
        setState(602);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(603);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(608);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(605);
        match(detect_type_functionParser::WS);
        setState(610);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(611);
      match(detect_type_functionParser::PRODUCT);
      setState(612);
      match(detect_type_functionParser::T__0);
      setState(613);
      expr(0);
      setState(614);
      match(detect_type_functionParser::T__2);
      setState(615);
      expr(0);
      setState(620);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(616);
        match(detect_type_functionParser::T__2);
        setState(617);
        expr(0);
        setState(622);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(623);
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
  enterRule(_localctx, 24, detect_type_functionParser::RuleRangefunction);
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
    setState(683);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(630);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(627);
        match(detect_type_functionParser::WS);
        setState(632);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(633);
      match(detect_type_functionParser::SUM_I);
      setState(634);
      match(detect_type_functionParser::T__0);
      setState(638);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(635);
          match(detect_type_functionParser::WS); 
        }
        setState(640);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(641);
      expr(0);
      setState(645);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(642);
        match(detect_type_functionParser::WS);
        setState(647);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(648);
      match(detect_type_functionParser::T__1);
      setState(652);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(649);
          match(detect_type_functionParser::WS); 
        }
        setState(654);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(658);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(655);
        match(detect_type_functionParser::WS);
        setState(660);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(661);
      match(detect_type_functionParser::PRODUCT_I);
      setState(662);
      match(detect_type_functionParser::T__0);
      setState(666);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(663);
          match(detect_type_functionParser::WS); 
        }
        setState(668);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
      setState(669);
      expr(0);
      setState(673);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(670);
        match(detect_type_functionParser::WS);
        setState(675);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(676);
      match(detect_type_functionParser::T__1);
      setState(680);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(677);
          match(detect_type_functionParser::WS); 
        }
        setState(682);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
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
  enterRule(_localctx, 26, detect_type_functionParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(685);
    match(detect_type_functionParser::T__6);
    setState(686);
    match(detect_type_functionParser::STRING);
    setState(687);
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
    case 5: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
