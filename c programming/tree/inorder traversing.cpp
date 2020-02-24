//post inorder traversing of tree
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left ;
	int data;
	struct node *right;
};
struct node * createNode(int a);
void traversal(struct node *root );
int main()
{
	//making of tree using structures 
	struct node *root;
	root = createNode(0);
	root->left=createNode(1);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);
	root->right->left=createNode(5);
	root->right->right=createNode(6);
	//preorder traversing of tree 
	traversal(root);
	
}
struct node * createNode(int a)
{
	struct node *ptr = (struct node *)malloc (sizeof(struct node));
	ptr->data = a ;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void traversal(struct node *root )
{
	if (root->left!=NULL)
	{
		traversal(root->left);
	}
	
	//print root data
	printf("%d ",root->data);
	
	if (root->right != NULL)
	{
		traversal(root->right);
	}
}
