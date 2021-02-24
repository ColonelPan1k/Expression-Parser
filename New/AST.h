#ifndef AST_H
#define AST_H

#include "Tokens.h"

typdef struct Node{
        Token Data;
        struct Node* left;
        struct Node* right;
}Node;

typdef struct AST {
        Node* head;
}AST;

Node* createNode(Token data);
int processAST(Node* node);


#endif
