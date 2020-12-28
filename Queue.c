#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

DL_node* createDLnode(char data){
        DL_node* newDL = (DL_node*)malloc(sizeof(DL_node));

        newDL->data = data;
        newDL->next = NULL;
        newDL->prev = NULL;

        return newDL;
}

Queue*
createQueue(){
        Queue* newQ = (Queue*)malloc(sizeof(Queue));
        newQ->front = NULL;
        newQ->back = NULL;

        return newQ;
}

void
enqueue(Queue* q, char data){
        DL_node* newDL = createDLnode(data);

        if (q->front == NULL){
                q->front = newDL;
        } else {
                q->back = newDL;
                newDL->next = q->back;
        }
}

char
dequeue(Queue* q){

        char data = q->front->data;
        DL_node* toFree = q->front;

        //update references
        q->front = toFree->prev;
        toFree->prev->next = NULL;

        free(toFree);
        return data;
}

char
peek(Queue* q){
        return q->front->data;
}

int
Q_isEmpty(Queue* q){
        return ((q->front == NULL) && (q->back == NULL));
}

void
printQueue(Queue* q){
        DL_node* ref = q->front;

        while(ref->next != NULL){
                printf("%c\n", ref->data);
                ref = ref->next;
        }
}

int main(int argc, char** argv){
        Queue* test = createQueue();

        enqueue(test, 'a');
        printf("Enqueue 'a'\n");
        enqueue(test, 'b');
        printf("Enqueue 'b'\n");        
        enqueue(test, 'c');
        printf("Enqueue 'c'\n");
        
        printQueue(test);

        dequeue(test);
        dequeue(test);

        printQueue(test);
        
        
}
