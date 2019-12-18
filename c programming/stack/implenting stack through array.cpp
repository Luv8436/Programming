//implementing stack through array
#include<stdio.h>
int main()
{
	printf("Do you want to perform operations on stack\nPress 1 for yes\nPress 2 for no\n");
	int ans;
	scanf("%d",&ans);
	int arr[100];
	int TOS=-1;
	while(ans==1)
	{
		printf("Press 3 for PUSH operation\nPress 4 for POP operation\n");
		int operation;
		scanf("%d",&operation);
		int number;
		if(operation==3)
		{
			TOS=TOS+1;
			printf("Enter the number to be pushed into stack  ");
			scanf("%d",&number);
			arr[TOS]=number;
			printf("%d is pushed in the stack  \n",number);
		}
		else if(operation==4){
		TOS=TOS-1;
		printf("%d is popped from the stack  \n",number);
		}
		printf("Press 1 for yes\nPress 2 for no\n");
		scanf("%d",&ans);	
	}
	printf("the elements of stack are: \n");
	for(int i=0;i<TOS+1;i++)
	{
		printf("%d ",arr[i]);
	}
}
