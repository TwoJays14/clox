//
// Created by Jermaine on 25/10/2025.
//

#ifndef CLOX_DYNAMICARRAY_H
#define CLOX_DYNAMICARRAY_H
#include <stddef.h>
#include "../token/token.h"

typedef struct TokenList {
  Token* tokens;
  size_t count;
  size_t capacity;
} TokenList;

TokenList* token_list_create(size_t initial_capacity);
void token_list_append(TokenList *list, Token token);
void token_list_free(TokenList* list);

#endif //CLOX_DYNAMICARRAY_H