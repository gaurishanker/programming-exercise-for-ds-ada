#include "stdio.h"
#include "stdlib.h"

struct node{
	char data;
	struct node* next;
};

struct node* push(char a)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = a;
	newNode -> next = NULL;
	return newNode;
}

void printList(struct node* head)
{
	while(head != NULL)
	{
		printf("%c ", head -> data);
		head= head->next;
	}
}

void reverse(struct node** head)
{
	struct node* next= *head;
	struct node *prev = NULL;
	struct node *curr = *head;
	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev=curr;
		curr=next;
	}
	*head = prev;
}

bool comp(struct node* first,struct node* second)
{
	while(first !=NULL  && second != NULL)
	{
		if(first -> data != second-> data)
			return false;
		first = first -> next;
		second  = second->next;
	}
	if(first == NULL && second == NULL)
		return true;
	return false;
}

bool checkPalindrome(struct node* head)
{
	bool result = true;
	if(head != NULL && head->next != NULL)
	{
		struct node *fast= head;
		struct node *slow=head;
		struct node *slow_prev=NULL;
		struct node *midNode=NULL;
		struct node *second_head = NULL;
		while(fast && fast->next)
		{
			slow_prev = slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		//if list is odd
		if(fast!=NULL)
		{
			midNode = slow;
			slow = slow -> next;
		}
		slow_prev->next = NULL;
		second_head = slow;
		reverse(&second_head);
		
		result = comp(head,second_head);
		reverse(&second_head);
		if(midNode != NULL)
		{
			slow_prev -> next = midNode;
			midNode -> next = slow;
		}
		else
			slow_prev->next = slow;
		return result;
	}
}

int main(int argc, char const *argv[])
{
	struct node* head = push('R');
	head->next=push('A');
	head->next->next=push('D');
	head->next->next->next=push('A');
	head->next->next->next->next=push('R');
	printf("Linked List is \n");
	printList(head);

	if(checkPalindrome(head))
		printf("\nYes Given list is a palindrome \n");
	else
		printf("\nNo Given List is not a palindrome \n");
	return 0;
}