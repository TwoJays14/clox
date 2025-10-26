//
// Created by Jermaine on 24/10/2025.
//

#include "arena.h"

#include <stdlib.h>
#include <string.h>

Arena* arena_create(const size_t capacity) {
  Arena* arena = malloc(sizeof(Arena));

  if (arena == NULL) {
    return NULL;
  }

  arena->buffer = malloc(capacity);
  if (arena->buffer == NULL) {
    free(arena);
    return NULL;
  }

  arena->capacity = capacity;
  arena->offset = 0;

  return arena;
};

char* arena_alloc(Arena* arena, const size_t size) {
  if (arena->offset + size > arena->capacity) {
    return NULL;
  }

  // calculate pointer to memory chunk that will be allocated
  char* ptr = arena->buffer + arena->offset;
  // increment offset by number of bytes requested
  arena->offset += size;

  return ptr;
};

void arena_free(Arena* arena) {
  if (arena == NULL) {
    return;
  }

  free(arena->buffer);
  free(arena);
};

char* arena_strdup(Arena* arena, const char* str) {
  // calculate length of string
  const size_t len = strlen(str) + 1;

  // request chunk of memory from arena
  char* copy = arena_alloc(arena, len);
  if (copy == NULL) {
    return NULL;
  }

  // copy lexeme value to arena;
  strcpy(copy, str);
  return copy;
};