#include <stdio.h>
#include <string.h>
#include "./parser.c"
#include "./variables.c"
#include "constants.c"

void main(){

    char c[100];
    Result r;
    r.status = ERROR;
    c[0] = '\0';
    printf("-----General Equation Parser MK II Proto I-----\n");
    initConst();
    while(1){
        printf(">>>>> ");
        fflush(stdin);
        memset(c,'\0',100);
        fgets(c,100,stdin);
        c[strlen(c)-1] = '\0';
        if(c[0] == 'q' || c[0] == 'Q'){
            break;
        }
        if(strcmp(c,"help")==0){
            printf("Give equation To evaluate.\n");
            printf("$varnum = eq  to set default variable values.\n");
            printf("varname = eq to set variable values\n");
            printf("showvars to show variable values.\n");
            printf("showconst to show constant values\n");
            printf("Q or q to quit\n");
        }else if(strcmp(c,"showvars")==0){
            showVars();
        }else if(strcmp(c,"showconst")==0){
            showConst();
        }else {
            //printf("CheckIE");
            r = parse(c,c+strlen(c));
            if(r.status != SUCCESS){
                printf("Error Occured...%s\n",r.error_info);
            }else{
                printf("%0.5e\n",r.data);
            }
            
        }
    }


}