// finding the max and min element in a bst by recursive approach
#include<stdio.h>
#include<stdlib.h>
struct bstnode{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};
struct bstnode * create_bst(struct bstnode *root , int data);
int find_min(struct bstnode *root);
int  find_max(struct bstnode *root);
struct bstnode *create_new_node(int data);
int main()
{
	char c;
	int data;
	// declare the root pointer = NULL
	struct bstnode *root = NULL;
	// ask the user if he want to add the node
	printf("do you want to enter the node(y/n): ");
	scanf(" %c",&c);
	if(c=='n')
	{
		printf("The tree is empty.");
	}
	// if ans is yes then ask to enter the data
	while(c=='y')
	{
		printf("enter the data: ");
		scanf("%d",&data);
		//  pass the root and data to create_bst function
		// create_bst return the root node of the bst
		root = create_bst(root , data);
		printf("do you want to enter the node(y/n): ");
		scanf(" %c",&c);
	}
	int min = find_min(root);
	int max = find_max(root);
	printf("max = %d\nmin=%d",max,min);
}
struct bstnode * create_bst(struct bstnode *root , int data)
{
	// if root = null then create new node 
	if(root == NULL)
	{
		root = create_new_node(data);
	}
	else if(data <= root->data)
	{
		root->left = create_bst(root->left , data);
	}
	else
	{
		root->right = create_bst(root->right , data);
	}
	return root;
}
int find_min(struct bstnode *root)
{
	if(root->left != NULL)
	{
		return find_min(root->left);
	}
	else
	{
		return root->data;
	}
	
	
}
int find_max(struct bstnode *root)
{
	if(root->right != NULL)
	{
		return find_max(root->right);
	}
	else
	{
		return root->data;
	}
}
struct bstnode *create_new_node(int data)
{
	struct bstnode *ptr = (struct bstnode *)malloc(sizeof(struct bstnode));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

