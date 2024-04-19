grammar bound_coefs;

import Equation;

file:
    eq EOL bound_coefs
    ;

eq:
    (VARIABLE WS? expr EOL)+
    ;

hdr:
    (VARIABLE WS?)+
    ;

values:
    (VARIABLE EOL ((expr WS?)+ (EOL | EOF))+)+
    ;

bound_coefs:
    hdr EOL values
    ;