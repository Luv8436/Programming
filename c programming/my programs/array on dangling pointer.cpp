<<<<<<< HEAD
// array on dangling pointer shows error
#include<stdio.h>
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
int *fun(int n)
{
	int arr[n];
	printf("enter the %d numbers: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	return arr;
}
=======
// array on dangling pointer shows error
#include<stdio.h>
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
int *fun(int n)
{
	int arr[n];
	printf("enter the %d numbers: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	return arr;
}
>>>>>>> d470e4cbe347fe6dd8c4b4d11ba6d97cb108f75c
