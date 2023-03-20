#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "filehandler.h"

bool is_valid_character(char c) {
  // Check if the character is an alphabetic character.
  return isalpha(c);
}

bool read_grid_from_file(const char *filename, char grid[GRID_SIZE][GRID_SIZE]) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("Error: could not open file %s\n", filename);
    return false;
  }

  for (int i = 0; i < GRID_SIZE; i++) {
    if (fgets(grid[i], GRID_SIZE + 2, file) == NULL) {
      printf("Error: file %s does not contain a valid grid\n", filename);
      fclose(file);
      return false;
    }
    if (strlen(grid[i]) != GRID_SIZE + 1) {
      printf("Error: file %s does not contain a valid grid\n", filename);
      fclose(file);
      return false;
    }
    for (int j = 0; j < GRID_SIZE; j++) {
      if (!is_valid_character(grid[i][j])) {
        printf("Error: file %s contains invalid character(s) in the grid\n", filename);
        fclose(file);
        return false;
      }
    }
  }

  fclose(file);
  return true;
}

bool check_empty_line(FILE *file) {
  char buffer[2];
  if (fgets(buffer, sizeof(buffer), file) == NULL || buffer[0] != '\n') {
    printf("Error: file does not contain a valid empty line\n");
    return false;
  }

  return true;
}

char *read_word_from_file(FILE *file, char *word, int max_len) {
  if (fgets(word, max_len, file) == NULL) {
    return NULL;
  }

  int len = strlen(word);
  if (len > 0 && word[len - 1] == '\n') {
    word[len - 1] = '\0';
    len--;
  }

  return word;
}
