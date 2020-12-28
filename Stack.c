/* A small library for using stacks in C
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        char data;
        struct Node* next;
}Node;

typedef struct Stack{
        Node* top;
}Stack;

Node*
createNode(char data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        return newNode;
}

Stack*
createStack(){
        Stack* newStack = (Stack*)malloc(sizeof(Stack));
        newStack->top = NULL;

        return newStack;
}

void
push(Stack* st, char data){
        Node* newNode = createNode(data);

        newNode->next = st->top;
        st->top = newNode;
}

char
pop(Stack* st){
        Node* toPop = st->top;
        
        char popData = toPop->data;
        st->top = toPop->next;
        
        free(toPop);
        return popData;
}

char
S_peek(Stack* st){
        return st->top->data;
}

int
printStack(Node* node){
        if (node == NULL){
                return 0;
        }

        printf("%c\n", node->data);

        printStack(node->next);
}

int
S_isEmpty(Stack* st){
        return (st->top == NULL);
}
