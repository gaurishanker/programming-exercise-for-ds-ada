#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node *left,*right;
};

int max(int a,int b)
{
	return a>b?a:b ;
}
struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data=data;
	temp->left =NULL;
	temp->right =NULL;
	return temp;
}

int height(struct node* node)
{
	if(node==NULL)
		return 0;
	return (1+max(height(node->left),height(node->right)));
}

void widthUtil(struct node* node,int wid[],int level)
{
	if(node==NULL)
		return;
	wid[level]++;
	widthUtil(node->left,wid,level+1);
	widthUtil(node->right,wid,level+1);
}

int width(struct node* node)
{
	int h= height(node);
	int *wid = (int*)calloc(h,sizeof(int));
	widthUtil(node,wid,0);
	int max= *wid;
	for(int i=0;i<h;++i)
		if(max<*(wid+i))
			max=*(wid+i);		
	return max;
	free(wid);
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	root->left->left->left=newNode(8);
	
	printf("Width of the given tree is %d\n",width(root));
	return 0;
}