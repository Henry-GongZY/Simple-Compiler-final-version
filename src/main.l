%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/\*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+
DOUBLE [0-9]+(\.[0-9]+)?
CHAR \'.?\'
STRING \".+\"
LPAREN \(
RPAREN \)
LBRACE \{
RBRACE \}
BT \>
ST \<
EQ ==
BEQ \>=
SEQ \<=
NEQ !=
LG_AND &&
LG_OR \|\|
LG_NOT !
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */

"if" return IF;
"else" return ELSE;
"for" return FOR;
"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"double" return T_DOUBLE;
"void" return T_VOID;
"=" return LOP_ASSIGN;
"+=" return PLUS_ASSIGN;
"-=" return MINUS_ASSIGN;
"*=" return MULTI_ASSIGN;
"/=" return DIVID_ASSIGN;
"%=" return MOD_ASSIGN;
";" return SEMICOLON;
"," return COMMA;
"while" return WHILE;

"main" {
    TreeNode* node = new TreeNode(lineno, NODE_MAIN);
    yylval = node;
    return MAIN;
}

"return" {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    yylval = node;
    return RETURN;
}

"printf" {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_PRINTF;
    yylval = node;
    return PRINTF;
}

"scanf" {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SCANF;
    yylval = node;
    return SCANF;
}

"+" {
    TreeNode* node = new TreeNode(lineno,NODE_EXPR);
    node->optype = OP_PLUS;
    yylval = node;
    return PLUS;
}

"-" {
    TreeNode* node = new TreeNode(lineno,NODE_EXPR);
    node->optype = OP_MINUS;
    yylval = node;
    return MINUS;
}

"*" {
    TreeNode* node = new TreeNode(lineno,NODE_EXPR);
    node->optype = OP_MULTI;
    yylval = node;
    return MULTI;
}

"/" {
    TreeNode* node = new TreeNode(lineno,NODE_EXPR);
    node->optype = OP_DIVID;
    yylval = node;
    return DIVIDE;
}

"%" {
    TreeNode* node = new TreeNode(lineno,NODE_EXPR);
    node->optype = OP_MOD;
    yylval = node;
    return MOD;
}

"&" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_AND;
    yylval = node;
    return AND;
}

"|" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_OR;
    yylval = node;
    return OR;
}

"~" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_NOT;
    yylval = node;
    return NOT;
}

"!" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_LG_NOT;
    yylval = node;
    return LG_NOT;
}

"++" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_SELFP;
    yylval = node;
    return SELFP;
}

"--" {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_SELFM;
    yylval = node;
    return SELFM;
}

{BT} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_BT;
    yylval = node;
    return BT;
}

{ST} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_ST;
    yylval = node;
    return ST;
}

{EQ} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_EQ;
    yylval = node;
    return EQ;
}

{BEQ} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_BEQ;
    yylval = node;
    return BEQ;
}

{SEQ} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_SEQ;
    yylval = node;
    return SEQ;
}

{NEQ} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_NEQ;
    yylval = node;
    return NEQ;
}

{LG_AND} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_LG_AND;
    yylval = node;
    return LG_AND;
}

{LG_OR} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_LG_OR;
    yylval = node;
    return LG_OR;
}

{LG_NOT} {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->optype = OP_LG_NOT;
    yylval = node;
    return LG_NOT;
}

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST); //常量节点和行数
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST); //常量节点和行数
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST); //常量节点和行数
    node->type = TYPE_STRING;
    node->str_val = string(yytext);
    yylval = node;
    return STRING;
}

{DOUBLE} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_DOUBLE;
    node->d_val = atof(yytext);
    yylval = node;
    return DOUBLE;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);  //变量节点和行数
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{LPAREN} return LPAREN;
{RPAREN} return RPAREN;
{LBRACE} return LBRACE;
{RBRACE} return RBRACE;

{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%