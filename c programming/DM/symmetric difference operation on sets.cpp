// program to find symmetric difference operation on two sets
//symmetric difference means all the elements expect common between two sets
#include<stdio.h>
void difference(int firstSet[],int firstNum,int secondSet[],int secondNum);
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
	printf("Elements in symmetric difference of set1 and set2 are:\n");
	// It contains all elements of set1-set2 and set2-set1
	difference(set1,num1,set2,num2);//difference function which prints the elements in set1-set2
	difference(set2,num2,set1,num1);//difference function which prints the elements in set2-set1
}
void difference(int firstSet[],int firstNum,int secondSet[],int secondNum)
{
	int i,j,flag=0;
	for(i=0;i<firstNum;i++)
	{
		for(j=0;j<secondNum;j++)
		{
			if(firstSet[i]==secondSet[j]){
				flag=1;
				break;
			}
			
		}
		if(flag==0){
			printf("%d ",firstSet[i]);
		}
		flag=0;
		
	}
}
