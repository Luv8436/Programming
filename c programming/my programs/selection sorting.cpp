// Program for selection sorting 
#include<stdio.h>
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
	// outer loop 
	for(int i = 0 ; i < n - 1 ; i++)
	{
		// taking small variable to arr[i]
		int small = arr[i];
		int index = i;
		// inner loop
		for(int j = i + 1 ; j < n ; j++)
		{
			if(small > arr[j])
			{
				small = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = small;
		arr[index] = temp;
	}
	
	// print the loop
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
}

