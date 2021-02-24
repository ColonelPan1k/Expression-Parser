#ifndef T_STACK_H
#define T_STACK_H

// Linked list implementation of a stack
typdef struct S_Node{
        Token data;
        struct S_Node* next;
}S_Node;

typdef struct Stack{
        S_Node* top;
};

Stack* createStack();

S_Node* s_createNode(Token* data);

void push(Stack* st);

Token* pop(Stack* st);

Token* peek(Stack* st);

#endif
