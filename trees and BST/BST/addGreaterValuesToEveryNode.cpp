/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*  modifies the root of the bst */
void mod(Node *node,Node*& prev)
{
    if(node==NULL)
        return;
    mod(node->right,prev);
    if(prev)
        node->data=node->data+prev->data;
    prev=node;
    mod(node->left,prev);
}
void modify(Node **root)
{
// Your code here
    Node* prev = NULL;
    mod(*root,prev);
}