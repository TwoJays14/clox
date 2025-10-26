#include <stdio.h>
#include <string.h>

#include "libs/arena/arena.h"

int main() {
  Arena* arena = arena_create(1024);

  char* str1 = arena_alloc(arena, 6);
  strcpy(str1, "class");

  char* str2 = arena_alloc(arena, 7);
  strcpy(str2, "Person");

  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  printf("Arena used: %zu / %zu bytes\n", arena->offset, arena->capacity);
  arena_free(arena);
  return 0;
}
