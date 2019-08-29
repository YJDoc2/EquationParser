//Suffix / Prefix :-
//Op = Operator
//P = Postfix
#include<stdio.h>
#include<stdlib.h>
typedef struct NodeOp //For Operators Stack
{
	char op;
	struct NodeOp *next;
}NodeO;
typedef struct NodePostfix //For Postfix Expression
{
	char var;
	struct NodePostfix *next;
}NodeP;
NodeO *Optop, *tempOp;			//Global Decalaration for Top and Temp of Operator Link List Stack
NodeP *Ptop, *tempP;		//Global Decalaration for Top and Temp of Postfix Link List Stack
void PushOp(char opr)
{
	NodeO *newnodeOp = (NodeO *)malloc(sizeof(NodeO));
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
	int i=3;
	tempOp=Optop;
	if (Optop==NULL)
	{
		printf("Optop is unassigned or the list is empty \n");
	}
	else
	{
		while (i>0)
		{
			printf("%c \n",tempOp->op);			//Display the operators from top -> bottom
			tempOp=tempOp->next;
			i--;
		}
	}
}
void PushP(char vari)
{
	NodeP *newnodeP =(NodeP *)malloc(sizeof(NodeP));
	newnodeP->var=vari;
	tempP=Ptop;
	if (tempP==NULL)
	{
		Ptop=newnodeP;
	}
	else
	{
		newnodeP->next=Ptop;
		Ptop=newnodeP;					//Attaches NewNode before (on top of) the top node in the stack
	}
}
char PopP()
{
	char variable;
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
	int i=3;
	tempP=Ptop;
	if (Ptop==NULL)
	{
		printf("Ptop is unassigned or the list is empty \n");
	}
	else
	{
		while (i>0)
		{
			printf("%c \n",tempP->var);			//Display the variables from top -> bottom
			tempP=tempP->next;
			i--;
		}
	}
}
void main()										//For Debugging
{
	PushOp('+');
	DisplayOp();
	PushOp('*');
	PushOp('/');
	printf("PopOp=%c",PopOp());
	DisplayOp();
	printf("Enter 3 variables\n");
	PushP('a');
	PushP('b');
	PushP('c');
	printf("PopP=%c",PopP());
	DisplayP();
}

