/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *temp,*prev,*aftr;

	if (head == NULL)
		return NULL;
	if (head->next== NULL)
		return head;

	temp = (struct node*)malloc(sizeof(struct node));
	prev = (struct node*)malloc(sizeof(struct node));
	aftr = (struct node*)malloc(sizeof(struct node));

	prev = head;
	temp = prev->next;
	aftr = temp->next;
	prev->next = NULL;

	

		while (temp->next != NULL)
		{
			temp->next = prev;
			prev = temp;
			temp = aftr;
			aftr = temp->next;
		}

		temp->next = prev;
	
	return temp;
}
