/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/

/* The below function should return the node which is 
inorder successor of given node x. */

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    if(root==NULL)
        return root;
    if(x->right)
    {
        Node* temp = x->right;
        while(temp->left)
            temp=temp->left;
        return temp;
    }
    Node* succ = NULL;
    while(root != NULL)
    {
        if(root->data > x->data)
        {
            succ= root;
            root=root->left;
        }
        else if(root->data < x->data)
            root=root->right;
        else
            break;
    }
    return succ;
}