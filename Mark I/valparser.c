#include "./stack.c"
#include<string.h>

//* Actual Infix Array
char infix[250];

//* prepares the input array for converting to postifx array
void prepParse(){

    char pre;
    int i =0,j=0;
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
        }else{
            infix[j] = in[i];
            j++;i++;
        }


    }



}

//* converts numbers in in array to float number
float parseVal(int k){
    int dec =0;
    float val = 0.0;
    while(isdigit(infix[k])){
        val = val*10 + (float)(infix[k]-'0');
        k++;
    }
   
    if(infix[k] == '.'){
         k++;
    while(isdigit(infix[k])){
        val = val*10 + (float)(infix[k]-'0');
        k++;
        dec++;
    }}
    val = nextafterf(val/pow(10,dec),val+1);
    pushVal(val);
    return k;
}