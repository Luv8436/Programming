#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *left;
	int data;
	struct student *right;
};
void create_tree(struct student **ptr);
struct student *root = NULL;
int main()
{
	create_tree(&root);
	printf("root->data = %d\n",root->data);
	printf("root->left->data = %d\n",root->left->data);
	printf("root->right->data = %d\n",root->right->data);	
}
void create_tree(struct student **ptr)
{
	char c;
	*ptr = (struct student *)malloc(sizeof(struct student));
	printf("enter the data: ");
	scanf("%d",&((*ptr)->data));
	((*ptr)->left) = NULL;
	((*ptr)->right) = NULL;
	printf("do you want to enter the left element(y/n): ");
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->left));
		printf("\n");
	}
	printf("do you want to enter the right element(y/n): ");
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->right));
		printf("\n");
	}
	return ;
}

