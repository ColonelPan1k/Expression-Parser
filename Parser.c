/* Right now this is just an implementation of Dijkstra's shunting yard algo
 * for converting an incoming infix notation equation to postfix
 *
 * I think I just spent like an hour making a queue implementation when I 
 * could have just used a god damn for loop.
 * no reason for a data structure when you'll never actually need to enque/dequeue anything
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Stack.h"



// I just needed this, it's hacky and doesn't really belong.
// I'll clean it later
int
contains(char c, char* str){
        for(int i = 0; i < strlen(str); ++i){
                if (c == str[i]){
                        return 1;
                } 
        }
        return 0;
}


char*
shuntingYard(char* infix){

        Stack* operatorStack = createStack();


        int len = strlen(infix);
        char* outputString = "Poopy";

        for (int i = 0; i < len; ++i){
                if (!isspace(infix[i])){
                        if (infix[i] >= 48 && infix[i] <= 57){
                                printf("%c ", infix[i]);
                        } else if (contains(infix[i], "+-/*")){
                                push(operatorStack, infix[i]);
                        }
                }
        }

        while(!S_isEmpty(operatorStack)){
                printf("%c ", pop(operatorStack));
        }

        return outputString;
}
       
int main(int argc, char** argv){

        shuntingYard(argv[1]);
}
