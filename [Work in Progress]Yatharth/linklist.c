#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList //For Operators Stack
{
	float coef;
	struct LinkList *next;
}Quotient;
Quotient *newnode,*start,*start2;			//start= to store quotient list  			start2= to store roots list
void pushList(float v)
{
	Quotient *temp;
	Quotient *newnode =(Quotient *)malloc(sizeof(Quotient));
	newnode->next=NULL;
	newnode->coef=v;
	if (start==NULL)
	{
		start=newnode;
	}
	else
	{
		temp=start;
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
	Quotient *temp;
	temp=start;
	if (start==NULL)
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
void pushRoot(float v)
{
	Quotient *temp;
	Quotient *newnode =(Quotient *)malloc(sizeof(Quotient));
	newnode->next=NULL;
	newnode->coef=v;
	if (start2==NULL)
	{
		start2=newnode;
	}
	else
	{
		temp=start2;
		newnode->coef=v;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void displayRoot()
{
	Quotient *temp;
	temp=start2;
	if (start2==NULL)
	{
		printf("List is empty \n");
	}
	else
	{
		while (temp!=NULL)
		{
			printf("Root= %f \n",temp->coef);			//Display the variables from top -> bottom
			temp=temp->next;
		}
	}
}
// Result flushList()								
// {
// 	Result ret;
// 	if (start==NULL)
// 	{
// 		ret.status = ERROR;
// 		strcpy(ret.error_info,"Empty Queue");
// 	}
// 	else
// 	{
// 		while (start!=NULL)	
// 		{
// 			temp=start;
// 			start=start->next;
// 			free(temp);
// 		}
// 		ret.status=SUCCESS;
// 	}
// 	return ret;
// }