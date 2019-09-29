#include<stdio.h>
#include<stdlib.h>
#include "./linklist.c"
// #include "./queues.c"  Later i will try to implement queues instead of arrays
float root1,Remainder;   			//root1= const in (x-r)
float *crrPoly;
float *polyQtnt;
//int degree;
float polyDiv(int degree)		//Returns Remainder , input is taken inside this.
{
	int i;
	polyQtnt[0]=crrPoly[0];			//coef of x^n = coef of x^n-1 after division
	for (i = 1; i <= degree; i++)
	{
		polyQtnt[i] = crrPoly[i] + root1 * polyQtnt[i-1];							// polyQtnt[i] is coef of x^(n-i) and same for crrPoly[i]
	}
	Remainder = crrPoly[degree] + root1 * polyQtnt[degree-1];								//Remainder
	for (i=0;i<degree;i++)									//Storing in LinkList
	{
		pushList(polyQtnt[i]);
	}
	//display();
	return Remainder;
}
void getDivisor()
{
	printf("Enter the value or r in (x-r) which is divisor\n");
  	scanf("%f",&root1);
}
int getPoly()
{
	int i,degree;
	printf("Enter the degree of Polynomial Eqn: \n");
	scanf("%d",&degree);
	crrPoly=(float *)malloc((degree+1)*sizeof(float));
	polyQtnt=(float *)malloc(degree*sizeof(float));
	for (i = 0; i <= degree; i++)
	{
		printf("Enter Coeffecient of x^%d\n", degree-i );
		scanf("%f",&crrPoly[i]);
	}
	return degree;
}
void displayQ(float polyQtnt[99],int degree)		//Pass the degree of eqn
{
	int i;
	for (i = 0; i <= degree; i++)
	{
		printf("(%f x^%d) + ",crrPoly[i],degree-i);		
	}
	printf(" / (x - %f) \n",root1);
	// printf("/ (x-%f) \n",root);
	printf("The Quotient is:\n");
	for (i = 0; i < degree; ++i)
	{
		printf("(%f x^%d) +",polyQtnt[i],degree-i-1);
	}
	printf("\n");
	printf("Remainder is %f",Remainder);
}
//========================================================================================================================
//==========Note: Add this void main code to Mark II and delete it from here. Also #include "./polydiv.c"=================
//========================================================================================================================
// void main()				
// {
// 	int degree;
// 	getDivisor();
// 	degree=getPoly();
// 	Remainder=polyDiv(degree);
// 	displayQ(polyQtnt,degree);
// }
//========------Add the above part-----------==========