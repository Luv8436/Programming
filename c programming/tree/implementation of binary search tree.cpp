#include<stdio.h>
struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
// declare the root pointer to the struct as global variable
struct bstnode *root = NULL;
int main()
{
	//ask for the user to enter data in the root node
	//ask the user to if he wants to add the next node
	//ask the user to enter the data
	//pass the data into the function create_bst node 
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
struct bstnode* create_node(int n)
{
	struct bstnode *ptr = (struct bstnode*)malloc(sizeof(struct bstnode));
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = n;
	return ptr;
}
