parser grammar head_interactor;
import common_parse_rules;
options {tokenVocab=main_lexics;}


value_type: array | expr | string;

input:
    line_input+
    | EOF
    ;

line_input:
    vardefinition
    | comparision
    ;

vardefinition:
    WS* ((VAR_TAG '(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')' node_access?) | (VARIABLE node_access?)) WS* '=' WS* value_type? WS* EOL
    ;

comparator: LARGER | LARGER_EQUAL | EQUAL | LESS | LESS_EQUAL;

comparision:
    WS* ((VAR_TAG '(' (WS* DATABASE VARIABLE WS* | WS* VARIABLE WS*) ')') | WS* VARIABLE WS*)  WS* ':' WS* lhs_comp WS* comparator
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

array
    :
    '[' WS* input_array WS* (';' WS* input_array)* ']'
    ;

input_array:
    array #ItemArray
    | expr #ItemArray
    ;