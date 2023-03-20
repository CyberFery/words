#include <CUnit/Basic.h>
#include "filehandler.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void create_temporary_valid_file(char *filename) {
    strcpy(filename, "tempfile.txt");

    FILE *file = fopen(filename, "w+");
    if (!file) {
        perror("fopen");
        return;
    }

    // Add valid grid content to the temporary file
    char grid_content[GRID_SIZE][GRID_SIZE] = {
        "abcdefghijkl",
        "mnopqrstuvwx",
        "yzABCDEFGHIJK",
        "LMNOPQRSTUVWX",
        "YZabcdefghijk",
        "lmnopqrstuvwx",
        "YZABCDEFGHIJK",
        "lmnopqrstuvwx",
        "yzABCDEFGHIJK",
        "LMNOPQRSTUVWX",
        "yzabcdefghijk",
        "lmnopqrstuvwx"
    };

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            fputc(grid_content[i][j], file);
        }
        fputc('\n', file);
    }

    fputs("\n", file); // Empty line after the grid
    fputs("word1\n", file);
    fputs("word2\n", file);

    fclose(file);
}








void test_read_temporary_valid_file(void) {
    char filename[15];
    create_temporary_valid_file(filename);

    char grid[GRID_SIZE][GRID_SIZE];
    CU_ASSERT_TRUE(read_grid_from_file(filename, grid));

    remove(filename);
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

    if (NULL == CU_add_test(pSuite, "test_read_temporary_valid_file", test_read_temporary_valid_file)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
