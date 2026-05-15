CC = gcc
CFLAGS = -g -lm -Wextra -Ilib
EXEC = Golf

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=%.o)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) *.o

run:
	./$(EXEC)
