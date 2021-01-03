%{
    #include "common.h"
    #include "symboltable.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern SymbolTable IDlist;
    extern int layer;
    extern int num_of_layer[100];
    extern Type* TYPE_INT;
    extern Type* TYPE_CHAR;
    extern Type* TYPE_BOOL;
    extern Type* TYPE_STRING;
    extern Type* TYPE_VOID;
    int yylex();
    int yyerror( char const * );
%}

%start program

%token T_CHAR T_INT T_STRING T_BOOL T_VOID WHILE FOR IF ELSE MAIN SCANF PRINTF RETURN

%token COMMA LPAREN RPAREN LBRACE RBRACE SEMICOLON REFERENCE 

%token LOP_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTI_ASSIGN DIVID_ASSIGN 

%token OR AND NOT EQ NEQ BT ST BEQ SEQ

%token ADD SUB MUL DIV MOD

%token IDENTIFIER INTEGER CHAR BOOL STRING 

%left EQ NEQ BT ST BEQ SEQ

%left ADD SUB

%left MUL DIV MOD

%right LOP_ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTI_ASSIGN DIVID_ASSIGN

%right UMINUS UADD NOT

%right SELFP_R SELFM_R

%left SELFP SELFM

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

//现可支持全局变量
program
: program function
    {
        root->addChild($2);
    }
| program decl_stmt SEMICOLON
    {
        root->addChild($2);
    }
| decl_stmt SEMICOLON
    {
        root=new TreeNode(0,NODE_PROG);
        root->addChild($1);
    }
| function
    {
        root=new TreeNode(0,NODE_PROG);
        root->addChild($1);
    }
;

function
: T MAIN LPAREN RPAREN statements
    {
        $1->addSibling($2);
        $1->addSibling($5);
        $$=$1;
    }
;

statements
:  statement {
        $$=$1;
    }
|  statements statement{   
        $$->addSibling($2); 
        $$=$1; 
    }
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| decl_stmt SEMICOLON {$$ = $1;}
| assign_stmt SEMICOLON {$$ = $1;}
| scanf_stmt SEMICOLON {$$ = $1;}
| printf_stmt SEMICOLON {$$ = $1;}
| return SEMICOLON {$$ = $1;}
| while_stmt {$$ = $1;}
| if_stmt {$$ = $1;}
| for_stmt {$$ = $1;}
| LBRACE statements RBRACE {
        TreeNode* node = new TreeNode(lineno,NODE_STMT); 
        node->stype=STMT_BLOCK;
        node->addChild($2);
        $$=node;
    }
;

return 
: RETURN INTEGER{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_RET;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
;

decl_stmt
: T IDENTIFIER LOP_ASSIGN add_sub_expr{
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_DECL;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        node->addChild($4);
        Symbol *x=IDlist.find_by_node($2);
        x->declaration=0;//将节点设置为声明节点
        x->node_type=$1->type;//记录节点的类型
        $2->type=$1->type; //把ID类型赋给ID
        if(IDlist.check_redefine(x)==true){
            cerr<<"Redefine variable "<<x->name<<" at line "<<$2->lineno<<endl;
            exit(1);
        }
        if($4->type!=$2->type){
            if($2->type==TYPE_INT) //支持类型转换
            {
                if($4->type==TYPE_BOOL){
                    $4->type=TYPE_INT;
                    $4->int_val=$4->b_val;
                }
                else if($4->type==TYPE_CHAR){
                    $4->type=TYPE_INT;
                    $4->int_val=$4->ch_val;
                }
                else{
                    cerr<<"Wrong string type at line "<<$4->lineno<<endl;
                    exit(1);
                }
            }
            else if($2->type==TYPE_BOOL) 
            {
                if($4->type==TYPE_INT){
                    $4->type=TYPE_BOOL;
                    $4->b_val=$4->int_val;
                }
                else if($4->type==TYPE_CHAR){
                    $4->type=TYPE_BOOL;
                    $4->b_val=$4->ch_val;
                }
                else{
                    cerr<<"Wrong string type at line "<<$4->lineno<<endl;
                    exit(1);
                }
            }
            else if($2->type==TYPE_CHAR)
            {
                if($4->type==TYPE_BOOL){
                    $4->type=TYPE_CHAR;
                    $4->ch_val=$4->b_val;
                }
                else if($4->type==TYPE_INT){
                    $4->type=TYPE_CHAR;
                    $4->ch_val=$4->int_val;
                }
                else{
                    cerr<<"Wrong string type at line "<<$4->lineno<<endl;
                    exit(1); 
                }
            }
            else 
            {
                cerr<<"Wrong string type at line "<<$4->lineno<<endl;
                exit(1);
            }
        }      
        $$ = node;   
    } 
| T SymbolTable {
        TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
        node->stype = STMT_DECL;
        node->addChild($1);
        node->addChild($2);
        TreeNode* curr=$2;
        while(curr!=nullptr){
            if(curr->nodeType==NODE_VAR){
                Symbol* y=IDlist.find_by_node(curr);
                //组合拳三件套
                y->declaration=0;
                y->node_type=$1->type;
                if(IDlist.check_redefine(y)==true){
                    cerr<<"Redefine variable "<<y->name<<" at line "<<$2->lineno<<endl;
                    exit(1);
                }                    
            }
            curr=curr->sibling;
        }
        $$ = node;   
    }
;

assign_stmt 
: unary_left_expr LOP_ASSIGN assign_stmt{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| unary_left_expr PLUS_ASSIGN assign_stmt{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| unary_left_expr MINUS_ASSIGN assign_stmt{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| unary_left_expr MULTI_ASSIGN assign_stmt{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| unary_left_expr DIVID_ASSIGN assign_stmt{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_ASSIGN;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| or_expr {$$=$1;}
;

while_stmt
:WHILE bool_stmt statement {
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype= STMT_WHILE;
        //将其他类型转换为bool类型
        if($2->type!=TYPE_BOOL){
            if($2->type==TYPE_INT){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->int_val;
            }
            else if($2->type==TYPE_CHAR){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->ch_val;
            }
            else{
                cerr<<"Wrong string type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
;

if_stmt
: IF bool_stmt statement %prec LOWER_THAN_ELSE{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_IF;
        //将其他类型转换为bool类型
        if($2->type!=TYPE_BOOL){
            if($2->type==TYPE_INT){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->int_val;
            }
            else if($2->type==TYPE_CHAR){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->ch_val;
            }
            else{
                cerr<<"Wrong string type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| IF bool_stmt statement ELSE statement{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_IF;
        //将其他类型转换为bool类型
        if($2->type!=TYPE_BOOL){
            if($2->type==TYPE_INT){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->int_val;
            }
            else if($2->type==TYPE_CHAR){
                $2->type=TYPE_BOOL;
                $2->b_val=$2->ch_val;
            }
            else{
                cerr<<"Wrong string type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        node->addChild($4);
        node->addChild($5);
        $$=node;
    }
;

for_stmt
: FOR LPAREN decl_stmt SEMICOLON or_expr SEMICOLON assign_stmt RPAREN statement {
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($3);
        node->addChild($5);
        node->addChild($7);
        node->addChild($9);
        TreeNode* x=$3->child;
        vector<string> symbol;
        while(x!=nullptr){
            if(x->nodeType==NODE_VAR){
                Symbol* y=IDlist.find_by_node(x);
                if(y==nullptr){
                    cerr<<"Var not defined at line "<<$3->lineno<<endl;
                    exit(1);
                }
                else{
                    y->depth++;
                    symbol.push_back(y->name);
                }
            }
            x=x->sibling;
        }

        x=$5;
        queue<TreeNode*>q;
        q.push(x);
        while(!q.empty()){
            TreeNode *next=q.front()->child;
            q.pop();
            while(next!=nullptr){
                if(next->nodeType==NODE_VAR){
                    Symbol* y=IDlist.find_by_node(next);
                    vector<string>::iterator result=find(symbol.begin(),symbol.end(),y->name);
                    if(result!=symbol.end()){
                        y->depth++;
                    }
                }
                q.push(next);
                next=next->sibling;
            }
        }

        x=$7;
        q.push(x);
        while(!q.empty()){
            TreeNode *next=q.front()->child;
            q.pop();
            while(next!=nullptr){
                if(next->nodeType==NODE_VAR){
                    Symbol* y=IDlist.find_by_node(next);
                    vector<string>::iterator result=find(symbol.begin(),symbol.end(),y->name);
                    if(result!=symbol.end()){
                        y->depth++;
                    }
                }
                q.push(next);
                next=next->sibling;
            }
        }
        $$=node;
    }
| FOR LPAREN assign_stmt SEMICOLON or_expr SEMICOLON assign_stmt RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($3);
        node->addChild($5);
        node->addChild($7);
        node->addChild($9);
        $$=node;
    }
| FOR LPAREN SEMICOLON SEMICOLON RPAREN statement RPAREN{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($6);
        $$=node;

    }
| FOR LPAREN SEMICOLON or_expr SEMICOLON assign_stmt RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($4);
        node->addChild($6);
        node->addChild($8);
        $$=node;
    }
| FOR LPAREN assign_stmt SEMICOLON SEMICOLON assign_stmt RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($3);
        node->addChild($6);
        node->addChild($8);
        $$=node;
    }
| FOR LPAREN assign_stmt SEMICOLON or_expr SEMICOLON RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($3);
        node->addChild($5);
        node->addChild($8);
        $$=node;
    }
| FOR LPAREN assign_stmt SEMICOLON SEMICOLON RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($3);
        node->addChild($7);
        $$=node;
    }
| FOR LPAREN SEMICOLON or_expr SEMICOLON RPAREN statement { 
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($4);
        node->addChild($7);
        $$=node;
    }
| FOR LPAREN SEMICOLON SEMICOLON assign_stmt RPAREN statement {
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild($1);
        node->addChild($5);
        node->addChild($7);
        $$=node;
    }
;

scanf_stmt
: SCANF LPAREN STRING COMMA scanf_list RPAREN{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        TreeNode* curr=$5;
        while(curr!=nullptr){
            //在符号表中找到对应节点,找不到则证明节点为未定义节点
            if(curr->nodeType==NODE_VAR){
                Symbol* x=IDlist.find_by_node(curr);
                Symbol* y=IDlist.find_decl(x->name,x->depth,x->num_of_depth,x->idcount);
                if(y==nullptr){
                    cerr<<"Undefined var "<<x->name<<" at line "<<$5->lineno<<endl;
                    exit(1);
                }
                x->decl_node=y;
                x->node_type=y->node_type; 
                curr->type=y->node_type;             
            }
            curr = curr->sibling;
        }
        node->stype=STMT_SCANF;
        node->addChild($1);
        node->addChild($3);
        node->addChild($5);
        $$ = node;
    }
;

printf_stmt
: PRINTF LPAREN STRING COMMA printf_list RPAREN{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        TreeNode* curr=$5;
        while(curr!=nullptr){
            //在符号表中找到对应节点,找不到则证明节点为未定义节点
            if(curr->nodeType==NODE_VAR){
                Symbol* x=IDlist.find_by_node(curr);
                Symbol* y=IDlist.find_decl(x->name,x->depth,x->num_of_depth,x->idcount);
                if(y==nullptr){
                    cerr<<"Undefined variable "<<x->name<<" at line "<<$5->lineno<<endl;
                    exit(1);
                }
                x->decl_node=y; 
                x->node_type=y->node_type;  
                curr->type=y->node_type;              
            }
            curr=curr->sibling;
        }
        node->stype=STMT_PRINTF;       
        node->addChild($1);
        node->addChild($3);
        node->addChild($5);
        $$=node;
    }
| PRINTF LPAREN STRING RPAREN{
        TreeNode* node=new TreeNode($1->lineno,NODE_STMT);
        node->stype=STMT_PRINTF;
        node->addChild($1);
        node->addChild($3);
        $$=node;
    }
;

scanf_list
: REFERENCE IDENTIFIER{$$=$2;}
| scanf_list COMMA REFERENCE IDENTIFIER{
        $1->addSibling($4);
        $$=$1;
    }
;

printf_list
: or_expr{$$=$1;}
| printf_list COMMA or_expr{
        $$=$1;
        $1->addSibling($3);
    }
;

SymbolTable
: SymbolTable COMMA IDENTIFIER{
        $$=$1;
        $$->addSibling($3);
    }
| IDENTIFIER {$$=$1;}   
;

bool_stmt
: LPAREN or_expr RPAREN{
        $$=$2;
    }
;
or_expr
: or_expr OR and_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_OR;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_BOOL){
            if($1->type==TYPE_INT){
                $1->type=TYPE_BOOL;
                $1->b_val=$1->int_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_BOOL;
                $1->b_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_BOOL){
            if($3->type==TYPE_INT){
                $3->type=TYPE_BOOL;
                $3->b_val=$3->int_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_BOOL;
                $3->b_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->b_val)||($3->b_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }   
| and_expr{
        $$=$1;
    }
;

and_expr
: and_expr AND EQ_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_AND;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_BOOL){
            if($1->type==TYPE_INT){
                $1->type=TYPE_BOOL;
                $1->b_val=$1->int_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_BOOL;
                $1->b_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_BOOL){
            if($3->type==TYPE_INT){
                $3->type=TYPE_BOOL;
                $3->b_val=$3->int_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_BOOL;
                $3->b_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->b_val)&&($3->b_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| EQ_expr{
        $$=$1;
    }
;

EQ_expr
: EQ_expr EQ relation_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_EQ;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)==($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| EQ_expr NEQ relation_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_EQ;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)!=($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| relation_expr {
        $$=$1;
    }
;

relation_expr
: relation_expr BT add_sub_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_RELATION;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)>($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| relation_expr ST add_sub_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_RELATION;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)<($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| relation_expr BEQ add_sub_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_RELATION;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)>=($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| relation_expr SEQ add_sub_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_RELATION;
        node->type=TYPE_BOOL;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL){
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR){
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->b_val=($1->int_val)<=($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| add_sub_expr{
        $$=$1;
    }
;

add_sub_expr
: add_sub_expr ADD mul_div_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL) 
            {
                $3->type=TYPE_INT;
                $3->int_val=$1->b_val;
            }
            else if($3->type==TYPE_CHAR) 
            {
                $3->type=TYPE_INT;
                $3->int_val=$1->ch_val;
            }
            else  
            {
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->type=TYPE_INT;
        node->etype=EXPR_ADD_SUB;
        node->int_val=$1->int_val+$3->int_val;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| add_sub_expr SUB mul_div_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else 
            {
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL)
            {
                $3->type=TYPE_INT;
                $3->int_val=$1->b_val;
            }
            else if($3->type==TYPE_CHAR)
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->type=TYPE_INT;
        node->etype=EXPR_ADD_SUB;
        node->int_val=$1->int_val-$3->int_val;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| mul_div_expr{
        $$=$1;
    }
;


mul_div_expr
: mul_div_expr MUL unary_left_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL) 
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else 
            {
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL)
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR)
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->type=TYPE_INT;
        node->etype=EXPR_MUL_DIV;
        node->int_val=($1->int_val)*($3->int_val);
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| mul_div_expr DIV unary_left_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else 
            {
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL)
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR) 
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->type=TYPE_INT;
        node->etype=EXPR_MUL_DIV;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| mul_div_expr MOD unary_left_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL)
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR) 
            {
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else 
            {
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        if($3->type!=TYPE_INT){
            if($3->type==TYPE_BOOL)
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->b_val;
            }
            else if($3->type==TYPE_CHAR) 
            {
                $3->type=TYPE_INT;
                $3->int_val=$3->ch_val;
            }
            else 
            {
                cerr<<"Wrong type at line "<<$3->lineno<<endl;
                exit(1);
            }
        }
        node->type=TYPE_INT;
        node->etype=EXPR_MUL_DIV;
        node->addChild($1);
        node->addChild($2);
        node->addChild($3);
        $$=node;
    }
| unary_left_expr{
        $$=$1;
    }
; 

unary_left_expr
: SUB unary_left_expr %prec UMINUS{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_UNARY_LEFT;
        //类型检查
        if($2->type!=TYPE_INT){
            if($2->type==TYPE_BOOL)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->b_val;
            }
            else if($2->type==TYPE_CHAR)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->type=$2->type;
        node->int_val=-($2->int_val);
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| ADD unary_left_expr %prec UADD{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_UNARY_LEFT;
        //类型检查
        if($2->type!=TYPE_INT){
            if($2->type==TYPE_BOOL) 
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->b_val;
            }
            else if($2->type==TYPE_CHAR)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->type=$2->type;
        node->int_val=$2->int_val;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| NOT unary_left_expr{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_UNARY_LEFT;
        //类型检查
        if($2->type!=TYPE_BOOL){
            if($2->type==TYPE_INT)
            {
                $2->type=TYPE_BOOL;
                $2->b_val=$2->int_val;
            }
            else if($2->type==TYPE_CHAR)
            {
                $2->type=TYPE_INT;
                $2->b_val=$2->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->type=$2->type;
        node->b_val=!($2->b_val);
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| SELFP unary_left_expr %prec SELFP_R{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_UNARY_LEFT;
        //类型检查
        if($2->type!=TYPE_INT){
            if($2->type==TYPE_BOOL)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->b_val;
            }
            else if($2->type==TYPE_CHAR)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->type=$2->type;
        node->int_val=$2->int_val+1;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| SELFM unary_left_expr %prec SELFM_R{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_UNARY_LEFT;
        //类型检查
        if($2->type!=TYPE_INT){
            if($2->type==TYPE_BOOL)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->b_val;
            }
            else if($2->type==TYPE_CHAR)
            {
                $2->type=TYPE_INT;
                $2->int_val=$2->ch_val;
            }
            else
            {
                cerr<<"Wrong type at line "<<$2->lineno<<endl;
                exit(1);
            }
        }
        node->type=$2->type;
        node->int_val=$2->int_val-1;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| unary_right_expr{
        $$=$1;
    }
;

unary_right_expr
: unary_right_expr SELFP{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_POSTFIX;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        node->type=$1->type;
        node->int_val=$1->int_val+1;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| unary_right_expr SELFM{
        TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
        node->etype=EXPR_POSTFIX;
        //类型检查
        if($1->type!=TYPE_INT){
            if($1->type==TYPE_BOOL){
                $1->type=TYPE_INT;
                $1->int_val=$1->b_val;
            }
            else if($1->type==TYPE_CHAR){
                $1->type=TYPE_INT;
                $1->int_val=$1->ch_val;
            }
            else{
                cerr<<"Wrong type at line "<<$1->lineno<<endl;
                exit(1);
            }
        }
        node->type=$1->type;
        node->int_val=$1->int_val-1;
        node->addChild($1);
        node->addChild($2);
        $$=node;
    }
| expr{
        $$=$1;
    }
;

expr
: LPAREN or_expr RPAREN{
        $$ = $2;
    }
| IDENTIFIER {
        //定义检查
        Symbol *x=IDlist.find_by_node($1);
        Symbol *y=IDlist.find_decl(x->name,x->depth,x->num_of_depth,x->idcount);
        if(y==nullptr){
            cerr<<"Undefined variable "<<x->name<<" at line "<<$1->lineno<<endl;
            exit(1);
        }
        else{
            x->decl_node=y;
            x->node_type=y->node_type;
            $1->type=y->node_type;
        }
        $$ = $1;
    }
| INTEGER {
        $1->type=TYPE_INT;
        $$ = $1;
    }
| CHAR {
        $1->type=TYPE_CHAR;
        $$ = $1;
    }
| STRING {
        $1->type=TYPE_STRING;
        $$ = $1;
    }
| BOOL {
        $1->type=TYPE_BOOL;
        $$ = $1;
    }
;

T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_STRING;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}