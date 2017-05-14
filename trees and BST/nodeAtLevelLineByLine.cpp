/* Iterative program to print levels line by line */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node
{
	struct node *left;
	int data;
	struct node *right;
};

// Iterative method to do level order traversal line by line
void printLevelOrder(node *root)
{
	// Base Case
	if (root == NULL) return;

	// Create an empty queue for level order tarversal
	queue<node *> q;

	// Enqueue Root and initialize height
	q.push(root);
    q.push(NULL);
	while (!q.empty())
	{
		// nodeCount (queue size) indicates number of nodes
		// at current lelvel.
		node* ele=q.front();
		q.pop();
		if(ele==NULL)
		{
		    cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		// Dequeue all nodes of current level and Enqueue all
		// nodes of next level
		else{
			
			cout << ele->data << " ";
			
			if (ele->left != NULL)
				q.push(ele->left);
			if (ele->right != NULL)
				q.push(ele->right);
		}
	}
}


node* newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

	printLevelOrder(root);
	return 0;
}
