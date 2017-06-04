/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printleft(Node *node)
{
    if(node==NULL)
        return;
    if(node->left==NULL && node->right==NULL)
        return;
    cout<<node->data<<" ";
    if(node->left)
        printleft(node->left);
    else
        printleft(node->right);
}

void printLeaf(Node *node)
{
    if(node==NULL)
        return;
    if(node->left==NULL && node->right==NULL)
    {
        cout<<node->data<<" ";
        return;
    }
    printLeaf(node->left);
    printLeaf(node->right);
}

void printr(Node* node,int path[],int *level)
{
    if(node==NULL)
        return;
    if(node->left==NULL && node->right==NULL)
        return;
    path[*level]=node->data;
    *level=*level+1;
    if(node->right)
        printr(node->right,path,level);
    else
        printr(node->left,path,level);

}
void printBoundary(Node *root)
{
     //Your code here
     if(root==NULL)
        return;
    cout<<root->data<<" ";
    int level = 0;
    printleft(root->left);
    printLeaf(root);
    int path[100];
    printr(root->right,path,&level);
    for(int i=level-1;i>=0;--i)
        cout<<path[i]<<" ";
    //cout<<"\nlevel is "<<level;
}