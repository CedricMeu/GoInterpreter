/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 68 "src/parsing/parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 114 "src/parsing/parser.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     INT = 259,
     FLOAT32 = 260,
     RUNE = 261,
     STRING = 262,
     STRUCT = 263,
     FUNC = 264,
     MAP = 265,
     TYPE = 266,
     VAR = 267,
     SHORT_VAR_DECL = 268,
     IF = 269,
     ELSE = 270,
     SWITCH = 271,
     CASE = 272,
     DEFAULT = 273,
     RETURN = 274,
     BREAK = 275,
     CONTINUE = 276,
     FOR = 277,
     INC = 278,
     DEC = 279,
     ELLIPSIS = 280,
     OR = 281,
     AND = 282,
     EQ = 283,
     NEQ = 284,
     LTE = 285,
     GTE = 286,
     SHIFT_LEFT = 287,
     SHIFT_RIGHT = 288,
     IDENTIFIER = 289,
     INT_LITERAL = 290,
     FLOAT_LITERAL = 291,
     BOOL_LITERAL = 292,
     RUNE_LITERAL = 293,
     STRING_LITERAL = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 26 "src/parsing/parser.y"

    int integer;
    float floating;
    bool boolean;
    char rune;
    char *identifier;
    str string;

    AST::Block *block;

    AST::Type *type;

    AST::Declaration *declaration;
    LinkedList<AST::Declaration *> *declarations;
    AST::TopLevelDeclaration *top_level_declaration;
    LinkedList<AST::TopLevelDeclaration *> *top_level_declarations;

    AST::SimpleStatement *simple_statement;
    AST::Statement *statement;
    LinkedList<AST::Statement *> *statements;
    AST::SwitchStatement::SwitchClause *switch_clause;
    LinkedList<AST::SwitchStatement::SwitchClause *> *switch_clauses;

    AST::Expression *expression;
    LinkedList<AST::Expression *> *expressions;
    LinkedList<std::pair<std::string, AST::Expression *>> *keyed_expressions;

    LinkedList<std::string> *id_list;
    LinkedList<std::pair<std::string, AST::Type *>> *fields;


/* Line 387 of yacc.c  */
#line 200 "src/parsing/parser.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 241 "src/parsing/parser.cpp"
/* Unqualified %code blocks.  */
/* Line 391 of yacc.c  */
#line 4 "src/parsing/parser.y"

    #include <iostream>
    #include <string>
    #include "lexing/lexer.hpp"
    AST::Program *tree;

    void yyerror(char *s);


/* Line 391 of yacc.c  */
#line 255 "src/parsing/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   957

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    48,    49,     2,
      50,    51,    46,    42,    56,    43,    61,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    57,
      40,    58,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    44,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    13,    15,    17,    19,
      22,    25,    27,    29,    34,    38,    43,    49,    51,    54,
      55,    57,    59,    62,    66,    71,    73,    76,    80,    85,
      89,    94,    98,   100,   102,   104,   108,   113,   115,   117,
     120,   125,   129,   132,   135,   139,   142,   147,   150,   155,
     159,   162,   166,   168,   170,   172,   174,   176,   178,   180,
     182,   183,   185,   189,   190,   194,   198,   204,   210,   216,
     221,   225,   226,   229,   232,   234,   242,   246,   249,   251,
     255,   259,   263,   267,   271,   275,   279,   283,   287,   291,
     295,   299,   303,   307,   311,   315,   319,   323,   325,   326,
     328,   331,   334,   337,   340,   343,   346,   348,   350,   354,
     356,   358,   362,   364,   366,   368,   370,   372,   374,   378,
     383,   385,   389,   393,   395,   397,   402,   406,   411,   418,
     427,   432,   434
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    74,    -1,    50,    64,    51,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,    46,
      64,    -1,     9,    67,    -1,    65,    -1,    34,    -1,    52,
      66,    53,    64,    -1,    52,    53,    64,    -1,     8,    54,
      71,    55,    -1,    10,    52,    64,    53,    64,    -1,    35,
      -1,    69,    68,    -1,    -1,    69,    -1,    64,    -1,    50,
      51,    -1,    50,    70,    51,    -1,    50,    70,    56,    51,
      -1,    64,    -1,   104,    64,    -1,    64,    56,    70,    -1,
     104,    64,    56,    70,    -1,   104,    64,    57,    -1,   104,
      64,    57,    71,    -1,    54,    85,    55,    -1,    76,    -1,
      75,    -1,    73,    -1,    73,    57,    74,    -1,     9,    34,
      67,    72,    -1,    77,    -1,    80,    -1,    11,    78,    -1,
      11,    50,    79,    51,    -1,    34,    58,    64,    -1,    34,
      64,    -1,    78,    57,    -1,    78,    57,    79,    -1,    12,
      81,    -1,    12,    50,    82,    51,    -1,   104,    64,    -1,
     104,    64,    58,    99,    -1,   104,    58,    99,    -1,    81,
      57,    -1,    81,    57,    82,    -1,    84,    -1,    86,    -1,
      87,    -1,    90,    -1,    20,    -1,    21,    -1,    91,    -1,
      76,    -1,    -1,    93,    -1,    99,    58,    99,    -1,    -1,
      83,    57,    85,    -1,    14,    93,    72,    -1,    14,    93,
      72,    15,    86,    -1,    14,    93,    72,    15,    72,    -1,
      16,    93,    54,    89,    55,    -1,    17,    99,    59,    85,
      -1,    18,    59,    85,    -1,    -1,    88,    89,    -1,    19,
      99,    -1,    92,    -1,    22,    84,    57,    93,    57,    84,
      72,    -1,    22,    93,    72,    -1,    22,    72,    -1,    95,
      -1,    93,    26,    93,    -1,    93,    27,    93,    -1,    93,
      28,    93,    -1,    93,    29,    93,    -1,    93,    30,    93,
      -1,    93,    31,    93,    -1,    93,    32,    93,    -1,    93,
      33,    93,    -1,    93,    40,    93,    -1,    93,    41,    93,
      -1,    93,    42,    93,    -1,    93,    43,    93,    -1,    93,
      44,    93,    -1,    93,    45,    93,    -1,    93,    49,    93,
      -1,    93,    46,    93,    -1,    93,    47,    93,    -1,    93,
      48,    93,    -1,    93,    -1,    -1,   103,    -1,    42,    95,
      -1,    43,    95,    -1,    60,    95,    -1,    45,    95,    -1,
      46,    95,    -1,    49,    95,    -1,    97,    -1,    34,    -1,
      50,    93,    51,    -1,    98,    -1,   100,    -1,     9,    67,
      72,    -1,    37,    -1,    35,    -1,    36,    -1,    38,    -1,
      39,    -1,    93,    -1,    93,    56,    99,    -1,    65,    54,
     101,    55,    -1,   102,    -1,   102,    56,   101,    -1,    34,
      59,    93,    -1,    93,    -1,    96,    -1,    64,    50,    93,
      51,    -1,   103,    61,    34,    -1,   103,    52,    93,    53,
      -1,   103,    52,    94,    59,    94,    53,    -1,   103,    52,
      94,    59,    93,    59,    93,    53,    -1,   103,    50,    99,
      51,    -1,    34,    -1,    34,    56,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   169,   170,   171,   172,   173,   177,   181,   190,
     191,   192,   201,   202,   204,   209,   215,   226,   233,   247,
     258,   273,   278,   287,   296,   298,   311,   318,   319,   323,
     329,   333,   334,   338,   344,   354,   360,   364,   365,   367,
     372,   378,   388,   394,   400,   406,   412,   417,   422,   428,
     440,   441,   442,   453,   456,   470,   471,   473,   478,   486,
     492,   500,   503,   513,   520,   524,   528,   536,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   570,   571,   575,
     576,   577,   578,   579,   580,   581,   585,   586,   587,   591,
     592,   593,   597,   598,   599,   600,   601,   605,   611,   620,
     629,   630,   643,   648,   656,   657,   658,   659,   660,   662,
     664,   670,   676
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "INT", "FLOAT32", "RUNE",
  "STRING", "STRUCT", "FUNC", "MAP", "TYPE", "VAR", "SHORT_VAR_DECL", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "RETURN", "BREAK", "CONTINUE",
  "FOR", "INC", "DEC", "ELLIPSIS", "OR", "AND", "EQ", "NEQ", "LTE", "GTE",
  "SHIFT_LEFT", "SHIFT_RIGHT", "IDENTIFIER", "INT_LITERAL",
  "FLOAT_LITERAL", "BOOL_LITERAL", "RUNE_LITERAL", "STRING_LITERAL", "'<'",
  "'>'", "'+'", "'-'", "'|'", "'^'", "'*'", "'/'", "'%'", "'&'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "','", "';'", "'='", "':'", "'!'",
  "'.'", "$accept", "start", "type", "literal_type", "array_length",
  "function_signature", "function_result", "function_parameters",
  "function_parameter_list", "struct_field_decls", "block",
  "top_level_declaration", "top_level_declaration_list",
  "function_declaration", "declaration", "type_decl", "type_spec",
  "type_spec_list", "var_decl", "var_spec", "var_spec_list", "statement",
  "simple_statement", "statement_list", "if_statement", "switch_statement",
  "switch_clause", "switch_clause_list", "return_statement",
  "for_statement", "for_condition_statement", "expression",
  "optional_expression", "unary_expression", "operand", "literal",
  "basic_literal", "expression_list", "composite_literal", "element_list",
  "keyed_element", "primary_expression", "identifier_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      60,    62,    43,    45,   124,    94,    42,    47,    37,    38,
      40,    41,    91,    93,   123,   125,    44,    59,    61,    58,
      33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    66,    67,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    86,    86,    86,    87,    88,
      88,    89,    89,    90,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     4,     3,     4,     5,     1,     2,     0,
       1,     1,     2,     3,     4,     1,     2,     3,     4,     3,
       4,     3,     1,     1,     1,     3,     4,     1,     1,     2,
       4,     3,     2,     2,     3,     2,     4,     2,     4,     3,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     3,     0,     3,     3,     5,     5,     5,     4,
       3,     0,     2,     2,     1,     7,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     0,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     3,     3,     1,     1,     4,     3,     4,     6,     8,
       4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    34,     2,    33,    32,    37,
      38,     0,     0,     0,    39,   131,     0,    45,     0,     1,
       0,     0,     0,    19,     4,     5,     6,     7,     8,     0,
       0,     0,    12,     0,     0,     0,     0,    42,    11,     0,
       0,     0,     0,     0,     0,    47,    35,   131,    22,    25,
       0,     0,    60,    36,     0,    21,    18,    20,     0,    10,
       0,     9,     0,    17,     0,     0,    41,    43,    40,   132,
      50,    46,     0,   107,   113,   114,   112,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,    11,   117,    78,
     124,   106,   109,    49,   110,    99,     0,     0,    23,     0,
      26,     0,     0,     0,    56,    57,    60,    59,     0,    52,
       0,    53,    54,    55,    58,    74,    61,     0,     0,     0,
       0,     0,     3,    14,     0,    44,    51,    10,   100,   101,
     103,     9,   104,   105,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,    48,    27,    24,     0,     0,     0,    73,    77,     0,
      61,    63,    31,     0,    15,     0,     0,    13,   111,   108,
       0,   107,   123,     0,   120,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    93,   118,     0,    97,     0,   126,    28,    65,
      71,     0,    76,    64,    62,    29,    16,   125,     0,   119,
       0,   130,   127,    98,     0,     0,     0,    71,     0,     0,
      30,   122,   121,    97,     0,    67,    66,     0,    63,    72,
      68,    60,     0,   128,    63,    70,     0,     0,    69,    75,
     129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    86,    87,    65,    22,    56,    23,    50,   119,
      53,     5,     6,     7,   107,     9,    39,    40,    10,    42,
      43,   108,   109,   110,   111,   112,   227,   228,   113,   114,
     115,    88,   206,    89,    90,    91,    92,   117,    94,   183,
     184,    95,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -168
static const yytype_int16 yypact[] =
{
      74,   -11,    -4,    16,    35,   -10,  -168,  -168,  -168,  -168,
    -168,     8,    11,    28,  -168,    18,    41,  -168,   472,  -168,
      74,   481,    22,   489,  -168,  -168,  -168,  -168,  -168,    53,
       8,    56,  -168,   504,   504,   -25,   504,  -168,  -168,    61,
      59,    41,    66,    68,   395,    67,  -168,   -20,  -168,    70,
     -19,   504,   279,  -168,   481,  -168,  -168,  -168,    41,  -168,
     504,  -168,    76,  -168,   504,    75,  -168,    28,  -168,  -168,
      41,  -168,     8,    62,  -168,  -168,  -168,  -168,  -168,   395,
     395,   395,   395,   395,   395,   395,    79,    77,   666,  -168,
    -168,  -168,  -168,  -168,  -168,   -28,   395,   539,  -168,    83,
      80,   395,   395,   395,  -168,  -168,   198,  -168,    82,  -168,
      85,  -168,  -168,  -168,  -168,  -168,   601,    84,     3,    86,
     504,    90,  -168,  -168,   504,  -168,  -168,    22,  -168,  -168,
    -168,    79,  -168,  -168,   -39,   811,  -168,   395,   414,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     103,  -168,  -168,  -168,   539,   697,   726,  -168,  -168,    87,
     568,   337,  -168,   395,  -168,    91,   504,  -168,  -168,  -168,
     837,    14,   863,    92,    93,   886,   908,   222,   222,   222,
     222,  -168,  -168,   222,   222,    -7,    -7,    -7,    -7,  -168,
    -168,  -168,  -168,  -168,   101,   755,    96,  -168,  -168,   142,
      26,   395,  -168,  -168,  -168,    41,  -168,  -168,   395,  -168,
     414,  -168,  -168,   395,    -6,   395,   105,    26,   107,   634,
    -168,   863,  -168,   534,   112,  -168,  -168,   113,   337,  -168,
    -168,   395,   395,  -168,   337,  -168,    22,   783,  -168,  -168,
    -168
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,    99,   133,  -168,   -23,  -168,   135,   -92,   -55,
    -100,  -168,   151,  -168,     9,  -168,   172,   108,  -168,   173,
     109,  -168,  -103,  -167,   -47,  -168,  -168,   -49,  -168,  -168,
    -168,   -50,   -38,    -1,  -168,  -168,  -168,   -43,  -168,   -40,
    -168,  -168,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
      18,    93,   116,   169,   213,   162,   168,    59,   101,     8,
      63,   137,   122,    18,    24,    25,    26,    27,    28,    29,
      30,    31,   158,    11,   159,   145,   146,   178,    64,     8,
      12,   -12,    98,   160,   135,    19,    41,    99,    69,   153,
     154,   155,   156,   225,   226,    32,    13,    20,    52,   127,
      15,   165,   166,   161,   122,   120,   170,    33,    21,    97,
     167,    34,    12,    35,   -12,   209,    16,    18,   -12,    36,
     212,   245,   208,   218,    41,    15,    52,   248,   128,   129,
     130,   132,   133,     1,   136,     2,     3,   180,   182,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    58,    60,   205,
      68,    37,   -12,   -12,   203,   204,   -12,    45,    67,    71,
      49,   116,    55,    70,   235,    96,    97,   122,   124,   137,
     214,   138,    61,    62,   163,    66,   164,   207,   246,   171,
     172,   174,   173,   176,   211,    38,   249,   219,   215,   220,
     100,    38,   221,   118,    38,   223,    38,   224,    57,   121,
     230,   229,   240,   123,   238,   243,    38,    38,   231,    38,
     182,    46,   244,   233,    14,   125,    17,   236,   239,   126,
     232,   131,   237,   134,    38,   234,     0,    38,   116,     0,
       0,   116,   247,    38,   116,     0,    49,    38,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    72,    31,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
      38,     0,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,     0,    81,    82,     0,     0,    83,    84,     0,
      35,     0,    52,    38,   145,   146,     0,    38,    85,     0,
       0,     0,     0,    49,   149,   150,   151,   152,   153,   154,
     155,   156,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    72,    31,
       2,     3,     0,   101,     0,   102,     0,    38,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,     0,    81,    82,     0,     0,    83,    84,
       0,    35,     0,     0,   -63,     0,     0,     0,     0,    85,
      24,    25,    26,    27,    28,    29,    72,    31,     2,     3,
       0,   101,     0,   102,     0,     0,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,     0,    81,    82,     0,     0,    83,    84,     0,    35,
       0,     0,     0,     0,   -60,     0,     0,    85,    24,    25,
      26,    27,    28,    29,    72,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    72,    31,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,     0,
      81,    82,     0,     0,    83,    84,     0,    35,   181,    74,
      75,    76,    77,    78,     0,    85,    79,    80,     0,    81,
      82,     0,     0,    83,    84,     0,    35,     0,     0,     0,
       0,     0,     0,     0,    85,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,    32,    24,    25,    26,
      27,    28,    29,    30,    31,    47,     0,     0,    33,     0,
       0,     0,    34,    32,    35,     0,     0,    33,     0,     0,
      44,    34,    48,    35,     0,    33,     0,     0,    32,    54,
       0,    35,    24,    25,    26,    27,    28,    29,    30,    31,
      33,     0,     0,     0,    34,     0,    35,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,    47,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,    33,     0,     0,     0,    34,
       0,    35,     0,   242,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,     0,
       0,     0,    52,     0,   157,     0,  -117,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,   157,     0,  -117,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
       0,   241,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,   157,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,     0,
       0,    52,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,     0,     0,     0,
     210,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,     0,     0,   222,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
       0,     0,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,     0,     0,   250,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   179,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   217,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
       0,     0,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-168)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,    44,    52,   106,   171,    97,   106,    30,    14,     0,
      35,    50,    51,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    50,    34,    52,    32,    33,   127,    53,    20,
      34,    51,    51,    61,    84,     0,    56,    56,    41,    46,
      47,    48,    49,    17,    18,    34,    50,    57,    54,    72,
      34,   101,   102,    96,    51,    58,   106,    46,    50,    56,
     103,    50,    34,    52,    50,   165,    50,    70,    54,    58,
     170,   238,   164,    59,    56,    34,    54,   244,    79,    80,
      81,    82,    83,     9,    85,    11,    12,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    54,    52,   159,
      51,    12,    50,    51,   157,   158,    54,    18,    57,    51,
      21,   171,    23,    57,   224,    58,    56,    51,    53,    50,
     173,    54,    33,    34,    51,    36,    56,    34,   241,    57,
      55,    55,    58,    53,    57,    12,   246,    55,    57,    56,
      51,    18,    51,    54,    21,    59,    23,    15,    23,    60,
     215,   211,    55,    64,    59,    53,    33,    34,   218,    36,
     220,    20,    59,   223,     2,    67,     3,   224,   227,    70,
     220,    82,   225,    84,    51,   223,    -1,    54,   238,    -1,
      -1,   241,   242,    60,   244,    -1,    97,    64,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    43,    -1,    45,    46,    -1,    -1,    49,    50,    -1,
      52,    -1,    54,   120,    32,    33,    -1,   124,    60,    -1,
      -1,    -1,    -1,   164,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    16,    -1,   164,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      -1,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    16,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      43,    -1,    45,    46,    -1,    -1,    49,    50,    -1,    52,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    60,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    -1,
      45,    46,    -1,    -1,    49,    50,    -1,    52,    34,    35,
      36,    37,    38,    39,    -1,    60,    42,    43,    -1,    45,
      46,    -1,    -1,    49,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    34,    -1,    -1,    46,    -1,
      -1,    -1,    50,    34,    52,    -1,    -1,    46,    -1,    -1,
      58,    50,    51,    52,    -1,    46,    -1,    -1,    34,    50,
      -1,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      46,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    34,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    46,    -1,    -1,    -1,    50,
      -1,    52,    -1,    59,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    56,    -1,    58,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    12,    63,    73,    74,    75,    76,    77,
      80,    34,    34,    50,    78,    34,    50,    81,   104,     0,
      57,    50,    67,    69,     3,     4,     5,     6,     7,     8,
       9,    10,    34,    46,    50,    52,    58,    64,    65,    78,
      79,    56,    81,    82,    58,    64,    74,    34,    51,    64,
      70,   104,    54,    72,    50,    64,    68,    69,    54,    67,
      52,    64,    64,    35,    53,    66,    64,    57,    51,   104,
      57,    51,     9,    34,    35,    36,    37,    38,    39,    42,
      43,    45,    46,    49,    50,    60,    64,    65,    93,    95,
      96,    97,    98,    99,   100,   103,    58,    56,    51,    56,
      64,    14,    16,    19,    20,    21,    22,    76,    83,    84,
      85,    86,    87,    90,    91,    92,    93,    99,    64,    71,
     104,    64,    51,    64,    53,    79,    82,    67,    95,    95,
      95,    64,    95,    95,    64,    93,    95,    50,    54,    26,
      27,    28,    29,    30,    31,    32,    33,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    56,    50,    52,
      61,    99,    70,    51,    56,    93,    93,    99,    72,    84,
      93,    57,    55,    58,    55,    64,    53,    64,    72,    51,
      93,    34,    93,   101,   102,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    99,    99,    93,    94,    34,    70,    72,
      54,    57,    72,    85,    99,    57,    64,    51,    59,    55,
      56,    51,    53,    59,    15,    17,    18,    88,    89,    93,
      71,    93,   101,    93,    94,    72,    86,    99,    59,    89,
      55,    57,    59,    53,    59,    85,    84,    93,    85,    72,
      53
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1802 of yacc.c  */
#line 152 "src/parsing/parser.y"
    { tree = new AST::Program{(yyvsp[(1) - (1)].top_level_declarations)->toStdVector()}; }
    break;

  case 3:
/* Line 1802 of yacc.c  */
#line 157 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(2) - (3)].type); }
    break;

  case 4:
/* Line 1802 of yacc.c  */
#line 158 "src/parsing/parser.y"
    { (yyval.type) = new AST::BoolType{}; }
    break;

  case 5:
/* Line 1802 of yacc.c  */
#line 159 "src/parsing/parser.y"
    { (yyval.type) = new AST::IntType{}; }
    break;

  case 6:
/* Line 1802 of yacc.c  */
#line 160 "src/parsing/parser.y"
    { (yyval.type) = new AST::Float32Type{}; }
    break;

  case 7:
/* Line 1802 of yacc.c  */
#line 161 "src/parsing/parser.y"
    { (yyval.type) = new AST::RuneType{}; }
    break;

  case 8:
/* Line 1802 of yacc.c  */
#line 162 "src/parsing/parser.y"
    { (yyval.type) = new AST::StringType{}; }
    break;

  case 9:
/* Line 1802 of yacc.c  */
#line 163 "src/parsing/parser.y"
    { (yyval.type) = new AST::PointerType{(yyvsp[(2) - (2)].type)}; }
    break;

  case 10:
/* Line 1802 of yacc.c  */
#line 164 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); }
    break;

  case 11:
/* Line 1802 of yacc.c  */
#line 165 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 12:
/* Line 1802 of yacc.c  */
#line 169 "src/parsing/parser.y"
    { (yyval.type) = new AST::CustomType{(yyvsp[(1) - (1)].identifier)}; delete (yyvsp[(1) - (1)].identifier); }
    break;

  case 13:
/* Line 1802 of yacc.c  */
#line 170 "src/parsing/parser.y"
    { (yyval.type) = new AST::ArrayType{(yyvsp[(2) - (4)].integer), (yyvsp[(4) - (4)].type)}; }
    break;

  case 14:
/* Line 1802 of yacc.c  */
#line 171 "src/parsing/parser.y"
    { (yyval.type) = new AST::SliceType{(yyvsp[(3) - (3)].type)}; }
    break;

  case 15:
/* Line 1802 of yacc.c  */
#line 172 "src/parsing/parser.y"
    { (yyval.type) = new AST::StructType{(yyvsp[(3) - (4)].fields)->toStdVector()}; delete (yyvsp[(3) - (4)].fields); }
    break;

  case 16:
/* Line 1802 of yacc.c  */
#line 173 "src/parsing/parser.y"
    { (yyval.type) = new AST::MapType{(yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].type)}; }
    break;

  case 17:
/* Line 1802 of yacc.c  */
#line 177 "src/parsing/parser.y"
    { (yyval.integer) = yylval.integer; }
    break;

  case 18:
/* Line 1802 of yacc.c  */
#line 182 "src/parsing/parser.y"
    { 
                                                (yyval.type) = new AST::FunctionType{(yyvsp[(1) - (2)].fields)->toStdVector(), (yyvsp[(2) - (2)].fields)->toStdVector()}; 
                                                delete (yyvsp[(1) - (2)].fields);
                                                delete (yyvsp[(2) - (2)].fields);
                                            }
    break;

  case 19:
/* Line 1802 of yacc.c  */
#line 190 "src/parsing/parser.y"
    { (yyval.fields) = new LinkedList<std::pair<std::string, AST::Type *>>; }
    break;

  case 20:
/* Line 1802 of yacc.c  */
#line 191 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(1) - (1)].fields); }
    break;

  case 21:
/* Line 1802 of yacc.c  */
#line 192 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (1)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 22:
/* Line 1802 of yacc.c  */
#line 201 "src/parsing/parser.y"
    { (yyval.fields) = new LinkedList<std::pair<std::string, AST::Type *>>; }
    break;

  case 23:
/* Line 1802 of yacc.c  */
#line 203 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(2) - (3)].fields); }
    break;

  case 24:
/* Line 1802 of yacc.c  */
#line 205 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(2) - (4)].fields); }
    break;

  case 25:
/* Line 1802 of yacc.c  */
#line 209 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (1)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 26:
/* Line 1802 of yacc.c  */
#line 216 "src/parsing/parser.y"
    {
                                                auto ids = (yyvsp[(1) - (2)].id_list)->toStdVector();
                                                delete (yyvsp[(1) - (2)].id_list);
                                                auto type = (yyvsp[(2) - (2)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                (yyval.fields) = list;
                                            }
    break;

  case 27:
/* Line 1802 of yacc.c  */
#line 227 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (3)].type);
                                                auto list = (yyvsp[(3) - (3)].fields);
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 28:
/* Line 1802 of yacc.c  */
#line 234 "src/parsing/parser.y"
    {
                                                auto ids = (yyvsp[(1) - (4)].id_list)->toStdVector();
                                                delete (yyvsp[(1) - (4)].id_list);
                                                auto type = (yyvsp[(2) - (4)].type);
                                                auto list = (yyvsp[(4) - (4)].fields);
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                (yyval.fields) = list;
                                            }
    break;

  case 29:
/* Line 1802 of yacc.c  */
#line 248 "src/parsing/parser.y"
    {
                                                auto ids = (yyvsp[(1) - (3)].id_list)->toStdVector();
                                                delete (yyvsp[(1) - (3)].id_list);
                                                auto type = (yyvsp[(2) - (3)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                (yyval.fields) = list;
                                            }
    break;

  case 30:
/* Line 1802 of yacc.c  */
#line 259 "src/parsing/parser.y"
    {
                                                auto ids = (yyvsp[(1) - (4)].id_list)->toStdVector();
                                                delete (yyvsp[(1) - (4)].id_list);
                                                auto type = (yyvsp[(2) - (4)].type);
                                                auto list = (yyvsp[(4) - (4)].fields);
                                                for (int i = 0; i < ids.size(); i++) {
                                                    list->insert(i, std::make_pair(ids[i], type));
                                                }
                                                (yyval.fields) = list;
                                            }
    break;

  case 31:
/* Line 1802 of yacc.c  */
#line 273 "src/parsing/parser.y"
    { (yyval.block) = new AST::Block{(yyvsp[(2) - (3)].statements)->toStdVector()}; delete (yyvsp[(2) - (3)].statements); }
    break;

  case 32:
/* Line 1802 of yacc.c  */
#line 278 "src/parsing/parser.y"
    {
                                                auto declarations = (yyvsp[(1) - (1)].declarations)->toStdVector(); 
                                                delete (yyvsp[(1) - (1)].declarations);
                                                auto list = new LinkedList<AST::TopLevelDeclaration *>;
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, declarations[i]);
                                                }
                                                (yyval.top_level_declarations) = list;
                                            }
    break;

  case 33:
/* Line 1802 of yacc.c  */
#line 287 "src/parsing/parser.y"
    {
                                                auto function = (yyvsp[(1) - (1)].top_level_declaration);
                                                auto list = new LinkedList<AST::TopLevelDeclaration *>; 
                                                list->insert(0, function);
                                                (yyval.top_level_declarations) = list;
                                            }
    break;

  case 34:
/* Line 1802 of yacc.c  */
#line 297 "src/parsing/parser.y"
    { (yyval.top_level_declarations) = (yyvsp[(1) - (1)].top_level_declarations); }
    break;

  case 35:
/* Line 1802 of yacc.c  */
#line 299 "src/parsing/parser.y"
    {
                                                auto declarations = (yyvsp[(1) - (3)].top_level_declarations)->toStdVector();
                                                delete (yyvsp[(1) - (3)].top_level_declarations);
                                                auto list = (yyvsp[(3) - (3)].top_level_declarations);
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, declarations[i]);
                                                }
                                                (yyval.top_level_declarations) = list;
                                            }
    break;

  case 36:
/* Line 1802 of yacc.c  */
#line 312 "src/parsing/parser.y"
    {
                                                (yyval.top_level_declaration) = new AST::FunctionDeclaration{(yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].type), (yyvsp[(4) - (4)].block)};
                                            }
    break;

  case 37:
/* Line 1802 of yacc.c  */
#line 318 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(1) - (1)].declarations); }
    break;

  case 38:
/* Line 1802 of yacc.c  */
#line 319 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(1) - (1)].declarations); }
    break;

  case 39:
/* Line 1802 of yacc.c  */
#line 323 "src/parsing/parser.y"
    { 
                                                auto typeSpec = (yyvsp[(2) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 40:
/* Line 1802 of yacc.c  */
#line 329 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(3) - (4)].declarations); }
    break;

  case 41:
/* Line 1802 of yacc.c  */
#line 333 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::TypeAliasDeclaration{(yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].type)}; delete (yyvsp[(1) - (3)].identifier); }
    break;

  case 42:
/* Line 1802 of yacc.c  */
#line 334 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::TypeDefinitionDeclaration{(yyvsp[(1) - (2)].identifier), (yyvsp[(2) - (2)].type)}; delete (yyvsp[(1) - (2)].identifier); }
    break;

  case 43:
/* Line 1802 of yacc.c  */
#line 338 "src/parsing/parser.y"
    {  
                                                auto typeSpec = (yyvsp[(1) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>; 
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 44:
/* Line 1802 of yacc.c  */
#line 345 "src/parsing/parser.y"
    { 
                                                auto typeSpec = (yyvsp[(1) - (3)].declaration);
                                                auto list = (yyvsp[(3) - (3)].declarations); 
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 45:
/* Line 1802 of yacc.c  */
#line 354 "src/parsing/parser.y"
    {
                                                auto varSpec = (yyvsp[(2) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration*>;
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 46:
/* Line 1802 of yacc.c  */
#line 360 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(3) - (4)].declarations); }
    break;

  case 47:
/* Line 1802 of yacc.c  */
#line 364 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (2)].id_list)->toStdVector(), (yyvsp[(2) - (2)].type), {}}; }
    break;

  case 48:
/* Line 1802 of yacc.c  */
#line 366 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (4)].id_list)->toStdVector(), (yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expressions)->toStdVector()}; }
    break;

  case 49:
/* Line 1802 of yacc.c  */
#line 368 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (3)].id_list)->toStdVector(), nullptr, (yyvsp[(3) - (3)].expressions)->toStdVector()}; }
    break;

  case 50:
/* Line 1802 of yacc.c  */
#line 372 "src/parsing/parser.y"
    {
                                                auto varSpec = (yyvsp[(1) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 51:
/* Line 1802 of yacc.c  */
#line 378 "src/parsing/parser.y"
    { 
                                                auto varSpec = (yyvsp[(1) - (3)].declaration);
                                                auto list = (yyvsp[(3) - (3)].declarations); 
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 52:
/* Line 1802 of yacc.c  */
#line 388 "src/parsing/parser.y"
    {
                                                auto stmt = (yyvsp[(1) - (1)].simple_statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, stmt);
                                                (yyval.statements) = list;
                                            }
    break;

  case 53:
/* Line 1802 of yacc.c  */
#line 394 "src/parsing/parser.y"
    {
                                                auto if_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, if_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 54:
/* Line 1802 of yacc.c  */
#line 400 "src/parsing/parser.y"
    {
                                                auto switch_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, switch_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 55:
/* Line 1802 of yacc.c  */
#line 406 "src/parsing/parser.y"
    {
                                                auto return_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, return_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 56:
/* Line 1802 of yacc.c  */
#line 412 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::BreakStatement{});
                                                (yyval.statements) = list;
                                            }
    break;

  case 57:
/* Line 1802 of yacc.c  */
#line 417 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::ContinueStatement{});
                                                (yyval.statements) = list;
                                            }
    break;

  case 58:
/* Line 1802 of yacc.c  */
#line 422 "src/parsing/parser.y"
    {
                                                auto for_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, for_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 59:
/* Line 1802 of yacc.c  */
#line 428 "src/parsing/parser.y"
    { 
                                                auto declarations = (yyvsp[(1) - (1)].declarations)->toStdVector(); 
                                                delete (yyvsp[(1) - (1)].declarations);
                                                auto list = new LinkedList<AST::Statement *>;
                                                for (int i = 0; i < declarations.size(); i++) {
                                                    list->insert(i, new AST::DeclarationStatement{declarations[i]});
                                                }
                                                (yyval.statements) = list;
                                            }
    break;

  case 60:
/* Line 1802 of yacc.c  */
#line 440 "src/parsing/parser.y"
    { (yyval.simple_statement) = new AST::EmptyStatement{}; }
    break;

  case 61:
/* Line 1802 of yacc.c  */
#line 441 "src/parsing/parser.y"
    { (yyval.simple_statement) = new AST::ExpressionStatement{(yyvsp[(1) - (1)].expression)}; }
    break;

  case 62:
/* Line 1802 of yacc.c  */
#line 443 "src/parsing/parser.y"
    {
                                                auto lhs = (yyvsp[(1) - (3)].expressions)->toStdVector();
                                                auto rhs = (yyvsp[(3) - (3)].expressions)->toStdVector();
                                                (yyval.simple_statement) = new AST::AssignmentStatement{lhs, rhs};
                                                delete (yyvsp[(1) - (3)].expressions);
                                                delete (yyvsp[(3) - (3)].expressions);
                                            }
    break;

  case 63:
/* Line 1802 of yacc.c  */
#line 453 "src/parsing/parser.y"
    { 
                                                (yyval.statements) = new LinkedList<AST::Statement *>;
                                            }
    break;

  case 64:
/* Line 1802 of yacc.c  */
#line 457 "src/parsing/parser.y"
    {
                                                auto statements = (yyvsp[(1) - (3)].statements)->toStdVector();
                                                delete (yyvsp[(1) - (3)].statements);
                                                auto list = (yyvsp[(3) - (3)].statements);
                                                for (int i = 0; i < statements.size(); i++) {
                                                    list->insert(i, statements[i]);
                                                }
                                                (yyval.statements) = list;
                                            }
    break;

  case 65:
/* Line 1802 of yacc.c  */
#line 470 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (3)].expression), (yyvsp[(3) - (3)].block), new AST::Block{{}}}; }
    break;

  case 66:
/* Line 1802 of yacc.c  */
#line 472 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(3) - (5)].block), new AST::Block{{(yyvsp[(5) - (5)].statement)}}}; }
    break;

  case 67:
/* Line 1802 of yacc.c  */
#line 474 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(3) - (5)].block), (yyvsp[(5) - (5)].block)}; }
    break;

  case 68:
/* Line 1802 of yacc.c  */
#line 479 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::SwitchStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].switch_clauses)->toStdVector()};
                                                delete (yyvsp[(4) - (5)].switch_clauses);
                                            }
    break;

  case 69:
/* Line 1802 of yacc.c  */
#line 487 "src/parsing/parser.y"
    {
                                                (yyval.switch_clause) = new AST::SwitchStatement::SwitchCaseClause{(yyvsp[(2) - (4)].expressions)->toStdVector(), (yyvsp[(4) - (4)].statements)->toStdVector()}; 
                                                delete (yyvsp[(2) - (4)].expressions);
                                                delete (yyvsp[(4) - (4)].statements);
                                            }
    break;

  case 70:
/* Line 1802 of yacc.c  */
#line 493 "src/parsing/parser.y"
    {
                                                (yyval.switch_clause) = new AST::SwitchStatement::SwitchDefaultClause{(yyvsp[(3) - (3)].statements)->toStdVector()}; 
                                                delete (yyvsp[(3) - (3)].statements);
                                            }
    break;

  case 71:
/* Line 1802 of yacc.c  */
#line 500 "src/parsing/parser.y"
    { 
                                                (yyval.switch_clauses) = new LinkedList<AST::SwitchStatement::SwitchClause *>;
                                            }
    break;

  case 72:
/* Line 1802 of yacc.c  */
#line 504 "src/parsing/parser.y"
    { 
                                                auto clause = (yyvsp[(1) - (2)].switch_clause);
                                                auto list = (yyvsp[(2) - (2)].switch_clauses);
                                                list->insert(0, clause);
                                                (yyval.switch_clauses) = list;
                                            }
    break;

  case 73:
/* Line 1802 of yacc.c  */
#line 513 "src/parsing/parser.y"
    { 
                                                (yyval.statement) = new AST::ReturnStatement{(yyvsp[(2) - (2)].expressions)->toStdVector()}; 
                                                delete (yyvsp[(2) - (2)].expressions);
                                            }
    break;

  case 74:
/* Line 1802 of yacc.c  */
#line 520 "src/parsing/parser.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 75:
/* Line 1802 of yacc.c  */
#line 525 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::ForConditionStatement{(yyvsp[(2) - (7)].simple_statement), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].simple_statement), (yyvsp[(7) - (7)].block)};
                                            }
    break;

  case 76:
/* Line 1802 of yacc.c  */
#line 529 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::ForConditionStatement{
                                                    new AST::EmptyStatement{}, 
                                                    (yyvsp[(2) - (3)].expression), 
                                                    new AST::EmptyStatement{}, 
                                                    (yyvsp[(3) - (3)].block)};
                                            }
    break;

  case 77:
/* Line 1802 of yacc.c  */
#line 537 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::ForConditionStatement{
                                                    new AST::EmptyStatement{}, 
                                                    new AST::BoolExpression{true}, 
                                                    new AST::EmptyStatement{}, 
                                                    (yyvsp[(2) - (2)].block)};
                                            }
    break;

  case 78:
/* Line 1802 of yacc.c  */
#line 548 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 79:
/* Line 1802 of yacc.c  */
#line 549 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::L_OR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 80:
/* Line 1802 of yacc.c  */
#line 550 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::L_AND, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 81:
/* Line 1802 of yacc.c  */
#line 551 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::EQ, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 82:
/* Line 1802 of yacc.c  */
#line 552 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::NEQ, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 83:
/* Line 1802 of yacc.c  */
#line 553 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::LTE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 84:
/* Line 1802 of yacc.c  */
#line 554 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::GTE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 85:
/* Line 1802 of yacc.c  */
#line 555 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::SHIFT_LEFT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 86:
/* Line 1802 of yacc.c  */
#line 556 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::SHIFT_RIGHT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 87:
/* Line 1802 of yacc.c  */
#line 557 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::LT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 88:
/* Line 1802 of yacc.c  */
#line 558 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::GT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 89:
/* Line 1802 of yacc.c  */
#line 559 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::ADD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 90:
/* Line 1802 of yacc.c  */
#line 560 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::SUB, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 91:
/* Line 1802 of yacc.c  */
#line 561 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::BW_OR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 92:
/* Line 1802 of yacc.c  */
#line 562 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::BW_XOR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 93:
/* Line 1802 of yacc.c  */
#line 563 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::BW_AND, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 94:
/* Line 1802 of yacc.c  */
#line 564 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::MULT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 95:
/* Line 1802 of yacc.c  */
#line 565 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::DIV, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 96:
/* Line 1802 of yacc.c  */
#line 566 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BinaryExpression{AST::BinaryExpression::Operation::MOD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)}; }
    break;

  case 97:
/* Line 1802 of yacc.c  */
#line 570 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 98:
/* Line 1802 of yacc.c  */
#line 571 "src/parsing/parser.y"
    { (yyval.expression) = nullptr; }
    break;

  case 99:
/* Line 1802 of yacc.c  */
#line 575 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 100:
/* Line 1802 of yacc.c  */
#line 576 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::PLUS, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 101:
/* Line 1802 of yacc.c  */
#line 577 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::NEGATE, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 102:
/* Line 1802 of yacc.c  */
#line 578 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::L_NOT, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 103:
/* Line 1802 of yacc.c  */
#line 579 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::BW_NOT, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 104:
/* Line 1802 of yacc.c  */
#line 580 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::DEREFERENCE, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 105:
/* Line 1802 of yacc.c  */
#line 581 "src/parsing/parser.y"
    { (yyval.expression) = new AST::UnaryExpression{AST::UnaryExpression::Operation::REFERENCE, (yyvsp[(2) - (2)].expression)}; }
    break;

  case 106:
/* Line 1802 of yacc.c  */
#line 585 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 107:
/* Line 1802 of yacc.c  */
#line 586 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IdentifierExpression{(yyvsp[(1) - (1)].identifier)}; }
    break;

  case 108:
/* Line 1802 of yacc.c  */
#line 587 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 109:
/* Line 1802 of yacc.c  */
#line 591 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 110:
/* Line 1802 of yacc.c  */
#line 592 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 111:
/* Line 1802 of yacc.c  */
#line 593 "src/parsing/parser.y"
    { (yyval.expression) = new AST::FunctionLiteralExpression{(yyvsp[(2) - (3)].type), (yyvsp[(3) - (3)].block)}; }
    break;

  case 112:
/* Line 1802 of yacc.c  */
#line 597 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BoolExpression{(yyvsp[(1) - (1)].boolean)}; }
    break;

  case 113:
/* Line 1802 of yacc.c  */
#line 598 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IntExpression{(yyvsp[(1) - (1)].integer)}; }
    break;

  case 114:
/* Line 1802 of yacc.c  */
#line 599 "src/parsing/parser.y"
    { (yyval.expression) = new AST::Float32Expression{(yyvsp[(1) - (1)].floating)}; }
    break;

  case 115:
/* Line 1802 of yacc.c  */
#line 600 "src/parsing/parser.y"
    { (yyval.expression) = new AST::RuneExpression{(yyvsp[(1) - (1)].rune)}; }
    break;

  case 116:
/* Line 1802 of yacc.c  */
#line 601 "src/parsing/parser.y"
    { (yyval.expression) = new AST::StringExpression{(yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).length}; }
    break;

  case 117:
/* Line 1802 of yacc.c  */
#line 605 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Expression *>{}; 
                                                list->insert(0, (yyvsp[(1) - (1)].expression));
                                                (yyval.expressions) = list;
                                                
                                            }
    break;

  case 118:
/* Line 1802 of yacc.c  */
#line 612 "src/parsing/parser.y"
    {
                                                auto list = (yyvsp[(3) - (3)].expressions);
                                                list->insert(0, (yyvsp[(1) - (3)].expression));
                                                (yyval.expressions) = list;
                                            }
    break;

  case 119:
/* Line 1802 of yacc.c  */
#line 620 "src/parsing/parser.y"
    {
                                                auto type = (yyvsp[(1) - (4)].type);
                                                auto elements = (yyvsp[(3) - (4)].keyed_expressions)->toStdVector();
                                                delete (yyvsp[(3) - (4)].keyed_expressions);
                                                (yyval.expression) = new AST::CompositLiteralExpression(type, elements);
                                            }
    break;

  case 120:
/* Line 1802 of yacc.c  */
#line 629 "src/parsing/parser.y"
    { (yyval.keyed_expressions) = (yyvsp[(1) - (1)].keyed_expressions); }
    break;

  case 121:
/* Line 1802 of yacc.c  */
#line 630 "src/parsing/parser.y"
    {

                                                auto elements = (yyvsp[(1) - (3)].keyed_expressions)->toStdVector();
                                                delete (yyvsp[(1) - (3)].keyed_expressions);
                                                auto list = (yyvsp[(3) - (3)].keyed_expressions);
                                                for (int i = 0; i < elements.size(); ++i) {
                                                    list->insert(i, elements[i]);
                                                }
                                                (yyval.keyed_expressions) = list;
                                            }
    break;

  case 122:
/* Line 1802 of yacc.c  */
#line 643 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::pair<std::string, AST::Expression*>>;
                                                list->insert(0, std::make_pair((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].expression)));
                                                (yyval.keyed_expressions) = list;
                                            }
    break;

  case 123:
/* Line 1802 of yacc.c  */
#line 648 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::pair<std::string, AST::Expression*>>;
                                                list->insert(0, std::make_pair("", (yyvsp[(1) - (1)].expression)));
                                                (yyval.keyed_expressions) = list;
                                            }
    break;

  case 124:
/* Line 1802 of yacc.c  */
#line 656 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 125:
/* Line 1802 of yacc.c  */
#line 657 "src/parsing/parser.y"
    { (yyval.expression) = new AST::ConversionExpression((yyvsp[(1) - (4)].type), (yyvsp[(3) - (4)].expression)); }
    break;

  case 126:
/* Line 1802 of yacc.c  */
#line 658 "src/parsing/parser.y"
    { (yyval.expression) = new AST::SelectExpression{(yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier)}; }
    break;

  case 127:
/* Line 1802 of yacc.c  */
#line 659 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IndexExpression{(yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression)}; }
    break;

  case 128:
/* Line 1802 of yacc.c  */
#line 661 "src/parsing/parser.y"
    { (yyval.expression) = new AST::SimpleSliceExpression{(yyvsp[(1) - (6)].expression), (yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].expression)}; }
    break;

  case 129:
/* Line 1802 of yacc.c  */
#line 663 "src/parsing/parser.y"
    { (yyval.expression) = new AST::FullSliceExpression{(yyvsp[(1) - (8)].expression), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression)}; }
    break;

  case 130:
/* Line 1802 of yacc.c  */
#line 665 "src/parsing/parser.y"
    { (yyval.expression) = new AST::CallExpression{(yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expressions)->toStdVector()}; }
    break;

  case 131:
/* Line 1802 of yacc.c  */
#line 670 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::string>{}; 
                                                list->insert(0, (yyvsp[(1) - (1)].identifier));
                                                (yyval.id_list) = list;
                                                delete (yyvsp[(1) - (1)].identifier);
                                            }
    break;

  case 132:
/* Line 1802 of yacc.c  */
#line 677 "src/parsing/parser.y"
    {
                                                auto list = (yyvsp[(3) - (3)].id_list);
                                                list->insert(0, (yyvsp[(1) - (3)].identifier));
                                                (yyval.id_list) = list;
                                                delete (yyvsp[(1) - (3)].identifier);
                                            }
    break;


/* Line 1802 of yacc.c  */
#line 2961 "src/parsing/parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 685 "src/parsing/parser.y"


void yyerror(char *s)
{
    std::cerr << s << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
    if (*yytext == '\n') {
        std::cerr  << "unexpected newline (implicit semicolon)." << std::endl;
    } else {
        std::cerr  << "unexpected \'" << yytext << "\'." << std::endl;
    }
}