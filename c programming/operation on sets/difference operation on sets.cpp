//program to find difference operation on two sets
//difference of setA and setB is made of elements which are in setA and not setB
#include<stdio.h>
int main()
{
	int num1,i;// number of elements in set1.
	printf("enter the number of elements in set1\n");
	scanf("%d",&num1);
	int set1[num1];
	printf("enter the elements of set1 ");
	for(i=0;i<num1;i++){//take elements of set1
	scanf("%d",&set1[i]);
	}
	int num2;// number of elements in set2.
	printf("enter the number of elements in set2\n");
	scanf("%d",&num2);
	int set2[num2];
	printf("enter the elements of set2 ");
	for(i=0;i<num2;i++){//take elements of set1
	scanf("%d",&set2[i]);
	}
	//set1-set2 operation on sets
	int j,flag=0;
	printf("set1-set2= { ");
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			if(set1[i]==set2[j]){
				flag=1;
				break;
			}
			
		}
		if(flag==0){
			printf("%d ",set1[i]);
		}
		flag=0;
		
	}
	printf(" }");
}
