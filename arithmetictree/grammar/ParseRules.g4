grammar ParseRules;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

QUOTE: '\'';
VARIABLE: '__'([a-zA-Z])+ [*'0-9]*'__';
STRING: '"'[a-zA-Z0-9 .,:;!?]+'"';
VARIABLE_RANGE: '__'([a-zA-Z])+ '*'* QUOTE*([0-9]*)?'_arr__';
WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

fragment INT: [-+]? UINT;
UINT: [0-9]+ (EXPONENT)?;
EXPONENT: [eE] INT;
FLOAT: UINT '.' UINT (EXPONENT)?;

number
    : (UINT | FLOAT)
    ;

SUMPRODUCT: [sS][uU][mM][pP][rR][oO][dD][uU][cC][tT];
LN: [lL][nN];       
LG: [lL][gG];       
LOG_X: [lL][oO][gG]'_'[xX];   
EXP: [eE][xX][pP];     
SQRT: [sS][qQ][rR][tT];
PI: [pP][iI];

constant:
    (PI | EXP)
    ;

array
    :
    '['input_array (','input_array)*']'
    ;

input_array:
    (VARIABLE | number | constant) #ItemArray
    ;

vardefinition
    :
    VARIABLE WS* '=' WS* (expr | STRING | array) WS* EOL
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
    number (WS+ number)
    ;

expr
    : 
    '(' expr ')'                            # Parens
    | VARIABLE                              # Variable
    | (ADD | SUB) expr                      # UnaryOp
    | expr POW expr                         # BinaryOp  
    | expr (MUL | DIV) expr                 # BinaryOp
    | expr (ADD | SUB) expr                 # BinaryOp           
    | (function | multiargfunction)         # FunctionCall
    | (number | constant)                   # Literal
    ;

function
    : LN '(' WS* expr WS* ')'
    | LG '(' WS* expr WS* ')'
    | EXP '(' WS* expr WS* ')'
    | SQRT '(' WS* expr WS* ')'
    ;

multiargfunction
    :
    LOG_X '(' WS* expr WS* ',' WS* expr WS* ')'
    | SUMPRODUCT '(' expr ',' expr (',' expr )*')'
    ;