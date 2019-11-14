//cartesian product of two sets
#include<stdio.h>
int main()
{
	int num1,i;// number of elements in set1.
	printf("enter the number of elements in set1(A)\n");
	scanf("%d",&num1);
	int set1[num1];
	printf("enter the elements of A ");
	for(i=0;i<num1;i++){//take elements of set1
	scanf("%d",&set1[i]);
	}
	int num2;// number of elements in set2.
	printf("enter the number of elements in set2(B)\n");
	scanf("%d",&num2);
	int set2[num2];
	printf("enter the elements of B ");
	for(i=0;i<num2;i++){//take elements of set1
	scanf("%d",&set2[i]);
	}
	//finding AXB
	printf("elements in AXB are:\n");
	int j;
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			printf("(%d,%d) ",set1[i],set2[j]);
		}
	}
}
