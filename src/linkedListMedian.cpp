/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int i = 0,l=0;
	struct node *temp,*prev;

	if (head == NULL)
		return -1;

	temp = (struct node*)malloc(sizeof(struct node));
	prev = (struct node*)malloc(sizeof(struct node));
	temp = head;
	prev = NULL;

	while (temp != NULL)
	{
		temp = temp->next;
		l++;
	}

	temp = head;
	for (i = 0; i < l / 2; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	if (l % 2 == 0)
		return (((prev->num) + (temp->num)) / 2);
	else
		return temp->num;

}
