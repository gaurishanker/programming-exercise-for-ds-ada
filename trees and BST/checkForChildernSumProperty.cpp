/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool isLeaf(Node* node)
{
    if(node->left == NULL && node->right==NULL)
        return true;
    return false;
}

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* node)
{
     // Your code here
     if(node == NULL)
        return true;
     if(node->left==NULL && node->right==NULL)
        return true;
    int lsum,rsum;
    if(isSumTree(node->left)&&isSumTree(node->right))
    {
        if(node==NULL)
            return true;
        if(node->left==NULL)
            lsum=0;
        else if(isLeaf(node->left))
            lsum = node->left->data;
        else
            lsum = 2*node->left->data;
            
        if(node->right==NULL)
            rsum=0;
        else if(isLeaf(node->right))
            rsum = node->right->data;
        else
            rsum = 2*node->right->data;
        
        return (lsum+rsum == node->data);
    }
}