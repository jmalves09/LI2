#include <stdio.h>

#include "Jogo.h"

int main(int argc,
         char *argv[]) {

    Jogo j;

    if(argc < 2) {

        printf("Uso: %s ficheiro.paciencia\n",
               argv[0]);

        return 1;
    }

    iniciarJogo(&j,
                 argv[1]);

    mostrarJogo(&j);

    return 0;
}