%locations

%{
#include <iostream>
#include <string>
#include "lexing/lexer.hpp"
void yyerror(char *s);
%}

%union {
    int integer;
    double floating;
    char* id;
}
%start test // entry point of tree

%token<id> identifier

%%

test    : identifier ';'    { std::cout << "id: " << std::string{$1} << std::endl; free($1); }

%%

void yyerror(char *s)
{
    std::cerr << s << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
}