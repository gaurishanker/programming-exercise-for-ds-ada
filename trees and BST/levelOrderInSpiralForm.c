/* level order traversal of binary tree */
#include "stdio.h"
#include "stdlib.h"

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
	int lheight = height(node->left);
	int rheight = height(node->right);
	if((lheight > rheight))
		return 1+lheight;
	else
		return rheight +1;
}

void printLevelOrderSpiral(struct node* node,int level,int flag)
{
	if(node == NULL)
		return;
	if(level == 0)
	{
		printf("%d ", node->data);
	}
	else if(level > 0 )
	{
		if(flag==false)
		{
			printLevelOrderSpiral(node -> right ,level-1,flag);
			printLevelOrderSpiral(node -> left,level -1,flag);
		}
		else
		{
			printLevelOrderSpiral(node->left,level-1,flag);
			printLevelOrderSpiral(node->right,level-1,flag);
		}
		
	}


}

void levelOrderInSpiralForm(struct node* node)
{
	int h= height(node);
	printf("Height of the tree is : %d\n",h );
	bool flag= false;
	for(int i=0;i<h;++i)
	{
		printLevelOrderSpiral(node,i,flag);
		flag = !flag;
	}
}



int main(int argc, char const *argv[])
{
	struct node* root = newNode(1);
	root -> left = newNode(2);
	root-> right =  newNode(3);
	root ->left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root-> right -> right = newNode(7);
	root -> left ->right ->left = newNode(8);
	printf("Level Order Traversal of the gien tree is :\n");
	levelOrderInSpiralForm(root);
	return 0;
}