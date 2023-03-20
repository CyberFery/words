CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -O2

SRC = main.c grid.c search.c filehandler.c
OBJ = $(SRC:.c=.o)
EXEC = wordsearch

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
