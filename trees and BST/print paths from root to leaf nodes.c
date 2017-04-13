#include "stdio.h"
#include "stdlib.h"

void printPathUtil(struct node* node,int path[], int pathLen);

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

void printPath(struct node* node)
{
	int path[100];
	if(node == NULL)
		return;
	printPathUtil(node,path,0);
}

void printPathUtil(struct node* node,int path[], int pathLen)
{
	if(node==NULL)
		return;
	
	path[pathLen] = node -> data;
	pathLen++;
	
	if(node -> left == NULL && node -> right == NULL)
	{
		//print path array ,Leaf node reached
		for(int i=0;i<pathLen;++i)
			printf("%d ",path[i]);
		printf("\n");
	}

	printPathUtil(node->left  ,path,pathLen);
	printPathUtil(node->right ,path,pathLen);
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

	printPath(root);
	return 0;
}