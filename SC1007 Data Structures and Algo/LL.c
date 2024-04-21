//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

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


//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);	//1 assignment q1
void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2); //2 assignment q2
void moveOddItemsToBack(LinkedList *ll);		//3 assignment q4
void frontBackSplitLinkedList(LinkedList* ll, LinkedList *resultFrontList, LinkedList *resultBackList); //4 assignemnt q3
void moveEvenItemsToBack(LinkedList *ll);       //5 tut q1
int moveMaxToFront(ListNode **ptrHead);         //6 tut q2
void removeDuplicatesSortedLL(LinkedList *ll);  //7 tut q3
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList) //8 lab q3
int duplicateReverse(ListNode *head, ListNode **ptrNewHead) 	//9 lab q4
int concatenate(ListNode **ptrHead1, ListNode *head2);			//10 practice q2
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2); //11 practice q3

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////
int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;
}
//////////////////////////////////////////////////////////////////////////////////
int insertSortedLL(LinkedList *ll, int item){ //1
	int index = 0;
	ListNode *cur;
	if (ll->head == NULL){
		insertNode(ll, 0, item);
		return index;
	}
	cur = ll->head;
	while (cur != NULL){
		if (cur->item == item){
			return -1;
		}
		else if (item > cur->item){
			if (cur ->next == NULL){
				insertNode(ll, index+1, item);
			}
			cur = cur->next;
			index++;
		}
		else{
			insertNode(ll, index, item);
			return index;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////
void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2){ //2
	ListNode *cur1, *cur2;
	cur1 = ll1->head;
	cur2 = ll2->head;
	int index = 1;

	if (ll2->head == NULL){
		return;
	}
	while (cur1 != NULL && cur2 != NULL){
		if (cur1->next == NULL){
			insertNode(ll1, index, cur2->item);
			removeNode(ll2, 0);
			return;
		}
		else{
			cur1 = cur1->next;
			insertNode(ll1, index, cur2->item);
			cur2 = cur2->next;
			removeNode(ll2, 0);
			index += 2;
		}
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////
void moveOddItemsToBack(LinkedList *ll){ //3
	ListNode *cur;
	int index=0, counter = 0;
	if (ll->head == NULL){
		return;
	}
	cur = ll->head;
	while (counter != ll->size){
		if ( (cur->item)%2 == 0){
			cur = cur->next;
			//index++;
			counter++;
		}
		else{
			insertNode(ll, ll->size, cur->item);
			cur = cur->next;
			removeNode(ll,index);
			counter++;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////
void frontBackSplitLinkedList(LinkedList *ll, LinkedList *resultFrontList, LinkedList *resultBackList){ //4
	ListNode *cur;
	int half, index;
	index = 0;
	if (ll->head == NULL){
		return;
	}
	cur = ll->head;
	half = (ll->size) / 2;
	if (ll->size % 2 != 0){
		for (int i=0;i<=half;i++){
			insertNode(resultFrontList, index, cur->item);
			index++;
			cur = cur->next;
		}
		index=0;
		while (cur != NULL){
			insertNode(resultBackList, index, cur->item);
			index++;
			cur = cur->next;
		}
	}
	else{
		for (int i=0;i<half;i++){
			insertNode(resultFrontList, index, cur->item);
			index++;
			cur = cur->next;
		}
		index=0;
		while (cur != NULL){
			insertNode(resultBackList, index, cur->item);
			index++;
			cur = cur->next;
		}
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////
void moveEvenItemsToBack(LinkedList *ll){ //5
	ListNode *cur;
	int d,size, j;

	size = ll->size;

	if (s < 2)
		return;
	cur = ll->head;
	j = 0;
	for (int i = 0; i < size; i++) {
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
///////////////////////////////////////////////////////////////////////////////////
int moveMaxToFront(ListNode **ptrHead){ //6
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
///////////////////////////////////////////////////////////////////////////////////
void removeDuplicatesSortedLL(LinkedList *ll){ //7
	ListNode *current = ll->head;
	if (current == NULL)
		return;
	while (current->next != NULL){
		if (current->item == current->next->item){
			ListNode *temp = current->next->next;
			free(current->next);
			current->next = temp;
			ll->size--;
		}
		else{
			current = current->next;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList){ //8
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
///////////////////////////////////////////////////////////////////////////////////
int duplicateReverse(ListNode *head, ListNode **ptrNewHead){ //9
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
///////////////////////////////////////////////////////////////////////////////////
int concatenate(ListNode **ptrHead1, ListNode *head2){ //10
	ListNode *temp = *ptrHead1;
	// Both lists empty, let's return a -1 error value
	if (*ptrHead1 == NULL && head2 == NULL)
		return -1;
	// Empty first list, just set the head pointer of list 1 to point to first node of list 2
	if (temp == NULL){
		*ptrHead1 = head2;
		return 0;
	}
	// Empty second list, nothing to do
	if (head2 == NULL)
		return 0;
	// Traverse the first list to get to the last node
	// Notice we check for the value of the next pointer for the current node
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = head2;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2){ //11
	ListNode *temp;
	if (head1 == NULL && head2 == NULL) return -1;
	// If both remaining lists are empty, we're done
	// We know that at least one of the lists has a remaining node inside this while loop
	// Check in pairs each cycle: List #1, then List #2
	while (head1 != NULL || head2 != NULL){// Adding the first node, remember to update the head pointer
		if (*ptrHead == NULL){
			if (head1 != NULL){
				*ptrHead = malloc(sizeof(ListNode));
				(*ptrHead)->num = head1->num;
				head1 = head1->next;
				temp = *ptrHead;
				if (head2 != NULL){
					temp->next = malloc(sizeof(ListNode));
					temp->next->num = head2->num;
					temp = temp->next;
					head2 = head2->next;
				}
			}
			else{
				*ptrHead = malloc(sizeof(ListNode));
				(*ptrHead)->num = head2->num;
				head2 = head2->next;
				temp = *ptrHead;
			}
		}
		else{
			if (head1 != NULL){
				temp->next = malloc(sizeof(ListNode));
				temp->next->num = head1->num;
				temp = temp->next;
				head1 = head1->next;
			}
			if (head2 != NULL){
				temp->next = malloc(sizeof(ListNode));
				temp->next->num = head2->num;
				temp = temp->next;
				head2 = head2->next;
			}
		}
	}
	temp->next =NULL;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}