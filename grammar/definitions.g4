grammar definitions;

main:
    ;

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;
fragment FLOAT: UINT([.]UINT)? | UINT([.]UINT EXPONENT UINT);

NUMBER
    : UINT EXPONENT?
    | FLOAT
    ;

STRING: [a-zA-Z0-9]+;
VARIABLE: '__'[a-zA-Z]+([0-9]+)?'__';

CONSTANTS:
    PI
    ;

ARRAY
    :
    '['VALUE(','VALUE)']'
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

RANGE
    :
    VARIABLE
    | VARIABLE
    ;

PI: 'Pi' | 'PI' | 'pi' WS;