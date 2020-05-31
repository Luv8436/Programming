#include<stdio.h>
#include<stdlib.h>
struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
void create_bst(int n);
struct bstnode* create_node(int n);
// declare the root pointer to the struct as global variable
struct bstnode *root = NULL;
int main()
{
	char c;
	//ask the user to if he wants to add the next node
	printf("Do you want insert the node(y/n):  ");
	scanf(" %c",&c);
	if(c=='n')
	{
		printf("The tree is empty.");
		return 0;
	}
	else
	{
		while(c=='y')
		{
			int n;
			//ask the user to enter the data
			printf("enter the data: ");
			scanf("%d",&n);
			//pass the data into the function create_bst node
			create_bst(n);
			printf("Do you want insert the node(y/n):  ");
			scanf(" %c",&c);
		}
	} 
}
//BST NODE function
void create_bst(int n)
{
	struct bstnode *ptr = root , *prev = root;
	int direction = -1;
	while(ptr!=NULL)
	{
		if(n <= ptr->data)
		{
			direction = 0;
			prev = ptr;
			ptr = ptr->left;
		}
		else
		{
			int direction = 1;
			prev = ptr;
			ptr = ptr->right;
		}
	}
	if(direction == -1)
	{
		prev = create_node(n);
	}
	else if(direction == 0)
	{
		prev->left = create_node(n);
	}
	else
	{
		prev->right = create_node(n);
	}
}
// make the node and return the pointer to the node
struct bstnode* create_node(int n)
{
	struct bstnode *ptr = (struct bstnode*)malloc(sizeof(struct bstnode));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = n;
	return ptr;
}
