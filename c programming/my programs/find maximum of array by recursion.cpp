// find maximum of an array by recursion
#include<stdio.h>
int maximum_of_array(int a[],int n,int m);
int main()
{
	int number,i;
	printf("enter the number of elements in array\n");
	scanf("%d",&number);
	int arr[number];
	printf("enter the elements of the array\n");
	for(i=0;i<number;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("elements of the array are\n");
	for(i=0;i<number;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	int max=arr[0];
	max=maximum_of_array(arr+1,number-1,max);
	printf("maximum value of all elements in the array is\n");
	printf("%d ",max);
	
}
int maximum_of_array(int a[],int n,int m)
{
	if(n==0)
	return m;
	else
	{
		if(a[0]>m)
		m=a[0];
		maximum_of_array(a+1,n-1,m);	
	}
}
