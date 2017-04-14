#include "stdio.h"
#include "stdlib.h"

/*
* program to check if a path from root to leaf nodes
* with sum equal to a given sum exists in a tree or not
*/

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

// utility function to check if path from root to leaf node with a given sum exists or not
bool check(struct node* node,int sum)
{
	if(node==NULL)
		return false;

	sum= sum - node -> data;
	if(node -> left ==NULL && node->right == NULL && sum==0)
		return true;
	return check(node->left,sum)||check(node->right,sum);
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
	root -> left ->right ->left = newNode(8);
	int sum=10;
	if(check(root,sum))
		printf("Yes, a path from root to leaf node with sum = %d exists in the given tree.\n",sum);
	else
		printf("No, a path from root to leaf node with sum = %d does not exist in the given tree.\n",sum);
	return 0;
}