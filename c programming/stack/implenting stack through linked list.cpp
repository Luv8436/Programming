//implementing stack through linked list
#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int data;
	struct Stack *next;
	struct Stack *prev;
};
struct Stack * push(int number);
struct Stack * append(struct Stack *ptr1,struct Stack *ptr2);
int main()
{
	printf("Do you want to perform operations on stack\nPress 1 for yes\nPress 2 for no\n");
	int ans;
	scanf("%d",&ans);
	struct Stack *start=NULL,*end=NULL,*newptr=NULL;
	while(ans==1)
	{
		printf("Press 3 for PUSH operation\nPress 4 for POP operation\n");
		int operation;
		scanf("%d",&operation);
		int number;
		if(operation==3)
		{
			printf("Enter the number to be pushed into stack  ");
			scanf("%d",&number);
			newptr=push(number);
			if(start==NULL)
			{
				start=end=newptr;	
			}
			else{
				end=append(end,newptr);
			}
			
			printf("%d is pushed in the stack  \n",number);
		}
		else if(operation==4){
		end->prev->next=NULL;
		printf("%d is popped from the stack  \n",number);
		}
		printf("Press 1 for yes\nPress 2 for no\n");
		scanf("%d",&ans);	
	}
	printf("the elements of stack are: \n");
	while(start!=NULL)
	{
		printf("%d ",start->data);
		newptr=start;
		start=start->next;
		free(newptr);
	}
	
	
}
struct Stack * push(int number)
{
	struct Stack *newptr=NULL;
	newptr=(struct Stack *)malloc(sizeof(struct Stack));
	newptr->data=number;
	newptr->next=NULL;
	newptr->prev=NULL;
	return newptr;
}
struct Stack * append(struct Stack *ptr1,struct Stack *ptr2)
{
	ptr1->next=ptr2;
	ptr2->prev=ptr1;
	return ptr2;
}
