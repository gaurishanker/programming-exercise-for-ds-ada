/* level order traversal of binary tree */
#include "stdio.h"
#include "stdlib.h"

void printLevelOrder(struct node* node , int level);

int max(int a,int b)
{
	return (a>b?a:b);
}
struct node
{
	int data;
	node *left,*right;
};

struct node* newNode(int data)
{
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->data = data;
	temp ->left = NULL;
	temp-> right = NULL;
	return temp;
}

int height(struct node* node)
{
	if(node == NULL)
		return 0;
	return (1+max(height(node->left),height(node->right)));
}

void levelOrder(struct node* node)
{
	int h= height(node);
	for(int i=0;i<h;++i)
		printLevelOrder(node,i);
}

void printLevelOrder(struct node* node , int level)
{
	if(node == NULL)
		return;
	if(level == 0)
		printf("%d ",node->data);
	level--;
	printLevelOrder(node->left,level);
	printLevelOrder(node->right,level);
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
	printf("Level Order Traversal of the gien tree is :\n");
	levelOrder(root);
	return 0;
}