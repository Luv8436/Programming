<<<<<<< HEAD
// creating doubly linked list by taking input from the user at run time
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *prev;
	char name[20];
	int grade;
	struct student *next;
};
struct student * createstd(void);
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
	//printing linkedlist traversing from r to l
	newstd = end;
	printf("\nStudent Record:\n");
	while(newstd!= NULL)
	{
		printf("the name of the student is: %s and grade = %d\n",newstd->name,newstd->grade);
		newstd = newstd->prev;
	}
	
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
=======
// creating doubly linked list by taking input from the user at run time
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *prev;
	char name[20];
	int grade;
	struct student *next;
};
struct student * createstd(void);
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
	//printing linkedlist traversing from r to l
	newstd = end;
	printf("\nStudent Record:\n");
	while(newstd!= NULL)
	{
		printf("the name of the student is: %s and grade = %d\n",newstd->name,newstd->grade);
		newstd = newstd->prev;
	}
	
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
>>>>>>> d470e4cbe347fe6dd8c4b4d11ba6d97cb108f75c
