#include<stdio.h>
#include<stdlib.h>
typedef struct varStack
{
	float var;
	struct varStack *next;
}gStack;
gStack *top,*temp;
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
void main()
{
	printf("Input is 1, 2.1, 4.6 \n");
	push(1);
	push(2.1);
	push(4.6);
	printf("Pop = %f \n", pop());
	display();
}