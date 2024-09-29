parser grammar detect_type_function;
import common_parse_rules;
options {tokenVocab=main_lexics;}

line_input:
    WS* EQUAL WS* (array | expr) EOL?
    | string
    | EOL
    ;

array
    :
    '[' WS* (expr | array) WS* (';' WS* (expr | array))* ']'
    ;