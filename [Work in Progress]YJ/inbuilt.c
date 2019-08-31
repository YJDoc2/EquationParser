#include "./typedef.c"
#include "./variables.c"
#include "./config.c"
#include<stdio.h>
#include<error.h>
#include<errno.h>

#ifndef INBUILT
#define INBUILT

FILE *file;

Result vardump(){

    Result ret;
    Var *temp = var_start;
    int c =0;
    char route[52];
    sprintf(route,"./%s",varlogFile);
    file = fopen(route,"w");
    if(file == NULL){
        ret.status = FILE_ERROR;
        sprintf(ret.error_info,"Error in writing vardump file : %s",strerror(errno));

    }else{
        for(;c<10;c++){
            fprintf(file,"%f ",default_var[c]); //! Mind the space after %lf, thus must be a space in fscanf
        }
        while(temp !=NULL){
            fprintf(file,"%s : %f\n",temp->name,temp->val);
            temp = temp->next;
        }
        ret.status = SUCCESS;
        fclose(file);
    }
    
    return ret;
}

Result varload(){

    Result ret;
    Var *temp = var_start;
    int c =0;
    char name[30];
    float val;
    char route[52];
    sprintf(route,"./%s",varlogFile);
    file = fopen(route,"r");
    if(file == NULL){
        
        ret.status = FILE_ERROR;
        sprintf(ret.error_info,"Error in reading vardump file : %s",strerror(errno));
    }else{
        clearVars();
        for(;c<10;c++){
            fscanf(file,"%f ",&default_var[c]);
        }
        while(!feof(file)){
            fscanf(file,"%s : %f\n",name,&val);
            setVar(name,val);
        }
        ret.status = SUCCESS;
        fclose(file);
    }
    
    return ret;

}




#endif