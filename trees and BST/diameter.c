#include "stdio.h"
#include "stdlib.h"

struct node{
	int data;
	struct node* left;
	struct node* right;
};

int max(int a,int b)
{
	return a>b?a:b;
}

struct node* newNode(int d)
{
	struct node* temp =(struct node*)malloc(sizeof(struct node));
	temp->data= d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int Diameter(struct node* node,int* height)
{
	if(node==NULL)
		return 0;
	int lh=0,rh=0;
	int ldia = Diameter(node->left,&lh);
	int rdia = Diameter(node->right,&rh);
	*height = max(lh,rh)+1;
	return  max(max(ldia,rdia),lh+rh+1);
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left= newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->right->right = newNode(7); 
	int height=0;
	printf("Diameter of given tree is %d ",Diameter(root,&height));
	return 0;
}