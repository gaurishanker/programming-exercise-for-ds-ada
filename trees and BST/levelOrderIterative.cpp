/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
#include <queue>
using namespace std;
//You are required to complete this method
void levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q;
  q.push(node);
  while(!q.empty())
  {
      
      Node *ele =q.front();
      q.pop();
      cout<<ele->data<<" ";
      if(ele->left)
        q.push(ele->left);
      if(ele->right)
        q.push(ele->right);
  }
}


