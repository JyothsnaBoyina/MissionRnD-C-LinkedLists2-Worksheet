/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	int flag;
	struct node  *temp1, *temp2,*prev;

	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	
	temp1 = (struct node*)malloc(sizeof(struct node));
	temp2 = (struct node*)malloc(sizeof(struct node));
	prev = (struct node*)malloc(sizeof(struct node));
	 
	if (head1->num < head2->num)
	{
		prev = head1;
		temp1 = head1->next;
		temp2 = head2;
		flag = 1;
	}

	else
	{
		prev = head2;
		temp1 = head2->next;
		temp2 = head1;
		flag = 2;
	}

	while (temp1 != NULL&&temp2 != NULL)
	{
		if (prev->num <= temp2->num){
			if (temp1 != NULL&&temp2->num <= (temp1->num))
			{
				prev->next = temp2;
				temp2 = temp2->next;
				prev->next->next = temp1;
			}
		}
	    
			prev = prev->next;
			temp1 = prev->next;
	}
	if (temp1 == NULL&&temp2!=NULL)
	{
		temp1 = temp2;
		prev->next = temp1;
	}
	
	if (flag == 1)
		return head1;
	else
		return head2;


}
