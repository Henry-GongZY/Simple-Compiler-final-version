%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
#include "symboltable.h"
#include "pch.h"
#include "type.h"
int lineno=1;
extern int last_num_of_layer[50][50];
extern int num_of_layer[100];
extern int layer;
extern idlist IDlist;
extern Type* TYPE_INT;
extern Type* TYPE_CHAR;
extern Type* TYPE_BOOL;
extern Type* TYPE_STRING;
extern Type* TYPE_VOID;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/\*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+
BOOL true|false
CHAR \'.?\'|\'\\t\'|\'\\n\'|\'\\r\'
STRING \".+\"
WHILE while
FOR for
IF if
ELSE else
MAIN main
SCANF scanf
PRINTF printf
RETURN return
OR \|\|
AND \&\&
NOT \!
BEQ \>\=
SEQ \<\=
BT \>
ST \<
EQ \=\=
NEQ \!\=
ADD \+
SUB \-
MUL \*
DIV \/
MOD \%
PLUS_ASSIGN \+\=
MINUS_ASSIGN \-\=
MULTI_ASSIGN \*\=
DIVID_ASSIGN \/\=
LOP_ASSIGN \=
SELFP \+\+
SELFM \-\-
LBRACE \{
RBRACE \}
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */


"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"string" return T_STRING;
"void" return T_VOID;
"&" return REFERENCE;
"(" return LPAREN;
")" return RPAREN;
"," return COMMA;
";" return SEMICOLON;



{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type=TYPE_INT;
    node->int_val=atoi(yytext);
    yylval = node;
    return INTEGER;
}

{BOOL} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type=TYPE_BOOL;
    if(string(yytext)=="true")
        node->b_val=true;
    else
        node->b_val=false;
    yylval = node;
    return BOOL;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type=TYPE_CHAR;
    if(yytext[1]=='\\'&&yytext[2]=='n')
        node->ch_val=char(10);   //换行符
    else if(yytext[1]=='\\'&&yytext[2]=='t') 
        node->ch_val=char(9);    //水平制表符
    else if(yytext[1]=='\\'&&yytext[2]==114)
        node->ch_val=char(13);   //回车符
    else
        node->ch_val=yytext[1];  //仅支持字符常量，取第一个
    yylval=node;
    return CHAR;
}

{STRING} {
    TreeNode*node = new TreeNode(lineno, NODE_CONST);
    node->type=TYPE_STRING;
    string str=string(yytext);
    node->str_val=str;
    yylval=node;
    return STRING;
}

{LOP_ASSIGN} {
    TreeNode* node = new TreeNode(lineno, NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_ASSIGN;
    yylval=node;
    return LOP_ASSIGN;
}

{PLUS_ASSIGN} {
    TreeNode* node = new TreeNode(lineno, NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_PLUS_ASSIGN;
    yylval=node;
    return PLUS_ASSIGN;
}

{MINUS_ASSIGN} {
    TreeNode* node = new TreeNode(lineno, NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_MINUS_ASSIGN;
    yylval=node;
    return MINUS_ASSIGN;
}

{MULTI_ASSIGN} {
    TreeNode* node = new TreeNode(lineno, NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_MULTITI_ASSIGN;
    yylval=node;
    return MULTI_ASSIGN;
}

{DIVID_ASSIGN} {
    TreeNode* node = new TreeNode(lineno, NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_DIVIDID_ASSIGN;
    yylval=node;
    return DIVID_ASSIGN;
}

{OR} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_LG_OR;
    yylval=node;
    return OR;
}

{AND} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_LG_AND;
    yylval=node;
    return AND;
}

{NOT} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_LG_NOT;
    yylval=node;
    return NOT;
}

{BEQ} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_BEQ;
    yylval=node;
    return BEQ;
}

{SEQ} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_SEQ;
    yylval=node;
    return SEQ;
}

{NEQ} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_NEQ;
    yylval=node;
    return NEQ;
}

{EQ} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_EQ;
    yylval=node;
    return EQ;
}

{BT} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_BT;
    yylval=node;
    return BT;
}

{ST} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_ST;
    yylval=node;
    return BT;
}

{ADD} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_PLUS;
    yylval=node;
    return ADD;
}

{SUB} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_MINUS;
    yylval=node;
    return SUB;
}

{MUL} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_MULTI;
    yylval=node;
    return MUL;
}

{DIV} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_DIVID;
    yylval=node;
    return DIV;
}

{MOD} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_MOD;
    yylval=node;
    return MOD;
}

{SELFP} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_SELFP;
    yylval=node;
    return SELFP;
}

{SELFM} {
    TreeNode* node= new TreeNode(lineno,NODE_OP);
    string str=string(yytext);
    node->op=str;
    node->optype=OP_SELFM;
    yylval=node;
    return SELFM;
}

{FOR} {
    TreeNode* node= new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return FOR;
}

{WHILE} {
    TreeNode* node= new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return WHILE;
}

{IF} {
    TreeNode* node= new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return IF;
}

{ELSE} {
    TreeNode* node=new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return ELSE;
}

{MAIN} {
    TreeNode* node=new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return MAIN;
}

{SCANF} {
    TreeNode* node=new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return SCANF;
}

{PRINTF} {
    TreeNode* node=new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return PRINTF;
}

{RETURN} {
    TreeNode* node=new TreeNode(lineno,NODE_KEYWORD);
    string str=string(yytext);
    node->var_name=str;
    yylval=node;
    return RETURN;
}
{LBRACE} {
    layer++;
    last_num_of_layer[layer][num_of_layer[layer]]=num_of_layer[layer-1];
    return LBRACE;
}

{RBRACE} {
    num_of_layer[layer]++;
    layer--;
    return RBRACE;
}
{WHILTESPACE}

{EOL} lineno++;


{IDENTIFIER} {
    string str=string(yytext);
    TreeNode* node=new TreeNode(lineno,NODE_VAR);
    node->int_val=0;
    node->b_val=0;
    node->ch_val='\0';
    node->var_name=str;
    yylval=node;
    IDlist.push_back(str,layer,num_of_layer[layer],node,1,num_of_layer[layer+1]);
    return IDENTIFIER;
}

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%