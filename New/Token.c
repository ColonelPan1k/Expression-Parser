xb#include <stdlib.h>
#include "Tokens.h"

Token* newToken(TokenType type, char* lexeme, void* literal, int line){
        Token* newToken = malloc(sizeof(Token));

        newToken->type = type;
        newToken->lexeme = lexeme;
        newToken->literal = literal;
        newToken->line = line;

        return newToken;
}
