#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include "./valparser.c"

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



//* convers infix operation to psuedo operation
void convert(){

    int i =0,j=0,len=0;
    float val =0.0;
    char x,t;
    x = infix[0];
    while(x!='\0'){

        if(isdigit(x)){
            i = parseVal(i)-1;
            postfix[j] = 'a';
            j++;    
        }else if(x =='('){
            pushOp(x);
        }else if(x==')'){
            t=popOp();
            
            while(t != '('){
               
                postfix[j] = t;
                j++;
                t = popOp();
            }
        }else if(x == '+'||x == '-'||x == '*'||x == '/'||x == '%'||x == 'e'||x == 'E'){
            if(opTop ==-1||priority(x)>priority(opSt[opTop])){
                pushOp(x);
            }else{
                while(opTop!=-1 && priority(x)<=priority(opSt[opTop])){
                    t = popOp();
                    postfix[j] = t;
                    j++;
                }
                
                pushOp(x);
            }
        }
        i++;
        x = infix[i];
       

        
    }
    
     while(opTop!= -1){
        t = popOp();
        postfix[j] = t;
        j++;
    }
}

void eval(){
    int temp =0,i=0;
    char op;
    float t =0.0,op1,op2;
    while(temp <vTop/2 +1){
        t = valArr[temp];
        valArr[temp] = valArr[vTop-temp];
         valArr[vTop-temp] = t;
         temp++;
    }
    op = postfix[i];
    while( op != '\0'){
        if(postfix[i] == 'a'){
            pushEval(popVal());
        }else{
            op2 = popEval();
            op1 = popEval();
            switch(op){
                case '+':{ pushEval(op1+op2);break;}
                case '-':{pushEval(op1-op2);break;}
                case '*':{pushEval(op1*op2);break;}
                case '/':{pushEval(op1/op2);break;}
                case '%':{pushEval((int)op1%(int)op2);break;}
                case 'e':
                case 'E' : {pushEval(pow(op1,op2));break;}
            }
        }
        op = postfix[++i];
    }


}
void main(){

    float val;
    printf("Give the expression To Evaluate.\n");
    printf("Supported Operators are: \n- : Negation\n+:Addition\n-:Subtraction\n*:Multiplication\n/:Division\n %%:Integer Division\n** or e or E : Exponentiation\n");
    printf("Give q or Q to quit.\n");
    while(1){
        scanf("%s",in);
        if(in[0]=='q'|| in[0] == 'Q'){break;}
        prepParse();
        convert();
        eval();
        val = popEval();
        printf("Answer is %f \n",nexttoward(val,val+1));
    }

}