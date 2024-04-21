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


void moveEvenItemsToBack(LinkedList *ll)
{
	ListNode *cur;
	int d,s,i, j;

	s = ll->size;

	if (s < 2)
		return;
	cur = ll->head;
	j = 0;
	for (i = 0; i < s; i++) {
		if (cur->item % 2 == 0) {
			d = cur->item;
			cur = cur->next;
			removeNode(ll, j);
			insertNode(ll, ll->size, d);
		}
		else {
			cur = cur->next;
			j++;
		}
	}

}

int moveMaxToFront(ListNode **ptrHead)
{
    ListNode *pre, *cur;
	ListNode *preMax = NULL;
	int maxItem;
	// Empty list
	if (*ptrHead == NULL) return -1;
	// Only one node in the list
	if ( (*ptrHead)->next == NULL )
		return 0;
	cur = (*ptrHead);
	maxItem = (*ptrHead)->item;
	// preMax gets set to the address of the ListNode with the max value
	// If preMax is still NULL at the end, first node had the max value
	while (cur != NULL){
		if (cur->item > maxItem){
			maxItem = cur->item;
			preMax = pre;
			}
		pre = cur;
		cur = cur->next;
	}
	// Never saw a value higher than the first node, nothing to move
	if (preMax == NULL)
		return 0;
	// Move node with max value to first position
	cur = preMax->next;
	preMax->next = preMax->next->next;
	// Update head pointer
	cur->next = *ptrHead;
	*ptrHead = cur;
	return 0;
}

void removeDuplicatesSortedLL(LinkedList *ll)
{
	ListNode *current = ll->head;
	if (current == NULL)
		return;
	while (current->next != NULL)
	{
		if (current->item == current->next->item)
		{
			ListNode *temp = current->next->next;
			free(current->next);
			current->next = temp;
			ll->size--;
		}
		else
		{
			current = current->next;
		}
	}
}