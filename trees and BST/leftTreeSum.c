/*
	Given a Binary Tree,
	change the value in each node to sum of all the values in the nodes in the left subtree including its own.

*/

#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->left = temp ->right = NULL;
	return temp;
}

int leftSum(struct node* node)
{
	if(node == NULL)
		return 0;
	if(node->left==NULL && node->right==NULL)
		return node->data;

	int lsum = leftSum(node->left);
	int rsum =leftSum(node->right);

	node->data +=lsum;
	lsum+=rsum;
	return lsum;
}

void printPreOrder(struct node* node)
{
	if(node == NULL)
		return;
	printf("%d ", node->data);
	printPreOrder(node->left);
	printPreOrder(node->right);
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	printPreOrder(root);
	leftSum(root);
	printf("\n");
	printPreOrder(root);
	return 0;
}