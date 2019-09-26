#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./polydiv.c"
#include "./config.c"

#ifndef POLY
#define POLY
float tempSum;
Result root()
{
	float t;
	Result ret;
	t=(crrPoly[1]/crrPoly[0])*(crrPoly[1]/crrPoly[0])-2*(crrPoly[2]/crrPoly[0]);				//Upper Limit of Root
	if (t<0)
	{	
		ret.status = ERROR;
		sprintf(ret.error_info,"No Real Root");
		return ret;
	}
	else
	{
		t=sqrt(t);
	}
	ret.status = SUCCESS;
	ret.data = t;
	return ret;
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
Result evalPoly()
{
	int i,j;
	Result temp;
	temp = root();
	if(temp.status != SUCCESS){return temp;}
	root1=temp.data;
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
			while (Remainder>ROOTERR);				//Iterating the value of Root till Remainder is less than 0.001
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
	temp.status = SUCCESS;
	return temp;
}
#endif