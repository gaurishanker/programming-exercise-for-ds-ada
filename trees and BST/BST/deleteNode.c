/* delete a node from binary search tree */

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
	if(root->data > data)
	{
		root->left = insert(root->left,data);
	}
	if(root->data < data)
	{
		root->right = insert(root->right,data);
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

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

struct node* inOrderSuccessor(struct node* node)
{
	while(node->left!=NULL)
		node=node->left;
	return node;
}

struct node* deleteNode(struct node* node,int x)
{
	if(node==NULL)
    return node;
  
  if(x < node->data)
    node->left = deleteNode(node->left,x);
  else if(x > node->data)
    node->right = deleteNode(node->right,x);
  else
  {
      if(node->left==NULL)
      {
          struct node* temp = node->right;
          free(node);
          return temp;
      }
      if(node->right == NULL)
      {
          struct node* temp = node->left;
          free(node);
          return temp;
      }
      else
      {
          struct node* temp = inOrderSuccessor(node->right);
          node->data = temp->data;
          node->right = deleteNode(node->right,temp->data);
      }
  }
  return node;
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
	root = deleteNode(root,13);
	printf("After deleting 13 \n");
	printTree(root);
	return 0;
}