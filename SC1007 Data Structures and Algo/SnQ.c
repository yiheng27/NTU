//////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#define MIN_INT -1000
//////////////////////////////////////////////////////////////////////////////////
typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;	// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;	// You should not change the definition of LinkedList

typedef struct _queue
{
	LinkedList ll;
} Queue;  // You should not change the definition of Queue

typedef struct _stack
{
	LinkedList ll;
}Stack;  // You should not change the definition of Stack
///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
void createQueueFromLinkedList(LinkedList *ll, Queue *q);       //1 assignment q1
void createStackFromLinkedList(LinkedList *ll , Stack *stack);  //2 assignment q2
int isStackPairwiseConsecutive(Stack *s);   //3 assignment q3
void reverse(Queue *q);                     //4 assignment q4
void removeUntil(Stack *s, int value);      //5 lab q1
void recursiveReverse(Queue *q);            //6 lab q2
int palindrome(char *word);                 //7 lab q3
int balanced(char *expression);             //8 lab q4
void reverseStack(Stack *s);                //9 tut q1
void reverseFirstKItems(Queue *q, int k);   //10 tut q2
void sortStack(Stack *s);                   //11 tut q3

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);
void removeAllItemsFromQueue(Queue *q);

void push(Stack *s , int item);
int pop(Stack *s);
int isEmptyStack(Stack *s);
void removeAllItemsFromStack(Stack *s);
// You may use the following functions or you may write your own
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	int c, i;
	LinkedList ll;
	Queue q;
	c = 1;

	// Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	// Initialize the Queue as an empty queue
	q.ll.head = NULL;
	q.ll.size = 0;

    // Initalize the stack as an empty stack
	s.ll.head = NULL;
	s.ll.size = 0;
}
//////////////////////////////////////////////////////////////////////////////////
void createQueueFromLinkedList(LinkedList *ll, Queue *q){ //1
	ListNode *cur;
	if (ll->head == NULL){
		return;
	}
	cur = ll->head;
	while (cur != NULL){
		enqueue (q, cur->item);
		cur = cur->next;
		removeNode(ll,0);
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////
void createStackFromLinkedList(LinkedList *ll, Stack *s){ //2
	ListNode *cur = NULL;
	if (ll->head==NULL){
		return;
	}
	if (s!=NULL){
		removeAllItemsFromStack(s);
	}
	cur = ll->head;
	while(cur != NULL){
		push(s,cur->item);
		cur = cur->next;
		removeNode(ll,0);
	}
	return;
}
//////////////////////////////////////////////////////////////////////////////////
int isStackPairwiseConsecutive(Stack *s){ //3
  int i,j,diff;
  if (s==NULL){
	  return -1;
  }
  while(!isEmptyStack(s)){
	  i = pop(s);
	  j = pop(s);
	  diff = i-j;
	  if ( abs(diff) != 1){ //abs() in stdlib.h
		  return 0;
	  }
  }
  return -1;
}
//////////////////////////////////////////////////////////////////////////////////
void reverse(Queue *q){ //4
    if (q == NULL){
		return;
	}
	Stack tmp;
	tmp.ll.size=0;
	tmp.ll.head=NULL;
	tmp.ll.tail=NULL;
	while (isEmptyQueue(q) == 0){
		push(&tmp, dequeue(q));
	}
	while (!isEmptyStack(&tmp)){
		enqueue(q, pop(&tmp));
	}
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void removeUntil(Stack *s, int value){ //5
	while (!isEmptyStack(s)){
		if (peek(s) != value)
			pop(s);
		else
			break;
	}
}

////////////////////////////////////////////////////////////
void recursiveReverse(Queue *q){ //6
	int i;
	if (isEmptyQueue(q))
		return;
	 i = dequeue(q);
	 recursiveReverse(q);
	 enqueue(q, i);
}
////////////////////////////////////////////////////////////
int palindrome(char *word){ //7
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;
    s.ll.tail = NULL;
    Queue q;
    q.ll.head = NULL;
    q.ll.size = 0;
    q.ll.tail = NULL;
    // Put the whole string in a stack and a queue, stripping out spaces

    while (*word){
        if (*word != ' '){
            push(&s, tolower(*word));
            enqueue(&q, tolower(*word));
        }
        word++;
    }
    // Integer division by 2, ignores the middle character in an odd-length string
    int half = (q.ll.size) / 2;
    // Pop first half of stripped string off the stack letter by letter, comparing with second half
	while (half>0){
        if (pop(&s) != dequeue(&q)){
            printf("The string is not a palindrome.\n");
            return -1;
        }
        half--;
    }
    printf("The string is a palindrome.\n");
    return 0;
}

////////////////////////////////////////////////////////////
int balanced(char *expression){ //8
	Stack s;
	s.ll.head = NULL;
	s.ll.tail = NULL;
	s.ll.size = 0;
	// Check one character at a time
	// If we see an opening bracket, store it in a stack
	// If we see a closing bracket, check stack for matching opening bracket (should be on top)
	// The moment we see a mismatch, expression is not balanced, return
	// If we finish looking at the expression and the stack is empty, it's balanced
	printf("%s\n", expression);
	while (*expression){
		if (*expression == '(' || *expression == '[' || *expression == '{'){
			push(&s, *expression);
		}
		else if (*expression == ')'){
			if (isEmptyStack(&s) || pop(&s) != '(')
				return -1;
		}
		else if (*expression == ']'){
			if (isEmptyStack(&s) || pop(&s) != '[')
				return -1;
		}
		else if (*expression == '}'){
			if (isEmptyStack(&s) || pop(&s) != '{')
				return -1 ;
		}
		expression++;
	 }
	if (isEmptyStack(&s)) return 0;
	else
		return -1;
}
////////////////////////////////////////////////////////////
void reverseStack(Stack *s) { //9
	int item;
	Queue q;
	q.ll.head = NULL;
	q.ll.size = 0;
	while (!isEmptyStack(s)){
		enqueue(&q, pop(s));
	}
	while (!isEmptyQueue(&q)){
		push(s, dequeue(&q));
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void reverseFirstKItems(Queue *q, int k){ //10
    Stack s;
    int i , j;
    if(k <= 0)
        return;
    if(isEmptyQueue(q) || k > q->ll.size)
        return;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;

    for(i=0; i < k; i++){
        push(&s,dequeue(q));
    }
    while(!isEmptyStack(&s)){
        enqueue(q,pop(&s));
    }
    j = q->ll.size;
    for(i=0; i< j-k;i++){
        enqueue(q,dequeue(q));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void sortStack(Stack *s){ //11
    int temp;
    Stack ts;
    ts.ll.head = NULL;
    ts.ll.tail = NULL;
    ts.ll.size = 0;

    while(!isEmptyStack(s)){
        push(&ts,pop(s));
    }

    while(!isEmptyStack(&ts)){
        temp = pop(&ts);
        while(!isEmptyStack(s) && peek(s) < temp){
           push(&ts,pop(s));
        }
        push(s,temp);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}
int pop(Stack *s){
	int item;
	if (s->ll.head != NULL)
	{
		item = ((s->ll).head)->item;
		removeNode(&(s->ll), 0);
		return item;
	}
	else
		return MIN_INT;
}
int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	else
		return 0;
}
void removeAllItemsFromStack(Stack *s){
	if (s == NULL)
		return;
	while (s->ll.head != NULL)
	{
		pop(s);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
void enqueue(Queue *q, int item) {
	insertNode(&(q->ll), q->ll.size, item);
}
int dequeue(Queue *q) {
	int item;

	if (!isEmptyQueue(q)) {
		item = ((q->ll).head)->item;
		removeNode(&(q->ll), 0);
		return item;
	}
	return -1;
}
int isEmptyQueue(Queue *q) {
	if ((q->ll).size == 0)
		return 1;
	return 0;
}
void removeAllItemsFromQueue(Queue *q){
	int count, i;
	if (q == NULL)
		return;
	count = q->ll.size;

	for (i = 0; i < count; i++)
		dequeue(q);
}
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
void removeAllItems(LinkedList *ll){
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
ListNode * findNode(LinkedList *ll, int index){
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
		if (ll->head == NULL)
		{
			exit(0);
		}
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
		if (pre->next == NULL)
		{
			exit(0);
		}
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
