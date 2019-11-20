// reversing of an array using recursion
#include<stdio.h>
void reverse_array(int a[],int n);
void swap(int a[],int n);
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
	reverse_array(arr,number);
	printf("elements of the reversed array are\n");
	for(int i=0;i<number;i++)
	{
		printf("%d ",arr[i]);
	}

}
void reverse_array(int a[],int n)
{
	if(n==1 || n==0)
	{
		if(n==0)
	 	printf("array is empty\n");
	}
	else{
		swap(a,n);
		reverse_array(a+1,n-2);
	}
	
}
void swap(int a[],int n)
{
	int *b=a+n-1;
	int temp=*a;
	*a=*b;
	*b=temp;
}

