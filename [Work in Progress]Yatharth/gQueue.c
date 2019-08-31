//========================================================
//==========================Queue=========================

#include<stdio.h>
#include<stdlib.h>
typedef struct varQueue
{
	float var;
	struct varQueue *next;
}gQueue;
gQueue *top,*rear,*temp;
void Push()
{
	gQueue *newnode = (gQueue *)malloc(sizeof(gQueue));

}