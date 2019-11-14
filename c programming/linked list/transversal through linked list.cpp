#include<stdio.h>
#include<stdlib.h>
struct student{
	int age;
	struct student *next;
};
struct student* createStructure(int num);
struct student* append(struct student *ptr1,struct student *ptr2);
void printAge(struct student* start);
int main()
{
	int num,i;
	printf("Enter the number of students: ");
	scanf("%d",&num);
	struct student *start,*end,*newptr;
	int age;
	for(i=0;i<num;i++){
		printf("enter student%d age: ",i+1);
		scanf("%d",&age);
		if(i==0){
			start=end=createStructure(age);
			
		}
		else{
			newptr=createStructure(age);
			end=append(end,newptr);
		}
	}
	printAge(start);
}
struct student* createStructure(int num){
	struct student* ptr;
	ptr=(struct student *)malloc(sizeof(struct student));
	ptr->age=num;
	ptr->next=NULL;
	return ptr;
}
struct student* append(struct student *ptr1,struct student *ptr2){
	ptr1->next=ptr2;
	return ptr2;
}
void printAge(struct student* start){
	struct student *ptr=start;
	int i=1;
	while(ptr!=NULL){
		printf("The age of student%d is %d\n",i,ptr->age);
		i++;
		ptr=ptr->next;
	}
}
