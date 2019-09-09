#include<stdio.h>
#include<stdlib.h>
#include "./linklist.c"
// #include "./queues.c"  Later i will try to implement queues instead of arrays
void main()
{
	float a[100];
	float b[99];
	int n,i;
	float r,R;
  	printf("Enter the value or r in (x-r) which is divisor\n");
  	scanf("%f",&r);
	printf("Enter the degree of Polynomial Eqn: \n");
	scanf("%d",&n);
	for (i = 0; i <= n; i++)
	{
		printf("Enter Coeffecient of x^%d\n", n-i );
		scanf("%f",&a[i]);
	}

//Printing the Input in the form Divident / Divisor
/*	for (i = 0; i <= n; i++)
	{
		printf("(%f x^%d) + ",a[i],n-i);		
	}
	printf("/ (x-%f) \n",r);
*/
	b[0]=a[0];			//coef of x^n = coef of x^n-1 after division
	for (i = 1; i <= n; i++)
	{
		b[i] = a[i] + r * b[i-1];							// b[i] is coef of x^(n-i) and same for a[i]
	}
	R = a[n] + r * b[n-1];								//Remainder

//Printing the Output
/*	printf("The Quotient is:\n");
	for (i = 0; i < n; ++i)
	{
		printf("(%f x^%d) +",b[i],n-i-1);
	}
	printf("\n");
	printf("Remainder is %f",R);
*/
	for (i=0;i<n;i++)
	{
		push(b[i]);
	}
	display();
	printf("Remainder=%f",R);
}