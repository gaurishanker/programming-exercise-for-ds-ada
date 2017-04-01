// function to add two linked list and return a resultant list
/*
struct Node{
  int data;
  Node *next;
}
*/


Node*  addTwoLists(Node* first, Node* second){
  // Code here
  Node *prev=NULL,*head=NULL;
  int sum=0,c=0;
  while(first!=NULL || second!=NULL)
  {
      int d1 = first ? first -> data :0;
      int d2 = second ? second -> data:0;
      sum = d1+d2+c;
      if(sum>=10)
        {
            sum=sum%10;
            c=1;
        }
        else
            c=0;
        Node *temp = newNode1(sum);
        if(head==NULL)
            head= temp;
        else
            prev->next=temp;
        prev= temp;
        if(first)
            first = first->next;
        if(second)
            second=second->next;
  }
  if(c>0)
    prev->next = newNode1(c);
  
  return head;
  
}