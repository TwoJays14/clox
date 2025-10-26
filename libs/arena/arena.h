//
// Created by Jermaine on 24/10/2025.
//

#ifndef CLOX_ARENA_H
#define CLOX_ARENA_H
#include <stddef.h>

typedef struct Arena {
  char* buffer; // ptr to memory block
  size_t capacity; // total bytes of memory
  size_t offset; // how much memory used
} Arena;

Arena* arena_create(size_t capacity);
char* arena_alloc(Arena* arena, size_t size);
void arena_free(Arena* arena);
char* arena_strdup(Arena* arena, const char* str);


#endif //CLOX_ARENA_H