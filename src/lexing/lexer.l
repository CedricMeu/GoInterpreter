%option noyywrap
%option header-file="../include/lexing/lexer.hpp"

%{
// My version of flex still uses the register keyword for some reason, this'll fix that
#define register

#include <iostream>
#include "parsing/parser.hpp"

#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }

%}

%%
"//".*                      ;
[ \t\t\n]                   ;

[_a-zA-Z]([_a-zA-Z0-9])*    { yylval.id = strdup(yytext); return identifier; }

.                           { return *yytext; }
%%