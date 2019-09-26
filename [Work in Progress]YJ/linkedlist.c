#include<stdio.h>
#include<stdlib.h>

#ifndef LINKEDLIST
#define LINKEDLIST
typedef struct LinkList //For Polynomial
{
	float coef;
	struct LinkList *next;
}Quotient;
typedef struct polyterm{
	int pow;
	float coeff;
	struct polyterm *next;
}Polyterm;
Quotient *newnode,*qstart,*rootstart;			//start= to store quotient list  			start2= to store roots list
Polyterm *newnodeP,*pstart,*last;
void pushList(float v)
{
	Quotient *temp;
	Quotient *newnode =(Quotient *)malloc(sizeof(Quotient));
	newnode->next=NULL;
	newnode->coef=v;
	if (qstart==NULL)
	{
		qstart=newnode;
	}
	else
	{
		temp=qstart;
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
	temp=qstart;
	if (qstart==NULL)
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
	if (rootstart==NULL)
	{
		rootstart=newnode;
	}
	else
	{
		temp=rootstart;
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
	temp=rootstart;
	if (rootstart==NULL)
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

void pushPolyTerm(int pow,float coeff)
{
	Polyterm *temp;
	Polyterm *newnode =(Polyterm *)malloc(sizeof(Polyterm));
	newnode->next=NULL;
	newnode->pow = pow;
	newnode->coeff=coeff;
	if (pstart==NULL)
	{
		pstart=newnode;
		last = newnode;
	}
	else
	{
		last->next = newnode;
		last=newnode;
	}
}
#endif
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