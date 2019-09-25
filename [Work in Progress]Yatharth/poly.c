#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./polydiv.c"
float tempSum;
float root()
{
	float t;
	t=(crrPoly[1]/crrPoly[0])*(crrPoly[1]/crrPoly[0])-2*(crrPoly[2]/crrPoly[0]);				//Upper Limit of Root
	if (t<0)
	{
		printf("Error Roots Not Defined");
		return -1;
	}
	else
	{
		t=sqrt(t);
	}
	return t;
}
void getSum()
{
	int i;
	tempSum=0;
	for (i=0;i<degree;i++)
	{
		tempSum=tempSum+polyQtnt[i];
	}
}
void evalPoly()
{
	int i,j;
	root1=root();
	if (root1 == -1)
	{
		return;
	}
	Remainder=0;		// For Line 42 Initialization
	tempSum=1;		// For Line 42 Initialization
	for (i = 0; i < degree; i++)
	{
		if (degree-i>1)	// For all cases except Last when the eqn will be linear
		{
			do
			{
				root1=root1-Remainder/tempSum;
				Remainder=polyDiv();
				getSum();
				//printf("%f R=%f\n", r,R);
			}
			while (Remainder>0.001);				//Iterating the value of Root till Remainder is less than 0.001
			for (j=0; j < degree-i; j++)			//Storing Quotient Array in our next Divisor Array
			{
				crrPoly[j]=polyQtnt[j];
			}
			pushRoot(root1);
		}
		else							//When the equation is reduced to Linear Form
		{
			root1 = -crrPoly[1]/crrPoly[0];
			pushRoot(root1);
		}
	}
}
void main()
{
	getPoly();
	evalPoly();	
	displayRoot();		//This will display the root
}