#ifndef STACK
#define STACK

typedef struct Node{
        char data;
        struct Node* next;
}Node;

typedef struct Stack{
        Node* top;
}Stack;

Node* createNode(char data);
Stack* createStack(char data);
void push(Stack* st, char data);
char pop(Stack* st);
int printStack(Node* node);
