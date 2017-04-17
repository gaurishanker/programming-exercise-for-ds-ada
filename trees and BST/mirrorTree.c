/* program to find mirror of a tree */

#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node *left , *right;
};

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc (sizeof(struct node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}


void InOrder(struct node* node)
{
	if(node == NULL)
		return;
	InOrder(node ->left);
	printf("%d ", node -> data);
	InOrder(node -> right);

}

void mirror(struct node* node)
{
	if(node == NULL)
		return;
	mirror(node -> right);
	mirror(node ->left);
	struct node* temp = node ->left;
	node -> left = node -> right;
	node ->right = temp;
}

int main(int argc, char const *argv[])
{
	struct node* root = NULL;
	root = newNode(1);
	root -> left = newNode(2);
	root-> right =  newNode(3);
	root ->left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root-> right -> right = newNode(7);
	
	printf("\nGiven tree inorder\n");
	InOrder(root);
	printf("\nMirror of given tree\n");
	mirror(root);
	InOrder(root);
	return 0;
}