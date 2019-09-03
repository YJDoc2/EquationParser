#include<stdio.h>
#include<string.h>
char in[20];
int top = -1;
void push(char c)
{
    if(top==19)
        printf("Overflow");
    else
    {
        top+=1;
        in[top] = c;
    }
}
char pop()
{
    if(top==-1)
        printf("Empty");
    else
    {
        return(in[top--]);
    }
}

char bracketCheck()
{
    char temp;
    int i, flag=1;
    for(i = 0; i<strlen(in) ;i++)
    {
        if(in[i]=='(' || in[i]=='[' || in[i]=='{')
            push(in[i]);
        if(in[i]==')' || in[i]==']' || in[i]=='}')
            if(top==-1)
                flag=0;
            else
            {
                temp=pop();
                if(in[i]==')' && (temp=='[' || temp=='{'))
                    flag=0;
                if(in[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(in[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
    }
    if(top>=0)
        flag=0;
    if(flag==1)
        printf("Valid Expression!");
    else
        printf("Invalid Expression!");
}
void main()
{
    gets(in);
    bracketCheck();
}
