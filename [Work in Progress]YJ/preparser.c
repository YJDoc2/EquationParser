#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PREPARSER
#define PREPARSER

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



#endif