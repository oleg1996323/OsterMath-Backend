grammar Equation;

main:
    expr EOF
    ;

expr
    : 
    '(' expr ')'                # Parens
    | (ADD | SUB) expr          # UnaryOp
    | expr (MUL | DIV) expr     # BinaryOp
    | expr (ADD | SUB) expr     # BinaryOp              
    | VALUE                     # ValueDef
    ;

functions
    : LN '(' VALUE ')'
    | LG '(' VALUE ')'
    | LOG_X '(' VALUE ',' VALUE ')'
    | EXP '(' VALUE ')'
    | SUMPRODUCT '(' ARRAY ',' ARRAY (',' ARRAY)*')'
    | VALUE
    ;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
WS: [ \t\n\r]+ -> skip ;

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;
fragment FLOAT: UINT([.]UINT)? | UINT([.]UINT EXPONENT UINT);
fragment STRING: [a-zA-Z0-9]+;
fragment VARIABLE: '__'[a-zA-Z]+([0-9]+)?'__';

NUMBER
    : UINT EXPONENT?
    | FLOAT
    ;

CONSTANTS:
    PI
    ;

ARRAY
    :
    VALUE(','VALUE)*']'
    ;

KEY
    :
    STRING
    | NUMBER
    | VARIABLE
    ;

MAP
    :
    '{'KEY':'VALUE'}'
    ;

PI: 'Pi' | 'PI' | 'pi' WS;

VALUE
    : functions
    | VARIABLE
    | NUMBER
    | CONSTANTS
    ;

SUMPRODUCT
    : 'sumproduct'
    | ARRAY
    ;
LN
    : 'Ln'
    | VALUE
    ;
LG
    : 'Lg'
    | VALUE
    ;
LOG_X
    : 'Log'
    | VALUE
    ;
EXP
    : 'Exp'
    | VALUE
    ;