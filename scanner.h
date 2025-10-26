//
// Created by Jermaine on 21/10/2025.
//

#ifndef CLOX_SCANNER_H
#define CLOX_SCANNER_H
#include "libs/arena/arena.h"
#include "libs/data_structures/DynamicArray.h"

typedef struct Scanner {
  const char* source;
  TokenList* tokenList;
  Arena* arena;
  int start;
  int current;
  int line;
} Scanner;

// public methods
TokenList* scanTokens(Scanner* scanner);

// private methods;
Scanner* scanner_init(const char* source, Arena* arena);
void scanToken(Scanner* scanner);
void addToken(Scanner* scanner, Token token);
void tokenizeString(Scanner* scanner);
void tokenizeNumber(Scanner* scanner);
void handleMultiLineComment(Scanner* scanner);
void tokenizeIdentifier(Scanner* scanner);
char advance(Scanner* scanner); // returns next character in source code;
char peekCurrent(Scanner* scanner);
char next(Scanner* scanner);
char peekNext(Scanner* scanner);
bool isAtFileEnd(const Scanner* scanner);
bool isMatch(Scanner* scanner, char expected);
bool isNumber(char c);
bool isAlpha(char c);
bool isAlphanumeric(char c);



#endif //CLOX_SCANNER_H