#include <CUnit/Basic.h>
#include <stdio.h>
#include "filehandler.h"

void test_read_grid_from_file() {
  // Create a temporary file with a valid grid
  FILE *temp_file = tmpfile();
  if (temp_file == NULL) {
    CU_FAIL("Failed to create temporary file");
    return;
  }
  fputs("ABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\nABCDEFGHIJKLMNOP\n\nABCD\nEFGH\nIJKL\nMNOP", temp_file);
  fflush(temp_file);

  // Get the temporary file name
  char temp_file_name[L_tmpnam];
  tmpnam(temp_file_name);


  char grid[GRID_SIZE][GRID_SIZE];
  CU_ASSERT_TRUE(read_grid_from_file(temp_file_name, grid));
  CU_ASSERT_EQUAL(grid[0][0], 'A');
  CU_ASSERT_EQUAL(grid[3][3], 'D');

  fclose(temp_file);
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("filehandler_suite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "test_read_grid_from_file", test_read_grid_from_file)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
