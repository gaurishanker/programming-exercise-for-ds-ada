/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from root node down to the nearest leaf node.
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

int min(int a,int b)
{
	return a<b?a:b;
}

int minDepth2(struct node* node)
{
	if(node == NULL)
		return 0;
	if( node->left==NULL && node->right==NULL)
		return 1;
	if(!node->left)
		return 1+minDepth2(node->right);
	if(!node->right)
		return 1+minDepth2(node->left);

	return 1+min(minDepth2(node->left),minDepth2(node->right));
}

void minDepth(struct node* node,int depth,int *min)
{
	if(node == NULL)
		return;
	if(node->left == NULL && node->right==NULL)
	{
		if(*min>depth)
			*min = depth;
		return;
	}
	minDepth(node->left,depth+1,min);
	minDepth(node->right,depth+1,min);
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	//root->right->left = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right =newNode(6);
	int min = 9999;
	minDepth(root,1,&min);
	printf("Minimum depth is %d\n",minDepth2(root) );
	return 0;
}