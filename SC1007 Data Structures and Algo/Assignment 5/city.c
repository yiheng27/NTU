#include<stdio.h>
#include <stdlib.h>

int* city_population (int N, int* population, int** road, int Q, int** cities) ;

int main() {
    int N;
    scanf("%d", &N);
    int i_population;
    int *population = (int *)malloc(sizeof(int)*(N));
    for(i_population = 0; i_population < N; i_population++)
    	scanf("%d", &population[i_population]);
    int i_road, j_road;
    int **road = (int **)malloc((N-1)*sizeof(int *));
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	road[i_road] = (int *)malloc((2)*sizeof(int));
    }
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	for(j_road = 0; j_road < 2; j_road++)
    	{
    		scanf("%d", &road[i_road][j_road]);
    	}
    }
    int Q;
    scanf("%d", &Q);
    int i_cities, j_cities;
    int **cities = (int **)malloc((Q)*sizeof(int *));
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	cities[i_cities] = (int *)malloc((3)*sizeof(int));
    }
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	for(j_cities = 0; j_cities < 3; j_cities++)
    	{
    		scanf("%d", &cities[i_cities][j_cities]);
    	}
    }

    int* out_ = city_population(N, population, road, Q, cities);
    printf("%d", out_[0]);
    int i_out_;
    for(i_out_ = 1; i_out_ < Q; i_out_++)
    	printf("\n%d", out_[i_out_]);
}
#include <string.h>


typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stack
{
	int size;
	StackNode *head;
} Stack;

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);

void printGraphList(Graph g);

void printGraphList(Graph g){
    int i;
    ListNode* temp;

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void enqueue(Queue *qPtr, int vertex) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = vertex;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}

void push(Stack *sPtr, int vertex)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}


int* city_population (int N, int* population, int** road, int Q, int** cities)
{
    int *answer = malloc(Q * sizeof(int));

    Graph g;
    g.V=N;
    g.E=N-1;
    g.list= (ListNode**) malloc((N+1) * sizeof(ListNode*));

    ListNode *cur = NULL;
    //printf("preadj\n");
    for (int i=0;i<N-1;i++){ //insert adj list from road
        if(g.list[road[i][0]-1]==NULL){
            g.list[road[i][0]-1] = (ListNode *)malloc(sizeof(ListNode));
            g.list[road[i][0]-1]->vertex = road[i][1];
            g.list[road[i][0]-1]->next = NULL;
        }
        else{
            ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[road[i][0]-1];
            temp->vertex = road[i][1];
            g.list[road[i][0]-1] = temp;
        }
        //backwards
        if(g.list[road[i][1]-1]==NULL){
            g.list[road[i][1]-1] = (ListNode *)malloc(sizeof(ListNode));
            g.list[road[i][1]-1]->vertex = road[i][0];
            g.list[road[i][1]-1]->next = NULL;
        }
        else{
            ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[road[i][1]-1];
            temp->vertex = road[i][0];
            g.list[road[i][1]-1] = temp;
        }
        //printf("i: %d\n", i);
    }

    //printGraphList(g);

    int visit[N+1];
    int path[N];
    Stack s;
    s.head = NULL; //initialise stack
    s.size = 0;

    for(int i=0;i<Q;i++){ //DFS for all queries
        memset(visit, 0 , sizeof(visit)); //reset visit for each query
        memset(path, 0 , sizeof(path));
        int u = cities[i][0];
        int v = cities[i][1];
        int w = cities[i][2];
        push(&s, u); //push i into stack
        visit[u]=1; //mark vertex as visited

        do{ //dfs
            int pek = peek(s);//peek, vertex is pek
            int visited = 0;

            cur = g.list[pek-1];

            while(cur != NULL){ //iterate thorugh list of w
                if (g.list[pek-1] == NULL){ //if w has no link, break
                    break;
                }
                //printf("dfs in while\n");
                if (visit [cur->vertex] == 0){ //if unvisited in list[w]
                    push(&s, cur->vertex ); //push unvisted vertex u
                    visit[cur->vertex] = 1; //mark u as visited
                    visited = 1;
                    break; //go next
                }
                cur = cur->next;
            }
            int j=0;
            if (visited == 0){ //if no unvisited adjacent to w, pop
                int poop = peek(s);

                if (poop == v){
                    while (!isEmptyStack(s)){
                        poop = peek(s);
                        pop(&s);
                        path[j]=poop;
                        j++;
                    }
                }
                else{
                    pop(&s);
                }
            }
        }
        while (!isEmptyStack(s));

        int itr = 0;
        int k=0;
        //printf("\npath:");
        while(path[k] != 0){
            //printf("%d ",path[k]);
            if(population[path[k]-1] <= w){
                itr++;
            }
            k++;
        }
        answer[i] = itr;
        //printf("k: %d\n",k);
        //printf("a[i]: %d\n",answer[i]);
    } //end query

    return answer;
}