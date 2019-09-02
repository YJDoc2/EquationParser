#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "./typedef.c"
#include "./variables.c"
#include "./constants.c"
#include "./queues.c"
#include "./constants.c"


#ifndef PREPARSER
#define PREPARSER

char infix[150];
int ASSIGN =0,DEFAULT = 0,EXISTING=0;
char v_name[30];

void removeSpaces(char *p){
    int n =0;
    if(p == NULL){
        return;
    }
    for(int i = 0;i<strlen(p);i++){
        if(p[i]!=' '){
            p[n++]=p[i];
        }
    }
    p[n]='\0';
}

Result checkAssign(char *in){

    Result ret;
    char temp[30];
    char *start = strchr(in,'=');
    if(start == NULL){
        ret.status = SUCCESS;
        return ret;
    }
    if(start != strrchr(in,'=')){
        ret.status = ERROR;
        strcpy(ret.error_info,"Cannot Perform Multiple Assignments");
        return ret;
    }
    strncpy(temp,in,start-in);
    if(strlen(temp)>=30){
        ret.status = ERROR;
        strcpy(ret.error_info,"Invalid Variable Assignment");
        return ret;
    }
    temp[strlen(temp) +1]='\0';
    ASSIGN =1;
    printf("T : %s \n",temp);
    if(*in == '$'){
        if(!isdigit(*(in+1)) || *(in+2) != '='){
            ret.status = ERROR;
            strcpy(ret.error_info,"Incorrect Default Variable Assignment");    
        }else{
            ret.status = SUCCESS;
            DEFAULT = 1;
        }
    }else{
        strcpy(v_name,temp);
        if(getVar(v_name).status == VARIABLE_NOT_DEFINED){
            strcpy(ret.error_info,"Creating new var");
        }else{
            EXISTING =1;
            strcpy(ret.error_info,"Overwriting Existing Var");
        }
        ret.status = SUCCESS;
    }
    return ret;
}



Result subVal(char *in,char *end){

    Result ret,val;
    char temp[30];
    if(end-in>=30){
        strncpy(temp,in,29);
        temp[30]='\0';
        ret.status = VARIABLE_NOT_DEFINED;
        sprintf(ret.error_info,"Invalid Variable or Const : %s In given expression",temp);
        return ret;
    }
    strncpy(temp,in,end-in+1);
    val = getConst(temp); 
    if(val.status == VARIABLE_NOT_DEFINED){
        val = getVar(temp);
    }
    if(val.status == VARIABLE_NOT_DEFINED){
        ret.status = VARIABLE_NOT_DEFINED;
        sprintf(ret.error_info,"Undefined Variable or Const : %s In given expression",temp);
        return ret;
    }else{
        enQVal(ret.data);
        ret.status = SUCCESS;
        return ret;
    }


}

//* Should Adjusting for -ve value at start of string done in defferent method?

Result preparse(char in[]){

    char pre;
    int i =0,j=0,t=0;
    Result ret,temp;
    removeSpaces(in);
    checkAssign(in);
    if(in[i]=='-'){
        infix[j++] = '(';
        infix[j++] = '0';
        infix[j++] = '-';
        infix[j++] = in[++i];
        infix[j++] = ')';
        i++;
    }
    while(in[i]!='\0'){
        if(isdigit(in[i])||in[i] =='.'){
            infix[j] = in[i];
            pre = in[i];
            i++;
            j++;
           
        }else if(in[i] == '*' && in[i+1] == '*'){
            infix[j] = 'E';
            j++;i+=2;
            pre = in[i];
        }else if(in[i] == '-' && (pre == '+'||pre == '-'||pre == '*'||pre == '/'||pre == '%'||pre == 'e'||pre == 'E')){
            infix[j++] = '(';
            infix[j++] = '0';
            infix[j++] = '-';
            infix[j++] = in[++i];
            infix[j++] = ')';
            i++;
        }else if(in[i] == '$'){
            
            if(isdigit(in[i+2])){
                ret.status = ERROR;
                sprintf(ret.error_info,"Invalid Default Variable %c%c%c at %d",in[i],in[i+1],in[i+2],i);
                return ret;
            }else{
                enQVal(getDefVar(in[i+1]-'0').data);
            }
        
        
        }else if(isalpha(in[i])){
            t =i;
            while(isalpha(in[i])){
                i++;
            }
            temp = subVal(in+i,in+t-1); 
            if(temp.status != SUCCESS){
                return temp; 
            }
            infix[j] = 'v';
            j++;
        }else{
            infix[j] = in[i];
            j++;i++;
        }
    }
    ret.status = SUCCESS;
    return ret;
}

#endif