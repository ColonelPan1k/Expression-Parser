#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Tokens.h"

typedef struct Lexer{
        char* source;
        Token* tokens;
        int start;
        int current;
        int line;
        int tokenPos;
} Lexer;

Lexer* createLexer(char* source){
        Lexer* newLexer = (Lexer*)malloc(sizeof(Lexer));
        // For now, just create an array of 100 tokens
        // I don't think I'll exceed that in testing.
        // A linked list of tokens would probably fit better
        newLexer->source = source;
        newLexer->tokens = malloc(sizeof(Token) * 100);
        newLexer->start = 0;
        newLexer->current = 0;
        newLexer->line = 1;
        newLexer->tokenPos = 0;

        return newLexer;
 }

char* substr(const char* src, int m, int n){
        int len = n - m;
        char * dest = (char*)malloc(sizeof(char) * (len + 1));

        for (int i = m; i < n && (*(src + i) != '\0'); ++i){
                *dest = *(src + i);
                ++dest;
        }
        *dest = '\0';
        return dest - len;
}

int isAtEnd(Lexer* lexer){
        return (lexer->current >= strlen(lexer->source));
}

char advance(Lexer* lexer){
        ++lexer->current;
        return lexer->source[lexer->current - 1];
}

char peek(Lexer* lexer){
        return lexer->source[lexer->current];
}

void addToken(Lexer* lexer, Token* token){
        lexer->tokens[lexer->tokenPos] = *token;
        ++lexer->tokenPos;
}

void addLexemeToken(Lexer* lexer, TokenType type, void* literal){
        char* text = substr(lexer->source, lexer->start, lexer->current);
        Token* toAdd = newToken(type, text, literal, lexer->line);

        lexer->tokens[lexer->tokenPos] = *toAdd;
        ++lexer->tokenPos;
}

void number(Lexer* lexer){
        while(isdigit(peek(lexer))) advance(lexer);
        addLexemeToken(lexer, NUMBER, NULL);
}

void scanToken(Lexer* lexer){
        char c  = advance(lexer);
        switch (c){
        case '(': addLexemeToken(lexer, L_PAREN, NULL); break;
        case ')': addLexemeToken(lexer, R_PAREN, NULL); break;
        case '+': addLexemeToken(lexer, PLUS, NULL); break;
        case '-': addLexemeToken(lexer, MINUS, NULL); break;
        case '*': addLexemeToken(lexer, STAR, NULL); break;
        case '/': addLexemeToken(lexer, SLASH, NULL); break;
        case ' ':
        case '\n': break;


        default:
                if (isdigit(c)) {
                        number(lexer);
                        } else {
                        printf("ERROR line %i\n", lexer->line);
                        exit(1);
                }

        }
}

void scanTokens(Lexer* lexer){
        while(!(isAtEnd(lexer))){
                lexer->start = lexer->current;
                scanToken(lexer);
        }
        addToken(lexer, newToken(END, "", NULL, lexer->line));

}

void printTokens(Lexer* lexer){
        for (int i = 0; i < lexer->tokenPos; ++i){
                printf("\nValue: %s\nToken Type: %d\n",lexer->tokens[i].lexeme, lexer->tokens[i].type);
        }
}
