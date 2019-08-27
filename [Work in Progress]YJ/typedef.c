#include<stdio.h>
#ifndef TYPEDEF
#define TYPEDEF


typedef enum
{
    SUCCESS,ERROR,VARIABLE_NOT_DEFINED,OUT_OF_BOUND,FILE_ERROR
}resultStatus;



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
    float data;
    resultStatus status;
    char error_info[100];
}Result;
typedef struct var
{
    float val;
    char name[30];
    struct var *next;
}Var;

#endif
