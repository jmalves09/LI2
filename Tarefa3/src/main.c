/* src/main.c */

#include <stdio.h>

#include "Jogo.h"
#include "Interface.h"

int main(int argc,
         char *argv[]) {

    Jogo j;

    char cmd;

    int origem;
    int destino;

    int ajudaOrigem;
    int ajudaDestino;

    char ficheiro[64];

    char ficheiroPaciencia[64];

    if(argc < 2) {

        printf("Uso: %s ficheiro.paciencia\n",
               argv[0]);

        return 1;
    }


    iniciarJogo(&j,
                 argv[1]);


    while(!jogoTerminou(&j)) {

        mostrarJogo(&j);

        mostrarComandos();

        lerComando(&cmd,
                   &origem,
                   &destino,
                   ficheiro);
        /* mover */

        if(cmd == 'm') {

            guardarUndo(&j);

            if(moverCartas(&j,
                           origem,
                           destino)) {

                while(executarAuto(&j));

                printf("Jogada realizada.\n");
            }

            else {

                printf("Jogada invalida.\n");
            }
        }

        /* ajuda */

        else if(cmd == 'h') {

            if(encontrarAjuda(&j,
                              &ajudaOrigem,
                              &ajudaDestino)) {

                printf("Sugestao: mover de %s para %s\n",
                       j.pilhas[ajudaOrigem].nome,
                       j.pilhas[ajudaDestino].nome);
            }

            else {

                printf("Nao existem jogadas possiveis.\n");
            }
        }

        /* guardar */

        else if(cmd == 's') {

            if(guardarJogo(&j,
                           ficheiro,
                           argv[1])) {

                printf("Jogo guardado.\n");
            }

            else {

                printf("Erro ao guardar jogo.\n");
            }
        }

        /* carregar */

        else if(cmd == 'l') {

            if(carregarJogo(&j,
                            ficheiro,
                            ficheiroPaciencia)) {

                printf("Jogo carregado.\n");
            }

            else {

                printf("Erro ao carregar jogo.\n");
            }
        }

        /* undo */

        else if(cmd == 'u') {

            desfazerJogada(&j);

            printf("Jogada desfeita.\n");
        }

        /* sair */

        else if(cmd == 'q') {

            printf("A sair...\n");

            return 0;
        }
    }

    mostrarJogo(&j);

    printf("\nVITORIA!\n");

    return 0;
}