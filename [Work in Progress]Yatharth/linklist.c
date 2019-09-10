#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList //For Operators Stack
{
	float coef;
	struct LinkList *next;
}Quotient;
Quotient *newnode,*front,*temp;
void pushList(float v)
{
	Quotient *newnode =(Quotient *)malloc(sizeof(Quotient));
	newnode->next=NULL;
	newnode->coef=v;
	if (front==NULL)
	{
		front=newnode;
	}
	else
	{
		temp=front;
		newnode->coef=v;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void displayList()
{
	temp=front;
	if (front==NULL)
	{
		printf("list is empty \n");
	}
	else
	{
		while (temp!=NULL)
		{
			printf("%f \n",temp->coef);			//Display the variables from top -> bottom
			temp=temp->next;
		}
	}
}
// Result flushList()								
// {
// 	Result ret;
// 	if (front==NULL)
// 	{
// 		ret.status = ERROR;
// 		strcpy(ret.error_info,"Empty Queue");
// 	}
// 	else
// 	{
// 		while (front!=NULL)	
// 		{
// 			temp=front;
// 			front=front->next;
// 			free(temp);
// 		}
// 		ret.status=SUCCESS;
// 	}
// 	return ret;
// }