<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("enter the n: ");
	scanf("%d",&n);
	int *a = (int *)malloc(n*sizeof(int));
	printf("enter the %d numbers: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The numbers are: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
=======
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("enter the n: ");
	scanf("%d",&n);
	int *a = (int *)malloc(n*sizeof(int));
	printf("enter the %d numbers: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The numbers are: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
>>>>>>> d470e4cbe347fe6dd8c4b4d11ba6d97cb108f75c
