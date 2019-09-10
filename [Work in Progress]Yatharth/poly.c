#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./polydiv.c"
float root()
{
	float t;
	t=(a[1]/a[0])*(a[1]/a[0])-2*(a[2]/a[0]);
	if (t<0)
	{
		printf("Error Roots Not Defined");
	}
	else
	{
		t=sqrt(t);
	}
	return t;
}
void main()
{
	getPoly();
	r=root();
	printf("%f\n", r);
}