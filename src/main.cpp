#include "common.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include "symboltable.h"

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();

extern Type* TYPE_INT = new Type(VALUE_INT);
extern Type* TYPE_CHAR = new Type(VALUE_CHAR);
extern Type* TYPE_BOOL = new Type(VALUE_BOOL);
extern Type* TYPE_STRING = new Type(VALUE_STRING);
extern Type* TYPE_VOID = new Type(VALUE_VOID);

int layer=0;
int num_of_layer[50];
int last_num_of_layer[50][50];
idlist IDlist;

using namespace std;
int main(int argc, char *argv[])
{
    
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    fill(num_of_layer,num_of_layer+50,0); //初始化深度个数
    fill(last_num_of_layer[0],last_num_of_layer[0]+50*50,-1); //初始化上一层深度个数
    yyparse(); 
    if(root != NULL) {
        root->genNodeId();
        root->gen_label();
        //root->printAST();
        //IDlist.printInfo();
        root->gen_code();
    }
    return 0;
}