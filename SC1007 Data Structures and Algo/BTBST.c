#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////
typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _bstnode{
	int item;
	struct _bstnode *left;
	struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode

typedef struct _stackNode{
	BSTNode *data;
	struct _stackNode *next;
}StackNode; // You should not change the definition of StackNode

typedef struct _stack
{
	StackNode *top;
}Stack; // You should not change the definition of Stack

///////////////////////// function prototypes ////////////////////////////////////
// You should not change the prototypes of these functions
int identical(BTNode *tree1, BTNode *tree2);//1 assignment q1
int maxHeight(BTNode *node);                //2 pactice q1
int maxDepth(BTNode *node);                 //3 tut q4
int countOneChildNodes(BTNode *node);       //4 practice q2
int sumOfOddNodes(BTNode *root);            //5 practice q3
void mirrorTree(BTNode *node);              //6 BT lab q1
void printSmallerValues(BTNode *node, int m); //7 BTlab q2
int smallestValue(BTNode *node);            //8 BT lab q3
int hasGreatGrandchild(BTNode *node);       //9 BT lab a4
void levelOrderTraversal(BSTNode *node);    //10 tut q2
void inOrderTraversal(BSTNode *node);       //11 assignment q2
void preOrderIterative(BSTNode *root);      //12 tut q2
void postOrderIterativeS1(BSTNode *node);   //13 assignment q3
void postOrderIterativeS2(BSTNode *root);   //14 assignment q4
void printBSTInOrder(BTNode *node);         //15 BST lab q2
int isBST(BTNode *node, int min, int max);  //16 BST lab q3

void insertBSTNode(BSTNode **node, int value);
void push(Stack *stack, BSTNode *node);
BSTNode *pop(Stack *s);
BSTNode *peek(Stack *s);
int isEmpty(Stack *s);
void removeAll(BSTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
	int c, i;
	c = 1;

	//Initialize the Binary Search Tree as an empty Binary Search Tree
	BSTNode *root;
	root = NULL;
}
//////////////////////////////////////////////////////////////////////////////////
int identical(BTNode *tree1, BTNode *tree2){ //1
   if (tree1 == NULL && tree2 == NULL){
       return 1;
   }
   if (tree1 == NULL && tree2 != NULL){
       return 0;
   }
   else if (tree1 != NULL && tree2 == NULL){
       return 0;
   }

   if (tree1->item != tree2->item){
       return 0;
   }
   else if (identical(tree1->left, tree2->left) == 0){
       return 0;
   }
   else if (identical(tree1->right, tree2->right) == 0){
       return 0;
   }
   else return 1;
}
/////////////////////////////////////////////////////////////////////////////////
int maxHeight(BTNode *node){ //2
   int lheight, rheight;

    if(node == NULL){
        return -1;
    }
    else{
        lheight = maxHeight(node->left);
        rheight = maxHeight(node->right);

        if(lheight > rheight) return lheight+1;
        else{
            return rheight+1;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////
int maxDepth(BTNode *node){ //3
    if(node == NULL){
        return -1;
    }
    else{
        int ldepth = maxDepth(node->left);
        int rdepth = maxDepth(node->right);

        if(ldepth > rdepth) return ldepth+1;
        else{
            return rdepth+1;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
int countOneChildNodes(BTNode *node){ //4
   int count;
    count = 0;
    if(node == NULL)
        return count;
    if((node->left == NULL && node->right != NULL)||(node->left != NULL && node->right == NULL)){
        count = 1;
    }
    return (count + countOneChildNodes(node->left)+countOneChildNodes(node->right));
}
///////////////////////////////////////////////////////////////////////////////////
int sumOfOddNodes(BTNode *node){ //5
    int sum;
    if(node == NULL)
        return 0;
    sum = 0;
    if(abs(node->item) %2 == 1)
        sum = node->item;
    return (sum + sumOfOddNodes(node->left)+ sumOfOddNodes(node->right));
}
//////////////////////////////////////////////////////////////////////////////////
void mirrorTree(BTNode *node){ //6
	BTNode *temp;
	if (node == NULL)
	return;
	// Swap left and right BTNode pointers
	// Using pre-order traversal
/*
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirrorTree(node->left);
	mirrorTree(node->right);
*/
	// Using post-order traversal
	/*
	 mirrorTree(node->left);
	 mirrorTree(node->right);
	 temp = node->left;
	 node->left = node->right;
	 node->right = temp;
	  */

	// What about using in-order traversal?
	mirrorTree(node->left);
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirrorTree(node->left);
}

///////////////////////////////////////////////////////////////////////////////////////////////
int hasGreatGrandchild(BTNode *node){ //9
	int l, r;
	// Calculate the height of each node in the tree
	// Print out (data stored in) node that has height > n
	if (node == NULL)
		return -1;
	l = hasGreatGrandchild(node->left);
	r = hasGreatGrandchild(node->right);

	if (r > l)
		l = r;
	if (l > 1)
		printf("%d ", node->item);
	return (l + 1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void printSmallerValues(BTNode *node, int m){ //7
	if (node==NULL) return;
	if (node->item<m)
	printf("%d,", node->item);
	 printSmallerValues(node->left, m);
	 printSmallerValues(node->right, m);
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
int smallestValue(BTNode *node){ //8
	int l,r;
	if (node==NULL)
		return 100000;
	l=smallestValue(node->left);
	r=smallestValue(node->right);
	if (l<node->item && l<r)
		return l;
	else if (r<node->item && r<l)
		return r;
	else return node->item;
}

///////////////////////////////////////////////////////////////////////////////
void levelOrderTraversal(BSTNode* root){ //10
    Queue q;
    q.head=NULL;
    q.tail=NULL;
    BSTNode *temp;
    temp = root;

    if(temp != NULL){
          enqueue(&q.head,&q.tail,temp);
          while(!isEmpty(q.head)){
              temp=dequeue(&q.head,&q.tail);
              printf("%d ",temp->item);
              if(temp->left!=NULL)
                  enqueue(&q.head,&q.tail,temp->left);
              if(temp->right!=NULL)
                  enqueue(&q.head,&q.tail,temp->right);
          }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void inOrderTraversal(BSTNode *root){ //11
	if (root == NULL){
		return;
	}
	Stack tmp;
	tmp.top=NULL; //1
	BSTNode *cur;
	cur = root; //2

	while ( !(cur == NULL && isEmpty(&tmp) ) ) {
		while (cur != NULL){ //3
			push(&tmp, cur);
			cur = cur->left;
		}
		if (cur==NULL && !isEmpty(&tmp) ){ //4
			cur = pop(&tmp); //4a
			printf("%d ", cur->item); //4b
			cur = cur->right;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void preOrderIterative(BSTNode *root){ //12
	Stack s;
	BSTNode *temp;
	s.top = NULL;
	temp = root;

	if (temp == NULL)
		return;
    push(&s, temp);

	do
	{
	    temp = pop(&s);
	    printf("%d ",temp->item);

	    if(temp->right != NULL)
            push(&s,temp->right);
        if(temp->left != NULL)
            push(&s,temp->left);

	} while (!isEmpty(&s));
}
///////////////////////////////////////////////////////////////////////////////
void postOrderIterativeS1(BSTNode *root){ //13
	 if (root == NULL){
		 return;
	 }
	 Stack tmp;
	 tmp.top=NULL;
	do{
		 while (root!=NULL){
			//push root's right child then root to stack
			if (root->right != NULL){
				push(&tmp, root->right);
			}
			push(&tmp, root);
			//set root as root's left child
			root = root->left;
	 	}
		//pop item from stack and set as root
		root = pop(&tmp);

		//if popped item has right child & right child top of stack
		if (root->right != NULL && (peek(&tmp) == root->right) ){
			//then remove right child from stack, push root back
			pop(&tmp);
			push(&tmp, root);
			//set root as right child
			root = root->right;
		}
		else{
			//print root's data and set root as NULL
			printf("%d ", root->item);
			root = NULL;
		}
	}
	while (!isEmpty(&tmp));
}
///////////////////////////////////////////////////////////////////////////////
void postOrderIterativeS2(BSTNode *root){ //14
	 if (root == NULL){
		 return;
	 }
	 Stack s1,s2;
	 s1.top = NULL;
	 s2.top = NULL;
	 BSTNode *tmp;
	 tmp = NULL;

	push(&s1, root);
	while(!isEmpty(&s1) ){
		tmp = pop(&s1);
		push(&s2, tmp);
		if (tmp->left != NULL){
			push(&s1, tmp->left);
		}
		if (tmp->right != NULL){
			push(&s1, tmp->right);
		}
	}
	while (!isEmpty(&s2)){
		printf("%d ", pop(&s2)->item);
	}
}
///////////////////////////////////////////////////////////////////////////////
void printBSTInOrder(BTNode *node){ //15
	if (node==NULL)
		return;

	printBSTInOrder(node->left );
	printf("%d, ", node->item);
	printBSTInOrder(node->right);

	return;

}
/////////////////////////////////////////////////////////////////
int isBST(BTNode *node, int min, int max){ //16
    // the item stored in node has to be smaller than max and larger than min
	if (node==NULL)
		return 1;
	if (node->item >= max || node->item <= min) //the node's value should belong to (min, max).
		return 0;

	// its left node should be smaller than node->item
	// its right node should be larger than node->item
	return isBST(node->left,min, node->item)&& isBST(node->right,node->item, max) ;

}
/////////////////////////////////////////////////////////////////

void insertBSTNode(BSTNode **node, int value){
	if (*node == NULL)
	{
		*node = malloc(sizeof(BSTNode));

		if (*node != NULL) {
			(*node)->item = value;
			(*node)->left = NULL;
			(*node)->right = NULL;
		}
	}
	else
	{
		if (value < (*node)->item)
		{
			insertBSTNode(&((*node)->left), value);
		}
		else if (value >(*node)->item)
		{
			insertBSTNode(&((*node)->right), value);
		}
		else
			return;
	}
}

//////////////////////////////////////////////////////////////////////////////////

void push(Stack *stack, BSTNode * node)
{
	StackNode *temp;

	temp = malloc(sizeof(StackNode));

	if (temp == NULL)
		return;
	temp->data = node;

	if (stack->top == NULL)
	{
		stack->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack->top;
		stack->top = temp;
	}
}

BSTNode * pop(Stack * s)
{
	StackNode *temp, *t;
	BSTNode * ptr;
	ptr = NULL;

	t = s->top;
	if (t != NULL)
	{
		temp = t->next;
		ptr = t->data;

		s->top = temp;
		free(t);
		t = NULL;
	}

	return ptr;
}

BSTNode * peek(Stack * s)
{
	StackNode *temp;
	temp = s->top;
	if (temp != NULL)
		return temp->data;
	else
		return NULL;
}

int isEmpty(Stack *s)
{
	if (s->top == NULL)
		return 1;
	else
		return 0;
}


void removeAll(BSTNode **node)
{
	if (*node != NULL)
	{
		removeAll(&((*node)->left));
		removeAll(&((*node)->right));
		free(*node);
		*node = NULL;
	}
}