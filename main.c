#include <stdio.h>
#include <string.h>
#include "grid.h"
#include "search.h"
#include "filehandler.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  char grid[GRID_SIZE][GRID_SIZE];
  int used[GRID_SIZE][GRID_SIZE] = {0};
  char word[100];

  if (!read_grid_from_file(argv[1], grid)) {
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }

  // skip grid
  for (int i = 0; i < GRID_SIZE; i++) {
    fgets(grid[i], GRID_SIZE + 2, file);
  }

  if (!check_empty_line(file)) {
    fclose(file);
    return 1;
  }

  while (read_word_from_file(file, word, sizeof(word)) != NULL) {
    search_word(grid, used, word, strlen(word));
  }

  print_unused_letters(grid, used);

  fclose(file);
  return 0;
}
