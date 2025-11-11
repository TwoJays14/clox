//
// Created by Jermaine on 21/10/2025.
//

#include "token.h"

#include <stdio.h>

Token token_create(const TokenType tokenType, char* lexeme, const Literal literal, const int line) {
  Token token;

  token.tokenType = tokenType;
  token.line = line;
  token.literal = literal;
  token.lexeme = lexeme;

  return token;
};

Literal literal_number_create(const double number) {
  Literal literal_number;

  literal_number.type = LIT_NUMBER;
  literal_number.value.number = number;

  return literal_number;
};

Literal literal_boolean_create(const bool boolean) {
  Literal literal_boolean;

  literal_boolean.type = LIT_BOOL;
  literal_boolean.value.boolean = boolean;

  return literal_boolean;
};

Literal literal_string_create(char* string) {
  Literal literal_string;

  literal_string.type = LIT_STRING;
  literal_string.value.string = string;

  return literal_string;
};

Literal literal_char_create(const char character) {
  Literal literal_character;

  literal_character.type = LIT_CHAR;
  literal_character.value.character = character;

  return literal_character;
};

Literal literal_none_create() {
  Literal literal_none;

  literal_none.type = LIT_NONE;

  return literal_none;
};

