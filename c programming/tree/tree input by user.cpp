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
struct node * createNode();
int main()
{
	//making of tree using structures 
	struct node *root;
	printf("-1 represents no node\n");
	root = createNode();

	//preorder traversing of tree 
	traversal(root);
	
	
}
struct node * createNode()
{
	printf("Enter the value in node : ");
	int value ;
	scanf("%d",&value );
	if(value==-1)
	{
		return NULL;
	}
	struct node *ptr = (struct node *)malloc (sizeof(struct node));
	ptr->data = value ;
	ptr->left=NULL;
	ptr->right=NULL;
	int valLeft;
	printf("Enter the value in left node : ");
	scanf("%d",&valLeft);
	if(valLeft==-1)
	{
		return NULL;
	}
	else
	{
		ptr->left=createNode();
	}
	int valRight;
	printf("Enter the value in right node : ");
	scanf("%d",&valRight);
	if(valRight==-1)
	{
		return NULL;
	}
	else
	{
		ptr->right=createNode();
	}
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
/*
	post order traversing of tree
void traversal(struct node *root )
{
	if (root->left!=NULL)
	{
		traversal(root->left);
	}
	
	if (root->right != NULL)
	{
		traversal(root->right);
	}
	
	//print root data
	printf("%d ",root->data);
}
*/
/*
	preorder traversing of tree
void traversal(struct node *root )
{
	//print root data
	printf("%d ",root->data);
	
	if (root->left!=NULL)
	{
		traversal(root->left);
	}
	
	if (root->right != NULL)
	{
		traversal(root->right);
	}
}
*/
