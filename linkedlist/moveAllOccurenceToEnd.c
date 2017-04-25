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

void printList(struct node* curr)
{
	struct node* node = curr;
	while(node != NULL)
	{
		printf("%d ",node->data);
		node= node -> next;
	}
}

void move(struct node **head,int key)
{
	if(*head == NULL)
		return;
	struct node* prev=NULL;
	struct node* curr=*head;
	struct node* next=*head;
	struct node* secondh = NULL;
	int i=0;
	while(curr->next != NULL)
	{
		++i;
		next=curr->next;
		if(curr == *head && curr->data==key)
		{
			if(secondh == NULL)
				curr->next=NULL;
			else
			{
				curr->next = secondh;
				
			}
			secondh = curr;
			*head = next;
			curr= next;
		}
		else if( curr != *head && curr -> data == key )
		{
			prev->next = curr ->next;
			curr->next = secondh;
			secondh = curr;
			curr = next;
		}
		else
		{
			prev = curr;
			curr = curr -> next;
		}
		
	}
	curr->next = secondh;
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	push(&head,5);
	push(&head,2);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("Linked list is\n");
	printList(head);

	move(&head,2);
	printf("\nAfter moving linked list is\n");
	printList(head);
	return 0;
}