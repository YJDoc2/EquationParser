#include<stdio.h>
#include<stdlib.h>
#include "./linklist.c"
// #include "./queues.c"  Later i will try to implement queues instead of arrays
float r,R;   			//r= const in (x-r)					R= Remainder1
float crrPoly[100];
float polyQtnt[99];
int n;
float polyDiv()		//Returns Remainder , input is taken inside this.
{
	int i;
	polyQtnt[0]=crrPoly[0];			//coef of x^n = coef of x^n-1 after division
	for (i = 1; i <= n; i++)
	{
		polyQtnt[i] = crrPoly[i] + r * polyQtnt[i-1];							// polyQtnt[i] is coef of x^(n-i) and same for crrPoly[i]
	}
	R = crrPoly[n] + r * polyQtnt[n-1];								//Remainder
	for (i=0;i<n;i++)									//Storing in LinkList
	{
		pushList(polyQtnt[i]);
	}
	//display();
	return R;
}
void getDivisor()
{
	printf("Enter the value or r in (x-r) which is divisor\n");
  	scanf("%f",&r);
}
void getPoly()
{
	int i;
	printf("Enter the degree of Polynomial Eqn: \n");
	scanf("%d",&n);
	for (i = 0; i <= n; i++)
	{
		printf("Enter Coeffecient of x^%d\n", n-i );
		scanf("%f",&crrPoly[i]);
	}
}
void displayQ(int n,float polyQtnt[99])		//Pass the degree of eqn
{
	int i;
	
	for (i = 0; i <= n; i++)
	{
		printf("(%f x^%d) + ",crrPoly[i],n-i);		
	}
	printf("/ (x-%f) \n",r);
	printf("The Quotient is:\n");
	for (i = 0; i < n; ++i)
	{
		printf("(%f x^%d) +",polyQtnt[i],n-i-1);
	}
	printf("\n");
	printf("Remainder is %f",R);
}
//========================================================================================================================
//==========Note: Add this void main code to Mark II and delete it from here. Also #include "./polydiv.c"=================
//========================================================================================================================
// void main()				
// {
// 	getDivisor();
// 	getPoly();
// 	R=polyDiv();
// 	displayQ(n,b);
// }
//========------Add the above part-----------==========