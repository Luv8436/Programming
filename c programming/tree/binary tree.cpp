<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
struct student{
	struct student *left ;
	int data;
	struct student *right;
};
struct student *create_tree();
void inorder_traversing(struct student *root);
int main()
{
	struct student *root = NULL;
	root = create_tree();
	printf("The inorder traversing of the binary tree is :\n");
	inorder_traversing(root);
}
struct student *create_tree()
{
	char c;
	struct student *rootptr =(struct student *)malloc(sizeof(struct student));
	rootptr->left = NULL;
	rootptr->right = NULL;
	printf("enter the data: ");
	scanf("%d",&rootptr->data);
	printf("do you want to enter element left to %d(y/n): ",rootptr->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		rootptr->left = create_tree();
		printf("\n");
	}
	printf("do you want to enter element right to %d(y/n): ",rootptr->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		rootptr->right = create_tree();
		printf("\n");
	}
	return rootptr;
	
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
	struct student *left ;
	int data;
	struct student *right;
};
struct student *create_tree();
void inorder_traversing(struct student *root);
int main()
{
	struct student *root = NULL;
	root = create_tree();
	printf("The inorder traversing of the binary tree is :\n");
	inorder_traversing(root);
}
struct student *create_tree()
{
	char c;
	struct student *rootptr =(struct student *)malloc(sizeof(struct student));
	rootptr->left = NULL;
	rootptr->right = NULL;
	printf("enter the data: ");
	scanf("%d",&rootptr->data);
	printf("do you want to enter element left to %d(y/n): ",rootptr->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		rootptr->left = create_tree();
		printf("\n");
	}
	printf("do you want to enter element right to %d(y/n): ",rootptr->data);
	scanf(" %c",&c);
	if(c=='y')
	{
		rootptr->right = create_tree();
		printf("\n");
	}
	return rootptr;
	
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
