//implementing stack through array
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	printf("Do you want to perform operations on stack Press yes or no\n");
	char *ans=(char * )malloc(sizeof(char)*4);
	scanf("%s",ans);
	int arr[100];
	int TOS=-1;
	while(strcmp(ans,"yes"))
	{
		printf("Press 1 for PUSH operation\nPress 2 for POP operation\n");
		int operation;
		scanf("%d",&operation);
		int number;
		if(operation==1)
		{
			TOS=TOS+1;
			printf("Enter the number to be pushed into stack  ");
			scanf("%d",&number);
			arr[TOS]=number;
			printf("%d is pushed in the stack  \n",number);
		}
		else if(operation==2){
		TOS=TOS-1;
		printf("%d is popped from the stack  \n",number);
		}
		printf("Press yes or no\n");
		scanf("%d",&ans);	
	}
	printf("the elements of stack are: \n");
	for(int i=0;i<TOS+1;i++)
	{
		printf("%d ",arr[i]);
	}
}
