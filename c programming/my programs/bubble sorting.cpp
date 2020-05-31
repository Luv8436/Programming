<<<<<<< HEAD
//Program for bubble sort
#include<stdio.h>
int main()
{
	int num;
	printf("enter the number of elements: ");
	scanf("%d",&num);
	int arr[num];
	printf("enter the %d numbers into the array:\n",num);
	for(int i = 0 ; i < num ; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int out = 0 ; out < num - 1; out++)
	{
		for(int in = 0 ; in < num - 1 - out ; in++)
		{
			if(arr[in] > arr[in + 1])
			{
				int temp = arr[in];
				arr[in] = arr[in + 1];
				arr[in + 1] = temp;
			}
		}
	}
	printf("The sorted elements are:\n");
	for(int i = 0 ; i < num ; i++)
	{
		printf("%d ",arr[i]);
	}
}
=======
//Program for bubble sort
#include<stdio.h>
int main()
{
	int num;
	printf("enter the number of elements: ");
	scanf("%d",&num);
	int arr[num];
	printf("enter the %d numbers into the array:\n",num);
	for(int i = 0 ; i < num ; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int out = 0 ; out < num - 1; out++)
	{
		for(int in = 0 ; in < num - 1 - out ; in++)
		{
			if(arr[in] > arr[in + 1])
			{
				int temp = arr[in];
				arr[in] = arr[in + 1];
				arr[in + 1] = temp;
			}
		}
	}
	printf("The sorted elements are:\n");
	for(int i = 0 ; i < num ; i++)
	{
		printf("%d ",arr[i]);
	}
}
>>>>>>> d470e4cbe347fe6dd8c4b4d11ba6d97cb108f75c
