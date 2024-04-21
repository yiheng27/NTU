#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList) //q3
{
	int even = 1, evenSize = 0, oddSize = 0;
	ListNode *cur=head;

	if (cur == NULL)
		return -1;
	while (cur!= NULL){
		if (even==1){
			insertNode(ptrEvenList, evenSize, cur->num);
			evenSize++;
		}
		else{
			insertNode(ptrOddList, oddSize, cur->num);
			oddSize++;
		}
	cur = cur ->next;
	even = -even;
	}
	return 0;
}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead){ //q4
	ListNode *cur=head;

	if (cur == NULL) return -1;
	// Simply traverse the list and insert each visited node into the new list at index 0 each time
	while (cur != NULL){

		if (insertNode(ptrNewHead, 0, cur->num) == -1)
			return -1;
		cur = cur ->next;
	}
	return 0;
}