grammar definitions;

main:
    ;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

STRING: '"'[a-zA-Z0-9 .,:;!?]+'"';
VARIABLE: '__'[a-zA-Z*']+([0-9]*)?'__';
VARIABLE_RANGE: '__'[a-zA-Z*']+([0-9]*)?'_arr__';
WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;
fragment FLOAT: UINT '.' UINT (EXPONENT)?;

NUMBER
    : (UINT | FLOAT) EXPONENT?
    ;

CONSTANTS:
    PI
    ;

SUMPRODUCT: 'sumproduct';
LN: 'Ln';       
LG: 'Lg';       
LOG_X: 'Log';   
EXP: 'Exp';     
SQRT: 'Sqrt';

PI: 'Pi' | 'PI' | 'pi' WS;