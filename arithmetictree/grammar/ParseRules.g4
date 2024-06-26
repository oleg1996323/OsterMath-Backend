grammar ParseRules;

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

VARIABLE: '#' [a-zA-Z] ((QUOTE | ASTERISK) | [a-zA-Z0-9])* {setText(getText().substr(1, getText().length()-1));};
DATABASE: '!(\'' [a-zA-Z0-9_] (~[()!,;#' ])* '\')' {setText(getText().substr(3, getText().length()-5));}; 
WS: [ \t]+ -> skip;
EOL: '\r'? '\n';
LARGER: '>';
LARGER_EQUAL: ('>=' | '=>');
EQUAL: '=';
LESS: ('<=' | '=<');
LESS_EQUAL: '<';
comparator: LARGER | LARGER_EQUAL | EQUAL | LESS | LESS_EQUAL;

input:
    line_input+
    | EOF
    ;

line_input:
    vardefinition
    | comparision
    ;

variable:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')') | WS* VARIABLE WS*) WS*
    ;

vardefinition:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')') | WS* VARIABLE WS*) WS* '=' WS* (array | expr | string) WS* EOL
    ;

comparision:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')') | WS* VARIABLE WS*)  WS* ':' WS* lhs_comp WS* comparator
     WS* rhs_comp WS* (':' WS* expr_comp WS*)? EOL
    ;

lhs_comp:
    expr
    ;

rhs_comp:
    expr
    ;

expr_comp:
    expr
    ;

expr
    : 
    '(' expr ')'                                            # Parens
    | variable                                              # VariableInExpr
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | (number | constant)                                   # Literal
    | (ADD | SUB) WS* expr                                  # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr WS* (MUL | DIV) WS* expr                         # BinaryOp
    | expr WS* (ADD | SUB) WS* expr                         # BinaryOp
    ;

array
    :
    '[' WS* input_array WS* (',' WS* input_array)*']'
    ;

input_array:
    array #ItemArray
    | expr #ItemArray
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

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;



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

STRING: '"' ~["]* '"'
        | '\'' ~[']* '\''
    ;