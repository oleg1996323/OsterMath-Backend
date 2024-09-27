
// Generated from /home/oster/Electrolisys/grammar/detect_type_function.g4 by ANTLR 4.13.1


#include "detect_type_functionListener.h"

#include "detect_type_function.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Detect_type_functionStaticData final {
  Detect_type_functionStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Detect_type_functionStaticData(const Detect_type_functionStaticData&) = delete;
  Detect_type_functionStaticData(Detect_type_functionStaticData&&) = delete;
  Detect_type_functionStaticData& operator=(const Detect_type_functionStaticData&) = delete;
  Detect_type_functionStaticData& operator=(Detect_type_functionStaticData&&) = delete;

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
Detect_type_functionStaticData *detect_type_functionParserStaticData = nullptr;

void detect_type_functionParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (detect_type_functionParserStaticData != nullptr) {
    return;
  }
#else
  assert(detect_type_functionParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Detect_type_functionStaticData>(
    std::vector<std::string>{
      "line_input", "node_access", "variable", "expr", "array", "number", 
      "constant", "function", "multiargfunction", "rangefunction", "string"
    },
    std::vector<std::string>{
      "", "'VAR'", "'['", "']'", "'\"'", "", "", "'>'", "", "'='", "", "'<'", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "'('", "')'", "':'", "';'", "'+'", "'-'", "'*'", "'/'", 
      "'^'", "'''"
    },
    std::vector<std::string>{
      "", "VAR_TAG", "BEG_ARR", "END_ARR", "DOUBLE_QUOTE", "VARIABLE", "DATABASE", 
      "LARGER", "LARGER_EQUAL", "EQUAL", "LESS", "LESS_EQUAL", "SUMPRODUCT", 
      "SUMPRODUCT_I", "SUM", "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", 
      "LOG_X", "EXP", "SQRT", "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", 
      "STRING", "WS", "EOL", "UINT", "Lb", "Rb", "COL", "SEPAR", "ADD", 
      "SUB", "MUL", "DIV", "POW", "QUOTE", "ASTERISK", "EXPONENT", "FLOAT", 
      "ID_NUMBER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,46,694,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,5,0,24,8,0,10,0,12,0,27,9,0,1,0,1,
  	0,5,0,31,8,0,10,0,12,0,34,9,0,1,0,1,0,1,0,3,0,39,8,0,1,0,3,0,42,8,0,1,
  	0,3,0,45,8,0,1,1,5,1,48,8,1,10,1,12,1,51,9,1,1,1,1,1,5,1,55,8,1,10,1,
  	12,1,58,9,1,1,1,1,1,1,1,5,1,63,8,1,10,1,12,1,66,9,1,1,1,1,1,5,1,70,8,
  	1,10,1,12,1,73,9,1,1,1,1,1,1,1,5,1,78,8,1,10,1,12,1,81,9,1,1,1,1,1,5,
  	1,85,8,1,10,1,12,1,88,9,1,1,1,1,1,5,1,92,8,1,10,1,12,1,95,9,1,1,1,5,1,
  	98,8,1,10,1,12,1,101,9,1,1,1,5,1,104,8,1,10,1,12,1,107,9,1,1,1,1,1,1,
  	1,5,1,112,8,1,10,1,12,1,115,9,1,3,1,117,8,1,1,2,5,2,120,8,2,10,2,12,2,
  	123,9,2,1,2,1,2,1,2,5,2,128,8,2,10,2,12,2,131,9,2,1,2,1,2,1,2,5,2,136,
  	8,2,10,2,12,2,139,9,2,1,2,5,2,142,8,2,10,2,12,2,145,9,2,1,2,1,2,5,2,149,
  	8,2,10,2,12,2,152,9,2,3,2,154,8,2,1,2,1,2,3,2,158,8,2,1,2,1,2,3,2,162,
  	8,2,3,2,164,8,2,1,2,5,2,167,8,2,10,2,12,2,170,9,2,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,3,3,181,8,3,1,3,1,3,3,3,185,8,3,1,3,1,3,5,3,189,8,3,10,
  	3,12,3,192,9,3,1,3,3,3,195,8,3,1,3,1,3,1,3,1,3,1,3,5,3,202,8,3,10,3,12,
  	3,205,9,3,1,3,1,3,5,3,209,8,3,10,3,12,3,212,9,3,1,3,1,3,1,3,5,3,217,8,
  	3,10,3,12,3,220,9,3,1,3,1,3,5,3,224,8,3,10,3,12,3,227,9,3,1,3,5,3,230,
  	8,3,10,3,12,3,233,9,3,1,4,1,4,5,4,237,8,4,10,4,12,4,240,9,4,1,4,1,4,3,
  	4,244,8,4,1,4,5,4,247,8,4,10,4,12,4,250,9,4,1,4,1,4,5,4,254,8,4,10,4,
  	12,4,257,9,4,1,4,1,4,3,4,261,8,4,5,4,263,8,4,10,4,12,4,266,9,4,1,4,1,
  	4,1,5,1,5,1,6,1,6,1,7,5,7,275,8,7,10,7,12,7,278,9,7,1,7,1,7,1,7,5,7,283,
  	8,7,10,7,12,7,286,9,7,1,7,1,7,5,7,290,8,7,10,7,12,7,293,9,7,1,7,1,7,5,
  	7,297,8,7,10,7,12,7,300,9,7,1,7,5,7,303,8,7,10,7,12,7,306,9,7,1,7,1,7,
  	1,7,5,7,311,8,7,10,7,12,7,314,9,7,1,7,1,7,5,7,318,8,7,10,7,12,7,321,9,
  	7,1,7,1,7,5,7,325,8,7,10,7,12,7,328,9,7,1,7,5,7,331,8,7,10,7,12,7,334,
  	9,7,1,7,1,7,1,7,5,7,339,8,7,10,7,12,7,342,9,7,1,7,1,7,5,7,346,8,7,10,
  	7,12,7,349,9,7,1,7,1,7,5,7,353,8,7,10,7,12,7,356,9,7,1,7,5,7,359,8,7,
  	10,7,12,7,362,9,7,1,7,1,7,1,7,5,7,367,8,7,10,7,12,7,370,9,7,1,7,1,7,5,
  	7,374,8,7,10,7,12,7,377,9,7,1,7,1,7,5,7,381,8,7,10,7,12,7,384,9,7,1,7,
  	5,7,387,8,7,10,7,12,7,390,9,7,1,7,1,7,1,7,5,7,395,8,7,10,7,12,7,398,9,
  	7,1,7,1,7,5,7,402,8,7,10,7,12,7,405,9,7,1,7,1,7,5,7,409,8,7,10,7,12,7,
  	412,9,7,1,7,5,7,415,8,7,10,7,12,7,418,9,7,1,7,1,7,1,7,5,7,423,8,7,10,
  	7,12,7,426,9,7,1,7,1,7,5,7,430,8,7,10,7,12,7,433,9,7,1,7,1,7,5,7,437,
  	8,7,10,7,12,7,440,9,7,1,7,5,7,443,8,7,10,7,12,7,446,9,7,1,7,1,7,1,7,5,
  	7,451,8,7,10,7,12,7,454,9,7,1,7,1,7,5,7,458,8,7,10,7,12,7,461,9,7,1,7,
  	1,7,5,7,465,8,7,10,7,12,7,468,9,7,1,7,5,7,471,8,7,10,7,12,7,474,9,7,1,
  	7,1,7,1,7,5,7,479,8,7,10,7,12,7,482,9,7,1,7,1,7,5,7,486,8,7,10,7,12,7,
  	489,9,7,1,7,1,7,5,7,493,8,7,10,7,12,7,496,9,7,1,7,5,7,499,8,7,10,7,12,
  	7,502,9,7,1,7,1,7,1,7,5,7,507,8,7,10,7,12,7,510,9,7,1,7,1,7,5,7,514,8,
  	7,10,7,12,7,517,9,7,1,7,1,7,5,7,521,8,7,10,7,12,7,524,9,7,1,7,5,7,527,
  	8,7,10,7,12,7,530,9,7,1,7,1,7,1,7,5,7,535,8,7,10,7,12,7,538,9,7,1,7,1,
  	7,5,7,542,8,7,10,7,12,7,545,9,7,1,7,1,7,5,7,549,8,7,10,7,12,7,552,9,7,
  	1,7,1,7,5,7,556,8,7,10,7,12,7,559,9,7,1,7,1,7,5,7,563,8,7,10,7,12,7,566,
  	9,7,3,7,568,8,7,1,8,5,8,571,8,8,10,8,12,8,574,9,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,5,8,583,8,8,10,8,12,8,586,9,8,1,8,1,8,1,8,5,8,591,8,8,10,8,12,
  	8,594,9,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,603,8,8,10,8,12,8,606,9,8,1,
  	8,1,8,1,8,5,8,611,8,8,10,8,12,8,614,9,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,
  	8,623,8,8,10,8,12,8,626,9,8,1,8,1,8,3,8,630,8,8,1,9,5,9,633,8,9,10,9,
  	12,9,636,9,9,1,9,1,9,1,9,5,9,641,8,9,10,9,12,9,644,9,9,1,9,1,9,5,9,648,
  	8,9,10,9,12,9,651,9,9,1,9,1,9,5,9,655,8,9,10,9,12,9,658,9,9,1,9,5,9,661,
  	8,9,10,9,12,9,664,9,9,1,9,1,9,1,9,5,9,669,8,9,10,9,12,9,672,9,9,1,9,1,
  	9,5,9,676,8,9,10,9,12,9,679,9,9,1,9,1,9,5,9,683,8,9,10,9,12,9,686,9,9,
  	3,9,688,8,9,1,10,1,10,1,10,1,10,1,10,0,1,6,11,0,2,4,6,8,10,12,14,16,18,
  	20,0,4,1,0,37,38,1,0,39,40,2,0,32,32,45,45,2,0,21,21,23,23,799,0,44,1,
  	0,0,0,2,116,1,0,0,0,4,121,1,0,0,0,6,194,1,0,0,0,8,234,1,0,0,0,10,269,
  	1,0,0,0,12,271,1,0,0,0,14,567,1,0,0,0,16,629,1,0,0,0,18,687,1,0,0,0,20,
  	689,1,0,0,0,22,24,5,30,0,0,23,22,1,0,0,0,24,27,1,0,0,0,25,23,1,0,0,0,
  	25,26,1,0,0,0,26,28,1,0,0,0,27,25,1,0,0,0,28,32,5,9,0,0,29,31,5,30,0,
  	0,30,29,1,0,0,0,31,34,1,0,0,0,32,30,1,0,0,0,32,33,1,0,0,0,33,38,1,0,0,
  	0,34,32,1,0,0,0,35,39,3,8,4,0,36,39,3,6,3,0,37,39,3,20,10,0,38,35,1,0,
  	0,0,38,36,1,0,0,0,38,37,1,0,0,0,39,41,1,0,0,0,40,42,5,31,0,0,41,40,1,
  	0,0,0,41,42,1,0,0,0,42,45,1,0,0,0,43,45,5,31,0,0,44,25,1,0,0,0,44,43,
  	1,0,0,0,45,1,1,0,0,0,46,48,5,30,0,0,47,46,1,0,0,0,48,51,1,0,0,0,49,47,
  	1,0,0,0,49,50,1,0,0,0,50,52,1,0,0,0,51,49,1,0,0,0,52,56,5,33,0,0,53,55,
  	5,30,0,0,54,53,1,0,0,0,55,58,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,59,
  	1,0,0,0,58,56,1,0,0,0,59,117,5,34,0,0,60,64,5,33,0,0,61,63,5,30,0,0,62,
  	61,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,0,65,67,1,0,0,0,66,
  	64,1,0,0,0,67,71,5,32,0,0,68,70,5,30,0,0,69,68,1,0,0,0,70,73,1,0,0,0,
  	71,69,1,0,0,0,71,72,1,0,0,0,72,74,1,0,0,0,73,71,1,0,0,0,74,117,5,34,0,
  	0,75,79,5,33,0,0,76,78,5,30,0,0,77,76,1,0,0,0,78,81,1,0,0,0,79,77,1,0,
  	0,0,79,80,1,0,0,0,80,82,1,0,0,0,81,79,1,0,0,0,82,86,5,32,0,0,83,85,5,
  	30,0,0,84,83,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,99,
  	1,0,0,0,88,86,1,0,0,0,89,93,5,36,0,0,90,92,5,30,0,0,91,90,1,0,0,0,92,
  	95,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,96,1,0,0,0,95,93,1,0,0,0,96,
  	98,5,32,0,0,97,89,1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,
  	100,105,1,0,0,0,101,99,1,0,0,0,102,104,5,30,0,0,103,102,1,0,0,0,104,107,
  	1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,107,105,1,0,0,
  	0,108,109,5,34,0,0,109,113,1,0,0,0,110,112,5,30,0,0,111,110,1,0,0,0,112,
  	115,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,117,1,0,0,0,115,113,1,
  	0,0,0,116,49,1,0,0,0,116,60,1,0,0,0,116,75,1,0,0,0,117,3,1,0,0,0,118,
  	120,5,30,0,0,119,118,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,
  	1,0,0,0,122,163,1,0,0,0,123,121,1,0,0,0,124,125,5,1,0,0,125,153,5,33,
  	0,0,126,128,5,30,0,0,127,126,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,
  	129,130,1,0,0,0,130,132,1,0,0,0,131,129,1,0,0,0,132,133,5,6,0,0,133,137,
  	5,5,0,0,134,136,5,30,0,0,135,134,1,0,0,0,136,139,1,0,0,0,137,135,1,0,
  	0,0,137,138,1,0,0,0,138,154,1,0,0,0,139,137,1,0,0,0,140,142,5,30,0,0,
  	141,140,1,0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,146,
  	1,0,0,0,145,143,1,0,0,0,146,150,5,5,0,0,147,149,5,30,0,0,148,147,1,0,
  	0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,154,1,0,0,0,152,
  	150,1,0,0,0,153,129,1,0,0,0,153,143,1,0,0,0,154,155,1,0,0,0,155,157,5,
  	34,0,0,156,158,3,2,1,0,157,156,1,0,0,0,157,158,1,0,0,0,158,164,1,0,0,
  	0,159,161,5,5,0,0,160,162,3,2,1,0,161,160,1,0,0,0,161,162,1,0,0,0,162,
  	164,1,0,0,0,163,124,1,0,0,0,163,159,1,0,0,0,164,168,1,0,0,0,165,167,5,
  	30,0,0,166,165,1,0,0,0,167,170,1,0,0,0,168,166,1,0,0,0,168,169,1,0,0,
  	0,169,5,1,0,0,0,170,168,1,0,0,0,171,172,6,3,-1,0,172,173,5,33,0,0,173,
  	174,3,6,3,0,174,175,5,34,0,0,175,195,1,0,0,0,176,195,3,4,2,0,177,181,
  	3,14,7,0,178,181,3,16,8,0,179,181,3,18,9,0,180,177,1,0,0,0,180,178,1,
  	0,0,0,180,179,1,0,0,0,181,195,1,0,0,0,182,185,3,10,5,0,183,185,3,12,6,
  	0,184,182,1,0,0,0,184,183,1,0,0,0,185,195,1,0,0,0,186,190,7,0,0,0,187,
  	189,5,30,0,0,188,187,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,
  	1,0,0,0,191,193,1,0,0,0,192,190,1,0,0,0,193,195,3,6,3,4,194,171,1,0,0,
  	0,194,176,1,0,0,0,194,180,1,0,0,0,194,184,1,0,0,0,194,186,1,0,0,0,195,
  	231,1,0,0,0,196,197,10,3,0,0,197,198,5,41,0,0,198,230,3,6,3,4,199,203,
  	10,2,0,0,200,202,5,30,0,0,201,200,1,0,0,0,202,205,1,0,0,0,203,201,1,0,
  	0,0,203,204,1,0,0,0,204,206,1,0,0,0,205,203,1,0,0,0,206,210,7,1,0,0,207,
  	209,5,30,0,0,208,207,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,
  	1,0,0,0,211,213,1,0,0,0,212,210,1,0,0,0,213,230,3,6,3,3,214,218,10,1,
  	0,0,215,217,5,30,0,0,216,215,1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,0,
  	218,219,1,0,0,0,219,221,1,0,0,0,220,218,1,0,0,0,221,225,7,0,0,0,222,224,
  	5,30,0,0,223,222,1,0,0,0,224,227,1,0,0,0,225,223,1,0,0,0,225,226,1,0,
  	0,0,226,228,1,0,0,0,227,225,1,0,0,0,228,230,3,6,3,2,229,196,1,0,0,0,229,
  	199,1,0,0,0,229,214,1,0,0,0,230,233,1,0,0,0,231,229,1,0,0,0,231,232,1,
  	0,0,0,232,7,1,0,0,0,233,231,1,0,0,0,234,238,5,2,0,0,235,237,5,30,0,0,
  	236,235,1,0,0,0,237,240,1,0,0,0,238,236,1,0,0,0,238,239,1,0,0,0,239,243,
  	1,0,0,0,240,238,1,0,0,0,241,244,3,6,3,0,242,244,3,8,4,0,243,241,1,0,0,
  	0,243,242,1,0,0,0,244,248,1,0,0,0,245,247,5,30,0,0,246,245,1,0,0,0,247,
  	250,1,0,0,0,248,246,1,0,0,0,248,249,1,0,0,0,249,264,1,0,0,0,250,248,1,
  	0,0,0,251,255,5,36,0,0,252,254,5,30,0,0,253,252,1,0,0,0,254,257,1,0,0,
  	0,255,253,1,0,0,0,255,256,1,0,0,0,256,260,1,0,0,0,257,255,1,0,0,0,258,
  	261,3,6,3,0,259,261,3,8,4,0,260,258,1,0,0,0,260,259,1,0,0,0,261,263,1,
  	0,0,0,262,251,1,0,0,0,263,266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,
  	265,267,1,0,0,0,266,264,1,0,0,0,267,268,5,3,0,0,268,9,1,0,0,0,269,270,
  	7,2,0,0,270,11,1,0,0,0,271,272,7,3,0,0,272,13,1,0,0,0,273,275,5,30,0,
  	0,274,273,1,0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,276,277,1,0,0,0,277,
  	279,1,0,0,0,278,276,1,0,0,0,279,280,5,18,0,0,280,284,5,33,0,0,281,283,
  	5,30,0,0,282,281,1,0,0,0,283,286,1,0,0,0,284,282,1,0,0,0,284,285,1,0,
  	0,0,285,287,1,0,0,0,286,284,1,0,0,0,287,291,3,6,3,0,288,290,5,30,0,0,
  	289,288,1,0,0,0,290,293,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,294,
  	1,0,0,0,293,291,1,0,0,0,294,298,5,34,0,0,295,297,5,30,0,0,296,295,1,0,
  	0,0,297,300,1,0,0,0,298,296,1,0,0,0,298,299,1,0,0,0,299,568,1,0,0,0,300,
  	298,1,0,0,0,301,303,5,30,0,0,302,301,1,0,0,0,303,306,1,0,0,0,304,302,
  	1,0,0,0,304,305,1,0,0,0,305,307,1,0,0,0,306,304,1,0,0,0,307,308,5,19,
  	0,0,308,312,5,33,0,0,309,311,5,30,0,0,310,309,1,0,0,0,311,314,1,0,0,0,
  	312,310,1,0,0,0,312,313,1,0,0,0,313,315,1,0,0,0,314,312,1,0,0,0,315,319,
  	3,6,3,0,316,318,5,30,0,0,317,316,1,0,0,0,318,321,1,0,0,0,319,317,1,0,
  	0,0,319,320,1,0,0,0,320,322,1,0,0,0,321,319,1,0,0,0,322,326,5,34,0,0,
  	323,325,5,30,0,0,324,323,1,0,0,0,325,328,1,0,0,0,326,324,1,0,0,0,326,
  	327,1,0,0,0,327,568,1,0,0,0,328,326,1,0,0,0,329,331,5,30,0,0,330,329,
  	1,0,0,0,331,334,1,0,0,0,332,330,1,0,0,0,332,333,1,0,0,0,333,335,1,0,0,
  	0,334,332,1,0,0,0,335,336,5,21,0,0,336,340,5,33,0,0,337,339,5,30,0,0,
  	338,337,1,0,0,0,339,342,1,0,0,0,340,338,1,0,0,0,340,341,1,0,0,0,341,343,
  	1,0,0,0,342,340,1,0,0,0,343,347,3,6,3,0,344,346,5,30,0,0,345,344,1,0,
  	0,0,346,349,1,0,0,0,347,345,1,0,0,0,347,348,1,0,0,0,348,350,1,0,0,0,349,
  	347,1,0,0,0,350,354,5,34,0,0,351,353,5,30,0,0,352,351,1,0,0,0,353,356,
  	1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,0,355,568,1,0,0,0,356,354,1,0,0,
  	0,357,359,5,30,0,0,358,357,1,0,0,0,359,362,1,0,0,0,360,358,1,0,0,0,360,
  	361,1,0,0,0,361,363,1,0,0,0,362,360,1,0,0,0,363,364,5,22,0,0,364,368,
  	5,33,0,0,365,367,5,30,0,0,366,365,1,0,0,0,367,370,1,0,0,0,368,366,1,0,
  	0,0,368,369,1,0,0,0,369,371,1,0,0,0,370,368,1,0,0,0,371,375,3,6,3,0,372,
  	374,5,30,0,0,373,372,1,0,0,0,374,377,1,0,0,0,375,373,1,0,0,0,375,376,
  	1,0,0,0,376,378,1,0,0,0,377,375,1,0,0,0,378,382,5,34,0,0,379,381,5,30,
  	0,0,380,379,1,0,0,0,381,384,1,0,0,0,382,380,1,0,0,0,382,383,1,0,0,0,383,
  	568,1,0,0,0,384,382,1,0,0,0,385,387,5,30,0,0,386,385,1,0,0,0,387,390,
  	1,0,0,0,388,386,1,0,0,0,388,389,1,0,0,0,389,391,1,0,0,0,390,388,1,0,0,
  	0,391,392,5,24,0,0,392,396,5,33,0,0,393,395,5,30,0,0,394,393,1,0,0,0,
  	395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,399,1,0,0,0,398,396,
  	1,0,0,0,399,403,3,6,3,0,400,402,5,30,0,0,401,400,1,0,0,0,402,405,1,0,
  	0,0,403,401,1,0,0,0,403,404,1,0,0,0,404,406,1,0,0,0,405,403,1,0,0,0,406,
  	410,5,34,0,0,407,409,5,30,0,0,408,407,1,0,0,0,409,412,1,0,0,0,410,408,
  	1,0,0,0,410,411,1,0,0,0,411,568,1,0,0,0,412,410,1,0,0,0,413,415,5,30,
  	0,0,414,413,1,0,0,0,415,418,1,0,0,0,416,414,1,0,0,0,416,417,1,0,0,0,417,
  	419,1,0,0,0,418,416,1,0,0,0,419,420,5,25,0,0,420,424,5,33,0,0,421,423,
  	5,30,0,0,422,421,1,0,0,0,423,426,1,0,0,0,424,422,1,0,0,0,424,425,1,0,
  	0,0,425,427,1,0,0,0,426,424,1,0,0,0,427,431,3,6,3,0,428,430,5,30,0,0,
  	429,428,1,0,0,0,430,433,1,0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,434,
  	1,0,0,0,433,431,1,0,0,0,434,438,5,34,0,0,435,437,5,30,0,0,436,435,1,0,
  	0,0,437,440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,0,0,439,568,1,0,0,0,440,
  	438,1,0,0,0,441,443,5,30,0,0,442,441,1,0,0,0,443,446,1,0,0,0,444,442,
  	1,0,0,0,444,445,1,0,0,0,445,447,1,0,0,0,446,444,1,0,0,0,447,448,5,27,
  	0,0,448,452,5,33,0,0,449,451,5,30,0,0,450,449,1,0,0,0,451,454,1,0,0,0,
  	452,450,1,0,0,0,452,453,1,0,0,0,453,455,1,0,0,0,454,452,1,0,0,0,455,459,
  	3,6,3,0,456,458,5,30,0,0,457,456,1,0,0,0,458,461,1,0,0,0,459,457,1,0,
  	0,0,459,460,1,0,0,0,460,462,1,0,0,0,461,459,1,0,0,0,462,466,5,34,0,0,
  	463,465,5,30,0,0,464,463,1,0,0,0,465,468,1,0,0,0,466,464,1,0,0,0,466,
  	467,1,0,0,0,467,568,1,0,0,0,468,466,1,0,0,0,469,471,5,30,0,0,470,469,
  	1,0,0,0,471,474,1,0,0,0,472,470,1,0,0,0,472,473,1,0,0,0,473,475,1,0,0,
  	0,474,472,1,0,0,0,475,476,5,26,0,0,476,480,5,33,0,0,477,479,5,30,0,0,
  	478,477,1,0,0,0,479,482,1,0,0,0,480,478,1,0,0,0,480,481,1,0,0,0,481,483,
  	1,0,0,0,482,480,1,0,0,0,483,487,3,6,3,0,484,486,5,30,0,0,485,484,1,0,
  	0,0,486,489,1,0,0,0,487,485,1,0,0,0,487,488,1,0,0,0,488,490,1,0,0,0,489,
  	487,1,0,0,0,490,494,5,34,0,0,491,493,5,30,0,0,492,491,1,0,0,0,493,496,
  	1,0,0,0,494,492,1,0,0,0,494,495,1,0,0,0,495,568,1,0,0,0,496,494,1,0,0,
  	0,497,499,5,30,0,0,498,497,1,0,0,0,499,502,1,0,0,0,500,498,1,0,0,0,500,
  	501,1,0,0,0,501,503,1,0,0,0,502,500,1,0,0,0,503,504,5,28,0,0,504,508,
  	5,33,0,0,505,507,5,30,0,0,506,505,1,0,0,0,507,510,1,0,0,0,508,506,1,0,
  	0,0,508,509,1,0,0,0,509,511,1,0,0,0,510,508,1,0,0,0,511,515,3,6,3,0,512,
  	514,5,30,0,0,513,512,1,0,0,0,514,517,1,0,0,0,515,513,1,0,0,0,515,516,
  	1,0,0,0,516,518,1,0,0,0,517,515,1,0,0,0,518,522,5,34,0,0,519,521,5,30,
  	0,0,520,519,1,0,0,0,521,524,1,0,0,0,522,520,1,0,0,0,522,523,1,0,0,0,523,
  	568,1,0,0,0,524,522,1,0,0,0,525,527,5,30,0,0,526,525,1,0,0,0,527,530,
  	1,0,0,0,528,526,1,0,0,0,528,529,1,0,0,0,529,531,1,0,0,0,530,528,1,0,0,
  	0,531,532,5,20,0,0,532,536,5,33,0,0,533,535,5,30,0,0,534,533,1,0,0,0,
  	535,538,1,0,0,0,536,534,1,0,0,0,536,537,1,0,0,0,537,539,1,0,0,0,538,536,
  	1,0,0,0,539,543,3,6,3,0,540,542,5,30,0,0,541,540,1,0,0,0,542,545,1,0,
  	0,0,543,541,1,0,0,0,543,544,1,0,0,0,544,546,1,0,0,0,545,543,1,0,0,0,546,
  	550,5,36,0,0,547,549,5,30,0,0,548,547,1,0,0,0,549,552,1,0,0,0,550,548,
  	1,0,0,0,550,551,1,0,0,0,551,553,1,0,0,0,552,550,1,0,0,0,553,557,3,6,3,
  	0,554,556,5,30,0,0,555,554,1,0,0,0,556,559,1,0,0,0,557,555,1,0,0,0,557,
  	558,1,0,0,0,558,560,1,0,0,0,559,557,1,0,0,0,560,564,5,34,0,0,561,563,
  	5,30,0,0,562,561,1,0,0,0,563,566,1,0,0,0,564,562,1,0,0,0,564,565,1,0,
  	0,0,565,568,1,0,0,0,566,564,1,0,0,0,567,276,1,0,0,0,567,304,1,0,0,0,567,
  	332,1,0,0,0,567,360,1,0,0,0,567,388,1,0,0,0,567,416,1,0,0,0,567,444,1,
  	0,0,0,567,472,1,0,0,0,567,500,1,0,0,0,567,528,1,0,0,0,568,15,1,0,0,0,
  	569,571,5,30,0,0,570,569,1,0,0,0,571,574,1,0,0,0,572,570,1,0,0,0,572,
  	573,1,0,0,0,573,575,1,0,0,0,574,572,1,0,0,0,575,576,5,12,0,0,576,577,
  	5,33,0,0,577,578,3,6,3,0,578,579,5,36,0,0,579,584,3,6,3,0,580,581,5,36,
  	0,0,581,583,3,6,3,0,582,580,1,0,0,0,583,586,1,0,0,0,584,582,1,0,0,0,584,
  	585,1,0,0,0,585,587,1,0,0,0,586,584,1,0,0,0,587,588,5,34,0,0,588,630,
  	1,0,0,0,589,591,5,30,0,0,590,589,1,0,0,0,591,594,1,0,0,0,592,590,1,0,
  	0,0,592,593,1,0,0,0,593,595,1,0,0,0,594,592,1,0,0,0,595,596,5,14,0,0,
  	596,597,5,33,0,0,597,598,3,6,3,0,598,599,5,36,0,0,599,604,3,6,3,0,600,
  	601,5,36,0,0,601,603,3,6,3,0,602,600,1,0,0,0,603,606,1,0,0,0,604,602,
  	1,0,0,0,604,605,1,0,0,0,605,607,1,0,0,0,606,604,1,0,0,0,607,608,5,34,
  	0,0,608,630,1,0,0,0,609,611,5,30,0,0,610,609,1,0,0,0,611,614,1,0,0,0,
  	612,610,1,0,0,0,612,613,1,0,0,0,613,615,1,0,0,0,614,612,1,0,0,0,615,616,
  	5,16,0,0,616,617,5,33,0,0,617,618,3,6,3,0,618,619,5,36,0,0,619,624,3,
  	6,3,0,620,621,5,36,0,0,621,623,3,6,3,0,622,620,1,0,0,0,623,626,1,0,0,
  	0,624,622,1,0,0,0,624,625,1,0,0,0,625,627,1,0,0,0,626,624,1,0,0,0,627,
  	628,5,34,0,0,628,630,1,0,0,0,629,572,1,0,0,0,629,592,1,0,0,0,629,612,
  	1,0,0,0,630,17,1,0,0,0,631,633,5,30,0,0,632,631,1,0,0,0,633,636,1,0,0,
  	0,634,632,1,0,0,0,634,635,1,0,0,0,635,637,1,0,0,0,636,634,1,0,0,0,637,
  	638,5,15,0,0,638,642,5,33,0,0,639,641,5,30,0,0,640,639,1,0,0,0,641,644,
  	1,0,0,0,642,640,1,0,0,0,642,643,1,0,0,0,643,645,1,0,0,0,644,642,1,0,0,
  	0,645,649,3,6,3,0,646,648,5,30,0,0,647,646,1,0,0,0,648,651,1,0,0,0,649,
  	647,1,0,0,0,649,650,1,0,0,0,650,652,1,0,0,0,651,649,1,0,0,0,652,656,5,
  	34,0,0,653,655,5,30,0,0,654,653,1,0,0,0,655,658,1,0,0,0,656,654,1,0,0,
  	0,656,657,1,0,0,0,657,688,1,0,0,0,658,656,1,0,0,0,659,661,5,30,0,0,660,
  	659,1,0,0,0,661,664,1,0,0,0,662,660,1,0,0,0,662,663,1,0,0,0,663,665,1,
  	0,0,0,664,662,1,0,0,0,665,666,5,17,0,0,666,670,5,33,0,0,667,669,5,30,
  	0,0,668,667,1,0,0,0,669,672,1,0,0,0,670,668,1,0,0,0,670,671,1,0,0,0,671,
  	673,1,0,0,0,672,670,1,0,0,0,673,677,3,6,3,0,674,676,5,30,0,0,675,674,
  	1,0,0,0,676,679,1,0,0,0,677,675,1,0,0,0,677,678,1,0,0,0,678,680,1,0,0,
  	0,679,677,1,0,0,0,680,684,5,34,0,0,681,683,5,30,0,0,682,681,1,0,0,0,683,
  	686,1,0,0,0,684,682,1,0,0,0,684,685,1,0,0,0,685,688,1,0,0,0,686,684,1,
  	0,0,0,687,634,1,0,0,0,687,662,1,0,0,0,688,19,1,0,0,0,689,690,5,4,0,0,
  	690,691,5,29,0,0,691,692,5,4,0,0,692,21,1,0,0,0,101,25,32,38,41,44,49,
  	56,64,71,79,86,93,99,105,113,116,121,129,137,143,150,153,157,161,163,
  	168,180,184,190,194,203,210,218,225,229,231,238,243,248,255,260,264,276,
  	284,291,298,304,312,319,326,332,340,347,354,360,368,375,382,388,396,403,
  	410,416,424,431,438,444,452,459,466,472,480,487,494,500,508,515,522,528,
  	536,543,550,557,564,567,572,584,592,604,612,624,629,634,642,649,656,662,
  	670,677,684,687
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

detect_type_function::detect_type_function(TokenStream *input) : detect_type_function(input, antlr4::atn::ParserATNSimulatorOptions()) {}

detect_type_function::detect_type_function(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  detect_type_function::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *detect_type_functionParserStaticData->atn, detect_type_functionParserStaticData->decisionToDFA, detect_type_functionParserStaticData->sharedContextCache, options);
}

detect_type_function::~detect_type_function() {
  delete _interpreter;
}

const atn::ATN& detect_type_function::getATN() const {
  return *detect_type_functionParserStaticData->atn;
}

std::string detect_type_function::getGrammarFileName() const {
  return "detect_type_function.g4";
}

const std::vector<std::string>& detect_type_function::getRuleNames() const {
  return detect_type_functionParserStaticData->ruleNames;
}

const dfa::Vocabulary& detect_type_function::getVocabulary() const {
  return detect_type_functionParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView detect_type_function::getSerializedATN() const {
  return detect_type_functionParserStaticData->serializedATN;
}


//----------------- Line_inputContext ------------------------------------------------------------------

detect_type_function::Line_inputContext::Line_inputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::Line_inputContext::EQUAL() {
  return getToken(detect_type_function::EQUAL, 0);
}

detect_type_function::ArrayContext* detect_type_function::Line_inputContext::array() {
  return getRuleContext<detect_type_function::ArrayContext>(0);
}

detect_type_function::ExprContext* detect_type_function::Line_inputContext::expr() {
  return getRuleContext<detect_type_function::ExprContext>(0);
}

detect_type_function::StringContext* detect_type_function::Line_inputContext::string() {
  return getRuleContext<detect_type_function::StringContext>(0);
}

std::vector<tree::TerminalNode *> detect_type_function::Line_inputContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::Line_inputContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::Line_inputContext::EOL() {
  return getToken(detect_type_function::EOL, 0);
}


size_t detect_type_function::Line_inputContext::getRuleIndex() const {
  return detect_type_function::RuleLine_input;
}

void detect_type_function::Line_inputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine_input(this);
}

void detect_type_function::Line_inputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine_input(this);
}

detect_type_function::Line_inputContext* detect_type_function::line_input() {
  Line_inputContext *_localctx = _tracker.createInstance<Line_inputContext>(_ctx, getState());
  enterRule(_localctx, 0, detect_type_function::RuleLine_input);
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
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_function::EQUAL:
      case detect_type_function::WS: {
        enterOuterAlt(_localctx, 1);
        setState(25);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == detect_type_function::WS) {
          setState(22);
          match(detect_type_function::WS);
          setState(27);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(28);
        match(detect_type_function::EQUAL);
        setState(32);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(29);
            match(detect_type_function::WS); 
          }
          setState(34);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        }
        setState(38);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case detect_type_function::BEG_ARR: {
            setState(35);
            array();
            break;
          }

          case detect_type_function::VAR_TAG:
          case detect_type_function::VARIABLE:
          case detect_type_function::SUMPRODUCT:
          case detect_type_function::SUM:
          case detect_type_function::SUM_I:
          case detect_type_function::PRODUCT:
          case detect_type_function::PRODUCT_I:
          case detect_type_function::LN:
          case detect_type_function::LG:
          case detect_type_function::LOG_X:
          case detect_type_function::EXP:
          case detect_type_function::SQRT:
          case detect_type_function::PI:
          case detect_type_function::COS:
          case detect_type_function::SIN:
          case detect_type_function::ASIN:
          case detect_type_function::ACOS:
          case detect_type_function::FACTORIAL:
          case detect_type_function::WS:
          case detect_type_function::UINT:
          case detect_type_function::Lb:
          case detect_type_function::ADD:
          case detect_type_function::SUB:
          case detect_type_function::FLOAT: {
            setState(36);
            expr(0);
            break;
          }

          case detect_type_function::DOUBLE_QUOTE: {
            setState(37);
            string();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(41);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == detect_type_function::EOL) {
          setState(40);
          match(detect_type_function::EOL);
        }
        break;
      }

      case detect_type_function::EOL: {
        enterOuterAlt(_localctx, 2);
        setState(43);
        match(detect_type_function::EOL);
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

detect_type_function::Node_accessContext::Node_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::Node_accessContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

tree::TerminalNode* detect_type_function::Node_accessContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::Node_accessContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::Node_accessContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

std::vector<tree::TerminalNode *> detect_type_function::Node_accessContext::UINT() {
  return getTokens(detect_type_function::UINT);
}

tree::TerminalNode* detect_type_function::Node_accessContext::UINT(size_t i) {
  return getToken(detect_type_function::UINT, i);
}

std::vector<tree::TerminalNode *> detect_type_function::Node_accessContext::SEPAR() {
  return getTokens(detect_type_function::SEPAR);
}

tree::TerminalNode* detect_type_function::Node_accessContext::SEPAR(size_t i) {
  return getToken(detect_type_function::SEPAR, i);
}


size_t detect_type_function::Node_accessContext::getRuleIndex() const {
  return detect_type_function::RuleNode_access;
}

void detect_type_function::Node_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_access(this);
}

void detect_type_function::Node_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_access(this);
}

detect_type_function::Node_accessContext* detect_type_function::node_access() {
  Node_accessContext *_localctx = _tracker.createInstance<Node_accessContext>(_ctx, getState());
  enterRule(_localctx, 2, detect_type_function::RuleNode_access);
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
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(46);
        match(detect_type_function::WS);
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(52);
      match(detect_type_function::Lb);
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(53);
        match(detect_type_function::WS);
        setState(58);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(59);
      match(detect_type_function::Rb);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      match(detect_type_function::Lb);
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(61);
        match(detect_type_function::WS);
        setState(66);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(67);
      match(detect_type_function::UINT);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(68);
        match(detect_type_function::WS);
        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(74);
      match(detect_type_function::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(75);
      match(detect_type_function::Lb);
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(76);
        match(detect_type_function::WS);
        setState(81);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(82);
      match(detect_type_function::UINT);
      setState(86);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(83);
          match(detect_type_function::WS); 
        }
        setState(88);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::SEPAR) {
        setState(89);
        match(detect_type_function::SEPAR);
        setState(93);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == detect_type_function::WS) {
          setState(90);
          match(detect_type_function::WS);
          setState(95);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(96);
        match(detect_type_function::UINT);
        setState(101);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(102);
        match(detect_type_function::WS);
        setState(107);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(108);
      match(detect_type_function::Rb);
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(110);
          match(detect_type_function::WS); 
        }
        setState(115);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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

detect_type_function::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> detect_type_function::VariableContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::VariableContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::VariableContext::VAR_TAG() {
  return getToken(detect_type_function::VAR_TAG, 0);
}

tree::TerminalNode* detect_type_function::VariableContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

tree::TerminalNode* detect_type_function::VariableContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

tree::TerminalNode* detect_type_function::VariableContext::VARIABLE() {
  return getToken(detect_type_function::VARIABLE, 0);
}

tree::TerminalNode* detect_type_function::VariableContext::DATABASE() {
  return getToken(detect_type_function::DATABASE, 0);
}

detect_type_function::Node_accessContext* detect_type_function::VariableContext::node_access() {
  return getRuleContext<detect_type_function::Node_accessContext>(0);
}


size_t detect_type_function::VariableContext::getRuleIndex() const {
  return detect_type_function::RuleVariable;
}

void detect_type_function::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void detect_type_function::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

detect_type_function::VariableContext* detect_type_function::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 4, detect_type_function::RuleVariable);
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
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_function::WS) {
      setState(118);
      match(detect_type_function::WS);
      setState(123);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_function::VAR_TAG: {
        setState(124);
        match(detect_type_function::VAR_TAG);
        setState(125);
        match(detect_type_function::Lb);
        setState(153);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(129);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(126);
            match(detect_type_function::WS);
            setState(131);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(132);
          match(detect_type_function::DATABASE);
          setState(133);
          match(detect_type_function::VARIABLE);
          setState(137);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(134);
            match(detect_type_function::WS);
            setState(139);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(143);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(140);
            match(detect_type_function::WS);
            setState(145);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(146);
          match(detect_type_function::VARIABLE);
          setState(150);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(147);
            match(detect_type_function::WS);
            setState(152);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(155);
        match(detect_type_function::Rb);
        setState(157);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(156);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case detect_type_function::VARIABLE: {
        setState(159);
        match(detect_type_function::VARIABLE);
        setState(161);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          setState(160);
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
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(165);
        match(detect_type_function::WS); 
      }
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
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

detect_type_function::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t detect_type_function::ExprContext::getRuleIndex() const {
  return detect_type_function::RuleExpr;
}

void detect_type_function::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

detect_type_function::ExprContext* detect_type_function::UnaryOpContext::expr() {
  return getRuleContext<detect_type_function::ExprContext>(0);
}

tree::TerminalNode* detect_type_function::UnaryOpContext::ADD() {
  return getToken(detect_type_function::ADD, 0);
}

tree::TerminalNode* detect_type_function::UnaryOpContext::SUB() {
  return getToken(detect_type_function::SUB, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::UnaryOpContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::UnaryOpContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

detect_type_function::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void detect_type_function::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- ParensContext ------------------------------------------------------------------

tree::TerminalNode* detect_type_function::ParensContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

detect_type_function::ExprContext* detect_type_function::ParensContext::expr() {
  return getRuleContext<detect_type_function::ExprContext>(0);
}

tree::TerminalNode* detect_type_function::ParensContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

detect_type_function::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void detect_type_function::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

detect_type_function::NumberContext* detect_type_function::LiteralContext::number() {
  return getRuleContext<detect_type_function::NumberContext>(0);
}

detect_type_function::ConstantContext* detect_type_function::LiteralContext::constant() {
  return getRuleContext<detect_type_function::ConstantContext>(0);
}

detect_type_function::LiteralContext::LiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void detect_type_function::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

detect_type_function::FunctionContext* detect_type_function::FunctionCallContext::function() {
  return getRuleContext<detect_type_function::FunctionContext>(0);
}

detect_type_function::MultiargfunctionContext* detect_type_function::FunctionCallContext::multiargfunction() {
  return getRuleContext<detect_type_function::MultiargfunctionContext>(0);
}

detect_type_function::RangefunctionContext* detect_type_function::FunctionCallContext::rangefunction() {
  return getRuleContext<detect_type_function::RangefunctionContext>(0);
}

detect_type_function::FunctionCallContext::FunctionCallContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void detect_type_function::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}
//----------------- VariableInExprContext ------------------------------------------------------------------

detect_type_function::VariableContext* detect_type_function::VariableInExprContext::variable() {
  return getRuleContext<detect_type_function::VariableContext>(0);
}

detect_type_function::VariableInExprContext::VariableInExprContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::VariableInExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInExpr(this);
}
void detect_type_function::VariableInExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInExpr(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<detect_type_function::ExprContext *> detect_type_function::BinaryOpContext::expr() {
  return getRuleContexts<detect_type_function::ExprContext>();
}

detect_type_function::ExprContext* detect_type_function::BinaryOpContext::expr(size_t i) {
  return getRuleContext<detect_type_function::ExprContext>(i);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::POW() {
  return getToken(detect_type_function::POW, 0);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::MUL() {
  return getToken(detect_type_function::MUL, 0);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::DIV() {
  return getToken(detect_type_function::DIV, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::BinaryOpContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::ADD() {
  return getToken(detect_type_function::ADD, 0);
}

tree::TerminalNode* detect_type_function::BinaryOpContext::SUB() {
  return getToken(detect_type_function::SUB, 0);
}

detect_type_function::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void detect_type_function::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void detect_type_function::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

detect_type_function::ExprContext* detect_type_function::expr() {
   return expr(0);
}

detect_type_function::ExprContext* detect_type_function::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  detect_type_function::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  detect_type_function::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, detect_type_function::RuleExpr, precedence);

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
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(172);
      match(detect_type_function::Lb);
      setState(173);
      expr(0);
      setState(174);
      match(detect_type_function::Rb);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(176);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(177);
        function();
        break;
      }

      case 2: {
        setState(178);
        multiargfunction();
        break;
      }

      case 3: {
        setState(179);
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
      setState(184);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_function::UINT:
        case detect_type_function::FLOAT: {
          setState(182);
          number();
          break;
        }

        case detect_type_function::EXP:
        case detect_type_function::PI: {
          setState(183);
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
      setState(186);
      _la = _input->LA(1);
      if (!(_la == detect_type_function::ADD

      || _la == detect_type_function::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(190);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(187);
          match(detect_type_function::WS); 
        }
        setState(192);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
      setState(193);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(231);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(229);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(196);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(197);
          match(detect_type_function::POW);
          setState(198);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(200);
            match(detect_type_function::WS);
            setState(205);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(206);
          _la = _input->LA(1);
          if (!(_la == detect_type_function::MUL

          || _la == detect_type_function::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(210);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(207);
              match(detect_type_function::WS); 
            }
            setState(212);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
          }
          setState(213);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(214);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(218);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_function::WS) {
            setState(215);
            match(detect_type_function::WS);
            setState(220);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(221);
          _la = _input->LA(1);
          if (!(_la == detect_type_function::ADD

          || _la == detect_type_function::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(225);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(222);
              match(detect_type_function::WS); 
            }
            setState(227);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
          }
          setState(228);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(233);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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

detect_type_function::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::ArrayContext::BEG_ARR() {
  return getToken(detect_type_function::BEG_ARR, 0);
}

tree::TerminalNode* detect_type_function::ArrayContext::END_ARR() {
  return getToken(detect_type_function::END_ARR, 0);
}

std::vector<detect_type_function::ExprContext *> detect_type_function::ArrayContext::expr() {
  return getRuleContexts<detect_type_function::ExprContext>();
}

detect_type_function::ExprContext* detect_type_function::ArrayContext::expr(size_t i) {
  return getRuleContext<detect_type_function::ExprContext>(i);
}

std::vector<detect_type_function::ArrayContext *> detect_type_function::ArrayContext::array() {
  return getRuleContexts<detect_type_function::ArrayContext>();
}

detect_type_function::ArrayContext* detect_type_function::ArrayContext::array(size_t i) {
  return getRuleContext<detect_type_function::ArrayContext>(i);
}

std::vector<tree::TerminalNode *> detect_type_function::ArrayContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::ArrayContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

std::vector<tree::TerminalNode *> detect_type_function::ArrayContext::SEPAR() {
  return getTokens(detect_type_function::SEPAR);
}

tree::TerminalNode* detect_type_function::ArrayContext::SEPAR(size_t i) {
  return getToken(detect_type_function::SEPAR, i);
}


size_t detect_type_function::ArrayContext::getRuleIndex() const {
  return detect_type_function::RuleArray;
}

void detect_type_function::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void detect_type_function::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

detect_type_function::ArrayContext* detect_type_function::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 8, detect_type_function::RuleArray);
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
    setState(234);
    match(detect_type_function::BEG_ARR);
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(235);
        match(detect_type_function::WS); 
      }
      setState(240);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_function::VAR_TAG:
      case detect_type_function::VARIABLE:
      case detect_type_function::SUMPRODUCT:
      case detect_type_function::SUM:
      case detect_type_function::SUM_I:
      case detect_type_function::PRODUCT:
      case detect_type_function::PRODUCT_I:
      case detect_type_function::LN:
      case detect_type_function::LG:
      case detect_type_function::LOG_X:
      case detect_type_function::EXP:
      case detect_type_function::SQRT:
      case detect_type_function::PI:
      case detect_type_function::COS:
      case detect_type_function::SIN:
      case detect_type_function::ASIN:
      case detect_type_function::ACOS:
      case detect_type_function::FACTORIAL:
      case detect_type_function::WS:
      case detect_type_function::UINT:
      case detect_type_function::Lb:
      case detect_type_function::ADD:
      case detect_type_function::SUB:
      case detect_type_function::FLOAT: {
        setState(241);
        expr(0);
        break;
      }

      case detect_type_function::BEG_ARR: {
        setState(242);
        array();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(248);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_function::WS) {
      setState(245);
      match(detect_type_function::WS);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_function::SEPAR) {
      setState(251);
      match(detect_type_function::SEPAR);
      setState(255);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(252);
          match(detect_type_function::WS); 
        }
        setState(257);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      }
      setState(260);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_function::VAR_TAG:
        case detect_type_function::VARIABLE:
        case detect_type_function::SUMPRODUCT:
        case detect_type_function::SUM:
        case detect_type_function::SUM_I:
        case detect_type_function::PRODUCT:
        case detect_type_function::PRODUCT_I:
        case detect_type_function::LN:
        case detect_type_function::LG:
        case detect_type_function::LOG_X:
        case detect_type_function::EXP:
        case detect_type_function::SQRT:
        case detect_type_function::PI:
        case detect_type_function::COS:
        case detect_type_function::SIN:
        case detect_type_function::ASIN:
        case detect_type_function::ACOS:
        case detect_type_function::FACTORIAL:
        case detect_type_function::WS:
        case detect_type_function::UINT:
        case detect_type_function::Lb:
        case detect_type_function::ADD:
        case detect_type_function::SUB:
        case detect_type_function::FLOAT: {
          setState(258);
          expr(0);
          break;
        }

        case detect_type_function::BEG_ARR: {
          setState(259);
          array();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(267);
    match(detect_type_function::END_ARR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

detect_type_function::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::NumberContext::UINT() {
  return getToken(detect_type_function::UINT, 0);
}

tree::TerminalNode* detect_type_function::NumberContext::FLOAT() {
  return getToken(detect_type_function::FLOAT, 0);
}


size_t detect_type_function::NumberContext::getRuleIndex() const {
  return detect_type_function::RuleNumber;
}

void detect_type_function::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void detect_type_function::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

detect_type_function::NumberContext* detect_type_function::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 10, detect_type_function::RuleNumber);
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
    setState(269);
    _la = _input->LA(1);
    if (!(_la == detect_type_function::UINT

    || _la == detect_type_function::FLOAT)) {
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

detect_type_function::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::ConstantContext::PI() {
  return getToken(detect_type_function::PI, 0);
}

tree::TerminalNode* detect_type_function::ConstantContext::EXP() {
  return getToken(detect_type_function::EXP, 0);
}


size_t detect_type_function::ConstantContext::getRuleIndex() const {
  return detect_type_function::RuleConstant;
}

void detect_type_function::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void detect_type_function::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

detect_type_function::ConstantContext* detect_type_function::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 12, detect_type_function::RuleConstant);
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
    setState(271);
    _la = _input->LA(1);
    if (!(_la == detect_type_function::EXP

    || _la == detect_type_function::PI)) {
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

detect_type_function::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::FunctionContext::LN() {
  return getToken(detect_type_function::LN, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

std::vector<detect_type_function::ExprContext *> detect_type_function::FunctionContext::expr() {
  return getRuleContexts<detect_type_function::ExprContext>();
}

detect_type_function::ExprContext* detect_type_function::FunctionContext::expr(size_t i) {
  return getRuleContext<detect_type_function::ExprContext>(i);
}

tree::TerminalNode* detect_type_function::FunctionContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::FunctionContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::FunctionContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::FunctionContext::LG() {
  return getToken(detect_type_function::LG, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::EXP() {
  return getToken(detect_type_function::EXP, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::SQRT() {
  return getToken(detect_type_function::SQRT, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::COS() {
  return getToken(detect_type_function::COS, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::SIN() {
  return getToken(detect_type_function::SIN, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::ACOS() {
  return getToken(detect_type_function::ACOS, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::ASIN() {
  return getToken(detect_type_function::ASIN, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::FACTORIAL() {
  return getToken(detect_type_function::FACTORIAL, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::LOG_X() {
  return getToken(detect_type_function::LOG_X, 0);
}

tree::TerminalNode* detect_type_function::FunctionContext::SEPAR() {
  return getToken(detect_type_function::SEPAR, 0);
}


size_t detect_type_function::FunctionContext::getRuleIndex() const {
  return detect_type_function::RuleFunction;
}

void detect_type_function::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void detect_type_function::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

detect_type_function::FunctionContext* detect_type_function::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 14, detect_type_function::RuleFunction);
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
    setState(567);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(273);
        match(detect_type_function::WS);
        setState(278);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(279);
      match(detect_type_function::LN);
      setState(280);
      match(detect_type_function::Lb);
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(281);
          match(detect_type_function::WS); 
        }
        setState(286);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      }
      setState(287);
      expr(0);
      setState(291);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(288);
        match(detect_type_function::WS);
        setState(293);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(294);
      match(detect_type_function::Rb);
      setState(298);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(295);
          match(detect_type_function::WS); 
        }
        setState(300);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(304);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(301);
        match(detect_type_function::WS);
        setState(306);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(307);
      match(detect_type_function::LG);
      setState(308);
      match(detect_type_function::Lb);
      setState(312);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(309);
          match(detect_type_function::WS); 
        }
        setState(314);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      }
      setState(315);
      expr(0);
      setState(319);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(316);
        match(detect_type_function::WS);
        setState(321);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(322);
      match(detect_type_function::Rb);
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(323);
          match(detect_type_function::WS); 
        }
        setState(328);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(332);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(329);
        match(detect_type_function::WS);
        setState(334);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(335);
      match(detect_type_function::EXP);
      setState(336);
      match(detect_type_function::Lb);
      setState(340);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(337);
          match(detect_type_function::WS); 
        }
        setState(342);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      }
      setState(343);
      expr(0);
      setState(347);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(344);
        match(detect_type_function::WS);
        setState(349);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(350);
      match(detect_type_function::Rb);
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(351);
          match(detect_type_function::WS); 
        }
        setState(356);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(360);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(357);
        match(detect_type_function::WS);
        setState(362);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(363);
      match(detect_type_function::SQRT);
      setState(364);
      match(detect_type_function::Lb);
      setState(368);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(365);
          match(detect_type_function::WS); 
        }
        setState(370);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
      }
      setState(371);
      expr(0);
      setState(375);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(372);
        match(detect_type_function::WS);
        setState(377);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(378);
      match(detect_type_function::Rb);
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(379);
          match(detect_type_function::WS); 
        }
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(388);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(385);
        match(detect_type_function::WS);
        setState(390);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(391);
      match(detect_type_function::COS);
      setState(392);
      match(detect_type_function::Lb);
      setState(396);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(393);
          match(detect_type_function::WS); 
        }
        setState(398);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      }
      setState(399);
      expr(0);
      setState(403);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(400);
        match(detect_type_function::WS);
        setState(405);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(406);
      match(detect_type_function::Rb);
      setState(410);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(407);
          match(detect_type_function::WS); 
        }
        setState(412);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(416);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(413);
        match(detect_type_function::WS);
        setState(418);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(419);
      match(detect_type_function::SIN);
      setState(420);
      match(detect_type_function::Lb);
      setState(424);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(421);
          match(detect_type_function::WS); 
        }
        setState(426);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      }
      setState(427);
      expr(0);
      setState(431);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(428);
        match(detect_type_function::WS);
        setState(433);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(434);
      match(detect_type_function::Rb);
      setState(438);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(435);
          match(detect_type_function::WS); 
        }
        setState(440);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(444);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(441);
        match(detect_type_function::WS);
        setState(446);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(447);
      match(detect_type_function::ACOS);
      setState(448);
      match(detect_type_function::Lb);
      setState(452);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(449);
          match(detect_type_function::WS); 
        }
        setState(454);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(455);
      expr(0);
      setState(459);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(456);
        match(detect_type_function::WS);
        setState(461);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(462);
      match(detect_type_function::Rb);
      setState(466);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(463);
          match(detect_type_function::WS); 
        }
        setState(468);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(472);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(469);
        match(detect_type_function::WS);
        setState(474);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(475);
      match(detect_type_function::ASIN);
      setState(476);
      match(detect_type_function::Lb);
      setState(480);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(477);
          match(detect_type_function::WS); 
        }
        setState(482);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      setState(483);
      expr(0);
      setState(487);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(484);
        match(detect_type_function::WS);
        setState(489);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(490);
      match(detect_type_function::Rb);
      setState(494);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(491);
          match(detect_type_function::WS); 
        }
        setState(496);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(497);
        match(detect_type_function::WS);
        setState(502);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(503);
      match(detect_type_function::FACTORIAL);
      setState(504);
      match(detect_type_function::Lb);
      setState(508);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(505);
          match(detect_type_function::WS); 
        }
        setState(510);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      setState(511);
      expr(0);
      setState(515);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(512);
        match(detect_type_function::WS);
        setState(517);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(518);
      match(detect_type_function::Rb);
      setState(522);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(519);
          match(detect_type_function::WS); 
        }
        setState(524);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(528);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(525);
        match(detect_type_function::WS);
        setState(530);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(531);
      match(detect_type_function::LOG_X);
      setState(532);
      match(detect_type_function::Lb);
      setState(536);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(533);
          match(detect_type_function::WS); 
        }
        setState(538);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
      setState(539);
      expr(0);
      setState(543);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(540);
        match(detect_type_function::WS);
        setState(545);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(546);
      match(detect_type_function::SEPAR);
      setState(550);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(547);
          match(detect_type_function::WS); 
        }
        setState(552);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      setState(553);
      expr(0);
      setState(557);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(554);
        match(detect_type_function::WS);
        setState(559);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(560);
      match(detect_type_function::Rb);
      setState(564);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(561);
          match(detect_type_function::WS); 
        }
        setState(566);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
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

detect_type_function::MultiargfunctionContext::MultiargfunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::SUMPRODUCT() {
  return getToken(detect_type_function::SUMPRODUCT, 0);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

std::vector<detect_type_function::ExprContext *> detect_type_function::MultiargfunctionContext::expr() {
  return getRuleContexts<detect_type_function::ExprContext>();
}

detect_type_function::ExprContext* detect_type_function::MultiargfunctionContext::expr(size_t i) {
  return getRuleContext<detect_type_function::ExprContext>(i);
}

std::vector<tree::TerminalNode *> detect_type_function::MultiargfunctionContext::SEPAR() {
  return getTokens(detect_type_function::SEPAR);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::SEPAR(size_t i) {
  return getToken(detect_type_function::SEPAR, i);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::MultiargfunctionContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::SUM() {
  return getToken(detect_type_function::SUM, 0);
}

tree::TerminalNode* detect_type_function::MultiargfunctionContext::PRODUCT() {
  return getToken(detect_type_function::PRODUCT, 0);
}


size_t detect_type_function::MultiargfunctionContext::getRuleIndex() const {
  return detect_type_function::RuleMultiargfunction;
}

void detect_type_function::MultiargfunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiargfunction(this);
}

void detect_type_function::MultiargfunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiargfunction(this);
}

detect_type_function::MultiargfunctionContext* detect_type_function::multiargfunction() {
  MultiargfunctionContext *_localctx = _tracker.createInstance<MultiargfunctionContext>(_ctx, getState());
  enterRule(_localctx, 16, detect_type_function::RuleMultiargfunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(572);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(569);
        match(detect_type_function::WS);
        setState(574);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(575);
      match(detect_type_function::SUMPRODUCT);
      setState(576);
      match(detect_type_function::Lb);
      setState(577);
      expr(0);
      setState(578);
      match(detect_type_function::SEPAR);
      setState(579);
      expr(0);
      setState(584);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::SEPAR) {
        setState(580);
        match(detect_type_function::SEPAR);
        setState(581);
        expr(0);
        setState(586);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(587);
      match(detect_type_function::Rb);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(589);
        match(detect_type_function::WS);
        setState(594);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(595);
      match(detect_type_function::SUM);
      setState(596);
      match(detect_type_function::Lb);
      setState(597);
      expr(0);
      setState(598);
      match(detect_type_function::SEPAR);
      setState(599);
      expr(0);
      setState(604);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::SEPAR) {
        setState(600);
        match(detect_type_function::SEPAR);
        setState(601);
        expr(0);
        setState(606);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(607);
      match(detect_type_function::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(612);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(609);
        match(detect_type_function::WS);
        setState(614);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(615);
      match(detect_type_function::PRODUCT);
      setState(616);
      match(detect_type_function::Lb);
      setState(617);
      expr(0);
      setState(618);
      match(detect_type_function::SEPAR);
      setState(619);
      expr(0);
      setState(624);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::SEPAR) {
        setState(620);
        match(detect_type_function::SEPAR);
        setState(621);
        expr(0);
        setState(626);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(627);
      match(detect_type_function::Rb);
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

detect_type_function::RangefunctionContext::RangefunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_function::RangefunctionContext::SUM_I() {
  return getToken(detect_type_function::SUM_I, 0);
}

tree::TerminalNode* detect_type_function::RangefunctionContext::Lb() {
  return getToken(detect_type_function::Lb, 0);
}

detect_type_function::ExprContext* detect_type_function::RangefunctionContext::expr() {
  return getRuleContext<detect_type_function::ExprContext>(0);
}

tree::TerminalNode* detect_type_function::RangefunctionContext::Rb() {
  return getToken(detect_type_function::Rb, 0);
}

std::vector<tree::TerminalNode *> detect_type_function::RangefunctionContext::WS() {
  return getTokens(detect_type_function::WS);
}

tree::TerminalNode* detect_type_function::RangefunctionContext::WS(size_t i) {
  return getToken(detect_type_function::WS, i);
}

tree::TerminalNode* detect_type_function::RangefunctionContext::PRODUCT_I() {
  return getToken(detect_type_function::PRODUCT_I, 0);
}


size_t detect_type_function::RangefunctionContext::getRuleIndex() const {
  return detect_type_function::RuleRangefunction;
}

void detect_type_function::RangefunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangefunction(this);
}

void detect_type_function::RangefunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangefunction(this);
}

detect_type_function::RangefunctionContext* detect_type_function::rangefunction() {
  RangefunctionContext *_localctx = _tracker.createInstance<RangefunctionContext>(_ctx, getState());
  enterRule(_localctx, 18, detect_type_function::RuleRangefunction);
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
    setState(687);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(634);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(631);
        match(detect_type_function::WS);
        setState(636);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(637);
      match(detect_type_function::SUM_I);
      setState(638);
      match(detect_type_function::Lb);
      setState(642);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(639);
          match(detect_type_function::WS); 
        }
        setState(644);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      setState(645);
      expr(0);
      setState(649);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(646);
        match(detect_type_function::WS);
        setState(651);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(652);
      match(detect_type_function::Rb);
      setState(656);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(653);
          match(detect_type_function::WS); 
        }
        setState(658);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(662);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(659);
        match(detect_type_function::WS);
        setState(664);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(665);
      match(detect_type_function::PRODUCT_I);
      setState(666);
      match(detect_type_function::Lb);
      setState(670);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(667);
          match(detect_type_function::WS); 
        }
        setState(672);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      }
      setState(673);
      expr(0);
      setState(677);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_function::WS) {
        setState(674);
        match(detect_type_function::WS);
        setState(679);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(680);
      match(detect_type_function::Rb);
      setState(684);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(681);
          match(detect_type_function::WS); 
        }
        setState(686);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
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

detect_type_function::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> detect_type_function::StringContext::DOUBLE_QUOTE() {
  return getTokens(detect_type_function::DOUBLE_QUOTE);
}

tree::TerminalNode* detect_type_function::StringContext::DOUBLE_QUOTE(size_t i) {
  return getToken(detect_type_function::DOUBLE_QUOTE, i);
}

tree::TerminalNode* detect_type_function::StringContext::STRING() {
  return getToken(detect_type_function::STRING, 0);
}


size_t detect_type_function::StringContext::getRuleIndex() const {
  return detect_type_function::RuleString;
}

void detect_type_function::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void detect_type_function::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

detect_type_function::StringContext* detect_type_function::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 20, detect_type_function::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(689);
    match(detect_type_function::DOUBLE_QUOTE);
    setState(690);
    match(detect_type_function::STRING);
    setState(691);
    match(detect_type_function::DOUBLE_QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool detect_type_function::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool detect_type_function::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void detect_type_function::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  detect_type_functionParserInitialize();
#else
  ::antlr4::internal::call_once(detect_type_functionParserOnceFlag, detect_type_functionParserInitialize);
#endif
}
