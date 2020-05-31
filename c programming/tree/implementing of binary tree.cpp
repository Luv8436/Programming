//program for implementation of binary tree
#include<stdio.h>
#include<stdlib.h>
void create_tree(struct tree *root);
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *root = NULL;
int main()
{
	int data;
	printf("enter the data: ");
	scanf("%d",&data);
	root = create_root(data);
}
struct tree* create_root(int data)
{
	struct tree *ptr = (struct tree*)malloc(sizeof(struct tree));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = data;
	return ptr;
}
void create_tree(struct tree *rootptr)
{
	char ans;
	root = (struct tree *)malloc(sizeof(struct tree));
	root->left = NULL;
	root->right = NULL;
	printf("enter the data: ");
	scanf("%d",&root->data);
	printf("do you want to add a left node(y/n): ");
	scanf(" %c",&ans);
	if(ans == 'y')
	{
		create_tree(root->left);
	}
	printf("do you want to add a right node(y/n): ");
	scanf(" %c",&ans);
	if(ans == 'y')
	{
		create_tree(root->right);
	}
	return ;

	
}
