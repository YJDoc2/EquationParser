#include "./typedef.c"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
Result setConst(char *name,float val){

    Result ret;
    Var *temp;

    temp = (Var *)malloc(sizeof(Var));
    strcpy(temp->name,name);
    temp->val = val;

    if(const_start == NULL){ //For First Constant
        const_start = temp;
        const_end = temp;

    }else{
        const_end->next = temp;
        const_end = temp;
    }
    const_end->next = NULL;
    ret.status = SUCCESS;
    ret.data = val;
    return ret;

}
Result getConst(char *name){

    Var *temp = const_start;
    Result ret;
    if(const_start == NULL){ //In case no constant has been defined yet
        ret.status = VARIABLE_NOT_DEFINED;
        sprintf(ret.error_info,"Variable %s not defined",name);

    }else{
        while(temp != NULL){
            if(strcmp(temp->name,name) == 0){
                break;
            }else{
                temp = temp->next;
            }
        }
        if(temp == NULL){//In case no constant with given name has been defined yet
            ret.status = VARIABLE_NOT_DEFINED;
            sprintf(ret.error_info,"Variable '%s' not defined",name);
        }else{
            ret.status = SUCCESS;
            ret.data = temp->val;
        }
    }
    return ret;
}
