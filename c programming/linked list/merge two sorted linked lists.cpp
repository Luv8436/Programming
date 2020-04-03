//program for merging two sorted linked lists
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int age;
	struct student *next;
};
// creating list1 starting pointer as global
struct student *start1 = NULL;
struct student* createStructure(int num);
struct student * create_list(int number);
struct student* append(struct student *ptr1,struct student *ptr2);
void printAge(struct student* start);
void free_list(struct student *start);
struct student * insert(struct student *data , struct student *start);
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
	struct student *start2 = create_list(num2);
	// printing list 1
	printf("The ages of student in class1 are :\n");
	printAge(start1);
	printf("\n");
	//printing list 2
	printf("The ages of student in class2 are :\n");
	printAge(start2);
	printf("\n");
	
	struct student *ptr = NULL;
	// extracting nodes one by one from linked list2 
	// and insert them into linked list1
	struct student *start = start1;
	while(start2!=NULL)
	{
		ptr = start2;
		start2 = start2->next;
		// insert the node ptr into linked list
		start = insert(ptr , start);
		//printing the list after combining
	}
	printf("\nThe ages of students are: ");
	printAge(start1);
	//free memory on the heap
	free_list(start1);
	free_list(start2);
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
//insert the struct pointer data into the list from current pointer start
struct student* insert(struct student *data , struct student *start)
{
	struct student *prev = start;
	while((start!=NULL)&&(data->age > start->age))
	{
		prev = start ;
		start = start->next ;
	}
	if(start == NULL)
	{
		prev->next = data;
		data->next = NULL;
		return prev;
	}
	if(prev == start1)
	{
		data->next = start1;
		start1 = data;
		return start1;
	}
	else
	{
		data->next = start;
		prev->next = data;
		return prev;
	}
}
