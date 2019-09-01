//========================================================
//==========================Queue=========================

#include<stdio.h>
#include<stdlib.h>

#ifndef QUEUE
#define QUEUE

typedef struct varQueue
{
	float var;
	struct varQueue *next;
}gQueue;
gQueue *front,*rear,*qTemp;
void enQ(float variable)
{
	gQueue *newnode = (gQueue *)malloc(sizeof(gQueue));
	newnode->next=NULL;
	newnode->var=variable;
	if (front==NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
Result deQ()
{
	Result ret;
	if (front==NULL)
	{	
		ret.status = ERROR;
		strcpy(ret.error_info,"Empty Queue");
	}
	else
	{
		float a;
		a=front->var;
		qTemp=front;
		front=front->next;
		free(qTemp);
		ret.status = SUCCESS;
		ret.data = a;
	}
	return ret;
}
/*void display()
{
	qTemp=front;
	if (front==NULL)
	{
		printf("Queue is empty \n");
	}
	else
	{
		while (qTemp!=NULL)
		{
			printf("%f \n",qTemp->var);			//Display the variables from top -> bottom
			qTemp=qTemp->next;
		}
	}
}
*/
#endif