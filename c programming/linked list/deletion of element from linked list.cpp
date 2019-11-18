//program for deletion of node in linked list having item
#include<stdio.h>
#include<stdlib.h>
struct student{
	int grade;
	struct student *next;
};
struct student * createStudent(int x);
int main()
{
	printf("enter the number of student: ");
	int num,grade,i;
	scanf("%d",&num);
	if(num==0)
	{
		printf("linked list is empty");
	}
	struct student *start,*end,*newstd;
	for(i=0;i<num;i++)
	{
		printf("enter the grade of student%d: ",i+1);
		scanf("%d",&grade);
		if(i==0)
		{
			start=end=createStudent(grade);
		}
		else{
			newstd=createStudent(grade);
			end->next=newstd;
			end=newstd;
		}
	}
	//printing linked list
	newstd=start;
	while(newstd!=NULL)
	{
		printf("%d ",newstd->grade);
		newstd=newstd->next;
	}
	//delete a node having item 
	int item;
	printf("\nenter the item you want to delete: ");
	scanf("%d",&item);
	struct student *currPtr;
	currPtr=start;
	struct student *prevPtr=start;
	//transversal till getting the item
	while(currPtr->grade!=item&&currPtr!=NULL)
	{
		prevPtr=currPtr;
		currPtr=currPtr->next;
		if(currPtr==NULL)
		break;
	}
	if(currPtr==NULL)
	{
		printf("item is not present in linked list");
		return 0;
	}
	//deletion of node
	prevPtr->next=currPtr->next;
	//printing linked list
	newstd=start;
	while(newstd!=NULL)
	{
		printf("%d ",newstd->grade);
		newstd=newstd->next;
	}
	return 0;
	
}
struct student* createStudent(int x)
{
	struct student *ptr;
	ptr=(struct student *)malloc(sizeof(struct student));
	ptr->next=NULL;
	ptr->grade=x;
	return ptr;
}
