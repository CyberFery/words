#ifndef SEARCH_H
#define SEARCH_H

#include "grid.h"

void search_word(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len);
void search_left_to_right(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len);
void search_right_to_left(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len);
void search_top_to_bottom(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len);
void search_bottom_to_top(char grid[GRID_SIZE][GRID_SIZE], int used[GRID_SIZE][GRID_SIZE], char *word, int len);

#endif
