// implemetation of binary tree 
// my code school
#include<stdio.h>
#include<stdlib.h>
struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right; 
};
struct bstnode *Insert(struct bstnode *root , int data);
struct bstnode *create_new_node(int data);
void search(struct bstnode *root , int data);
int main()
{
	struct bstnode *root = NULL;
	// insertion in binary tree
	root = Insert(root , 10);
	root = Insert(root , 15);
	root = Insert(root , 20);
	root = Insert(root , 25);
	//searching for data in the root
	
	
}
struct bstnode *Insert(struct bstnode *root , int data)
{
	if(root == NULL)
	{
		root = create_new_node(data);
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left , data);
	}
	else
	{
		root->right = Insert(root->right , data);
	}
	
	return root;
}
struct bstnode *create_new_node(int data)
{
	struct bstnode *ptr =(struct bstnode *)malloc(sizeof(struct bstnode));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void search(struct bstnode *root , int data)
{
	if(root == NULL)
	{
		printf("Not found");
	}
	else if(root->data == data)
	{
		printf("found !!!");
	}
	else if(data < root->data)
	{
		search(root->left , data);
	}
	else
	{
		search(root->right , data);
	}
}
