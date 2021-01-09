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
        int result = 0;

        for (int i = 0; i < strlen(expression); ++i){
                char ch = expression[i];

                switch(ch){
                        
                case '+':
                        result = add(pop(st), pop(st));
                        push(st, result);
                        break;
                case '-':
                        result = sub(pop(st), pop(st));
                        push(st, result);
                        break;

                case '*':
                        result = mult(pop(st), pop(st));
                        push(st, result);

                        break;
                case '/':
                        result = divide(pop(st), pop(st));
                        push(st, result);
                        break;

                default:
                        push(st, ch - '0');
                             
                }
        }

        return result;
}

int main(int argc, char** argv){

        char* expression = translate(argv[1], strlen(argv[1]));
        printf("Result: %i\n", parse(expression));
}
