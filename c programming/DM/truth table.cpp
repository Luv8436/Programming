//program for boolean truth table of AND, OR, and NOT gate
#include<stdio.h>
int main()
{
	int i;
	printf("enter the value for following given operations:\n1 for OR gate.\n2 for AND gate.\n3 for NOT gate\n");
	scanf("%d",&i);
	int A,B;
	switch(i)
	{
		case 1: printf("enter the value of A:\n");
			scanf("%d",&A);
			printf("enter the value of B:\n");
			scanf("%d",&B);
			if(A+B==2){
				printf("Truth value of A and B in OR gate is: 1");
			}
			else{
				printf("Truth value of A and B in OR gate is: %d",A+B);
			}
			break;
		case 2: printf("enter the value of A:\n");
			scanf("%d",&A);
			printf("enter the value of B:\n");
			scanf("%d",&B);
			printf("Truth value of A and B in AND gate is: %d",A*B);
			break;
		case 3: printf("enter the value of A:\n");
			scanf("%d",&A);
			if(A==1){
				printf("Truth value of A and B in NOT gate is: 0");
			}
			else{
				printf("Truth value of A and B in AND gate is: 1");
			}
	}
}
