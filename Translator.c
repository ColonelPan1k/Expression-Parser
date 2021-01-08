/* Translator.c
 * Infix to postfix translator for evaluator.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void
processOp(Stack* opStack, Queue* q, char incoming, int incPrecedence){
              
        char opTop = S_peek(opStack);
        int topPrecedence;

        if (opTop == '*' || opTop == '/'){
                topPrecedence = 2;
        } else {
                topPrecedence = 1;
        }

        if (incPrecedence > topPrecedence ){
                push(opStack, incoming);
                
                                                      
        } else if (incPrecedence < topPrecedence ){

                char toAdd = pop(opStack);
                printf("toAdd: %c\n", toAdd);
                enqueue(q, toAdd);
                push(opStack, incoming);


        }
}

char*
translate(char* expression, int len){

        Stack* opStack = createStack();
        

        /* There's probably a better way to do this but 
         * as of right now I can't figure out how to do it
         * with strings so I'm just going to use a queue.
         */

        // The output queue
        Queue* q = createQueue();

        char* output = (char*)calloc(1, sizeof(char) * len);
        
        for (int i = 0; i < len; ++i){
                char ch = expression[i];

                switch(ch){
                case '+':
                case '-':
                        if (S_isEmpty(opStack)){
                                push(opStack, ch);
                                break;
                        }
                        processOp(opStack, q, ch, 1);
                        break;

                case '*':
                case '/':
                        if (S_isEmpty(opStack)){
                                push(opStack, ch);
                                break;
                        }
                        processOp(opStack, q, ch, 2);
                        break;

                default:
                        enqueue(q, ch);
                }
        }

        while(!(S_isEmpty(opStack))){
                char toAdd = pop(opStack);
                printf("%c\n", toAdd);
                enqueue(q, toAdd);
        }

        int i = 0;

        printf("dequeue: %c\n", dequeue(q));
        printf("dequeue: %c\n", dequeue(q));
        printf("dequeue: %c\n", dequeue(q));
        printf("dequeue: %c\n", dequeue(q));

        
        return output;

}

