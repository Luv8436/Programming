//swapping nodes of a linked list without changing data fields
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
	printf("\nThe grades of the student are: ");
	while(newstd!=NULL)
	{
		printf("%d ",newstd->grade);
		newstd=newstd->next;
	}
	//values to swap
	int val1,val2;
	printf("\nenter the values to be swapped: ");
	scanf("%d %d",&val1,&val2);
	//finding the first node to be swapped
	newstd = start;
	struct student *prev = start;
	while((newstd->grade!=val1)&&(newstd->grade!=val2))
	{
		prev = newstd;
		newstd = newstd->next;
	}
	//if the values are adjacent
	if((newstd->next->grade==val1)||(newstd->next->grade==val2))
	{
		if(newstd!=prev)
		{
			prev->next = newstd->next;
			struct student *temp = newstd->next->next;
			newstd->next->next = newstd;
			newstd->next = temp;
		}
		else{
			start = newstd->next;
			prev = start->next;
			start->next = newstd;
			newstd->next = prev;	
		}
		
	}
	//there is exactly one node between these two nodes
	else if((newstd->next->next->grade==val1)||(newstd->next->next->grade==val2))
	{
		if(newstd!=prev)
		{
			prev->next = newstd->next->next;
			struct student *temp = prev->next->next;
			prev->next->next = newstd->next;
			newstd->next->next = newstd;
			newstd->next = temp;
			
		}
		else{
			struct student *temp = newstd->next->next;
			start = temp;
			prev = temp->next;
			temp->next = newstd->next;
			newstd->next->next = newstd;
			newstd->next = prev;
		}
	}
	// if there are two or more nodes between 
	else
	{
		if(newstd!=prev)
		{
			struct student *temp = newstd->next , *ptr1 = newstd , *ptr2 = NULL;
			while((temp->grade!=val1)&&(temp->grade!=val2))
			{
				ptr1 = ptr1->next;
				temp = temp->next;
			}
			ptr2 = temp->next;
			prev->next = temp;
			temp->next = newstd->next;
			ptr1->next = newstd;
			newstd->next = ptr2;
		}
		else
		{
			struct student *temp = newstd->next;
			while((temp->grade!=val1)&&(temp->grade!=val2))
			{
				prev = prev->next;
				temp = temp->next;
			}
			start = temp;
			struct student *ptr = temp->next;
			temp->next = newstd->next;
			prev->next = newstd;
			newstd->next = ptr;
		}
			
	}
	struct student *newptr = start ;
	//printing the values after swappping of nodes
	printf("\nThe values of nodes after swapping are: \n");
	while(newptr!=NULL)
	{
		printf("%d ",newptr->grade);
		newptr = newptr->next;
	}
	//free the memory allocated on the heap
	while(start!=NULL)
	{
		prev = start;
		start = start->next;
		free(prev);
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
