#include "stdio.h"
#include "stdlib.h"

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head,int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;

	if(*head == NULL)
		*head=temp;
	else
	{
		temp->next = *head;
		*head = temp;
	}

}

void printList(struct node* node)
{
	while(node != NULL)
	{
		printf("%d ",node->data);
		node= node -> next;
	}
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("Linked list is\n");
	printList(head);
	return 0;
}