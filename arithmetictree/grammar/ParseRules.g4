grammar ParseRules;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

QUOTE: '\'';
ASTERISK: '^' '*'+;

WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

fragment INT: [-+]? UINT;
EXPONENT: [eE] INT;
UINT: [0-9]+ (EXPONENT)?;
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
DATABASE: '$('([a-zA-Z0-9_]) [a-zA-Z0-9 _]*')';
VARIABLE: '#'([a-zA-Z])+ ((QUOTE | ASTERISK) | [a-zA-Z0-9])*;
STRING: '\''[a-zA-Z0-9_] [a-zA-Z0-9 _,.;!?]*;

variable:
    WS* ( DATABASE )? VARIABLE WS*
    ;

constant:
    (PI | EXP)
    ;

input_array:
    expr #ItemArray
    ;

array
    :
    '['input_array (','input_array)*']'
    ;
    
string
    :
    STRING
    ;

vardefinition
    :
    variable '=' WS* (expr | string | array) WS* EOL
    ;

input:
    line_input+
    | EOF
    ;

line_input:
    table_definition+
    | vardefinition+
    | comparision+
    ;

table_definition:
    hdr EOL numbers_line EOL
    ;

hdr:
    variable (WS variable)+
    ;

numbers_line:
    WS* number (WS+ number) WS*
    ;

expr
    : 
    '(' expr ')'                                            # Parens
    | (number | constant)                                   # Literal
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | variable                                              # VariableInExpr
    | (ADD | SUB) WS* expr                                  # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr WS* (MUL | DIV) WS* expr                         # BinaryOp
    | expr WS* (ADD | SUB) WS* expr                         # BinaryOp
    ;

function
    : WS* LN '(' WS* expr WS* ')' WS*
    | WS* LG '(' WS* expr WS* ')' WS*
    | WS* EXP '(' WS* expr WS* ')' WS*
    | WS* SQRT '(' WS* expr WS* ')' WS*
    | WS* COS '('WS* expr WS*')' WS*
    | WS* SIN '('WS* expr WS*')' WS*
    | WS* ACOS '('WS* expr WS*')' WS*
    | WS* ASIN '('WS* expr WS*')' WS*
    | WS* FACTORIAL '('WS* expr WS*')' WS*
    | WS* LOG_X '(' WS* expr WS* ',' WS* expr WS* ')' WS*
    ;

multiargfunction
    :
    WS* SUMPRODUCT '(' expr ',' expr (',' expr )*')'
    | WS* SUM '(' expr ',' expr (',' expr )*')'
    | WS* PRODUCT '(' expr ',' expr (',' expr )*')'
    ;

rangefunction
    :
    WS* SUMPRODUCT_I '(' WS* expr WS* ')' WS*
    | WS* SUM_I '(' WS* expr WS* ')' WS*
    | WS* PRODUCT_I '(' WS* expr WS* ')' WS*
    ;

comparision
    :
    variable ':' variable '<' WS* expr WS* EOL              #less
    | variable ':' WS* expr WS* '>' variable EOL            #less
    | variable ':' variable ('<=' | '=<') WS* expr WS* EOL  #less_equal
    | variable ':' WS* expr WS* ('>=' | '=>') variable EOL  #less_equal
    | variable ':' variable '>' WS* expr WS* EOL            #larger
    | variable ':' WS* expr WS* '<' variable EOL            #larger
    | variable ':' variable ('>=' | '=>') WS* expr WS* EOL  #larger_equal
    | variable ':' WS* expr WS* ('<=' | '=<') variable EOL  #larger_equal
    ;