#include "stdio.h"
#include "stdlib.h"
struct node
{
	int data;
	struct node *left,*right;
};

struct node* NewNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


/*
Traversal for this tree

		1
	
	2		3

  4    5 6		7

PreOrder traversal of above tree : 1 2 4 5 3 6 7
InOrder traversal of above tree : 4 2 5 1 6 3 7
PostOrder traversal of above tree : 4 5 2 6 7 3 1

*/

void PreOrder(struct node* node)
{
	if(node == NULL)
		return;
	printf("%d ", node -> data);

	PreOrder(node ->left);
	PreOrder(node -> right);

}


void InOrder(struct node* node)
{
	if(node == NULL)
		return;
	InOrder(node ->left);
	printf("%d ", node -> data);
	InOrder(node -> right);

}


void PostOrder(struct node* node)
{
	if(node == NULL)
		return;
	PostOrder(node ->left);
	
	PostOrder(node -> right);

	printf("%d ", node -> data);
}


int main(int argc, char const *argv[])
{
	struct node* root = NULL;
	root = NewNode(1);
	root -> left = NewNode(2);
	root-> right =  NewNode(3);
	root ->left -> left = NewNode(4);
	root -> left -> right = NewNode(5);
	root -> right -> left = NewNode(6);
	root-> right -> right = NewNode(7);

	printf("\nPreOrder traversal of tree : ");
	PreOrder(root);
	printf("\nInOrder traversal of tree : ");
	InOrder(root);
	printf("\nPostOrder traversal of tree : ");
	PostOrder(root);
	return 0;
}