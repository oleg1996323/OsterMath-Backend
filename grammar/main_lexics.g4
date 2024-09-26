lexer grammar main_lexics;
import fundamental;

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
LG: L G;       
LOG_X: L O G '_' X;   
EXP: E X P;     
SQRT: S Q R T;
PI: P I;
COS: C O S;
SIN: S I N;
ASIN: A SIN;
ACOS: A COS;
FACTORIAL: F A C T O R I A L;
STRING: '"' ~["]* '"'
        | '\'' ~[']* '\''
    ;