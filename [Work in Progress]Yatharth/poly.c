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
float absolute(float x)
{
	if ( x < 0)
		return -x;
	else
		return x;
}
void getSum(int iteration,int degree)
{
	int i;
	tempSum=0;
	for (i=0;i<=degree-iteration-1;i++)
	{
		tempSum=root1*tempSum+polyQtnt[i];
	}
}
void evalPoly(int degree)
{
	int i,j;
	float tempRoot;
	for (i = 0; i < degree; i++)
	{
		
		if (degree-i>1)	// For all cases except Last when the eqn will be linear
		{
			root1=root();
			if (root1 == -1)
			{
				return;
			}
			do
			{
				Remainder=polyDiv(degree-i);
				getSum(i,degree-i);
				tempRoot=root1;
				root1=tempRoot-Remainder/tempSum;
			}
			while (absolute(Remainder)>=0.001);				//Iterating the value of Root till Remainder is less than 0.001
			for (j=0; j < degree-i; j++)			//Storing Quotient Array in our next Divisor Array
			{
				crrPoly[j]=polyQtnt[j];
			}
			printf("\n");
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
	int degree;
	degree=getPoly();
	evalPoly(degree);	
	displayRoot();		//This will display the root
}