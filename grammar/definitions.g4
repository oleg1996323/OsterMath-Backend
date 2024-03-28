grammar definitions;

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
    '['VALUE(','VALUE)*']'
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