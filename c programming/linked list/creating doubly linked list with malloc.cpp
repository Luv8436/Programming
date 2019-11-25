//doubly linked list with malloc
#include<stdio.h>
#include<stdlib.h>
struct point{
	struct point *prev;
	int x;
	int y;
	struct point *next;
};
struct point* append(struct point *p1,struct point *p2);
struct point* createPoint();
int main()
{
	struct point *start,*end,*newpt;
	int num;
	printf("enter the number of points: ");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		if(i==0)
		{
			start=end=createPoint();
		}
		else{
			newpt=createPoint();
			end=append(end,newpt);
		}
	}
	newpt=start;
	int i=1;
	// printing via forward traversing
	while(newpt!=NULL)
	{
		printf("Point%d is (%d,%d)\n",i,newpt->x,newpt->y);
		newpt=newpt->next;
		i++;
	}
	printf("\n");
	//printing via backward traversing
	newpt=end;
	while(newpt!=NULL)
	{
		printf("Point%d is (%d,%d)\n",i,newpt->x,newpt->y);
		newpt=newpt->prev;
		i++;
	}
}
struct point* createPoint(){
	struct point *ptr=(struct point *)malloc(sizeof(struct point));
	printf("enter the x coordinate of point: ");
	scanf("%d",&ptr->x);
	printf("enter the y coordinate of point: ");
	scanf("%d",&ptr->y);
	ptr->next=NULL;
	ptr->prev=NULL;
}
struct point* append(struct point *p1,struct point *p2)
{
	p1->next=p2;
	p2->prev=p1;
	return p2;
	
}
