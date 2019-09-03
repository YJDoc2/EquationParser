#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include "./typedef.c"
#include "./variables.c"
#include "./constants.c"
#include "./queues.c"
#include "./constants.c"


#ifndef PREPARSER
#define PREPARSER

char infix[150],buf[150];
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

Result parseVal(char inString[]){
    int dec =0;
    float val = 0.0;
    int i=0;
    Result ret;
    while(isdigit(inString[i])){
        val = val*10 + (float)(inString[i]-'0');
        i++;
    }
    if(inString[i] == '.'){
         i++;
    while(isdigit(inString[i])){
        val = val*10 + (float)(inString[i]-'0');
        i++;
        dec++;
    }}
    val = nextafterf(val/pow(10,dec),val+1);
    ret.data = val;
    ret.status = SUCCESS;
    return ret;
}

Result subVal(char *in){

    Result ret,val;
    char *token = strtok(in,"+-/%*E");
    while(token != NULL){
        //printf(" T -> %s\n",token);
        if(token == ""){
            continue;
        }
        if(strlen(token)>=30){
            ret.status = ERROR;
            sprintf(ret.error_info,"Invalid Token %s",token);
            return ret;
        }
        if(token[0] == '$'){
            if(strlen(token)>2){
                ret.status = ERROR;
                sprintf(ret.error_info,"Invalid Default Variable %s",token);
                return ret;
            }else{
                val = getDefVar(token[1]-'0');
                enQVal(val.data);
            }
        }else if(isalpha(token[0])){
            val = getConst(token);
            
            if(val.status != SUCCESS){
                val = getVar(token);
                if(val.status != SUCCESS){
                    return val;
                }
            }

            enQVal(val.data);
        }else if(isdigit(token[0])){
            val = parseVal(token);
            if (val.status == ERROR){
                ret.status = ERROR;
                sprintf(ret.error_info,"Invalid Token %s",token);
                return ret;
            }else{
                enQVal(val.data);
            }
            
        }else
        {
            ret.status = ERROR;
            sprintf(ret.error_info,"Invalid Token %s",token);
            return ret;
        }
        token = strtok(NULL,"+-/%*E");   
    }
    ret.status = SUCCESS;
    return ret;




}

//* Should Adjusting for -ve value at start of string done in defferent method ---- YES!!!
int isop(char a){
    
    return a=='+' || a=='-' || a=='*' || a=='/' ||a=='%' || a=='E';
}

char *adjustNegetive(char *in){

    int i=0,j=0;
    int oNeg =0,open = 0;
    char pre = in[0];
    for(i=0;i<strlen(in);){
        if(in[i] == '-' && isop(pre) &&(isalnum(in[i+1]) || in[i+1] == '$')){
            buf[j++] = '(';
            buf[j++] = '0';
            buf[j++] = '-';
            i++;
            while(i<strlen(in) && !isop(in[i])){
                pre = in[i];
                buf[j++] = in[i++];
            }
            buf[j++] = ')';
        }else if(in[i] =='-'&& isop(pre) &&(in[i+1] == '(' || in[i+1] == '[' || in[i+1] == '{' )){   
            oNeg =1;open =1;
            i++;
            buf[j++] = '(';
            buf[j++] = '0';
            buf[j++] = '-';
            buf[j++] = in[i++];
            while(i<strlen(in) && oNeg!=0){
                
                if(in[i] =='-' && isop(pre)&&(in[i+1] == '(' || in[i+1] == '[' || in[i+1] == '{' )){
                    oNeg++;i++;open++;
                    buf[j++] = '(';
                    buf[j++] = '0';
                    buf[j++] = '-';
                    buf[j++] = in[i++];
                }else if(in[i] == '(' || in[i] == '[' || in[i] == '{' ){
                    open++;
                    buf[j++] = in[i++];
                }else if(in[i] == ')' || in[i] == ']' || in[i] == '}'){
                    open--;
                    buf[j++] = in[i++];
                    if(open<oNeg){
                        buf[j++] = ')';
                        oNeg--;
                    }
                }else{
                    pre = in[i];
                    buf[j++] = in[i++];
                }
                while(oNeg>0 && open<=0){
                    buf[j++] = ')';
                    oNeg--;
                }
            }

        }else{
            pre = in[i];
            buf[j++] = in[i++];
        }
        
    }
    return buf;
}


Result preparse(char in[]){

    char pre,buf[150],temp[150];
    int i =0,j=0,t=0;
    Result ret,t1;
    strcpy(temp,adjustNegetive(in));
    while(i<strlen(temp)){

        if(isalnum(temp[i]) || temp[i] == '$'){
            infix[j] = 'v';
            i++;j++;
            while(isalnum(temp[i]) || temp[i] == '$' || temp[i] == '.'){
                i++;
            }
        }else{
            infix[j] = temp[i];
            j++;i++;
        }

    }
    for(i=0,j=0;i<strlen(temp);i++){
        if(temp[i] == '*' && temp[i+1] == '*' ){
            buf[j] = 'E';
            i++;j++;
        }else if(temp[i] == '(' || temp[i] == ')'||temp[i] == '[' || temp[i] == ']'||temp[i] == '{' || temp[i] == '}'){
            continue;
        }else{
            buf[j] = temp[i];
            j++;
        }
    }
    t1 = subVal(buf);
    if(t1.status != SUCCESS){
        return t1;
    }else{
        ret.status = SUCCESS;
        return ret;
    }


}

#endif
