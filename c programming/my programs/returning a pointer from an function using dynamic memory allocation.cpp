#include<stdio.h>
#include<stdlib.h>
// program for returning a pointer from an function using dynamic memory allocation
int *increment(int n)
{
	int *ptr;
	ptr=(int *)malloc(sizeof(int));//allocating memory using malloc function
	*ptr=n+1;
	return ptr;
}
int main()
{
	int *p;
	p=increment(1);
	printf("%d\n",*p);
	free(p);
}

