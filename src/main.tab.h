/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
