// creating of a doubly linked list
#include<stdio.h>
struct student{
	struct student *prev;
	int age;
	struct student *next;
};
int main()
{
	struct student *start=NULL;
	//declaring of structures
	struct student std1={NULL,21,NULL};
	struct student std2={NULL,22,NULL};
	struct student std3={NULL,23,NULL};
	// linking of structures
	start=&std1;
	std1.next=&std2;
	std2.next=&std3;
	std3.next=NULL;
	std3.prev=&std2;
	std2.prev=&std1;
	struct student *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->age);
		ptr=ptr->next;
	}
	
	
}
