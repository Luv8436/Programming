//reverse the singly linked list
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
	printf("linked list before reversing: ");
	while(newstd!=NULL)
	{
		printf("%d ",newstd->grade);
		newstd=newstd->next;
	}
	//reversing the linked list
	printf("\nlinked list after reversing: ");
	struct student *middle = NULL;
	if(start->next==NULL)
	{
		printf("%d",start->grade);
	}
	else{
		newstd=start;
		start = start->next;
		newstd->next = NULL;
		while(start!=NULL)
		{
			middle = start ;
			start = start->next;
			middle->next = newstd;
			newstd = middle;
		}
		start = newstd;
		//printing the reversed linked list
		newstd=start;
		while(newstd!=NULL)
		{
			printf("%d ",newstd->grade);
			newstd=newstd->next;
		}
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
