prog=motcache

@test "MANDOLINE" {
    run ./$prog test_files/mandoline.txt
    [ "$?" -eq 0 ]
    [ "${lines[0]}" = "MANDOLINE" ]
}

@test "VENISE" {
    run ./$prog test_files/venise.txt
    [ "$?" -eq 0 ]
    [ "${lines[0]}" = "VENISE" ]
}

@test "Invalid grid too small" {
    run ./$prog test_files/grid_too_small.txt
    [ "$?" -eq 1 ]
    [ "${lines[0]}" = "Error: file test_files/grid_too_small.txt does not contain a valid grid" ]
}

@test "Invalid grid too large" {
    run ./$prog test_files/grid_too_large.txt
    [ "$?" -eq 1 ]
    [ "${lines[0]}" = "Error: file test_files/grid_too_large.txt does not contain a valid grid" ]
}

@test "Invalid grid extra characters" {
    run ./$prog test_files/grid_extra_characters.txt
    [ "$?" -eq 1 ]
    [ "${lines[0]}" = "Error: file test_files/grid_extra_characters.txt does not contain a valid grid" ]
}

@test "Invalid grid invalid characters" {
    run ./$prog test_files/grid_invalid_characters.txt
    [ "$?" -eq 1 ]
    [ "${lines[0]}" = "Error: file test_files/grid_invalid_characters.txt contains invalid character(s) in the grid" ]
}

@test "No empty line after grid" {
    run ./$prog test_files/no_empty_line.txt
    [ "$?" -eq 1 ]
    [ "${lines[0]}" = "Error: file does not contain a valid empty line" ]
}
