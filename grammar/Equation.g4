grammar Equation;

import definitions;

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

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
WS: [ \t\n\r]+ -> skip ; 

FUNCTIONS
    : '(' FUNCTIONS ')'
    | LN
    | LG
    | LOG_X
    | EXP
    | SUMPRODUCT
    ;

VALUE
    : '(' VALUE ')'
    | FUNCTIONS
    | VARIABLE
    | NUMBER
    | CONSTANTS
    ;

SUMPRODUCT
    : 'sumproduct(' ARRAY ',' ARRAY (',' ARRAY)*')' 
    ;
LN
    : 'Ln(' VALUE ')'
    ;
LG
    : 'Lg(' VALUE ')'
    ;
LOG_X
    : 'Log(' VALUE ',' VALUE ')'
    ;
EXP
    : 'Exp(' VALUE ')'
    | 'Exp(' UINT ')'
    ;