//========================================================
//=====================PostFix Stack======================

//Suffix / Prefix :-
//Op = Operator
//P = Postfix
#include<stdio.h>
#include<stdlib.h>

#ifndef STACK
#define STACK
typedef struct NodeOp //For Operators Stack
{
	char op;
	struct NodeOp *next;
}NodeO;
typedef struct NodePostfix //For Postfix Expression
{
	float var;
	struct NodePostfix *next;
}NodeP;
//========================================General Stack=====================================================
typedef struct varStack
{
	float var;
	struct varStack *next;
}gStack;
gStack *top,*temp;			    //General Stack
NodeO *Optop, *tempOp;			//Global Decalaration for Top and Temp of Operator Link List Stack
NodeP *Ptop, *tempP;		//Global Decalaration for Top and Temp of Postfix Link List Stack
void PushOp(char opr)
{
	NodeO *newnodeOp = (NodeO *)malloc(sizeof(NodeO));
	newnodeOp->next=NULL;
	newnodeOp->op=opr;
	if (Optop==NULL)
	{
		Optop=newnodeOp;
	}
	else
	{
		newnodeOp->next=Optop;
		Optop=newnodeOp;					//Attaches NewNode before (on top of) the top node in the stack
	}
}
char PopOp()
{
	char operator;
	if (Optop==NULL)
	{
		printf("Operator Stack List Empty Error\n");
		return 0;
	}
	else
	{
		operator=Optop->op;
		tempOp=Optop;
		Optop=Optop->next;
		free(tempOp);
		return operator;
	}
}
//Display Function Only For Debugging
void DisplayOp()
{
	//int i=2;
	tempOp=Optop;
	if (Optop==NULL)
	{
		printf("Optop is unassigned or the list is empty \n");
	}
	else
	{
		while (tempOp!=NULL)
		{
			printf("%c \n",tempOp->op);			//Display the operators from top -> bottom
			tempOp=tempOp->next;
		}
	}
}
void PushP(float vari)
{
	NodeP *newnodeP =(NodeP *)malloc(sizeof(NodeP));
	newnodeP->next=NULL;
	newnodeP->var=vari;
	if (Ptop==NULL)
	{
		Ptop=newnodeP;
	}
	else
	{
		newnodeP->next=Ptop;
		Ptop=newnodeP;					//Attaches NewNode before (on top of) the top node in the stack
	}
}
float PopP()
{
	float variable;
	if (Ptop==NULL)
	{
		printf("Postfix Stack List Empty Error\n");
		return 0;
	}
	else
	{
		variable=Ptop->var;
		tempP=Ptop;
		Ptop=Ptop->next;
		free(tempP);
		return variable;
	}
}
void DisplayP()
{
	tempP=Ptop;
	if (Ptop==NULL)
	{
		printf("Ptop is unassigned or the list is empty \n");
	}
	else
	{
		while (tempP!=NULL)
		{
			printf("%f \n",tempP->var);			//Display the variables from top -> bottom
			tempP=tempP->next;
		}
	}
}
//================================Functions of General Stack========================================
void push(float variable)
{
	gStack *newnode =(gStack *)malloc(sizeof(gStack));
	newnode->next=NULL;
	newnode->var=variable;
	if (top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;					//Attaches NewNode before (on top of) the top node in the stack
	}
}
float pop()
{
	float variable;
	if (top==NULL)
	{
		printf("Postfix Stack List Empty Error\n");
		return 0;
	}
	else
	{
		variable=top->var;
		temp=top;
		top=top->next;
		free(temp);
		return variable;
	}
}
void display()
{
	temp=top;
	if (top==NULL)
	{
		printf("top is unassigned or the list is empty \n");
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

#endif