#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum NodeType
{
    NODE_CONST, //常量
    NODE_VAR,   //变量
    NODE_EXPR,  //表达式
    NODE_TYPE,  //类型
    NODE_STMT,  //语句
    NODE_PROG,  //树根
    NODE_OP,    //运算符
    NODE_KEYWORD, //关键字
};

//不需要按位操作，补充了赋值节点
enum OperatorType
{
    OP_PLUS, 
    OP_MINUS, 
    OP_MULTI, 
    OP_DIVID, 
    OP_MOD,
    OP_SELFP, 
    OP_SELFM, 
    OP_LG_OR,  
    OP_LG_AND, 
    OP_LG_NOT, 
    OP_EQ,  
    OP_BT,  
    OP_ST,  
    OP_BEQ,
    OP_SEQ,
    OP_NEQ, 
    OP_ASSIGN, 
    OP_PLUS_ASSIGN, 
    OP_MINUS_ASSIGN, 
    OP_MULTITI_ASSIGN, 
    OP_DIVIDID_ASSIGN, 
};

enum StmtType {
    STMT_SKIP,  //跳过
    STMT_DECL,  //声明
    STMT_ASSIGN, 
    STMT_WHILE,
    STMT_IF,
    STMT_FOR,
    STMT_SCANF,
    STMT_PRINTF,
    STMT_RET,
    STMT_BLOCK,
};

enum ExprType{
    EXPR_OR, 
    EXPR_AND, 
    EXPR_EQ, 
    EXPR_RELATION, 
    EXPR_ADD_SUB, 
    EXPR_MUL_DIV, 
    EXPR_UNARY_LEFT, 
    EXPR_POSTFIX, 
};

struct Label{
    string begin_label;
    string next_label;
    string true_label;
    string false_label;
};

struct TreeNode {
public:
    int nodeID;  //用于作业的序号输出
    int lineno;  //记录行号
    int count_string=-1;  //常量字符串计数
    int count_temp=-1;  //表达式临时变量计数
    NodeType nodeType;  //节点类型

    TreeNode* child = nullptr;  //一个孩子，其他孩子表现为此孩子的兄弟
    TreeNode* sibling = nullptr;  //兄弟

    void addChild(TreeNode*);   //添加孩子
    void addSibling(TreeNode*);    //添加兄弟
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    void genNodeId();

public:
    OperatorType optype;  // 运算符操作类型
    Type* type;     //类型(整型、浮点型等)
    StmtType stype;
    ExprType etype;
    int int_val; //整型值
    char ch_val; //char类型数值
    bool b_val;  //bool类型数值
    string str_val; //string类型数值
    string var_name;//（临时）变量名或关键字
    string op; //存储操作符
    Label label;

public:
    TreeNode(int lineno, NodeType type); //构造函数
    string opType2String(); 
    string sType2String(); 
    string exprType2String(); 

public:
    void gen_code(); //生成汇编代码
    void gen_const(); //生成字符串常量
    void gen_var(); //生成全局变量
    void gen_temp_var(); //生成临时变量
    void gen_content(); //生成main函数体
    void gen_label(); //生成label标签
    string new_label(); //生成新标签
    bool Sibling = true;//是否有兄弟
};

#endif