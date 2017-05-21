#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* left,*right;	
};

struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void printTreePreOrder(struct node* node)
{
	if(node == NULL)
		return;
	printf("%d ", node -> data );
	printTreePreOrder(node -> left);
	printTreePreOrder(node -> right);
}
/*
Below algorithm is used to solve this problem

diff = left child data + right child data - current node data
If diff is 0 then nothing needs to be done.

If diff > 0 ( node’s data is smaller than node’s children sum) increment the node’s data by diff.

If diff < 0 (node’s data is greater than the node's children sum) then increment one child’s data.
We can choose to increment either left or right child if they both are not NULL. 
Let us always first increment the left child.
Incrementing a child changes the subtree’s children sum property so we need to change left subtree also. So we recursively increment the left child. 
If left child is empty then we recursively call increment() for right child.




*/
void Increment(struct node* node,int diff)
{
	if(node -> left != NULL)
	{
		node->left -> data = node->left ->data + diff;
		Increment(node->left,diff);
	}
	else if( node-> right != NULL)
	{
		node -> right -> data = node->right ->data + diff;
		Increment(node->right,diff);
	}
}

void ConvertTree(struct node* node)
{
	if(node == NULL || ( node -> left == NULL && node -> right ==NULL))
		return;
	ConvertTree(node->left);
	ConvertTree(node->right);
	int lsum=0,rsum=0;
	if(node-> left)
		lsum = node->left->data;
	if(node->right)
		rsum= node->right->data;
	int diff = lsum + rsum - node->data;
	
	if(diff >0)
		node->data = node -> data + diff;
	if(diff<0)
		Increment(node,-diff);
}

int main(int argc, char const *argv[])
{
	struct node *root = newNode(50);
	root->left	 = newNode(7);
	root->right	 = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(1);
	root->right->right = newNode(30);
    printf("Before Converting tree\n");
    printTreePreOrder(root);
    ConvertTree(root);
    printf("\nAfter converting tree\n");
    printTreePreOrder(root);
	return 0;
}