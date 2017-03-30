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

void detectAndRemoveLoop(struct node* head)
{
	struct node* slow = head;
	struct node* fast = head -> next;
	while(fast && fast -> next)
	{
		if(slow == fast)
			break;
		slow= slow -> next;
		fast = fast -> next ->next;
	}

	if(slow == fast)
	{
		printf("Oh Yes!! Loop Exists\n");
		slow = head;
		while(slow != fast->next)
		{
			slow = slow -> next;
			fast = fast -> next;
		}
	}

	fast -> next = NULL;
}



int main(int argc, char const *argv[])
{
	struct node* head =newNode(35);
	head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;
 	
 	detectAndRemoveLoop(head);
    printList(head);
	return 0;
}