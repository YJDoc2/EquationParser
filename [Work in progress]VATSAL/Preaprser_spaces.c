#include<stdio.h>
#include<string.h>
void removeSpaces(char *p)
{

    if(NULL == p)
        return;
    int n =0;
    for(int i = 0;i<strlen(p);++i)
        if(p[i]!=' ')
            p[n++]=p[i];
        p[n]='\0';
}
void main()
{
    char in[200];
    printf("Enter a string : ");
    gets(in);
    removeSpaces(in);
    printf("%s",in);
}
