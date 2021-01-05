/*
 * No guarantee this is correct or will even work
 * but it's worth a shot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int
doOp(int (*op)(int, int), int a, int b){
        return op(a, b);
}

int
add(int a, int b){
        return a + b;
}

int
sub(int a, int b){
        return a - b;
}

int
mult(int a, int b){
        return a * b;
}

int
divide(int a, int b){
        return a / b;
}

// Move to a case/switch statement or something to avoid
// the if/else blocks

// This currently works for +-*/ for numbers 1-9
// I'm working on cleaning this up and
// adding in numbers greater than 10.
char*
parse(char* expression){

        Stack* st = createStack();
        int result = 0;

        for (int i = 0; i < strlen(expression); ++i){
                // if the current char is an operand
                if (expression[i] >= '0' && expression[i] <= '9'){
                        printf("Pushed %i\n", expression[i] - '0');
                        push(st, expression[i] - '0');
                        
                } else if (expression[i] == '+'){
                        result = add(pop(st), pop(st));
                        printf("add: pushed %i\n", result);
                        push(st, result);
                        
                } else if (expression[i] == '-'){
                        result = sub(pop(st), pop(st));
                        printf("sub: pushed %i\n", result);
                        push(st, result);
                } else if (expression[i] == '*'){
                        result = mult(pop(st), pop(st));
                        printf("mult: pushed %i\n", result);
                        push(st, result);
                } else if (expression[i] == '/'){

                        result = divide(pop(st), pop(st));
                        printf("div: pushed: %i\n", result);
                        push(st, result);
                        
                } else {
                        printf("Something went wrong: %c\n", expression[i]);
                }
                

        }

        printf("%s = %i\n", expression, result);
        


}


int
main(int argc, char** argv){

        char* testStr = argv[1];

        parse(testStr);
}
        
