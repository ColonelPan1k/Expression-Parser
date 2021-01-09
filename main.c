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

/* Just integer division for now */
int
divide(int a, int b){
        return a / b;
}

/* Find some way to make this work without a big if/else if/else block */
int
parse(char* expression){

        Stack* st = createStack();
        int result = 0;

        for (int i = 0; i < strlen(expression); ++i){
                if (expression[i] >= '0' && expression[i] <= '9'){
                        push(st, expression[i] - '0');
                } else if (expression[i] == '+'){
                        result = add( pop(st), pop(st));
                        push(st, result);
                } else if (expression[i] == '-'){
                        result = sub(pop(st), pop(st));
                        push(st, result);
                } else if (expression[i] == '*'){
                        result  = mult(pop(st), pop(st));
                        push(st, result);
                } else if (expression[i] == '/'){
                        result = divide(pop(st), pop(st));
                        push(st, result);
                } else {
                        printf("Something went wrong: %i\n", expression[i] - '0');
                }
                
        }

        return result;
}


int
main(int argc, char** argv){

        // TODO: Add strtok() for numbers higher than 10


        char* result = translate(argv[1], strlen(argv[1]));

        printf("%i\n", parse(result));

}
        
