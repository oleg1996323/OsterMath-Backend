grammar head_interactor;
import main_lexics;

value_type: array | expr | string;
comparator: LARGER | LARGER_EQUAL | EQUAL | LESS | LESS_EQUAL;

input:
    line_input+
    | EOF
    ;

line_input:
    vardefinition
    | comparision
    ;

node_access:
    WS* ('(' WS* ')') | ('('WS* UINT WS* ')') | ('(' WS* UINT WS* (';' WS* UINT)* WS* ')') WS*
    ;

variable:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*)')'node_access?) | (VARIABLE node_access?))  WS*
    ;

vardefinition:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*)')'node_access?) | (VARIABLE node_access?)) WS* '=' WS* value_type? WS* EOL
    ;

comparision:
    WS* (('VAR(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')') | WS* VARIABLE WS*)  WS* ':' WS* lhs_comp WS* comparator
     WS* rhs_comp WS* (':' WS* expr_comp WS*)? EOL
    ;

lhs_comp:
    expr
    ;

rhs_comp:
    expr
    ;

expr_comp:
    expr
    ;

expr
    : 
    '(' expr ')'                                            # Parens
    | variable                                              # VariableInExpr
    | (function | multiargfunction | rangefunction)         # FunctionCall
    | (number | constant)                                   # Literal
    | (ADD | SUB) WS* expr                                  # UnaryOp
    | expr POW expr                                         # BinaryOp  
    | expr WS* (MUL | DIV) WS* expr                         # BinaryOp
    | expr WS* (ADD | SUB) WS* expr                         # BinaryOp
    ;

array
    :
    '[' WS* input_array WS* (';' WS* input_array)*']'
    ;

input_array:
    array #ItemArray
    | expr #ItemArray
    ;

number
    : (UINT | FLOAT)
    ;

constant:
    (PI | EXP)
    ;

function
    : WS* LN '(' WS* expr WS* ')' WS*
    | WS* LG '(' WS* expr WS* ')' WS*
    | WS* EXP '(' WS* expr WS* ')' WS*
    | WS* SQRT '(' WS* expr WS* ')' WS*
    | WS* COS '('WS* expr WS*')' WS*
    | WS* SIN '('WS* expr WS*')' WS*
    | WS* ACOS '('WS* expr WS*')' WS*
    | WS* ASIN '('WS* expr WS*')' WS*
    | WS* FACTORIAL '('WS* expr WS*')' WS*
    | WS* LOG_X '(' WS* expr WS* ';' WS* expr WS* ')' WS*
    ;

multiargfunction
    :
    WS* SUMPRODUCT '(' expr ';' expr (';' expr )*')'
    | WS* SUM '(' expr ';' expr (';' expr )*')'
    | WS* PRODUCT '(' expr ';' expr (';' expr )*')'
    ;

rangefunction
    :
    WS* SUM_I '(' WS* expr WS* ')' WS*
    | WS* PRODUCT_I '(' WS* expr WS* ')' WS*
    ;

string
    :
    '"' STRING '"'
    ;