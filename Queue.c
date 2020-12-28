#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        if (Q_isEmpty(q)){
                q->front = newDL;
                q->back = newDL;
        } else {
                newDL->next = q->back;
                q->back->prev = newDL;
                q->back = newDL;
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
Q_peek(Queue* q){
        return q->front->data;
}

int
Q_isEmpty(Queue* q){
        return ((q->front == NULL) && (q->back == NULL));
}

void
printQueue(DL_node* front){
        if (front == NULL){
                return;
        }
        printf("%c\n", front->data);

        printQueue(front->prev);
}
