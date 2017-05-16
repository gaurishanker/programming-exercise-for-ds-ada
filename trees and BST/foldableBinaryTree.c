#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* left,*right;	
};

struct node* newnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

bool check(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a==NULL || b== NULL)
		return false;
	return check(a->left,b->right) && check(a->right,b->left);
}

bool checkFoldableTree(struct node* root)
{
	if(root==NULL)
		return false;
	return check(root->left,root->right);
}

int main(int argc, char const *argv[])
{
	struct node *root = newnode(1);
	root->left	 = newnode(2);
	root->right	 = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->left->left->left = newnode(7);
	if(checkFoldableTree(root))
		printf("Yes given tree is foldable tree\n");
	else
		printf("No given tree is not foldable tree\n");
	return 0;
}