/* src/main.c */

#include <stdio.h>

#include "Jogo.h"
#include "Interface.h"
#include <stdlib.h>
#include <string.h>

int main(int argc,
         char *argv[]) {

    Jogo j;

    char cmd;

    char mensagem[128] = "";

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

        system("clear");

        mostrarJogo(&j);

        printf("\n%s\n", mensagem);

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

                strcpy(mensagem,"Jogada realizada.");
            }

            else {

                strcpy(mensagem,"Jogada invalida.");
            }
        }

        /* ajuda */

        else if(cmd == 'h') {

            if(encontrarAjuda(&j,
                              &ajudaOrigem,
                              &ajudaDestino)) {

                sprintf(mensagem,"Sugestao: mover de %s para %s",
                       j.pilhas[ajudaOrigem].nome,
                       j.pilhas[ajudaDestino].nome);
            }

            else {

                strcpy(mensagem,"Nao existem jogadas possiveis.");
            }
        }

        /* guardar */

        else if(cmd == 's') {

            if(guardarJogo(&j,
                           ficheiro,
                           argv[1])) {

                strcpy(mensagem,"Jogo guardado.");
            }

            else {

                strcpy(mensagem,"Erro ao guardar jogo.");
            }
        }

        /* carregar */

        else if(cmd == 'l') {

            if(carregarJogo(&j,
                            ficheiro,
                            ficheiroPaciencia)) {

                strcpy(mensagem,"Jogo carregado.");
            }

            else {

                strcpy(mensagem,"Erro ao carregar jogo.");
            }
        }

        /* undo */

        else if(cmd == 'u') {

            desfazerJogada(&j);

            strcpy(mensagem,"Jogada desfeita.");
        }

        /* sair */

        else if(cmd == 'q') {

            strcpy(mensagem,"A sair...");

            return 0;
        }
    }

    mostrarJogo(&j);

    printf("\nVITORIA!\n");

    return 0;
}