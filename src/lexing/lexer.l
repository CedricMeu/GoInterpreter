%option noyywrap
%option header-file="include/lexing/lexer.hpp"

%{
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

long binarytoint(char *string);
long octaltoint(char *string);
long dectoint(char * string);
long hextoint(char *string);
%}

bin_lit 0(b|B)((_)?[0-1]+)+
oct_lit 0(o|O)?((_)?[0-7]+)+
dec_lit 0|([1-9]((_)?[0-9]+)*)
hex_lit 0(x|X)((_)?[0-9a-fA-F]+)+

identifier [_a-zA-Z]([_a-zA-Z0-9])*

%%
"//".*                      ;
[ \t\t\n]                   ;

bool                        { return BOOL; }
uint                        { return UINT; }
int                         { return INT; }
float32                     { return FLOAT32; }
complex64                   { return COMPLEX64; }
byte                        { return BYTE; }
rune                        { return RUNE; }
string                      { return STRING; }
struct                      { return STRUCT; }
func                        { return FUNC; }
map                         { return MAP; }

{bin_lit}                   { yylval.integer = binarytoint(yytext); return INT_LITERAL; }
{oct_lit}                   { yylval.integer = octaltoint(yytext); return INT_LITERAL; }
{dec_lit}                   { yylval.integer = dectoint(yytext); return INT_LITERAL; }
{hex_lit}                   { yylval.integer = hextoint(yytext); return INT_LITERAL; }

{identifier}                { yylval.id = strdup(yytext); return IDENTIFIER; }
 
.                           { return *yytext; }
%%

char *filterintrep(char *string)
{
    auto filtered = new char[strlen(string)+1];
    auto origin = string;
    auto dest = filtered;

    while(*origin) {
        if (*origin != '_') {
            *dest = *origin;
            ++dest;
        }
        ++origin;
    }

    *dest = '\0';

    return filtered;
}

long binarytoint(char *string)
{
    auto filtered = filterintrep(string)+2; // need to remove '0b or 0B'
    return strtol(filtered, NULL, 2);
}

long octaltoint(char *string)
{
    auto filtered = filterintrep(string) + 1;
    filtered = (*filtered == 'o' || *filtered == 'O')? filtered + 1 : filtered;
    return strtol(filtered, NULL, 8);
}

long dectoint(char * string)
{
    auto filtered = filterintrep(string); // already in correct representation
    return strtol(filtered, NULL, 10);
}

long hextoint(char *string) 
{
    auto filtered = filterintrep(string)+2; // need to remove '0x or 0X'
    return strtol(filtered, NULL, 16);
}