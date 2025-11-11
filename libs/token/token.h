//
// Created by Jermaine on 21/10/2025.
//

#ifndef CLOX_TOKEN_H
#define CLOX_TOKEN_H

typedef enum TokenType {
  // Single char tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or more char tokens.
  BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL, GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,

  // Literals
  IDENTIFIER, STRING, NUMBER,

  // Keywords
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR, PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, EOF1
} TokenType;

typedef struct Literal {
  enum {
    LIT_NUMBER,
    LIT_STRING,
    LIT_CHAR,
    LIT_BOOL,
    LIT_NONE
  } type;
  union {
    double number;
    bool boolean;
    char* string;
    char character;
  } value;
} Literal;

typedef struct Token {
  TokenType tokenType;
  char* lexeme;
  Literal literal;
  int line;
} Token;

Token token_create(TokenType tokenType, char* lexeme, Literal literal, int line);

Literal literal_number_create(double number);

Literal literal_boolean_create(bool boolean);

Literal literal_string_create(char* string);

Literal literal_char_create(char character);

Literal literal_none_create();



#endif //CLOX_TOKEN_H