#include<stdio.h>
// program for returning a pointer from an function DANGLING POINTER
int *increment(int n)
{
	int temp;
	int *ptr= &temp;
	temp=n+1;
	return ptr;
}
int main()
{
	int *p;
	p=increment(1);
	printf("%d\n",*p);
}

