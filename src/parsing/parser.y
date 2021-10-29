%locations
%defines "include/parsing/parser.hpp"

%code {
    #include <iostream>
    #include <string>
    #include "lexing/lexer.hpp"
    AST::Program *tree;

    void yyerror(char *s);
}

%code requires {
    #include <string>
    #include <map>
    #include <vector>
    #include "ast/ast.hpp"
    #include "utils/linked_list.hpp"

    typedef struct str {
        char *string;
        int length;
    } str;
}

%union {
    int integer;
    float floating;
    bool boolean;
    char rune;
    char *identifier;
    str string;

    AST::Block *block;
    AST::Type *type;
    AST::Expression *expression;
    LinkedList<AST::Expression *> *expressions;
    AST::Statement *statement;
    LinkedList<AST::Statement *> *statements;
    AST::Declaration *declaration;
    LinkedList<AST::Declaration *> *declarations;
    AST::TopLevelDeclaration *top_level_declaration;
    LinkedList<AST::TopLevelDeclaration *> *top_level_declarations;

    LinkedList<std::string> *id_list;
    LinkedList<std::pair<std::string, AST::Type *>> *fields;
}

%start start // entry point of parsing

%token BOOL
%token INT
%token FLOAT32
%token COMPLEX64
%token BYTE
%token RUNE
%token STRING
%token STRUCT
%token FUNC
%token MAP
%token TYPE
%token VAR
%token SHORT_VAR_DECL
%token IF
%token ELSE

%token<identifier> IDENTIFIER
%token<integer> INT_LITERAL
%token<floating> FLOAT_LITERAL
%token<boolean> BOOL_LITERAL
%token<rune> RUNE_LITERAL
%token<string> STRING_LITERAL

%type<type> type
%type<type> function_signature
%type<integer> array_length
%type<id_list> identifier_list
%type<fields> function_result
%type<fields> function_parameters
%type<fields> function_parameter_list
%type<fields> struct_field_decls

%type<block> block

%type<statements> statement
%type<statements> statement_list
%type<statement> if_statement

%type<top_level_declarations> top_level_declaration
%type<top_level_declarations> top_level_declaration_list
%type<top_level_declaration> function_declaration
%type<declarations> declaration
%type<declarations> type_decl
%type<declarations> type_spec_list
%type<declarations> var_decl
%type<declarations> var_spec_list
%type<declaration> type_spec
%type<declaration> var_spec

%type<expressions> expression_list
%type<expression> expression
%%

start: top_level_declaration_list           { tree = new AST::Program{$1->toStdVector()}; }
     ;

// Types
type: IDENTIFIER                            { $$ = new AST::CustomType{$1}; delete $1; }
    | '(' type ')'                          { $$ = $2; }
    | BOOL                                  { $$ = new AST::BoolType{}; }
    | INT                                   { $$ = new AST::IntType{}; }
    | FLOAT32                               { $$ = new AST::Float32Type{}; }
    | RUNE                                  { $$ = new AST::RuneType{}; }
    | STRING                                { $$ = new AST::StringType{}; }
    | '[' array_length ']' type             { $$ = new AST::ArrayType{$2, $4}; }
    | '[' ']' type                          { $$ = new AST::SliceType{$3}; }
    | STRUCT '{' struct_field_decls '}'     { $$ = new AST::StructType{$3->toStdVector()}; delete $3; }
    | '*' type                              { $$ = new AST::PointerType{$2}; }
    | FUNC function_signature               { $$ = $2; }
    | MAP '[' type ']' type                 { $$ = new AST::MapType{$3, $5}; }
    ;

array_length: INT_LITERAL                   { $$ = yylval.integer; }
            ;

function_signature: function_parameters function_result
                                            { 
                                                $$ = new AST::FunctionType{$1->toStdVector(), $2->toStdVector()}; 
                                                delete $1;
                                                delete $2;
                                            }
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

// Block
block: '{' '}'                              { $$ = new AST::Block{{}}; }
     | '{' statement_list '}'               { $$ = new AST::Block{$2->toStdVector()}; delete $2; }
     ;

// declarations
top_level_declaration: declaration          {
                                                auto declarations = $1->toStdVector(); 
                                                delete $1;
                                                auto list = new LinkedList<AST::TopLevelDeclaration *>;
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, declarations[i]);
                                                }
                                                $$ = list;
                                            }
                     | function_declaration {
                                                auto function = $1;
                                                auto list = new LinkedList<AST::TopLevelDeclaration *>; 
                                                list->insert(0, function);
                                                $$ = list;
                                            }
                     ;

top_level_declaration_list: top_level_declaration     
                                            { $$ = $1; }
                          | top_level_declaration ';' top_level_declaration_list
                                            {
                                                auto declarations = $1->toStdVector();
                                                delete $1;
                                                auto list = $3;
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, declarations[i]);
                                                }
                                                $$ = list;
                                            }
                          ;

function_declaration: FUNC IDENTIFIER function_signature block
                                            {
                                                $$ = new AST::FunctionDeclaration{$2, $3, $4};
                                            }
                    ;

declaration: type_decl                        { $$ = $1; }
           | var_decl                         { $$ = $1; }
           ;

type_decl: TYPE type_spec                   { 
                                                auto typeSpec = $2;
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, typeSpec);
                                                $$ = list;
                                            }
         | TYPE '(' type_spec_list ')'      { $$ = $3; }
         ;

type_spec: IDENTIFIER '=' type              { $$ = new AST::TypeAliasDeclaration{$1, $3}; delete $1; }
         | IDENTIFIER type                  { $$ = new AST::TypeDefinitionDeclaration{$1, $2}; delete $1; }
         ;

type_spec_list: type_spec ';'               { 
                                                auto typeSpec = $1;
                                                auto list = new LinkedList<AST::Declaration *>; 
                                                list->insert(0, typeSpec);
                                                $$ = list;
                                            }
              | type_spec ';' type_spec_list
                                            { 
                                                auto typeSpec = $1;
                                                auto list = $3; 
                                                list->insert(0, typeSpec);
                                                $$ = list;
                                            }
              ;

var_decl: VAR var_spec                      {
                                                auto varSpec = $2;
                                                auto list = new LinkedList<AST::Declaration*>;
                                                list->insert(0, varSpec);
                                                $$ = list;
                                            }
        | VAR '(' var_spec_list ')'         { $$ = $3; }
        ;

var_spec: identifier_list type              { $$ = new AST::VariableDeclaration{$1->toStdVector(), $2, {}}; }
        | identifier_list type '=' expression_list
                                            { $$ = new AST::VariableDeclaration{$1->toStdVector(), $2, $4->toStdVector()}; }
        | identifier_list '=' expression_list
                                            { $$ = new AST::VariableDeclaration{$1->toStdVector(), nullptr, $3->toStdVector()}; }
        ;

var_spec_list: var_spec ';'                 {
                                                auto varSpec = $1;
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, varSpec);
                                                $$ = list;
                                            }
             | var_spec ';' var_spec_list   { 
                                                auto varSpec = $1;
                                                auto list = $3; 
                                                list->insert(0, varSpec);
                                                $$ = list;
                                            }
             ;

// Statements
statement: expression                       {
                                                auto expression = $1;
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::ExpressionStatement{expression});
                                                $$ = list;
                                            }
         | expression_list '=' expression_list
                                            {
                                                auto lhs = $1->toStdVector();
                                                auto rhs = $3->toStdVector();
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::AssignmentStatement{lhs, rhs});
                                                $$ = list;
                                            }
         | if_statement                     {
                                                auto if_statement = $1;
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, if_statement);
                                                $$ = list;
                                            }
         | declaration                      { 
                                                auto declarations = $1->toStdVector(); 
                                                delete $1;
                                                auto list = new LinkedList<AST::Statement *>;
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, new AST::DeclarationStatement{declarations[i]});
                                                }
                                                $$ = list;
                                            }
         ;

statement_list: statement ';'               { $$ = $1; }
              | statement ';' statement_list
                                            {
                                                auto statements = $1->toStdVector();
                                                delete $1;
                                                auto list = $3;
                                                for (int i = 0; i < statements.size(); i++) {
                                                    list->insert(i, statements[i]);
                                                }
                                                $$ = list;
                                            }

              ;
if_statement: IF expression block           { $$ = new AST::IfStatement{$2, $3, new AST::Block{{}}}; }
            | IF expression block ELSE if_statement 
                                            { $$ = new AST::IfStatement{$2, $3, new AST::Block{{$5}}}; }
            | IF expression block ELSE block        
                                            { $$ = new AST::IfStatement{$2, $3, $5}; }
    ;

// Expressions
expression: BOOL_LITERAL                    { $$ = new AST::BoolExpression{$1}; }
          | INT_LITERAL                     { $$ = new AST::IntExpression{$1}; }
          | FLOAT_LITERAL                   { $$ = new AST::Float32Expression{$1}; }
          | RUNE_LITERAL                    { $$ = new AST::RuneExpression{$1}; }
          | STRING_LITERAL                  { $$ = new AST::StringExpression{$1.string, $1.length}; }
          | IDENTIFIER                      { $$ = new AST::IdentifierExpression{$1}; }
          ;

expression_list: expression                 {
                                                auto list = new LinkedList<AST::Expression *>{}; 
                                                list->insert(0, $1);
                                                $$ = list;
                                                
                                            }
               | expression ',' expression_list
                                            {
                                                auto list = $3;
                                                list->insert(0, $1);
                                                $$ = list;
                                            }
               ;

// Miscellaneous
identifier_list: IDENTIFIER                 {
                                                auto list = new LinkedList<std::string>{}; 
                                                list->insert(0, $1);
                                                $$ = list;
                                                delete $1;
                                            }
               | IDENTIFIER ',' identifier_list    
                                            {
                                                auto list = $3;
                                                list->insert(0, $1);
                                                $$ = list;
                                                delete $1;
                                            }
               ;

%%

void yyerror(char *s)
{
    std::cerr << s << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
    if (*yytext == '\n') {
        std::cerr  << "unexpected newline (implicit semicolon)." << std::endl;
    } else {
        std::cerr  << "unexpected \'" << yytext << "\'." << std::endl;
    }
}