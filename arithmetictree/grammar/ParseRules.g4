grammar ParseRules;

VARIABLE: [a-zA-Z] ((QUOTE | ASTERISK) | [a-zA-Z0-9])*;
DATABASE: [a-zA-Z0-9_] [a-zA-Z0-9 _]*;
WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

input:
    line_input+
    | EOF
    ;

line_input:
    vardefinition
    | comparision
    | table_definition
    ;

vardefinition
    :
    variable '=' WS* (array | expr | string) WS* EOL
    ;

variable:
    WS* ('$(' DATABASE ')')? '#' VARIABLE WS*
    ;

expr
    : 
    '(' expr ')'                                            # Parens
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | variable                                              # VariableInExpr
    | (number | constant)                                   # Literal
    | (ADD | SUB) WS* expr                                  # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr WS* (MUL | DIV) WS* expr                         # BinaryOp
    | expr WS* (ADD | SUB) WS* expr                         # BinaryOp
    ;

array
    :
    '['input_array (','input_array)*']'
    ;

input_array:
    expr #ItemArray
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

number
    : (UINT | FLOAT)
    ;

constant:
    (PI | EXP)
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
    WS* SUM_I '(' WS* expr WS* ')' WS*
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

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

fragment A : [aA];
fragment B : [bB];
fragment C : [cC];
fragment D : [dD];
fragment E : [eE];
fragment F : [fF];
fragment G : [gG];
fragment H : [hH];
fragment I : [iI];
fragment J : [jJ];
fragment K : [kK];
fragment L : [lL];
fragment M : [mM];
fragment N : [nN];
fragment O : [oO];
fragment P : [pP];
fragment Q : [qQ];
fragment R : [rR];
fragment S : [sS];
fragment T : [tT];
fragment U : [uU];
fragment V : [vV];
fragment W : [wW];
fragment X : [xX];
fragment Y : [yY];
fragment Z : [zZ];

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

QUOTE: '\'';
ASTERISK: '^' '*'+;

fragment INT: [-+]? UINT;
EXPONENT: [eE] INT;
UINT: [0-9]+ (EXPONENT)?;
FLOAT: INT '.' UINT (EXPONENT)?;

string
    :
    '"' STRING '"'
    ;

STRING: .*?;