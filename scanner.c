//
// Created by Jermaine on 21/10/2025.
//

#include <stdio.h>
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
  addToken(scanner, token_create(EOF1, "EOF", literal_none_create(), scanner->line));

  return scanner->tokenList;
};

//TODO: handle multi char tokens
void scanToken(Scanner* scanner) {
  const char currentChar = advance(scanner);

  switch (currentChar) {
    case '{':
      const Token left_brace_token = token_create(LEFT_BRACE, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, left_brace_token);
      break;
    case '}':
      const Token right_brace_token = token_create(RIGHT_BRACE, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, right_brace_token);
      break;
    case '(':
      const Token left_paren_token = token_create(LEFT_PAREN, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, left_paren_token);
      break;
    case ')':
      const Token right_paren_token = token_create(RIGHT_PAREN, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, right_paren_token);
      break;
    case ',':
      const Token comma_token = token_create(COMMA, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, comma_token);
      break;
    case '.':
      const Token dot_token = token_create(DOT, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, dot_token);
      break;
    case '-':
      const Token minus_token = token_create(MINUS, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, minus_token);
      break;
    case '+':
      const Token plus_token = token_create(PLUS, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, plus_token);
      break;
    case ';':
      const Token semi_colon_token = token_create(SEMICOLON, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, semi_colon_token);
      break;
    case '/':
      const Token slash_token = token_create(SLASH, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, slash_token);
      break;
    case '*':
      const Token star_token = token_create(STAR, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, star_token);
      break;
    case '!':
      const Token bang_token = token_create(BANG, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, bang_token);
      break;
    case '=':
      const Token equal_token = token_create(EQUAL, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, equal_token);
      break;
    case '>':
      const Token greater_token = token_create(GREATER, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, greater_token);
      break;
    case '<':
      const Token less_token = token_create(LESS, extractLexeme(scanner), literal_none_create(), scanner->line);
      addToken(scanner, less_token);
      break;
    case '\n':
      scanner->line += 1;
      break;
  }
};

void addToken(const Scanner* scanner, const Token token) {
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
  return scanner->current >= (int)strlen(scanner->source);
};

char advance(Scanner* scanner) {
  //get next character in source file
  return charAt(scanner->source, scanner->current++);
};

char* extractLexeme(const Scanner* scanner) {
  const int len = scanner->current - scanner->start;

  char* arena_mem = arena_alloc(scanner->arena, len + 1);
  char* lexeme = strncpy(arena_mem, &scanner->source[scanner->start], len + 1);
  lexeme[len] = '\0';

  return lexeme;
};
