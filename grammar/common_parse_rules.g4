parser grammar common_parse_rules;


node_access:
    WS* ('('  WS*  ')') | ('(' WS* UINT WS*  ')') | ('('  WS* UINT WS* (';' WS* UINT)* WS*  ')') WS*
    ;

variable:
    WS* ((VAR_TAG '(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')' node_access?) | (VARIABLE node_access?))  WS*
    ;

expr
    : 
    '('  expr  ')'                                            # Parens
    | variable                                              # VariableInExpr
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | (number | constant)                                   # Literal
    | (ADD | SUB) WS* expr                                  # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr WS* (MUL | DIV) WS* expr                         # BinaryOp
    | expr WS* (ADD | SUB) WS* expr                         # BinaryOp
    ;

number
    : (UINT | FLOAT)
    ;

constant:
    (PI | EXP)
    ;

function
    : WS* LN '('  WS* expr WS*  ')' WS*
    | WS* LG '('  WS* expr WS*  ')' WS*
    | WS* EXP '('  WS* expr WS*  ')' WS*
    | WS* SQRT '('  WS* expr WS*  ')' WS*
    | WS* COS '(' WS* expr WS* ')' WS*
    | WS* SIN '(' WS* expr WS* ')' WS*
    | WS* ACOS '(' WS* expr WS* ')' WS*
    | WS* ASIN '(' WS* expr WS* ')' WS*
    | WS* FACTORIAL '(' WS* expr WS* ')' WS*
    | WS* LOG_X '('  WS* expr WS* ';' WS* expr WS*  ')' WS*
    | WS* WEIBULL_DISTRIB '('  WS* expr WS* ';' WS* expr WS* ';' WS* expr WS* ';' WS* expr WS* ')' WS*
    | WS* GAUSS '('  WS* expr WS* ')' WS*
    | WS* STD_NORM_DISTRIB '('  WS* expr WS* ';' WS* expr WS* ')' WS*
    | WS* NORM_DISTRIB '('  WS* expr WS* ';' WS* expr WS* ';' WS* expr WS* ';' WS* expr WS* ')' WS*
    | WS* PEARSON '('  WS* expr WS* ';' WS* expr WS*  ')' WS*
    | WS* GAMMA '('  WS* expr WS* ')' WS*
    | WS* GAMMA_REV '('  WS* expr WS* ';' WS* expr WS* ';' WS* expr WS* ')' WS*
    ;

multiargfunction
    :
    WS* SUMPRODUCT '('  expr ';' expr (';' expr )* ')'
    | WS* SUM '('  expr ';' expr (';' expr )* ')'
    | WS* PRODUCT '('  expr ';' expr (';' expr )* ')'
    | WS* CONCAT '(' string_arg ';' string_arg (';' string_arg )* ')'
    | WS* SEARCH_STRING '(' string_arg (';' string_arg )* ')' WS*
    | WS* CONTAIN_TEXT '(' string_arg (';' string_arg )* ')' WS*
    | WS* ROOT_MEAN_SQUARE '(' expr (';' expr )* ')' WS* 
    | WS* ROOT_MEAN_SQUARE_ERROR '(' expr (';' expr )* ')' WS* 
    | WS* AVERAGE '(' expr (';' expr )* ')' WS* 
    | WS* MEDIAN '(' expr (';' expr )* ')' WS* 
    ;

rangefunction
    :
    WS* SUM_I '('  WS* expr WS*  ')' WS*
    | WS* PRODUCT_I '('  WS* expr WS*  ')' WS*
    ;

string
    :
    STRING
    ;

string_arg:
    STRING_ARG
    ;