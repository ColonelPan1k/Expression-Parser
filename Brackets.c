/* 
 * This is a very simple CLI program to check bracket balance.
 * I'm using it mainly as a test for my tiny stack library.
 * 
 * This program is really bad and the code is gross but it works 
 * so I'll fix it later.  It's not really that important if it's 
 * pretty or not.
 * 
 */

#include <stdio.h>
#include "Stack.h"

int
main(int argc, char** argv){


        FILE *fp;
        fp = fopen(argv[1], "r");

        Stack* bracketCheck = createStack();
        char c;

        // this is one case where a contains(char, "{[()]}")
        // would really help out
        while ((c = fgetc(fp)) != EOF){
                if (c == '{'){
                        push(bracketCheck, '{');
                }

                else if(c == '}'){
                        if (isEmpty(bracketCheck)){
                                printf("%c error in %s\n", c, argv[1]);
                                break;
                        } else {
                                pop(bracketCheck);
                        }
                }
                
        }

        if (!isEmpty(bracketCheck)){
                printf("%c error in %s\n", pop(bracketCheck), argv[1]);
        } else {
                printf("Your brackets are fine");
        }

        

        return 0;
}
