
/*
Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).
Nodes should be printed from left to right.  If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2.  Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8


*/

void printKdistance(Node *root, int k)
{
  // Your code here
  if(root == NULL)
    return;
    
    if(k==0)
    {
        printf("%d ",root->data);
        return;
    }
    printKdistance(root->left,k-1);
    printKdistance(root->right,k-1);
}