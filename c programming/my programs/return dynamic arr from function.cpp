//solution for dangling array
//declaring arr in function and return arr
#include<stdio.h>
#include<stdlib.h>
int * fun(int n);
int main()
{
	int *p;
	int n;
	printf("enter the n: ");
	scanf("%d",&n);
	p = fun(n);
	printf("The elements of the array are: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	
}
int * fun(int n)
{
	int *arr = (int *)malloc(n*sizeof(int));
	printf("enter the %d numbers: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	return arr;
}
