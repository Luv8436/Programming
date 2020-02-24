// binary search
#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element you want to search: ");
	int left=0;
	int right=n-1;
	int mid=(left+right)/2;
	int item;
	scanf("%d",&item);
	
	while(left<=right)
	{
		if(arr[mid]==item)
		{
		printf("Search successfull\nelement found at index %d index",mid);
		return 0;
		}
		else if(item>arr[mid])
		{
			left=mid+1;	
		}
		if(item<arr[mid])
		{
			right=mid-1;	
		}
		mid=(left+right)/2;
	}
	printf("Search unsuccessfull");
	return 0;	
}
