//
// Created by Jermaine on 21/10/2025.
//

#include <stdlib.h>
#include <string.h>

#include "Scanner.h"
#include "libs/token/token.h"
#include "libs/helpers/string/string.h"

TokenList* scanTokens(Scanner* scanner) {
  if (scanner == NULL) {
    return NULL;
  }

  // iterate through source
  while (!isAtFileEnd(scanner)) {
    scanner->start = scanner->current;
  // if not scanToken
    scanToken(scanner);
  }

  // if so add EOF token to tokenList and return the list
  token_list_append(scanner->tokenList, token_create(EOF, "EOF", literal_none_create(), scanner->line));

  return scanner->tokenList;
};

void scanToken(Scanner* scanner) {
  const char currentChar = next(scanner);

  switch (currentChar) {
    case '(':
      Token left_brace_token;
      left_brace_token.line = scanner->line;
      left_brace_token.tokenType = LEFT_BRACE;

      addToken(scanner, left_brace_token);
      break;
  }
};

void addToken(Scanner* scanner, Token token) {
  if (scanner == NULL) {
    return;
  }

  token_list_append(scanner->tokenList, token);

};


Scanner* scanner_init(const char* source, Arena* arena) {
  // Allocate Scanner struct memory
  Scanner* scanner = malloc(sizeof(Scanner));
  if (scanner == NULL) {
    return NULL;
  }

  // Set source field
  scanner->source = source;
  // create token list
  scanner->tokenList = token_list_create(100);
  if (scanner->tokenList == NULL) {
    free(scanner);
    return NULL;
  }

  scanner->arena = arena;
  scanner->current = 0;
  scanner->start = 0;
  scanner->line = 1;

  return scanner;
};

bool isAtFileEnd(const Scanner* scanner) {
  return scanner->current >= strlen(scanner->source);
};

char next(Scanner* scanner) {
  //get next character in source file
  return charAt(scanner->source, scanner->current++);
};
