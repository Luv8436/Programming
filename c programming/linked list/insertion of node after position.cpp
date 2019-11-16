//program for insertion of linked list after position
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
	//insert a new node after position
	int item;
	printf("\nenter the item to be added: ");
	scanf("%d",&item);
	printf("enter the position: ");
	int pos;
	struct student *newptr=createStudent(item);
	scanf("%d",&pos);
	newstd=start;
	i=1;
	if(pos==0)
	{
		newptr->next=start;
		start=newptr;	
	}
	else{
	while(i<pos)
	{
		newstd=newstd->next;
		i++;
	}
	newptr->next=newstd->next;
	newstd->next=newptr;
	}
	printf("\n");
	//printing linked list
	newstd=start;
	while(newstd!=NULL)
	{
		printf("%d ",newstd->grade);
		newstd=newstd->next;
	}
	
}
struct student* createStudent(int x)
{
	struct student *ptr;
	ptr=(struct student *)malloc(sizeof(struct student));
	ptr->next=NULL;
	ptr->grade=x;
	return ptr;
}
