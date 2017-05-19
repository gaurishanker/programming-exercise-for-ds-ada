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

bool isBalanced(struct node* node,int *height)
{
	if(node==NULL)
		{
			*height=0;
			return true;
		}
	int lh=0,rh=0;
	int l=0,r=0;
	l=isBalanced(node->left,&lh);
	r=isBalanced(node->right,&rh);
	*height = (lh>rh?lh:rh)+1;
	if(l&&r)
	{
		
		if(abs(lh-rh)<=1)
			return true;
		else
			return false;
	}
	return false;
	

}

int main(int argc, char const *argv[])
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->left->left = newNode(8);
     //root->left->left->left ->left= newNode(8);
     //root->left->left->left ->left->left= newNode(8);
 	int height=0;
    if(isBalanced(root,&height))
      printf("Given tree is balanced");
    else
      printf("Given tree is not balanced");    
	return 0;
}