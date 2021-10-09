%locations
%defines "include/parsing/parser.hpp"

%code {
    #include <iostream>
    #include <string>
    #include "lexing/lexer.hpp"
    AST::Type *tree;

    void yyerror(char *s);
}

%code requires {
    #include <string>
    #include <map>
    #include <vector>
    #include "ast/ast.hpp"
    #include "utils/linked_list.hpp"
}

%union {
    int integer;
    double floating;
    char* id;
    AST::Type *type;
    LinkedList<std::string> *id_list;
    LinkedList<std::pair<std::string, AST::Type *>> *fields;
}

%start start // entry point of parsing

%token BOOL
%token UINT
%token INT
%token FLOAT32
%token COMPLEX64
%token BYTE
%token RUNE
%token STRING
%token STRUCT
%token FUNC
%token MAP

%token<id> IDENTIFIER
%token<integer> INT_LITERAL

%type<type> type
%type<integer> array_length
%type<id_list> identifier_list
%type<fields> function_result
%type<fields> function_parameters
%type<fields> function_parameter_list
%type<fields> struct_field_decls

%%

start: type                                 { tree = $1; }
     ;

type: IDENTIFIER                            { $$ = new AST::CustomType{$1}; }
    | '(' type ')'                          { $$ = $2; }
    | BOOL                                  { $$ = new AST::BoolType{}; }
    | UINT                                  { $$ = new AST::UIntType{}; }
    | INT                                   { $$ = new AST::IntType{}; }
    | FLOAT32                               { $$ = new AST::Float32Type{}; }
    | COMPLEX64                             { $$ = new AST::Complex64Type{}; }
    | BYTE                                  { $$ = new AST::ByteType{}; }
    | RUNE                                  { $$ = new AST::RuneType{}; }
    | STRING                                { $$ = new AST::StringType{}; }
    | '[' array_length ']' type             { $$ = new AST::ArrayType{$2, $4}; }
    | '[' ']' type                          { $$ = new AST::SliceType{$3}; }
    | STRUCT '{' struct_field_decls '}'     { $$ = new AST::StructType{$3->toStdVector()}; delete $3; }
    | '*' type                              { $$ = new AST::PointerType{$2}; }
    | FUNC function_parameters function_result
                                            { $$ = new AST::FunctionType{$2->toStdVector(), $3->toStdVector()}; delete $2; delete $3; }
    | MAP '[' type ']' type                 { $$ = new AST::MapType{$3, $5}; }
    ;

array_length: INT_LITERAL                   { $$ = yylval.integer; }
            ;

function_result:                            { $$ = new LinkedList<std::pair<std::string, AST::Type *>>; }
               | function_parameters        { $$ = $1; }
               | type                       { 
                                                auto type = $1;
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                $$ = list;
                                            }
               ;

function_parameters: '(' ')'                { $$ = new LinkedList<std::pair<std::string, AST::Type *>>; }
                   | '(' function_parameter_list ')'
                                            { $$ = $2; }
                   | '(' function_parameter_list ',' ')'
                                            { $$ = $2; }
                   ;

function_parameter_list: type               { 
                                                auto type = $1;
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                $$ = list;
                                            }
                       | identifier_list type
                                            {
                                                auto ids = $1->toStdVector();
                                                delete $1;
                                                auto type = $2;
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                $$ = list;
                                            }
                       | type ',' function_parameter_list
                                            { 
                                                auto type = $1;
                                                auto list = $3;
                                                list->insert(0, std::make_pair("", type));
                                                $$ = list;
                                            }
                       | identifier_list type ',' function_parameter_list
                                            {
                                                auto ids = $1->toStdVector();
                                                delete $1;
                                                auto type = $2;
                                                auto list = $4;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                $$ = list;
                                            }
                       ;

struct_field_decls: identifier_list type ';'
                                            {
                                                auto ids = $1->toStdVector();
                                                delete $1;
                                                auto type = $2;
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                $$ = list;
                                            }
                  | identifier_list type ';' struct_field_decls 
                                            {
                                                auto ids = $1->toStdVector();
                                                delete $1;
                                                auto type = $2;
                                                auto list = $4;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                $$ = list;
                                            }
                  ;

identifier_list: IDENTIFIER                 { 
                                                auto list = new LinkedList<std::string>{}; 
                                                list->insert(0, $1);
                                                $$ = list;
                                            }
               | IDENTIFIER ',' identifier_list    
                                            {
                                                auto list = $3;
                                                list->insert(0, $1);
                                                $$ = list;
                                            }
               ;

%%

void yyerror(char *s)
{
    std::cerr << s << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
}