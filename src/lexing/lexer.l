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

typedef struct convert_char_result {
    int length;
    char value;
} convert_char_result;

bool insertSemicolon = false;

long binarytoint(char *string);
long octaltoint(char *string);
long dectoint(char * string);
long hextoint(char *string);
float convertfloat(char *string);
char *removeQuotes(char *string);
convert_char_result convertchar(char *string);
char convertCharLiteral(char *string);
str convertStringLiteral(char *string);
char *copyString(char *string); // basically strdup but with new instead of malloc
%}

bin_lit 0(b|B)((_)?[0-1]+)+
oct_lit 0(o|O)?((_)?[0-7]+)+
dec_lit 0|([1-9]((_)?[0-9]+)*)
hex_lit 0(x|X)((_)?[0-9a-fA-F]+)+

dec_float_lit [0-9]((_)?[0-9]+)*\.([0-9]((_)?[0-9]+)*)?

rune_lit_esc \\(a|b|f|n|r|t|v|\\|\'|\")
rune_lit_oct \\[0-7]{3}
rune_lit_hex \\(x)[0-9a-fA-F]{2}
rune_lit_uns \\u[0-9a-fA-F]{4}
rune_lit_unb \\U[0-9a-fA-F]{8}
rune_lit_all [^\a\b\f\n\r\t\v\\\'"]

rune_lit ({rune_lit_esc}|{rune_lit_oct}|{rune_lit_hex}|{rune_lit_all})

identifier [_a-zA-Z]([_a-zA-Z0-9])*

%%
"//".*                      {}
[ \t\r]                     {}
\n                          { 
                                if (insertSemicolon) {
                                    insertSemicolon = false;
                                    return ';'; 
                                }
                            }

bool                        { insertSemicolon = true; return BOOL; }
int                         { insertSemicolon = true; return INT; }
float32                     { insertSemicolon = true; return FLOAT32; }
rune                        { insertSemicolon = true; return RUNE; }
string                      { insertSemicolon = true; return STRING; }
struct                      { insertSemicolon = true; return STRUCT; }
func                        { insertSemicolon = true; return FUNC; }
map                         { insertSemicolon = true; return MAP; }
type                        { insertSemicolon = true; return TYPE; }
var                         { insertSemicolon = true; return VAR; }

true                        { insertSemicolon = true; yylval.boolean = true; return BOOL_LITERAL; }
false                       { insertSemicolon = true; yylval.boolean = false; return BOOL_LITERAL; }

:=                          { insertSemicolon = false; return SHORT_VAR_DECL; }

{bin_lit}                   { insertSemicolon = true; yylval.integer = binarytoint(yytext); return INT_LITERAL; }
{oct_lit}                   { insertSemicolon = true; yylval.integer = octaltoint(yytext); return INT_LITERAL; }
{dec_lit}                   { insertSemicolon = true; yylval.integer = dectoint(yytext); return INT_LITERAL; }
{hex_lit}                   { insertSemicolon = true; yylval.integer = hextoint(yytext); return INT_LITERAL; }

{dec_float_lit}             { insertSemicolon = true; yylval.floating = convertfloat(yytext); return FLOAT_LITERAL; }

\'{rune_lit}\'              { insertSemicolon = true; yylval.rune = convertCharLiteral(yytext); return RUNE_LITERAL; }
\"{rune_lit}*\"             { insertSemicolon = true; yylval.string = convertStringLiteral(yytext); return STRING_LITERAL; }

{identifier}                { insertSemicolon = true; yylval.identifier = copyString(yytext); return IDENTIFIER; }
 
.                           { 
                                insertSemicolon = *yytext == ')' || *yytext == '}' ; 
                                return *yytext; 
                            }
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

char *removeQuotes(char *string)
{
    // remove ' ' or " "
    auto copy = copyString(string+1);
    auto length = strlen(copy);
    copy[length-1] = '\0';
    return copy;
}

convert_char_result convertchar(char *string)
{
    convert_char_result result;

    if (*string == '\\') {
        string = string + 1; // skip the /

        // octal representation
        if (string[0] >= '0' && string[0] <= '7') {
            // copy the value to a buffer for strtol()
            char rep[4];
            rep[0] = string[0];
            rep[1] = string[1];
            rep[2] = string[2];
            rep[3] = '\0';

            // create result
            result.length = 4;  // length of used string is '\' + 3 numbers
            result.value = (char)strtol(rep, NULL, 8);

            return result;
        }

        // hex representation
        if (*string == 'x') {
            // copy the value to a buffer for strtol()
            char rep[3];
            rep[0] = string[1];
            rep[1] = string[2];
            rep[2] = '\0';

            // create result
            result.length = 4;  // length of used string is '\' + 'x' + 2 numbers
            result.value = (char)strtol(rep, NULL, 16);

            return result;
        }

        result.length = 2; // '\' + symbol
        switch (*string) {
            case 'a': result.value = '\a'; break;
            case 'b': result.value = '\b'; break;
            case 'f': result.value = '\f'; break;
            case 'n': result.value = '\n'; break;
            case 'r': result.value = '\r'; break;
            case 't': result.value = '\t'; break;
            case 'v': result.value = '\v'; break;
            case '\\': result.value = '\\'; break;
            case '\'': result.value = '\''; break;
            case '\"': result.value = '\"'; break;
        }

        return result;
    }

    result.length = 1;
    result.value = *string;

    return result;
}

char convertCharLiteral(char *string)
{
    auto quoteless = removeQuotes(string);
    auto result = convertchar(quoteless);
    delete quoteless;
    return result.value;
}

str convertStringLiteral(char *string)
{
    auto quoteless = removeQuotes(string);
    auto length = strlen(quoteless);
    auto offset = 0;

    auto converted = new char[length];

    int i = 0;

    while (offset < length) {
        auto result = convertchar(quoteless + offset);
        converted[i++] = result.value;
        offset += result.length;
    }

    converted[i] = '\0';

    delete quoteless;

    return {converted, i};
}

char *copyString(char *string)
{
    auto result = new char[strlen(string) + 1];
    strcpy(result, string);

    return result;
}