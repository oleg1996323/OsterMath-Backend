lexer grammar fundamental;

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

WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

UINT: [0-9]+ (EXPONENT)?;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

QUOTE: '\'';
ASTERISK: '^' '*'+;

fragment INT: [-+]? UINT;
EXPONENT: [eE] INT;
FLOAT: INT '.' UINT (EXPONENT)?;
ID_NUMBER: [0-9]+;