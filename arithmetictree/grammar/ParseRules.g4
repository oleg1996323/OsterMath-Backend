grammar ParseRules;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

QUOTE: '\'';
VARIABLE: '__'([a-zA-Z])+ [*'0-9]*'__';
STRING: '"'[a-zA-Z0-9 .,:;!?]+'"';
VARIABLE_RANGE: VARIABLE'()';
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
SUMPRODUCT_I: SUMPRODUCT '_' [iI];
SUM: [sS][uU][mM];
SUM_I: SUM '_' [iI];
PRODUCT: [pP][rR][oO][dD][uU][cC][tT];
PRODUCT_I: PRODUCT '_' [iI];
LN: [lL][nN];       
LG: [lL][gG];       
LOG_X: [lL][oO][gG]'_'[xX];   
EXP: [eE][xX][pP];     
SQRT: [sS][qQ][rR][tT];
PI: [pP][iI];
COS: [cC][oO][sS];
SIN: [sS][iI][nN];
ASIN: [aA] SIN;
ACOS: [aA] COS;
FACTORIAL: [fF][aA][cC][tT][oO][rR][iI][aA][lL];

constant:
    (PI | EXP)
    ;

array
    :
    '['input_array (','input_array)*']'
    ;

input_array:
    expr #ItemArray
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
    '(' expr ')'                                            # Parens
    | VARIABLE                                              # Variable
    | (ADD | SUB) expr                                      # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr (MUL | DIV) expr                                 # BinaryOp
    | expr (ADD | SUB) expr                                 # BinaryOp           
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | (number | constant)                                   # Literal
    ;

function
    : LN '(' WS* expr WS* ')'
    | LG '(' WS* expr WS* ')'
    | EXP '(' WS* expr WS* ')'
    | SQRT '(' WS* expr WS* ')'
    | COS '('WS* expr WS*')'
    | SIN '('WS* expr WS*')'
    | ACOS '('WS* expr WS*')'
    | ASIN '('WS* expr WS*')'
    | FACTORIAL '('WS* expr WS*')'
    ;

variable_range_input:
    VARIABLE_RANGE
    ;

multiargfunction
    :
    LOG_X '(' WS* expr WS* ',' WS* expr WS* ')'
    | SUMPRODUCT '(' expr ',' expr (',' expr )*')'
    | SUM '(' expr ',' expr (',' expr )*')'
    | PRODUCT '(' expr ',' expr (',' expr )*')'
    ;

rangefunction
    :
    SUMPRODUCT_I '(' WS* variable_range_input WS* (','WS* variable_range_input WS*)* ')'
    | SUM_I '(' WS* variable_range_input WS* (','WS* variable_range_input WS*)* ')'
    | PRODUCT_I '(' WS* variable_range_input WS* (','WS* variable_range_input WS*)* ')'
    ;
