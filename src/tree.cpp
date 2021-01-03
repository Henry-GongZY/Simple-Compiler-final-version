#ifndef TREE_CPP
#define TREE_CPP
#include "tree.h"
#include "symboltable.h"

extern idlist IDlist;
extern Type* TYPE_INT;
extern Type* TYPE_CHAR;
extern Type* TYPE_BOOL;
extern Type* TYPE_STRING;
extern Type* TYPE_VOID;

void TreeNode::addChild(TreeNode* child) {
    if(this->child==nullptr){
         this->child=child;
    }
    else{
        this->child->addSibling(child);
    }
}

void TreeNode::addSibling(TreeNode* sibling){
    if (this->sibling == nullptr)  //没有兄弟的直接添加为兄弟
        this->sibling = sibling;
    else {                         //有兄弟则添加为最后一个兄弟的兄弟
        TreeNode *curr = this->sibling;   
        while (curr->sibling != nullptr)
            curr = curr->sibling;
        curr->sibling = sibling;
    }
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno=lineno;
    this->nodeType=type;
}

void TreeNode::genNodeId() {
    this->nodeID=0;
    int count=1;
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode *next=q.front()->child;//下一层
        q.pop();
        while(next!=nullptr){
            next->nodeID=count++;//同层所有结点赋值
            q.push(next);
            next=next->sibling;
        }
    }
}

void TreeNode::printNodeInfo()
{
    cout << "line:";
    cout.setf(ios::left);
    cout.width(4);
    cout<< this->lineno << " Node_id:";
    cout.width(4);
    cout<< this->nodeID;
    this->printSpecialInfo();
    cout << " child: ";
}

void TreeNode::printChildrenId()
{
    TreeNode *next = this->child;
    if (next != nullptr){
        cout << next->nodeID << " ";
        TreeNode *curr = next->sibling;
        while (curr != nullptr) {
            cout << curr->nodeID<<" ";
            curr = curr->sibling;
        }
    } else {
        cout<<"NULL";
    } 
    cout<<endl;
}

void TreeNode::printAST() {
    this->printNodeInfo();
    this->printChildrenId();
    if(this->label.begin_label!=""){
        cout<<"BEGIN:"<<this->label.begin_label<<"  ";
    }
    if(this->label.next_label!=""){
        cout<<"NEXT:"<<this->label.next_label<<"  ";
    }
    if(this->label.true_label!=""){
        cout<<"TRUE:"<<this->label.true_label<<"  ";
    }
    if(this->label.false_label!=""){
        cout<<"FALSE:"<<this->label.false_label<<"  ";
    }
    cout<<endl;
    TreeNode *child=this->child;
    if(child!=nullptr){
        child->printAST();
        TreeNode *curr=child->sibling;
        while(curr!=nullptr){
            curr->printAST();
            curr=curr->sibling;
        }
    }
    
}


void TreeNode::printSpecialInfo() {
    switch (this->nodeType)
    {
    case NODE_CONST:
        cout << " CONST:";
        cout.width(23);
        if (this->type->type == VALUE_STRING)
            cout << this->str_val;
        else if (this->type->type == VALUE_INT)
            cout << this->int_val;
        else if (this->type->type == VALUE_CHAR)
            cout << this->ch_val;
        else if (this->type->type == VALUE_BOOL)
        {
            if (this->b_val == 1)
                cout << "true";
            else
                cout << "false";
        }
        break;
    case NODE_VAR:
        cout << " VAR:";
        cout.width(25);
        cout << this->var_name;
        break;
    case NODE_EXPR:
        cout << " EXPR:";
        cout.width(24);
        cout<<this->exprType2String();
        break;
    case NODE_STMT:
        cout << " STMT:";
        cout.width(24);
        cout<<this->sType2String();
        break;
    case NODE_TYPE:
        cout << " TYPE:";
        cout.width(24);
        cout << this->type->getTypeInfo();
        break;
    case NODE_PROG:
        cout.width(30);
        cout << " PROGRAM";
        break;
    case NODE_OP:
        cout << " OP:";
        cout.width(26);
        cout << this->op;
        break;
    case NODE_KEYWORD:
        cout<<" KEYWORD:";
        cout.width(21);
        cout<<this->var_name;
        break;
    default:
        break;
    }
}

string TreeNode::opType2String(){
    switch (this->optype)
    {
    case OP_EQ:
        return "=";
    case OP_ST:
        return "<";
    case OP_BT:
        return ">";
    case OP_SEQ:
        return "<=";
    case OP_BEQ:
        return ">=";
    case OP_ASSIGN:
        return "=";
    case OP_PLUS_ASSIGN:
        return "+=";
    case OP_MINUS_ASSIGN:
        return "-=";
    case OP_MULTITI_ASSIGN:
        return "*=";
    case OP_DIVIDID_ASSIGN:
        return "/=";
    default:
        break;
    }
}

string TreeNode::sType2String(){
    switch(this->stype){
    case STMT_SKIP:
        return "SKIP";
    case STMT_DECL:
        return "DECL";
    case STMT_ASSIGN:
        return "ASSIGN";
    case STMT_WHILE:
        return "WHILE";
    case STMT_IF:
        return "IF";
    case STMT_FOR:
        return "FOR";
    case STMT_SCANF:
        return "SCANF";
    case STMT_PRINTF:
        return "PRINTF";
    case STMT_RET:
        return "RETURN";
    case STMT_BLOCK:
        return "BLOCK";
    default:
        break;
    }
}

string TreeNode::exprType2String(){
    switch (this->etype){
    case EXPR_OR:
        return "OR";
    case EXPR_AND:
        return "AND";
    case EXPR_EQ:
        return "EQ";
    case EXPR_RELATION:
        return "RELATION";
    case EXPR_ADD_SUB:
        return "ADD";
    case EXPR_MUL_DIV:
        return "MUL";
    case EXPR_UNARY_LEFT:
        return "UNARY";
    case EXPR_POSTFIX:
        return "POSTFIX";
    default:
        break;
    }
}

void TreeNode::gen_code(){
    //声明常量
    cout<<".section .rodata"<<endl;
    this->gen_const();
    //声明全局变量
    cout<<endl<<"\t.bss"<<endl;
    this->gen_var();
    //声明表达式临时变量
    this->gen_temp_var();
    //main函数定义
    cout<<endl<<"\t.text"<<endl<<"\t.globl main"<<endl<<"\t.type main, @function"<<endl<<"main:"<<endl;
    //声明函数内容
    this->gen_content();
}


void TreeNode::gen_const(){
    int count=0;
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode *next=q.front();//根节点放入队列
        q.pop();
        while(next!=nullptr){
            //字符串常量需要在rodata段开空间存储
            if(next->nodeType==NODE_CONST&&next->type->type==VALUE_STRING){
                cout<<"STRING"<<count<<":"<<endl;
                cout<<"\t.string "<<next->str_val<<endl;
                next->count_string=count;
                count++;
            }
            q.push(next->child);
            next=next->sibling;
        }
    }
}

void TreeNode::gen_var(){
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode *next=q.front();//根节点放入队列
        q.pop();
        while(next!=nullptr){
            //如果该节点是变量类型的节点
            if(next->nodeType==NODE_VAR){
                idnode* x=IDlist.find_by_node(next);
                //该变量是声明节点且目前没有开空间，则为其开辟全局变量空间
                if(x->decl_or_refe==0){
                    cout<<"_"<<next->var_name<<":"<<endl<<"\t.zero 4"<<endl<<"\t.align 4"<<endl;
                }
            }
            q.push(next->child);
            next=next->sibling;
        }
    }
    return;
}

void TreeNode::gen_temp_var(){
    int count=0;
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode *next=q.front();//根节点放入队列
        q.pop();
        while(next!=nullptr){
            //表达式中如a+b、a*b之类需要生成临时变量
            if(next->nodeType==NODE_EXPR){
                //前缀++、--，后缀++、--都不需要另开空间，但前缀+、-和!都需要开空间
                if(next->etype!=EXPR_POSTFIX&&(next->etype!=EXPR_UNARY_LEFT||(next->child->optype!=OP_SELFP&&next->child->optype!=OP_SELFM))){
                    next->var_name="temp"+to_string(count);//给表达式制定一个变量名存起来                    
                    cout<<"_temp"<<count<<":"<<endl;
                    cout<<"\t.zero 4"<<endl<<"\t.align 4"<<endl;
                    count++;
                }
            }
            q.push(next->child);
            next=next->sibling;
        }
    }
    return;
}

void TreeNode::gen_label(){
    stack<TreeNode*> s;
    s.push(this);
    while(!s.empty()){
        TreeNode *next=s.top();//根节点放入栈中
        s.pop();
        while(next!=nullptr){
            if(next->nodeType==NODE_STMT){
                if (next->stype==STMT_WHILE){
                    //开始标签
                    if(next->label.begin_label==""){
                        next->label.begin_label=new_label();                        
                    }
                    //下一句标签
                    if(next->sibling!=nullptr){
                        if(next->sibling->label.begin_label!=""){
                            next->label.next_label=next->sibling->label.begin_label;
                        }
                        else{
                            next->label.next_label=next->sibling->label.begin_label=new_label();
                        }
                    } 
                    else if(next->label.next_label==""){
                        next->label.next_label=new_label();
                        next->Sibling=0;
                    }
                    else{
                        next->Sibling=0;
                    }
                    TreeNode* x=next->child->sibling; //判断语句
                    TreeNode* y=x->sibling; //循环体语句块
                    x->label.false_label=next->label.next_label;
                    x->label.true_label=y->label.begin_label=new_label();
                    y->label.next_label=next->label.begin_label;             
                }
                else if(next->stype==STMT_IF){
                    TreeNode *x=next->child->sibling;//判断语句
                    TreeNode *y=x->sibling; //if执行的语句块
                    //给next的下一条语句的begin_label置为next的next_label
                    if(next->sibling!=nullptr){
                        if(next->sibling->label.begin_label!=""){
                            next->label.next_label=next->sibling->label.begin_label;
                        }
                        else{
                            next->label.next_label=next->sibling->label.begin_label=new_label();
                        }
                    }
                    else if(next->label.next_label==""){
                        next->label.next_label=new_label();
                        next->Sibling=0;
                    }
                    else{
                        next->Sibling=0;
                    }
                    //说明是if单语句
                    if(y->sibling==nullptr){
                        x->label.true_label=y->label.begin_label=new_label();  
                        x->label.false_label=next->label.next_label;                                                                 
                    }
                    //说明是if_else语句
                    else{
                        TreeNode* z=y->sibling->sibling;//else执行的语句块
                        y->label.next_label=next->label.next_label;
                        x->label.true_label=y->label.begin_label=new_label();
                        x->label.false_label=z->label.begin_label=new_label();
                        if(z!=nullptr&&z->stype==STMT_IF)//如果还是if语句
                        {
                            z->label.next_label=next->label.next_label;
                        }
                    }
                }
                else if(next->stype==STMT_FOR){
                    //开始标签
                    if(next->label.begin_label==""){
                        next->label.begin_label=new_label();
                    }
                    //下一句标签
                    if(next->sibling!=nullptr){
                        if(next->sibling->label.begin_label!=""){
                            next->label.next_label=next->sibling->label.begin_label;
                        }
                        else{
                            next->label.next_label=next->sibling->label.begin_label=new_label();
                        }
                    }
                    else if(next->label.next_label==""){
                        next->label.next_label=new_label();
                        next->Sibling=0;
                    }  
                    else{
                        next->Sibling=0;
                    }
                    TreeNode* x=next->child->sibling->sibling;//判断语句
                    TreeNode* y=x->sibling->sibling;//循环体的语句块
                    x->label.true_label=y->label.begin_label=new_label();
                    x->label.false_label=next->label.next_label;
                    y->label.next_label=next->label.begin_label;
                }                                    
            }
            s.push(next->sibling);
            next=next->child;
        }
    }
}

string TreeNode::new_label(){
    static int count=0;
    string tmp="L"+to_string(count);
    count++;
    return tmp;
}

void TreeNode::gen_content(){
    if(this->nodeType==NODE_STMT){
        if(this->stype==STMT_WHILE){
            if(this->label.begin_label!=""){
                //输出开始label对应的汇编节点
                cout<<this->label.begin_label<<":"<<endl;
            }

            //循环判断条件和循环体
            TreeNode* judge=this->child->sibling;
            TreeNode* body=judge->sibling;

            judge->gen_content();    //循环判断条件递归

            cout<<"\tmovl $1,%eax"<<endl;

            if(judge->nodeType==NODE_CONST) //条件是常量，直接与1（true）进行比较
            {
                cout<<"\tcmpl $"<<judge->b_val<<",%eax"<<endl;           
            } else {                        //条件是表达式，便取其对应的临时变量值进行比较
                cout<<"\tcmpl _"<<judge->var_name<<",%eax"<<endl;
            }
            //不等（为假）则跳出
            cout<<"\tjne "<<this->label.next_label<<endl;
            body->gen_content(); //循环体递归
            cout<<"\tjmp "<<this->label.begin_label<<endl; //继续循环

            //如果无后继节点，打出其next_label，有的话会在遍历到它时打出begin_label
            if(this->Sibling==0){
                cout<<this->label.next_label<<":"<<endl;
            }
        }
        else if(this->stype==STMT_IF){
            if(this->label.begin_label!=""){
                //输出开始label对应的汇编节点
                cout<<this->label.begin_label<<":"<<endl;
            }

            //if判断条件和执行体
            TreeNode* judge=this->child->sibling;
            TreeNode* body=judge->sibling;

            if(body->sibling==nullptr) //无else
            {
                judge->gen_content(); //if判断条件递归
                cout<<"\tmovl $1,%eax"<<endl;
                if(judge->nodeType==NODE_CONST) //常量
                {
                    cout<<"\tcmpl $"<<judge->b_val<<",%eax"<<endl;
                } else {//表达式
                    cout<<"\tcmpl _"<<judge->var_name<<",%eax"<<endl;
                }
                cout<<"\tjne "<<this->label.next_label<<endl;
                body->gen_content();
            }
            else //if_else语句
            {
                TreeNode* else_body=body->sibling->sibling;
                judge->gen_content(); //if判断条件递归
                cout<<"\tmovl $1,%eax"<<endl;
                if(judge->nodeType==NODE_CONST) //常量
                {
                    cout<<"\tcmpl $"<<judge->b_val<<",%eax"<<endl;
                } else {//表达式
                    cout<<"\tcmpl _"<<judge->var_name<<",%eax"<<endl;
                }
                cout<<"\tjne "<<judge->label.false_label<<endl;

                body->gen_content();

                cout<<"\tjmp "<<this->label.next_label<<endl;
                
                else_body->gen_content();
            }
            if(this->Sibling==0){
                cout<<this->label.next_label<<":"<<endl;
            }
        }
        else if(this->stype==STMT_FOR){
            TreeNode* decl=this->child->sibling;//声明语句
            TreeNode* judge=decl->sibling;      //判断语句
            TreeNode* assign=judge->sibling;    //赋值语句
            TreeNode* body=assign->sibling;     //循环体

            decl->gen_content();

            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }

            judge->gen_content();

            //与while如出一辙
            cout<<"\tmovl $1,%eax"<<endl;
            if(judge->nodeType==NODE_CONST){
                cout<<"\tcmpl $"<<judge->b_val<<",%eax"<<endl;
            }
            else{
                cout<<"\tcmpl _"<<judge->var_name<<",%eax"<<endl;
            }
            cout<<"\tjne "<<this->label.next_label<<endl;
            //每次赋值语句均在循环体后执行，因而将其放在循环体之后
            body->gen_content();
            assign->gen_content();
            //回跳，每次在开始进行比较
            cout<<"\tjmp "<<this->label.begin_label<<endl;
            if(this->Sibling==0){
                cout<<this->label.next_label<<":"<<endl;
            }
        }
        else if(this->stype==STMT_PRINTF){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            TreeNode* str=this->child->sibling;
            if(str->sibling==nullptr) //无参
            {
                cout<<"\tpushl $STRING"<<str->count_string<<endl;
                cout<<"\tcall printf"<<endl;
                cout<<"\taddl $4,%esp"<<endl;
            }
            else //有参
            {
                TreeNode* curr=str->sibling;
                int count=0;
                //统计变量数目
                while(curr!=nullptr){
                    curr->gen_content();
                    count++;
                    cout<<"\tpushl _"<<curr->var_name<<endl;
                    curr=curr->sibling;
                }
                cout<<"\tpushl $STRING"<<str->count_string<<endl;
                cout<<"\tcall printf"<<endl;
                cout<<"\taddl $"<<4*(count+1)<<",%esp"<<endl;
            }
        }
        else if(this->stype==STMT_SCANF){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            TreeNode* str=this->child->sibling;
            TreeNode* curr=str->sibling;
            int count=0;
            while(curr!=nullptr){
                curr->gen_content();
                count++;
                cout<<"\tleal _"<<curr->var_name<<",%eax"<<endl;
                cout<<"\tpushl %eax"<<endl;
                curr=curr->sibling;
            }
            cout<<"\tpushl $STRING"<<str->count_string<<endl;
            cout<<"\tcall scanf"<<endl;
            cout<<"\taddl $"<<4*(count+1)<<",%esp"<<endl;
        }
        else if(this->stype==STMT_DECL){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            TreeNode* id1=this->child->sibling;
            TreeNode* id2=id1->sibling;

            if(id2!=nullptr)
            {
                if(id2->nodeType==NODE_OP&&id2->optype==OP_ASSIGN)
                {
                    TreeNode* value=id2->sibling;
                    value->gen_content();
                    if(value->nodeType==NODE_CONST){
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl $"<<value->int_val<<",_"<<id1->var_name<<endl;
                        }
                        else if(value->type==TYPE_BOOL){
                            cout<<"\tmovl $"<<value->b_val<<",_"<<id1->var_name<<endl;
                        }
                        else if(value->type==TYPE_CHAR){ //ascll代码式赋值
                            cout<<"\tmovl $"<<int(value->ch_val)<<",_"<<id1->var_name<<endl;
                        }
                    }
                    else if(value->nodeType==NODE_EXPR){
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl _"<<value->var_name<<",%eax"<<endl;
                            cout<<"\tmovl %eax,_"<<id1->var_name<<endl;
                        }
                    }
                }
            }
            
        }
        else if(this->stype==STMT_ASSIGN){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            TreeNode* expr=this->child;
            while(expr!=nullptr){
                expr->gen_content();
                expr=expr->sibling;
            }
            expr=this->child; //赋值对象
            TreeNode* op = expr->sibling; //赋值号
            TreeNode* value = op->sibling; //值
            if(expr->nodeType==NODE_VAR){
                if(op->optype==OP_ASSIGN){
                    if(value->nodeType==NODE_CONST) //值是常量
                    {
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl $"<<value->int_val<<",_"<<expr->var_name<<endl;
                        }
                        else if(value->type==TYPE_BOOL){
                            cout<<"\tmovl $"<<value->b_val<<",_"<<expr->var_name<<endl;
                        }
                        else if(value->type==TYPE_CHAR){
                            cout<<"\tmovl $"<<int(value->ch_val)<<",_"<<expr->var_name<<endl;
                        }
                    }
                    else if(value->nodeType==NODE_STMT&&value->stype==STMT_ASSIGN) //连续赋值
                    {
                        TreeNode* curr=value->child;
                        //循环拿到最后一个
                        while(curr!=nullptr){
                            while(curr->sibling!=nullptr){
                                curr=curr->sibling;
                            }                               
                            if(curr->nodeType!=NODE_STMT||curr->stype!=STMT_ASSIGN){
                                break;
                            }                             
                            else{
                                curr=curr->child;
                            }                                
                        }
                        if(curr->nodeType==NODE_CONST) //常量赋值
                        {
                            if(curr->type==TYPE_INT){
                                cout<<"\tmovl $"<<curr->int_val<<",_"<<expr->var_name<<endl;
                            }
                            else if(curr->type==TYPE_BOOL){
                                cout<<"\tmovl $"<<curr->b_val<<",_"<<expr->var_name<<endl;
                            }
                            else if(curr->type==TYPE_CHAR){
                                cout<<"\tmovl $"<<int(curr->ch_val)<<",_"<<expr->var_name<<endl;
                            }
                        }
                        else //表达式或者变量赋值
                        {
                            cout<<"\tmovl _"<<curr->var_name<<",%eax"<<endl;
                        }
                        cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                    }
                    else //表达式或者变量赋值
                    {
                        cout<<"\tmovl _"<<value->var_name<<",%eax"<<endl;
                        cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                    }
                }
                else if(op->optype==OP_PLUS_ASSIGN){
                    if(value->nodeType==NODE_CONST) //常量
                    {
                        if(value->type==TYPE_INT){
                            cout<<"\taddl $"<<value->int_val<<",_"<<expr->var_name<<endl;
                        } //类型转换
                        else if(value->type==TYPE_CHAR){
                            cout<<"\taddl $"<<int(value->ch_val)<<",_"<<expr->var_name<<endl;
                        }
                    }
                    else //表达式或变量
                    {
                        cout<<"\tmovl _"<<value->var_name<<",%eax"<<endl;
                        cout<<"\taddl %eax,_"<<expr->var_name<<endl;
                    }
                }
                else if(op->optype==OP_MINUS_ASSIGN){
                    if(value->nodeType==NODE_CONST) //常量
                    {
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\tsubl $"<<value->int_val<<",%eax"<<endl;
                            cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                        } //类型转换
                        else if(value->type==TYPE_CHAR){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\tsubl $"<<int(value->ch_val)<<",%eax"<<endl;
                            cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                        }
                    }
                    else //表达式或变量
                    {
                        cout<<"\tmovl _"<<value->var_name<<",%eax"<<endl;
                        cout<<"\tsubl %eax,_"<<expr->var_name<<endl;
                    }
                }
                else if(op->optype==OP_MULTITI_ASSIGN){
                    if(value->nodeType==NODE_CONST) //常量
                    {
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\timull $"<<value->int_val<<",%eax"<<endl;
                            cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                        } //类型转换
                        else if(value->type==TYPE_CHAR){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\timull $"<<int(value->ch_val)<<",%eax"<<endl;
                            cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                        }
                    }
                    else //表达式或变量
                    {
                        cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                        cout<<"\timull _"<<value->var_name<<",%eax"<<endl;
                        cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                    }
                }
                else if(op->optype==OP_DIVIDID_ASSIGN){
                    /*
                        idiv指令：
                        eax/ebx 结果放在eax，余数放在edx
                        edx需要置0
                    */
                    if(value->nodeType==NODE_CONST) //常量
                    {
                        if(value->type==TYPE_INT){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\tmovl $0,%edx"<<endl;
                            cout<<"\tmovl $"<<value->int_val<<",%ebx"<<endl;
                            cout<<"\tidiv %ebx"<<endl;
                        } //类型转换
                        else if(value->type==TYPE_CHAR){
                            cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                            cout<<"\tmovl $0,%edx"<<endl;
                            cout<<"\tmovl $"<<int(value->ch_val)<<",%ebx"<<endl;
                            cout<<"\tidiv %ebx"<<endl;
                        }
                    }
                    else //表达式或变量
                    {
                        cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                        cout<<"\tmovl $0,%edx"<<endl;
                        cout<<"\tmovl _"<<value->var_name<<",%ebx"<<endl;
                        cout<<"\tidiv %ebx"<<endl;
                    }
                    cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
                }
            }
        }
        else if(this->stype==STMT_BLOCK){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            TreeNode* stmt=this->child;
            while(stmt!=nullptr){
                stmt->gen_content();
                stmt=stmt->sibling;
            }
        }
        else if(this->stype==STMT_RET){
            if(this->label.begin_label!=""){
                cout<<this->label.begin_label<<":"<<endl;
            }
            cout<<"\tmovl $0,%eax"<<endl;
            cout<<"\tret"<<endl;
        }
    }
    else if(this->nodeType==NODE_EXPR){
        TreeNode* expr=this->child;
        while(expr!=nullptr){
            expr->gen_content();
            expr=expr->sibling;
        }
        expr=this->child;
        if(this->etype==EXPR_OR){
            TreeNode* expr2=expr->sibling->sibling;
            if(expr->nodeType==NODE_CONST){
                cout<<"\tmovl $"<<expr->b_val<<",%eax"<<endl;
            }
            else{
                cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
            }
            if(expr2->nodeType==NODE_CONST){
                cout<<"\tor $"<<expr2->b_val<<",%eax"<<endl;
            }
            else{
                cout<<"\tor _"<<expr2->var_name<<",%eax"<<endl;
            }
            cout<<"\tmovl %eax,_"<<this->var_name<<endl;
        }
        else if(this->etype==EXPR_AND){
            TreeNode* expr2=expr->sibling->sibling; 
            if(expr->nodeType==NODE_CONST){
                cout<<"\tmovl $"<<expr->b_val<<",%eax"<<endl;
            }
            else{
                cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
            }
            if(expr2->nodeType==NODE_CONST){
                cout<<"\tand $"<<expr2->b_val<<",%eax"<<endl;
            }
            else{
                cout<<"\tand _"<<expr2->var_name<<",%eax"<<endl;
            }
            cout<<"\tmovl %eax,_"<<this->var_name<<endl;
        }
        else if(this->etype==EXPR_EQ){
            TreeNode* jdg_op=expr->sibling;
            TreeNode* expr2=jdg_op->sibling;
            if(jdg_op->optype==OP_EQ) {
                //==
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }

                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp = new_label();
                string tmp2 = new_label();
                cout<<"\tje "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;
            }
            else {
                //!= 基本相同，je和jne的区别
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp=new_label();
                string tmp2=new_label();
                cout<<"\tjne "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;
            }
        }
        else if(this->etype==EXPR_RELATION){
            TreeNode* jdg_op=expr->sibling;
            TreeNode* expr2=jdg_op->sibling;
            if(jdg_op->optype==OP_BT){
                // > 应对方式相近
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp=new_label();
                string tmp2=new_label();
                cout<<"\tjg "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;                
            }
            else if(jdg_op->optype==OP_ST){
                // <  复制粘贴
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp=new_label();
                string tmp2=new_label();
                cout<<"\tjl "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;
            }
            else if(jdg_op->optype==OP_BEQ){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp=new_label();
                string tmp2=new_label();
                cout<<"\tjge "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;
            }
            else if(jdg_op->optype==OP_SEQ){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tcmpl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tcmpl _"<<expr2->var_name<<",%eax"<<endl;
                }
                string tmp=new_label();
                string tmp2=new_label();
                cout<<"\tjle "<<tmp<<endl;
                cout<<"\tmovl $0,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<"\tjmp "<<tmp2<<endl;
                cout<<tmp<<":"<<endl;
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
                cout<<tmp2<<":"<<endl;
            }
        }
        else if(this->etype==EXPR_ADD_SUB){
            TreeNode* jdg_op=expr->sibling;
            TreeNode* expr2=jdg_op->sibling;
            if(jdg_op->optype==OP_PLUS){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\taddl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\taddl _"<<expr2->var_name<<",%eax"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else{
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tsubl $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tsubl _"<<expr2->var_name<<",%eax"<<endl;
                }               
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
        }
        else if(this->etype==EXPR_MUL_DIV){
            TreeNode* jdg_op=expr->sibling;
            TreeNode* expr2=jdg_op->sibling;
            if(jdg_op->optype==OP_MULTI){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\timull $"<<expr2->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\timull _"<<expr2->var_name<<",%eax"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_DIVID){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                    cout<<"\tmovl $0,%edx"<<endl;
                    cout<<"\tcltd"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                    cout<<"\tmovl $0,%edx"<<endl;
                    cout<<"\tcltd"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr2->int_val<<",%ebx"<<endl;
                    cout<<"\tidiv %ebx"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr2->var_name<<",%ebx"<<endl;
                    cout<<"\tidiv %ebx"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_MOD){
                if(expr->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr->int_val<<",%eax"<<endl;
                    cout<<"\tmovl $0,%edx"<<endl;
                    cout<<"\tcltd"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                    cout<<"\tmovl $0,%edx"<<endl;
                    cout<<"\tcltd"<<endl;
                }
                if(expr2->nodeType==NODE_CONST){
                    cout<<"\tmovl $"<<expr2->int_val<<",%ebx"<<endl;
                    cout<<"\tidiv %ebx"<<endl;
                }
                else{
                    cout<<"\tmovl _"<<expr2->var_name<<",%ebx"<<endl;
                    cout<<"\tidiv %ebx"<<endl;
                }
                cout<<"\tmovl %edx,_"<<this->var_name<<endl;
            }
        }
        else if(this->etype==EXPR_UNARY_LEFT){
            //与true异或实现取非
            TreeNode* jdg_op=expr;
            TreeNode* value=jdg_op->sibling;
            if(jdg_op->optype==OP_LG_NOT){
                cout<<"\tmovl $1,%eax"<<endl;
                if(value->nodeType==NODE_CONST){
                    cout<<"\txor $"<<value->b_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\txor _"<<value->var_name<<",%eax"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_PLUS){
                cout<<"\tmovl $0,%eax"<<endl;
                if(value->nodeType==NODE_CONST){
                    cout<<"\taddl $"<<value->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\taddl _"<<value->var_name<<",%eax"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_MINUS){
                cout<<"\tmovl $0,%eax"<<endl;
                if(value->nodeType==NODE_CONST){
                    cout<<"\tsubl $"<<value->int_val<<",%eax"<<endl;
                }
                else{
                    cout<<"\tsubl _"<<value->var_name<<",%eax"<<endl;
                }
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_SELFP){
                cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                cout<<"\taddl $1,%eax"<<endl;
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
            else if(jdg_op->optype==OP_SELFM){
                cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                cout<<"\tsubl $1,%eax"<<endl;                
                cout<<"\tmovl %eax,_"<<this->var_name<<endl;
            }
        }
        else if(this->etype==EXPR_POSTFIX){
            TreeNode* jdg_op=expr->sibling;
            if(jdg_op->optype==OP_SELFP){ //++
                cout<<"\tmovl $1,%eax"<<endl;
                cout<<"\taddl _"<<expr->var_name<<",%eax"<<endl;
                cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
            }
            else{ //--
                cout<<"\tmovl _"<<expr->var_name<<",%eax"<<endl;
                cout<<"\tsubl $1,%eax"<<endl;                
                cout<<"\tmovl %eax,_"<<expr->var_name<<endl;
            }
        }
    }
    else{
        TreeNode* next=this->child;
        while(next!=nullptr){
            next->gen_content();
            next=next->sibling;
        }
    }
}
#endif