#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* next;
};

node* newNode(int data)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp-> data = data;
	temp -> next = NULL;
	return temp;
} 

void printList(struct node* node)
{
	while(node)
	{
		printf("%d ",node -> data );
		node= node -> next;
	}
}

int getNthFromLast(node *head, int n)
{
       // Your code here
       if(head == NULL)
        return -1;
       node *fast = head;
       node *slow = head;
       int i=1;
       while(i<=n)
       {
       	   if(fast == NULL)
       	   		return -1;
           fast= fast -> next;
           i++;
       }
       while(fast!=NULL)
       {
           fast = fast -> next;
           slow = slow -> next;
       }
       return (slow -> data);
}



int main(int argc, char const *argv[])
{
	struct node* head =newNode(1);
	head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    printList(head);
    printf("\nNth node from end is %d\n", getNthFromLast(head,5) );
	return 0;
}