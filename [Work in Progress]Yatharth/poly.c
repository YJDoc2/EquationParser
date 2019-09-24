#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./polydiv.c"
float S;
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
	S=0;
	for (i=0;i<n;i++)
	{
		S=S+polyQtnt[i];
	}
}
void evalPoly()
{
	int i,j;
	r=root();
	if (r == -1)
	{
		return;
	}
	R=0;		// For Line 42 Initialization
	S=1;		// For Line 42 Initialization
	for (i = 0; i < n; i++)
	{
		if (n-i>1)	// For all cases except Last when the eqn will be linear
		{
			do
			{
				r=r-R/S;
				R=polyDiv();
				getSum();
				//printf("%f R=%f\n", r,R);
			}
			while (R>0.001);				//Iterating the value of Root till Remainder is less than 0.001
			for (j=0; j < n-i; j++)			//Storing Quotient Array in our next Divisor Array
			{
				crrPoly[j]=polyQtnt[j];
			}
			printf("Root %d = %f\n",i+1, r);
		}
		else							//When the equation is reduced to Linear Form
		{
			r = -crrPoly[1]/crrPoly[0];
			printf("Root %d = %f \n",i+1,r);
		}
	}
}
void main()
{
	getPoly();
	evalPoly();	
}