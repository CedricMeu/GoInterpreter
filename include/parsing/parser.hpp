/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_INCLUDE_PARSING_PARSER_HPP_INCLUDED
# define YY_YY_INCLUDE_PARSING_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2060 of yacc.c  */
#line 13 "src/parsing/parser.y"

    #include <string>
    #include <map>
    #include <vector>
    #include "ast/ast.hpp"
    #include "utils/linked_list.hpp"

    typedef struct str {
        char *string;
        int length;
    } str;


/* Line 2060 of yacc.c  */
#line 60 "include/parsing/parser.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     INT = 259,
     FLOAT32 = 260,
     COMPLEX64 = 261,
     BYTE = 262,
     RUNE = 263,
     STRING = 264,
     STRUCT = 265,
     FUNC = 266,
     MAP = 267,
     TYPE = 268,
     VAR = 269,
     SHORT_VAR_DECL = 270,
     IDENTIFIER = 271,
     INT_LITERAL = 272,
     FLOAT_LITERAL = 273,
     BOOL_LITERAL = 274,
     RUNE_LITERAL = 275,
     STRING_LITERAL = 276
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2060 of yacc.c  */
#line 26 "src/parsing/parser.y"

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


/* Line 2060 of yacc.c  */
#line 120 "include/parsing/parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_INCLUDE_PARSING_PARSER_HPP_INCLUDED  */
