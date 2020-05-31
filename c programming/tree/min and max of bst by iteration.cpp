// finding the max and min element in a bst by recursive approach
#include<stdio.h>
#include<stdlib.h>
struct bstnode{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};
struct bstnode * create_bst(struct bstnode *root , int data);
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
	// find the min of bst 
	struct bstnode *ptr = root , *prev = root;
	while(ptr!= NULL)
	{
		prev = ptr;
		ptr = ptr->left;
	}
	// when ptr becomes null print the data in prev
	int min = prev->data;
	//find max of bst
	ptr = root;
	prev = ptr;
	while(ptr!= NULL)
	{
		prev = ptr;
		ptr = ptr->right;
	}
	int max = prev->data;
	printf("\nmax = %d\nmin=%d",max,min);

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
struct bstnode *create_new_node(int data)
{
	struct bstnode *ptr = (struct bstnode *)malloc(sizeof(struct bstnode));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

