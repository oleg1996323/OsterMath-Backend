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
    table_definition
    | vardefinition
    | EOF
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
    | expr (MUL | DIV) expr                 # BinaryOp
    | expr (ADD | SUB) expr                 # BinaryOp
    | expr POW expr                         # PowerOp              
    | functions                             # FunctionCall
    | NUMBER                                # Number
    | CONSTANTS                             # Constant
    ;

array
    :
    '['(VARIABLE | NUMBER | CONSTANTS)(','VARIABLE | NUMBER | CONSTANTS)+']'
    ;

functions
    : LN '(' WS? expr WS? ')'                       #Natlog
    | LG '(' WS? expr WS? ')'                       #Declog
    | LOG_X '(' WS? expr WS? ',' WS? expr WS? ')'   #Baselog
    | EXP '(' WS? expr WS? ')'                      #Exponent
    | SQRT '(' WS? expr WS? ')'                     #Squareroot
    | SUMPRODUCT '(' expr ',' expr (',' expr )*')'  #Sumproduct
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