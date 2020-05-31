// program for BFS traversal of binary tree
#include<stdio.h>
#include<stdlib.h>
// node of binary tree
struct bstnode
{
	struct bstnode *left;
	int data;
	struct bstnode *right;
};
// node of queue
struct queue{
	struct bstnode *data;
	struct queue *next;
};
struct bstnode* insert(struct bstnode *root , int data);
struct bstnode* create_node(int data);
// starting and ending node of the queue
struct queue *start = NULL,*end = NULL;
void bfs_traversal();
void enqueue(struct bstnode *root);
struct bstnode* dequeue();
int main()
{
	struct bstnode *root = NULL;
	char c;
	printf("do you want to insert the node(y/n): ");
	scanf("%c",&c);
	if(c=='n')
	{
		printf("The tree is empty.\n");
	}
	int data;
	while(c=='y')
	{
		printf("Enter the data of the node: ");
		scanf("%d",&data);
		root = insert(root , data);
		printf("do you want to insert the node(y/n): ");
		scanf(" %c",&c);
	}
	// enter the root node into the queue
	enqueue(root);
	// breadth for search
	bfs_traversal();
	
}
struct bstnode* insert(struct bstnode *root , int data)
{
	if(root == NULL)
	{
		root = create_node(data);
	}
	else if(data < root->data)
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
// breadth for search 
void bfs_traversal()
{
	while(start != NULL)
	{
		struct bstnode *ptr = dequeue();	
		enqueue(ptr->left);
		enqueue(ptr->right);
		printf("%d ",ptr->data);
		bfs_traversal();
	}
}
// enqueue operation 
void enqueue(struct bstnode *root)
{
	struct queue *ptr =(struct queue *)malloc(sizeof(struct queue));
	ptr->data = root;
	ptr->next = NULL;
	if(start == NULL)
	{
		start = end = ptr;
	}
	else
	{
		end->next = ptr;
		end = ptr;
	}
	
}
// dequeue operation 
struct bstnode* dequeue()
{
	if(start == NULL)
	{
		return NULL;
	}
	struct queue *ptr = start;
	start = start->next;
	return ptr->data;
}
