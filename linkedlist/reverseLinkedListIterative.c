#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head_ref,int data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node -> data=data;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}

void printList(struct node *node)
{
	while(node)
	{
		printf("%d ",node -> data );
		node = node -> next;
	}
}

void reverse(struct node** head_ref)
{
	struct node* prev=NULL;
	struct node* curr= *head_ref;
	struct node* temp = *head_ref;
	if(head_ref == NULL)
		return ;
	while(curr)
	{
	  temp=curr->next;
	  curr->next=prev;
	  prev=curr;
	  curr=temp;
	}
	*head_ref=prev;
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;

	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	printf(" Before reversing linked list \n");
	printList(head);

	reverse(&head);

	printf(" After reversing linked list \n");
	printList(head);

	return 0;
}