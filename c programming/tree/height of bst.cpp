// program to find the height of binary search tree
#include<stdlib.h>
#include<stdio.h>
struct bstnode{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};
struct bstnode* insert(struct bstnode *root , int data);
struct bstnode* create_node(int data);
int height_bst(struct bstnode *root);
int max(int x , int y);
int main()
{
	struct bstnode *root = NULL;
	printf("do you want to insert into the tree(y/n): ");
	char c;
	scanf("%c",&c);
	if(c=='n')
	{
		printf("The tree is empty, height of tree is -1.\n");
		return 0;
	}
	int data;
	while(c=='y')
	{
		printf("enter the data to insert: ");
		scanf("%d",&data);
		root = insert(root , data);
		printf("do you want to insert into the tree(y/n): ");
		scanf(" %c",&c);
	}
	
	int height = height_bst(root);
	printf("Height of bst is : %d",height);
}
struct bstnode* insert(struct bstnode *root , int data)
{
	if(root == NULL)
	{
		root = create_node(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left , data);
	}
	else
	{
		root->right = insert(root->right , data);
	}
	
	return root;
}
struct bstnode* create_node(int data)
{
	struct bstnode *ptr = (struct bstnode *)malloc(sizeof(struct bstnode));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = data;
	return ptr;
}

int height_bst(struct bstnode *root)
{
	if(root == NULL)
	{
		return -1;
	}
	int height_left= height_bst(root->left);
	int height_right = height_bst(root->right);
	
	return 1+max(height_left , height_right);
	
}
int max(int x , int y)
{
	if(x>y)
	return x;
	else
	return y;
}
