parser grammar detect_type_function;
options { tokenVocab=main_lexics; }

value_type: array | expr | string;

line_input:
    array
    | expr
    ;

node_access:
    WS* (Lb  WS*  Rb) | (Lb WS* UINT WS*  Rb) | (Lb  WS* UINT WS* (SEPAR WS* UINT)* WS*  Rb) WS*
    ;

variable:
    WS* ((VAR_TAG (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) Rb node_access?) | (VARIABLE node_access?))  WS*
    ;

expr
    : 
    Lb  expr  Rb                                            # Parens
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
    BEG_ARR WS* (expr | array) WS* (SEPAR WS* (expr | array))*END_ARR
    ;

number
    : (UINT | FLOAT)
    ;

constant:
    (PI | EXP)
    ;

function
    : WS* LN Lb  WS* expr WS*  Rb WS*
    | WS* LG Lb  WS* expr WS*  Rb WS*
    | WS* EXP Lb  WS* expr WS*  Rb WS*
    | WS* SQRT Lb  WS* expr WS*  Rb WS*
    | WS* COS Lb WS* expr WS* Rb WS*
    | WS* SIN Lb WS* expr WS* Rb WS*
    | WS* ACOS Lb WS* expr WS* Rb WS*
    | WS* ASIN Lb WS* expr WS* Rb WS*
    | WS* FACTORIAL Lb WS* expr WS* Rb WS*
    | WS* LOG_X Lb  WS* expr WS* SEPAR WS* expr WS*  Rb WS*
    ;

multiargfunction
    :
    WS* SUMPRODUCT Lb  expr SEPAR expr (SEPAR expr )* Rb
    | WS* SUM Lb  expr SEPAR expr (SEPAR expr )* Rb
    | WS* PRODUCT Lb  expr SEPAR expr (SEPAR expr )* Rb
    ;

rangefunction
    :
    WS* SUM_I Lb  WS* expr WS*  Rb WS*
    | WS* PRODUCT_I Lb  WS* expr WS*  Rb WS*
    ;

string
    :
    DOUBLE_QUOTE STRING DOUBLE_QUOTE
    ;