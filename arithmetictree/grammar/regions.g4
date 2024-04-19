grammar regions;

import Equation;

file:
    data_bound EOL const_zone EOL virial_coefs
    ;

hdr:
    (VARIABLE WS*)+
    ;

data_bound:
    (VARIABLE WS* (STRING | NUMBER) EOL)+
    ;

const_zone:
    hdr EOL values
    ;

virial_coefs:
    hdr EOL values
    ;

values:
    (NUMBER WS*)+ EOL
    ;

bound_equation:
    functions
    ;

tempbound:
    ;