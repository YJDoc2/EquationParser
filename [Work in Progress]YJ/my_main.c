#include<stdio.h>
#include "./typedef.c"
#include "./variables.c"
#include "./inbuilt.c"
#include "./config.c"
#include "./parser.c"
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

    char in[50];
    Result ret;
    printf("Give Expression :\n");
    scanf("%s",in);
    ret = convert(in);
    printf("C -> %s\n",postfix);
    ret = eval();
    printf("Stat : %d ; Data : %f ; Info : %s\n",ret.status,ret.data,ret.error_info);

}