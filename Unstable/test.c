#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "./stacks.c"

char buf[50];
int isop(char a){
    
    return a=='+' || a=='-' || a=='*' || a=='/' ||a=='%' || a=='E';
}
void pushbrack(char i){

    if(i == '(') push(')');
    if(i=='[') push(']');
    if(i=='{') push('}');

}

char *adjustNegetive(char *in){

    int i=0,j=0,l =0;
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

void main(){
    char in[50];
    scanf("%s",in);
    printf("%s\n",adjustNegetive(in));
}