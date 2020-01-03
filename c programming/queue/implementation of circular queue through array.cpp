//implementing of circular queue through array
#include<stdio.h>
int main()
{
	int imax=10;
	int arr[imax];
	int front=0,end=0;
	int x,y;
	printf("enter 1 for enqueue and 2 for dequeue and 3 for exit :");
	scanf("%d",&x);
	while(x==1||x==2)
	{
		if(x==1)
		{
			if(front == (end+1)%imax)
			{
				printf("the queue is full\n");
				break;
			}
			printf("enter the element to push  :");
			scanf("%d",&y);
			if(front == 0 && end == 0)
			{
				arr[end]=y;
			}
			else
			{
				end = (end +1)/imax;
				arr[end]=y;
			}
	
		}
		if(x==2)
		{
			if(front == 0 && end == 0){
				printf("The queue is empty\n");
				return 0;
			}
			front=front +1;
		}
		printf("enter 1 for enqueue and 2 for dequeue and 3 for exit :");
		scanf("%d",&x);
	}
	if(end>front)
	{
		for(int i=front;i<=end;i++)
		{
			printf("%d",arr[i]);
		}
	}
	else{
		for(int i=front;i<imax;i++)
		{
			printf("%d",arr[i]);
		}
		for(int i=0;i<=end;i++){
			printf("%d",arr[i]);
		}	
	}
	
	
}
