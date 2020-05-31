//program for deletion of node in linked list having position pos
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
	
	//taking pos from the user
	printf("enter the position of the node to be deleted: ");
	int pos;
	scanf("%d",&pos);
	
	struct student *curr_ptr = start, *prev_ptr = start ;
	
	if(pos ==0)
	{
		start= start->next;
	}
	else{
		while(pos>0)
		{
			prev_ptr = curr_ptr;
			curr_ptr = curr_ptr->next;
			pos = pos - 1;
			
		}
		//deletion of node
		prev_ptr->next = curr_ptr->next;
	}

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
