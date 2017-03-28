#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void push(struct node** head_ref,int data)
{
	struct node* new_node =(struct node*) malloc (sizeof(struct node));
	new_node -> data = data;
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

// function to reverse the given linked list
void printMiddleElement(struct node** head_ref)
{
	if(head_ref == NULL)
		return;
	struct node* slow = *head_ref;
	struct node* fast = *head_ref;
	while(fast!=NULL && fast->next != NULL)
	{
		slow=slow->next;
		fast= fast -> next ->next;
	}
	printf("\nMiddle Element of given linked list is %d ",slow -> data);
} 
int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	printf(" Given linked list is \n");
	printList(head);

	printMiddleElement(&head);
	return 0;
}