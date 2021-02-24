/*

Need:
=> a stack and queue library that take a lexer and work on an array of tokens
=> Shunting yard algorithm for formatting the token array
   => Create new token array with size lexer->tokenPos, free original lexer->tokens array
   and assign a new formatted token array to lexer->tokens

=> Reverse function, takes in array of tokens and returns the reverse.
   Necessary for generating a proper AST

=> AST gen function.  Should take in a properly formatted list of tokens
   and return a binary tree representation of that list

GenerateAST should accept a valid lexer and return a valid AST
There should be no reason to use any of the lexer functions


Full Pipeline;
String -> Lexer+Token Array -> Shunting yard -> PN Token Array -> Reverse array -> Generate AST -> Recursive AST Evaluation => Answer

*/

#include <stdio.h>
#include <stdlib.h>
#include "Tokens.h"
#include "Lexer.h"
#include "AST.h"
#include "T_Queue.h"

// TODO Make stack and queue for tokens

void processOp(Stack* opStack, Queue* q, Token incoming, int precedence){

}

Lexer* shuntingYard(Lexer* lexer){
        Stack* st = createStack();
        Queue* q  = createQueue();

        // TODO Fix this
        Token paren;

        for (int i = 0; i < lexer->tokenPos; ++i){
                Token* current = lexer->tokens[i];

                // current.type?
                switch(current->type){
                case PLUS:
                case MINUS:
                        processOp(st, q, current, 1); break;
                case STAR:
                case SLASH:
                        processOp(st, q, current, 2); break;
                case L_PAREN: push(st, current);
                case R_PAREN:
                        // is this valid????
                        while(!(S_isEmpty(st)) && (paren = pop(st))->type != R_PAREN){
                                enqueue(q, paren);
                        }
                case NUMBER: enqueue(q, current); break;
                default:
                        printf("Something's gone wrong\n");
                        exit(3);
                }
        }
}

Lexer* reverseTokens(Lexer* lexer){

}

/* Formats the tokens of the passed lexer*/
Lexer* formatTokens(Lexer* lexer){

}

AST* generateAST(Lexer* lexer){
        AST* newAST = createAST(lexer->tokens[0]);

        // Map the contents of the token array to an AST
        for (int i = 0; i < lexer->tokenPos; ++i){

        }


        free(lexer);
        return newAST;
}
