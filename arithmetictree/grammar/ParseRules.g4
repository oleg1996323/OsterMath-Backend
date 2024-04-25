grammar ParseRules;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

vardefinition
    :
    VARIABLE WS* '=' WS* (expr | STRING) WS* EOL
    ;

input:
    line_input+
    | EOF
    ;

line_input:
    table_definition+
    | vardefinition+
    ;

table_definition:
    hdr EOL numbers_line EOL
    ;

hdr:
    VARIABLE (WS+ VARIABLE)+
    ;

numbers_line:
    NUMBER (WS+ NUMBER)
    ;

expr
    : 
    '(' expr ')'                            # Parens
    | VARIABLE                              # Variable
    | (ADD | SUB) expr                      # UnaryOp
    | expr POW expr                         # BinaryOp  
    | expr (MUL | DIV) expr                 # BinaryOp
    | expr (ADD | SUB) expr                 # BinaryOp           
    | functions                             # FunctionCall
    | NUMBER                                # Number
    | CONSTANTS                             # Constant
    ;

array
    :
    '['(VARIABLE | NUMBER | CONSTANTS)(','VARIABLE | NUMBER | CONSTANTS)+']'
    ;

functions
    : LN '(' WS? expr WS? ')'
    | LG '(' WS? expr WS? ')'
    | LOG_X '(' WS? expr WS? ',' WS? expr WS? ')'
    | EXP '(' WS? expr WS? ')'
    | SQRT '(' WS? expr WS? ')'
    | SUMPRODUCT '(' expr ',' expr (',' expr )*')'
    ;

QUOTE: '\'';
VARIABLE: '__'([a-zA-Z])+ '*'* QUOTE*([0-9]*)?'__';
STRING: '"'[a-zA-Z0-9 .,:;!?]+'"';
VARIABLE_RANGE: '__'([a-zA-Z])+ '*'* QUOTE*([0-9]*)?'_arr__';
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