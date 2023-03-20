#include <CUnit/Basic.h>
#include "grid.h"

void test_print_unused_letters() {
  char grid[GRID_SIZE][GRID_SIZE] = {
    {'A', 'B', 'C', 'D'},
    {'E', 'F', 'G', 'H'},
    {'I', 'J', 'K', 'L'},
    {'M', 'N', 'O', 'P'}
  };
  int used[GRID_SIZE][GRID_SIZE] = {0};
  used[1][0] = 1;
  used[1][1] = 1;
  used[1][2] = 1;
  used[1][3] = 1;

  used[2][0] = 1;
  used[2][1] = 1;
  used[2][2] = 1;
  used[2][3] = 1;

  used[3][0] = 1;
  used[3][1] = 1;
  used[3][2] = 1;
  used[3][3] = 1;

  FILE *temp_file = tmpfile();
  if (temp_file == NULL) {
    CU_FAIL("Failed to create temporary file");
    return;
  }

  // Redirect stdout to the temporary file
  FILE *old_stdout = stdout;
  stdout = temp_file;

  print_unused_letters(grid, used);

  // Restore stdout
  stdout = old_stdout;

  // Read the output from the temporary file
  char output[100];
  rewind(temp_file);
  fgets(output, sizeof(output), temp_file);
  fclose(temp_file);

  CU_ASSERT_STRING_EQUAL(output, "ABCD");
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("grid_suite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "test_print_unused_letters", test_print_unused_letters)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
