// find maximum of an array by recursion
#include<stdio.h>
int maximum_of_array(int a[],int n);
int maximum(int a,int b);
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
	int max;
	max=maximum_of_array(arr,number);
	printf("maximum value of all elements in the array is\n");
	printf("%d ",max);
	
}
int maximum_of_array(int a[],int n)
{
	int max;
	if(n==0)
	return a[0];
	
	
	max=maximum_of_array(a+1,n-1);
	return maximum(a[0],max);	
	
}
int maximum(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
