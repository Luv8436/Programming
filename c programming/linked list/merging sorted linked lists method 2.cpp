//program for merging two sorted linked lists by creating sorted list.
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int age;
	struct student *next;
};
// creating list1 starting pointer as global
struct student *start1 = NULL;
struct student *start2 = NULL;
struct student* createStructure(int num);
struct student * create_list(int number);
struct student* append(struct student *ptr1,struct student *ptr2);
void printAge(struct student* start);
void free_list(struct student *start);
struct student * compare(struct student *list1 , struct student *list2);
int main()
{
	// number of students in each lists
	int num1,num2;
	printf("Enter the number of students in class1: ");
	scanf("%d",&num1);
	// creating list 1
	start1 = create_list(num1);
	printf("Enter the number of students in class2: ");
	scanf("%d",&num2);
	//creating list 2
	start2 = create_list(num2);
	// printing list 1
	printf("The ages of student in class1 are :\n");
	printAge(start1);
	printf("\n");
	//printing list 2
	printf("The ages of student in class2 are :\n");
	printAge(start2);
	printf("\n");
	struct student *start3 = NULL;
	// comparing first elements of both linked lists 
	// and return pointer to the node
	struct student *ptr = NULL , *end = NULL;
	//merge the list until all nodes from the lists are deleted
	while(start1!=NULL || start2 != NULL)
	{
		// return the smallest element in the list
		ptr = compare(start1 , start2);
		if(start3 == NULL)
		{
			start3 = end = ptr;
		}
		else
		{
			end->next = ptr;
			end = ptr;
		}
	}
	//printing the merged linked lists
	printf("The ages of students are :\n");
	printAge(start3);
	
	//free memory on the heap
	free_list(start1);
	free_list(start2);
	free_list(start3);
}
//create node and return pointer to structure
struct student* createStructure(int num){
	struct student* ptr;
	ptr=(struct student *)malloc(sizeof(struct student));
	ptr->age=num;
	ptr->next=NULL;
	return ptr;
}
// link the previous and current nodes
struct student* append(struct student *ptr1,struct student *ptr2)
{
	ptr1->next=ptr2;
	return ptr2;
}
// print the numbers in list starting from start pointer
void printAge(struct student* start)
{
	struct student *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->age);
		ptr=ptr->next;
	}
}
//create the linked list 
struct student * create_list(int number)
{
	struct student *start,*end,*newptr;
	int age;
	for(int i=0;i<number;i++)
	{
		printf("enter student%d age: ",i+1);
		scanf("%d",&age);
		if(i==0)
		{
			start=end=createStructure(age);
		}
		else
		{
			newptr=createStructure(age);
			end=append(end,newptr);
		}
	}
	return start;
}
// free memory
void free_list(struct student *start)
{
	struct student *ptr = start ;
	while(start!=NULL)
	{
		start = start->next;
		free(ptr);
		ptr = start ;
	}
}
struct student * compare(struct student *list1 , struct student *list2)
{
	struct student *ptr = NULL;
	if(list1 == NULL || list2 == NULL)
	{
		if(list1 == NULL)
		{
			ptr = start2;
			start2 = start2->next;
			return ptr;
		}
		if(list2 == NULL)
		{
			ptr = start1;
			start1 = start1->next;
			return ptr;
		}
	}
	else
	{
		if(start1->age < start2->age)
		{
			ptr=start1;
			start1 = start1->next;
			return ptr;
		}
		else
		{
			ptr=start2;
			start2= start2->next;
			return ptr;
		}
	}
}
