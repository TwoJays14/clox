//
// Created by Jermaine on 25/10/2025.
//

#include "DynamicArray.h"

#include <stdlib.h>

TokenList* token_list_create(const size_t initial_capacity) {
  TokenList *token_list = malloc(sizeof(TokenList));

  if (token_list == NULL) {
    return NULL;
  };

  token_list->tokens = malloc(sizeof(Token) * initial_capacity);
  if (token_list->tokens == NULL) {
    free(token_list);
    return NULL;
  }

  token_list->capacity = initial_capacity;
  token_list->count = 0;

  return token_list;
};


void token_list_append(TokenList *list, const Token token) {
  if (list == NULL) {
    return;
  };

  if (list->count >= list->capacity) {
    const size_t new_capacity = list->capacity * 2;
    Token* new_tokens = realloc(list->tokens, sizeof(Token) * new_capacity);
    if (new_tokens == NULL) {
      return;
    }

    list->tokens = new_tokens;
    list->capacity = new_capacity;
  }

  list->tokens[list->count++] = token;

};


void token_list_free(TokenList* list) {
  if (list == NULL) {
    return;
  };

  free(list->tokens);
  free(list);
};