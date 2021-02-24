#ifndef LEXER_H
#define LEXER_H

typedef struct Lexer{
        char* source;
        Token* tokens;
        int start;
        int current;
        int line;
        int tokenPos;
} Lexer;


#endif
