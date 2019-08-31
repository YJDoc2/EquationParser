//========================================================
//==========================Queue=========================

#include<stdio.h>
#include<stdlib.h>
typedef struct varQueue
{
	float var;
	struct varQueue *next;
}gQueue;
gQueue *front,*rear,*temp;
void push(float variable)
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
float pop()
{
	if (front==NULL)
	{
		printf("Empty Queue\n");
		return 0;
	}
	else
	{
		float a;
		a=front->var;
		temp=front;
		front=front->next;
		printf("%f \n",a);
		free(temp);
		return a;
	}
}
void display()
{
	temp=front;
	if (front==NULL)
	{
		printf("Queue is empty \n");
	}
	else
	{
		while (temp!=NULL)
		{
			printf("%f \n",temp->var);			//Display the variables from top -> bottom
			temp=temp->next;
		}
	}
}
//For debugging
void main()
{
	printf("Input is 1 , 2 , 3 , 4.5\n");
	push(1);
	push(2);
	push(3);
	push(4.5);
	printf("pop=%f\n",pop() );
	display();
}