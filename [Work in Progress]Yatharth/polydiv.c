#include<stdio.h>
#include<stdlib.h>
#include "./linklist.c"
// #include "./queues.c"  Later i will try to implement queues instead of arrays
float r,R;   			//r= const in (x-r)					R= Remainder1
float a[100];
float b[99];
int n;
float polyDiv()		//Returns Remainder , input is taken inside this.
{
	int i;
	b[0]=a[0];			//coef of x^n = coef of x^n-1 after division
	for (i = 1; i <= n; i++)
	{
		b[i] = a[i] + r * b[i-1];							// b[i] is coef of x^(n-i) and same for a[i]
	}
	R = a[n] + r * b[n-1];								//Remainder
	for (i=0;i<n;i++)
	{
		pushList(b[i]);
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
		scanf("%f",&a[i]);
	}
	for (i = 0; i <= n; i++)
	{
		printf("(%f x^%d) + ",a[i],n-i);		
	}
	printf("/ (x-%f) \n",r);
}
void displayQ(int n,float b[99])		//Pass the degree of eqn
{
	int i;
	printf("The Quotient is:\n");
	for (i = 0; i < n; ++i)
	{
		printf("(%f x^%d) +",b[i],n-i-1);
	}
	printf("\n");
	printf("Remainder is %f",R);
}
//========================================================================================================================
//==========Note: Add this void main code to Mark II and delete it from here. Also #include "./polydiv.c"=================
//========================================================================================================================
void main()				
{
	getDivisor();
	getPoly();
	R=polyDiv();
	displayQ(n,b);
}
//========------Add the above part-----------==========