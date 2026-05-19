CC = gcc
CFLAGS = -Wall -Wextra -pedantic

OBJ = Simon.o Jogo.o Pilha.o Carta.o Baralho.o Interface.o

Simon: $(OBJ)
	$(CC) $(CFLAGS) -o Simon $(OBJ)

Simon.o: Simon.c
Jogo.o: Jogo.c
Pilha.o: Pilha.c
Carta.o: Carta.c
Baralho.o: Baralho.c
Interface.o: Interface.c

clean:
	rm -f *.o Simon