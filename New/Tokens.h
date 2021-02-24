#ifndef TOKEN_H
#define TOKEN_H

typedef enum TokenType{
                       PLUS, MINUS, STAR, SLASH,
                       L_PAREN, R_PAREN, END,
                       NUMBER

}TokenType;


typedef struct Token{
        TokenType type;
        char* lexeme;
        void* literal;
        int line;
}Token;

Token* newToken(TokenType type, char* lexeme, void* literal, int line);

#endif
