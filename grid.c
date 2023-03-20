#include <stdio.h>
#include "grid.h"

void print_unused_letters(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE]) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (!used[i][j]) {
        printf("%c", grid[i][j]);
      }
    }
  }
  printf("\n");
}
