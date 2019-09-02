#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include "./typedef.c"
#include "./preparser.c"
#include "./stacks.c"
#include "./queues.c"

#ifndef PARSER
#define PARSER

#define CHECK(ret,inS,pos)({\
            if(ret.status != SUCCESS){\
                printf("\nError in Parsing Expression %s at %d :: %s\n",inS,pos,ret.error_info);\
                return ret;\
            }\
        })

char postfix[150];

int priority(char c){
    if(c == 'e' || c =='E'){
        return 4;
    }else if(c =='*'||c=='/'||c == '%'){
        return 3;
    }else if(c =='+'||c =='-'){
        return 2;
    }else {
        return 1;
    }
}

Result parseVal(char inString[],int start){
    int dec =0;
    float val = 0.0;
    int count;
    Result ret;
    while(isdigit(inString[start])){
        val = val*10 + (float)(inString[start]-'0');
        start++;
    }
    if(inString[start] == '.'){
         start++;
    while(isdigit(inString[start])){
        val = val*10 + (float)(inString[start]-'0');
        start++;
    }}
    val = nextafterf(val/pow(10,dec),val+1);
    ret.data = val;
    ret.status = SUCCESS;
    ret.subdata[0] = start;
    return ret;
}

//!! DOES NOT CONVERT ** TO E
//!! DO THAT IN PREPARSER
Result convert(char in[]){

    int i =0,j=0,len=0;
    float val =0.0;
    char x,t;
    Result temp;
    preparse(in);
    x = infix[0];
    while(x!='\0'){

        if(isdigit(x)){
            temp = parseVal(infix,i);
            i = temp.subdata[0]-1;
            enQVar(temp.data);
            postfix[j] = 'a';
            j++;    
        }else if(x =='('){
            pushOp(x);
        }else if(x==')'){
            temp = popOp();
            CHECK(temp,infix,i+1);
            t=(char)temp.data;
            
            while(t != '('){
               
                postfix[j] = t;
                j++;
                temp = popOp();
                CHECK(temp,infix,i+1);
            }
        }else if(x == '+'||x == '-'||x == '*'||x == '/'||x == '%'||x == 'e'||x == 'E'){
            if(opTop ==NULL||priority(x)>priority((char)peekOp().data)){
                pushOp(x);
            }else{
                while(opTop!=NULL && priority(x)<=priority((char)peekOp().data)){

                    temp = popOp();
                    CHECK(temp,infix,i+1);
                    t = (char)temp.data;
                    postfix[j] = t;
                    j++;
                }
                
                pushOp(x);
            }
        }
        i++;
        x = infix[i];
       

        
    }
    
     while(opTop!= NULL){
        temp = popOp();
        CHECK(temp,infix,i+1);
        t = (char)temp.data;
        postfix[j] = t;
        j++;
    }
}

Result eval(){
    int temp =0,i=0;
    char op;
    float t =0.0,op1,op2;
    op = postfix[i];
    Result r,ret;
    while( op != '\0'){
        if(postfix[i] == 'a'){
            r = deQVar();
            CHECK(r,postfix,i+1); 
            push(r.data);
        }else if(postfix[i] == 'v'){
            r = deQVal();
            CHECK(r,postfix,i+1); 
            push(r.data);
        }else{
            r = pop();
            CHECK(r,postfix,i+1);
            op2 = r.data;
            r = pop();
            CHECK(r,postfix,i+1);
            op1 = r.data;
            switch(op){
                case '+':{ push(op1+op2);break;}
                case '-':{push(op1-op2);break;}
                case '*':{push(op1*op2);break;}
                case '/':{push(op1/op2);break;}
                case '%':{push((int)op1%(int)op2);break;}
                case 'e':
                case 'E' : {push(pow(op1,op2));break;}
            }
        }
        op = postfix[++i];
    }
    r = pop();
    CHECK(r,postfix,i);
    ret.status = SUCCESS;
    ret.data = r.data;
    return ret;


}


#endif