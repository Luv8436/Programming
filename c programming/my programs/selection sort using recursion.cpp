// Program for selection sorting by recursion
#include<stdio.h>
void selection_sort(int *arr , int n);
int main()
{
	int n ;
	printf("enter the number of elements in array: ");
	scanf("%d",&n);
	printf("enter the %d elements: ",n);
	int arr[n];
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&arr[i]);
	} 
	selection_sort(arr , n);
	
	// print the array
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
}
void selection_sort(int *arr , int n)
{
	if(n==1)
	return ;
	else
	{
		int small = arr[0];
		int index = 0;
		for(int i = 1 ; i < n ; i++)
		{
			if(small > arr[i])
			{
				small = arr[i];
				index = i;
			}
		}
		int temp = arr[0];
		arr[0] = small;
		arr[index] = temp;
		
		selection_sort(arr+1 , n-1);
	}
}

