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
char*
parse(char* expression){

        Stack* st = createStack();
        int result = 0;

        for (int i = 0; i < strlen(expression); ++i){
                if (expression[i] >= '0' && expression[i] <= '9'){
                        printf("Pushed %i\n", expression[i] - '0');
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

        printf("%s = %i\n", expression, result);
}


int
main(int argc, char** argv){

        // 1*2+3 => 12*3+
        // 1+2*3 => 123*+
        // 1+2*(3-4) => 1234-*+
        char* testStr = "(2+3)*1-(3*4)";
        

        /* Add in strtok() parsing so this can take numbers > 9 
         * and also space deliminated expressions like: 2 + 2 instead
         * of 2+2
         */


        char* result = translate(testStr, strlen(testStr));
        
        printf("Translated Expression: %s\n", result);
}
        
