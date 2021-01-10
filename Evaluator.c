#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Translator.h"

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

int
parse(char* expression){
        Stack* st = createStack();

        for (int i = 0; i < strlen(expression); ++i){
                char ch = expression[i];

                switch(ch){
                        
                case '+':
                        push(st, add(pop(st), pop(st)));
                        break;
                case '-':
                        push(st, sub(pop(st), pop(st)));
                        break;

                case '*':
                        push(st, mult(pop(st), pop(st)));
                        break;
                case '/':
                        push(st, divide(pop(st), pop(st)));
                        break;

                default:
                        push(st, ch - '0');
                             
                }
        }

        return pop(st);
}

int main(int argc, char** argv){

        char* expression = translate(argv[1], strlen(argv[1]));
        printf("Result: %i\n", parse(expression));
}
