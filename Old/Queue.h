#ifndef QUEUE_C
#define QUEUE_C

typedef struct DL_node{
        char data;
        struct DL_node* next;
        struct DL_node* prev;
} DL_node;

typedef struct Queue{
        DL_node* front;
        DL_node* back;
} Queue;


DL_node* createDLnode(char data);
Queue* createQueue();
void enqueue(Queue* q, char data);
char dequeue(Queue* q);
char Q_peek(Queue* q);
int Q_isEmpty(Queue* q);
void printQueue(DL_node* front);

#endif 
