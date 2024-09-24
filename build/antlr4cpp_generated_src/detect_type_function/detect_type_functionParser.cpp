
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
      "value_type", "comparator", "input", "line_input", "node_access", 
      "variable", "vardefinition", "comparision", "lhs_comp", "rhs_comp", 
      "expr_comp", "expr", "array", "input_array", "number", "constant", 
      "function", "multiargfunction", "rangefunction", "string"
    },
    std::vector<std::string>{
      "", "'('", "')'", "';'", "'VAR('", "':'", "'['", "']'", "'\"'", "", 
      "", "", "", "'>'", "", "'='", "", "'<'", "", "'+'", "'-'", "'*'", 
      "'/'", "'^'", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "'''"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "VARIABLE", "DATABASE", "WS", 
      "EOL", "LARGER", "LARGER_EQUAL", "EQUAL", "LESS", "LESS_EQUAL", "UINT", 
      "ADD", "SUB", "MUL", "DIV", "POW", "SUMPRODUCT", "SUMPRODUCT_I", "SUM", 
      "SUM_I", "PRODUCT", "PRODUCT_I", "LN", "LG", "LOG_X", "EXP", "SQRT", 
      "PI", "COS", "SIN", "ASIN", "ACOS", "FACTORIAL", "QUOTE", "ASTERISK", 
      "EXPONENT", "FLOAT", "ID_NUMBER", "STRING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,46,884,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,3,0,
  	44,8,0,1,1,1,1,1,2,4,2,49,8,2,11,2,12,2,50,1,2,3,2,54,8,2,1,3,1,3,3,3,
  	58,8,3,1,4,5,4,61,8,4,10,4,12,4,64,9,4,1,4,1,4,5,4,68,8,4,10,4,12,4,71,
  	9,4,1,4,1,4,1,4,5,4,76,8,4,10,4,12,4,79,9,4,1,4,1,4,5,4,83,8,4,10,4,12,
  	4,86,9,4,1,4,1,4,1,4,5,4,91,8,4,10,4,12,4,94,9,4,1,4,1,4,5,4,98,8,4,10,
  	4,12,4,101,9,4,1,4,1,4,5,4,105,8,4,10,4,12,4,108,9,4,1,4,5,4,111,8,4,
  	10,4,12,4,114,9,4,1,4,5,4,117,8,4,10,4,12,4,120,9,4,1,4,1,4,1,4,5,4,125,
  	8,4,10,4,12,4,128,9,4,3,4,130,8,4,1,5,5,5,133,8,5,10,5,12,5,136,9,5,1,
  	5,1,5,5,5,140,8,5,10,5,12,5,143,9,5,1,5,1,5,1,5,5,5,148,8,5,10,5,12,5,
  	151,9,5,1,5,5,5,154,8,5,10,5,12,5,157,9,5,1,5,1,5,5,5,161,8,5,10,5,12,
  	5,164,9,5,3,5,166,8,5,1,5,1,5,3,5,170,8,5,1,5,1,5,3,5,174,8,5,3,5,176,
  	8,5,1,5,5,5,179,8,5,10,5,12,5,182,9,5,1,6,5,6,185,8,6,10,6,12,6,188,9,
  	6,1,6,1,6,5,6,192,8,6,10,6,12,6,195,9,6,1,6,1,6,1,6,5,6,200,8,6,10,6,
  	12,6,203,9,6,1,6,5,6,206,8,6,10,6,12,6,209,9,6,1,6,1,6,5,6,213,8,6,10,
  	6,12,6,216,9,6,3,6,218,8,6,1,6,1,6,3,6,222,8,6,1,6,1,6,3,6,226,8,6,3,
  	6,228,8,6,1,6,5,6,231,8,6,10,6,12,6,234,9,6,1,6,1,6,5,6,238,8,6,10,6,
  	12,6,241,9,6,1,6,3,6,244,8,6,1,6,5,6,247,8,6,10,6,12,6,250,9,6,1,6,1,
  	6,1,7,5,7,255,8,7,10,7,12,7,258,9,7,1,7,1,7,5,7,262,8,7,10,7,12,7,265,
  	9,7,1,7,1,7,1,7,5,7,270,8,7,10,7,12,7,273,9,7,1,7,5,7,276,8,7,10,7,12,
  	7,279,9,7,1,7,1,7,5,7,283,8,7,10,7,12,7,286,9,7,3,7,288,8,7,1,7,1,7,5,
  	7,292,8,7,10,7,12,7,295,9,7,1,7,1,7,5,7,299,8,7,10,7,12,7,302,9,7,3,7,
  	304,8,7,1,7,5,7,307,8,7,10,7,12,7,310,9,7,1,7,1,7,5,7,314,8,7,10,7,12,
  	7,317,9,7,1,7,1,7,5,7,321,8,7,10,7,12,7,324,9,7,1,7,1,7,5,7,328,8,7,10,
  	7,12,7,331,9,7,1,7,1,7,5,7,335,8,7,10,7,12,7,338,9,7,1,7,1,7,5,7,342,
  	8,7,10,7,12,7,345,9,7,1,7,1,7,5,7,349,8,7,10,7,12,7,352,9,7,3,7,354,8,
  	7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,3,11,373,8,11,1,11,1,11,3,11,377,8,11,1,11,1,11,5,11,381,8,
  	11,10,11,12,11,384,9,11,1,11,3,11,387,8,11,1,11,1,11,1,11,1,11,1,11,5,
  	11,394,8,11,10,11,12,11,397,9,11,1,11,1,11,5,11,401,8,11,10,11,12,11,
  	404,9,11,1,11,1,11,1,11,5,11,409,8,11,10,11,12,11,412,9,11,1,11,1,11,
  	5,11,416,8,11,10,11,12,11,419,9,11,1,11,5,11,422,8,11,10,11,12,11,425,
  	9,11,1,12,1,12,5,12,429,8,12,10,12,12,12,432,9,12,1,12,1,12,5,12,436,
  	8,12,10,12,12,12,439,9,12,1,12,1,12,5,12,443,8,12,10,12,12,12,446,9,12,
  	1,12,5,12,449,8,12,10,12,12,12,452,9,12,1,12,1,12,1,13,1,13,3,13,458,
  	8,13,1,14,1,14,1,15,1,15,1,16,5,16,465,8,16,10,16,12,16,468,9,16,1,16,
  	1,16,1,16,5,16,473,8,16,10,16,12,16,476,9,16,1,16,1,16,5,16,480,8,16,
  	10,16,12,16,483,9,16,1,16,1,16,5,16,487,8,16,10,16,12,16,490,9,16,1,16,
  	5,16,493,8,16,10,16,12,16,496,9,16,1,16,1,16,1,16,5,16,501,8,16,10,16,
  	12,16,504,9,16,1,16,1,16,5,16,508,8,16,10,16,12,16,511,9,16,1,16,1,16,
  	5,16,515,8,16,10,16,12,16,518,9,16,1,16,5,16,521,8,16,10,16,12,16,524,
  	9,16,1,16,1,16,1,16,5,16,529,8,16,10,16,12,16,532,9,16,1,16,1,16,5,16,
  	536,8,16,10,16,12,16,539,9,16,1,16,1,16,5,16,543,8,16,10,16,12,16,546,
  	9,16,1,16,5,16,549,8,16,10,16,12,16,552,9,16,1,16,1,16,1,16,5,16,557,
  	8,16,10,16,12,16,560,9,16,1,16,1,16,5,16,564,8,16,10,16,12,16,567,9,16,
  	1,16,1,16,5,16,571,8,16,10,16,12,16,574,9,16,1,16,5,16,577,8,16,10,16,
  	12,16,580,9,16,1,16,1,16,1,16,5,16,585,8,16,10,16,12,16,588,9,16,1,16,
  	1,16,5,16,592,8,16,10,16,12,16,595,9,16,1,16,1,16,5,16,599,8,16,10,16,
  	12,16,602,9,16,1,16,5,16,605,8,16,10,16,12,16,608,9,16,1,16,1,16,1,16,
  	5,16,613,8,16,10,16,12,16,616,9,16,1,16,1,16,5,16,620,8,16,10,16,12,16,
  	623,9,16,1,16,1,16,5,16,627,8,16,10,16,12,16,630,9,16,1,16,5,16,633,8,
  	16,10,16,12,16,636,9,16,1,16,1,16,1,16,5,16,641,8,16,10,16,12,16,644,
  	9,16,1,16,1,16,5,16,648,8,16,10,16,12,16,651,9,16,1,16,1,16,5,16,655,
  	8,16,10,16,12,16,658,9,16,1,16,5,16,661,8,16,10,16,12,16,664,9,16,1,16,
  	1,16,1,16,5,16,669,8,16,10,16,12,16,672,9,16,1,16,1,16,5,16,676,8,16,
  	10,16,12,16,679,9,16,1,16,1,16,5,16,683,8,16,10,16,12,16,686,9,16,1,16,
  	5,16,689,8,16,10,16,12,16,692,9,16,1,16,1,16,1,16,5,16,697,8,16,10,16,
  	12,16,700,9,16,1,16,1,16,5,16,704,8,16,10,16,12,16,707,9,16,1,16,1,16,
  	5,16,711,8,16,10,16,12,16,714,9,16,1,16,5,16,717,8,16,10,16,12,16,720,
  	9,16,1,16,1,16,1,16,5,16,725,8,16,10,16,12,16,728,9,16,1,16,1,16,5,16,
  	732,8,16,10,16,12,16,735,9,16,1,16,1,16,5,16,739,8,16,10,16,12,16,742,
  	9,16,1,16,1,16,5,16,746,8,16,10,16,12,16,749,9,16,1,16,1,16,5,16,753,
  	8,16,10,16,12,16,756,9,16,3,16,758,8,16,1,17,5,17,761,8,17,10,17,12,17,
  	764,9,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,773,8,17,10,17,12,17,
  	776,9,17,1,17,1,17,1,17,5,17,781,8,17,10,17,12,17,784,9,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,5,17,793,8,17,10,17,12,17,796,9,17,1,17,1,17,
  	1,17,5,17,801,8,17,10,17,12,17,804,9,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,5,17,813,8,17,10,17,12,17,816,9,17,1,17,1,17,3,17,820,8,17,1,18,
  	5,18,823,8,18,10,18,12,18,826,9,18,1,18,1,18,1,18,5,18,831,8,18,10,18,
  	12,18,834,9,18,1,18,1,18,5,18,838,8,18,10,18,12,18,841,9,18,1,18,1,18,
  	5,18,845,8,18,10,18,12,18,848,9,18,1,18,5,18,851,8,18,10,18,12,18,854,
  	9,18,1,18,1,18,1,18,5,18,859,8,18,10,18,12,18,862,9,18,1,18,1,18,5,18,
  	866,8,18,10,18,12,18,869,9,18,1,18,1,18,5,18,873,8,18,10,18,12,18,876,
  	9,18,3,18,878,8,18,1,19,1,19,1,19,1,19,1,19,0,1,22,20,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,38,0,5,1,0,13,17,1,0,19,20,1,0,21,
  	22,2,0,18,18,44,44,2,0,33,33,35,35,1008,0,43,1,0,0,0,2,45,1,0,0,0,4,53,
  	1,0,0,0,6,57,1,0,0,0,8,129,1,0,0,0,10,134,1,0,0,0,12,186,1,0,0,0,14,256,
  	1,0,0,0,16,357,1,0,0,0,18,359,1,0,0,0,20,361,1,0,0,0,22,386,1,0,0,0,24,
  	426,1,0,0,0,26,457,1,0,0,0,28,459,1,0,0,0,30,461,1,0,0,0,32,757,1,0,0,
  	0,34,819,1,0,0,0,36,877,1,0,0,0,38,879,1,0,0,0,40,44,3,24,12,0,41,44,
  	3,22,11,0,42,44,3,38,19,0,43,40,1,0,0,0,43,41,1,0,0,0,43,42,1,0,0,0,44,
  	1,1,0,0,0,45,46,7,0,0,0,46,3,1,0,0,0,47,49,3,6,3,0,48,47,1,0,0,0,49,50,
  	1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,54,1,0,0,0,52,54,5,0,0,1,53,48,
  	1,0,0,0,53,52,1,0,0,0,54,5,1,0,0,0,55,58,3,12,6,0,56,58,3,14,7,0,57,55,
  	1,0,0,0,57,56,1,0,0,0,58,7,1,0,0,0,59,61,5,11,0,0,60,59,1,0,0,0,61,64,
  	1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,0,0,65,69,
  	5,1,0,0,66,68,5,11,0,0,67,66,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,
  	1,0,0,0,70,72,1,0,0,0,71,69,1,0,0,0,72,130,5,2,0,0,73,77,5,1,0,0,74,76,
  	5,11,0,0,75,74,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,80,
  	1,0,0,0,79,77,1,0,0,0,80,84,5,18,0,0,81,83,5,11,0,0,82,81,1,0,0,0,83,
  	86,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,87,1,0,0,0,86,84,1,0,0,0,87,
  	130,5,2,0,0,88,92,5,1,0,0,89,91,5,11,0,0,90,89,1,0,0,0,91,94,1,0,0,0,
  	92,90,1,0,0,0,92,93,1,0,0,0,93,95,1,0,0,0,94,92,1,0,0,0,95,99,5,18,0,
  	0,96,98,5,11,0,0,97,96,1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,
  	0,0,0,100,112,1,0,0,0,101,99,1,0,0,0,102,106,5,3,0,0,103,105,5,11,0,0,
  	104,103,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,109,
  	1,0,0,0,108,106,1,0,0,0,109,111,5,18,0,0,110,102,1,0,0,0,111,114,1,0,
  	0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,118,1,0,0,0,114,112,1,0,0,0,115,
  	117,5,11,0,0,116,115,1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,
  	1,0,0,0,119,121,1,0,0,0,120,118,1,0,0,0,121,122,5,2,0,0,122,126,1,0,0,
  	0,123,125,5,11,0,0,124,123,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,126,
  	127,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,129,62,1,0,0,0,129,73,1,0,
  	0,0,129,88,1,0,0,0,130,9,1,0,0,0,131,133,5,11,0,0,132,131,1,0,0,0,133,
  	136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,175,1,0,0,0,136,134,1,
  	0,0,0,137,165,5,4,0,0,138,140,5,11,0,0,139,138,1,0,0,0,140,143,1,0,0,
  	0,141,139,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,0,143,141,1,0,0,0,144,
  	145,5,10,0,0,145,149,5,9,0,0,146,148,5,11,0,0,147,146,1,0,0,0,148,151,
  	1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,166,1,0,0,0,151,149,1,0,0,
  	0,152,154,5,11,0,0,153,152,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,155,
  	156,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,0,158,162,5,9,0,0,159,161,5,
  	11,0,0,160,159,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,162,163,1,0,0,
  	0,163,166,1,0,0,0,164,162,1,0,0,0,165,141,1,0,0,0,165,155,1,0,0,0,166,
  	167,1,0,0,0,167,169,5,2,0,0,168,170,3,8,4,0,169,168,1,0,0,0,169,170,1,
  	0,0,0,170,176,1,0,0,0,171,173,5,9,0,0,172,174,3,8,4,0,173,172,1,0,0,0,
  	173,174,1,0,0,0,174,176,1,0,0,0,175,137,1,0,0,0,175,171,1,0,0,0,176,180,
  	1,0,0,0,177,179,5,11,0,0,178,177,1,0,0,0,179,182,1,0,0,0,180,178,1,0,
  	0,0,180,181,1,0,0,0,181,11,1,0,0,0,182,180,1,0,0,0,183,185,5,11,0,0,184,
  	183,1,0,0,0,185,188,1,0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,227,1,
  	0,0,0,188,186,1,0,0,0,189,217,5,4,0,0,190,192,5,11,0,0,191,190,1,0,0,
  	0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,196,1,0,0,0,195,
  	193,1,0,0,0,196,197,5,10,0,0,197,201,5,9,0,0,198,200,5,11,0,0,199,198,
  	1,0,0,0,200,203,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,0,202,218,1,0,0,
  	0,203,201,1,0,0,0,204,206,5,11,0,0,205,204,1,0,0,0,206,209,1,0,0,0,207,
  	205,1,0,0,0,207,208,1,0,0,0,208,210,1,0,0,0,209,207,1,0,0,0,210,214,5,
  	9,0,0,211,213,5,11,0,0,212,211,1,0,0,0,213,216,1,0,0,0,214,212,1,0,0,
  	0,214,215,1,0,0,0,215,218,1,0,0,0,216,214,1,0,0,0,217,193,1,0,0,0,217,
  	207,1,0,0,0,218,219,1,0,0,0,219,221,5,2,0,0,220,222,3,8,4,0,221,220,1,
  	0,0,0,221,222,1,0,0,0,222,228,1,0,0,0,223,225,5,9,0,0,224,226,3,8,4,0,
  	225,224,1,0,0,0,225,226,1,0,0,0,226,228,1,0,0,0,227,189,1,0,0,0,227,223,
  	1,0,0,0,228,232,1,0,0,0,229,231,5,11,0,0,230,229,1,0,0,0,231,234,1,0,
  	0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,235,1,0,0,0,234,232,1,0,0,0,235,
  	239,5,15,0,0,236,238,5,11,0,0,237,236,1,0,0,0,238,241,1,0,0,0,239,237,
  	1,0,0,0,239,240,1,0,0,0,240,243,1,0,0,0,241,239,1,0,0,0,242,244,3,0,0,
  	0,243,242,1,0,0,0,243,244,1,0,0,0,244,248,1,0,0,0,245,247,5,11,0,0,246,
  	245,1,0,0,0,247,250,1,0,0,0,248,246,1,0,0,0,248,249,1,0,0,0,249,251,1,
  	0,0,0,250,248,1,0,0,0,251,252,5,12,0,0,252,13,1,0,0,0,253,255,5,11,0,
  	0,254,253,1,0,0,0,255,258,1,0,0,0,256,254,1,0,0,0,256,257,1,0,0,0,257,
  	303,1,0,0,0,258,256,1,0,0,0,259,287,5,4,0,0,260,262,5,11,0,0,261,260,
  	1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,264,1,0,0,0,264,266,1,0,0,
  	0,265,263,1,0,0,0,266,267,5,10,0,0,267,271,5,9,0,0,268,270,5,11,0,0,269,
  	268,1,0,0,0,270,273,1,0,0,0,271,269,1,0,0,0,271,272,1,0,0,0,272,288,1,
  	0,0,0,273,271,1,0,0,0,274,276,5,11,0,0,275,274,1,0,0,0,276,279,1,0,0,
  	0,277,275,1,0,0,0,277,278,1,0,0,0,278,280,1,0,0,0,279,277,1,0,0,0,280,
  	284,5,9,0,0,281,283,5,11,0,0,282,281,1,0,0,0,283,286,1,0,0,0,284,282,
  	1,0,0,0,284,285,1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,287,263,1,0,0,
  	0,287,277,1,0,0,0,288,289,1,0,0,0,289,304,5,2,0,0,290,292,5,11,0,0,291,
  	290,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,293,294,1,0,0,0,294,296,1,
  	0,0,0,295,293,1,0,0,0,296,300,5,9,0,0,297,299,5,11,0,0,298,297,1,0,0,
  	0,299,302,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,304,1,0,0,0,302,
  	300,1,0,0,0,303,259,1,0,0,0,303,293,1,0,0,0,304,308,1,0,0,0,305,307,5,
  	11,0,0,306,305,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,
  	0,309,311,1,0,0,0,310,308,1,0,0,0,311,315,5,5,0,0,312,314,5,11,0,0,313,
  	312,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,0,316,318,1,
  	0,0,0,317,315,1,0,0,0,318,322,3,16,8,0,319,321,5,11,0,0,320,319,1,0,0,
  	0,321,324,1,0,0,0,322,320,1,0,0,0,322,323,1,0,0,0,323,325,1,0,0,0,324,
  	322,1,0,0,0,325,329,3,2,1,0,326,328,5,11,0,0,327,326,1,0,0,0,328,331,
  	1,0,0,0,329,327,1,0,0,0,329,330,1,0,0,0,330,332,1,0,0,0,331,329,1,0,0,
  	0,332,336,3,18,9,0,333,335,5,11,0,0,334,333,1,0,0,0,335,338,1,0,0,0,336,
  	334,1,0,0,0,336,337,1,0,0,0,337,353,1,0,0,0,338,336,1,0,0,0,339,343,5,
  	5,0,0,340,342,5,11,0,0,341,340,1,0,0,0,342,345,1,0,0,0,343,341,1,0,0,
  	0,343,344,1,0,0,0,344,346,1,0,0,0,345,343,1,0,0,0,346,350,3,20,10,0,347,
  	349,5,11,0,0,348,347,1,0,0,0,349,352,1,0,0,0,350,348,1,0,0,0,350,351,
  	1,0,0,0,351,354,1,0,0,0,352,350,1,0,0,0,353,339,1,0,0,0,353,354,1,0,0,
  	0,354,355,1,0,0,0,355,356,5,12,0,0,356,15,1,0,0,0,357,358,3,22,11,0,358,
  	17,1,0,0,0,359,360,3,22,11,0,360,19,1,0,0,0,361,362,3,22,11,0,362,21,
  	1,0,0,0,363,364,6,11,-1,0,364,365,5,1,0,0,365,366,3,22,11,0,366,367,5,
  	2,0,0,367,387,1,0,0,0,368,387,3,10,5,0,369,373,3,32,16,0,370,373,3,34,
  	17,0,371,373,3,36,18,0,372,369,1,0,0,0,372,370,1,0,0,0,372,371,1,0,0,
  	0,373,387,1,0,0,0,374,377,3,28,14,0,375,377,3,30,15,0,376,374,1,0,0,0,
  	376,375,1,0,0,0,377,387,1,0,0,0,378,382,7,1,0,0,379,381,5,11,0,0,380,
  	379,1,0,0,0,381,384,1,0,0,0,382,380,1,0,0,0,382,383,1,0,0,0,383,385,1,
  	0,0,0,384,382,1,0,0,0,385,387,3,22,11,4,386,363,1,0,0,0,386,368,1,0,0,
  	0,386,372,1,0,0,0,386,376,1,0,0,0,386,378,1,0,0,0,387,423,1,0,0,0,388,
  	389,10,3,0,0,389,390,5,23,0,0,390,422,3,22,11,4,391,395,10,2,0,0,392,
  	394,5,11,0,0,393,392,1,0,0,0,394,397,1,0,0,0,395,393,1,0,0,0,395,396,
  	1,0,0,0,396,398,1,0,0,0,397,395,1,0,0,0,398,402,7,2,0,0,399,401,5,11,
  	0,0,400,399,1,0,0,0,401,404,1,0,0,0,402,400,1,0,0,0,402,403,1,0,0,0,403,
  	405,1,0,0,0,404,402,1,0,0,0,405,422,3,22,11,3,406,410,10,1,0,0,407,409,
  	5,11,0,0,408,407,1,0,0,0,409,412,1,0,0,0,410,408,1,0,0,0,410,411,1,0,
  	0,0,411,413,1,0,0,0,412,410,1,0,0,0,413,417,7,1,0,0,414,416,5,11,0,0,
  	415,414,1,0,0,0,416,419,1,0,0,0,417,415,1,0,0,0,417,418,1,0,0,0,418,420,
  	1,0,0,0,419,417,1,0,0,0,420,422,3,22,11,2,421,388,1,0,0,0,421,391,1,0,
  	0,0,421,406,1,0,0,0,422,425,1,0,0,0,423,421,1,0,0,0,423,424,1,0,0,0,424,
  	23,1,0,0,0,425,423,1,0,0,0,426,430,5,6,0,0,427,429,5,11,0,0,428,427,1,
  	0,0,0,429,432,1,0,0,0,430,428,1,0,0,0,430,431,1,0,0,0,431,433,1,0,0,0,
  	432,430,1,0,0,0,433,437,3,26,13,0,434,436,5,11,0,0,435,434,1,0,0,0,436,
  	439,1,0,0,0,437,435,1,0,0,0,437,438,1,0,0,0,438,450,1,0,0,0,439,437,1,
  	0,0,0,440,444,5,3,0,0,441,443,5,11,0,0,442,441,1,0,0,0,443,446,1,0,0,
  	0,444,442,1,0,0,0,444,445,1,0,0,0,445,447,1,0,0,0,446,444,1,0,0,0,447,
  	449,3,26,13,0,448,440,1,0,0,0,449,452,1,0,0,0,450,448,1,0,0,0,450,451,
  	1,0,0,0,451,453,1,0,0,0,452,450,1,0,0,0,453,454,5,7,0,0,454,25,1,0,0,
  	0,455,458,3,24,12,0,456,458,3,22,11,0,457,455,1,0,0,0,457,456,1,0,0,0,
  	458,27,1,0,0,0,459,460,7,3,0,0,460,29,1,0,0,0,461,462,7,4,0,0,462,31,
  	1,0,0,0,463,465,5,11,0,0,464,463,1,0,0,0,465,468,1,0,0,0,466,464,1,0,
  	0,0,466,467,1,0,0,0,467,469,1,0,0,0,468,466,1,0,0,0,469,470,5,30,0,0,
  	470,474,5,1,0,0,471,473,5,11,0,0,472,471,1,0,0,0,473,476,1,0,0,0,474,
  	472,1,0,0,0,474,475,1,0,0,0,475,477,1,0,0,0,476,474,1,0,0,0,477,481,3,
  	22,11,0,478,480,5,11,0,0,479,478,1,0,0,0,480,483,1,0,0,0,481,479,1,0,
  	0,0,481,482,1,0,0,0,482,484,1,0,0,0,483,481,1,0,0,0,484,488,5,2,0,0,485,
  	487,5,11,0,0,486,485,1,0,0,0,487,490,1,0,0,0,488,486,1,0,0,0,488,489,
  	1,0,0,0,489,758,1,0,0,0,490,488,1,0,0,0,491,493,5,11,0,0,492,491,1,0,
  	0,0,493,496,1,0,0,0,494,492,1,0,0,0,494,495,1,0,0,0,495,497,1,0,0,0,496,
  	494,1,0,0,0,497,498,5,31,0,0,498,502,5,1,0,0,499,501,5,11,0,0,500,499,
  	1,0,0,0,501,504,1,0,0,0,502,500,1,0,0,0,502,503,1,0,0,0,503,505,1,0,0,
  	0,504,502,1,0,0,0,505,509,3,22,11,0,506,508,5,11,0,0,507,506,1,0,0,0,
  	508,511,1,0,0,0,509,507,1,0,0,0,509,510,1,0,0,0,510,512,1,0,0,0,511,509,
  	1,0,0,0,512,516,5,2,0,0,513,515,5,11,0,0,514,513,1,0,0,0,515,518,1,0,
  	0,0,516,514,1,0,0,0,516,517,1,0,0,0,517,758,1,0,0,0,518,516,1,0,0,0,519,
  	521,5,11,0,0,520,519,1,0,0,0,521,524,1,0,0,0,522,520,1,0,0,0,522,523,
  	1,0,0,0,523,525,1,0,0,0,524,522,1,0,0,0,525,526,5,33,0,0,526,530,5,1,
  	0,0,527,529,5,11,0,0,528,527,1,0,0,0,529,532,1,0,0,0,530,528,1,0,0,0,
  	530,531,1,0,0,0,531,533,1,0,0,0,532,530,1,0,0,0,533,537,3,22,11,0,534,
  	536,5,11,0,0,535,534,1,0,0,0,536,539,1,0,0,0,537,535,1,0,0,0,537,538,
  	1,0,0,0,538,540,1,0,0,0,539,537,1,0,0,0,540,544,5,2,0,0,541,543,5,11,
  	0,0,542,541,1,0,0,0,543,546,1,0,0,0,544,542,1,0,0,0,544,545,1,0,0,0,545,
  	758,1,0,0,0,546,544,1,0,0,0,547,549,5,11,0,0,548,547,1,0,0,0,549,552,
  	1,0,0,0,550,548,1,0,0,0,550,551,1,0,0,0,551,553,1,0,0,0,552,550,1,0,0,
  	0,553,554,5,34,0,0,554,558,5,1,0,0,555,557,5,11,0,0,556,555,1,0,0,0,557,
  	560,1,0,0,0,558,556,1,0,0,0,558,559,1,0,0,0,559,561,1,0,0,0,560,558,1,
  	0,0,0,561,565,3,22,11,0,562,564,5,11,0,0,563,562,1,0,0,0,564,567,1,0,
  	0,0,565,563,1,0,0,0,565,566,1,0,0,0,566,568,1,0,0,0,567,565,1,0,0,0,568,
  	572,5,2,0,0,569,571,5,11,0,0,570,569,1,0,0,0,571,574,1,0,0,0,572,570,
  	1,0,0,0,572,573,1,0,0,0,573,758,1,0,0,0,574,572,1,0,0,0,575,577,5,11,
  	0,0,576,575,1,0,0,0,577,580,1,0,0,0,578,576,1,0,0,0,578,579,1,0,0,0,579,
  	581,1,0,0,0,580,578,1,0,0,0,581,582,5,36,0,0,582,586,5,1,0,0,583,585,
  	5,11,0,0,584,583,1,0,0,0,585,588,1,0,0,0,586,584,1,0,0,0,586,587,1,0,
  	0,0,587,589,1,0,0,0,588,586,1,0,0,0,589,593,3,22,11,0,590,592,5,11,0,
  	0,591,590,1,0,0,0,592,595,1,0,0,0,593,591,1,0,0,0,593,594,1,0,0,0,594,
  	596,1,0,0,0,595,593,1,0,0,0,596,600,5,2,0,0,597,599,5,11,0,0,598,597,
  	1,0,0,0,599,602,1,0,0,0,600,598,1,0,0,0,600,601,1,0,0,0,601,758,1,0,0,
  	0,602,600,1,0,0,0,603,605,5,11,0,0,604,603,1,0,0,0,605,608,1,0,0,0,606,
  	604,1,0,0,0,606,607,1,0,0,0,607,609,1,0,0,0,608,606,1,0,0,0,609,610,5,
  	37,0,0,610,614,5,1,0,0,611,613,5,11,0,0,612,611,1,0,0,0,613,616,1,0,0,
  	0,614,612,1,0,0,0,614,615,1,0,0,0,615,617,1,0,0,0,616,614,1,0,0,0,617,
  	621,3,22,11,0,618,620,5,11,0,0,619,618,1,0,0,0,620,623,1,0,0,0,621,619,
  	1,0,0,0,621,622,1,0,0,0,622,624,1,0,0,0,623,621,1,0,0,0,624,628,5,2,0,
  	0,625,627,5,11,0,0,626,625,1,0,0,0,627,630,1,0,0,0,628,626,1,0,0,0,628,
  	629,1,0,0,0,629,758,1,0,0,0,630,628,1,0,0,0,631,633,5,11,0,0,632,631,
  	1,0,0,0,633,636,1,0,0,0,634,632,1,0,0,0,634,635,1,0,0,0,635,637,1,0,0,
  	0,636,634,1,0,0,0,637,638,5,39,0,0,638,642,5,1,0,0,639,641,5,11,0,0,640,
  	639,1,0,0,0,641,644,1,0,0,0,642,640,1,0,0,0,642,643,1,0,0,0,643,645,1,
  	0,0,0,644,642,1,0,0,0,645,649,3,22,11,0,646,648,5,11,0,0,647,646,1,0,
  	0,0,648,651,1,0,0,0,649,647,1,0,0,0,649,650,1,0,0,0,650,652,1,0,0,0,651,
  	649,1,0,0,0,652,656,5,2,0,0,653,655,5,11,0,0,654,653,1,0,0,0,655,658,
  	1,0,0,0,656,654,1,0,0,0,656,657,1,0,0,0,657,758,1,0,0,0,658,656,1,0,0,
  	0,659,661,5,11,0,0,660,659,1,0,0,0,661,664,1,0,0,0,662,660,1,0,0,0,662,
  	663,1,0,0,0,663,665,1,0,0,0,664,662,1,0,0,0,665,666,5,38,0,0,666,670,
  	5,1,0,0,667,669,5,11,0,0,668,667,1,0,0,0,669,672,1,0,0,0,670,668,1,0,
  	0,0,670,671,1,0,0,0,671,673,1,0,0,0,672,670,1,0,0,0,673,677,3,22,11,0,
  	674,676,5,11,0,0,675,674,1,0,0,0,676,679,1,0,0,0,677,675,1,0,0,0,677,
  	678,1,0,0,0,678,680,1,0,0,0,679,677,1,0,0,0,680,684,5,2,0,0,681,683,5,
  	11,0,0,682,681,1,0,0,0,683,686,1,0,0,0,684,682,1,0,0,0,684,685,1,0,0,
  	0,685,758,1,0,0,0,686,684,1,0,0,0,687,689,5,11,0,0,688,687,1,0,0,0,689,
  	692,1,0,0,0,690,688,1,0,0,0,690,691,1,0,0,0,691,693,1,0,0,0,692,690,1,
  	0,0,0,693,694,5,40,0,0,694,698,5,1,0,0,695,697,5,11,0,0,696,695,1,0,0,
  	0,697,700,1,0,0,0,698,696,1,0,0,0,698,699,1,0,0,0,699,701,1,0,0,0,700,
  	698,1,0,0,0,701,705,3,22,11,0,702,704,5,11,0,0,703,702,1,0,0,0,704,707,
  	1,0,0,0,705,703,1,0,0,0,705,706,1,0,0,0,706,708,1,0,0,0,707,705,1,0,0,
  	0,708,712,5,2,0,0,709,711,5,11,0,0,710,709,1,0,0,0,711,714,1,0,0,0,712,
  	710,1,0,0,0,712,713,1,0,0,0,713,758,1,0,0,0,714,712,1,0,0,0,715,717,5,
  	11,0,0,716,715,1,0,0,0,717,720,1,0,0,0,718,716,1,0,0,0,718,719,1,0,0,
  	0,719,721,1,0,0,0,720,718,1,0,0,0,721,722,5,32,0,0,722,726,5,1,0,0,723,
  	725,5,11,0,0,724,723,1,0,0,0,725,728,1,0,0,0,726,724,1,0,0,0,726,727,
  	1,0,0,0,727,729,1,0,0,0,728,726,1,0,0,0,729,733,3,22,11,0,730,732,5,11,
  	0,0,731,730,1,0,0,0,732,735,1,0,0,0,733,731,1,0,0,0,733,734,1,0,0,0,734,
  	736,1,0,0,0,735,733,1,0,0,0,736,740,5,3,0,0,737,739,5,11,0,0,738,737,
  	1,0,0,0,739,742,1,0,0,0,740,738,1,0,0,0,740,741,1,0,0,0,741,743,1,0,0,
  	0,742,740,1,0,0,0,743,747,3,22,11,0,744,746,5,11,0,0,745,744,1,0,0,0,
  	746,749,1,0,0,0,747,745,1,0,0,0,747,748,1,0,0,0,748,750,1,0,0,0,749,747,
  	1,0,0,0,750,754,5,2,0,0,751,753,5,11,0,0,752,751,1,0,0,0,753,756,1,0,
  	0,0,754,752,1,0,0,0,754,755,1,0,0,0,755,758,1,0,0,0,756,754,1,0,0,0,757,
  	466,1,0,0,0,757,494,1,0,0,0,757,522,1,0,0,0,757,550,1,0,0,0,757,578,1,
  	0,0,0,757,606,1,0,0,0,757,634,1,0,0,0,757,662,1,0,0,0,757,690,1,0,0,0,
  	757,718,1,0,0,0,758,33,1,0,0,0,759,761,5,11,0,0,760,759,1,0,0,0,761,764,
  	1,0,0,0,762,760,1,0,0,0,762,763,1,0,0,0,763,765,1,0,0,0,764,762,1,0,0,
  	0,765,766,5,24,0,0,766,767,5,1,0,0,767,768,3,22,11,0,768,769,5,3,0,0,
  	769,774,3,22,11,0,770,771,5,3,0,0,771,773,3,22,11,0,772,770,1,0,0,0,773,
  	776,1,0,0,0,774,772,1,0,0,0,774,775,1,0,0,0,775,777,1,0,0,0,776,774,1,
  	0,0,0,777,778,5,2,0,0,778,820,1,0,0,0,779,781,5,11,0,0,780,779,1,0,0,
  	0,781,784,1,0,0,0,782,780,1,0,0,0,782,783,1,0,0,0,783,785,1,0,0,0,784,
  	782,1,0,0,0,785,786,5,26,0,0,786,787,5,1,0,0,787,788,3,22,11,0,788,789,
  	5,3,0,0,789,794,3,22,11,0,790,791,5,3,0,0,791,793,3,22,11,0,792,790,1,
  	0,0,0,793,796,1,0,0,0,794,792,1,0,0,0,794,795,1,0,0,0,795,797,1,0,0,0,
  	796,794,1,0,0,0,797,798,5,2,0,0,798,820,1,0,0,0,799,801,5,11,0,0,800,
  	799,1,0,0,0,801,804,1,0,0,0,802,800,1,0,0,0,802,803,1,0,0,0,803,805,1,
  	0,0,0,804,802,1,0,0,0,805,806,5,28,0,0,806,807,5,1,0,0,807,808,3,22,11,
  	0,808,809,5,3,0,0,809,814,3,22,11,0,810,811,5,3,0,0,811,813,3,22,11,0,
  	812,810,1,0,0,0,813,816,1,0,0,0,814,812,1,0,0,0,814,815,1,0,0,0,815,817,
  	1,0,0,0,816,814,1,0,0,0,817,818,5,2,0,0,818,820,1,0,0,0,819,762,1,0,0,
  	0,819,782,1,0,0,0,819,802,1,0,0,0,820,35,1,0,0,0,821,823,5,11,0,0,822,
  	821,1,0,0,0,823,826,1,0,0,0,824,822,1,0,0,0,824,825,1,0,0,0,825,827,1,
  	0,0,0,826,824,1,0,0,0,827,828,5,27,0,0,828,832,5,1,0,0,829,831,5,11,0,
  	0,830,829,1,0,0,0,831,834,1,0,0,0,832,830,1,0,0,0,832,833,1,0,0,0,833,
  	835,1,0,0,0,834,832,1,0,0,0,835,839,3,22,11,0,836,838,5,11,0,0,837,836,
  	1,0,0,0,838,841,1,0,0,0,839,837,1,0,0,0,839,840,1,0,0,0,840,842,1,0,0,
  	0,841,839,1,0,0,0,842,846,5,2,0,0,843,845,5,11,0,0,844,843,1,0,0,0,845,
  	848,1,0,0,0,846,844,1,0,0,0,846,847,1,0,0,0,847,878,1,0,0,0,848,846,1,
  	0,0,0,849,851,5,11,0,0,850,849,1,0,0,0,851,854,1,0,0,0,852,850,1,0,0,
  	0,852,853,1,0,0,0,853,855,1,0,0,0,854,852,1,0,0,0,855,856,5,29,0,0,856,
  	860,5,1,0,0,857,859,5,11,0,0,858,857,1,0,0,0,859,862,1,0,0,0,860,858,
  	1,0,0,0,860,861,1,0,0,0,861,863,1,0,0,0,862,860,1,0,0,0,863,867,3,22,
  	11,0,864,866,5,11,0,0,865,864,1,0,0,0,866,869,1,0,0,0,867,865,1,0,0,0,
  	867,868,1,0,0,0,868,870,1,0,0,0,869,867,1,0,0,0,870,874,5,2,0,0,871,873,
  	5,11,0,0,872,871,1,0,0,0,873,876,1,0,0,0,874,872,1,0,0,0,874,875,1,0,
  	0,0,875,878,1,0,0,0,876,874,1,0,0,0,877,824,1,0,0,0,877,852,1,0,0,0,878,
  	37,1,0,0,0,879,880,5,8,0,0,880,881,5,46,0,0,881,882,5,8,0,0,882,39,1,
  	0,0,0,129,43,50,53,57,62,69,77,84,92,99,106,112,118,126,129,134,141,149,
  	155,162,165,169,173,175,180,186,193,201,207,214,217,221,225,227,232,239,
  	243,248,256,263,271,277,284,287,293,300,303,308,315,322,329,336,343,350,
  	353,372,376,382,386,395,402,410,417,421,423,430,437,444,450,457,466,474,
  	481,488,494,502,509,516,522,530,537,544,550,558,565,572,578,586,593,600,
  	606,614,621,628,634,642,649,656,662,670,677,684,690,698,705,712,718,726,
  	733,740,747,754,757,762,774,782,794,802,814,819,824,832,839,846,852,860,
  	867,874,877
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
    setState(43);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(40);
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
        setState(41);
        expr(0);
        break;
      }

      case detect_type_functionParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(42);
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

//----------------- ComparatorContext ------------------------------------------------------------------

detect_type_functionParser::ComparatorContext::ComparatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::ComparatorContext::LARGER() {
  return getToken(detect_type_functionParser::LARGER, 0);
}

tree::TerminalNode* detect_type_functionParser::ComparatorContext::LARGER_EQUAL() {
  return getToken(detect_type_functionParser::LARGER_EQUAL, 0);
}

tree::TerminalNode* detect_type_functionParser::ComparatorContext::EQUAL() {
  return getToken(detect_type_functionParser::EQUAL, 0);
}

tree::TerminalNode* detect_type_functionParser::ComparatorContext::LESS() {
  return getToken(detect_type_functionParser::LESS, 0);
}

tree::TerminalNode* detect_type_functionParser::ComparatorContext::LESS_EQUAL() {
  return getToken(detect_type_functionParser::LESS_EQUAL, 0);
}


size_t detect_type_functionParser::ComparatorContext::getRuleIndex() const {
  return detect_type_functionParser::RuleComparator;
}

void detect_type_functionParser::ComparatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparator(this);
}

void detect_type_functionParser::ComparatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparator(this);
}

detect_type_functionParser::ComparatorContext* detect_type_functionParser::comparator() {
  ComparatorContext *_localctx = _tracker.createInstance<ComparatorContext>(_ctx, getState());
  enterRule(_localctx, 2, detect_type_functionParser::RuleComparator);
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
    setState(45);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 253952) != 0))) {
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
  enterRule(_localctx, 4, detect_type_functionParser::RuleInput);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3:
      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS: {
        enterOuterAlt(_localctx, 1);
        setState(48); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(47);
          line_input();
          setState(50); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2576) != 0));
        break;
      }

      case detect_type_functionParser::EOF: {
        enterOuterAlt(_localctx, 2);
        setState(52);
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

detect_type_functionParser::VardefinitionContext* detect_type_functionParser::Line_inputContext::vardefinition() {
  return getRuleContext<detect_type_functionParser::VardefinitionContext>(0);
}

detect_type_functionParser::ComparisionContext* detect_type_functionParser::Line_inputContext::comparision() {
  return getRuleContext<detect_type_functionParser::ComparisionContext>(0);
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
  enterRule(_localctx, 6, detect_type_functionParser::RuleLine_input);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(55);
      vardefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(56);
      comparision();
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
  enterRule(_localctx, 8, detect_type_functionParser::RuleNode_access);
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
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(59);
        match(detect_type_functionParser::WS);
        setState(64);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(65);
      match(detect_type_functionParser::T__0);
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(66);
        match(detect_type_functionParser::WS);
        setState(71);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(72);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      match(detect_type_functionParser::T__0);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(74);
        match(detect_type_functionParser::WS);
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
      match(detect_type_functionParser::UINT);
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(81);
        match(detect_type_functionParser::WS);
        setState(86);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(87);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(88);
      match(detect_type_functionParser::T__0);
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
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(96);
          match(detect_type_functionParser::WS); 
        }
        setState(101);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(102);
        match(detect_type_functionParser::T__2);
        setState(106);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == detect_type_functionParser::WS) {
          setState(103);
          match(detect_type_functionParser::WS);
          setState(108);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(109);
        match(detect_type_functionParser::UINT);
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(115);
        match(detect_type_functionParser::WS);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(121);
      match(detect_type_functionParser::T__1);
      setState(126);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(123);
          match(detect_type_functionParser::WS); 
        }
        setState(128);
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
  enterRule(_localctx, 10, detect_type_functionParser::RuleVariable);
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
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(131);
      match(detect_type_functionParser::WS);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3: {
        setState(137);
        match(detect_type_functionParser::T__3);
        setState(165);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
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
          match(detect_type_functionParser::DATABASE);
          setState(145);
          match(detect_type_functionParser::VARIABLE);
          setState(149);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(146);
            match(detect_type_functionParser::WS);
            setState(151);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(155);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(152);
            match(detect_type_functionParser::WS);
            setState(157);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(158);
          match(detect_type_functionParser::VARIABLE);
          setState(162);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(159);
            match(detect_type_functionParser::WS);
            setState(164);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(167);
        match(detect_type_functionParser::T__1);
        setState(169);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(168);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case detect_type_functionParser::VARIABLE: {
        setState(171);
        match(detect_type_functionParser::VARIABLE);
        setState(173);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(172);
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
    setState(180);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(177);
        match(detect_type_functionParser::WS); 
      }
      setState(182);
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

//----------------- VardefinitionContext ------------------------------------------------------------------

detect_type_functionParser::VardefinitionContext::VardefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* detect_type_functionParser::VardefinitionContext::EQUAL() {
  return getToken(detect_type_functionParser::EQUAL, 0);
}

tree::TerminalNode* detect_type_functionParser::VardefinitionContext::EOL() {
  return getToken(detect_type_functionParser::EOL, 0);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::VardefinitionContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::VardefinitionContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

detect_type_functionParser::Value_typeContext* detect_type_functionParser::VardefinitionContext::value_type() {
  return getRuleContext<detect_type_functionParser::Value_typeContext>(0);
}

tree::TerminalNode* detect_type_functionParser::VardefinitionContext::VARIABLE() {
  return getToken(detect_type_functionParser::VARIABLE, 0);
}

tree::TerminalNode* detect_type_functionParser::VardefinitionContext::DATABASE() {
  return getToken(detect_type_functionParser::DATABASE, 0);
}

detect_type_functionParser::Node_accessContext* detect_type_functionParser::VardefinitionContext::node_access() {
  return getRuleContext<detect_type_functionParser::Node_accessContext>(0);
}


size_t detect_type_functionParser::VardefinitionContext::getRuleIndex() const {
  return detect_type_functionParser::RuleVardefinition;
}

void detect_type_functionParser::VardefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardefinition(this);
}

void detect_type_functionParser::VardefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardefinition(this);
}

detect_type_functionParser::VardefinitionContext* detect_type_functionParser::vardefinition() {
  VardefinitionContext *_localctx = _tracker.createInstance<VardefinitionContext>(_ctx, getState());
  enterRule(_localctx, 12, detect_type_functionParser::RuleVardefinition);
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
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(183);
      match(detect_type_functionParser::WS);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3: {
        setState(189);
        match(detect_type_functionParser::T__3);
        setState(217);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          setState(193);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(190);
            match(detect_type_functionParser::WS);
            setState(195);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(196);
          match(detect_type_functionParser::DATABASE);
          setState(197);
          match(detect_type_functionParser::VARIABLE);
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
          break;
        }

        case 2: {
          setState(207);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(204);
            match(detect_type_functionParser::WS);
            setState(209);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(210);
          match(detect_type_functionParser::VARIABLE);
          setState(214);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(211);
            match(detect_type_functionParser::WS);
            setState(216);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(219);
        match(detect_type_functionParser::T__1);
        setState(221);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          setState(220);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case detect_type_functionParser::VARIABLE: {
        setState(223);
        match(detect_type_functionParser::VARIABLE);
        setState(225);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          setState(224);
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
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(229);
      match(detect_type_functionParser::WS);
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    match(detect_type_functionParser::EQUAL);
    setState(239);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(236);
        match(detect_type_functionParser::WS); 
      }
      setState(241);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(243);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(242);
      value_type();
      break;
    }

    default:
      break;
    }
    setState(248);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(245);
      match(detect_type_functionParser::WS);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(251);
    match(detect_type_functionParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisionContext ------------------------------------------------------------------

detect_type_functionParser::ComparisionContext::ComparisionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::Lhs_compContext* detect_type_functionParser::ComparisionContext::lhs_comp() {
  return getRuleContext<detect_type_functionParser::Lhs_compContext>(0);
}

detect_type_functionParser::ComparatorContext* detect_type_functionParser::ComparisionContext::comparator() {
  return getRuleContext<detect_type_functionParser::ComparatorContext>(0);
}

detect_type_functionParser::Rhs_compContext* detect_type_functionParser::ComparisionContext::rhs_comp() {
  return getRuleContext<detect_type_functionParser::Rhs_compContext>(0);
}

tree::TerminalNode* detect_type_functionParser::ComparisionContext::EOL() {
  return getToken(detect_type_functionParser::EOL, 0);
}

tree::TerminalNode* detect_type_functionParser::ComparisionContext::VARIABLE() {
  return getToken(detect_type_functionParser::VARIABLE, 0);
}

std::vector<tree::TerminalNode *> detect_type_functionParser::ComparisionContext::WS() {
  return getTokens(detect_type_functionParser::WS);
}

tree::TerminalNode* detect_type_functionParser::ComparisionContext::WS(size_t i) {
  return getToken(detect_type_functionParser::WS, i);
}

detect_type_functionParser::Expr_compContext* detect_type_functionParser::ComparisionContext::expr_comp() {
  return getRuleContext<detect_type_functionParser::Expr_compContext>(0);
}

tree::TerminalNode* detect_type_functionParser::ComparisionContext::DATABASE() {
  return getToken(detect_type_functionParser::DATABASE, 0);
}


size_t detect_type_functionParser::ComparisionContext::getRuleIndex() const {
  return detect_type_functionParser::RuleComparision;
}

void detect_type_functionParser::ComparisionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparision(this);
}

void detect_type_functionParser::ComparisionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparision(this);
}

detect_type_functionParser::ComparisionContext* detect_type_functionParser::comparision() {
  ComparisionContext *_localctx = _tracker.createInstance<ComparisionContext>(_ctx, getState());
  enterRule(_localctx, 14, detect_type_functionParser::RuleComparision);
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
    setState(256);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(253);
        match(detect_type_functionParser::WS); 
      }
      setState(258);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(303);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__3: {
        setState(259);
        match(detect_type_functionParser::T__3);
        setState(287);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          setState(263);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(260);
            match(detect_type_functionParser::WS);
            setState(265);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(266);
          match(detect_type_functionParser::DATABASE);
          setState(267);
          match(detect_type_functionParser::VARIABLE);
          setState(271);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(268);
            match(detect_type_functionParser::WS);
            setState(273);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
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
          match(detect_type_functionParser::VARIABLE);
          setState(284);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(281);
            match(detect_type_functionParser::WS);
            setState(286);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(289);
        match(detect_type_functionParser::T__1);
        break;
      }

      case detect_type_functionParser::VARIABLE:
      case detect_type_functionParser::WS: {
        setState(293);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == detect_type_functionParser::WS) {
          setState(290);
          match(detect_type_functionParser::WS);
          setState(295);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(296);
        match(detect_type_functionParser::VARIABLE);
        setState(300);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(297);
            match(detect_type_functionParser::WS); 
          }
          setState(302);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(305);
      match(detect_type_functionParser::WS);
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(311);
    match(detect_type_functionParser::T__4);
    setState(315);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(312);
        match(detect_type_functionParser::WS); 
      }
      setState(317);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
    setState(318);
    lhs_comp();
    setState(322);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(319);
      match(detect_type_functionParser::WS);
      setState(324);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(325);
    comparator();
    setState(329);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(326);
        match(detect_type_functionParser::WS); 
      }
      setState(331);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(332);
    rhs_comp();
    setState(336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(333);
      match(detect_type_functionParser::WS);
      setState(338);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == detect_type_functionParser::T__4) {
      setState(339);
      match(detect_type_functionParser::T__4);
      setState(343);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(340);
          match(detect_type_functionParser::WS); 
        }
        setState(345);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(346);
      expr_comp();
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(347);
        match(detect_type_functionParser::WS);
        setState(352);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(355);
    match(detect_type_functionParser::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lhs_compContext ------------------------------------------------------------------

detect_type_functionParser::Lhs_compContext::Lhs_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::ExprContext* detect_type_functionParser::Lhs_compContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}


size_t detect_type_functionParser::Lhs_compContext::getRuleIndex() const {
  return detect_type_functionParser::RuleLhs_comp;
}

void detect_type_functionParser::Lhs_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLhs_comp(this);
}

void detect_type_functionParser::Lhs_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLhs_comp(this);
}

detect_type_functionParser::Lhs_compContext* detect_type_functionParser::lhs_comp() {
  Lhs_compContext *_localctx = _tracker.createInstance<Lhs_compContext>(_ctx, getState());
  enterRule(_localctx, 16, detect_type_functionParser::RuleLhs_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rhs_compContext ------------------------------------------------------------------

detect_type_functionParser::Rhs_compContext::Rhs_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::ExprContext* detect_type_functionParser::Rhs_compContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}


size_t detect_type_functionParser::Rhs_compContext::getRuleIndex() const {
  return detect_type_functionParser::RuleRhs_comp;
}

void detect_type_functionParser::Rhs_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhs_comp(this);
}

void detect_type_functionParser::Rhs_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhs_comp(this);
}

detect_type_functionParser::Rhs_compContext* detect_type_functionParser::rhs_comp() {
  Rhs_compContext *_localctx = _tracker.createInstance<Rhs_compContext>(_ctx, getState());
  enterRule(_localctx, 18, detect_type_functionParser::RuleRhs_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_compContext ------------------------------------------------------------------

detect_type_functionParser::Expr_compContext::Expr_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

detect_type_functionParser::ExprContext* detect_type_functionParser::Expr_compContext::expr() {
  return getRuleContext<detect_type_functionParser::ExprContext>(0);
}


size_t detect_type_functionParser::Expr_compContext::getRuleIndex() const {
  return detect_type_functionParser::RuleExpr_comp;
}

void detect_type_functionParser::Expr_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_comp(this);
}

void detect_type_functionParser::Expr_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<detect_type_functionListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_comp(this);
}

detect_type_functionParser::Expr_compContext* detect_type_functionParser::expr_comp() {
  Expr_compContext *_localctx = _tracker.createInstance<Expr_compContext>(_ctx, getState());
  enterRule(_localctx, 20, detect_type_functionParser::RuleExpr_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    expr(0);
   
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, detect_type_functionParser::RuleExpr, precedence);

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
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(364);
      match(detect_type_functionParser::T__0);
      setState(365);
      expr(0);
      setState(366);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(368);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(372);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(369);
        function();
        break;
      }

      case 2: {
        setState(370);
        multiargfunction();
        break;
      }

      case 3: {
        setState(371);
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
      setState(376);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case detect_type_functionParser::UINT:
        case detect_type_functionParser::FLOAT: {
          setState(374);
          number();
          break;
        }

        case detect_type_functionParser::EXP:
        case detect_type_functionParser::PI: {
          setState(375);
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
      setState(378);
      _la = _input->LA(1);
      if (!(_la == detect_type_functionParser::ADD

      || _la == detect_type_functionParser::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(379);
          match(detect_type_functionParser::WS); 
        }
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(385);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(423);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(421);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(388);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(389);
          match(detect_type_functionParser::POW);
          setState(390);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(391);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(395);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(392);
            match(detect_type_functionParser::WS);
            setState(397);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(398);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::MUL

          || _la == detect_type_functionParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(402);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(399);
              match(detect_type_functionParser::WS); 
            }
            setState(404);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          }
          setState(405);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(406);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(410);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == detect_type_functionParser::WS) {
            setState(407);
            match(detect_type_functionParser::WS);
            setState(412);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(413);
          _la = _input->LA(1);
          if (!(_la == detect_type_functionParser::ADD

          || _la == detect_type_functionParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(417);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(414);
              match(detect_type_functionParser::WS); 
            }
            setState(419);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          }
          setState(420);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(425);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
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
  enterRule(_localctx, 24, detect_type_functionParser::RuleArray);
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
    setState(426);
    match(detect_type_functionParser::T__5);
    setState(430);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(427);
        match(detect_type_functionParser::WS); 
      }
      setState(432);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    }
    setState(433);
    input_array();
    setState(437);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::WS) {
      setState(434);
      match(detect_type_functionParser::WS);
      setState(439);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(450);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == detect_type_functionParser::T__2) {
      setState(440);
      match(detect_type_functionParser::T__2);
      setState(444);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(441);
          match(detect_type_functionParser::WS); 
        }
        setState(446);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(447);
      input_array();
      setState(452);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(453);
    match(detect_type_functionParser::T__6);
   
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
  enterRule(_localctx, 26, detect_type_functionParser::RuleInput_array);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(457);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case detect_type_functionParser::T__5: {
        _localctx = _tracker.createInstance<detect_type_functionParser::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(455);
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
        setState(456);
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
  enterRule(_localctx, 28, detect_type_functionParser::RuleNumber);
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
    setState(459);
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
  enterRule(_localctx, 30, detect_type_functionParser::RuleConstant);
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
    setState(461);
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
  enterRule(_localctx, 32, detect_type_functionParser::RuleFunction);
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
    setState(757);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(466);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(463);
        match(detect_type_functionParser::WS);
        setState(468);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(469);
      match(detect_type_functionParser::LN);
      setState(470);
      match(detect_type_functionParser::T__0);
      setState(474);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(471);
          match(detect_type_functionParser::WS); 
        }
        setState(476);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      setState(477);
      expr(0);
      setState(481);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(478);
        match(detect_type_functionParser::WS);
        setState(483);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(484);
      match(detect_type_functionParser::T__1);
      setState(488);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(485);
          match(detect_type_functionParser::WS); 
        }
        setState(490);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(494);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(491);
        match(detect_type_functionParser::WS);
        setState(496);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(497);
      match(detect_type_functionParser::LG);
      setState(498);
      match(detect_type_functionParser::T__0);
      setState(502);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(499);
          match(detect_type_functionParser::WS); 
        }
        setState(504);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      setState(505);
      expr(0);
      setState(509);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(506);
        match(detect_type_functionParser::WS);
        setState(511);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(512);
      match(detect_type_functionParser::T__1);
      setState(516);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(513);
          match(detect_type_functionParser::WS); 
        }
        setState(518);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(522);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(519);
        match(detect_type_functionParser::WS);
        setState(524);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(525);
      match(detect_type_functionParser::EXP);
      setState(526);
      match(detect_type_functionParser::T__0);
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(527);
          match(detect_type_functionParser::WS); 
        }
        setState(532);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
      setState(533);
      expr(0);
      setState(537);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(534);
        match(detect_type_functionParser::WS);
        setState(539);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(540);
      match(detect_type_functionParser::T__1);
      setState(544);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(541);
          match(detect_type_functionParser::WS); 
        }
        setState(546);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(550);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(547);
        match(detect_type_functionParser::WS);
        setState(552);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(553);
      match(detect_type_functionParser::SQRT);
      setState(554);
      match(detect_type_functionParser::T__0);
      setState(558);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(555);
          match(detect_type_functionParser::WS); 
        }
        setState(560);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      }
      setState(561);
      expr(0);
      setState(565);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(562);
        match(detect_type_functionParser::WS);
        setState(567);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(568);
      match(detect_type_functionParser::T__1);
      setState(572);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(569);
          match(detect_type_functionParser::WS); 
        }
        setState(574);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
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
      match(detect_type_functionParser::COS);
      setState(582);
      match(detect_type_functionParser::T__0);
      setState(586);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(583);
          match(detect_type_functionParser::WS); 
        }
        setState(588);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      }
      setState(589);
      expr(0);
      setState(593);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(590);
        match(detect_type_functionParser::WS);
        setState(595);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(596);
      match(detect_type_functionParser::T__1);
      setState(600);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(597);
          match(detect_type_functionParser::WS); 
        }
        setState(602);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(606);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(603);
        match(detect_type_functionParser::WS);
        setState(608);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(609);
      match(detect_type_functionParser::SIN);
      setState(610);
      match(detect_type_functionParser::T__0);
      setState(614);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(611);
          match(detect_type_functionParser::WS); 
        }
        setState(616);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(617);
      expr(0);
      setState(621);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(618);
        match(detect_type_functionParser::WS);
        setState(623);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(624);
      match(detect_type_functionParser::T__1);
      setState(628);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(625);
          match(detect_type_functionParser::WS); 
        }
        setState(630);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(634);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(631);
        match(detect_type_functionParser::WS);
        setState(636);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(637);
      match(detect_type_functionParser::ACOS);
      setState(638);
      match(detect_type_functionParser::T__0);
      setState(642);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(639);
          match(detect_type_functionParser::WS); 
        }
        setState(644);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
      setState(645);
      expr(0);
      setState(649);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(646);
        match(detect_type_functionParser::WS);
        setState(651);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(652);
      match(detect_type_functionParser::T__1);
      setState(656);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(653);
          match(detect_type_functionParser::WS); 
        }
        setState(658);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(662);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(659);
        match(detect_type_functionParser::WS);
        setState(664);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(665);
      match(detect_type_functionParser::ASIN);
      setState(666);
      match(detect_type_functionParser::T__0);
      setState(670);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(667);
          match(detect_type_functionParser::WS); 
        }
        setState(672);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      }
      setState(673);
      expr(0);
      setState(677);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(674);
        match(detect_type_functionParser::WS);
        setState(679);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(680);
      match(detect_type_functionParser::T__1);
      setState(684);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(681);
          match(detect_type_functionParser::WS); 
        }
        setState(686);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(690);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(687);
        match(detect_type_functionParser::WS);
        setState(692);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(693);
      match(detect_type_functionParser::FACTORIAL);
      setState(694);
      match(detect_type_functionParser::T__0);
      setState(698);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(695);
          match(detect_type_functionParser::WS); 
        }
        setState(700);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      }
      setState(701);
      expr(0);
      setState(705);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(702);
        match(detect_type_functionParser::WS);
        setState(707);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(708);
      match(detect_type_functionParser::T__1);
      setState(712);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(709);
          match(detect_type_functionParser::WS); 
        }
        setState(714);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(718);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(715);
        match(detect_type_functionParser::WS);
        setState(720);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(721);
      match(detect_type_functionParser::LOG_X);
      setState(722);
      match(detect_type_functionParser::T__0);
      setState(726);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(723);
          match(detect_type_functionParser::WS); 
        }
        setState(728);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      }
      setState(729);
      expr(0);
      setState(733);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(730);
        match(detect_type_functionParser::WS);
        setState(735);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(736);
      match(detect_type_functionParser::T__2);
      setState(740);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(737);
          match(detect_type_functionParser::WS); 
        }
        setState(742);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      }
      setState(743);
      expr(0);
      setState(747);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(744);
        match(detect_type_functionParser::WS);
        setState(749);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(750);
      match(detect_type_functionParser::T__1);
      setState(754);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(751);
          match(detect_type_functionParser::WS); 
        }
        setState(756);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
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
  enterRule(_localctx, 34, detect_type_functionParser::RuleMultiargfunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(819);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(762);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(759);
        match(detect_type_functionParser::WS);
        setState(764);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(765);
      match(detect_type_functionParser::SUMPRODUCT);
      setState(766);
      match(detect_type_functionParser::T__0);
      setState(767);
      expr(0);
      setState(768);
      match(detect_type_functionParser::T__2);
      setState(769);
      expr(0);
      setState(774);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(770);
        match(detect_type_functionParser::T__2);
        setState(771);
        expr(0);
        setState(776);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(777);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(782);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(779);
        match(detect_type_functionParser::WS);
        setState(784);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(785);
      match(detect_type_functionParser::SUM);
      setState(786);
      match(detect_type_functionParser::T__0);
      setState(787);
      expr(0);
      setState(788);
      match(detect_type_functionParser::T__2);
      setState(789);
      expr(0);
      setState(794);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(790);
        match(detect_type_functionParser::T__2);
        setState(791);
        expr(0);
        setState(796);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(797);
      match(detect_type_functionParser::T__1);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(802);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(799);
        match(detect_type_functionParser::WS);
        setState(804);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(805);
      match(detect_type_functionParser::PRODUCT);
      setState(806);
      match(detect_type_functionParser::T__0);
      setState(807);
      expr(0);
      setState(808);
      match(detect_type_functionParser::T__2);
      setState(809);
      expr(0);
      setState(814);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::T__2) {
        setState(810);
        match(detect_type_functionParser::T__2);
        setState(811);
        expr(0);
        setState(816);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(817);
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
  enterRule(_localctx, 36, detect_type_functionParser::RuleRangefunction);
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
    setState(877);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(824);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(821);
        match(detect_type_functionParser::WS);
        setState(826);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(827);
      match(detect_type_functionParser::SUM_I);
      setState(828);
      match(detect_type_functionParser::T__0);
      setState(832);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(829);
          match(detect_type_functionParser::WS); 
        }
        setState(834);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      }
      setState(835);
      expr(0);
      setState(839);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(836);
        match(detect_type_functionParser::WS);
        setState(841);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(842);
      match(detect_type_functionParser::T__1);
      setState(846);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(843);
          match(detect_type_functionParser::WS); 
        }
        setState(848);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(852);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(849);
        match(detect_type_functionParser::WS);
        setState(854);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(855);
      match(detect_type_functionParser::PRODUCT_I);
      setState(856);
      match(detect_type_functionParser::T__0);
      setState(860);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(857);
          match(detect_type_functionParser::WS); 
        }
        setState(862);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      }
      setState(863);
      expr(0);
      setState(867);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == detect_type_functionParser::WS) {
        setState(864);
        match(detect_type_functionParser::WS);
        setState(869);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(870);
      match(detect_type_functionParser::T__1);
      setState(874);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(871);
          match(detect_type_functionParser::WS); 
        }
        setState(876);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
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
  enterRule(_localctx, 38, detect_type_functionParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(879);
    match(detect_type_functionParser::T__7);
    setState(880);
    match(detect_type_functionParser::STRING);
    setState(881);
    match(detect_type_functionParser::T__7);
   
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
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
