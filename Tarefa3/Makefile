# Makefile

CC=gcc

CFLAGS=-Wall -Wextra -Iinclude

SRC=src/main.c src/parser.c src/dsl.c

OBJ=$(SRC:.c=.o)

jogo: $(OBJ)
	$(CC) $(OBJ) -o jogo

clean:
	rm -f src/*.o jogo