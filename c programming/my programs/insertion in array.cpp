// insert an element in array
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
	printf("enter the item and position of insertion: ");
	int item,pos;
	scanf("%d %d",&item,&pos);
	int newArr[n+1];
	for(int i=0;i<pos;i++)
	{
		newArr[i]=arr[i];
	}
	newArr[pos]=item;
	for(int i=pos;i<n;i++)
	{
		newArr[i+1]=arr[i];
	}
	for(int i=0;i<n+1;i++)
	{
		printf("%d ",newArr[i]);
	}
	
}
