grammar Formula;

main
    : expr EOF
    ;

expr
    : '(' expr ')'  # Parens
    | (ADD | SUB) expr  # UnaryOp
    | expr (MUL | DIV) expr  # BinaryOp
    | expr (ADD | SUB) expr  # BinaryOp
    | expr (MUL_RANGE | SUM_RANGE)  # 
    | NUMBER  # Literal
    ;

// number literals cannot be signed, or else 1-2 would be lexed as [1] [-2]
fragment INT: [-+]? UINT ;
fragment UINT: [0-9]+ ;
fragment EXPONENT: [eE] INT;
NUMBER
    : UINT EXPONENT?
    | UINT? '.' UINT EXPONENT?
    ;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;

VARIABLE: \w+(\d+)?             #Any variable name (may have index)
RANGE: RANGE                    #Any range of variable
SUM_PRODUCT: sumprod(RANGE,...);
WS: [ \t\n\r]+ -> skip ;