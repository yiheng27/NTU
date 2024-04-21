#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray; //size of possible sequence
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the size of a possible sequence
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum; //the number of possible sequences
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);
    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){
        for(j=0;j<temp->sizeArray;j++)
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		ll->sum -= ll->head->item;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		ll->sum -= cur->item;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
		return NULL;

	temp = ll.head;

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
	ll->sum =0;
}

#include<string.h>

void s2c (int arr[],int index, int C, int reducedC, ArrayList* al){
    if (reducedC < 0){ //base; exceed
		return;
	}
    if (reducedC == 0){ //found comb
	//put into al
        ArrayNode*tmp = malloc(sizeof(ArrayNode));
		tmp->sizeArray = index;
		tmp->next = NULL;
		tmp->itemArray = malloc(sizeof(int)*(index));
		//printf("ans: ");
		for (int i = 0; i < index; i++){
			tmp->itemArray[i] = arr[i];
			//printf(" %d ", tmp->itemArray[i]);
		}
		//printf("\n");
		//memset(arr,0,sizeof(arr));
		if (al->head == NULL){ //empty al
			al->head = tmp;
		}
		else{ //al alr have entries
			ArrayNode* cural = al->head;
			while(cural->next!=NULL){
				cural=cural->next;
			}
			cural->next = tmp; //connect last AN to tmp;
		}
		al->size++;
        return;
    }
	int prev = 0;
	if (index == 0){ //find prev number stored in arr
		prev = 1;
	}
	else{
		prev = arr[index-1] + 1;
	}

    for (int k = prev; k <= C ; k++) //loop starting from prev
    {
        arr[index] = k; //add k into array

        // call recursively with reduced number
        s2c(arr, index + 1, C, reducedC - k, al);

    }
}


void sumToC(LinkedList* ll, int C, ArrayList* al)
{
	int arr[C];

	s2c(arr, 0, C, C, al);
}


