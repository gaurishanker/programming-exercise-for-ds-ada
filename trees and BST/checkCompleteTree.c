/*
Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not.

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

*/

#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left =temp->right =NULL;
	return temp;
}

int count(struct node* node)
{
	if(node == NULL)
		return 0;
	return (1+count(node->left)+count(node->right));
}

int check(struct node* node,int nodes, int index)
{
	if(node==NULL)
		return 1;
	if(index>=nodes)
		return 0;
	return check(node->left,nodes,2*index+1) && check(node->right,nodes,2*index+2);
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root->left         = newNode(2);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(5);
	root->right->right = newNode(6);
	int c = count(root);
	if(check(root,c,0))
		printf("Yes Given tree is complete binary tree\n");
	else
		printf("No Given tree is not complete binary tree\n");	
	return 0;
}