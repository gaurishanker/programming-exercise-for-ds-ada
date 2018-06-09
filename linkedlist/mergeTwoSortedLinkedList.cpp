/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */

Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    if(head1==NULL) 
        return head2;
    if(head2==NULL)
        return head1;
        
    Node *fhead=head1;
    Node *fprev=NULL;
    Node *snext=NULL;
    while(head1!=NULL && head2!=NULL) {
        if(head1->data < head2->data) {
            fprev=head1;
            head1=head1->next;
        }
        else {
            snext=head2->next;
            head2->next=head1;
            if(fprev==NULL)
                fhead=head2;
            else
                fprev->next=head2;
            fprev=head2;
            head2=snext;
        }
    }
    if(head2!=NULL) {
        fprev->next=head2;
    }
    return fhead;
}