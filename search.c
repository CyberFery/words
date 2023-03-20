#include "search.h"

void search_word(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len) {
  search_left_to_right(grid, used, word, len);
  search_right_to_left(grid, used, word, len);
  search_top_to_bottom(grid, used, word, len);
  search_bottom_to_top(grid, used, word, len);
}

void search_left_to_right(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j <= GRID_SIZE - len; j++) {
      int k;
      for (k = 0; k < len; k++) {
        if (grid[i][j + k] != word[k]) {
          break;
        }
      }
      if (k == len) {
        for (k = 0; k < len; k++) {
          used[i][j + k] = 1;
        }
        return;
      }
    }
  }
}

void search_right_to_left(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = len - 1; j < GRID_SIZE; j++) {
      int k;
      for (k = 0; k < len; k++) {
        if (grid[i][j - k] != word[k]) {
          break;
        }
      }
      if (k == len) {
        for (k = 0; k < len; k++) {
          used[i][j - k] = 1;
        }
        return;
      }
    }
  }
}

void search_top_to_bottom(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len) {
  for (int i = 0; i <= GRID_SIZE - len; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      int k;
      for (k = 0; k < len; k++) {
        if (grid[i + k][j] != word[k]) {
          break;
        }
      }
      if (k == len) {
        for (k = 0; k < len; k++) {
          used[i + k][j] = 1;
        }
        return;
      }
    }
  }
}

void search_bottom_to_top(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len) {
  for (int i = len - 1; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      int k;
      for (k = 0; k < len; k++) {
        if (grid[i - k][j] != word[k]) {
          break;
        }
      }
      if (k == len) {
        for (k = 0; k < len; k++) {
          used[i - k][j] = 1;
        }
        return;
      }
    }
  }
}
