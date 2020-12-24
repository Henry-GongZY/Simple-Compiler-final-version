/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/main.y"

    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );

#line 79 "src/main.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_DOUBLE = 262,
    T_VOID = 263,
    LOP_ASSIGN = 264,
    PLUS_ASSIGN = 265,
    MINUS_ASSIGN = 266,
    MULTI_ASSIGN = 267,
    DIVID_ASSIGN = 268,
    MOD_ASSIGN = 269,
    SEMICOLON = 270,
    COMMA = 271,
    LBRACE = 272,
    RBRACE = 273,
    LPAREN = 274,
    RPAREN = 275,
    IDENTIFIER = 276,
    INTEGER = 277,
    CHAR = 278,
    STRING = 279,
    DOUBLE = 280,
    PLUS = 281,
    MINUS = 282,
    MULTI = 283,
    DIVIDE = 284,
    MOD = 285,
    SELFP = 286,
    SELFM = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    EQ = 291,
    BT = 292,
    ST = 293,
    BEQ = 294,
    SEQ = 295,
    NEQ = 296,
    LG_AND = 297,
    LG_OR = 298,
    LG_NOT = 299,
    UMINUS = 300,
    FOR = 301,
    MAIN = 302,
    IF = 303,
    ELSE = 304,
    WHILE = 305,
    RETURN = 306,
    PRINTF = 307,
    SCANF = 308,
    XOR = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   913

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    45,    46,    51,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    70,    71,    76,
      87,    90,    93,    96,    99,   102,   105,   108,   111,   114,
     117,   120,   123,   151,   158,   168,   169,   174,   179,   180,
     184,   188,   199,   209,   210,   215,   216,   221,   229,   239,
     243,   247,   253,   259,   265,   271,   277,   283,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   323,   324,   325,   326,   327,
     328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_DOUBLE", "T_VOID", "LOP_ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTI_ASSIGN", "DIVID_ASSIGN", "MOD_ASSIGN", "SEMICOLON", "COMMA",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "IDENTIFIER", "INTEGER", "CHAR",
  "STRING", "DOUBLE", "PLUS", "MINUS", "MULTI", "DIVIDE", "MOD", "SELFP",
  "SELFM", "AND", "OR", "NOT", "EQ", "BT", "ST", "BEQ", "SEQ", "NEQ",
  "LG_AND", "LG_OR", "LG_NOT", "UMINUS", "FOR", "MAIN", "IF", "ELSE",
  "WHILE", "RETURN", "PRINTF", "SCANF", "XOR", "$accept", "program",
  "statements", "statement", "while_stmt", "for_stmt", "function_call",
  "function_call_idlist", "function_call_id", "function_return",
  "if_else_stmt", "if_stmt", "else_stmt", "scanf_stmt", "printf_stmt",
  "declaration", "IDLIST", "assign_stmt", "do_assign", "expr", "T", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   150,   847,
      13,   -57,   -57,   -57,   -57,   847,   847,   847,    -2,    -1,
       1,    62,     2,     9,    29,   -57,   150,   -57,   -57,   -57,
     -57,   -57,   -36,   -57,   -57,    18,   -57,    26,   220,   -16,
      24,   -57,   423,   847,   847,   847,   847,   847,   847,   760,
     -22,   -22,   -22,   201,   847,   847,   -57,   249,   778,   796,
     -57,   -57,   150,   -57,   -57,   -57,   -57,   847,   847,   847,
     847,   847,   -57,   -57,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,    -5,    28,   -57,   -57,   -57,
     680,   680,   680,   680,   680,   680,    33,    23,    47,   680,
     631,   105,    49,    61,   278,    57,   452,   481,   -57,    65,
      68,    67,    70,   -57,   131,   131,   -22,   -22,   -22,   152,
     737,    72,    25,    25,    25,    25,    72,   718,   699,   872,
     847,    71,    73,   -57,    79,   847,   814,   307,   847,   646,
     661,   150,   150,   -57,    90,   -57,    93,   680,   104,   -57,
     150,   -57,   -57,   150,   112,   510,    -6,   336,   114,   365,
     115,   394,   -57,   -57,   -57,   -57,   -57,   -57,   150,   150,
     150,   105,   118,   862,   150,   862,   119,   832,   -57,   -57,
     -57,   150,   120,   539,   -57,   124,   568,   150,   150,   597,
     -57,   150,   150,   150,   150,   -57,   -57,   150,   -57,   -57,
     -57,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    86,    85,    88,    87,    89,    90,    16,     0,     0,
      80,    81,    83,    84,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,    10,     9,    11,
      12,     8,     7,    13,    14,     0,    15,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    68,    78,     0,     0,     0,    38,     0,     0,     0,
       1,     4,     0,    40,    17,    51,    18,     0,     0,     0,
       0,     0,    65,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    48,     6,    58,
      52,    53,    54,    55,    56,    57,     0,     0,    35,    37,
       0,    80,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    42,    59,    60,    61,    62,    63,    66,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    69,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    44,     0,    47,    50,    49,
       0,    33,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    19,    45,    43,     5,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    28,
      30,     0,     0,     0,    31,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,    26,    27,     0,    24,    23,
      20,    21,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,    -7,   -46,   -57,   -57,   -57,   -56,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,    96,    39,   -57,   -23,    -9,
     123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    97,    98,    30,
      31,    32,    63,    33,    34,    35,    87,    36,    37,    38,
      39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    40,   110,   112,   130,    85,    50,    51,    52,    72,
      73,   131,    57,    62,   170,   171,   113,    53,    54,    61,
      55,    58,    43,    44,    45,    46,    47,    48,    59,    60,
     103,    86,    49,    64,    90,    91,    92,    93,    94,    95,
      99,    65,    88,   134,   104,   106,   107,   132,   133,    99,
      99,    67,    68,    69,    70,    71,    72,    73,   114,   115,
     116,   117,   118,   135,   138,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   139,    56,    85,   152,
     143,     9,   145,    41,    11,    12,    13,    14,   144,    15,
     146,   137,   148,   150,   151,   162,   163,    16,    67,    68,
      69,    70,    71,    72,    73,   164,    17,   167,   165,    77,
      78,    79,    80,   154,    43,    44,    45,    46,    47,    48,
     131,   147,   178,   179,   180,     0,    99,   155,   184,   157,
     159,   161,   168,   172,   174,   190,   171,   176,   181,   187,
     191,   195,   196,   166,   193,   198,   199,   200,   201,   102,
     182,   202,   185,     1,     2,     3,     4,     5,     6,    69,
      70,    71,    72,    73,   183,     7,   186,     8,   189,     9,
     149,    10,    11,    12,    13,    14,   105,    15,    67,    68,
      69,    70,    71,    72,    73,    16,     0,     0,    76,    77,
      78,    79,    80,    81,    17,     0,    18,     0,    19,     0,
      20,    21,    22,    23,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       9,     0,   101,    11,    12,    13,    14,     0,    15,     0,
       0,     0,     0,     0,     0,    66,    16,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    83,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    83,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80,    81,    82,    83,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    83,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    84,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,   141,     0,     0,     0,     0,    84,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,    84,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,    84,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,   192,
       0,     0,     0,     0,    84,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,    84,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,    84,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       9,    84,    41,    11,    12,    13,    14,     0,    15,     0,
       0,   158,     0,     0,     0,     9,    16,    41,    11,    12,
      13,    14,     0,    15,     0,    17,   160,     0,     0,     0,
       9,    16,    41,    11,    12,    13,    14,     0,    15,     0,
      17,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    84,    76,    77,    78,    79,    80,
      81,    82,     0,     0,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    84,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    84,    76,    77,    78,    79,    80,    81,     9,
      96,    41,    11,    12,    13,    14,     0,    15,     0,     0,
       0,    84,     0,     0,     0,    16,     0,     9,   109,    41,
      11,    12,    13,    14,    17,    15,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     9,   111,    41,    11,    12,
      13,    14,    17,    15,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     9,   153,   101,    11,    12,    13,    14,
      17,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     9,   188,    41,    11,    12,    13,    14,    17,    15,
       0,     0,     0,     0,     0,     0,     9,    16,    41,    11,
      12,    13,    14,     0,    15,     0,    17,     0,     0,     0,
       0,     9,    16,   101,    11,    12,    13,    14,     0,    15,
       0,    17,     0,     0,     0,     0,     0,    16,    67,    68,
      69,    70,    71,    72,    73,    74,    17,     0,    76,    77,
      78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       9,     8,    58,    59,     9,    21,    15,    16,    17,    31,
      32,    16,    21,    49,    20,    21,    62,    19,    19,    26,
      19,    19,     9,    10,    11,    12,    13,    14,    19,     0,
      53,    47,    19,    15,    43,    44,    45,    46,    47,    48,
      49,    15,    18,    20,    53,    54,    55,    19,    15,    58,
      59,    26,    27,    28,    29,    30,    31,    32,    67,    68,
      69,    70,    71,    16,    15,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    15,    15,    21,   135,
      15,    19,    15,    21,    22,    23,    24,    25,    20,    27,
      20,   100,    21,    20,    15,   141,   142,    35,    26,    27,
      28,    29,    30,    31,    32,    15,    44,   153,    15,    37,
      38,    39,    40,   136,     9,    10,    11,    12,    13,    14,
      16,   130,   168,   169,   170,    -1,   135,   136,   174,   138,
     139,   140,    20,   156,    20,   181,    21,   160,    20,    20,
      20,   187,   188,   150,    20,   191,   192,   193,   194,    53,
     173,   197,   175,     3,     4,     5,     6,     7,     8,    28,
      29,    30,    31,    32,   173,    15,   175,    17,   177,    19,
     131,    21,    22,    23,    24,    25,    53,    27,    26,    27,
      28,    29,    30,    31,    32,    35,    -1,    -1,    36,    37,
      38,    39,    40,    41,    44,    -1,    46,    -1,    48,    -1,
      50,    51,    52,    53,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    54,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    54,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    54,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    54,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    54,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    54,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    54,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,    54,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    15,    -1,    -1,    -1,    19,    35,    21,    22,    23,
      24,    25,    -1,    27,    -1,    44,    15,    -1,    -1,    -1,
      19,    35,    21,    22,    23,    24,    25,    -1,    27,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    54,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    54,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    54,    36,    37,    38,    39,    40,    41,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    35,    -1,    19,    20,    21,
      22,    23,    24,    25,    44,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    19,    20,    21,    22,    23,
      24,    25,    44,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    19,    20,    21,    22,    23,    24,    25,
      44,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    19,    20,    21,    22,    23,    24,    25,    44,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    35,    21,    22,
      23,    24,    25,    -1,    27,    -1,    44,    -1,    -1,    -1,
      -1,    19,    35,    21,    22,    23,    24,    25,    -1,    27,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    35,    26,    27,
      28,    29,    30,    31,    32,    33,    44,    -1,    36,    37,
      38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    15,    17,    19,
      21,    22,    23,    24,    25,    27,    35,    44,    46,    48,
      50,    51,    52,    53,    56,    57,    58,    59,    60,    61,
      64,    65,    66,    68,    69,    70,    72,    73,    74,    75,
      57,    21,    74,     9,    10,    11,    12,    13,    14,    19,
      74,    74,    74,    19,    19,    19,    15,    74,    19,    19,
       0,    57,    49,    67,    15,    15,    15,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    54,    21,    47,    71,    18,    20,
      74,    74,    74,    74,    74,    74,    20,    62,    63,    74,
      15,    21,    70,    73,    74,    75,    74,    74,    15,    20,
      62,    20,    62,    58,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
       9,    16,    19,    15,    20,    16,    15,    74,    15,    15,
      15,    20,    20,    15,    20,    15,    20,    74,    21,    71,
      20,    15,    62,    20,    73,    74,    15,    74,    15,    74,
      15,    74,    58,    58,    15,    15,    57,    58,    20,    20,
      20,    21,    73,    15,    20,    15,    73,    15,    58,    58,
      58,    20,    73,    74,    58,    73,    74,    20,    20,    74,
      58,    20,    20,    20,    20,    58,    58,    20,    58,    58,
      58,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     5,
       9,     9,     9,     9,     9,     8,     8,     8,     7,     7,
       7,     7,     6,     5,     4,     1,     3,     1,     2,     3,
       2,     5,     2,     5,     4,     5,     4,     4,     2,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 41 "src/main.y"
             {root = new TreeNode(0, NODE_PROG); root->addChild(yyvsp[0]);}
#line 1636 "src/main.tab.cpp"
    break;

  case 3:
#line 45 "src/main.y"
             {yyval=yyvsp[0];}
#line 1642 "src/main.tab.cpp"
    break;

  case 4:
#line 46 "src/main.y"
                        {yyvsp[-1]->addSibling(yyvsp[0]); yyval=yyvsp[-1];}
#line 1648 "src/main.tab.cpp"
    break;

  case 5:
#line 51 "src/main.y"
                                  {
    yyvsp[-3]->addChild(yyvsp[-4]);
    yyvsp[-3]->addChild(yyvsp[0]);
    yyval = yyvsp[-3];
}
#line 1658 "src/main.tab.cpp"
    break;

  case 6:
#line 56 "src/main.y"
                           { yyval = yyvsp[-1]; }
#line 1664 "src/main.tab.cpp"
    break;

  case 7:
#line 57 "src/main.y"
          {yyval = yyvsp[0];}
#line 1670 "src/main.tab.cpp"
    break;

  case 8:
#line 58 "src/main.y"
               {yyval = yyvsp[0];}
#line 1676 "src/main.tab.cpp"
    break;

  case 9:
#line 59 "src/main.y"
           {yyval = yyvsp[0];}
#line 1682 "src/main.tab.cpp"
    break;

  case 10:
#line 60 "src/main.y"
             {yyval = yyvsp[0];}
#line 1688 "src/main.tab.cpp"
    break;

  case 11:
#line 61 "src/main.y"
                {yyval=yyvsp[0]; }
#line 1694 "src/main.tab.cpp"
    break;

  case 12:
#line 62 "src/main.y"
                  {yyval=yyvsp[0]; }
#line 1700 "src/main.tab.cpp"
    break;

  case 13:
#line 63 "src/main.y"
             {yyval = yyvsp[0];}
#line 1706 "src/main.tab.cpp"
    break;

  case 14:
#line 64 "src/main.y"
              {yyval = yyvsp[0];}
#line 1712 "src/main.tab.cpp"
    break;

  case 15:
#line 65 "src/main.y"
              {yyval = yyvsp[0];}
#line 1718 "src/main.tab.cpp"
    break;

  case 16:
#line 66 "src/main.y"
             {
    yyval = new TreeNode(lineno, NODE_STMT); 
    yyval->stype = STMT_SKIP;
}
#line 1727 "src/main.tab.cpp"
    break;

  case 17:
#line 70 "src/main.y"
                        {yyval = yyvsp[-1];}
#line 1733 "src/main.tab.cpp"
    break;

  case 18:
#line 71 "src/main.y"
                 {yyval = yyvsp[-1];}
#line 1739 "src/main.tab.cpp"
    break;

  case 19:
#line 76 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 1750 "src/main.tab.cpp"
    break;

  case 20:
#line 87 "src/main.y"
                                                                          {
    TreeNode* node = for_addChild(yyvsp[-8]->lineno, yyvsp[-6], yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1758 "src/main.tab.cpp"
    break;

  case 21:
#line 90 "src/main.y"
                                                                      {
    TreeNode* node = for_addChild(yyvsp[-8]->lineno, yyvsp[-6], yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1766 "src/main.tab.cpp"
    break;

  case 22:
#line 93 "src/main.y"
                                                                 {
    TreeNode* node = for_addChild(yyvsp[-8]->lineno, yyvsp[-6], yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1774 "src/main.tab.cpp"
    break;

  case 23:
#line 96 "src/main.y"
                                                                        {
    TreeNode* node = for_addChild(yyvsp[-8]->lineno, yyvsp[-6], yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1782 "src/main.tab.cpp"
    break;

  case 24:
#line 99 "src/main.y"
                                                                             {
    TreeNode* node = for_addChild(yyvsp[-8]->lineno, yyvsp[-6], yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1790 "src/main.tab.cpp"
    break;

  case 25:
#line 102 "src/main.y"
                                                                 {
    TreeNode* node = for_addChild(yyvsp[-7]->lineno, nullptr, yyvsp[-4], yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1798 "src/main.tab.cpp"
    break;

  case 26:
#line 105 "src/main.y"
                                                                 {
    TreeNode* node = for_addChild(yyvsp[-7]->lineno, yyvsp[-5], nullptr, yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1806 "src/main.tab.cpp"
    break;

  case 27:
#line 108 "src/main.y"
                                                            {
    TreeNode* node = for_addChild(yyvsp[-7]->lineno, yyvsp[-5], yyvsp[-3], nullptr, yyvsp[0]);
    yyval = node;}
#line 1814 "src/main.tab.cpp"
    break;

  case 28:
#line 111 "src/main.y"
                                                       {
    TreeNode* node = for_addChild(yyvsp[-6]->lineno, nullptr, nullptr, yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1822 "src/main.tab.cpp"
    break;

  case 29:
#line 114 "src/main.y"
                                                            {
    TreeNode* node = for_addChild(yyvsp[-6]->lineno, nullptr, nullptr, yyvsp[-2], yyvsp[0]);
    yyval = node;}
#line 1830 "src/main.tab.cpp"
    break;

  case 30:
#line 117 "src/main.y"
                                                       {
    TreeNode* node = for_addChild(yyvsp[-6]->lineno, nullptr, yyvsp[-3], nullptr, yyvsp[0]);
    yyval = node;}
#line 1838 "src/main.tab.cpp"
    break;

  case 31:
#line 120 "src/main.y"
                                                            {
    TreeNode* node = for_addChild(yyvsp[-6]->lineno, yyvsp[-4], nullptr, nullptr, yyvsp[0]);
    yyval = node;}
#line 1846 "src/main.tab.cpp"
    break;

  case 32:
#line 123 "src/main.y"
                                                  {
    TreeNode* node = for_addChild(yyvsp[-5]->lineno, nullptr, nullptr, nullptr, yyvsp[0]);
    yyval = node;}
#line 1854 "src/main.tab.cpp"
    break;

  case 33:
#line 151 "src/main.y"
                                                         {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno,NODE_STMT);
    node->stype = STMT_FUNC_CALL;
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    yyval = node;
}
#line 1866 "src/main.tab.cpp"
    break;

  case 34:
#line 158 "src/main.y"
                                    {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno,NODE_STMT);
    node->stype = STMT_FUNC_CALL;
    node->addChild(yyvsp[-3]);
    yyval = node;
}
#line 1877 "src/main.tab.cpp"
    break;

  case 35:
#line 168 "src/main.y"
                   { yyval=yyvsp[0]; }
#line 1883 "src/main.tab.cpp"
    break;

  case 36:
#line 169 "src/main.y"
                                             { yyvsp[-2]->addSibling(yyvsp[0]); yyval=yyvsp[-2];}
#line 1889 "src/main.tab.cpp"
    break;

  case 37:
#line 174 "src/main.y"
       {yyval = yyvsp[0]; }
#line 1895 "src/main.tab.cpp"
    break;

  case 38:
#line 179 "src/main.y"
                   {yyval = yyvsp[-1];}
#line 1901 "src/main.tab.cpp"
    break;

  case 39:
#line 180 "src/main.y"
                        { yyvsp[-2]->addSibling(yyvsp[-1]); yyval=yyvsp[-2]; }
#line 1907 "src/main.tab.cpp"
    break;

  case 40:
#line 184 "src/main.y"
                    {yyvsp[-1]->addSibling(yyvsp[0]); yyval = yyvsp[-1];}
#line 1913 "src/main.tab.cpp"
    break;

  case 41:
#line 188 "src/main.y"
                                  {
    //开辟 if 空间
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno,NODE_STMT);
    node->stype = STMT_IF;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 1926 "src/main.tab.cpp"
    break;

  case 42:
#line 199 "src/main.y"
                 {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno,NODE_STMT);
    node->stype = STMT_ELSE;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 1937 "src/main.tab.cpp"
    break;

  case 43:
#line 209 "src/main.y"
                                                     {yyvsp[-4]->addChild(yyvsp[-2]); yyval=yyvsp[-4];}
#line 1943 "src/main.tab.cpp"
    break;

  case 44:
#line 210 "src/main.y"
                                {yyval=yyvsp[-3];}
#line 1949 "src/main.tab.cpp"
    break;

  case 45:
#line 215 "src/main.y"
                                                      {yyvsp[-4]->addChild(yyvsp[-2]); yyval=yyvsp[-4];}
#line 1955 "src/main.tab.cpp"
    break;

  case 46:
#line 216 "src/main.y"
                                 {yyval=yyvsp[-3];}
#line 1961 "src/main.tab.cpp"
    break;

  case 47:
#line 221 "src/main.y"
                              {  //int a = 表达式
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;   
}
#line 1974 "src/main.tab.cpp"
    break;

  case 48:
#line 229 "src/main.y"
           { //int 标识符列表
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    yyval = node;   
}
#line 1986 "src/main.tab.cpp"
    break;

  case 49:
#line 239 "src/main.y"
                          {
    yyvsp[-2]->addSibling(yyvsp[0]);
    yyval = yyvsp[-2];
}
#line 1995 "src/main.tab.cpp"
    break;

  case 50:
#line 243 "src/main.y"
             { yyval = yyvsp[0]; }
#line 2001 "src/main.tab.cpp"
    break;

  case 51:
#line 247 "src/main.y"
                     {
    yyval=yyvsp[-1];
}
#line 2009 "src/main.tab.cpp"
    break;

  case 52:
#line 253 "src/main.y"
                             {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2020 "src/main.tab.cpp"
    break;

  case 53:
#line 259 "src/main.y"
                              {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_PLUS_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2031 "src/main.tab.cpp"
    break;

  case 54:
#line 265 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_MINUS_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2042 "src/main.tab.cpp"
    break;

  case 55:
#line 271 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_MULTI_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2053 "src/main.tab.cpp"
    break;

  case 56:
#line 277 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_DIVID_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2064 "src/main.tab.cpp"
    break;

  case 57:
#line 283 "src/main.y"
                             {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype = STMT_MOD_ASSIGN;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;}
#line 2075 "src/main.tab.cpp"
    break;

  case 58:
#line 293 "src/main.y"
                      { yyval = yyvsp[-1]; }
#line 2081 "src/main.tab.cpp"
    break;

  case 59:
#line 294 "src/main.y"
                        { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2087 "src/main.tab.cpp"
    break;

  case 60:
#line 295 "src/main.y"
                        { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2093 "src/main.tab.cpp"
    break;

  case 61:
#line 296 "src/main.y"
                        { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2099 "src/main.tab.cpp"
    break;

  case 62:
#line 297 "src/main.y"
                        { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2105 "src/main.tab.cpp"
    break;

  case 63:
#line 298 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2111 "src/main.tab.cpp"
    break;

  case 64:
#line 299 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-1], yyvsp[0], NULL); }
#line 2117 "src/main.tab.cpp"
    break;

  case 65:
#line 300 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-1], yyvsp[0], NULL); }
#line 2123 "src/main.tab.cpp"
    break;

  case 66:
#line 301 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2129 "src/main.tab.cpp"
    break;

  case 67:
#line 302 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2135 "src/main.tab.cpp"
    break;

  case 68:
#line 303 "src/main.y"
                    { yyval = expr_addChild(yyvsp[0], yyvsp[-1], NULL); }
#line 2141 "src/main.tab.cpp"
    break;

  case 69:
#line 304 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2147 "src/main.tab.cpp"
    break;

  case 70:
#line 305 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2153 "src/main.tab.cpp"
    break;

  case 71:
#line 306 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2159 "src/main.tab.cpp"
    break;

  case 72:
#line 307 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2165 "src/main.tab.cpp"
    break;

  case 73:
#line 308 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2171 "src/main.tab.cpp"
    break;

  case 74:
#line 309 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2177 "src/main.tab.cpp"
    break;

  case 75:
#line 310 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2183 "src/main.tab.cpp"
    break;

  case 76:
#line 311 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2189 "src/main.tab.cpp"
    break;

  case 77:
#line 312 "src/main.y"
                    { yyval = expr_addChild(yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 2195 "src/main.tab.cpp"
    break;

  case 78:
#line 313 "src/main.y"
                    { yyval = expr_addChild(yyvsp[0], yyvsp[-1], NULL); }
#line 2201 "src/main.tab.cpp"
    break;

  case 79:
#line 314 "src/main.y"
                            { yyval = expr_addChild(yyvsp[0], yyvsp[-1], NULL); yyval->type = yyvsp[0]->type;}
#line 2207 "src/main.tab.cpp"
    break;

  case 80:
#line 315 "src/main.y"
                 { yyval = yyvsp[0]; yyval->type = yyvsp[0]->type;}
#line 2213 "src/main.tab.cpp"
    break;

  case 81:
#line 316 "src/main.y"
                 { yyval = yyvsp[0]; yyval->type = TYPE_INT;}
#line 2219 "src/main.tab.cpp"
    break;

  case 82:
#line 317 "src/main.y"
                 { yyval = yyvsp[0]; yyval->type = TYPE_DOUBLE;}
#line 2225 "src/main.tab.cpp"
    break;

  case 83:
#line 318 "src/main.y"
                 { yyval = yyvsp[0]; yyval->type = TYPE_CHAR;}
#line 2231 "src/main.tab.cpp"
    break;

  case 84:
#line 319 "src/main.y"
                 { yyval = yyvsp[0]; yyval->type = TYPE_STRING;}
#line 2237 "src/main.tab.cpp"
    break;

  case 85:
#line 323 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_INT;}
#line 2243 "src/main.tab.cpp"
    break;

  case 86:
#line 324 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_CHAR;}
#line 2249 "src/main.tab.cpp"
    break;

  case 87:
#line 325 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_BOOL;}
#line 2255 "src/main.tab.cpp"
    break;

  case 88:
#line 326 "src/main.y"
           {yyval = new TreeNode(lineno,NODE_TYPE); yyval->type = TYPE_STRING;}
#line 2261 "src/main.tab.cpp"
    break;

  case 89:
#line 327 "src/main.y"
           {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_DOUBLE;}
#line 2267 "src/main.tab.cpp"
    break;

  case 90:
#line 328 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_VOID;}
#line 2273 "src/main.tab.cpp"
    break;


#line 2277 "src/main.tab.cpp"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 331 "src/main.y"


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
