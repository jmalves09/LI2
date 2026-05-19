#include <stdio.h>

#include "Interface.h"


void mostrarComandos(void) {

    printf("\nCOMANDOS:\n");

    printf("m origem destino  -> mover cartas\n");

    printf("u                 -> desfazer jogada\n");

    printf("h                 -> ajuda\n");

    printf("q                 -> sair\n\n");
    
    printf("s ficheiro        -> guardar jogo\n");

    printf("l ficheiro        -> carregar jogo\n");

    printf("q                 -> sair\n\n");
}


void lerComando(char *cmd,
                int *origem,
                int *destino,
                char *ficheiro) {
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
    else if(cmd == 'u') {

    desfazerJogada(&j);
    }
    else if(*cmd == 's' ||
            *cmd == 'l') {

        scanf("%s",
              ficheiro);
    }
}