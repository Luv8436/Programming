//finding the length of linked list recursively
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *prev;
	char name[20];
	int grade;
	struct student *next;
};
struct student * createstd(void);
void list_length(struct student *ptr);
int length=0; // global variable to find length of linked list 
int main()
{
	char c;
	printf("Do you to add a student , enter(y/n): ");
	scanf("%c",&c);
	struct student *start=NULL , *end=NULL , *newstd=NULL;
	int flag = 0;
	//creating doubly linked list
	while(c=='y')
	{
		newstd = createstd();
		if(flag == 0)
		{
			flag = 1;
			start = end = newstd;
		}
		else{
			end->next = newstd;
			newstd->prev = end;
			end = newstd;
		}
		printf("Do you want to add a student , enter(y/n): ");
		scanf(" %c",&c); // the space before format specifier is very important for input
		
	}
	//printing linkedlist traversing from l to r
	newstd = start;
	printf("Student Record:\n");
	while(newstd!= NULL)
	{
		printf("the name of the student is: %s and grade = %d\n",newstd->name,newstd->grade);
		newstd = newstd->next;
	}
	newstd = start;
	list_length(newstd);
	printf("The length of the linked list is %d.",length);
	
	//free the memory on heap
	
	newstd = start;
	while(start!=NULL)
	{
		start=start->next;
		free(newstd);
		newstd = start;
	}
	
}
struct student * createstd(void)
{
	struct student *ptr = (struct student *)malloc(sizeof(struct student));
	printf("enter the name of the student: ");
	scanf("%s",ptr->name);
	printf("enter the grade: ");
	scanf("%d",&ptr->grade);
	ptr->next = NULL;
	ptr->prev = NULL;	
	return ptr;
}
void list_length(struct student *ptr)
{
	if(ptr == NULL)
	return ;
	else{
		length = length + 1;
		list_length(ptr->next);
	}
}
