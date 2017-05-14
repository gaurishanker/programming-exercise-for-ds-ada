 /*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
#include <queue>
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
   // Your code here
   queue<Node*> q;
   if(root==NULL)
    return 0;
   int max=-1,count=0;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
       Node* ele = q.front();
       q.pop();
       if(ele == NULL)
       {
           if(max<count)
                max=count;
            count=0;
            if(!q.empty())
                q.push(NULL);
       }
       else
       {
           count++;
           if(ele->left)
            q.push(ele->left);
         if(ele->right)
            q.push(ele->right);
            
       }
   }
   return max;
}
