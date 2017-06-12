/* binary search tree insertion and deletion */

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
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* insert(struct node* root,int data)
{
	if(root==NULL)
		return newNode(data);
	else
	{
		if(root->data > data)
		{
			root->left = insert(root->left,data);
		}
		if(root->data < data)
		{
			root->right = insert(root->right,data);
		}
	}
	return root;
	
}

void printTree(struct node* node)
{
	if(node==NULL)
		return;
	printTree(node->left);
	printf("%d ",node->data);
	printTree(node->right);
}

struct node* search(struct node* node,int data)
{
	if(node==NULL || data==node->data)
		return node;
	if(data<node->data)
		search(node->left,data);
	else
		search(node->right,data);

}



int main(int argc, char const *argv[])
{
	struct node* root = insert(NULL,8);
	insert(root,3);
	insert(root,10);
	insert(root,1);
	insert(root,6);
	insert(root,14);
	insert(root,4);
	insert(root,7);
	insert(root,13);
	printTree(root);
	int key = 7;
	struct node* temp = search(root,key); 
	if(temp!=NULL)
		printf("\nKey found\n");
	else
		printf("\nNot present\n");
	return 0;
}
