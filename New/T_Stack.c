#include <stdlib.h>
#include "T_Stack.h"
#inlclude "Tokens.h"

Stack* createStack(){
        Stack* newStack = malloc(sizeof(Stack));
        newStack->top = NULL;
}

S_Node* s_createNode(Token* data){
        S_Node* newNode = malloc(sizeof(S_Node));
        newNode->next = NULL;

        return newNode;
}

void push(Stack* st, Token* token){
        // Create a new node from the incoming token
        S_Node* tokenNode = s_createNode(token);

        tokenNode->next = st->top;
        st->top = tokenNode;
}

// Should this return a pointer to a token or just a copy
// the top token? Try both
// Should I free the top node so it's actually gone, not just
// hanging around on the heap?
Token* pop(Stack* st){

        // TODO: Figure out pop()

}

Token* peek(Stack* st){

}

int main(){
        Stack* test = createStack();
        push(test, newToken(NUMBER, "2", NULL, 1));
        push(test, newToken(NUMBER, "1", NULL, 1));
        push(test, newToken(NUMBER, "0", NULL, 1));

        printf("Pushed 3 tokens\n");

        Token* popToken = pop(test);
        printf("%s\n", popToken->lexeme);

        Token* popToken2 = pop(test);
        printf("%s\n", popToken->lexeme);

        Token* popToken3 = pop(test);
        printf("%s\n", popToken->lexeme);
}
