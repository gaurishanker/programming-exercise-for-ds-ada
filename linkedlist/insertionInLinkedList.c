#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void push(struct node **head_ref,int data)
{
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node -> data = data;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}

void printLinkedList(struct node* head)
{
	struct node* curr=head;
	while(curr != NULL)
	{
		printf("%d -> ",curr->data );
		curr = curr -> next;
	}
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);

	printf("Linked List : ");
	printLinkedList(head);
	return 0;
}