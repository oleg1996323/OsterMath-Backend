lexer grammar main_lexics;
import fundamental;

VAR_TAG: 'VAR';
BEG_ARR: '[';
END_ARR: ']';
DOUBLE_QUOTE: '"';
ESCAPED_DOUBLE_QUOTE: '\\"' {setText("\"");};

VARIABLE: '#' [a-zA-Z] ((QUOTE | ASTERISK) | [a-zA-Z0-9])* {setText(getText().substr(1, getText().length()-1));};
DATABASE: '!(\'' [a-zA-Z0-9_] (~[()!,;#' ])* '\')' {setText(getText().substr(3, getText().length()-5));}; 

LARGER: '>';
LARGER_EQUAL: ('>=' | '=>');
EQUAL: '=';
LESS: ('<=' | '=<');
LESS_EQUAL: '<';


SUMPRODUCT: S U M P R O D U C T;
SUMPRODUCT_I: SUMPRODUCT '_' I;
SUM: S U M;
SUM_I: SUM '_' I;
PRODUCT: P R O D U C T;
PRODUCT_I: PRODUCT '_' I;
LN: L N;       
LG: L G '10';
LOG_X: L O G '_' X;   
EXP: E X P;     
SQRT: S Q R T;
PI: P I;
COS: C O S;
SIN: S I N;
ASIN: A SIN;
ACOS: A COS;
FACTORIAL: F A C T O R I A L;
SEARCH_STRING: S E A R C H S T R I N G;
CONTAIN_TEXT: C O N T A I N T E X T;
CONCAT: C O N C A T;
WEIBULL_DISTRIB: W E I B U L L '.' D I S T;
GAUSS: G A U S S;
STD_NORM_DISTRIB: S T D '.' N O R M '.' D I S T;
NORM_DISTRIB: N O R M '.' D I S T;
GAMMA: G A M M A;
GAMMA_REV: G A M M A '.' R E V;
ROOT_MEAN_SQUARE: R M S;
ROOT_MEAN_SQUARE_ERROR: R M S E;
AVERAGE: A V E R A G E;
MEDIAN: M E D I A N;
PEARSON: P E A R S O N;


STRING_ARG: '"' (~[\n\r"] | ESCAPED_DOUBLE_QUOTE)* '"' {setText(getText().substr(1,getText().length()-1));}
            ;
STRING: WS* '=' WS* '"' (~[\n\r"] | ESCAPED_DOUBLE_QUOTE)* '"' WS* {setText(getText().substr(2,getText().length()-1));}|
        STRING_ARG |
        '\''(~[\n\r"] | ESCAPED_DOUBLE_QUOTE)* {setText(getText().substr(1,getText().length()));}
        ;