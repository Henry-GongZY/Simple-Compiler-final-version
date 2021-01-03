#include "pch.h"
#include "tree.h"
#include "type.h"
extern int last_num_of_layer[50][50];

class idnode{
public:
    string name; //变量名
    int depth;   //作用域层数
    int num_of_depth; //第几个同层次作用域
    idnode* next; //符号表内的下一个节点
    TreeNode *node; //该符号表节点对应的树中的节点
    int decl_or_refe; //该变量是声明还是引用，0为声明，1为引用
    int count;        //结点序号
    idnode* decl_node;   //引用类型节点对应的声明节点
    int next_num_of_depth; //若是for循环语句内声明的变量，需要将其depth+1，并且修改num_of_depth为next_num_of_depth
    Type* node_type; //节点类型

    idnode(){
        name=nullptr;
        depth=0;
        num_of_depth=0;
        node=nullptr;
        next=nullptr;
        decl_or_refe=1;
        next_num_of_depth=0;
    }
    idnode(string var,int layer,int num_of_layer,TreeNode *new_node,int x ,int next_num_of_layer){
        name=var;
        num_of_depth=num_of_layer;
        depth=layer;
        node=new_node;
        next=nullptr;
        decl_or_refe=x;
        next_num_of_depth=next_num_of_layer;
    }
};

class idlist{
public:
    idnode* head;
    int elementnum;

    idlist(){
        head=nullptr;
        elementnum=0;
    }

    //生成新节点并加入链表
    void push_back(string var,int layer,int num_of_layer,TreeNode* node,int x,int next_num_of_layer){
        idnode *new_node=new idnode(var,layer,num_of_layer,node,x,next_num_of_layer);
        new_node->count=++elementnum;
        if(head==nullptr){
            head=new_node;
        }
        else{
            idnode *x=head;
            while(x->next!=nullptr){
                x=x->next;
            }
            x->next=new_node;
        }
    }

    //通过节点使用找到节点定义
    idnode* find_decl(string var_name,int layer,int num_of_layer,int count){
        idnode*x=head;
        while(x!=nullptr){
            if(x->name==var_name&&x->count<count&&x->decl_or_refe==0){
                return x;
            }
            x=x->next;
        }
        return nullptr;
    }

    //使用TreeNode寻找对应的符号表结点
    idnode* find_by_node(TreeNode *n){      
        idnode* x=head;
        while(x!=nullptr){
            if(x->node==n){
                return x;
            }
            x=x->next;
        }
        return nullptr;
    }

    //检查重复定义
    bool check_redefine(idnode* y){
        idnode* x=head;
        while(x->count<y->count){
            if(x->name==y->name&&x->depth==y->depth&&x->num_of_depth==y->num_of_depth&&x->decl_or_refe==0&&x->node_type==y->node_type){
                return true;
            }
            x=x->next;
        }
        return false;
    }

};