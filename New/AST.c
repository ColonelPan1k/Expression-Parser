#include <stdio.h>
#include <stdlib.h>
#include "Tokens.h"

typedef struct Node{
        Token data;
        struct Node* left;
        struct Node* right;
}Node;


Node* createNode(Token data){
        Node* newToken = malloc(sizeof(Node));
        newToken->data = data;

        return newToken;
}

int processAST(Node* node){
        if (node->data.type == NUMBER){
                return atoi(node->data.lexeme);
        }

        switch(node->data.type){
        case PLUS: return processAST(node->left) + processAST(node->right); break;
        case MINUS: return processAST(node->left) - processAST(node->right); break;
        case STAR: return processAST(node->left) * processAST(node->right); break;
        case SLASH: return processAST(node->left) / processAST(node->right); break;
        }
}

int main(){
        // I haven't made the Tokens => AST program yet so
        // this is just for testing

        Token* token1 = newToken(PLUS, "+", NULL, 1);
        Token* token2 = newToken(MINUS, "-", NULL, 1);

        Token* token2a = newToken(NUMBER, "20", NULL, 1);
        Token* token2b = newToken(NUMBER, "7", NULL, 1);

        Token* token3 = newToken(STAR, "*", NULL, 1);
        Token* token4 = newToken(NUMBER, "2", NULL, 1);
        Token* token5 = newToken(NUMBER, "3", NULL, 1);

        Node* node1 = createNode(*token1);
        Node* node2 = createNode(*token2);

        Node* node2a = createNode(*token2a);
        Node* node2b = createNode(*token2b);

        Node* node3 = createNode(*token3);
        Node* node4 = createNode(*token4);
        Node* node5 = createNode(*token5);

        node1->left  = node2;

        node2->left = node2a;
        node2->right = node2b;

        node1->right = node3;

        node3->left  = node4;
        node3->right = node5;
        /*
              +       node 1
             / \      /    \
            1   *  node2   node 3
               / \         /    \
              2   3      node4  node 5
        */
        printf("Result: %i\n", processAST(node1));



}
