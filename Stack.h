#ifndef STACK_C
#define STACK_C

typedef struct Node{
        char data;
        struct Node* next;
}Node;

typedef struct Stack{
        Node* top;
}Stack;

Node* createNode(char data);
Stack* createStack();
void push(Stack* st, char data);
char pop(Stack* st);
char S_peek(Stack* st);
int printStack(Node* node);
int S_isEmpty(Stack* st);

#endif
