//nodePf=NodePostfix;
#include<stdio.h>
typedef struct NodeOp
{
    float op;
    struct NodeOp *next;
}nodeOp;
typedef struct NodePostfix
{
    float var;
    struct NodePostfix *next;
}nodePf;
typedef struct result
{
    float dataR;
    char status[30];
    char error_info[30];
}Result;
typedef struct var
{
    float var_val;
    char var_name[30];
}Var;
typedef enum
{
    SUCCESS,VARIABLE_NOT_DEFINED,ERROR
}resultStatus;
void main()
{

}
