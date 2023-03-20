CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lcunit
TARGET = motcache
TEST_TARGETS = test_search test_grid test_filehandler
SRC = search.c grid.c filehandler.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test_search: test_search.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_grid: test_grid.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_filehandler: test_filehandler.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: test
test: $(TEST_TARGETS)
	@echo "Running CUnit tests..."
	@./test_search
	@./test_grid
	@./test_filehandler
	@echo "Running Bats tests..."
	@bats test_main.bats

.PHONY: clean
clean:
	rm -f $(TARGET) $(TEST_TARGETS) *.o
