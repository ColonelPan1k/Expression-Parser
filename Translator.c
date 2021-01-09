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
        } else if (opTop == '+' || opTop == '-') {
                topPrecedence = 1;
        } else {
                topPrecedence = 0;
        }

        if (incPrecedence > topPrecedence ){
                push(opStack, incoming);
                
                                                      
        } else if (incPrecedence < topPrecedence ){
                char toAdd = pop(opStack);
                enqueue(q, toAdd);
                push(opStack,incoming);
        }
}

char*
translate(char* expression, int len){

        /* Since there's no easy way to do 
         * += for strings in C, I'm going to 
         * just use a queue for this.  
         * It's not ideal, but it works for now.
         */

        // The main stack 
        Stack* st = createStack();
        
        Queue* q = createQueue();
        char* output = (char*)calloc(1, sizeof(char) * len);
        char parenChar;
        
        for (int i = 0; i < len; ++i){
                char ch = expression[i];


                switch(ch){
                case '+':
                case '-':
                        if(S_isEmpty(st)){
                                push(st, ch);
                                break;
                        }
                        printf("+/- found: %c\n", ch);
                        processOp(st, q, ch, 1);
                        break;

                        
                case '*':
                case '/':
                        if (S_isEmpty(st)){
                                push(st, ch);
                                break;
                        }
                        processOp(st, q, ch, 2);
                        break;

                        
                case '(':
                        push(st, ch);
                        break;
                case ')':
                        printStack(st->top);
                        while((!(S_isEmpty(st)) && (parenChar = pop(st)) != '(')){
                                enqueue(q, parenChar);
                        }

                        break;

                default:
                        enqueue(q, ch);
                       
                }
        }
                                             
        // Push the final stack to the output queue
        while(!(S_isEmpty(st))){
                enqueue(q, pop(st));
        }

        // Dequeue the output queue to an output string
        int i = 0;
        while(!(Q_isEmpty(q))){
                output[i] = dequeue(q);
                ++i;
        }


        
        return output;

}
