
// Generated from /home/oster/OsterMath-Backend/grammar/head_interactor.g4 by ANTLR 4.13.1


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
      "ID_NUMBER", "LbWS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,47,886,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,3,0,
  	44,8,0,1,1,1,1,1,2,4,2,49,8,2,11,2,12,2,50,1,2,3,2,54,8,2,1,3,1,3,3,3,
  	58,8,3,1,4,5,4,61,8,4,10,4,12,4,64,9,4,1,4,1,4,5,4,68,8,4,10,4,12,4,71,
  	9,4,1,4,1,4,5,4,75,8,4,10,4,12,4,78,9,4,1,4,1,4,5,4,82,8,4,10,4,12,4,
  	85,9,4,1,4,1,4,1,4,5,4,90,8,4,10,4,12,4,93,9,4,1,4,1,4,5,4,97,8,4,10,
  	4,12,4,100,9,4,1,4,1,4,5,4,104,8,4,10,4,12,4,107,9,4,1,4,5,4,110,8,4,
  	10,4,12,4,113,9,4,1,4,5,4,116,8,4,10,4,12,4,119,9,4,1,4,1,4,1,4,5,4,124,
  	8,4,10,4,12,4,127,9,4,3,4,129,8,4,1,5,5,5,132,8,5,10,5,12,5,135,9,5,1,
  	5,1,5,1,5,5,5,140,8,5,10,5,12,5,143,9,5,1,5,1,5,1,5,5,5,148,8,5,10,5,
  	12,5,151,9,5,1,5,5,5,154,8,5,10,5,12,5,157,9,5,1,5,1,5,5,5,161,8,5,10,
  	5,12,5,164,9,5,3,5,166,8,5,1,5,1,5,3,5,170,8,5,1,5,1,5,3,5,174,8,5,3,
  	5,176,8,5,1,5,5,5,179,8,5,10,5,12,5,182,9,5,1,6,5,6,185,8,6,10,6,12,6,
  	188,9,6,1,6,1,6,1,6,5,6,193,8,6,10,6,12,6,196,9,6,1,6,1,6,1,6,5,6,201,
  	8,6,10,6,12,6,204,9,6,1,6,5,6,207,8,6,10,6,12,6,210,9,6,1,6,1,6,5,6,214,
  	8,6,10,6,12,6,217,9,6,3,6,219,8,6,1,6,1,6,3,6,223,8,6,1,6,1,6,3,6,227,
  	8,6,3,6,229,8,6,1,6,5,6,232,8,6,10,6,12,6,235,9,6,1,6,1,6,5,6,239,8,6,
  	10,6,12,6,242,9,6,1,6,3,6,245,8,6,1,6,5,6,248,8,6,10,6,12,6,251,9,6,1,
  	6,1,6,1,7,5,7,256,8,7,10,7,12,7,259,9,7,1,7,1,7,1,7,5,7,264,8,7,10,7,
  	12,7,267,9,7,1,7,1,7,1,7,5,7,272,8,7,10,7,12,7,275,9,7,1,7,5,7,278,8,
  	7,10,7,12,7,281,9,7,1,7,1,7,5,7,285,8,7,10,7,12,7,288,9,7,3,7,290,8,7,
  	1,7,1,7,5,7,294,8,7,10,7,12,7,297,9,7,1,7,1,7,5,7,301,8,7,10,7,12,7,304,
  	9,7,3,7,306,8,7,1,7,5,7,309,8,7,10,7,12,7,312,9,7,1,7,1,7,5,7,316,8,7,
  	10,7,12,7,319,9,7,1,7,1,7,5,7,323,8,7,10,7,12,7,326,9,7,1,7,1,7,5,7,330,
  	8,7,10,7,12,7,333,9,7,1,7,1,7,5,7,337,8,7,10,7,12,7,340,9,7,1,7,1,7,5,
  	7,344,8,7,10,7,12,7,347,9,7,1,7,1,7,5,7,351,8,7,10,7,12,7,354,9,7,3,7,
  	356,8,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,3,11,375,8,11,1,11,1,11,3,11,379,8,11,1,11,1,11,5,11,
  	383,8,11,10,11,12,11,386,9,11,1,11,3,11,389,8,11,1,11,1,11,1,11,1,11,
  	1,11,5,11,396,8,11,10,11,12,11,399,9,11,1,11,1,11,5,11,403,8,11,10,11,
  	12,11,406,9,11,1,11,1,11,1,11,5,11,411,8,11,10,11,12,11,414,9,11,1,11,
  	1,11,5,11,418,8,11,10,11,12,11,421,9,11,1,11,5,11,424,8,11,10,11,12,11,
  	427,9,11,1,12,1,12,5,12,431,8,12,10,12,12,12,434,9,12,1,12,1,12,5,12,
  	438,8,12,10,12,12,12,441,9,12,1,12,1,12,5,12,445,8,12,10,12,12,12,448,
  	9,12,1,12,5,12,451,8,12,10,12,12,12,454,9,12,1,12,1,12,1,13,1,13,3,13,
  	460,8,13,1,14,1,14,1,15,1,15,1,16,5,16,467,8,16,10,16,12,16,470,9,16,
  	1,16,1,16,1,16,5,16,475,8,16,10,16,12,16,478,9,16,1,16,1,16,5,16,482,
  	8,16,10,16,12,16,485,9,16,1,16,1,16,5,16,489,8,16,10,16,12,16,492,9,16,
  	1,16,5,16,495,8,16,10,16,12,16,498,9,16,1,16,1,16,1,16,5,16,503,8,16,
  	10,16,12,16,506,9,16,1,16,1,16,5,16,510,8,16,10,16,12,16,513,9,16,1,16,
  	1,16,5,16,517,8,16,10,16,12,16,520,9,16,1,16,5,16,523,8,16,10,16,12,16,
  	526,9,16,1,16,1,16,1,16,5,16,531,8,16,10,16,12,16,534,9,16,1,16,1,16,
  	5,16,538,8,16,10,16,12,16,541,9,16,1,16,1,16,5,16,545,8,16,10,16,12,16,
  	548,9,16,1,16,5,16,551,8,16,10,16,12,16,554,9,16,1,16,1,16,1,16,5,16,
  	559,8,16,10,16,12,16,562,9,16,1,16,1,16,5,16,566,8,16,10,16,12,16,569,
  	9,16,1,16,1,16,5,16,573,8,16,10,16,12,16,576,9,16,1,16,5,16,579,8,16,
  	10,16,12,16,582,9,16,1,16,1,16,1,16,5,16,587,8,16,10,16,12,16,590,9,16,
  	1,16,1,16,5,16,594,8,16,10,16,12,16,597,9,16,1,16,1,16,5,16,601,8,16,
  	10,16,12,16,604,9,16,1,16,5,16,607,8,16,10,16,12,16,610,9,16,1,16,1,16,
  	1,16,5,16,615,8,16,10,16,12,16,618,9,16,1,16,1,16,5,16,622,8,16,10,16,
  	12,16,625,9,16,1,16,1,16,5,16,629,8,16,10,16,12,16,632,9,16,1,16,5,16,
  	635,8,16,10,16,12,16,638,9,16,1,16,1,16,1,16,5,16,643,8,16,10,16,12,16,
  	646,9,16,1,16,1,16,5,16,650,8,16,10,16,12,16,653,9,16,1,16,1,16,5,16,
  	657,8,16,10,16,12,16,660,9,16,1,16,5,16,663,8,16,10,16,12,16,666,9,16,
  	1,16,1,16,1,16,5,16,671,8,16,10,16,12,16,674,9,16,1,16,1,16,5,16,678,
  	8,16,10,16,12,16,681,9,16,1,16,1,16,5,16,685,8,16,10,16,12,16,688,9,16,
  	1,16,5,16,691,8,16,10,16,12,16,694,9,16,1,16,1,16,1,16,5,16,699,8,16,
  	10,16,12,16,702,9,16,1,16,1,16,5,16,706,8,16,10,16,12,16,709,9,16,1,16,
  	1,16,5,16,713,8,16,10,16,12,16,716,9,16,1,16,5,16,719,8,16,10,16,12,16,
  	722,9,16,1,16,1,16,1,16,5,16,727,8,16,10,16,12,16,730,9,16,1,16,1,16,
  	5,16,734,8,16,10,16,12,16,737,9,16,1,16,1,16,5,16,741,8,16,10,16,12,16,
  	744,9,16,1,16,1,16,5,16,748,8,16,10,16,12,16,751,9,16,1,16,1,16,5,16,
  	755,8,16,10,16,12,16,758,9,16,3,16,760,8,16,1,17,5,17,763,8,17,10,17,
  	12,17,766,9,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,775,8,17,10,17,
  	12,17,778,9,17,1,17,1,17,1,17,5,17,783,8,17,10,17,12,17,786,9,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,5,17,795,8,17,10,17,12,17,798,9,17,1,17,
  	1,17,1,17,5,17,803,8,17,10,17,12,17,806,9,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,815,8,17,10,17,12,17,818,9,17,1,17,1,17,3,17,822,8,17,
  	1,18,5,18,825,8,18,10,18,12,18,828,9,18,1,18,1,18,1,18,5,18,833,8,18,
  	10,18,12,18,836,9,18,1,18,1,18,5,18,840,8,18,10,18,12,18,843,9,18,1,18,
  	1,18,5,18,847,8,18,10,18,12,18,850,9,18,1,18,5,18,853,8,18,10,18,12,18,
  	856,9,18,1,18,1,18,1,18,5,18,861,8,18,10,18,12,18,864,9,18,1,18,1,18,
  	5,18,868,8,18,10,18,12,18,871,9,18,1,18,1,18,5,18,875,8,18,10,18,12,18,
  	878,9,18,3,18,880,8,18,1,19,1,19,1,19,1,19,1,19,0,1,22,20,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,5,1,0,7,11,1,0,37,38,1,0,
  	39,40,2,0,32,32,45,45,2,0,21,21,23,23,1010,0,43,1,0,0,0,2,45,1,0,0,0,
  	4,53,1,0,0,0,6,57,1,0,0,0,8,128,1,0,0,0,10,133,1,0,0,0,12,186,1,0,0,0,
  	14,257,1,0,0,0,16,359,1,0,0,0,18,361,1,0,0,0,20,363,1,0,0,0,22,388,1,
  	0,0,0,24,428,1,0,0,0,26,459,1,0,0,0,28,461,1,0,0,0,30,463,1,0,0,0,32,
  	759,1,0,0,0,34,821,1,0,0,0,36,879,1,0,0,0,38,881,1,0,0,0,40,44,3,24,12,
  	0,41,44,3,22,11,0,42,44,3,38,19,0,43,40,1,0,0,0,43,41,1,0,0,0,43,42,1,
  	0,0,0,44,1,1,0,0,0,45,46,7,0,0,0,46,3,1,0,0,0,47,49,3,6,3,0,48,47,1,0,
  	0,0,49,50,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,54,1,0,0,0,52,54,5,0,
  	0,1,53,48,1,0,0,0,53,52,1,0,0,0,54,5,1,0,0,0,55,58,3,12,6,0,56,58,3,14,
  	7,0,57,55,1,0,0,0,57,56,1,0,0,0,58,7,1,0,0,0,59,61,5,30,0,0,60,59,1,0,
  	0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,
  	0,0,65,69,5,33,0,0,66,68,5,30,0,0,67,66,1,0,0,0,68,71,1,0,0,0,69,67,1,
  	0,0,0,69,70,1,0,0,0,70,72,1,0,0,0,71,69,1,0,0,0,72,129,5,34,0,0,73,75,
  	5,47,0,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,79,
  	1,0,0,0,78,76,1,0,0,0,79,83,5,32,0,0,80,82,5,30,0,0,81,80,1,0,0,0,82,
  	85,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,86,1,0,0,0,85,83,1,0,0,0,86,
  	129,5,34,0,0,87,91,5,33,0,0,88,90,5,30,0,0,89,88,1,0,0,0,90,93,1,0,0,
  	0,91,89,1,0,0,0,91,92,1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,98,5,32,
  	0,0,95,97,5,30,0,0,96,95,1,0,0,0,97,100,1,0,0,0,98,96,1,0,0,0,98,99,1,
  	0,0,0,99,111,1,0,0,0,100,98,1,0,0,0,101,105,5,36,0,0,102,104,5,30,0,0,
  	103,102,1,0,0,0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,
  	1,0,0,0,107,105,1,0,0,0,108,110,5,32,0,0,109,101,1,0,0,0,110,113,1,0,
  	0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,117,1,0,0,0,113,111,1,0,0,0,114,
  	116,5,30,0,0,115,114,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,117,118,
  	1,0,0,0,118,120,1,0,0,0,119,117,1,0,0,0,120,121,5,34,0,0,121,125,1,0,
  	0,0,122,124,5,30,0,0,123,122,1,0,0,0,124,127,1,0,0,0,125,123,1,0,0,0,
  	125,126,1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,128,62,1,0,0,0,128,76,
  	1,0,0,0,128,87,1,0,0,0,129,9,1,0,0,0,130,132,5,30,0,0,131,130,1,0,0,0,
  	132,135,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,175,1,0,0,0,135,133,
  	1,0,0,0,136,137,5,1,0,0,137,165,5,33,0,0,138,140,5,30,0,0,139,138,1,0,
  	0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,0,143,
  	141,1,0,0,0,144,145,5,6,0,0,145,149,5,5,0,0,146,148,5,30,0,0,147,146,
  	1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,166,1,0,0,
  	0,151,149,1,0,0,0,152,154,5,30,0,0,153,152,1,0,0,0,154,157,1,0,0,0,155,
  	153,1,0,0,0,155,156,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,0,158,162,5,
  	5,0,0,159,161,5,30,0,0,160,159,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,
  	0,162,163,1,0,0,0,163,166,1,0,0,0,164,162,1,0,0,0,165,141,1,0,0,0,165,
  	155,1,0,0,0,166,167,1,0,0,0,167,169,5,34,0,0,168,170,3,8,4,0,169,168,
  	1,0,0,0,169,170,1,0,0,0,170,176,1,0,0,0,171,173,5,5,0,0,172,174,3,8,4,
  	0,173,172,1,0,0,0,173,174,1,0,0,0,174,176,1,0,0,0,175,136,1,0,0,0,175,
  	171,1,0,0,0,176,180,1,0,0,0,177,179,5,30,0,0,178,177,1,0,0,0,179,182,
  	1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,11,1,0,0,0,182,180,1,0,0,
  	0,183,185,5,30,0,0,184,183,1,0,0,0,185,188,1,0,0,0,186,184,1,0,0,0,186,
  	187,1,0,0,0,187,228,1,0,0,0,188,186,1,0,0,0,189,190,5,1,0,0,190,218,5,
  	33,0,0,191,193,5,30,0,0,192,191,1,0,0,0,193,196,1,0,0,0,194,192,1,0,0,
  	0,194,195,1,0,0,0,195,197,1,0,0,0,196,194,1,0,0,0,197,198,5,6,0,0,198,
  	202,5,5,0,0,199,201,5,30,0,0,200,199,1,0,0,0,201,204,1,0,0,0,202,200,
  	1,0,0,0,202,203,1,0,0,0,203,219,1,0,0,0,204,202,1,0,0,0,205,207,5,30,
  	0,0,206,205,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,209,1,0,0,0,209,
  	211,1,0,0,0,210,208,1,0,0,0,211,215,5,5,0,0,212,214,5,30,0,0,213,212,
  	1,0,0,0,214,217,1,0,0,0,215,213,1,0,0,0,215,216,1,0,0,0,216,219,1,0,0,
  	0,217,215,1,0,0,0,218,194,1,0,0,0,218,208,1,0,0,0,219,220,1,0,0,0,220,
  	222,5,34,0,0,221,223,3,8,4,0,222,221,1,0,0,0,222,223,1,0,0,0,223,229,
  	1,0,0,0,224,226,5,5,0,0,225,227,3,8,4,0,226,225,1,0,0,0,226,227,1,0,0,
  	0,227,229,1,0,0,0,228,189,1,0,0,0,228,224,1,0,0,0,229,233,1,0,0,0,230,
  	232,5,30,0,0,231,230,1,0,0,0,232,235,1,0,0,0,233,231,1,0,0,0,233,234,
  	1,0,0,0,234,236,1,0,0,0,235,233,1,0,0,0,236,240,5,9,0,0,237,239,5,30,
  	0,0,238,237,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,
  	244,1,0,0,0,242,240,1,0,0,0,243,245,3,0,0,0,244,243,1,0,0,0,244,245,1,
  	0,0,0,245,249,1,0,0,0,246,248,5,30,0,0,247,246,1,0,0,0,248,251,1,0,0,
  	0,249,247,1,0,0,0,249,250,1,0,0,0,250,252,1,0,0,0,251,249,1,0,0,0,252,
  	253,5,31,0,0,253,13,1,0,0,0,254,256,5,30,0,0,255,254,1,0,0,0,256,259,
  	1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,305,1,0,0,0,259,257,1,0,0,
  	0,260,261,5,1,0,0,261,289,5,33,0,0,262,264,5,30,0,0,263,262,1,0,0,0,264,
  	267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,268,1,0,0,0,267,265,1,
  	0,0,0,268,269,5,6,0,0,269,273,5,5,0,0,270,272,5,30,0,0,271,270,1,0,0,
  	0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,290,1,0,0,0,275,
  	273,1,0,0,0,276,278,5,30,0,0,277,276,1,0,0,0,278,281,1,0,0,0,279,277,
  	1,0,0,0,279,280,1,0,0,0,280,282,1,0,0,0,281,279,1,0,0,0,282,286,5,5,0,
  	0,283,285,5,30,0,0,284,283,1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,286,
  	287,1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,289,265,1,0,0,0,289,279,1,
  	0,0,0,290,291,1,0,0,0,291,306,5,34,0,0,292,294,5,30,0,0,293,292,1,0,0,
  	0,294,297,1,0,0,0,295,293,1,0,0,0,295,296,1,0,0,0,296,298,1,0,0,0,297,
  	295,1,0,0,0,298,302,5,5,0,0,299,301,5,30,0,0,300,299,1,0,0,0,301,304,
  	1,0,0,0,302,300,1,0,0,0,302,303,1,0,0,0,303,306,1,0,0,0,304,302,1,0,0,
  	0,305,260,1,0,0,0,305,295,1,0,0,0,306,310,1,0,0,0,307,309,5,30,0,0,308,
  	307,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,1,0,0,0,311,313,1,
  	0,0,0,312,310,1,0,0,0,313,317,5,35,0,0,314,316,5,30,0,0,315,314,1,0,0,
  	0,316,319,1,0,0,0,317,315,1,0,0,0,317,318,1,0,0,0,318,320,1,0,0,0,319,
  	317,1,0,0,0,320,324,3,16,8,0,321,323,5,30,0,0,322,321,1,0,0,0,323,326,
  	1,0,0,0,324,322,1,0,0,0,324,325,1,0,0,0,325,327,1,0,0,0,326,324,1,0,0,
  	0,327,331,3,2,1,0,328,330,5,30,0,0,329,328,1,0,0,0,330,333,1,0,0,0,331,
  	329,1,0,0,0,331,332,1,0,0,0,332,334,1,0,0,0,333,331,1,0,0,0,334,338,3,
  	18,9,0,335,337,5,30,0,0,336,335,1,0,0,0,337,340,1,0,0,0,338,336,1,0,0,
  	0,338,339,1,0,0,0,339,355,1,0,0,0,340,338,1,0,0,0,341,345,5,35,0,0,342,
  	344,5,30,0,0,343,342,1,0,0,0,344,347,1,0,0,0,345,343,1,0,0,0,345,346,
  	1,0,0,0,346,348,1,0,0,0,347,345,1,0,0,0,348,352,3,20,10,0,349,351,5,30,
  	0,0,350,349,1,0,0,0,351,354,1,0,0,0,352,350,1,0,0,0,352,353,1,0,0,0,353,
  	356,1,0,0,0,354,352,1,0,0,0,355,341,1,0,0,0,355,356,1,0,0,0,356,357,1,
  	0,0,0,357,358,5,31,0,0,358,15,1,0,0,0,359,360,3,22,11,0,360,17,1,0,0,
  	0,361,362,3,22,11,0,362,19,1,0,0,0,363,364,3,22,11,0,364,21,1,0,0,0,365,
  	366,6,11,-1,0,366,367,5,33,0,0,367,368,3,22,11,0,368,369,5,34,0,0,369,
  	389,1,0,0,0,370,389,3,10,5,0,371,375,3,32,16,0,372,375,3,34,17,0,373,
  	375,3,36,18,0,374,371,1,0,0,0,374,372,1,0,0,0,374,373,1,0,0,0,375,389,
  	1,0,0,0,376,379,3,28,14,0,377,379,3,30,15,0,378,376,1,0,0,0,378,377,1,
  	0,0,0,379,389,1,0,0,0,380,384,7,1,0,0,381,383,5,30,0,0,382,381,1,0,0,
  	0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,1,0,0,0,385,387,1,0,0,0,386,
  	384,1,0,0,0,387,389,3,22,11,4,388,365,1,0,0,0,388,370,1,0,0,0,388,374,
  	1,0,0,0,388,378,1,0,0,0,388,380,1,0,0,0,389,425,1,0,0,0,390,391,10,3,
  	0,0,391,392,5,41,0,0,392,424,3,22,11,4,393,397,10,2,0,0,394,396,5,30,
  	0,0,395,394,1,0,0,0,396,399,1,0,0,0,397,395,1,0,0,0,397,398,1,0,0,0,398,
  	400,1,0,0,0,399,397,1,0,0,0,400,404,7,2,0,0,401,403,5,30,0,0,402,401,
  	1,0,0,0,403,406,1,0,0,0,404,402,1,0,0,0,404,405,1,0,0,0,405,407,1,0,0,
  	0,406,404,1,0,0,0,407,424,3,22,11,3,408,412,10,1,0,0,409,411,5,30,0,0,
  	410,409,1,0,0,0,411,414,1,0,0,0,412,410,1,0,0,0,412,413,1,0,0,0,413,415,
  	1,0,0,0,414,412,1,0,0,0,415,419,7,1,0,0,416,418,5,30,0,0,417,416,1,0,
  	0,0,418,421,1,0,0,0,419,417,1,0,0,0,419,420,1,0,0,0,420,422,1,0,0,0,421,
  	419,1,0,0,0,422,424,3,22,11,2,423,390,1,0,0,0,423,393,1,0,0,0,423,408,
  	1,0,0,0,424,427,1,0,0,0,425,423,1,0,0,0,425,426,1,0,0,0,426,23,1,0,0,
  	0,427,425,1,0,0,0,428,432,5,2,0,0,429,431,5,30,0,0,430,429,1,0,0,0,431,
  	434,1,0,0,0,432,430,1,0,0,0,432,433,1,0,0,0,433,435,1,0,0,0,434,432,1,
  	0,0,0,435,439,3,26,13,0,436,438,5,30,0,0,437,436,1,0,0,0,438,441,1,0,
  	0,0,439,437,1,0,0,0,439,440,1,0,0,0,440,452,1,0,0,0,441,439,1,0,0,0,442,
  	446,5,36,0,0,443,445,5,30,0,0,444,443,1,0,0,0,445,448,1,0,0,0,446,444,
  	1,0,0,0,446,447,1,0,0,0,447,449,1,0,0,0,448,446,1,0,0,0,449,451,3,26,
  	13,0,450,442,1,0,0,0,451,454,1,0,0,0,452,450,1,0,0,0,452,453,1,0,0,0,
  	453,455,1,0,0,0,454,452,1,0,0,0,455,456,5,3,0,0,456,25,1,0,0,0,457,460,
  	3,24,12,0,458,460,3,22,11,0,459,457,1,0,0,0,459,458,1,0,0,0,460,27,1,
  	0,0,0,461,462,7,3,0,0,462,29,1,0,0,0,463,464,7,4,0,0,464,31,1,0,0,0,465,
  	467,5,30,0,0,466,465,1,0,0,0,467,470,1,0,0,0,468,466,1,0,0,0,468,469,
  	1,0,0,0,469,471,1,0,0,0,470,468,1,0,0,0,471,472,5,18,0,0,472,476,5,33,
  	0,0,473,475,5,30,0,0,474,473,1,0,0,0,475,478,1,0,0,0,476,474,1,0,0,0,
  	476,477,1,0,0,0,477,479,1,0,0,0,478,476,1,0,0,0,479,483,3,22,11,0,480,
  	482,5,30,0,0,481,480,1,0,0,0,482,485,1,0,0,0,483,481,1,0,0,0,483,484,
  	1,0,0,0,484,486,1,0,0,0,485,483,1,0,0,0,486,490,5,34,0,0,487,489,5,30,
  	0,0,488,487,1,0,0,0,489,492,1,0,0,0,490,488,1,0,0,0,490,491,1,0,0,0,491,
  	760,1,0,0,0,492,490,1,0,0,0,493,495,5,30,0,0,494,493,1,0,0,0,495,498,
  	1,0,0,0,496,494,1,0,0,0,496,497,1,0,0,0,497,499,1,0,0,0,498,496,1,0,0,
  	0,499,500,5,19,0,0,500,504,5,33,0,0,501,503,5,30,0,0,502,501,1,0,0,0,
  	503,506,1,0,0,0,504,502,1,0,0,0,504,505,1,0,0,0,505,507,1,0,0,0,506,504,
  	1,0,0,0,507,511,3,22,11,0,508,510,5,30,0,0,509,508,1,0,0,0,510,513,1,
  	0,0,0,511,509,1,0,0,0,511,512,1,0,0,0,512,514,1,0,0,0,513,511,1,0,0,0,
  	514,518,5,34,0,0,515,517,5,30,0,0,516,515,1,0,0,0,517,520,1,0,0,0,518,
  	516,1,0,0,0,518,519,1,0,0,0,519,760,1,0,0,0,520,518,1,0,0,0,521,523,5,
  	30,0,0,522,521,1,0,0,0,523,526,1,0,0,0,524,522,1,0,0,0,524,525,1,0,0,
  	0,525,527,1,0,0,0,526,524,1,0,0,0,527,528,5,21,0,0,528,532,5,33,0,0,529,
  	531,5,30,0,0,530,529,1,0,0,0,531,534,1,0,0,0,532,530,1,0,0,0,532,533,
  	1,0,0,0,533,535,1,0,0,0,534,532,1,0,0,0,535,539,3,22,11,0,536,538,5,30,
  	0,0,537,536,1,0,0,0,538,541,1,0,0,0,539,537,1,0,0,0,539,540,1,0,0,0,540,
  	542,1,0,0,0,541,539,1,0,0,0,542,546,5,34,0,0,543,545,5,30,0,0,544,543,
  	1,0,0,0,545,548,1,0,0,0,546,544,1,0,0,0,546,547,1,0,0,0,547,760,1,0,0,
  	0,548,546,1,0,0,0,549,551,5,30,0,0,550,549,1,0,0,0,551,554,1,0,0,0,552,
  	550,1,0,0,0,552,553,1,0,0,0,553,555,1,0,0,0,554,552,1,0,0,0,555,556,5,
  	22,0,0,556,560,5,33,0,0,557,559,5,30,0,0,558,557,1,0,0,0,559,562,1,0,
  	0,0,560,558,1,0,0,0,560,561,1,0,0,0,561,563,1,0,0,0,562,560,1,0,0,0,563,
  	567,3,22,11,0,564,566,5,30,0,0,565,564,1,0,0,0,566,569,1,0,0,0,567,565,
  	1,0,0,0,567,568,1,0,0,0,568,570,1,0,0,0,569,567,1,0,0,0,570,574,5,34,
  	0,0,571,573,5,30,0,0,572,571,1,0,0,0,573,576,1,0,0,0,574,572,1,0,0,0,
  	574,575,1,0,0,0,575,760,1,0,0,0,576,574,1,0,0,0,577,579,5,30,0,0,578,
  	577,1,0,0,0,579,582,1,0,0,0,580,578,1,0,0,0,580,581,1,0,0,0,581,583,1,
  	0,0,0,582,580,1,0,0,0,583,584,5,24,0,0,584,588,5,33,0,0,585,587,5,30,
  	0,0,586,585,1,0,0,0,587,590,1,0,0,0,588,586,1,0,0,0,588,589,1,0,0,0,589,
  	591,1,0,0,0,590,588,1,0,0,0,591,595,3,22,11,0,592,594,5,30,0,0,593,592,
  	1,0,0,0,594,597,1,0,0,0,595,593,1,0,0,0,595,596,1,0,0,0,596,598,1,0,0,
  	0,597,595,1,0,0,0,598,602,5,34,0,0,599,601,5,30,0,0,600,599,1,0,0,0,601,
  	604,1,0,0,0,602,600,1,0,0,0,602,603,1,0,0,0,603,760,1,0,0,0,604,602,1,
  	0,0,0,605,607,5,30,0,0,606,605,1,0,0,0,607,610,1,0,0,0,608,606,1,0,0,
  	0,608,609,1,0,0,0,609,611,1,0,0,0,610,608,1,0,0,0,611,612,5,25,0,0,612,
  	616,5,33,0,0,613,615,5,30,0,0,614,613,1,0,0,0,615,618,1,0,0,0,616,614,
  	1,0,0,0,616,617,1,0,0,0,617,619,1,0,0,0,618,616,1,0,0,0,619,623,3,22,
  	11,0,620,622,5,30,0,0,621,620,1,0,0,0,622,625,1,0,0,0,623,621,1,0,0,0,
  	623,624,1,0,0,0,624,626,1,0,0,0,625,623,1,0,0,0,626,630,5,34,0,0,627,
  	629,5,30,0,0,628,627,1,0,0,0,629,632,1,0,0,0,630,628,1,0,0,0,630,631,
  	1,0,0,0,631,760,1,0,0,0,632,630,1,0,0,0,633,635,5,30,0,0,634,633,1,0,
  	0,0,635,638,1,0,0,0,636,634,1,0,0,0,636,637,1,0,0,0,637,639,1,0,0,0,638,
  	636,1,0,0,0,639,640,5,27,0,0,640,644,5,33,0,0,641,643,5,30,0,0,642,641,
  	1,0,0,0,643,646,1,0,0,0,644,642,1,0,0,0,644,645,1,0,0,0,645,647,1,0,0,
  	0,646,644,1,0,0,0,647,651,3,22,11,0,648,650,5,30,0,0,649,648,1,0,0,0,
  	650,653,1,0,0,0,651,649,1,0,0,0,651,652,1,0,0,0,652,654,1,0,0,0,653,651,
  	1,0,0,0,654,658,5,34,0,0,655,657,5,30,0,0,656,655,1,0,0,0,657,660,1,0,
  	0,0,658,656,1,0,0,0,658,659,1,0,0,0,659,760,1,0,0,0,660,658,1,0,0,0,661,
  	663,5,30,0,0,662,661,1,0,0,0,663,666,1,0,0,0,664,662,1,0,0,0,664,665,
  	1,0,0,0,665,667,1,0,0,0,666,664,1,0,0,0,667,668,5,26,0,0,668,672,5,33,
  	0,0,669,671,5,30,0,0,670,669,1,0,0,0,671,674,1,0,0,0,672,670,1,0,0,0,
  	672,673,1,0,0,0,673,675,1,0,0,0,674,672,1,0,0,0,675,679,3,22,11,0,676,
  	678,5,30,0,0,677,676,1,0,0,0,678,681,1,0,0,0,679,677,1,0,0,0,679,680,
  	1,0,0,0,680,682,1,0,0,0,681,679,1,0,0,0,682,686,5,34,0,0,683,685,5,30,
  	0,0,684,683,1,0,0,0,685,688,1,0,0,0,686,684,1,0,0,0,686,687,1,0,0,0,687,
  	760,1,0,0,0,688,686,1,0,0,0,689,691,5,30,0,0,690,689,1,0,0,0,691,694,
  	1,0,0,0,692,690,1,0,0,0,692,693,1,0,0,0,693,695,1,0,0,0,694,692,1,0,0,
  	0,695,696,5,28,0,0,696,700,5,33,0,0,697,699,5,30,0,0,698,697,1,0,0,0,
  	699,702,1,0,0,0,700,698,1,0,0,0,700,701,1,0,0,0,701,703,1,0,0,0,702,700,
  	1,0,0,0,703,707,3,22,11,0,704,706,5,30,0,0,705,704,1,0,0,0,706,709,1,
  	0,0,0,707,705,1,0,0,0,707,708,1,0,0,0,708,710,1,0,0,0,709,707,1,0,0,0,
  	710,714,5,34,0,0,711,713,5,30,0,0,712,711,1,0,0,0,713,716,1,0,0,0,714,
  	712,1,0,0,0,714,715,1,0,0,0,715,760,1,0,0,0,716,714,1,0,0,0,717,719,5,
  	30,0,0,718,717,1,0,0,0,719,722,1,0,0,0,720,718,1,0,0,0,720,721,1,0,0,
  	0,721,723,1,0,0,0,722,720,1,0,0,0,723,724,5,20,0,0,724,728,5,33,0,0,725,
  	727,5,30,0,0,726,725,1,0,0,0,727,730,1,0,0,0,728,726,1,0,0,0,728,729,
  	1,0,0,0,729,731,1,0,0,0,730,728,1,0,0,0,731,735,3,22,11,0,732,734,5,30,
  	0,0,733,732,1,0,0,0,734,737,1,0,0,0,735,733,1,0,0,0,735,736,1,0,0,0,736,
  	738,1,0,0,0,737,735,1,0,0,0,738,742,5,36,0,0,739,741,5,30,0,0,740,739,
  	1,0,0,0,741,744,1,0,0,0,742,740,1,0,0,0,742,743,1,0,0,0,743,745,1,0,0,
  	0,744,742,1,0,0,0,745,749,3,22,11,0,746,748,5,30,0,0,747,746,1,0,0,0,
  	748,751,1,0,0,0,749,747,1,0,0,0,749,750,1,0,0,0,750,752,1,0,0,0,751,749,
  	1,0,0,0,752,756,5,34,0,0,753,755,5,30,0,0,754,753,1,0,0,0,755,758,1,0,
  	0,0,756,754,1,0,0,0,756,757,1,0,0,0,757,760,1,0,0,0,758,756,1,0,0,0,759,
  	468,1,0,0,0,759,496,1,0,0,0,759,524,1,0,0,0,759,552,1,0,0,0,759,580,1,
  	0,0,0,759,608,1,0,0,0,759,636,1,0,0,0,759,664,1,0,0,0,759,692,1,0,0,0,
  	759,720,1,0,0,0,760,33,1,0,0,0,761,763,5,30,0,0,762,761,1,0,0,0,763,766,
  	1,0,0,0,764,762,1,0,0,0,764,765,1,0,0,0,765,767,1,0,0,0,766,764,1,0,0,
  	0,767,768,5,12,0,0,768,769,5,33,0,0,769,770,3,22,11,0,770,771,5,36,0,
  	0,771,776,3,22,11,0,772,773,5,36,0,0,773,775,3,22,11,0,774,772,1,0,0,
  	0,775,778,1,0,0,0,776,774,1,0,0,0,776,777,1,0,0,0,777,779,1,0,0,0,778,
  	776,1,0,0,0,779,780,5,34,0,0,780,822,1,0,0,0,781,783,5,30,0,0,782,781,
  	1,0,0,0,783,786,1,0,0,0,784,782,1,0,0,0,784,785,1,0,0,0,785,787,1,0,0,
  	0,786,784,1,0,0,0,787,788,5,14,0,0,788,789,5,33,0,0,789,790,3,22,11,0,
  	790,791,5,36,0,0,791,796,3,22,11,0,792,793,5,36,0,0,793,795,3,22,11,0,
  	794,792,1,0,0,0,795,798,1,0,0,0,796,794,1,0,0,0,796,797,1,0,0,0,797,799,
  	1,0,0,0,798,796,1,0,0,0,799,800,5,34,0,0,800,822,1,0,0,0,801,803,5,30,
  	0,0,802,801,1,0,0,0,803,806,1,0,0,0,804,802,1,0,0,0,804,805,1,0,0,0,805,
  	807,1,0,0,0,806,804,1,0,0,0,807,808,5,16,0,0,808,809,5,33,0,0,809,810,
  	3,22,11,0,810,811,5,36,0,0,811,816,3,22,11,0,812,813,5,36,0,0,813,815,
  	3,22,11,0,814,812,1,0,0,0,815,818,1,0,0,0,816,814,1,0,0,0,816,817,1,0,
  	0,0,817,819,1,0,0,0,818,816,1,0,0,0,819,820,5,34,0,0,820,822,1,0,0,0,
  	821,764,1,0,0,0,821,784,1,0,0,0,821,804,1,0,0,0,822,35,1,0,0,0,823,825,
  	5,30,0,0,824,823,1,0,0,0,825,828,1,0,0,0,826,824,1,0,0,0,826,827,1,0,
  	0,0,827,829,1,0,0,0,828,826,1,0,0,0,829,830,5,15,0,0,830,834,5,33,0,0,
  	831,833,5,30,0,0,832,831,1,0,0,0,833,836,1,0,0,0,834,832,1,0,0,0,834,
  	835,1,0,0,0,835,837,1,0,0,0,836,834,1,0,0,0,837,841,3,22,11,0,838,840,
  	5,30,0,0,839,838,1,0,0,0,840,843,1,0,0,0,841,839,1,0,0,0,841,842,1,0,
  	0,0,842,844,1,0,0,0,843,841,1,0,0,0,844,848,5,34,0,0,845,847,5,30,0,0,
  	846,845,1,0,0,0,847,850,1,0,0,0,848,846,1,0,0,0,848,849,1,0,0,0,849,880,
  	1,0,0,0,850,848,1,0,0,0,851,853,5,30,0,0,852,851,1,0,0,0,853,856,1,0,
  	0,0,854,852,1,0,0,0,854,855,1,0,0,0,855,857,1,0,0,0,856,854,1,0,0,0,857,
  	858,5,17,0,0,858,862,5,33,0,0,859,861,5,30,0,0,860,859,1,0,0,0,861,864,
  	1,0,0,0,862,860,1,0,0,0,862,863,1,0,0,0,863,865,1,0,0,0,864,862,1,0,0,
  	0,865,869,3,22,11,0,866,868,5,30,0,0,867,866,1,0,0,0,868,871,1,0,0,0,
  	869,867,1,0,0,0,869,870,1,0,0,0,870,872,1,0,0,0,871,869,1,0,0,0,872,876,
  	5,34,0,0,873,875,5,30,0,0,874,873,1,0,0,0,875,878,1,0,0,0,876,874,1,0,
  	0,0,876,877,1,0,0,0,877,880,1,0,0,0,878,876,1,0,0,0,879,826,1,0,0,0,879,
  	854,1,0,0,0,880,37,1,0,0,0,881,882,5,4,0,0,882,883,5,29,0,0,883,884,5,
  	4,0,0,884,39,1,0,0,0,129,43,50,53,57,62,69,76,83,91,98,105,111,117,125,
  	128,133,141,149,155,162,165,169,173,175,180,186,194,202,208,215,218,222,
  	226,228,233,240,244,249,257,265,273,279,286,289,295,302,305,310,317,324,
  	331,338,345,352,355,374,378,384,388,397,404,412,419,423,425,432,439,446,
  	452,459,468,476,483,490,496,504,511,518,524,532,539,546,552,560,567,574,
  	580,588,595,602,608,616,623,630,636,644,651,658,664,672,679,686,692,700,
  	707,714,720,728,735,742,749,756,759,764,776,784,796,804,816,821,826,834,
  	841,848,854,862,869,876,879
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

std::vector<tree::TerminalNode *> head_interactor::Node_accessContext::LbWS() {
  return getTokens(head_interactor::LbWS);
}

tree::TerminalNode* head_interactor::Node_accessContext::LbWS(size_t i) {
  return getToken(head_interactor::LbWS, i);
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
    setState(128);
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
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::LbWS) {
        setState(73);
        match(head_interactor::LbWS);
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(79);
      match(head_interactor::UINT);
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(80);
        match(head_interactor::WS);
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(86);
      match(head_interactor::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
      match(head_interactor::Lb);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(88);
        match(head_interactor::WS);
        setState(93);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(94);
      match(head_interactor::UINT);
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(95);
          match(head_interactor::WS); 
        }
        setState(100);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(101);
        match(head_interactor::SEPAR);
        setState(105);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == head_interactor::WS) {
          setState(102);
          match(head_interactor::WS);
          setState(107);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(108);
        match(head_interactor::UINT);
        setState(113);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(114);
        match(head_interactor::WS);
        setState(119);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(120);
      match(head_interactor::Rb);
      setState(125);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(122);
          match(head_interactor::WS); 
        }
        setState(127);
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
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(130);
      match(head_interactor::WS);
      setState(135);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(136);
        match(head_interactor::VAR_TAG);
        setState(137);
        match(head_interactor::Lb);
        setState(165);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(141);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(138);
            match(head_interactor::WS);
            setState(143);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(144);
          match(head_interactor::DATABASE);
          setState(145);
          match(head_interactor::VARIABLE);
          setState(149);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(146);
            match(head_interactor::WS);
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
          while (_la == head_interactor::WS) {
            setState(152);
            match(head_interactor::WS);
            setState(157);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(158);
          match(head_interactor::VARIABLE);
          setState(162);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(159);
            match(head_interactor::WS);
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
        match(head_interactor::Rb);
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

      case head_interactor::VARIABLE: {
        setState(171);
        match(head_interactor::VARIABLE);
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
        match(head_interactor::WS); 
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
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(183);
      match(head_interactor::WS);
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(189);
        match(head_interactor::VAR_TAG);
        setState(190);
        match(head_interactor::Lb);
        setState(218);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          setState(194);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(191);
            match(head_interactor::WS);
            setState(196);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(197);
          match(head_interactor::DATABASE);
          setState(198);
          match(head_interactor::VARIABLE);
          setState(202);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(199);
            match(head_interactor::WS);
            setState(204);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(208);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(205);
            match(head_interactor::WS);
            setState(210);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(211);
          match(head_interactor::VARIABLE);
          setState(215);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(212);
            match(head_interactor::WS);
            setState(217);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(220);
        match(head_interactor::Rb);
        setState(222);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          setState(221);
          node_access();
          break;
        }

        default:
          break;
        }
        break;
      }

      case head_interactor::VARIABLE: {
        setState(224);
        match(head_interactor::VARIABLE);
        setState(226);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          setState(225);
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
    setState(233);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(230);
      match(head_interactor::WS);
      setState(235);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(236);
    match(head_interactor::EQUAL);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(237);
        match(head_interactor::WS); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(244);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(243);
      value_type();
      break;
    }

    default:
      break;
    }
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(246);
      match(head_interactor::WS);
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(252);
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
    setState(257);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(254);
        match(head_interactor::WS); 
      }
      setState(259);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::VAR_TAG: {
        setState(260);
        match(head_interactor::VAR_TAG);
        setState(261);
        match(head_interactor::Lb);
        setState(289);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          setState(265);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(262);
            match(head_interactor::WS);
            setState(267);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(268);
          match(head_interactor::DATABASE);
          setState(269);
          match(head_interactor::VARIABLE);
          setState(273);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(270);
            match(head_interactor::WS);
            setState(275);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(279);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(276);
            match(head_interactor::WS);
            setState(281);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(282);
          match(head_interactor::VARIABLE);
          setState(286);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(283);
            match(head_interactor::WS);
            setState(288);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        default:
          break;
        }
        setState(291);
        match(head_interactor::Rb);
        break;
      }

      case head_interactor::VARIABLE:
      case head_interactor::WS: {
        setState(295);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == head_interactor::WS) {
          setState(292);
          match(head_interactor::WS);
          setState(297);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(298);
        match(head_interactor::VARIABLE);
        setState(302);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(299);
            match(head_interactor::WS); 
          }
          setState(304);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(307);
      match(head_interactor::WS);
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(313);
    match(head_interactor::COL);
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(314);
        match(head_interactor::WS); 
      }
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    }
    setState(320);
    lhs_comp();
    setState(324);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(321);
      match(head_interactor::WS);
      setState(326);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(327);
    comparator();
    setState(331);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(328);
        match(head_interactor::WS); 
      }
      setState(333);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(334);
    rhs_comp();
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(335);
      match(head_interactor::WS);
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == head_interactor::COL) {
      setState(341);
      match(head_interactor::COL);
      setState(345);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(342);
          match(head_interactor::WS); 
        }
        setState(347);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      setState(348);
      expr_comp();
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(349);
        match(head_interactor::WS);
        setState(354);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(357);
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
    setState(363);
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
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(366);
      match(head_interactor::Lb);
      setState(367);
      expr(0);
      setState(368);
      match(head_interactor::Rb);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableInExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(370);
      variable();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(374);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(371);
        function();
        break;
      }

      case 2: {
        setState(372);
        multiargfunction();
        break;
      }

      case 3: {
        setState(373);
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
      setState(378);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case head_interactor::UINT:
        case head_interactor::FLOAT: {
          setState(376);
          number();
          break;
        }

        case head_interactor::EXP:
        case head_interactor::PI: {
          setState(377);
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
      setState(380);
      _la = _input->LA(1);
      if (!(_la == head_interactor::ADD

      || _la == head_interactor::SUB)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(381);
          match(head_interactor::WS); 
        }
        setState(386);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
      }
      setState(387);
      expr(4);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(425);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(423);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(390);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(391);
          match(head_interactor::POW);
          setState(392);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(393);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(397);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(394);
            match(head_interactor::WS);
            setState(399);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(400);
          _la = _input->LA(1);
          if (!(_la == head_interactor::MUL

          || _la == head_interactor::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(404);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(401);
              match(head_interactor::WS); 
            }
            setState(406);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
          }
          setState(407);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(408);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(412);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == head_interactor::WS) {
            setState(409);
            match(head_interactor::WS);
            setState(414);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(415);
          _la = _input->LA(1);
          if (!(_la == head_interactor::ADD

          || _la == head_interactor::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(419);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(416);
              match(head_interactor::WS); 
            }
            setState(421);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
          }
          setState(422);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(427);
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
    setState(428);
    match(head_interactor::BEG_ARR);
    setState(432);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(429);
        match(head_interactor::WS); 
      }
      setState(434);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    }
    setState(435);
    input_array();
    setState(439);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::WS) {
      setState(436);
      match(head_interactor::WS);
      setState(441);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(452);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == head_interactor::SEPAR) {
      setState(442);
      match(head_interactor::SEPAR);
      setState(446);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(443);
          match(head_interactor::WS); 
        }
        setState(448);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(449);
      input_array();
      setState(454);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(455);
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
    setState(459);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case head_interactor::BEG_ARR: {
        _localctx = _tracker.createInstance<head_interactor::ItemArrayContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(457);
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
        setState(458);
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
    setState(461);
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
    setState(463);
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
    setState(759);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(468);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(465);
        match(head_interactor::WS);
        setState(470);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(471);
      match(head_interactor::LN);
      setState(472);
      match(head_interactor::Lb);
      setState(476);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(473);
          match(head_interactor::WS); 
        }
        setState(478);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      setState(479);
      expr(0);
      setState(483);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(480);
        match(head_interactor::WS);
        setState(485);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(486);
      match(head_interactor::Rb);
      setState(490);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(487);
          match(head_interactor::WS); 
        }
        setState(492);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(496);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(493);
        match(head_interactor::WS);
        setState(498);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(499);
      match(head_interactor::LG);
      setState(500);
      match(head_interactor::Lb);
      setState(504);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(501);
          match(head_interactor::WS); 
        }
        setState(506);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      setState(507);
      expr(0);
      setState(511);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(508);
        match(head_interactor::WS);
        setState(513);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(514);
      match(head_interactor::Rb);
      setState(518);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(515);
          match(head_interactor::WS); 
        }
        setState(520);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(524);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(521);
        match(head_interactor::WS);
        setState(526);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(527);
      match(head_interactor::EXP);
      setState(528);
      match(head_interactor::Lb);
      setState(532);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(529);
          match(head_interactor::WS); 
        }
        setState(534);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
      }
      setState(535);
      expr(0);
      setState(539);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(536);
        match(head_interactor::WS);
        setState(541);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(542);
      match(head_interactor::Rb);
      setState(546);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(543);
          match(head_interactor::WS); 
        }
        setState(548);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(552);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(549);
        match(head_interactor::WS);
        setState(554);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(555);
      match(head_interactor::SQRT);
      setState(556);
      match(head_interactor::Lb);
      setState(560);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(557);
          match(head_interactor::WS); 
        }
        setState(562);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      }
      setState(563);
      expr(0);
      setState(567);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(564);
        match(head_interactor::WS);
        setState(569);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(570);
      match(head_interactor::Rb);
      setState(574);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(571);
          match(head_interactor::WS); 
        }
        setState(576);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(580);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(577);
        match(head_interactor::WS);
        setState(582);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(583);
      match(head_interactor::COS);
      setState(584);
      match(head_interactor::Lb);
      setState(588);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(585);
          match(head_interactor::WS); 
        }
        setState(590);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx);
      }
      setState(591);
      expr(0);
      setState(595);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(592);
        match(head_interactor::WS);
        setState(597);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(598);
      match(head_interactor::Rb);
      setState(602);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(599);
          match(head_interactor::WS); 
        }
        setState(604);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(608);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(605);
        match(head_interactor::WS);
        setState(610);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(611);
      match(head_interactor::SIN);
      setState(612);
      match(head_interactor::Lb);
      setState(616);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(613);
          match(head_interactor::WS); 
        }
        setState(618);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(619);
      expr(0);
      setState(623);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(620);
        match(head_interactor::WS);
        setState(625);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(626);
      match(head_interactor::Rb);
      setState(630);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(627);
          match(head_interactor::WS); 
        }
        setState(632);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
      }
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(636);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(633);
        match(head_interactor::WS);
        setState(638);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(639);
      match(head_interactor::ACOS);
      setState(640);
      match(head_interactor::Lb);
      setState(644);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(641);
          match(head_interactor::WS); 
        }
        setState(646);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
      }
      setState(647);
      expr(0);
      setState(651);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(648);
        match(head_interactor::WS);
        setState(653);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(654);
      match(head_interactor::Rb);
      setState(658);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(655);
          match(head_interactor::WS); 
        }
        setState(660);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      }
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(664);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(661);
        match(head_interactor::WS);
        setState(666);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(667);
      match(head_interactor::ASIN);
      setState(668);
      match(head_interactor::Lb);
      setState(672);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(669);
          match(head_interactor::WS); 
        }
        setState(674);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      }
      setState(675);
      expr(0);
      setState(679);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(676);
        match(head_interactor::WS);
        setState(681);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(682);
      match(head_interactor::Rb);
      setState(686);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(683);
          match(head_interactor::WS); 
        }
        setState(688);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
      }
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(692);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(689);
        match(head_interactor::WS);
        setState(694);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(695);
      match(head_interactor::FACTORIAL);
      setState(696);
      match(head_interactor::Lb);
      setState(700);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(697);
          match(head_interactor::WS); 
        }
        setState(702);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
      }
      setState(703);
      expr(0);
      setState(707);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(704);
        match(head_interactor::WS);
        setState(709);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(710);
      match(head_interactor::Rb);
      setState(714);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(711);
          match(head_interactor::WS); 
        }
        setState(716);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
      }
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(720);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(717);
        match(head_interactor::WS);
        setState(722);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(723);
      match(head_interactor::LOG_X);
      setState(724);
      match(head_interactor::Lb);
      setState(728);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(725);
          match(head_interactor::WS); 
        }
        setState(730);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      }
      setState(731);
      expr(0);
      setState(735);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(732);
        match(head_interactor::WS);
        setState(737);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(738);
      match(head_interactor::SEPAR);
      setState(742);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(739);
          match(head_interactor::WS); 
        }
        setState(744);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      }
      setState(745);
      expr(0);
      setState(749);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(746);
        match(head_interactor::WS);
        setState(751);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(752);
      match(head_interactor::Rb);
      setState(756);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(753);
          match(head_interactor::WS); 
        }
        setState(758);
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
    setState(821);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(764);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(761);
        match(head_interactor::WS);
        setState(766);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(767);
      match(head_interactor::SUMPRODUCT);
      setState(768);
      match(head_interactor::Lb);
      setState(769);
      expr(0);
      setState(770);
      match(head_interactor::SEPAR);
      setState(771);
      expr(0);
      setState(776);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(772);
        match(head_interactor::SEPAR);
        setState(773);
        expr(0);
        setState(778);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(779);
      match(head_interactor::Rb);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(784);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(781);
        match(head_interactor::WS);
        setState(786);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(787);
      match(head_interactor::SUM);
      setState(788);
      match(head_interactor::Lb);
      setState(789);
      expr(0);
      setState(790);
      match(head_interactor::SEPAR);
      setState(791);
      expr(0);
      setState(796);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(792);
        match(head_interactor::SEPAR);
        setState(793);
        expr(0);
        setState(798);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(799);
      match(head_interactor::Rb);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(804);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(801);
        match(head_interactor::WS);
        setState(806);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(807);
      match(head_interactor::PRODUCT);
      setState(808);
      match(head_interactor::Lb);
      setState(809);
      expr(0);
      setState(810);
      match(head_interactor::SEPAR);
      setState(811);
      expr(0);
      setState(816);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::SEPAR) {
        setState(812);
        match(head_interactor::SEPAR);
        setState(813);
        expr(0);
        setState(818);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(819);
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
    setState(879);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(826);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(823);
        match(head_interactor::WS);
        setState(828);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(829);
      match(head_interactor::SUM_I);
      setState(830);
      match(head_interactor::Lb);
      setState(834);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(831);
          match(head_interactor::WS); 
        }
        setState(836);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx);
      }
      setState(837);
      expr(0);
      setState(841);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(838);
        match(head_interactor::WS);
        setState(843);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(844);
      match(head_interactor::Rb);
      setState(848);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(845);
          match(head_interactor::WS); 
        }
        setState(850);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(854);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(851);
        match(head_interactor::WS);
        setState(856);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(857);
      match(head_interactor::PRODUCT_I);
      setState(858);
      match(head_interactor::Lb);
      setState(862);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(859);
          match(head_interactor::WS); 
        }
        setState(864);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx);
      }
      setState(865);
      expr(0);
      setState(869);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == head_interactor::WS) {
        setState(866);
        match(head_interactor::WS);
        setState(871);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(872);
      match(head_interactor::Rb);
      setState(876);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(873);
          match(head_interactor::WS); 
        }
        setState(878);
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
    setState(881);
    match(head_interactor::DOUBLE_QUOTE);
    setState(882);
    match(head_interactor::STRING);
    setState(883);
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
