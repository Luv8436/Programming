// insertion of element in an array after position pos
#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements of array: ");
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
}
