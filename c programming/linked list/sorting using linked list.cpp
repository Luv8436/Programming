//sorting of elements in linked list
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
	printf("\n");
	struct student *curr,*add_small=start,*prev;
	curr=start;
	prev=start;
	while(prev!=NULL)
	{
		curr=prev;
		int small=prev->grade;
		add_small=prev;
		while(curr!=NULL)
		{
			if(small>curr->grade)
			{
			small=curr->grade;
			add_small=curr;
			}
			curr=curr->next;
		}
		add_small->grade=prev->grade;
		prev->grade=small;
		prev=prev->next;
	}
	//printing of linked list
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
