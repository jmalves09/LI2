#include <stdio.h>

#include "Interface.h"


void mostrarComandos(void) {

    printf("\nCOMANDOS:\n");

    printf("m origem destino  -> mover cartas\n");

    printf("h                 -> ajuda\n");

    printf("q                 -> sair\n\n");
}


void lerComando(char *cmd,
                int *origem,
                int *destino) {

    printf("> ");

    scanf(" %c",
          cmd);

    if(*cmd == 'm') {

        scanf("%d %d",
              origem,
              destino);

        (*origem)--;

        (*destino)--;
    }
}