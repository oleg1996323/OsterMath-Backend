
// Generated from /home/oster/Electrolisys/grammar/head_interactor.g4 by ANTLR 4.13.1


#include "head_interactorListener.h"

#include "head_interactor.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Head_interactorStaticData final {
  Head_interactorStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Head_interactorStaticData(const Head_interactorStaticData&) = delete;
  Head_interactorStaticData(Head_interactorStaticData&&) = delete;
  Head_interactorStaticData& operator=(const Head_interactorStaticData&) = delete;
  Head_interactorStaticData& operator=(Head_interactorStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag head_interactorParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
Head_interactorStaticData *head_interactorParserStaticData = nullptr;

void head_interactorParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (head_interactorParserStaticData != nullptr) {
    return;
  }
#else
  assert(head_interactorParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Head_interactorStaticData>(
    std::vector<std::string>{
      "value_type", "comparator", "input", "line_input", "node_access", 
      "variable", "vardefinition", "comparision", "lhs_comp", "rhs_comp", 
      "expr_comp", "expr", "array", "input_array", "number", "constant", 
      "function", "multiargfunction", "rangefunction", "string"
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
  	4,1,46,887,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,3,0,
  	44,8,0,1,1,1,1,1,2,4,2,49,8,2,11,2,12,2,50,1,2,3,2,54,8,2,1,3,1,3,3,3,
  	58,8,3,1,4,5,4,61,8,4,10,4,12,4,64,9,4,1,4,1,4,5,4,68,8,4,10,4,12,4,71,
  	9,4,1,4,1,4,1,4,5,4,76,8,4,10,4,12,4,79,9,4,1,4,1,4,5,4,83,8,4,10,4,12,
  	4,86,9,4,1,4,1,4,1,4,5,4,91,8,4,10,4,12,4,94,9,4,1,4,1,4,5,4,98,8,4,10,
  	4,12,4,101,9,4,1,4,1,4,5,4,105,8,4,10,4,12,4,108,9,4,1,4,5,4,111,8,4,
  	10,4,12,4,114,9,4,1,4,5,4,117,8,4,10,4,12,4,120,9,4,1,4,1,4,1,4,5,4,125,
  	8,4,10,4,12,4,128,9,4,3,4,130,8,4,1,5,5,5,133,8,5,10,5,12,5,136,9,5,1,
  	5,1,5,1,5,5,5,141,8,5,10,5,12,5,144,9,5,1,5,1,5,1,5,5,5,149,8,5,10,5,
  	12,5,152,9,5,1,5,5,5,155,8,5,10,5,12,5,158,9,5,1,5,1,5,5,5,162,8,5,10,
  	5,12,5,165,9,5,3,5,167,8,5,1,5,1,5,3,5,171,8,5,1,5,1,5,3,5,175,8,5,3,
  	5,177,8,5,1,5,5,5,180,8,5,10,5,12,5,183,9,5,1,6,5,6,186,8,6,10,6,12,6,
  	189,9,6,1,6,1,6,1,6,5,6,194,8,6,10,6,12,6,197,9,6,1,6,1,6,1,6,5,6,202,
  	8,6,10,6,12,6,205,9,6,1,6,5,6,208,8,6,10,6,12,6,211,9,6,1,6,1,6,5,6,215,
  	8,6,10,6,12,6,218,9,6,3,6,220,8,6,1,6,1,6,3,6,224,8,6,1,6,1,6,3,6,228,
  	8,6,3,6,230,8,6,1,6,5,6,233,8,6,10,6,12,6,236,9,6,1,6,1,6,5,6,240,8,6,
  	10,6,12,6,243,9,6,1,6,3,6,246,8,6,1,6,5,6,249,8,6,10,6,12,6,252,9,6,1,
  	6,1,6,1,7,5,7,257,8,7,10,7,12,7,260,9,7,1,7,1,7,1,7,5,7,265,8,7,10,7,
  	12,7,268,9,7,1,7,1,7,1,7,5,7,273,8,7,10,7,12,7,276,9,7,1,7,5,7,279,8,
  	7,10,7,12,7,282,9,7,1,7,1,7,5,7,286,8,7,10,7,12,7,289,9,7,3,7,291,8,7,
  	1,7,1,7,5,7,295,8,7,10,7,12,7,298,9,7,1,7,1,7,5,7,302,8,7,10,7,12,7,305,
  	9,7,3,7,307,8,7,1,7,5,7,310,8,7,10,7,12,7,313,9,7,1,7,1,7,5,7,317,8,7,
  	10,7,12,7,320,9,7,1,7,1,7,5,7,324,8,7,10,7,12,7,327,9,7,1,7,1,7,5,7,331,
  	8,7,10,7,12,7,334,9,7,1,7,1,7,5,7,338,8,7,10,7,12,7,341,9,7,1,7,1,7,5,
  	7,345,8,7,10,7,12,7,348,9,7,1,7,1,7,5,7,352,8,7,10,7,12,7,355,9,7,3,7,
  	357,8,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,3,11,376,8,11,1,11,1,11,3,11,380,8,11,1,11,1,11,5,11,
  	384,8,11,10,11,12,11,387,9,11,1,11,3,11,390,8,11,1,11,1,11,1,11,1,11,
  	1,11,5,11,397,8,11,10,11,12,11,400,9,11,1,11,1,11,5,11,404,8,11,10,11,
  	12,11,407,9,11,1,11,1,11,1,11,5,11,412,8,11,10,11,12,11,415,9,11,1,11,
  	1,11,5,11,419,8,11,10,11,12,11,422,9,11,1,11,5,11,425,8,11,10,11,12,11,
  	428,9,11,1,12,1,12,5,12,432,8,12,10,12,12,12,435,9,12,1,12,1,12,5,12,
  	439,8,12,10,12,12,12,442,9,12,1,12,1,12,5,12,446,8,12,10,12,12,12,449,
  	9,12,1,12,5,12,452,8,12,10,12,12,12,455,9,12,1,12,1,12,1,13,1,13,3,13,
  	461,8,13,1,14,1,14,1,15,1,15,1,16,5,16,468,8,16,10,16,12,16,471,9,16,
  	1,16,1,16,1,16,5,16,476,8,16,10,16,12,16,479,9,16,1,16,1,16,5,16,483,
  	8,16,10,16,12,16,486,9,16,1,16,1,16,5,16,490,8,16,10,16,12,16,493,9,16,
  	1,16,5,16,496,8,16,10,16,12,16,499,9,16,1,16,1,16,1,16,5,16,504,8,16,
  	10,16,12,16,507,9,16,1,16,1,16,5,16,511,8,16,10,16,12,16,514,9,16,1,16,
  	1,16,5,16,518,8,16,10,16,12,16,521,9,16,1,16,5,16,524,8,16,10,16,12,16,
  	527,9,16,1,16,1,16,1,16,5,16,532,8,16,10,16,12,16,535,9,16,1,16,1,16,
  	5,16,539,8,16,10,16,12,16,542,9,16,1,16,1,16,5,16,546,8,16,10,16,12,16,
  	549,9,16,1,16,5,16,552,8,16,10,16,12,16,555,9,16,1,16,1,16,1,16,5,16,
  	560,8,16,10,16,12,16,563,9,16,1,16,1,16,5,16,567,8,16,10,16,12,16,570,
  	9,16,1,16,1,16,5,16,574,8,16,10,16,12,16,577,9,16,1,16,5,16,580,8,16,
  	10,16,12,16,583,9,16,1,16,1,16,1,16,5,16,588,8,16,10,16,12,16,591,9,16,
  	1,16,1,16,5,16,595,8,16,10,16,12,16,598,9,16,1,16,1,16,5,16,602,8,16,
  	10,16,12,16,605,9,16,1,16,5,16,608,8,16,10,16,12,16,611,9,16,1,16,1,16,
  	1,16,5,16,616,8,16,10,16,12,16,619,9,16,1,16,1,16,5,16,623,8,16,10,16,
  	12,16,626,9,16,1,16,1,16,5,16,630,8,16,10,16,12,16,633,9,16,1,16,5,16,
  	636,8,16,10,16,12,16,639,9,16,1,16,1,16,1,16,5,16,644,8,16,10,16,12,16,
  	647,9,16,1,16,1,16,5,16,651,8,16,10,16,12,16,654,9,16,1,16,1,16,5,16,
  	658,8,16,10,16,12,16,661,9,16,1,16,5,16,664,8,16,10,16,12,16,667,9,16,
  	1,16,1,16,1,16,5,16,672,8,16,10,16,12,16,675,9,16,1,16,1,16,5,16,679,
  	8,16,10,16,12,16,682,9,16,1,16,1,16,5,16,686,8,16,10,16,12,16,689,9,16,
  	1,16,5,16,692,8,16,10,16,12,16,695,9,16,1,16,1,16,1,16,5,16,700,8,16,
  	10,16,12,16,703,9,16,1,16,1,16,5,16,707,8,16,10,16,12,16,710,9,16,1,16,
  	1,16,5,16,714,8,16,10,16,12,16,717,9,16,1,16,5,16,720,8,16,10,16,12,16,
  	723,9,16,1,16,1,16,1,16,5,16,728,8,16,10,16,12,16,731,9,16,1,16,1,16,
  	5,16,735,8,16,10,16,12,16,738,9,16,1,16,1,16,5,16,742,8,16,10,16,12,16,
  	745,9,16,1,16,1,16,5,16,749,8,16,10,16,12,16,752,9,16,1,16,1,16,5,16,
  	756,8,16,10,16,12,16,759,9,16,3,16,761,8,16,1,17,5,17,764,8,17,10,17,
  	12,17,767,9,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,776,8,17,10,17,
  	12,17,779,9,17,1,17,1,17,1,17,5,17,784,8,17,10,17,12,17,787,9,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,5,17,796,8,17,10,17,12,17,799,9,17,1,17,
  	1,17,1,17,5,17,804,8,17,10,17,12,17,807,9,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,816,8,17,10,17,12,17,819,9,17,1,17,1,17,3,17,823,8,17,
  	1,18,5,18,826,8,18,10,18,12,18,829,9,18,1,18,1,18,1,18,5,18,834,8,18,
  	10,18,12,18,837,9,18,1,18,1,18,5,18,841,8,18,10,18,12,18,844,9,18,1,18,
  	1,18,5,18,848,8,18,10,18,12,18,851,9,18,1,18,5,18,854,8,18,10,18,12,18,
  	857,9,18,1,18,1,18,1,18,5,18,862,8,18,10,18,12,18,865,9,18,1,18,1,18,
  	5,18,869,8,18,10,18,12,18,872,9,18,1,18,1,18,5,18,876,8,18,10,18,12,18,
  	879,9,18,3,18,881,8,18,1,19,1,19,1,19,1,19,1,19,0,1,22,20,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,5,1,0,7,11,1,0,37,38,1,0,
  	39,40,2,0,32,32,45,45,2,0,21,21,23,23,1011,0,43,1,0,0,0,2,45,1,0,0,0,
  	4,53,1,0,0,0,6,57,1,0,0,0,8,129,1,0,0,0,10,134,1,0,0,0,12,187,1,0,0,0,
  	14,258,1,0,0,0,16,360,1,0,0,0,18,362,1,0,0,0,20,364,1,0,0,0,22,389,1,
  	0,0,0,24,429,1,0,0,0,26,460,1,0,0,0,28,462,1,0,0,0,30,464,1,0,0,0,32,
  	760,1,0,0,0,34,822,1,0,0,0,36,880,1,0,0,0,38,882,1,0,0,0,40,44,3,24,12,
  	0,41,44,3,22,11,0,42,44,3,38,19,0,43,40,1,0,0,0,43,41,1,0,0,0,43,42,1,
  	0,0,0,44,1,1,0,0,0,45,46,7,0,0,0,46,3,1,0,0,0,47,49,3,6,3,0,48,47,1,0,
  	0,0,49,50,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,54,1,0,0,0,52,54,5,0,
  	0,1,53,48,1,0,0,0,53,52,1,0,0,0,54,5,1,0,0,0,55,58,3,12,6,0,56,58,3,14,
  	7,0,57,55,1,0,0,0,57,56,1,0,0,0,58,7,1,0,0,0,59,61,5,30,0,0,60,59,1,0,
  	0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,
  	0,0,65,69,5,33,0,0,66,68,5,30,0,0,67,66,1,0,0,0,68,71,1,0,0,0,69,67,1,
  	0,0,0,69,70,1,0,0,0,70,72,1,0,0,0,71,69,1,0,0,0,72,130,5,34,0,0,73,77,
  	5,33,0,0,74,76,5,30,0,0,75,74,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,
  	78,1,0,0,0,78,80,1,0,0,0,79,77,1,0,0,0,80,84,5,32,0,0,81,83,5,30,0,0,
  	82,81,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,87,1,0,0,0,
  	86,84,1,0,0,0,87,130,5,34,0,0,88,92,5,33,0,0,89,91,5,30,0,0,90,89,1,0,
  	0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,95,1,0,0,0,94,92,1,0,
  	0,0,95,99,5,32,0,0,96,98,5,30,0,0,97,96,1,0,0,0,98,101,1,0,0,0,99,97,
  	1,0,0,0,99,100,1,0,0,0,100,112,1,0,0,0,101,99,1,0,0,0,102,106,5,36,0,
  	0,103,105,5,30,0,0,104,103,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,
  	107,1,0,0,0,107,109,1,0,0,0,108,106,1,0,0,0,109,111,5,32,0,0,110,102,
  	1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,118,1,0,0,
  	0,114,112,1,0,0,0,115,117,5,30,0,0,116,115,1,0,0,0,117,120,1,0,0,0,118,
  	116,1,0,0,0,118,119,1,0,0,0,119,121,1,0,0,0,120,118,1,0,0,0,121,122,5,
  	34,0,0,122,126,1,0,0,0,123,125,5,30,0,0,124,123,1,0,0,0,125,128,1,0,0,
  	0,126,124,1,0,0,0,126,127,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,129,
  	62,1,0,0,0,129,73,1,0,0,0,129,88,1,0,0,0,130,9,1,0,0,0,131,133,5,30,0,
  	0,132,131,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,
  	176,1,0,0,0,136,134,1,0,0,0,137,138,5,1,0,0,138,166,5,33,0,0,139,141,
  	5,30,0,0,140,139,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,
  	0,0,143,145,1,0,0,0,144,142,1,0,0,0,145,146,5,6,0,0,146,150,5,5,0,0,147,
  	149,5,30,0,0,148,147,1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,
  	1,0,0,0,151,167,1,0,0,0,152,150,1,0,0,0,153,155,5,30,0,0,154,153,1,0,
  	0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,159,1,0,0,0,158,
  	156,1,0,0,0,159,163,5,5,0,0,160,162,5,30,0,0,161,160,1,0,0,0,162,165,
  	1,0,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,
  	0,166,142,1,0,0,0,166,156,1,0,0,0,167,168,1,0,0,0,168,170,5,34,0,0,169,
  	171,3,8,4,0,170,169,1,0,0,0,170,171,1,0,0,0,171,177,1,0,0,0,172,174,5,
  	5,0,0,173,175,3,8,4,0,174,173,1,0,0,0,174,175,1,0,0,0,175,177,1,0,0,0,
  	176,137,1,0,0,0,176,172,1,0,0,0,177,181,1,0,0,0,178,180,5,30,0,0,179,
  	178,1,0,0,0,180,183,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,0,182,11,1,
  	0,0,0,183,181,1,0,0,0,184,186,5,30,0,0,185,184,1,0,0,0,186,189,1,0,0,
  	0,187,185,1,0,0,0,187,188,1,0,0,0,188,229,1,0,0,0,189,187,1,0,0,0,190,
  	191,5,1,0,0,191,219,5,33,0,0,192,194,5,30,0,0,193,192,1,0,0,0,194,197,
  	1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,195,1,0,0,
  	0,198,199,5,6,0,0,199,203,5,5,0,0,200,202,5,30,0,0,201,200,1,0,0,0,202,
  	205,1,0,0,0,203,201,1,0,0,0,203,204,1,0,0,0,204,220,1,0,0,0,205,203,1,
  	0,0,0,206,208,5,30,0,0,207,206,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,
  	0,209,210,1,0,0,0,210,212,1,0,0,0,211,209,1,0,0,0,212,216,5,5,0,0,213,
  	215,5,30,0,0,214,213,1,0,0,0,215,218,1,0,0,0,216,214,1,0,0,0,216,217,
  	1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,0,219,195,1,0,0,0,219,209,1,0,0,
  	0,220,221,1,0,0,0,221,223,5,34,0,0,222,224,3,8,4,0,223,222,1,0,0,0,223,
  	224,1,0,0,0,224,230,1,0,0,0,225,227,5,5,0,0,226,228,3,8,4,0,227,226,1,
  	0,0,0,227,228,1,0,0,0,228,230,1,0,0,0,229,190,1,0,0,0,229,225,1,0,0,0,
  	230,234,1,0,0,0,231,233,5,30,0,0,232,231,1,0,0,0,233,236,1,0,0,0,234,
  	232,1,0,0,0,234,235,1,0,0,0,235,237,1,0,0,0,236,234,1,0,0,0,237,241,5,
  	9,0,0,238,240,5,30,0,0,239,238,1,0,0,0,240,243,1,0,0,0,241,239,1,0,0,
  	0,241,242,1,0,0,0,242,245,1,0,0,0,243,241,1,0,0,0,244,246,3,0,0,0,245,
  	244,1,0,0,0,245,246,1,0,0,0,246,250,1,0,0,0,247,249,5,30,0,0,248,247,
  	1,0,0,0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,1,0,0,
  	0,252,250,1,0,0,0,253,254,5,31,0,0,254,13,1,0,0,0,255,257,5,30,0,0,256,
  	255,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,258,259,1,0,0,0,259,306,1,
  	0,0,0,260,258,1,0,0,0,261,262,5,1,0,0,262,290,5,33,0,0,263,265,5,30,0,
  	0,264,263,1,0,0,0,265,268,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,
  	269,1,0,0,0,268,266,1,0,0,0,269,270,5,6,0,0,270,274,5,5,0,0,271,273,5,
  	30,0,0,272,271,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,
  	0,275,291,1,0,0,0,276,274,1,0,0,0,277,279,5,30,0,0,278,277,1,0,0,0,279,
  	282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,283,1,0,0,0,282,280,1,
  	0,0,0,283,287,5,5,0,0,284,286,5,30,0,0,285,284,1,0,0,0,286,289,1,0,0,
  	0,287,285,1,0,0,0,287,288,1,0,0,0,288,291,1,0,0,0,289,287,1,0,0,0,290,
  	266,1,0,0,0,290,280,1,0,0,0,291,292,1,0,0,0,292,307,5,34,0,0,293,295,
  	5,30,0,0,294,293,1,0,0,0,295,298,1,0,0,0,296,294,1,0,0,0,296,297,1,0,
  	0,0,297,299,1,0,0,0,298,296,1,0,0,0,299,303,5,5,0,0,300,302,5,30,0,0,
  	301,300,1,0,0,0,302,305,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,0,304,307,
  	1,0,0,0,305,303,1,0,0,0,306,261,1,0,0,0,306,296,1,0,0,0,307,311,1,0,0,
  	0,308,310,5,30,0,0,309,308,1,0,0,0,310,313,1,0,0,0,311,309,1,0,0,0,311,
  	312,1,0,0,0,312,314,1,0,0,0,313,311,1,0,0,0,314,318,5,35,0,0,315,317,
  	5,30,0,0,316,315,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,0,318,319,1,0,
  	0,0,319,321,1,0,0,0,320,318,1,0,0,0,321,325,3,16,8,0,322,324,5,30,0,0,
  	323,322,1,0,0,0,324,327,1,0,0,0,325,323,1,0,0,0,325,326,1,0,0,0,326,328,
  	1,0,0,0,327,325,1,0,0,0,328,332,3,2,1,0,329,331,5,30,0,0,330,329,1,0,
  	0,0,331,334,1,0,0,0,332,330,1,0,0,0,332,333,1,0,0,0,333,335,1,0,0,0,334,
  	332,1,0,0,0,335,339,3,18,9,0,336,338,5,30,0,0,337,336,1,0,0,0,338,341,
  	1,0,0,0,339,337,1,0,0,0,339,340,1,0,0,0,340,356,1,0,0,0,341,339,1,0,0,
  	0,342,346,5,35,0,0,343,345,5,30,0,0,344,343,1,0,0,0,345,348,1,0,0,0,346,
  	344,1,0,0,0,346,347,1,0,0,0,347,349,1,0,0,0,348,346,1,0,0,0,349,353,3,
  	20,10,0,350,352,5,30,0,0,351,350,1,0,0,0,352,355,1,0,0,0,353,351,1,0,
  	0,0,353,354,1,0,0,0,354,357,1,0,0,0,355,353,1,0,0,0,356,342,1,0,0,0,356,
  	357,1,0,0,0,357,358,1,0,0,0,358,359,5,31,0,0,359,15,1,0,0,0,360,361,3,
  	22,11,0,361,17,1,0,0,0,362,363,3,22,11,0,363,19,1,0,0,0,364,365,3,22,
  	11,0,365,21,1,0,0,0,366,367,6,11,-1,0,367,368,5,33,0,0,368,369,3,22,11,
  	0,369,370,5,34,0,0,370,390,1,0,0,0,371,390,3,10,5,0,372,376,3,32,16,0,
  	373,376,3,34,17,0,374,376,3,36,18,0,375,372,1,0,0,0,375,373,1,0,0,0,375,
  	374,1,0,0,0,376,390,1,0,0,0,377,380,3,28,14,0,378,380,3,30,15,0,379,377,
  	1,0,0,0,379,378,1,0,0,0,380,390,1,0,0,0,381,385,7,1,0,0,382,384,5,30,
  	0,0,383,382,1,0,0,0,384,387,1,0,0,0,385,383,1,0,0,0,385,386,1,0,0,0,386,
  	388,1,0,0,0,387,385,1,0,0,0,388,390,3,22,11,4,389,366,1,0,0,0,389,371,
  	1,0,0,0,389,375,1,0,0,0,389,379,1,0,0,0,389,381,1,0,0,0,390,426,1,0,0,
  	0,391,392,10,3,0,0,392,393,5,41,0,0,393,425,3,22,11,4,394,398,10,2,0,
  	0,395,397,5,30,0,0,396,395,1,0,0,0,397,400,1,0,0,0,398,396,1,0,0,0,398,
  	399,1,0,0,0,399,401,1,0,0,0,400,398,1,0,0,0,401,405,7,2,0,0,402,404,5,
  	30,0,0,403,402,1,0,0,0,404,407,1,0,0,0,405,403,1,0,0,0,405,406,1,0,0,
  	0,406,408,1,0,0,0,407,405,1,0,0,0,408,425,3,22,11,3,409,413,10,1,0,0,
  	410,412,5,30,0,0,411,410,1,0,0,0,412,415,1,0,0,0,413,411,1,0,0,0,413,
  	414,1,0,0,0,414,416,1,0,0,0,415,413,1,0,0,0,416,420,7,1,0,0,417,419,5,
  	30,0,0,418,417,1,0,0,0,419,422,1,0,0,0,420,418,1,0,0,0,420,421,1,0,0,
  	0,421,423,1,0,0,0,422,420,1,0,0,0,423,425,3,22,11,2,424,391,1,0,0,0,424,
  	394,1,0,0,0,424,409,1,0,0,0,425,428,1,0,0,0,426,424,1,0,0,0,426,427,1,
  	0,0,0,427,23,1,0,0,0,428,426,1,0,0,0,429,433,5,2,0,0,430,432,5,30,0,0,
  	431,430,1,0,0,0,432,435,1,0,0,0,433,431,1,0,0,0,433,434,1,0,0,0,434,436,
  	1,0,0,0,435,433,1,0,0,0,436,440,3,26,13,0,437,439,5,30,0,0,438,437,1,
  	0,0,0,439,442,1,0,0,0,440,438,1,0,0,0,440,441,1,0,0,0,441,453,1,0,0,0,
  	442,440,1,0,0,0,443,447,5,36,0,0,444,446,5,30,0,0,445,444,1,0,0,0,446,
  	449,1,0,0,0,447,445,1,0,0,0,447,448,1,0,0,0,448,450,1,0,0,0,449,447,1,
  	0,0,0,450,452,3,26,13,0,451,443,1,0,0,0,452,455,1,0,0,0,453,451,1,0,0,
  	0,453,454,1,0,0,0,454,456,1,0,0,0,455,453,1,0,0,0,456,457,5,3,0,0,457,
  	25,1,0,0,0,458,461,3,24,12,0,459,461,3,22,11,0,460,458,1,0,0,0,460,459,
  	1,0,0,0,461,27,1,0,0,0,462,463,7,3,0,0,463,29,1,0,0,0,464,465,7,4,0,0,
  	465,31,1,0,0,0,466,468,5,30,0,0,467,466,1,0,0,0,468,471,1,0,0,0,469,467,
  	1,0,0,0,469,470,1,0,0,0,470,472,1,0,0,0,471,469,1,0,0,0,472,473,5,18,
  	0,0,473,477,5,33,0,0,474,476,5,30,0,0,475,474,1,0,0,0,476,479,1,0,0,0,
  	477,475,1,0,0,0,477,478,1,0,0,0,478,480,1,0,0,0,479,477,1,0,0,0,480,484,
  	3,22,11,0,481,483,5,30,0,0,482,481,1,0,0,0,483,486,1,0,0,0,484,482,1,
  	0,0,0,484,485,1,0,0,0,485,487,1,0,0,0,486,484,1,0,0,0,487,491,5,34,0,
  	0,488,490,5,30,0,0,489,488,1,0,0,0,490,493,1,0,0,0,491,489,1,0,0,0,491,
  	492,1,0,0,0,492,761,1,0,0,0,493,491,1,0,0,0,494,496,5,30,0,0,495,494,
  	1,0,0,0,496,499,1,0,0,0,497,495,1,0,0,0,497,498,1,0,0,0,498,500,1,0,0,
  	0,499,497,1,0,0,0,500,501,5,19,0,0,501,505,5,33,0,0,502,504,5,30,0,0,
  	503,502,1,0,0,0,504,507,1,0,0,0,505,503,1,0,0,0,505,506,1,0,0,0,506,508,
  	1,0,0,0,507,505,1,0,0,0,508,512,3,22,11,0,509,511,5,30,0,0,510,509,1,
  	0,0,0,511,514,1,0,0,0,512,510,1,0,0,0,512,513,1,0,0,0,513,515,1,0,0,0,
  	514,512,1,0,0,0,515,519,5,34,0,0,516,518,5,30,0,0,517,516,1,0,0,0,518,
  	521,1,0,0,0,519,517,1,0,0,0,519,520,1,0,0,0,520,761,1,0,0,0,521,519,1,
  	0,0,0,522,524,5,30,0,0,523,522,1,0,0,0,524,527,1,0,0,0,525,523,1,0,0,
  	0,525,526,1,0,0,0,526,528,1,0,0,0,527,525,1,0,0,0,528,529,5,21,0,0,529,
  	533,5,33,0,0,530,532,5,30,0,0,531,530,1,0,0,0,532,535,1,0,0,0,533,531,
  	1,0,0,0,533,534,1,0,0,0,534,536,1,0,0,0,535,533,1,0,0,0,536,540,3,22,
  	11,0,537,539,5,30,0,0,538,537,1,0,0,0,539,542,1,0,0,0,540,538,1,0,0,0,
  	540,541,1,0,0,0,541,543,1,0,0,0,542,540,1,0,0,0,543,547,5,34,0,0,544,
  	546,5,30,0,0,545,544,1,0,0,0,546,549,1,0,0,0,547,545,1,0,0,0,547,548,
  	1,0,0,0,548,761,1,0,0,0,549,547,1,0,0,0,550,552,5,30,0,0,551,550,1,0,
  	0,0,552,555,1,0,0,0,553,551,1,0,0,0,553,554,1,0,0,0,554,556,1,0,0,0,555,
  	553,1,0,0,0,556,557,5,22,0,0,557,561,5,33,0,0,558,560,5,30,0,0,559,558,
  	1,0,0,0,560,563,1,0,0,0,561,559,1,0,0,0,561,562,1,0,0,0,562,564,1,0,0,
  	0,563,561,1,0,0,0,564,568,3,22,11,0,565,567,5,30,0,0,566,565,1,0,0,0,
  	567,570,1,0,0,0,568,566,1,0,0,0,568,569,1,0,0,0,569,571,1,0,0,0,570,568,
  	1,0,0,0,571,575,5,34,0,0,572,574,5,30,0,0,573,572,1,0,0,0,574,577,1,0,
  	0,0,575,573,1,0,0,0,575,576,1,0,0,0,576,761,1,0,0,0,577,575,1,0,0,0,578,
  	580,5,30,0,0,579,578,1,0,0,0,580,583,1,0,0,0,581,579,1,0,0,0,581,582,
  	1,0,0,0,582,584,1,0,0,0,583,581,1,0,0,0,584,585,5,24,0,0,585,589,5,33,
  	0,0,586,588,5,30,0,0,587,586,1,0,0,0,588,591,1,0,0,0,589,587,1,0,0,0,
  	589,590,1,0,0,0,590,592,1,0,0,0,591,589,1,0,0,0,592,596,3,22,11,0,593,
  	595,5,30,0,0,594,593,1,0,0,0,595,598,1,0,0,0,596,594,1,0,0,0,596,597,
  	1,0,0,0,597,599,1,0,0,0,598,596,1,0,0,0,599,603,5,34,0,0,600,602,5,30,
  	0,0,601,600,1,0,0,0,602,605,1,0,0,0,603,601,1,0,0,0,603,604,1,0,0,0,604,
  	761,1,0,0,0,605,603,1,0,0,0,606,608,5,30,0,0,607,606,1,0,0,0,608,611,
  	1,0,0,0,609,607,1,0,0,0,609,610,1,0,0,0,610,612,1,0,0,0,611,609,1,0,0,
  	0,612,613,5,25,0,0,613,617,5,33,0,0,614,616,5,30,0,0,615,614,1,0,0,0,
  	616,619,1,0,0,0,617,615,1,0,0,0,617,618,1,0,0,0,618,620,1,0,0,0,619,617,
  	1,0,0,0,620,624,3,22,11,0,621,623,5,30,0,0,622,621,1,0,0,0,623,626,1,
  	0,0,0,624,622,1,0,0,0,624,625,1,0,0,0,625,627,1,0,0,0,626,624,1,0,0,0,
  	627,631,5,34,0,0,628,630,5,30,0,0,629,628,1,0,0,0,630,633,1,0,0,0,631,
  	629,1,0,0,0,631,632,1,0,0,0,632,761,1,0,0,0,633,631,1,0,0,0,634,636,5,
  	30,0,0,635,634,1,0,0,0,636,639,1,0,0,0,637,635,1,0,0,0,637,638,1,0,0,
  	0,638,640,1,0,0,0,639,637,1,0,0,0,640,641,5,27,0,0,641,645,5,33,0,0,642,
  	644,5,30,0,0,643,642,1,0,0,0,644,647,1,0,0,0,645,643,1,0,0,0,645,646,
  	1,0,0,0,646,648,1,0,0,0,647,645,1,0,0,0,648,652,3,22,11,0,649,651,5,30,
  	0,0,650,649,1,0,0,0,651,654,1,0,0,0,652,650,1,0,0,0,652,653,1,0,0,0,653,
  	655,1,0,0,0,654,652,1,0,0,0,655,659,5,34,0,0,656,658,5,30,0,0,657,656,
  	1,0,0,0,658,661,1,0,0,0,659,657,1,0,0,0,659,660,1,0,0,0,660,761,1,0,0,
  	0,661,659,1,0,0,0,662,664,5,30,0,0,663,662,1,0,0,0,664,667,1,0,0,0,665,
  	663,1,0,0,0,665,666,1,0,0,0,666,668,1,0,0,0,667,665,1,0,0,0,668,669,5,
  	26,0,0,669,673,5,33,0,0,670,672,5,30,0,0,671,670,1,0,0,0,672,675,1,0,
  	0,0,673,671,1,0,0,0,673,674,1,0,0,0,674,676,1,0,0,0,675,673,1,0,0,0,676,
  	680,3,22,11,0,677,679,5,30,0,0,678,677,1,0,0,0,679,682,1,0,0,0,680,678,
  	1,0,0,0,680,681,1,0,0,0,681,683,1,0,0,0,682,680,1,0,0,0,683,687,5,34,
  	0,0,684,686,5,30,0,0,685,684,1,0,0,0,686,689,1,0,0,0,687,685,1,0,0,0,
  	687,688,1,0,0,0,688,761,1,0,0,0,689,687,1,0,0,0,690,692,5,30,0,0,691,
  	690,1,0,0,0,692,695,1,0,0,0,693,691,1,0,0,0,693,694,1,0,0,0,694,696,1,
  	0,0,0,695,693,1,0,0,0,696,697,5,28,0,0,697,701,5,33,0,0,698,700,5,30,
  	0,0,699,698,1,0,0,0,700,703,1,0,0,0,701,699,1,0,0,0,701,702,1,0,0,0,702,
  	704,1,0,0,0,703,701,1,0,0,0,704,708,3,22,11,0,705,707,5,30,0,0,706,705,
  	1,0,0,0,707,710,1,0,0,0,708,706,1,0,0,0,708,709,1,0,0,0,709,711,1,0,0,
  	0,710,708,1,0,0,0,711,715,5,34,0,0,712,714,5,30,0,0,713,712,1,0,0,0,714,
  	717,1,0,0,0,715,713,1,0,0,0,715,716,1,0,0,0,716,761,1,0,0,0,717,715,1,
  	0,0,0,718,720,5,30,0,0,719,718,1,0,0,0,720,723,1,0,0,0,721,719,1,0,0,
  	0,721,722,1,0,0,0,722,724,1,0,0,0,723,721,1,0,0,0,724,725,5,20,0,0,725,
  	729,5,33,0,0,726,728,5,30,0,0,727,726,1,0,0,0,728,731,1,0,0,0,729,727,
  	1,0,0,0,729,730,1,0,0,0,730,732,1,0,0,0,731,729,1,0,0,0,732,736,3,22,
  	11,0,733,735,5,30,0,0,734,733,1,0,0,0,735,738,1,0,0,0,736,734,1,0,0,0,
  	736,737,1,0,0,0,737,739,1,0,0,0,738,736,1,0,0,0,739,743,5,36,0,0,740,
  	742,5,30,0,0,741,740,1,0,0,0,742,745,1,0,0,0,743,741,1,0,0,0,743,744,
  	1,0,0,0,744,746,1,0,0,0,745,743,1,0,0,0,746,750,3,22,11,0,747,749,5,30,
  	0,0,748,747,1,0,0,0,749,752,1,0,0,0,750,748,1,0,0,0,750,751,1,0,0,0,751,
  	753,1,0,0,0,752,750,1,0,0,0,753,757,5,34,0,0,754,756,5,30,0,0,755,754,
  	1,0,0,0,756,759,1,0,0,0,757,755,1,0,0,0,757,758,1,0,0,0,758,761,1,0,0,
  	0,759,757,1,0,0,0,760,469,1,0,0,0,760,497,1,0,0,0,760,525,1,0,0,0,760,
  	553,1,0,0,0,760,581,1,0,0,0,760,609,1,0,0,0,760,637,1,0,0,0,760,665,1,
  	0,0,0,760,693,1,0,0,0,760,721,1,0,0,0,761,33,1,0,0,0,762,764,5,30,0,0,
  	763,762,1,0,0,0,764,767,1,0,0,0,765,763,1,0,0,0,765,766,1,0,0,0,766,768,
  	1,0,0,0,767,765,1,0,0,0,768,769,5,12,0,0,769,770,5,33,0,0,770,771,3,22,
  	11,0,771,772,5,36,0,0,772,777,3,22,11,0,773,774,5,36,0,0,774,776,3,22,
  	11,0,775,773,1,0,0,0,776,779,1,0,0,0,777,775,1,0,0,0,777,778,1,0,0,0,
  	778,780,1,0,0,0,779,777,1,0,0,0,780,781,5,34,0,0,781,823,1,0,0,0,782,
  	784,5,30,0,0,783,782,1,0,0,0,784,787,1,0,0,0,785,783,1,0,0,0,785,786,
  	1,0,0,0,786,788,1,0,0,0,787,785,1,0,0,0,788,789,5,14,0,0,789,790,5,33,
  	0,0,790,791,3,22,11,0,791,792,5,36,0,0,792,797,3,22,11,0,793,794,5,36,
  	0,0,794,796,3,22,11,0,795,793,1,0,0,0,796,799,1,0,0,0,797,795,1,0,0,0,
  	797,798,1,0,0,0,798,800,1,0,0,0,799,797,1,0,0,0,800,801,5,34,0,0,801,
  	823,1,0,0,0,802,804,5,30,0,0,803,802,1,0,0,0,804,807,1,0,0,0,805,803,
  	1,0,0,0,805,806,1,0,0,0,806,808,1,0,0,0,807,805,1,0,0,0,808,809,5,16,
  	0,0,809,810,5,33,0,0,810,811,3,22,11,0,811,812,5,36,0,0,812,817,3,22,
  	11,0,813,814,5,36,0,0,814,816,3,22,11,0,815,813,1,0,0,0,816,819,1,0,0,
  	0,817,815,1,0,0,0,817,818,1,0,0,0,818,820,1,0,0,0,819,817,1,0,0,0,820,
  	821,5,34,0,0,821,823,1,0,0,0,822,765,1,0,0,0,822,785,1,0,0,0,822,805,
  	1,0,0,0,823,35,1,0,0,0,824,826,5,30,0,0,825,824,1,0,0,0,826,829,1,0,0,
  	0,827,825,1,0,0,0,827,828,1,0,0,0,828,830,1,0,0,0,829,827,1,0,0,0,830,
  	831,5,15,0,0,831,835,5,33,0,0,832,834,5,30,0,0,833,832,1,0,0,0,834,837,
  	1,0,0,0,835,833,1,0,0,0,835,836,1,0,0,0,836,838,1,0,0,0,837,835,1,0,0,
  	0,838,842,3,22,11,0,839,841,5,30,0,0,840,839,1,0,0,0,841,844,1,0,0,0,
  	842,840,1,0,0,0,842,843,1,0,0,0,843,845,1,0,0,0,844,842,1,0,0,0,845,849,
  	5,34,0,0,846,848,5,30,0,0,847,846,1,0,0,0,848,851,1,0,0,0,849,847,1,0,
  	0,0,849,850,1,0,0,0,850,881,1,0,0,0,851,849,1,0,0,0,852,854,5,30,0,0,
  	853,852,1,0,0,0,854,857,1,0,0,0,855,853,1,0,0,0,855,856,1,0,0,0,856,858,
  	1,0,0,0,857,855,1,0,0,0,858,859,5,17,0,0,859,863,5,33,0,0,860,862,5,30,
  	0,0,861,860,1,0,0,0,862,865,1,0,0,0,863,861,1,0,0,0,863,864,1,0,0,0,864,
  	866,1,0,0,0,865,863,1,0,0,0,866,870,3,22,11,0,867,869,5,30,0,0,868,867,
  	1,0,0,0,869,872,1,0,0,0,870,868,1,0,0,0,870,871,1,0,0,0,871,873,1,0,0,
  	0,872,870,1,0,0,0,873,877,5,34,0,0,874,876,5,30,0,0,875,874,1,0,0,0,876,
  	879,1,0,0,0,877,875,1,0,0,0,877,878,1,0,0,0,878,881,1,0,0,0,879,877,1,
  	0,0,0,880,827,1,0,0,0,880,855,1,0,0,0,881,37,1,0,0,0,882,883,5,4,0,0,
  	883,884,5,29,0,0,884,885,5,4,0,0,885,39,1,0,0,0,129,43,50,53,57,62,69,
  	77,84,92,99,106,112,118,126,129,134,142,150,156,163,166,170,174,176,181,
  	187,195,203,209,216,219,223,227,229,234,241,245,250,258,266,274,280,287,
  	290,296,303,306,311,318,325,332,339,346,353,356,375,379,385,389,398,405,
  	413,420,424,426,433,440,447,453,460,469,477,484,491,497,505,512,519,525,
  	533,540,547,553,561,568,575,581,589,596,603,609,617,624,631,637,645,652,
  	659,665,673,680,687,693,701,708,715,721,729,736,743,750,757,760,765,777,
  	785,797,805,817,822,827,835,842,849,855,863,870,877,880
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  head_interactorParserStaticData = staticData.release();
}

}

head_interactor::head_interactor(TokenStream *input) : head_interactor(input, antlr4::atn::ParserATNSimulatorOptions()) {}

head_interactor::head_interactor(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  head_interactor::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *head_interactorParserStaticData->atn, head_interactorParserStaticData->decisionToDFA, head_interactorParserStaticData->sharedContextCache, options);
}

head_interactor::~head_interactor() {
  delete _interpreter;
}

const atn::ATN& head_interactor::getATN() const {
  return *head_interactorParserStaticData->atn;
}

std::string head_interactor::getGrammarFileName() const {
  return "head_interactor.g4";
}

const std::vector<std::string>& head_interactor::getRuleNames() const {
  return head_interactorParserStaticData->ruleNames;
}

const dfa::Vocabulary& head_interactor::getVocabulary() const {
  return head_interactorParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView head_interactor::getSerializedATN() const {
  return head_interactorParserStaticData->serializedATN;
}


//----------------- Value_typeContext ------------------------------------------------------------------

head_interactor::Value_typeContext::Value_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

head_interactor::ArrayContext* head_interactor::Value_typeContext::array() {
  return getRuleContext<head_interactor::ArrayContext>(0);
}

head_interactor::ExprContext* head_interactor::Value_typeContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}

head_interactor::StringContext* head_interactor::Value_typeContext::string() {
  return getRuleContext<head_interactor::StringContext>(0);
}


size_t head_interactor::Value_typeContext::getRuleIndex() const {
  return head_interactor::RuleValue_type;
}

void head_interactor::Value_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_type(this);
}

void head_interactor::Value_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_type(this);
}

head_interactor::Value_typeContext* head_interactor::value_type() {
  Value_typeContext *_localctx = _tracker.createInstance<Value_typeContext>(_ctx, getState());
  enterRule(_localctx, 0, head_interactor::RuleValue_type);

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
      case head_interactor::BEG_ARR: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        array();
        break;
      }

      case head_interactor::VAR_TAG:
      case head_interactor::VARIABLE:
      case head_interactor::SUMPRODUCT:
      case head_interactor::SUM:
      case head_interactor::SUM_I:
      case head_interactor::PRODUCT:
      case head_interactor::PRODUCT_I:
      case head_interactor::LN:
      case head_interactor::LG:
      case head_interactor::LOG_X:
      case head_interactor::EXP:
      case head_interactor::SQRT:
      case head_interactor::PI:
      case head_interactor::COS:
      case head_interactor::SIN:
      case head_interactor::ASIN:
      case head_interactor::ACOS:
      case head_interactor::FACTORIAL:
      case head_interactor::WS:
      case head_interactor::UINT:
      case head_interactor::Lb:
      case head_interactor::ADD:
      case head_interactor::SUB:
      case head_interactor::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(41);
        expr(0);
        break;
      }

      case head_interactor::DOUBLE_QUOTE: {
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

head_interactor::ComparatorContext::ComparatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::ComparatorContext::LARGER() {
  return getToken(head_interactor::LARGER, 0);
}

tree::TerminalNode* head_interactor::ComparatorContext::LARGER_EQUAL() {
  return getToken(head_interactor::LARGER_EQUAL, 0);
}

tree::TerminalNode* head_interactor::ComparatorContext::EQUAL() {
  return getToken(head_interactor::EQUAL, 0);
}

tree::TerminalNode* head_interactor::ComparatorContext::LESS() {
  return getToken(head_interactor::LESS, 0);
}

tree::TerminalNode* head_interactor::ComparatorContext::LESS_EQUAL() {
  return getToken(head_interactor::LESS_EQUAL, 0);
}


size_t head_interactor::ComparatorContext::getRuleIndex() const {
  return head_interactor::RuleComparator;
}

void head_interactor::ComparatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparator(this);
}

void head_interactor::ComparatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparator(this);
}

head_interactor::ComparatorContext* head_interactor::comparator() {
  ComparatorContext *_localctx = _tracker.createInstance<ComparatorContext>(_ctx, getState());
  enterRule(_localctx, 2, head_interactor::RuleComparator);
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
      ((1ULL << _la) & 3968) != 0))) {
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

head_interactor::InputContext::InputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<head_interactor::Line_inputContext *> head_interactor::InputContext::line_input() {
  return getRuleContexts<head_interactor::Line_inputContext>();
}

head_interactor::Line_inputContext* head_interactor::InputContext::line_input(size_t i) {
  return getRuleContext<head_interactor::Line_inputContext>(i);
}

tree::TerminalNode* head_interactor::InputContext::EOF() {
  return getToken(head_interactor::EOF, 0);
}


size_t head_interactor::InputContext::getRuleIndex() const {
  return head_interactor::RuleInput;
}

void head_interactor::InputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInput(this);
}

void head_interactor::InputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInput(this);
}

head_interactor::InputContext* head_interactor::input() {
  InputContext *_localctx = _tracker.createInstance<InputContext>(_ctx, getState());
  enterRule(_localctx, 4, head_interactor::RuleInput);
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
      case head_interactor::VAR_TAG:
      case head_interactor::VARIABLE:
      case head_interactor::WS: {
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
          ((1ULL << _la) & 1073741858) != 0));
        break;
      }

      case head_interactor::EOF: {
        enterOuterAlt(_localctx, 2);
        setState(52);
        match(head_interactor::EOF);
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

head_interactor::Line_inputContext::Line_inputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

head_interactor::VardefinitionContext* head_interactor::Line_inputContext::vardefinition() {
  return getRuleContext<head_interactor::VardefinitionContext>(0);
}

head_interactor::ComparisionContext* head_interactor::Line_inputContext::comparision() {
  return getRuleContext<head_interactor::ComparisionContext>(0);
}


size_t head_interactor::Line_inputContext::getRuleIndex() const {
  return head_interactor::RuleLine_input;
}

void head_interactor::Line_inputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine_input(this);
}

void head_interactor::Line_inputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine_input(this);
}

head_interactor::Line_inputContext* head_interactor::line_input() {
  Line_inputContext *_localctx = _tracker.createInstance<Line_inputContext>(_ctx, getState());
  enterRule(_localctx, 6, head_interactor::RuleLine_input);

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

head_interactor::Node_accessContext::Node_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::Node_accessContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

tree::TerminalNode* head_interactor::Node_accessContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

std::vector<tree::TerminalNode *> head_interactor::Node_accessContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::Node_accessContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

std::vector<tree::TerminalNode *> head_interactor::Node_accessContext::UINT() {
  return getTokens(head_interactor::UINT);
}

tree::TerminalNode* head_interactor::Node_accessContext::UINT(size_t i) {
  return getToken(head_interactor::UINT, i);
}

std::vector<tree::TerminalNode *> head_interactor::Node_accessContext::SEPAR() {
  return getTokens(head_interactor::SEPAR);
}

tree::TerminalNode* head_interactor::Node_accessContext::SEPAR(size_t i) {
  return getToken(head_interactor::SEPAR, i);
}


size_t head_interactor::Node_accessContext::getRuleIndex() const {
  return head_interactor::RuleNode_access;
}

void head_interactor::Node_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_access(this);
}

void head_interactor::Node_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_access(this);
}

head_interactor::Node_accessContext* head_interactor::node_access() {
  Node_accessContext *_localctx = _tracker.createInstance<Node_accessContext>(_ctx, getState());
  enterRule(_localctx, 8, head_interactor::RuleNode_access);
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
      while (_la == head_interactor::WS) {
        setState(59);
        match(head_interactor::WS);
        setState(64);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(65);
      match(head_interactor::Lb);
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(66);
        match(head_interactor::WS);
        setState(71);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(72);
      match(head_interactor::Rb);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      match(head_interactor::Lb);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(74);
        match(head_interactor::WS);
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
      match(head_interactor::UINT);
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(81);
        match(head_interactor::WS);
        setState(86);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(87);
      match(head_interactor::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(88);
      match(head_interactor::Lb);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(89);
        match(head_interactor::WS);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(95);
      match(head_interactor::UINT);
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(96);
          match(head_interactor::WS); 
        }
        setState(101);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(102);
        match(head_interactor::SEPAR);
        setState(106);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == head_interactor::WS) {
          setState(103);
          match(head_interactor::WS);
          setState(108);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(109);
        match(head_interactor::UINT);
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(115);
        match(head_interactor::WS);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(121);
      match(head_interactor::Rb);
      setState(126);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(123);
          match(head_interactor::WS); 
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

head_interactor::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> head_interactor::VariableContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::VariableContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

tree::TerminalNode* head_interactor::VariableContext::VAR_TAG() {
  return getToken(head_interactor::VAR_TAG, 0);
}

tree::TerminalNode* head_interactor::VariableContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

tree::TerminalNode* head_interactor::VariableContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

tree::TerminalNode* head_interactor::VariableContext::VARIABLE() {
  return getToken(head_interactor::VARIABLE, 0);
}

tree::TerminalNode* head_interactor::VariableContext::DATABASE() {
  return getToken(head_interactor::DATABASE, 0);
}

head_interactor::Node_accessContext* head_interactor::VariableContext::node_access() {
  return getRuleContext<head_interactor::Node_accessContext>(0);
}


size_t head_interactor::VariableContext::getRuleIndex() const {
  return head_interactor::RuleVariable;
}

void head_interactor::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void head_interactor::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

head_interactor::VariableContext* head_interactor::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 10, head_interactor::RuleVariable);
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
    while (_la == head_interactor::WS) {
      setState(131);
      match(head_interactor::WS);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(137);
        match(head_interactor::VAR_TAG);
        setState(138);
        match(head_interactor::Lb);
        setState(166);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(142);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(139);
            match(head_interactor::WS);
            setState(144);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(145);
          match(head_interactor::DATABASE);
          setState(146);
          match(head_interactor::VARIABLE);
          setState(150);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(147);
            match(head_interactor::WS);
            setState(152);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(156);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(153);
            match(head_interactor::WS);
            setState(158);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(159);
          match(head_interactor::VARIABLE);
          setState(163);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(160);
            match(head_interactor::WS);
            setState(165);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(168);
        match(head_interactor::Rb);
        setState(170);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(169);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case head_interactor::VARIABLE: {
        setState(172);
        match(head_interactor::VARIABLE);
        setState(174);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(173);
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
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(178);
        match(head_interactor::WS); 
      }
      setState(183);
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

head_interactor::VardefinitionContext::VardefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::VardefinitionContext::EQUAL() {
  return getToken(head_interactor::EQUAL, 0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::EOL() {
  return getToken(head_interactor::EOL, 0);
}

std::vector<tree::TerminalNode *> head_interactor::VardefinitionContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::VardefinitionContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

head_interactor::Value_typeContext* head_interactor::VardefinitionContext::value_type() {
  return getRuleContext<head_interactor::Value_typeContext>(0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::VAR_TAG() {
  return getToken(head_interactor::VAR_TAG, 0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::VARIABLE() {
  return getToken(head_interactor::VARIABLE, 0);
}

tree::TerminalNode* head_interactor::VardefinitionContext::DATABASE() {
  return getToken(head_interactor::DATABASE, 0);
}

head_interactor::Node_accessContext* head_interactor::VardefinitionContext::node_access() {
  return getRuleContext<head_interactor::Node_accessContext>(0);
}


size_t head_interactor::VardefinitionContext::getRuleIndex() const {
  return head_interactor::RuleVardefinition;
}

void head_interactor::VardefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardefinition(this);
}

void head_interactor::VardefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardefinition(this);
}

head_interactor::VardefinitionContext* head_interactor::vardefinition() {
  VardefinitionContext *_localctx = _tracker.createInstance<VardefinitionContext>(_ctx, getState());
  enterRule(_localctx, 12, head_interactor::RuleVardefinition);
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
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(184);
      match(head_interactor::WS);
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(190);
        match(head_interactor::VAR_TAG);
        setState(191);
        match(head_interactor::Lb);
        setState(219);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          setState(195);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(192);
            match(head_interactor::WS);
            setState(197);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(198);
          match(head_interactor::DATABASE);
          setState(199);
          match(head_interactor::VARIABLE);
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(200);
            match(head_interactor::WS);
            setState(205);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(209);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(206);
            match(head_interactor::WS);
            setState(211);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(212);
          match(head_interactor::VARIABLE);
          setState(216);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(213);
            match(head_interactor::WS);
            setState(218);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(221);
        match(head_interactor::Rb);
        setState(223);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          setState(222);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case head_interactor::VARIABLE: {
        setState(225);
        match(head_interactor::VARIABLE);
        setState(227);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          setState(226);
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
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(231);
      match(head_interactor::WS);
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    match(head_interactor::EQUAL);
    setState(241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(238);
        match(head_interactor::WS); 
      }
      setState(243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(245);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(244);
      value_type();
      break;
    }

    default:
      break;
    }
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(247);
      match(head_interactor::WS);
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(253);
    match(head_interactor::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisionContext ------------------------------------------------------------------

head_interactor::ComparisionContext::ComparisionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> head_interactor::ComparisionContext::COL() {
  return getTokens(head_interactor::COL);
}

tree::TerminalNode* head_interactor::ComparisionContext::COL(size_t i) {
  return getToken(head_interactor::COL, i);
}

head_interactor::Lhs_compContext* head_interactor::ComparisionContext::lhs_comp() {
  return getRuleContext<head_interactor::Lhs_compContext>(0);
}

head_interactor::ComparatorContext* head_interactor::ComparisionContext::comparator() {
  return getRuleContext<head_interactor::ComparatorContext>(0);
}

head_interactor::Rhs_compContext* head_interactor::ComparisionContext::rhs_comp() {
  return getRuleContext<head_interactor::Rhs_compContext>(0);
}

tree::TerminalNode* head_interactor::ComparisionContext::EOL() {
  return getToken(head_interactor::EOL, 0);
}

tree::TerminalNode* head_interactor::ComparisionContext::VARIABLE() {
  return getToken(head_interactor::VARIABLE, 0);
}

std::vector<tree::TerminalNode *> head_interactor::ComparisionContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::ComparisionContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

head_interactor::Expr_compContext* head_interactor::ComparisionContext::expr_comp() {
  return getRuleContext<head_interactor::Expr_compContext>(0);
}

tree::TerminalNode* head_interactor::ComparisionContext::VAR_TAG() {
  return getToken(head_interactor::VAR_TAG, 0);
}

tree::TerminalNode* head_interactor::ComparisionContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

tree::TerminalNode* head_interactor::ComparisionContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

tree::TerminalNode* head_interactor::ComparisionContext::DATABASE() {
  return getToken(head_interactor::DATABASE, 0);
}


size_t head_interactor::ComparisionContext::getRuleIndex() const {
  return head_interactor::RuleComparision;
}

void head_interactor::ComparisionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparision(this);
}

void head_interactor::ComparisionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparision(this);
}

head_interactor::ComparisionContext* head_interactor::comparision() {
  ComparisionContext *_localctx = _tracker.createInstance<ComparisionContext>(_ctx, getState());
  enterRule(_localctx, 14, head_interactor::RuleComparision);
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
    setState(258);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(255);
        match(head_interactor::WS); 
      }
      setState(260);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(306);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(261);
        match(head_interactor::VAR_TAG);
        setState(262);
        match(head_interactor::Lb);
        setState(290);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          setState(266);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(263);
            match(head_interactor::WS);
            setState(268);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(269);
          match(head_interactor::DATABASE);
          setState(270);
          match(head_interactor::VARIABLE);
          setState(274);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(271);
            match(head_interactor::WS);
            setState(276);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(280);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(277);
            match(head_interactor::WS);
            setState(282);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(283);
          match(head_interactor::VARIABLE);
          setState(287);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(284);
            match(head_interactor::WS);
            setState(289);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(292);
        match(head_interactor::Rb);
        break;
      }

      case head_interactor::VARIABLE:
      case head_interactor::WS: {
        setState(296);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == head_interactor::WS) {
          setState(293);
          match(head_interactor::WS);
          setState(298);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(299);
        match(head_interactor::VARIABLE);
        setState(303);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(300);
            match(head_interactor::WS); 
          }
          setState(305);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(308);
      match(head_interactor::WS);
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(314);
    match(head_interactor::COL);
    setState(318);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(315);
        match(head_interactor::WS); 
      }
      setState(320);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
    setState(321);
    lhs_comp();
    setState(325);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(322);
      match(head_interactor::WS);
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(328);
    comparator();
    setState(332);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(329);
        match(head_interactor::WS); 
      }
      setState(334);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(335);
    rhs_comp();
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(336);
      match(head_interactor::WS);
      setState(341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(356);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == head_interactor::COL) {
      setState(342);
      match(head_interactor::COL);
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(343);
          match(head_interactor::WS); 
        }
        setState(348);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(349);
      expr_comp();
      setState(353);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(350);
        match(head_interactor::WS);
        setState(355);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(358);
    match(head_interactor::EOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lhs_compContext ------------------------------------------------------------------

head_interactor::Lhs_compContext::Lhs_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

head_interactor::ExprContext* head_interactor::Lhs_compContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}


size_t head_interactor::Lhs_compContext::getRuleIndex() const {
  return head_interactor::RuleLhs_comp;
}

void head_interactor::Lhs_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLhs_comp(this);
}

void head_interactor::Lhs_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLhs_comp(this);
}

head_interactor::Lhs_compContext* head_interactor::lhs_comp() {
  Lhs_compContext *_localctx = _tracker.createInstance<Lhs_compContext>(_ctx, getState());
  enterRule(_localctx, 16, head_interactor::RuleLhs_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
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

head_interactor::Rhs_compContext::Rhs_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

head_interactor::ExprContext* head_interactor::Rhs_compContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}


size_t head_interactor::Rhs_compContext::getRuleIndex() const {
  return head_interactor::RuleRhs_comp;
}

void head_interactor::Rhs_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhs_comp(this);
}

void head_interactor::Rhs_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhs_comp(this);
}

head_interactor::Rhs_compContext* head_interactor::rhs_comp() {
  Rhs_compContext *_localctx = _tracker.createInstance<Rhs_compContext>(_ctx, getState());
  enterRule(_localctx, 18, head_interactor::RuleRhs_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
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

head_interactor::Expr_compContext::Expr_compContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

head_interactor::ExprContext* head_interactor::Expr_compContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}


size_t head_interactor::Expr_compContext::getRuleIndex() const {
  return head_interactor::RuleExpr_comp;
}

void head_interactor::Expr_compContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_comp(this);
}

void head_interactor::Expr_compContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_comp(this);
}

head_interactor::Expr_compContext* head_interactor::expr_comp() {
  Expr_compContext *_localctx = _tracker.createInstance<Expr_compContext>(_ctx, getState());
  enterRule(_localctx, 20, head_interactor::RuleExpr_comp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
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

head_interactor::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t head_interactor::ExprContext::getRuleIndex() const {
  return head_interactor::RuleExpr;
}

void head_interactor::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

head_interactor::ExprContext* head_interactor::UnaryOpContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}

tree::TerminalNode* head_interactor::UnaryOpContext::ADD() {
  return getToken(head_interactor::ADD, 0);
}

tree::TerminalNode* head_interactor::UnaryOpContext::SUB() {
  return getToken(head_interactor::SUB, 0);
}

std::vector<tree::TerminalNode *> head_interactor::UnaryOpContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::UnaryOpContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

head_interactor::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void head_interactor::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- ParensContext ------------------------------------------------------------------

tree::TerminalNode* head_interactor::ParensContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

head_interactor::ExprContext* head_interactor::ParensContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}

tree::TerminalNode* head_interactor::ParensContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

head_interactor::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void head_interactor::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

head_interactor::NumberContext* head_interactor::LiteralContext::number() {
  return getRuleContext<head_interactor::NumberContext>(0);
}

head_interactor::ConstantContext* head_interactor::LiteralContext::constant() {
  return getRuleContext<head_interactor::ConstantContext>(0);
}

head_interactor::LiteralContext::LiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void head_interactor::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

head_interactor::FunctionContext* head_interactor::FunctionCallContext::function() {
  return getRuleContext<head_interactor::FunctionContext>(0);
}

head_interactor::MultiargfunctionContext* head_interactor::FunctionCallContext::multiargfunction() {
  return getRuleContext<head_interactor::MultiargfunctionContext>(0);
}

head_interactor::RangefunctionContext* head_interactor::FunctionCallContext::rangefunction() {
  return getRuleContext<head_interactor::RangefunctionContext>(0);
}

head_interactor::FunctionCallContext::FunctionCallContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void head_interactor::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}
//----------------- VariableInExprContext ------------------------------------------------------------------

head_interactor::VariableContext* head_interactor::VariableInExprContext::variable() {
  return getRuleContext<head_interactor::VariableContext>(0);
}

head_interactor::VariableInExprContext::VariableInExprContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::VariableInExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInExpr(this);
}
void head_interactor::VariableInExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInExpr(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<head_interactor::ExprContext *> head_interactor::BinaryOpContext::expr() {
  return getRuleContexts<head_interactor::ExprContext>();
}

head_interactor::ExprContext* head_interactor::BinaryOpContext::expr(size_t i) {
  return getRuleContext<head_interactor::ExprContext>(i);
}

tree::TerminalNode* head_interactor::BinaryOpContext::POW() {
  return getToken(head_interactor::POW, 0);
}

tree::TerminalNode* head_interactor::BinaryOpContext::MUL() {
  return getToken(head_interactor::MUL, 0);
}

tree::TerminalNode* head_interactor::BinaryOpContext::DIV() {
  return getToken(head_interactor::DIV, 0);
}

std::vector<tree::TerminalNode *> head_interactor::BinaryOpContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::BinaryOpContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

tree::TerminalNode* head_interactor::BinaryOpContext::ADD() {
  return getToken(head_interactor::ADD, 0);
}

tree::TerminalNode* head_interactor::BinaryOpContext::SUB() {
  return getToken(head_interactor::SUB, 0);
}

head_interactor::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void head_interactor::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void head_interactor::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

head_interactor::ExprContext* head_interactor::expr() {
   return expr(0);
}

head_interactor::ExprContext* head_interactor::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  head_interactor::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  head_interactor::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, head_interactor::RuleExpr, precedence);

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
    setState(389);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(367);
      match(head_interactor::Lb);
      setState(368);
      expr(0);
      setState(369);
      match(head_interactor::Rb);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(371);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(375);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(372);
        function();
        break;
      }

      case 2: {
        setState(373);
        multiargfunction();
        break;
      }

      case 3: {
        setState(374);
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
      setState(379);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case head_interactor::UINT:
        case head_interactor::FLOAT: {
          setState(377);
          number();
          break;
        }

        case head_interactor::EXP:
        case head_interactor::PI: {
          setState(378);
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
      setState(381);
      _la = _input->LA(1);
      if (!(_la == head_interactor::ADD

      || _la == head_interactor::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(385);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(382);
          match(head_interactor::WS); 
        }
        setState(387);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(388);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(426);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(424);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(391);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(392);
          match(head_interactor::POW);
          setState(393);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(394);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(398);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(395);
            match(head_interactor::WS);
            setState(400);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(401);
          _la = _input->LA(1);
          if (!(_la == head_interactor::MUL

          || _la == head_interactor::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(405);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(402);
              match(head_interactor::WS); 
            }
            setState(407);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          }
          setState(408);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(409);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(413);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(410);
            match(head_interactor::WS);
            setState(415);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(416);
          _la = _input->LA(1);
          if (!(_la == head_interactor::ADD

          || _la == head_interactor::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(420);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(417);
              match(head_interactor::WS); 
            }
            setState(422);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          }
          setState(423);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(428);
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

head_interactor::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::ArrayContext::BEG_ARR() {
  return getToken(head_interactor::BEG_ARR, 0);
}

std::vector<head_interactor::Input_arrayContext *> head_interactor::ArrayContext::input_array() {
  return getRuleContexts<head_interactor::Input_arrayContext>();
}

head_interactor::Input_arrayContext* head_interactor::ArrayContext::input_array(size_t i) {
  return getRuleContext<head_interactor::Input_arrayContext>(i);
}

tree::TerminalNode* head_interactor::ArrayContext::END_ARR() {
  return getToken(head_interactor::END_ARR, 0);
}

std::vector<tree::TerminalNode *> head_interactor::ArrayContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::ArrayContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

std::vector<tree::TerminalNode *> head_interactor::ArrayContext::SEPAR() {
  return getTokens(head_interactor::SEPAR);
}

tree::TerminalNode* head_interactor::ArrayContext::SEPAR(size_t i) {
  return getToken(head_interactor::SEPAR, i);
}


size_t head_interactor::ArrayContext::getRuleIndex() const {
  return head_interactor::RuleArray;
}

void head_interactor::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void head_interactor::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

head_interactor::ArrayContext* head_interactor::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 24, head_interactor::RuleArray);
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
    setState(429);
    match(head_interactor::BEG_ARR);
    setState(433);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(430);
        match(head_interactor::WS); 
      }
      setState(435);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    }
    setState(436);
    input_array();
    setState(440);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(437);
      match(head_interactor::WS);
      setState(442);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::SEPAR) {
      setState(443);
      match(head_interactor::SEPAR);
      setState(447);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(444);
          match(head_interactor::WS); 
        }
        setState(449);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(450);
      input_array();
      setState(455);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(456);
    match(head_interactor::END_ARR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Input_arrayContext ------------------------------------------------------------------

head_interactor::Input_arrayContext::Input_arrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t head_interactor::Input_arrayContext::getRuleIndex() const {
  return head_interactor::RuleInput_array;
}

void head_interactor::Input_arrayContext::copyFrom(Input_arrayContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemArrayContext ------------------------------------------------------------------

head_interactor::ArrayContext* head_interactor::ItemArrayContext::array() {
  return getRuleContext<head_interactor::ArrayContext>(0);
}

head_interactor::ExprContext* head_interactor::ItemArrayContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}

head_interactor::ItemArrayContext::ItemArrayContext(Input_arrayContext *ctx) { copyFrom(ctx); }

void head_interactor::ItemArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItemArray(this);
}
void head_interactor::ItemArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItemArray(this);
}
head_interactor::Input_arrayContext* head_interactor::input_array() {
  Input_arrayContext *_localctx = _tracker.createInstance<Input_arrayContext>(_ctx, getState());
  enterRule(_localctx, 26, head_interactor::RuleInput_array);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(460);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::BEG_ARR: {
        _localctx = _tracker.createInstance<head_interactor::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(458);
        array();
        break;
      }

      case head_interactor::VAR_TAG:
      case head_interactor::VARIABLE:
      case head_interactor::SUMPRODUCT:
      case head_interactor::SUM:
      case head_interactor::SUM_I:
      case head_interactor::PRODUCT:
      case head_interactor::PRODUCT_I:
      case head_interactor::LN:
      case head_interactor::LG:
      case head_interactor::LOG_X:
      case head_interactor::EXP:
      case head_interactor::SQRT:
      case head_interactor::PI:
      case head_interactor::COS:
      case head_interactor::SIN:
      case head_interactor::ASIN:
      case head_interactor::ACOS:
      case head_interactor::FACTORIAL:
      case head_interactor::WS:
      case head_interactor::UINT:
      case head_interactor::Lb:
      case head_interactor::ADD:
      case head_interactor::SUB:
      case head_interactor::FLOAT: {
        _localctx = _tracker.createInstance<head_interactor::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(459);
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

head_interactor::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::NumberContext::UINT() {
  return getToken(head_interactor::UINT, 0);
}

tree::TerminalNode* head_interactor::NumberContext::FLOAT() {
  return getToken(head_interactor::FLOAT, 0);
}


size_t head_interactor::NumberContext::getRuleIndex() const {
  return head_interactor::RuleNumber;
}

void head_interactor::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void head_interactor::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

head_interactor::NumberContext* head_interactor::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 28, head_interactor::RuleNumber);
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
    setState(462);
    _la = _input->LA(1);
    if (!(_la == head_interactor::UINT

    || _la == head_interactor::FLOAT)) {
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

head_interactor::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::ConstantContext::PI() {
  return getToken(head_interactor::PI, 0);
}

tree::TerminalNode* head_interactor::ConstantContext::EXP() {
  return getToken(head_interactor::EXP, 0);
}


size_t head_interactor::ConstantContext::getRuleIndex() const {
  return head_interactor::RuleConstant;
}

void head_interactor::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void head_interactor::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

head_interactor::ConstantContext* head_interactor::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 30, head_interactor::RuleConstant);
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
    setState(464);
    _la = _input->LA(1);
    if (!(_la == head_interactor::EXP

    || _la == head_interactor::PI)) {
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

head_interactor::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::FunctionContext::LN() {
  return getToken(head_interactor::LN, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

std::vector<head_interactor::ExprContext *> head_interactor::FunctionContext::expr() {
  return getRuleContexts<head_interactor::ExprContext>();
}

head_interactor::ExprContext* head_interactor::FunctionContext::expr(size_t i) {
  return getRuleContext<head_interactor::ExprContext>(i);
}

tree::TerminalNode* head_interactor::FunctionContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

std::vector<tree::TerminalNode *> head_interactor::FunctionContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::FunctionContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

tree::TerminalNode* head_interactor::FunctionContext::LG() {
  return getToken(head_interactor::LG, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::EXP() {
  return getToken(head_interactor::EXP, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::SQRT() {
  return getToken(head_interactor::SQRT, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::COS() {
  return getToken(head_interactor::COS, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::SIN() {
  return getToken(head_interactor::SIN, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::ACOS() {
  return getToken(head_interactor::ACOS, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::ASIN() {
  return getToken(head_interactor::ASIN, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::FACTORIAL() {
  return getToken(head_interactor::FACTORIAL, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::LOG_X() {
  return getToken(head_interactor::LOG_X, 0);
}

tree::TerminalNode* head_interactor::FunctionContext::SEPAR() {
  return getToken(head_interactor::SEPAR, 0);
}


size_t head_interactor::FunctionContext::getRuleIndex() const {
  return head_interactor::RuleFunction;
}

void head_interactor::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void head_interactor::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

head_interactor::FunctionContext* head_interactor::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 32, head_interactor::RuleFunction);
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
    setState(760);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(469);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(466);
        match(head_interactor::WS);
        setState(471);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(472);
      match(head_interactor::LN);
      setState(473);
      match(head_interactor::Lb);
      setState(477);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(474);
          match(head_interactor::WS); 
        }
        setState(479);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      setState(480);
      expr(0);
      setState(484);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(481);
        match(head_interactor::WS);
        setState(486);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(487);
      match(head_interactor::Rb);
      setState(491);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(488);
          match(head_interactor::WS); 
        }
        setState(493);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(497);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(494);
        match(head_interactor::WS);
        setState(499);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(500);
      match(head_interactor::LG);
      setState(501);
      match(head_interactor::Lb);
      setState(505);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(502);
          match(head_interactor::WS); 
        }
        setState(507);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      setState(508);
      expr(0);
      setState(512);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(509);
        match(head_interactor::WS);
        setState(514);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(515);
      match(head_interactor::Rb);
      setState(519);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(516);
          match(head_interactor::WS); 
        }
        setState(521);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(525);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(522);
        match(head_interactor::WS);
        setState(527);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(528);
      match(head_interactor::EXP);
      setState(529);
      match(head_interactor::Lb);
      setState(533);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(530);
          match(head_interactor::WS); 
        }
        setState(535);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
      setState(536);
      expr(0);
      setState(540);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(537);
        match(head_interactor::WS);
        setState(542);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(543);
      match(head_interactor::Rb);
      setState(547);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(544);
          match(head_interactor::WS); 
        }
        setState(549);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(553);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(550);
        match(head_interactor::WS);
        setState(555);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(556);
      match(head_interactor::SQRT);
      setState(557);
      match(head_interactor::Lb);
      setState(561);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(558);
          match(head_interactor::WS); 
        }
        setState(563);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      }
      setState(564);
      expr(0);
      setState(568);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(565);
        match(head_interactor::WS);
        setState(570);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(571);
      match(head_interactor::Rb);
      setState(575);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(572);
          match(head_interactor::WS); 
        }
        setState(577);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(581);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(578);
        match(head_interactor::WS);
        setState(583);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(584);
      match(head_interactor::COS);
      setState(585);
      match(head_interactor::Lb);
      setState(589);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(586);
          match(head_interactor::WS); 
        }
        setState(591);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      }
      setState(592);
      expr(0);
      setState(596);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(593);
        match(head_interactor::WS);
        setState(598);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(599);
      match(head_interactor::Rb);
      setState(603);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(600);
          match(head_interactor::WS); 
        }
        setState(605);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(609);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(606);
        match(head_interactor::WS);
        setState(611);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(612);
      match(head_interactor::SIN);
      setState(613);
      match(head_interactor::Lb);
      setState(617);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(614);
          match(head_interactor::WS); 
        }
        setState(619);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(620);
      expr(0);
      setState(624);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(621);
        match(head_interactor::WS);
        setState(626);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(627);
      match(head_interactor::Rb);
      setState(631);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(628);
          match(head_interactor::WS); 
        }
        setState(633);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(634);
        match(head_interactor::WS);
        setState(639);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(640);
      match(head_interactor::ACOS);
      setState(641);
      match(head_interactor::Lb);
      setState(645);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(642);
          match(head_interactor::WS); 
        }
        setState(647);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
      setState(648);
      expr(0);
      setState(652);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(649);
        match(head_interactor::WS);
        setState(654);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(655);
      match(head_interactor::Rb);
      setState(659);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(656);
          match(head_interactor::WS); 
        }
        setState(661);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(665);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(662);
        match(head_interactor::WS);
        setState(667);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(668);
      match(head_interactor::ASIN);
      setState(669);
      match(head_interactor::Lb);
      setState(673);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(670);
          match(head_interactor::WS); 
        }
        setState(675);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      }
      setState(676);
      expr(0);
      setState(680);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(677);
        match(head_interactor::WS);
        setState(682);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(683);
      match(head_interactor::Rb);
      setState(687);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(684);
          match(head_interactor::WS); 
        }
        setState(689);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(693);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(690);
        match(head_interactor::WS);
        setState(695);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(696);
      match(head_interactor::FACTORIAL);
      setState(697);
      match(head_interactor::Lb);
      setState(701);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(698);
          match(head_interactor::WS); 
        }
        setState(703);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      }
      setState(704);
      expr(0);
      setState(708);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(705);
        match(head_interactor::WS);
        setState(710);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(711);
      match(head_interactor::Rb);
      setState(715);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(712);
          match(head_interactor::WS); 
        }
        setState(717);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(721);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(718);
        match(head_interactor::WS);
        setState(723);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(724);
      match(head_interactor::LOG_X);
      setState(725);
      match(head_interactor::Lb);
      setState(729);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(726);
          match(head_interactor::WS); 
        }
        setState(731);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      }
      setState(732);
      expr(0);
      setState(736);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(733);
        match(head_interactor::WS);
        setState(738);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(739);
      match(head_interactor::SEPAR);
      setState(743);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(740);
          match(head_interactor::WS); 
        }
        setState(745);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      }
      setState(746);
      expr(0);
      setState(750);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(747);
        match(head_interactor::WS);
        setState(752);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(753);
      match(head_interactor::Rb);
      setState(757);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(754);
          match(head_interactor::WS); 
        }
        setState(759);
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

head_interactor::MultiargfunctionContext::MultiargfunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::SUMPRODUCT() {
  return getToken(head_interactor::SUMPRODUCT, 0);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

std::vector<head_interactor::ExprContext *> head_interactor::MultiargfunctionContext::expr() {
  return getRuleContexts<head_interactor::ExprContext>();
}

head_interactor::ExprContext* head_interactor::MultiargfunctionContext::expr(size_t i) {
  return getRuleContext<head_interactor::ExprContext>(i);
}

std::vector<tree::TerminalNode *> head_interactor::MultiargfunctionContext::SEPAR() {
  return getTokens(head_interactor::SEPAR);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::SEPAR(size_t i) {
  return getToken(head_interactor::SEPAR, i);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

std::vector<tree::TerminalNode *> head_interactor::MultiargfunctionContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::SUM() {
  return getToken(head_interactor::SUM, 0);
}

tree::TerminalNode* head_interactor::MultiargfunctionContext::PRODUCT() {
  return getToken(head_interactor::PRODUCT, 0);
}


size_t head_interactor::MultiargfunctionContext::getRuleIndex() const {
  return head_interactor::RuleMultiargfunction;
}

void head_interactor::MultiargfunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiargfunction(this);
}

void head_interactor::MultiargfunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiargfunction(this);
}

head_interactor::MultiargfunctionContext* head_interactor::multiargfunction() {
  MultiargfunctionContext *_localctx = _tracker.createInstance<MultiargfunctionContext>(_ctx, getState());
  enterRule(_localctx, 34, head_interactor::RuleMultiargfunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(822);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(765);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(762);
        match(head_interactor::WS);
        setState(767);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(768);
      match(head_interactor::SUMPRODUCT);
      setState(769);
      match(head_interactor::Lb);
      setState(770);
      expr(0);
      setState(771);
      match(head_interactor::SEPAR);
      setState(772);
      expr(0);
      setState(777);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(773);
        match(head_interactor::SEPAR);
        setState(774);
        expr(0);
        setState(779);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(780);
      match(head_interactor::Rb);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(785);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(782);
        match(head_interactor::WS);
        setState(787);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(788);
      match(head_interactor::SUM);
      setState(789);
      match(head_interactor::Lb);
      setState(790);
      expr(0);
      setState(791);
      match(head_interactor::SEPAR);
      setState(792);
      expr(0);
      setState(797);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(793);
        match(head_interactor::SEPAR);
        setState(794);
        expr(0);
        setState(799);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(800);
      match(head_interactor::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(805);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(802);
        match(head_interactor::WS);
        setState(807);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(808);
      match(head_interactor::PRODUCT);
      setState(809);
      match(head_interactor::Lb);
      setState(810);
      expr(0);
      setState(811);
      match(head_interactor::SEPAR);
      setState(812);
      expr(0);
      setState(817);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(813);
        match(head_interactor::SEPAR);
        setState(814);
        expr(0);
        setState(819);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(820);
      match(head_interactor::Rb);
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

head_interactor::RangefunctionContext::RangefunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* head_interactor::RangefunctionContext::SUM_I() {
  return getToken(head_interactor::SUM_I, 0);
}

tree::TerminalNode* head_interactor::RangefunctionContext::Lb() {
  return getToken(head_interactor::Lb, 0);
}

head_interactor::ExprContext* head_interactor::RangefunctionContext::expr() {
  return getRuleContext<head_interactor::ExprContext>(0);
}

tree::TerminalNode* head_interactor::RangefunctionContext::Rb() {
  return getToken(head_interactor::Rb, 0);
}

std::vector<tree::TerminalNode *> head_interactor::RangefunctionContext::WS() {
  return getTokens(head_interactor::WS);
}

tree::TerminalNode* head_interactor::RangefunctionContext::WS(size_t i) {
  return getToken(head_interactor::WS, i);
}

tree::TerminalNode* head_interactor::RangefunctionContext::PRODUCT_I() {
  return getToken(head_interactor::PRODUCT_I, 0);
}


size_t head_interactor::RangefunctionContext::getRuleIndex() const {
  return head_interactor::RuleRangefunction;
}

void head_interactor::RangefunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangefunction(this);
}

void head_interactor::RangefunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangefunction(this);
}

head_interactor::RangefunctionContext* head_interactor::rangefunction() {
  RangefunctionContext *_localctx = _tracker.createInstance<RangefunctionContext>(_ctx, getState());
  enterRule(_localctx, 36, head_interactor::RuleRangefunction);
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
    setState(880);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(827);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(824);
        match(head_interactor::WS);
        setState(829);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(830);
      match(head_interactor::SUM_I);
      setState(831);
      match(head_interactor::Lb);
      setState(835);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(832);
          match(head_interactor::WS); 
        }
        setState(837);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      }
      setState(838);
      expr(0);
      setState(842);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(839);
        match(head_interactor::WS);
        setState(844);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(845);
      match(head_interactor::Rb);
      setState(849);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(846);
          match(head_interactor::WS); 
        }
        setState(851);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(855);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(852);
        match(head_interactor::WS);
        setState(857);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(858);
      match(head_interactor::PRODUCT_I);
      setState(859);
      match(head_interactor::Lb);
      setState(863);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(860);
          match(head_interactor::WS); 
        }
        setState(865);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      }
      setState(866);
      expr(0);
      setState(870);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(867);
        match(head_interactor::WS);
        setState(872);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(873);
      match(head_interactor::Rb);
      setState(877);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(874);
          match(head_interactor::WS); 
        }
        setState(879);
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

head_interactor::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> head_interactor::StringContext::DOUBLE_QUOTE() {
  return getTokens(head_interactor::DOUBLE_QUOTE);
}

tree::TerminalNode* head_interactor::StringContext::DOUBLE_QUOTE(size_t i) {
  return getToken(head_interactor::DOUBLE_QUOTE, i);
}

tree::TerminalNode* head_interactor::StringContext::STRING() {
  return getToken(head_interactor::STRING, 0);
}


size_t head_interactor::StringContext::getRuleIndex() const {
  return head_interactor::RuleString;
}

void head_interactor::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void head_interactor::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<head_interactorListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

head_interactor::StringContext* head_interactor::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 38, head_interactor::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(882);
    match(head_interactor::DOUBLE_QUOTE);
    setState(883);
    match(head_interactor::STRING);
    setState(884);
    match(head_interactor::DOUBLE_QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool head_interactor::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool head_interactor::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void head_interactor::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  head_interactorParserInitialize();
#else
  ::antlr4::internal::call_once(head_interactorParserOnceFlag, head_interactorParserInitialize);
#endif
}
