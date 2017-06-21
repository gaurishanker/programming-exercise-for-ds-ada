/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
   // Your code here
   if(node == NULL)
     return;
   Node *next = node->next;
   node->data = next->data;
   node->next = next->next;
   free(next);
   return;
   
}