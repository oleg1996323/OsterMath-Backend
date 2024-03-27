grammar equation;

main:
    expr EOF
    ;

expr
    : '(' expr ')'  # Parens
    | (ADD | SUB) expr  # UnaryOp
    | expr (MUL | DIV) expr  # BinaryOp
    | expr (ADD | SUB) expr  # BinaryOp
    | NUMBER  # Literal
    | SUMPRODUCT #SumProduct
    ;

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;

NUMBER
    : UINT EXPONENT?
    | UINT? '.' UINT EXPONENT?
    ;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
WS: [ \t\n\r]+ -> skip ; 

SUMPRODUCT: 'sumproduct(' VARIABLE (';'VARIABLE)*')';

VARIABLE: [a-zA-Z]+[0-9]*;           