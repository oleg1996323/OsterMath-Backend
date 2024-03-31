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

SUMPRODUCT: 'sumproduct';
LN: 'Ln';       
LG: 'Lg';       
LOG_X: 'Log';   
EXP: 'Exp';     
SQRT: 'Sqrt';
