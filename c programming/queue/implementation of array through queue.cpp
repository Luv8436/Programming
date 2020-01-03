//implementing of linear queue through array
#include<stdio.h>
int main()
{
	int imax=100;
	int arr[imax];
	int front=0,end=0;
	int x,y;
	printf("enter 1 for enqueue and 2 for dequeue and 3 for exit :");
	scanf("%d",&x);
	while(x==1||x==2)
	{
		if(x==1)
		{
			if(end == imax)
			{
				printf("the queue is full\n");
				break;
			}
			printf("enter the element to push  :");
			scanf("%d",&y);
			arr[end]=y;
			end=end+1;
		}
		if(x==2)
		{
			if(front == 0)
			{
				printf("The queue is empty\n");
				break;
				
			}
			front=front +1;
		}
		printf("enter 1 for enqueue and 2 for dequeue and 3 for exit :");
		scanf("%d",&x);
	}
	for(int i=front;i<end;i++)
	{
		printf("%d",arr[i]);
	}
	
	
}
