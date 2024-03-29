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

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;
fragment FLOAT: UINT([.]UINT)? | UINT([.]UINT EXPONENT UINT);
fragment STRING: '"'[a-zA-Z0-9]+'"';
fragment VARIABLE: '__'[a-zA-Z]+([0-9]+)?'__';

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
WS: [ \t\n\r]+ -> skip ;

NUMBER
    : UINT EXPONENT?
    | FLOAT
    ;

CONSTANTS:
    PI
    ;

ARRAY
    :
    '[' VALUE(','VALUE)*']'
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
    ;
LN
    : 'Ln'
    ;
LG
    : 'Lg'
    ;
LOG_X
    : 'Log'
    ;
EXP
    : 'Exp'
    ;

functions
    :
    functions '('functions')'
    | LN '(' WS* VALUE WS* ')'
    | LG '(' WS* VALUE WS* ')'
    | LOG_X '(' WS* VALUE WS*',' WS* VALUE WS*')'
    | EXP '(' WS* VALUE WS* ')'
    | SUMPRODUCT '(' ARRAY ',' ARRAY (',' ARRAY)*')'
    ;

VALUE
    :
    | functions
    | VARIABLE
    | NUMBER
    | CONSTANTS
    ;