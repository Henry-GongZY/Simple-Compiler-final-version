#include "pch.h"
#include "tree.h"
#include "type.h"
extern int last_num_of_layer[50][50];

class Symbol{
public:
    string name; //变量名
    int depth;   //作用域层数
    int num_of_depth; //第几个同层次作用域
    Symbol* next; //符号表内的下一个节点
    TreeNode *node; //该符号表节点对应的树中的节点
    int declaration; //该变量是声明还是引用，0为声明，1为引用
    int idcount;        //结点序号
    Symbol* decl_node;   //引用类型节点对应的声明节点
    Type* node_type; //节点类型

    Symbol(){
        name=nullptr;
        depth=0;
        num_of_depth=0;
        node=nullptr;
        next=nullptr;
        declaration=1;
    }
    Symbol(string var,int layer,int num_of_layer,TreeNode *new_node,int x ,int next_num_of_layer){
        name=var;
        num_of_depth=num_of_layer;
        depth=layer;
        node=new_node;
        next=nullptr;
        declaration=x;
    }
};

class SymbolTable{
public:
    Symbol* head;
    int elementnum;

    SymbolTable(){
        head=nullptr;
        elementnum=0;
    }

    //生成新节点并加入链表
    void push_back(string var,int layer,int num_of_layer,TreeNode* node,int x,int next_num_of_layer){
        Symbol *new_node=new Symbol(var,layer,num_of_layer,node,x,next_num_of_layer);
        new_node->idcount=++elementnum;
        if(head==nullptr){
            head=new_node;
        }
        else{
            Symbol *x=head;
            while(x->next!=nullptr){
                x=x->next;
            }
            x->next=new_node;
        }
    }

    //通过节点使用找到节点定义
    Symbol* find_decl(string var_name,int layer,int num_of_layer,int idcount){
        Symbol*x=head;
        while(x!=nullptr){
            if(x->name==var_name&&x->idcount<idcount&&x->declaration==0){
                return x;
            }
            x=x->next;
        }
        return nullptr;
    }

    //使用TreeNode寻找对应的符号表结点
    Symbol* find_by_node(TreeNode *n){      
        Symbol* x=head;
        while(x!=nullptr){
            if(x->node==n){
                return x;
            }
            x=x->next;
        }
        return nullptr;
    }

    //检查重复定义
    bool check_redefine(Symbol* y){
        Symbol* x=head;
        while(x->idcount<y->idcount){
            if(x->name==y->name&&x->depth==y->depth&&x->num_of_depth==y->num_of_depth&&x->declaration==0&&x->node_type==y->node_type){
                return true;
            }
            x=x->next;
        }
        return false;
    }

};