<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *left;
	int data;
	struct student *right;
};
struct student *root = NULL;
void create_tree(struct student **ptr);
void inorder_traversing(struct student *root);
int main()
{
	create_tree(&root);
	inorder_traversing(root);	
}
void create_tree(struct student **ptr)
{
	char c;
	*ptr = (struct student *)malloc(sizeof(struct student));
	printf("enter the data: ");
	scanf("%d",&((*ptr)->data));
	((*ptr)->left) = NULL;
	((*ptr)->right) = NULL;
	printf("do you want to enter the element left to %d(y/n): ",(*ptr)->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->left));
		printf("\n");
	}
	printf("do you want to enter the element right to %d(y/n): ",(*ptr)->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->right));
		printf("\n");
	}
	return ;
}
void inorder_traversing(struct student *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
	}
	if(root->left != NULL)
	{
		inorder_traversing(root->left);
	}
	if(root->right != NULL)
	{
		inorder_traversing(root->right);
	}
}
=======
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *left;
	int data;
	struct student *right;
};
struct student *root = NULL;
void create_tree(struct student **ptr);
void inorder_traversing(struct student *root);
int main()
{
	create_tree(&root);
	inorder_traversing(root);	
}
void create_tree(struct student **ptr)
{
	char c;
	*ptr = (struct student *)malloc(sizeof(struct student));
	printf("enter the data: ");
	scanf("%d",&((*ptr)->data));
	((*ptr)->left) = NULL;
	((*ptr)->right) = NULL;
	printf("do you want to enter the element left to %d(y/n): ",(*ptr)->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->left));
		printf("\n");
	}
	printf("do you want to enter the element right to %d(y/n): ",(*ptr)->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		create_tree(&((*ptr)->right));
		printf("\n");
	}
	return ;
}
void inorder_traversing(struct student *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
	}
	if(root->left != NULL)
	{
		inorder_traversing(root->left);
	}
	if(root->right != NULL)
	{
		inorder_traversing(root->right);
	}
}
>>>>>>> d470e4cbe347fe6dd8c4b4d11ba6d97cb108f75c
