// program to find a key in an array using recursion
#include<stdio.h>
void search(int *a,int n , int key);
int main()
{
	int len;// length of array
	printf("enter the length of array\n");
	scanf("%d",&len);
	int arr[len];
	printf("enter the elements in the array\n");
	int i=0;
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	int key;
	printf("enter the number to be searched\n");
	scanf("%d",&key);
	search(arr , len , key);
}
void search(int *a,int n,int item)
{
	if(n==0)
	printf("search unsuccessfull\n");
	else{
	if(a[0]==item)
	printf("search successfull\n");
	else
	search(a+1,n-1,item);
		}
}
