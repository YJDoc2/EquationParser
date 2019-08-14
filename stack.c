

char in[200],postfix[200], opSt[50];
float valArr[50],evalSt[20];
int opTop =-1,vTop =-1,eTop=-1;




char pushOp(char c){
    if(opTop <199){
        opTop++;
        opSt[opTop] = c;
        return opSt[opTop];
    }else{
        printf("opStack Overflow Error!!!\n");
        return 0;
    }
}
float pushVal(float val){
    if(vTop <49){
        vTop++;
        valArr[vTop] =val;
        return valArr[vTop];
    }else{
        printf("valArrack Overflow Error!!!\n");
        return 0;
    }
}
float pushEval(float val){
    if(eTop <19){
        eTop++;
        evalSt[eTop] =val;
        return evalSt[eTop];
    }else{
        printf("evalArrack Overflow Error!!!\n");
        return 0;
    }
}

char popOp(){

    if(opTop !=-1){
        char val = opSt[opTop];
        opTop--;
        return val;
    }else{
        printf("opStack Empty Error!!!\n");
        return 0;
    }

}

float popVal(){

    if(vTop !=-1){
        float val = valArr[vTop];
        vTop--;
        return val;
    }else{
        printf("valArr Empty Error!!!\n");
        return 0;
    }

}
float popEval(){

    if(eTop !=-1){
        float val = evalSt[eTop];
        eTop--;
        return val;
    }else{
        printf("evalStack Empty Error!!!\n");
        return 0;
    }

}