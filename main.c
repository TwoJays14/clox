#include <stdio.h>
#include <string.h>

#include "scanner.h"
#include "libs/arena/arena.h"

int main() {
  printf("> ");
  char line[100];
  scanf("%s", &line);
  Arena* arena = arena_create(1048 * 1048);
  Scanner* scanner = scanner_init(line, arena);
  const TokenList* token_list = scanTokens(scanner);
  for (int i = 0; i <= token_list->count - 1; i++) {
    printf("%s", token_list->tokens[i].lexeme);
  }
  return 0;
}
