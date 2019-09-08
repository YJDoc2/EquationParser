#include<stdio.h>
#include<string.h>
#include "./typedef.c"
#include "./variables.c"
#include "./preparser.c"
#include "./parser.c"
#include "./constants.c"
/*
* This is checking main file for variables and typedef

*/
/*void main(){

    int c = -1;
    int place;
    char name[30];
    float val;
    Result res;
    while(c != 11){
        printf("\n1.setDefVar\n2.getDefVar\n3.setVar\n4.getVar\n5.clearVars\n6.showVars\n7.vardump\n8.varload\n9.setConfig\n10.showConfig\n11.exit\n");
        fflush(stdin);
        scanf("%d",&c);
        switch(c){
            case 1: {
                fflush(stdin);
                scanf("%d %f",&place,&val);
                res = setDefVal(place,val);
                printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);
                break;
            }
            case 2: {
                fflush(stdin);
                scanf("%d",&place);
                res = getDefVal(place);
                printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);
                break;

            }
            case 3:{
                fflush(stdin);
                scanf("%s %f",name,&val);
                if(strlen(name)>30){
                    printf("Too big name");
                }else{
                    res = setVar(name,val);
                    printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);
                }
                break;
            }
            case 4 :{
                fflush(stdin);
                scanf("%s",name);
                if(strlen(name)>30){
                    printf("Too big name\n");
                }else{
                    res = getVar(name);
                    printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);
                }
                break;
            }
            case 5:{
                res = clearVars();
                printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);
                break;
            }
            case 6: {res = showVars();printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);break;}
            case 7: {res = vardump();printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);break;}
            case 8 : {res = varload();printf("stat : %d, info :%s,data: %lf\n",res.status,res.error_info,res.data);break;}
            case 9 :{setConfig();break;}
            case 10 :{showConfig();break;};
            case 11 : break;
        }

    }



}*/
void main(){

    int c =-1,place =0;
    char name[30];
    float val;
    char in[50];
    Result ret,res;
    initConst();
    /*printf("Give Expression : ");
                fgets(in,50,stdin);
                in[strlen(in)-1] = '\0';
                removeSpaces(in);
                ret = convert(in);
                if(ret.status == SUCCESS)ret = eval();
                printf("Stat : %d ; Data : %0.5e ;Info : %s\n",ret.status,ret.data,ret.error_info);*/
                
       
    while(c!=5){
        printf("\n1.set variable\n2.set default variable $0-$9\n3.print variables\n4.evaluate expression\n5.Quit\n");
        scanf("%d",&c);
        getc(stdin);
        switch(c){
            
            case 1:{fflush(stdin);
                printf("name <space> value\n");
                scanf("%s %f",name,&val);
                if(strlen(name)>30){
                    printf("Too big name");
                }else{
                    res = setVar(name,val);
                    if(res.status != SUCCESS){
                        printf("Error : %d, info :%s\n",res.status,res.error_info);
                    }
                }
                break;}
            case 2:{fflush(stdin);
                printf("place <space> value\n");
                scanf("%d %f",&place,&val);
                res = setDefVar(place,val);
                if(res.status != SUCCESS){
                    printf("ERROR : %d, info :%s\n",res.status,res.error_info);}
                break;}
            case 3: {showVars();break;}
            case 4:{
                printf("Give Expression : ");
                fgets(in,50,stdin);
                in[strlen(in)-1] = '\0';
                removeSpaces(in);
                ret = convert(in,in+strlen(in));
                if(ret.status == SUCCESS)ret = eval();
                printf("Stat : %d ; Data : %0.5e ;Info : %s\n",ret.status,ret.data,ret.error_info);
                break;
            }
            case 5:break;
            default : break;
        }
    }
}