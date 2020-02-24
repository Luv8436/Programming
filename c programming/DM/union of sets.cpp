// program to form intersection on two sets
#include<stdio.h>
int main()
{
	int num1,i;// number of elements in set1.
	printf("enter the number of elements in set1\n");
	scanf("%d",&num1);
	int set1[num1];
	printf("enter the elements of set1 ");
	for(i=0;i<num1;i++){
	scanf("%d",&set1[i]);
	}
	int num2;// number of elements in set2.
	printf("enter the number of elements in set2\n");
	scanf("%d",&num2);
	int set2[num2];
	printf("enter the elements of set2 ");
	for(i=0;i<num2;i++){
	scanf("%d",&set2[i]);
	}
	int j,temp=0;
	printf("The elements in union of set1 and set2 are:\n");
	for(i=0;i<num1;i++){// printing the elements of set1 which are not in set2
		for(j=0;j<num2;j++){
			if(set1[i]==set2[j])
			{
				temp=1;
				break;
			}
		}
		if(temp==0){
			printf("%d ",set1[i]);
		}
		temp=0;
	}//then prints all the elements of set2
	for(i=0;i<num2;i++){
		printf("%d ",set2[i]);
	}
}


