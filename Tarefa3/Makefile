CC = gcc

CFLAGS = -Wall -Wextra -pedantic -Iinclude

SRC = src/main.c \
      src/Jogo.c \
      src/Parser.c \
      src/Dsl.c \
      src/Interface.c \
      src/Carta.c \
      src/Pilha.c \
      src/Baralho.c

OBJ = $(SRC:.c=.o)

EXEC = paciencia


$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)


src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f src/*.o $(EXEC)