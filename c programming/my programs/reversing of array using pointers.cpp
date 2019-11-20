// program for reversing of an array by pointers
#include <stdio.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int main(void) {
	int number,i;
	printf("enter the number of elements in array\n");
	scanf("%d",&number);
	int arr[number];
	printf("enter the elements of the array\n");
	for(i=0;i<number;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<number;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	int *left=arr;
	int *right=arr+number-1;
	while(left<right){
		swap(left,right);
		left++;
		right--;
	}
	for(i=0;i<number;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}


