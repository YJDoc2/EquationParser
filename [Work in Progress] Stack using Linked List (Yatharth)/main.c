#include "./linklist.c"
void main()										//For Debugging
{
	PushOp('+');
	DisplayOp();
	PushOp('*');
	PushOp('/');
	printf("PopOp=%c \n",PopOp());
	DisplayOp();
	printf("The 3 variables are:\n");
	PushP(1.5);
	PushP(2);
	PushP(3);
	printf("PopP=%f \n",PopP());
	DisplayP();
}