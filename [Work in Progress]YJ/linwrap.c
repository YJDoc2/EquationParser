#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./typedef.c"
#include "./preparser.c"
#include "./parser.c"
#include "./linear.c"


#ifndef LINWRAP
#define LINWRAP

int currentEq=1;

//* Gets the First occurence of character c, case-ignored in range in->end
char *getCharPos(char *in, char *end,char c){
    char *t = in;

    if(end<in){
        return NULL;
    }
    while(t<=end){
        if(tolower(*t) == tolower(c)){
            return t;
        }else{
            t = t+1;
        }
    }
    return NULL;
}

Result getCoeffNum(char *in){
    Result ret;
    if(!isdigit(*(in+1)) || (*(in+2) != '+' && *(in+2) != '-' && *(in+2) !='\0')){
        ret.status = ERROR;
        sprintf(ret.error_info,"Invalid Variable %c%c%c",*in,*(in+1),*(in+2));
        return ret;
    }else{
        ret.status = SUCCESS;
        ret.data = *(in+1) - '0';
        return ret;
    }

}

void setConstTerm(float val){
    int sign = val<0?-1:1;
    //printf("Constant Value %f\n",val);
    if(-1E-36<val && 1E-36>val){
        val = sign*1E-37;
    }
    addConstTerm(currentEq,val);
}
void setCoeff(int pos,float val){
    //printf("Position : %d Value %f\n",pos,val);
    addCoeff(currentEq,pos,val);
}
//!Will only work if given equation are in form f()x0+f()x1+....+f()x9+c with/wothout = c'
//! Please use specified format to have accurate answers

Result parserLinear(char in[]){
    char *start,*end,*eq,*xpos;
    char eqn[50];
    memset(eqn,'\0',50);
    int varnum;
    Result temp;
    removeSpaces(in);
    if(strchr(in,'=') != strrchr(in,'=')){
        temp.status = ERROR;
        sprintf(temp.error_info,"Cannot Have multiple assignment Signs in An Equation");
        return temp;
    }
    eq = strchr(in,'=');
    if(eq == NULL){
        setConstTerm(0);
        strncpy(eqn,in,strlen(in)+1);
        end = eqn+strlen(eqn)-1; //!check for error in running
    }else{
        end = eq-1;
        temp = parse(eq+1,in+strlen(in));
        CHECK(temp,in,eq+1);
        strncpy(eqn,in,eq-in);
        eqn[strlen(eqn)] ='\0';
        setConstTerm(temp.data);
    }
    start = eqn;
    xpos = getCharPos(eqn,end,'x');
    if(xpos == NULL){
        temp.status = ERROR;
        sprintf(temp.error_info,"No X or x found in given linear equation");
        return temp;
    }
    while(xpos != NULL){
        temp = getCoeffNum(xpos);
        CHECK(temp,in,xpos-in+1);
        varnum = temp.data;
        if(start == xpos || *start == '\0'){
            temp.status = SUCCESS;
            temp.data = 1;
        }else if(*start=='-' && start+1 ==xpos){
            temp.status = SUCCESS;
            temp.data = -1;
        }else{
            temp = parse(start,xpos);
            CHECK(temp,in,xpos-in);
        }
        setCoeff(varnum,temp.data);
        if(*(xpos+2) == '+'){
            start = xpos+3;
        }else{
            start = xpos+2;
        }
        xpos = getCharPos(xpos+1,xpos+strlen(xpos),'x');
    }
    if(start != eqn+strlen(eqn)){
        temp = parse(start,eqn+strlen(eqn));
        CHECK(temp,in,xpos-in);
        setConstTerm(temp.data);
    }
}

Result linearSolve(){

    char eq[175];
    char null;
    Result ret;
    initLinear();
    printf("please Give The linear equations in following way for most accurate results :\n");
    printf("Coeffx0 + Coeffx1 + ... + Coeffxn + Constant = Constant\n");
    printf("Do not put multiplication sign * between Coefficient and variable, both constants are optional.\n");
    printf("Give number of variables : ");
    scanf("%d",&numVars);
    printf("Please use variables x0 to x%d only\nDo not use inbuilt constants or defined Variables that contain X\n",numVars-1);
    null = getchar();
    fflush(stdin);
    for(currentEq=1;currentEq<=numVars;currentEq++){
        memset(eq,'\0',175);
        printf(">>>>> ");
        fgets(eq,170,stdin);
        eq[strlen(eq)-1] = '\0';
        if(strcmp(eq,"back")==0){
            ret.status = SUCCESS;
            return ret;
        }
        if(strlen(eq)>150){
            printf("Please give Equation containing less Than 150 Character.\n");
            currentEq--;
            continue;
        }else{
            parserLinear(eq);
        }
    }
    ret = solveLinear();
    CHECK(ret,eq,0);
    displayLinearSoln();
    return ret;
}

void main(){
    Result ret;
   /* char in[50];
    printf(">>>>> ");
    fgets(in,50,stdin);
    in[strlen(in)-1] = '\0';
    ret = parserLinear(in);*/
    ret = linearSolve();
    if(ret.status!=SUCCESS)printf("%s\n",ret.error_info);
}


#endif