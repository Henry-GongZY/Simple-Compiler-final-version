%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL T_DOUBLE T_VOID

%token LOP_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTI_ASSIGN DIVID_ASSIGN MOD_ASSIGN

%token SEMICOLON COMMA LBRACE RBRACE LPAREN RPAREN

%token IDENTIFIER INTEGER CHAR STRING DOUBLE

%token PLUS MINUS MULTI DIVIDE MOD SELFP SELFM AND OR NOT EQ

%token BT ST BEQ SEQ NEQ LG_AND LG_OR LG_NOT UMINUS

%token FOR MAIN IF ELSE WHILE RETURN

%token PRINTF SCANF

%left LG_OR
%left LG_AND
%left OR
%left XOR
%left AND
%left EQ NEQ
%left BT ST BEQ SEQ
%left PLUS MINUS
%left MULTI DIVIDE MOD
%left NOT LG_NOT
%left UMINUS
%left SELFP SELFM

%%
//程序
program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};

//语句序列
statements
:  statement {$$=$1;}
|  statement statements {$1->addSibling($2); $$=$1;}
;

//语句
statement
: T MAIN LPAREN RPAREN statements {
    $2->addChild($1);
    $2->addChild($5);
    $$ = $2;
}
| LBRACE statements RBRACE { $$ = $2; }
| if_stmt {$$ = $1;} 
| if_else_stmt {$$ = $1;}
| for_stmt {$$ = $1;}
| while_stmt {$$ = $1;}
| function_call {$$=$1; }//函数调用
| function_return {$$=$1; }//函数返回
| scanf_stmt {$$ = $1;}
| printf_stmt {$$ = $1;}
| assign_stmt {$$ = $1;}
| SEMICOLON  {
    $$ = new TreeNode(lineno, NODE_STMT); 
    $$->stype = STMT_SKIP;
}
| declaration SEMICOLON {$$ = $1;}
| expr SEMICOLON {$$ = $1;}
;

//while语句
while_stmt
: WHILE LPAREN expr RPAREN statement {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    $$ = node;}
;

//for语句的不同情况
for_stmt
: 
  FOR LPAREN do_assign SEMICOLON expr SEMICOLON do_assign RPAREN statement {
    TreeNode* node = for_addChild($1->lineno, $3, $5, $7, $9);
    $$ = node;}
| FOR LPAREN do_assign SEMICOLON expr SEMICOLON expr RPAREN statement {
    TreeNode* node = for_addChild($1->lineno, $3, $5, $7, $9);
    $$ = node;}
| FOR LPAREN declaration SEMICOLON expr SEMICOLON expr RPAREN statement {
    TreeNode* node = for_addChild($1->lineno, $3, $5, $7, $9);
    $$ = node;}
| FOR LPAREN declaration SEMICOLON expr SEMICOLON do_assign RPAREN statement {
    TreeNode* node = for_addChild($1->lineno, $3, $5, $7, $9);
    $$ = node;}
;


//声明标识符
function_declaration_id
: T IDENTIFIER LOP_ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;
} 
| T IDENTIFIER {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;}
| T {$$=$1;}
;


//函数调用
function_call
: IDENTIFIER LPAREN function_call_idlist RPAREN SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = STMT_FUNC_CALL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| IDENTIFIER LPAREN RPAREN SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = STMT_FUNC_CALL;
    node->addChild($1);
    $$ = node;
}
;

//函数调用标识符列表
function_call_idlist
: function_call_id { $$=$1; }
| function_call_id COMMA function_call_idlist{ $1->addSibling($3); $$=$1;}
;

//函数调用标识符
function_call_id
: expr {$$ = $1; }
;

//函数返回
function_return
: RETURN SEMICOLON {$$ = $1;}
| RETURN expr SEMICOLON { $1->addSibling($2); $$=$1; }

//if else语句
if_else_stmt
: if_stmt else_stmt {$1->addSibling($2); $$ = $1;}
;

if_stmt
: IF LPAREN expr RPAREN statement {
    //开辟 if 空间
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = STMT_IF;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
;

else_stmt
: ELSE statement {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = STMT_ELSE;
    node->addChild($2);
    $$ = node;
}
;

//输入
scanf_stmt
: SCANF LPAREN function_call_idlist RPAREN SEMICOLON {$1->addChild($3); $$=$1;}
| SCANF LPAREN RPAREN SEMICOLON {$$=$1;}
;

//输出
printf_stmt
: PRINTF LPAREN function_call_idlist RPAREN SEMICOLON {$1->addChild($3); $$=$1;}
| PRINTF LPAREN RPAREN SEMICOLON {$$=$1;}
;

//声明
declaration
: T IDENTIFIER LOP_ASSIGN expr{  //int a = 表达式
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T IDLIST { //int 标识符列表
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
;

IDLIST
: IDENTIFIER COMMA IDLIST {
    $1->addSibling($3);
    $$ = $1;
}
| IDENTIFIER { $$ = $1; }
;

assign_stmt
: do_assign SEMICOLON{
    $$=$1;
}

//几种赋值or计算赋值
do_assign
: IDENTIFIER LOP_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
| IDENTIFIER PLUS_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_PLUS_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
| IDENTIFIER MINUS_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_MINUS_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
| IDENTIFIER MULTI_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_MULTI_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
| IDENTIFIER DIVID_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DIVID_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
| IDENTIFIER MOD_ASSIGN expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_MOD_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;}
;

//表达式
expr
: LPAREN expr RPAREN  { $$ = $2; }
| expr PLUS expr	{ $$ = expr_addChild($1, $2, $3); } //ok
| expr MINUS expr	{ $$ = expr_addChild($1, $2, $3); } //ok
| expr MULTI expr	{ $$ = expr_addChild($1, $2, $3); } //ok
| expr DIVIDE expr	{ $$ = expr_addChild($1, $2, $3); } //ok
| expr MOD expr	    { $$ = expr_addChild($1, $2, $3); } //ok
| expr SELFM        { $$ = expr_addChild($1, $2, NULL); } //ok
| expr SELFP        { $$ = expr_addChild($1, $2, NULL); } //ok
| expr AND expr     { $$ = expr_addChild($1, $2, $3); }   //ok
| expr OR expr      { $$ = expr_addChild($1, $2, $3); }   //ok
| NOT expr          { $$ = expr_addChild($2, $1, NULL); } //ok
| expr XOR expr     { $$ = expr_addChild($1, $2, $3); } //not ready
| expr EQ expr      { $$ = expr_addChild($1, $2, $3); } //ok
| expr BT expr      { $$ = expr_addChild($1, $2, $3); } //ok
| expr ST expr      { $$ = expr_addChild($1, $2, $3); } //ok
| expr BEQ expr     { $$ = expr_addChild($1, $2, $3); } //ok
| expr SEQ expr     { $$ = expr_addChild($1, $2, $3); } //ok
| expr NEQ expr     { $$ = expr_addChild($1, $2, $3); } //ok
| expr LG_AND expr  { $$ = expr_addChild($1, $2, $3); }  //not ready
| expr LG_OR expr   { $$ = expr_addChild($1, $2, $3); }  //not ready
| LG_NOT expr       { $$ = expr_addChild($2, $1, NULL); } //not ready
| MINUS expr %prec UMINUS   { $$ = expr_addChild($2, $1, NULL); $$->type = $2->type;}
| IDENTIFIER     { $$ = $1; $$->type = $1->type;}
| INTEGER        { $$ = $1; $$->type = TYPE_INT;}
| DOUBLE         { $$ = $1; $$->type = TYPE_DOUBLE;}
| CHAR           { $$ = $1; $$->type = TYPE_CHAR;}
| STRING         { $$ = $1; $$->type = TYPE_STRING;}
;

//类型
T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_STRING;}
| T_DOUBLE {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_DOUBLE;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}