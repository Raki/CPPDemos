#include <stdio.h>

void temp(int a)
{
	printf("value of given var %d",a);
}


void main()
{
	int arr[] = { 10, 20, 30, 40, 50, 60 };
	printf("Hello world %d",*(arr+2));
	temp(26);
}