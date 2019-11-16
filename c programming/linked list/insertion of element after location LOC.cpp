//program for insertion of linked list
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
	//insert a new node after location LOC
	int item;
	printf("\nenter the item to be added: ");
	scanf("%d",&item);
	//create a new node and store item in this node
	struct student *newptr=createStudent(item);
	struct student *LOC=NULL;
	printf("enter the LOC ");
	scanf("%p",LOC);
	printf("LOC= %p\n",LOC);
	printf("value at location LOC: ");
	printf("%d\n",&LOC->grade);
	newptr->next=LOC->next;
	LOC->next=newptr;
	//print linked list
	struct student* newpointer=start;
	while(newpointer!=NULL)
	{
		printf("%d ",newpointer->grade);
		newpointer=newpointer->next;
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
