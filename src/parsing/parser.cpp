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
     IDENTIFIER = 281,
     INT_LITERAL = 282,
     FLOAT_LITERAL = 283,
     BOOL_LITERAL = 284,
     RUNE_LITERAL = 285,
     STRING_LITERAL = 286
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
#line 192 "src/parsing/parser.cpp"
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
#line 233 "src/parsing/parser.cpp"
/* Unqualified %code blocks.  */
/* Line 391 of yacc.c  */
#line 4 "src/parsing/parser.y"

    #include <iostream>
    #include <string>
    #include "lexing/lexer.hpp"
    AST::Program *tree;

    void yyerror(char *s);


/* Line 391 of yacc.c  */
#line 247 "src/parsing/parser.cpp"

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
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    34,     2,    39,     2,    43,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    40,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
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
     253,   254,   256,   258,   262,   264,   266,   270,   272,   274,
     276,   278,   280,   282,   286,   291,   293,   297,   301,   303,
     305,   310,   314,   319,   326,   335,   340,   342
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    56,    -1,    32,    46,    33,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,    34,
      46,    -1,     9,    49,    -1,    47,    -1,    26,    -1,    35,
      48,    36,    46,    -1,    35,    36,    46,    -1,     8,    37,
      53,    38,    -1,    10,    35,    46,    36,    46,    -1,    27,
      -1,    51,    50,    -1,    -1,    51,    -1,    46,    -1,    32,
      33,    -1,    32,    52,    33,    -1,    32,    52,    39,    33,
      -1,    46,    -1,    85,    46,    -1,    46,    39,    52,    -1,
      85,    46,    39,    52,    -1,    85,    46,    40,    -1,    85,
      46,    40,    53,    -1,    37,    67,    38,    -1,    58,    -1,
      57,    -1,    55,    -1,    55,    40,    56,    -1,     9,    26,
      49,    54,    -1,    59,    -1,    62,    -1,    11,    60,    -1,
      11,    32,    61,    33,    -1,    26,    41,    46,    -1,    26,
      46,    -1,    60,    40,    -1,    60,    40,    61,    -1,    12,
      63,    -1,    12,    32,    64,    33,    -1,    85,    46,    -1,
      85,    46,    41,    80,    -1,    85,    41,    80,    -1,    63,
      40,    -1,    63,    40,    64,    -1,    66,    -1,    68,    -1,
      69,    -1,    72,    -1,    20,    -1,    21,    -1,    73,    -1,
      58,    -1,    -1,    75,    -1,    80,    41,    80,    -1,    -1,
      65,    40,    67,    -1,    14,    75,    54,    -1,    14,    75,
      54,    15,    68,    -1,    14,    75,    54,    15,    54,    -1,
      16,    75,    37,    71,    38,    -1,    17,    80,    42,    67,
      -1,    18,    42,    67,    -1,    -1,    70,    71,    -1,    19,
      80,    -1,    74,    -1,    22,    66,    40,    75,    40,    66,
      54,    -1,    22,    75,    54,    -1,    22,    54,    -1,    84,
      -1,    75,    -1,    -1,    78,    -1,    26,    -1,    32,    75,
      33,    -1,    79,    -1,    81,    -1,     9,    49,    54,    -1,
      29,    -1,    27,    -1,    28,    -1,    30,    -1,    31,    -1,
      75,    -1,    75,    39,    80,    -1,    47,    37,    82,    38,
      -1,    83,    -1,    83,    39,    82,    -1,    26,    42,    75,
      -1,    75,    -1,    77,    -1,    46,    32,    75,    33,    -1,
      84,    43,    26,    -1,    84,    35,    75,    36,    -1,    84,
      35,    76,    42,    76,    36,    -1,    84,    35,    76,    42,
      75,    42,    75,    36,    -1,    84,    32,    80,    33,    -1,
      26,    -1,    26,    39,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   154,   155,   156,   157,   158,   162,   166,   175,
     176,   177,   186,   187,   189,   194,   200,   211,   218,   232,
     243,   258,   263,   272,   281,   283,   296,   303,   304,   308,
     314,   318,   319,   323,   329,   339,   345,   349,   350,   352,
     357,   363,   373,   379,   385,   391,   397,   402,   407,   413,
     425,   426,   427,   438,   441,   455,   456,   458,   463,   471,
     477,   485,   488,   498,   505,   509,   513,   521,   533,   537,
     538,   542,   543,   544,   548,   549,   550,   554,   555,   556,
     557,   558,   562,   568,   577,   586,   587,   600,   605,   613,
     614,   615,   616,   617,   619,   621,   627,   633
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
  "FOR", "INC", "DEC", "ELLIPSIS", "IDENTIFIER", "INT_LITERAL",
  "FLOAT_LITERAL", "BOOL_LITERAL", "RUNE_LITERAL", "STRING_LITERAL", "'('",
  "')'", "'*'", "'['", "']'", "'{'", "'}'", "','", "';'", "'='", "':'",
  "'.'", "$accept", "start", "type", "literal_type", "array_length",
  "function_signature", "function_result", "function_parameters",
  "function_parameter_list", "struct_field_decls", "block",
  "top_level_declaration", "top_level_declaration_list",
  "function_declaration", "declaration", "type_decl", "type_spec",
  "type_spec_list", "var_decl", "var_spec", "var_spec_list", "statement",
  "simple_statement", "statement_list", "if_statement", "switch_statement",
  "switch_clause", "switch_clause_list", "return_statement",
  "for_statement", "for_condition_statement", "expression",
  "optional_expression", "operand", "literal", "basic_literal",
  "expression_list", "composite_literal", "element_list", "keyed_element",
  "primary_expression", "identifier_list", YY_NULL
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
     285,   286,    40,    41,    42,    91,    93,   123,   125,    44,
      59,    61,    58,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    47,    48,    49,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    71,    71,    72,    73,    74,    74,    74,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    85,    85
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
       3,     0,     2,     2,     1,     7,     3,     2,     1,     1,
       0,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     3,     3,     1,     1,
       4,     3,     4,     6,     8,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    34,     2,    33,    32,    37,
      38,     0,     0,     0,    39,   106,     0,    45,     0,     1,
       0,     0,     0,    19,     4,     5,     6,     7,     8,     0,
       0,     0,    12,     0,     0,     0,     0,    42,    11,     0,
       0,     0,     0,     0,     0,    47,    35,   106,    22,    25,
       0,     0,    60,    36,     0,    21,    18,    20,     0,    10,
       0,     0,     9,    17,     0,     0,    41,    43,    40,   107,
      50,    46,     0,    82,    88,    89,    87,    90,    91,     0,
       0,    11,    92,    99,    81,    84,    49,    85,    78,     0,
       0,    23,     0,    26,     0,     0,     0,    56,    57,    60,
      59,     0,    52,     0,    53,    54,    55,    58,    74,    61,
       0,     0,     0,     0,     0,     3,    14,     0,    44,    51,
      10,     0,     0,     0,     0,     0,     0,    80,     0,    48,
      27,    24,     0,     0,     0,    73,    77,     0,    61,    63,
      31,     0,    15,     0,     0,    13,    86,    83,     0,    82,
      98,     0,    95,    93,     0,    79,     0,   101,    28,    65,
      71,     0,    76,    64,    62,    29,    16,   100,     0,    94,
       0,   105,   102,    80,     0,     0,     0,    71,     0,     0,
      30,    97,    96,    79,     0,    67,    66,     0,    63,    72,
      68,    60,     0,   103,    63,    70,     0,     0,    69,    75,
     104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    80,    81,    65,    22,    56,    23,    50,   112,
      53,     5,     6,     7,   100,     9,    39,    40,    10,    42,
      43,   101,   102,   103,   104,   105,   177,   178,   106,   107,
     108,    82,   156,    83,    84,    85,   110,    87,   151,   152,
      88,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
      68,    14,    -7,     1,    10,   -22,  -135,  -135,  -135,  -135,
    -135,    20,   165,    33,  -135,    25,    44,  -135,   211,  -135,
      68,   379,    13,   412,  -135,  -135,  -135,  -135,  -135,    37,
      20,    48,  -135,   422,   422,   -19,   422,  -135,  -135,    45,
      51,    44,    53,    58,   336,    55,  -135,     2,  -135,    59,
       6,   422,   288,  -135,   379,  -135,  -135,  -135,    44,  -135,
     422,    64,  -135,  -135,   422,    65,  -135,    33,  -135,  -135,
      44,  -135,    20,    29,  -135,  -135,  -135,  -135,  -135,   336,
      72,    70,    67,  -135,  -135,  -135,  -135,  -135,   -23,   336,
     455,  -135,    75,    74,   336,   336,   336,  -135,  -135,   324,
    -135,    76,  -135,    71,  -135,  -135,  -135,  -135,  -135,    24,
      77,    18,    83,   422,    79,  -135,  -135,   422,  -135,  -135,
      13,   -18,    91,   336,   369,   336,   336,   336,   100,  -135,
    -135,  -135,   455,    13,    93,  -135,  -135,    88,    -5,   250,
    -135,   336,  -135,    92,   422,  -135,  -135,  -135,    98,   -16,
    -135,    96,    97,  -135,   102,   103,   104,  -135,  -135,   123,
       5,   336,  -135,  -135,  -135,    44,  -135,  -135,   336,  -135,
     369,  -135,  -135,   336,    -8,   336,   105,     5,   106,   109,
    -135,  -135,  -135,   108,   115,  -135,  -135,   111,   250,  -135,
    -135,   336,   336,  -135,   250,  -135,    13,   118,  -135,  -135,
    -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,    35,    69,  -135,   -26,  -135,   119,   -83,   -20,
     -96,  -135,   135,  -135,    11,  -135,   154,    90,  -135,   155,
      94,  -135,   -97,  -134,   -11,  -135,  -135,   -17,  -135,  -135,
    -135,   -51,     3,  -135,  -135,  -135,   -14,  -135,    -4,  -135,
    -135,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      18,   109,   137,   136,    59,   163,    94,   130,    63,   126,
      19,     8,   127,    18,   123,   115,   -12,    64,    20,    12,
     128,   -12,   175,   176,   146,    13,   168,    15,   122,    52,
      86,     8,    52,    16,   125,   -12,   -92,   159,    69,    91,
      11,    41,   162,   133,   134,    92,   120,    37,   138,   158,
      52,   115,    21,    45,   195,   113,    49,    90,    55,    12,
     198,   -12,   -12,   125,    41,   -92,   -12,    18,    61,    62,
      15,    66,   148,   150,    58,   129,   155,     1,   185,     2,
       3,    38,   135,    60,    68,    67,    93,    38,   109,   111,
      38,    71,    38,    70,   196,   114,    89,   115,    90,   116,
     199,   117,    38,    38,   123,    38,   125,   124,   131,   140,
     179,   153,   154,   132,   121,   144,   139,   181,   141,   150,
      38,   142,   183,    38,   147,    49,   157,   164,   161,    38,
     160,   167,   165,    38,   169,   171,   170,   109,   174,   172,
     109,   197,    57,   109,   190,   180,   173,   188,   143,   191,
     192,   193,   145,   194,   200,    46,    14,   118,    17,    38,
     189,   187,   113,   186,   119,     0,   182,    49,    24,    25,
      26,    27,    28,    29,    30,    31,   184,     0,     0,   166,
       0,     0,    38,     0,     0,     0,    38,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,    33,     0,    34,
      35,    38,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,    38,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,    33,     0,    34,    35,     0,     0,     0,
       0,     0,    44,    24,    25,    26,    27,    28,    29,    72,
      31,     2,     3,     0,    94,     0,    95,     0,     0,    96,
      97,    98,    99,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,     0,    34,    35,     0,     0,     0,     0,
     -60,    24,    25,    26,    27,    28,    29,    72,    31,     2,
       3,     0,    94,     0,    95,     0,     0,    96,    97,    98,
      99,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,     0,    34,    35,     0,     0,   -63,    24,    25,    26,
      27,    28,    29,    72,    31,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    72,    31,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,     0,    34,    35,
       0,    52,    73,    74,    75,    76,    77,    78,    79,     0,
      34,    35,    24,    25,    26,    27,    28,    29,    72,    31,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,   149,    74,    75,    76,    77,
      78,    79,     0,    34,    35,    47,     0,     0,     0,     0,
       0,    33,    48,    34,    35,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,     0,    54,     0,    34,    35,    32,     0,
       0,     0,     0,     0,    33,     0,    34,    35,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    33,     0,    34,
      35
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,    52,    99,    99,    30,   139,    14,    90,    27,    32,
       0,     0,    35,    16,    32,    33,    32,    36,    40,    26,
      43,    37,    17,    18,   120,    32,    42,    26,    79,    37,
      44,    20,    37,    32,    39,    33,    41,   133,    41,    33,
      26,    39,   138,    94,    95,    39,    72,    12,    99,   132,
      37,    33,    32,    18,   188,    58,    21,    39,    23,    26,
     194,    32,    33,    39,    39,    41,    37,    70,    33,    34,
      26,    36,   123,   124,    37,    89,   127,     9,   174,    11,
      12,    12,    96,    35,    33,    40,    51,    18,   139,    54,
      21,    33,    23,    40,   191,    60,    41,    33,    39,    64,
     196,    36,    33,    34,    32,    36,    39,    37,    33,    38,
     161,   125,   126,    39,    79,    36,    40,   168,    41,   170,
      51,    38,   173,    54,    33,    90,    26,   141,    40,    60,
      37,    33,    40,    64,    38,    33,    39,   188,    15,    36,
     191,   192,    23,   194,    38,   165,    42,    42,   113,    40,
      42,    36,   117,    42,    36,    20,     2,    67,     3,    90,
     177,   175,   165,   174,    70,    -1,   170,   132,     3,     4,
       5,     6,     7,     8,     9,    10,   173,    -1,    -1,   144,
      -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,   132,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,   144,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    -1,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    16,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    -1,    -1,    38,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      -1,    37,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    26,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    12,    45,    55,    56,    57,    58,    59,
      62,    26,    26,    32,    60,    26,    32,    63,    85,     0,
      40,    32,    49,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    26,    32,    34,    35,    41,    46,    47,    60,
      61,    39,    63,    64,    41,    46,    56,    26,    33,    46,
      52,    85,    37,    54,    32,    46,    50,    51,    37,    49,
      35,    46,    46,    27,    36,    48,    46,    40,    33,    85,
      40,    33,     9,    26,    27,    28,    29,    30,    31,    32,
      46,    47,    75,    77,    78,    79,    80,    81,    84,    41,
      39,    33,    39,    46,    14,    16,    19,    20,    21,    22,
      58,    65,    66,    67,    68,    69,    72,    73,    74,    75,
      80,    46,    53,    85,    46,    33,    46,    36,    61,    64,
      49,    46,    75,    32,    37,    39,    32,    35,    43,    80,
      52,    33,    39,    75,    75,    80,    54,    66,    75,    40,
      38,    41,    38,    46,    36,    46,    54,    33,    75,    26,
      75,    82,    83,    80,    80,    75,    76,    26,    52,    54,
      37,    40,    54,    67,    80,    40,    46,    33,    42,    38,
      39,    33,    36,    42,    15,    17,    18,    70,    71,    75,
      53,    75,    82,    75,    76,    54,    68,    80,    42,    71,
      38,    40,    42,    36,    42,    67,    66,    75,    67,    54,
      36
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
#line 137 "src/parsing/parser.y"
    { tree = new AST::Program{(yyvsp[(1) - (1)].top_level_declarations)->toStdVector()}; }
    break;

  case 3:
/* Line 1802 of yacc.c  */
#line 142 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(2) - (3)].type); }
    break;

  case 4:
/* Line 1802 of yacc.c  */
#line 143 "src/parsing/parser.y"
    { (yyval.type) = new AST::BoolType{}; }
    break;

  case 5:
/* Line 1802 of yacc.c  */
#line 144 "src/parsing/parser.y"
    { (yyval.type) = new AST::IntType{}; }
    break;

  case 6:
/* Line 1802 of yacc.c  */
#line 145 "src/parsing/parser.y"
    { (yyval.type) = new AST::Float32Type{}; }
    break;

  case 7:
/* Line 1802 of yacc.c  */
#line 146 "src/parsing/parser.y"
    { (yyval.type) = new AST::RuneType{}; }
    break;

  case 8:
/* Line 1802 of yacc.c  */
#line 147 "src/parsing/parser.y"
    { (yyval.type) = new AST::StringType{}; }
    break;

  case 9:
/* Line 1802 of yacc.c  */
#line 148 "src/parsing/parser.y"
    { (yyval.type) = new AST::PointerType{(yyvsp[(2) - (2)].type)}; }
    break;

  case 10:
/* Line 1802 of yacc.c  */
#line 149 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); }
    break;

  case 11:
/* Line 1802 of yacc.c  */
#line 150 "src/parsing/parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 12:
/* Line 1802 of yacc.c  */
#line 154 "src/parsing/parser.y"
    { (yyval.type) = new AST::CustomType{(yyvsp[(1) - (1)].identifier)}; delete (yyvsp[(1) - (1)].identifier); }
    break;

  case 13:
/* Line 1802 of yacc.c  */
#line 155 "src/parsing/parser.y"
    { (yyval.type) = new AST::ArrayType{(yyvsp[(2) - (4)].integer), (yyvsp[(4) - (4)].type)}; }
    break;

  case 14:
/* Line 1802 of yacc.c  */
#line 156 "src/parsing/parser.y"
    { (yyval.type) = new AST::SliceType{(yyvsp[(3) - (3)].type)}; }
    break;

  case 15:
/* Line 1802 of yacc.c  */
#line 157 "src/parsing/parser.y"
    { (yyval.type) = new AST::StructType{(yyvsp[(3) - (4)].fields)->toStdVector()}; delete (yyvsp[(3) - (4)].fields); }
    break;

  case 16:
/* Line 1802 of yacc.c  */
#line 158 "src/parsing/parser.y"
    { (yyval.type) = new AST::MapType{(yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].type)}; }
    break;

  case 17:
/* Line 1802 of yacc.c  */
#line 162 "src/parsing/parser.y"
    { (yyval.integer) = yylval.integer; }
    break;

  case 18:
/* Line 1802 of yacc.c  */
#line 167 "src/parsing/parser.y"
    { 
                                                (yyval.type) = new AST::FunctionType{(yyvsp[(1) - (2)].fields)->toStdVector(), (yyvsp[(2) - (2)].fields)->toStdVector()}; 
                                                delete (yyvsp[(1) - (2)].fields);
                                                delete (yyvsp[(2) - (2)].fields);
                                            }
    break;

  case 19:
/* Line 1802 of yacc.c  */
#line 175 "src/parsing/parser.y"
    { (yyval.fields) = new LinkedList<std::pair<std::string, AST::Type *>>; }
    break;

  case 20:
/* Line 1802 of yacc.c  */
#line 176 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(1) - (1)].fields); }
    break;

  case 21:
/* Line 1802 of yacc.c  */
#line 177 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (1)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 22:
/* Line 1802 of yacc.c  */
#line 186 "src/parsing/parser.y"
    { (yyval.fields) = new LinkedList<std::pair<std::string, AST::Type *>>; }
    break;

  case 23:
/* Line 1802 of yacc.c  */
#line 188 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(2) - (3)].fields); }
    break;

  case 24:
/* Line 1802 of yacc.c  */
#line 190 "src/parsing/parser.y"
    { (yyval.fields) = (yyvsp[(2) - (4)].fields); }
    break;

  case 25:
/* Line 1802 of yacc.c  */
#line 194 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (1)].type);
                                                auto list = new LinkedList<std::pair<std::string, AST::Type *>>;
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 26:
/* Line 1802 of yacc.c  */
#line 201 "src/parsing/parser.y"
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
#line 212 "src/parsing/parser.y"
    { 
                                                auto type = (yyvsp[(1) - (3)].type);
                                                auto list = (yyvsp[(3) - (3)].fields);
                                                list->insert(0, std::make_pair("", type));
                                                (yyval.fields) = list;
                                            }
    break;

  case 28:
/* Line 1802 of yacc.c  */
#line 219 "src/parsing/parser.y"
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
#line 233 "src/parsing/parser.y"
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
#line 244 "src/parsing/parser.y"
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
#line 258 "src/parsing/parser.y"
    { (yyval.block) = new AST::Block{(yyvsp[(2) - (3)].statements)->toStdVector()}; delete (yyvsp[(2) - (3)].statements); }
    break;

  case 32:
/* Line 1802 of yacc.c  */
#line 263 "src/parsing/parser.y"
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
#line 272 "src/parsing/parser.y"
    {
                                                auto function = (yyvsp[(1) - (1)].top_level_declaration);
                                                auto list = new LinkedList<AST::TopLevelDeclaration *>; 
                                                list->insert(0, function);
                                                (yyval.top_level_declarations) = list;
                                            }
    break;

  case 34:
/* Line 1802 of yacc.c  */
#line 282 "src/parsing/parser.y"
    { (yyval.top_level_declarations) = (yyvsp[(1) - (1)].top_level_declarations); }
    break;

  case 35:
/* Line 1802 of yacc.c  */
#line 284 "src/parsing/parser.y"
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
#line 297 "src/parsing/parser.y"
    {
                                                (yyval.top_level_declaration) = new AST::FunctionDeclaration{(yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].type), (yyvsp[(4) - (4)].block)};
                                            }
    break;

  case 37:
/* Line 1802 of yacc.c  */
#line 303 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(1) - (1)].declarations); }
    break;

  case 38:
/* Line 1802 of yacc.c  */
#line 304 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(1) - (1)].declarations); }
    break;

  case 39:
/* Line 1802 of yacc.c  */
#line 308 "src/parsing/parser.y"
    { 
                                                auto typeSpec = (yyvsp[(2) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 40:
/* Line 1802 of yacc.c  */
#line 314 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(3) - (4)].declarations); }
    break;

  case 41:
/* Line 1802 of yacc.c  */
#line 318 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::TypeAliasDeclaration{(yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].type)}; delete (yyvsp[(1) - (3)].identifier); }
    break;

  case 42:
/* Line 1802 of yacc.c  */
#line 319 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::TypeDefinitionDeclaration{(yyvsp[(1) - (2)].identifier), (yyvsp[(2) - (2)].type)}; delete (yyvsp[(1) - (2)].identifier); }
    break;

  case 43:
/* Line 1802 of yacc.c  */
#line 323 "src/parsing/parser.y"
    {  
                                                auto typeSpec = (yyvsp[(1) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>; 
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 44:
/* Line 1802 of yacc.c  */
#line 330 "src/parsing/parser.y"
    { 
                                                auto typeSpec = (yyvsp[(1) - (3)].declaration);
                                                auto list = (yyvsp[(3) - (3)].declarations); 
                                                list->insert(0, typeSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 45:
/* Line 1802 of yacc.c  */
#line 339 "src/parsing/parser.y"
    {
                                                auto varSpec = (yyvsp[(2) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration*>;
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 46:
/* Line 1802 of yacc.c  */
#line 345 "src/parsing/parser.y"
    { (yyval.declarations) = (yyvsp[(3) - (4)].declarations); }
    break;

  case 47:
/* Line 1802 of yacc.c  */
#line 349 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (2)].id_list)->toStdVector(), (yyvsp[(2) - (2)].type), {}}; }
    break;

  case 48:
/* Line 1802 of yacc.c  */
#line 351 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (4)].id_list)->toStdVector(), (yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expressions)->toStdVector()}; }
    break;

  case 49:
/* Line 1802 of yacc.c  */
#line 353 "src/parsing/parser.y"
    { (yyval.declaration) = new AST::VariableDeclaration{(yyvsp[(1) - (3)].id_list)->toStdVector(), nullptr, (yyvsp[(3) - (3)].expressions)->toStdVector()}; }
    break;

  case 50:
/* Line 1802 of yacc.c  */
#line 357 "src/parsing/parser.y"
    {
                                                auto varSpec = (yyvsp[(1) - (2)].declaration);
                                                auto list = new LinkedList<AST::Declaration *>;
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 51:
/* Line 1802 of yacc.c  */
#line 363 "src/parsing/parser.y"
    { 
                                                auto varSpec = (yyvsp[(1) - (3)].declaration);
                                                auto list = (yyvsp[(3) - (3)].declarations); 
                                                list->insert(0, varSpec);
                                                (yyval.declarations) = list;
                                            }
    break;

  case 52:
/* Line 1802 of yacc.c  */
#line 373 "src/parsing/parser.y"
    {
                                                auto stmt = (yyvsp[(1) - (1)].simple_statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, stmt);
                                                (yyval.statements) = list;
                                            }
    break;

  case 53:
/* Line 1802 of yacc.c  */
#line 379 "src/parsing/parser.y"
    {
                                                auto if_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, if_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 54:
/* Line 1802 of yacc.c  */
#line 385 "src/parsing/parser.y"
    {
                                                auto switch_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, switch_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 55:
/* Line 1802 of yacc.c  */
#line 391 "src/parsing/parser.y"
    {
                                                auto return_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, return_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 56:
/* Line 1802 of yacc.c  */
#line 397 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::BreakStatement{});
                                                (yyval.statements) = list;
                                            }
    break;

  case 57:
/* Line 1802 of yacc.c  */
#line 402 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, new AST::ContinueStatement{});
                                                (yyval.statements) = list;
                                            }
    break;

  case 58:
/* Line 1802 of yacc.c  */
#line 407 "src/parsing/parser.y"
    {
                                                auto for_statement = (yyvsp[(1) - (1)].statement);
                                                auto list = new LinkedList<AST::Statement *>;
                                                list->insert(0, for_statement);
                                                (yyval.statements) = list;
                                            }
    break;

  case 59:
/* Line 1802 of yacc.c  */
#line 413 "src/parsing/parser.y"
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
#line 425 "src/parsing/parser.y"
    { (yyval.simple_statement) = new AST::EmptyStatement{}; }
    break;

  case 61:
/* Line 1802 of yacc.c  */
#line 426 "src/parsing/parser.y"
    { (yyval.simple_statement) = new AST::ExpressionStatement{(yyvsp[(1) - (1)].expression)}; }
    break;

  case 62:
/* Line 1802 of yacc.c  */
#line 428 "src/parsing/parser.y"
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
#line 438 "src/parsing/parser.y"
    { 
                                                (yyval.statements) = new LinkedList<AST::Statement *>;
                                            }
    break;

  case 64:
/* Line 1802 of yacc.c  */
#line 442 "src/parsing/parser.y"
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
#line 455 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (3)].expression), (yyvsp[(3) - (3)].block), new AST::Block{{}}}; }
    break;

  case 66:
/* Line 1802 of yacc.c  */
#line 457 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(3) - (5)].block), new AST::Block{{(yyvsp[(5) - (5)].statement)}}}; }
    break;

  case 67:
/* Line 1802 of yacc.c  */
#line 459 "src/parsing/parser.y"
    { (yyval.statement) = new AST::IfStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(3) - (5)].block), (yyvsp[(5) - (5)].block)}; }
    break;

  case 68:
/* Line 1802 of yacc.c  */
#line 464 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::SwitchStatement{(yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].switch_clauses)->toStdVector()};
                                                delete (yyvsp[(4) - (5)].switch_clauses);
                                            }
    break;

  case 69:
/* Line 1802 of yacc.c  */
#line 472 "src/parsing/parser.y"
    {
                                                (yyval.switch_clause) = new AST::SwitchStatement::SwitchCaseClause{(yyvsp[(2) - (4)].expressions)->toStdVector(), (yyvsp[(4) - (4)].statements)->toStdVector()}; 
                                                delete (yyvsp[(2) - (4)].expressions);
                                                delete (yyvsp[(4) - (4)].statements);
                                            }
    break;

  case 70:
/* Line 1802 of yacc.c  */
#line 478 "src/parsing/parser.y"
    {
                                                (yyval.switch_clause) = new AST::SwitchStatement::SwitchDefaultClause{(yyvsp[(3) - (3)].statements)->toStdVector()}; 
                                                delete (yyvsp[(3) - (3)].statements);
                                            }
    break;

  case 71:
/* Line 1802 of yacc.c  */
#line 485 "src/parsing/parser.y"
    { 
                                                (yyval.switch_clauses) = new LinkedList<AST::SwitchStatement::SwitchClause *>;
                                            }
    break;

  case 72:
/* Line 1802 of yacc.c  */
#line 489 "src/parsing/parser.y"
    { 
                                                auto clause = (yyvsp[(1) - (2)].switch_clause);
                                                auto list = (yyvsp[(2) - (2)].switch_clauses);
                                                list->insert(0, clause);
                                                (yyval.switch_clauses) = list;
                                            }
    break;

  case 73:
/* Line 1802 of yacc.c  */
#line 498 "src/parsing/parser.y"
    { 
                                                (yyval.statement) = new AST::ReturnStatement{(yyvsp[(2) - (2)].expressions)->toStdVector()}; 
                                                delete (yyvsp[(2) - (2)].expressions);
                                            }
    break;

  case 74:
/* Line 1802 of yacc.c  */
#line 505 "src/parsing/parser.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 75:
/* Line 1802 of yacc.c  */
#line 510 "src/parsing/parser.y"
    {
                                                (yyval.statement) = new AST::ForConditionStatement{(yyvsp[(2) - (7)].simple_statement), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].simple_statement), (yyvsp[(7) - (7)].block)};
                                            }
    break;

  case 76:
/* Line 1802 of yacc.c  */
#line 514 "src/parsing/parser.y"
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
#line 522 "src/parsing/parser.y"
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
#line 533 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 79:
/* Line 1802 of yacc.c  */
#line 537 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 80:
/* Line 1802 of yacc.c  */
#line 538 "src/parsing/parser.y"
    { (yyval.expression) = nullptr; }
    break;

  case 81:
/* Line 1802 of yacc.c  */
#line 542 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 82:
/* Line 1802 of yacc.c  */
#line 543 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IdentifierExpression{(yyvsp[(1) - (1)].identifier)}; }
    break;

  case 83:
/* Line 1802 of yacc.c  */
#line 544 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 84:
/* Line 1802 of yacc.c  */
#line 548 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 85:
/* Line 1802 of yacc.c  */
#line 549 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 86:
/* Line 1802 of yacc.c  */
#line 550 "src/parsing/parser.y"
    { (yyval.expression) = new AST::FunctionLiteralExpression{(yyvsp[(2) - (3)].type), (yyvsp[(3) - (3)].block)}; }
    break;

  case 87:
/* Line 1802 of yacc.c  */
#line 554 "src/parsing/parser.y"
    { (yyval.expression) = new AST::BoolExpression{(yyvsp[(1) - (1)].boolean)}; }
    break;

  case 88:
/* Line 1802 of yacc.c  */
#line 555 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IntExpression{(yyvsp[(1) - (1)].integer)}; }
    break;

  case 89:
/* Line 1802 of yacc.c  */
#line 556 "src/parsing/parser.y"
    { (yyval.expression) = new AST::Float32Expression{(yyvsp[(1) - (1)].floating)}; }
    break;

  case 90:
/* Line 1802 of yacc.c  */
#line 557 "src/parsing/parser.y"
    { (yyval.expression) = new AST::RuneExpression{(yyvsp[(1) - (1)].rune)}; }
    break;

  case 91:
/* Line 1802 of yacc.c  */
#line 558 "src/parsing/parser.y"
    { (yyval.expression) = new AST::StringExpression{(yyvsp[(1) - (1)].string).string, (yyvsp[(1) - (1)].string).length}; }
    break;

  case 92:
/* Line 1802 of yacc.c  */
#line 562 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<AST::Expression *>{}; 
                                                list->insert(0, (yyvsp[(1) - (1)].expression));
                                                (yyval.expressions) = list;
                                                
                                            }
    break;

  case 93:
/* Line 1802 of yacc.c  */
#line 569 "src/parsing/parser.y"
    {
                                                auto list = (yyvsp[(3) - (3)].expressions);
                                                list->insert(0, (yyvsp[(1) - (3)].expression));
                                                (yyval.expressions) = list;
                                            }
    break;

  case 94:
/* Line 1802 of yacc.c  */
#line 577 "src/parsing/parser.y"
    {
                                                auto type = (yyvsp[(1) - (4)].type);
                                                auto elements = (yyvsp[(3) - (4)].keyed_expressions)->toStdVector();
                                                delete (yyvsp[(3) - (4)].keyed_expressions);
                                                (yyval.expression) = new AST::CompositLiteralExpression(type, elements);
                                            }
    break;

  case 95:
/* Line 1802 of yacc.c  */
#line 586 "src/parsing/parser.y"
    { (yyval.keyed_expressions) = (yyvsp[(1) - (1)].keyed_expressions); }
    break;

  case 96:
/* Line 1802 of yacc.c  */
#line 587 "src/parsing/parser.y"
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

  case 97:
/* Line 1802 of yacc.c  */
#line 600 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::pair<std::string, AST::Expression*>>;
                                                list->insert(0, std::make_pair((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].expression)));
                                                (yyval.keyed_expressions) = list;
                                            }
    break;

  case 98:
/* Line 1802 of yacc.c  */
#line 605 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::pair<std::string, AST::Expression*>>;
                                                list->insert(0, std::make_pair("", (yyvsp[(1) - (1)].expression)));
                                                (yyval.keyed_expressions) = list;
                                            }
    break;

  case 99:
/* Line 1802 of yacc.c  */
#line 613 "src/parsing/parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 100:
/* Line 1802 of yacc.c  */
#line 614 "src/parsing/parser.y"
    { (yyval.expression) = new AST::ConversionExpression((yyvsp[(1) - (4)].type), (yyvsp[(3) - (4)].expression)); }
    break;

  case 101:
/* Line 1802 of yacc.c  */
#line 615 "src/parsing/parser.y"
    { (yyval.expression) = new AST::SelectExpression{(yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identifier)}; }
    break;

  case 102:
/* Line 1802 of yacc.c  */
#line 616 "src/parsing/parser.y"
    { (yyval.expression) = new AST::IndexExpression{(yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression)}; }
    break;

  case 103:
/* Line 1802 of yacc.c  */
#line 618 "src/parsing/parser.y"
    { (yyval.expression) = new AST::SimpleSliceExpression{(yyvsp[(1) - (6)].expression), (yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].expression)}; }
    break;

  case 104:
/* Line 1802 of yacc.c  */
#line 620 "src/parsing/parser.y"
    { (yyval.expression) = new AST::FullSliceExpression{(yyvsp[(1) - (8)].expression), (yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), (yyvsp[(7) - (8)].expression)}; }
    break;

  case 105:
/* Line 1802 of yacc.c  */
#line 622 "src/parsing/parser.y"
    { (yyval.expression) = new AST::CallExpression{(yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expressions)->toStdVector()}; }
    break;

  case 106:
/* Line 1802 of yacc.c  */
#line 627 "src/parsing/parser.y"
    {
                                                auto list = new LinkedList<std::string>{}; 
                                                list->insert(0, (yyvsp[(1) - (1)].identifier));
                                                (yyval.id_list) = list;
                                                delete (yyvsp[(1) - (1)].identifier);
                                            }
    break;

  case 107:
/* Line 1802 of yacc.c  */
#line 634 "src/parsing/parser.y"
    {
                                                auto list = (yyvsp[(3) - (3)].id_list);
                                                list->insert(0, (yyvsp[(1) - (3)].identifier));
                                                (yyval.id_list) = list;
                                                delete (yyvsp[(1) - (3)].identifier);
                                            }
    break;


/* Line 1802 of yacc.c  */
#line 2670 "src/parsing/parser.cpp"
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
#line 642 "src/parsing/parser.y"


void yyerror(char *s)
{
    std::cerr << s << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
    if (*yytext == '\n') {
        std::cerr  << "unexpected newline (implicit semicolon)." << std::endl;
    } else {
        std::cerr  << "unexpected \'" << yytext << "\'." << std::endl;
    }
}