parser grammar head_interactor;
options { tokenVocab=main_lexics; }

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
    WS* (Lb WS* Rb) | (Lb WS* UINT WS* Rb) | (Lb WS* UINT WS* (';' WS* UINT)* WS* Rb) WS*
    ;

variable:
    WS* ((VAR_TAG Lb (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) Rb node_access?) | (VARIABLE node_access?))  WS*
    ;

vardefinition:
    WS* ((VAR_TAG Lb (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) Rb node_access?) | (VARIABLE node_access?)) WS* EQUAL WS* value_type? WS* EOL
    ;

comparision:
    WS* ((VAR_TAG Lb (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) Rb) | WS* VARIABLE WS*)  WS* ':' WS* lhs_comp WS* comparator
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
    Lb expr Rb                                              # Parens
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
    BEG_ARR WS* input_array WS* (';' WS* input_array)*END_ARR
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
    : WS* LN Lb WS* expr WS* Rb WS*
    | WS* LG Lb WS* expr WS* Rb WS*
    | WS* EXP Lb WS* expr WS* Rb WS*
    | WS* SQRT Lb WS* expr WS* Rb WS*
    | WS* COS Lb WS* expr WS* Rb WS*
    | WS* SIN Lb WS* expr WS* Rb WS*
    | WS* ACOS Lb WS* expr WS* Rb WS*
    | WS* ASIN Lb WS* expr WS* Rb WS*
    | WS* FACTORIAL Lb WS* expr WS* Rb WS*
    | WS* LOG_X Lb WS* expr WS* ';' WS* expr WS*  Rb WS*
    ;

multiargfunction
    :
    WS* SUMPRODUCT Lb expr ';' expr (';' expr )* Rb
    | WS* SUM Lb expr ';' expr (';' expr )* Rb
    | WS* PRODUCT Lb expr ';' expr (';' expr )* Rb
    ;

rangefunction
    :
    WS* SUM_I Lb WS* expr WS*  Rb WS*
    | WS* PRODUCT_I Lb WS* expr WS*  Rb WS*
    ;

string
    :
    DOUBLE_QUOTE STRING DOUBLE_QUOTE
    ;