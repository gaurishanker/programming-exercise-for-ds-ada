/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
   
   
bool isBSTL(Node* node, int min,int max)
{
    if(node==NULL)
        return true;
    if(isBSTL(node->left,min,node->data-1) && isBSTL(node->right,node->data+1,max))
    {
        if(node->data <= max && node->data >=min)
            return true;
    }
    return false;
}
bool isBST(Node* root) {
    // Your code here
    int min = -9999;
    int max= 99999;
    return isBSTL(root,min,max);
}
