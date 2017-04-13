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

int max(int a,int b)
{
	return a>b?a:b;
}
int height(struct node* node)
{
	if(node==NULL)
		return 0;
	return (1+max(height(node->left),height(node->right)));
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

	printf("Height of given tree is %d ",height(root));
	return 0;
}