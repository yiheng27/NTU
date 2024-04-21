//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	if (*node == NULL){ //if tree empty
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
	}

	if (value < (*node)->item){ //if value smaller than node, go left
        insertBSTNode(&(*node)->left, value);
        return;
	}
	if (value > (*node)->item){ //if value larger than node, go right
        insertBSTNode(&(*node)->right, value);
        return;
	}
	if (value == (*node)->item){ //if same don't insert
        printf("Already exists.\n");
        return;
	}

    return;
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	if (node==NULL){
        return;
	}

	printBSTInOrder(node->left);
	printf("%d ", node->item);
	printBSTInOrder(node->right);

	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	if (node == NULL){
        return 1;
	}
	if (node->item >= max || node->item <= min){
        return 0;
	}
    if (isBST(node->left,min,node->item) == 0){
        return 0;
    }
    if (isBST(node->right,node->item,max) == 0){
        return 0;
    }
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	BTNode *cur;
	if (node == NULL){
        printf("unable to find.\n");
        return NULL;
	}
	if (value < node->item){ //if value less than item go left
        node->left=removeBSTNode(node->left,value);
	}
	if (value > node->item){ //if value more than item go right
        node->right=removeBSTNode(node->right,value);
	}
	else{
        if (node->left != NULL && node->right != NULL){ //2 children
            cur = findMin(node->right); //successor
            node->item = cur->item; //swap
            removeBSTNode(node->right, cur->item); //remove node from right subtree
        }
        else { //1 or no children
            cur = node;
            if (cur->left != NULL){ //child left
                node = node->left; //swap
            }
            else if (cur->right !=NULL){
                node = node->right;
            }
            free(cur);
        }
	}
	return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	if (p->left != NULL){
        return findMin(p->left);
    }
    else{
        return p;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
