//linear search using linked list
//find name of student in list
#include<stdio.h>
#include<stdlib.h>
struct student{
	char name[20];
	int age;
	struct student *next;
};
int strCompare(char name[],char key[]);
int lsearch(struct student *start,char key[]);
int main()
{
	int *ans=(int *)malloc(sizeof(int));
	int i=0;
	struct student *start,*end,*newstd;
	printf("Do you want to add a node,enter 1 for yes and 0 for no:  ");
	scanf("%d",ans);
	if(!(*ans))
	{
		printf("linked list is empty ");
		return 0;
	}
	while(*ans)
	{
		if(i==0)
		{
			start=end=(struct student *)malloc(sizeof(struct student));	
			start->next=NULL;
			printf("enter the name of student%d: ",i+1);
			scanf("%s",start->name);
			printf("enter the age of student%d: ",i+1);
			scanf("%d",&start->age);
		}
		else{
			newstd=(struct student *)malloc(sizeof(struct student));
			newstd->next= NULL;
			printf("enter the name of student%d: ",i+1);
			scanf("%s",newstd->name);
			printf("enter the age of student%d: ",i+1);
			scanf("%d",&newstd->age);
			end->next=newstd;
			end=newstd;
		}
		i++;
		printf("Do you want to add a node,enter 1 for yes and 0 for no:  ");
		scanf("%d",ans);	
	}
	char key[20];
	printf("enter the name of the student ,whom to find: \n");
	scanf("%s",key);
	i=lsearch(start,key);
	if(i==0)
	printf("name not found\n");
}
int lsearch(struct student *start,char key[])
{
	struct student *ptr;
	ptr=start;
	int i;
	while(ptr!=NULL)
	{
		i=strCompare(ptr->name,key);
		if(i==1){
		printf("name found\n");
		return 1;
		}
		ptr=ptr->next;
	}
	return 0;
}
int strCompare(char name[],char key[])
{
	int i=0;
	while(name[i]!='\0')
	{
		if(name[i]!=key[i])
		return 0;
		i++;
	}
	return 1;
}
