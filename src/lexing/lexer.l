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
float convertfloat(char *string);
char convertchar(char *string);
%}

bin_lit 0(b|B)((_)?[0-1]+)+
oct_lit 0(o|O)?((_)?[0-7]+)+
dec_lit 0|([1-9]((_)?[0-9]+)*)
hex_lit 0(x|X)((_)?[0-9a-fA-F]+)+

dec_float_lit [0-9]((_)?[0-9]+)*\.([0-9]((_)?[0-9]+)*)?

rune_lit_esc \'\\(a|b|f|n|r|t|v|\\|\'|\")\'
rune_lit_oct \'\\[0-7]{3}\'
rune_lit_hex \'\\(x)[0-9a-fA-F]{2}\'
rune_lit_uns \'\\u[0-9a-fA-F]{4}\'
rune_lit_unb \'\\U[0-9a-fA-F]{8}\'
rune_lit_all \'[^\a\b\f\n\r\t\v\\\'"]\'

identifier [_a-zA-Z]([_a-zA-Z0-9])*

%%
"//".*                      ;
[ \t\t\n]                   ;

bool                        { return BOOL; }
int                         { return INT; }
float32                     { return FLOAT32; }
rune                        { return RUNE; }
string                      { return STRING; }
struct                      { return STRUCT; }
func                        { return FUNC; }
map                         { return MAP; }

true                        { yylval.boolean = true; return BOOL_LITERAL; }
false                       { yylval.boolean = false; return BOOL_LITERAL; }

{bin_lit}                   { yylval.integer = binarytoint(yytext); return INT_LITERAL; }
{oct_lit}                   { yylval.integer = octaltoint(yytext); return INT_LITERAL; }
{dec_lit}                   { yylval.integer = dectoint(yytext); return INT_LITERAL; }
{hex_lit}                   { yylval.integer = hextoint(yytext); return INT_LITERAL; }

{dec_float_lit}             { yylval.floating = convertfloat(yytext); return FLOAT_LITERAL; }

{rune_lit_esc}              { yylval.rune = convertchar(yytext); return RUNE_LITERAL; }
{rune_lit_oct}              { yylval.rune = convertchar(yytext); return RUNE_LITERAL; }
{rune_lit_hex}              { yylval.rune = convertchar(yytext); return RUNE_LITERAL; }
{rune_lit_all}              { yylval.rune = convertchar(yytext); return RUNE_LITERAL; }

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

float convertfloat(char *string)
{
    auto filtered = filterintrep(string); // already in correct representation
    return strtof(filtered, NULL);
}

char convertchar(char *string)
{
    // remove ' '
    auto length = strlen(string);
    string[length-1] = '\0';
    string = string + 1;

    length = strlen(string);
    if (length == 1) {
        return *string;
    }

    string = string + 1; // skip the /

    // octal representation
    if (*string >= '0' && *string <= '7') {
        return (char)strtol(string, NULL, 8);
    }

    // hex representation
    if (*string == 'x') {
        string = string + 1; // skip the x
        return (char)strtol(string, NULL, 16);
    }

    switch (*string) {
        case 'a': return '\a';
        case 'b': return '\b';
        case 'f': return '\f';
        case 'n': return '\n';
        case 'r': return '\r';
        case 't': return '\t';
        case 'v': return '\v';
        case '\\': return '\\';
        case '\'': return '\'';
        case '\"': return '\"';
    }

    return 0;
}