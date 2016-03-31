/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int i = 1;
	struct node *temp,*new1;
	temp = (struct node*)malloc(sizeof(struct node)); 
	temp = head;
	
		while (temp!= NULL)
		{
			for (i = 1; i <K&&temp!=NULL; i++)
			{
				if (K!=1||temp!=head)
				temp = temp->next;
			}

			if (i == K&&temp!=NULL)
			{
				new1 = (struct node*)malloc(sizeof(struct node));
				new1->num = K;
				new1->next = temp->next;
				temp->next = new1;
				temp = new1->next;
			}
		}
	
	return head;
}
