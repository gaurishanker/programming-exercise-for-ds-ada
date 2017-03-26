#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};


//function to add elements at head of linkedlist
void push(struct node **head_ref,int data)
{
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node -> data = data;
	new_node -> next = (*head_ref);
	*head_ref = new_node;
}



// function to print linked list
void printList(struct node *curr)
{
	while(curr != NULL)
	{
		printf("%d ", curr -> data );
		curr = curr -> next;
	}
}

// function to swap elements present in a linked list
void swap(struct node **head_ref,int a,int b)
{
	struct node* prevA = NULL;
	struct node* prevB = NULL;
	struct node* currA = *head_ref;
	struct node* currB = *head_ref;
	if(head_ref == NULL)
		return;
	while(currA != NULL && currA -> data != a)
	{
		prevA = currA;
		currA = currA -> next;
	}

	while(currB != NULL && currB -> data != b)
	{
		prevB = currB;
		currB = currB -> next;
	}

	if(currA == NULL || currB == NULL)
		return;

	if(prevA != NULL)
		prevA -> next = currB;
	else
		*head_ref = currB;

	if(prevB != NULL)
		prevB -> next = currA;
	else
		*head_ref = currA;

	struct node* temp = currB -> next;
	currB -> next = currA -> next;
	currA -> next = temp;

}

int main(int argc, char const *argv[])
{
	struct node *head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);

	printf(" Before swapping \n");
	printList(head);
	swap(&head,1,5);

	printf("\n After swapping \n");
	printList(head);

	return 0;
}