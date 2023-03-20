#include <CUnit/Basic.h>
#include "search.h"
#include "grid.h"

void test_search_left_to_right() {
  char grid[GRID_SIZE][GRID_SIZE] = {
    {'A', 'B', 'C', 'D'},
    {'E', 'F', 'G', 'H'},
    {'I', 'J', 'K', 'L'},
    {'M', 'N', 'O', 'P'}
  };
  int used[GRID_SIZE][GRID_SIZE] = {0};
  search_left_to_right(grid, used, "ABCD", 4);
  CU_ASSERT_EQUAL(used[0][0], 1);
  CU_ASSERT_EQUAL(used[0][1], 1);
  CU_ASSERT_EQUAL(used[0][2], 1);
  CU_ASSERT_EQUAL(used[0][3], 1);
}

void test_search_right_to_left() {
  char grid[GRID_SIZE][GRID_SIZE] = {
    {'D', 'C', 'B', 'A'},
    {'H', 'G', 'F', 'E'},
    {'L', 'K', 'J', 'I'},
    {'P', 'O', 'N', 'M'}
  };
  int used[GRID_SIZE][GRID_SIZE] = {0};
  search_right_to_left(grid, used, "ABCD", 4);
  CU_ASSERT_EQUAL(used[0][0], 1);
  CU_ASSERT_EQUAL(used[0][1], 1);
  CU_ASSERT_EQUAL(used[0][2], 1);
  CU_ASSERT_EQUAL(used[0][3], 1);
}

void test_search_top_to_bottom() {
  char grid[GRID_SIZE][GRID_SIZE] = {
    {'A', 'E', 'I', 'M'},
    {'B', 'F', 'J', 'N'},
    {'C', 'G', 'K', 'O'},
    {'D', 'H', 'L', 'P'}
  };
  int used[GRID_SIZE][GRID_SIZE] = {0};
  search_top_to_bottom(grid, used, "ABCD", 4);
  CU_ASSERT_EQUAL(used[0][0], 1);
  CU_ASSERT_EQUAL(used[1][0], 1);
  CU_ASSERT_EQUAL(used[2][0], 1);
  CU_ASSERT_EQUAL(used[3][0], 1);
}

void test_search_bottom_to_top() {
  char grid[GRID_SIZE][GRID_SIZE] = {
    {'D', 'I', 'E', 'N'},
    {'C', 'J', 'F', 'M'},
    {'B', 'K', 'G', 'O'},
    {'A', 'L', 'H', 'P'}
  };
  int used[GRID_SIZE][GRID_SIZE] = {0};
  search_bottom_to_top(grid, used, "ABCD", 4);
  CU_ASSERT_EQUAL(used[0][0], 1);
  CU_ASSERT_EQUAL(used[1][0], 1);
  CU_ASSERT_EQUAL(used[2][0], 1);
  CU_ASSERT_EQUAL(used[3][0], 1);
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("search_suite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  if ((NULL == CU_add_test(pSuite, "test_search_left_to_right", test_search_left_to_right)) ||
      (NULL == CU_add_test(pSuite, "test_search_right_to_left", test_search_right_to_left)) ||
      (NULL == CU_add_test(pSuite, "test_search_top_to_bottom", test_search_top_to_bottom)) ||
      (NULL == CU_add_test(pSuite, "test_search_bottom_to_top", test_search_bottom_to_top))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
