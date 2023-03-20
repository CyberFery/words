#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "grid.h"
#include <stdbool.h>

bool read_grid_from_file(const char *filename, char grid[GRID_SIZE][GRID_SIZE]);
bool check_empty_line(FILE *file);
char *read_word_from_file(FILE *file, char *word, int max_len);

#endif
