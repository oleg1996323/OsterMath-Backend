grammar ParseRules;

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;
POW: '^' ;

STRING: '"'[a-zA-Z0-9 .,:;!?]+'"';
VARIABLE: '__'[a-zA-Z*']+([0-9]*)?'__';
VARIABLE_RANGE: '__'[a-zA-Z*']+([0-9]*)?'_arr__';
WS: [ \t]+ -> skip;
EOL: '\r'? '\n';

fragment INT: [-+]? UINT;
fragment UINT: [0-9]+;
fragment EXPONENT: [eE] INT;
fragment FLOAT: UINT '.' UINT (EXPONENT)?;

NUMBER
    : (UINT | FLOAT) EXPONENT?
    ;

CONSTANTS:
    PI
    ;

SUMPRODUCT: 'sumproduct';
LN: 'Ln';       
LG: 'Lg';       
LOG_X: 'Log';   
EXP: 'Exp';     
SQRT: 'Sqrt';

PI: 'Pi' | 'PI' | 'pi' WS;

expr
    : 
    '(' expr ')'                # Parens
    | (ADD | SUB) expr          # UnaryOp
    | expr (MUL | DIV) expr     # BinaryOp
    | expr (ADD | SUB) expr     # BinaryOp
    | expr POW expr             # PowerOp              
    | functions                 # FunctionCall
    | array                     # ArrayDef
    | VARIABLE                  # Variable
    | NUMBER                    # Number
    | CONSTANTS                 # Constant
    ;


array
    :
    '['(VARIABLE | NUMBER | CONSTANTS)(','VARIABLE | NUMBER | CONSTANTS)+']'
    ;

functions
    : '(' functions ')'                             #pares
    | LN '(' WS? expr WS? ')'                       #Natlog
    | LG '(' WS? expr WS? ')'                       #Declog
    | LOG_X '(' WS? expr WS? ',' WS? expr WS? ')'   #Baselog
    | EXP '(' WS? expr WS? ')'                      #Exponent
    | SQRT '(' WS? expr WS? ')'                     #Squareroot
    | SUMPRODUCT '(' expr ',' expr (',' expr )*')'  #Sumproduct
    ;

bound_temperature:
    equations_bound EOL bound_coefs
    ;

equations_bound:
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

zone:
    data_bound_zone EOL const_volume EOL virial_coefs_volume
    ;

data_bound_zone:
    (VARIABLE WS* (STRING | NUMBER) EOL)+
    ;

const_volume:
    hdr EOL values
    ;

virial_coefs_volume:
    hdr EOL values;

values_volume:
    (NUMBER WS*)+ EOL;

bound_equation_volume:
    functions
    ;

