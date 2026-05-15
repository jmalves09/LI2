#include <stdio.h>
#include <string.h>
#include "Jogo.h"
#include "Interface.h"
#include "Carta.h"
int main() {
    Jogo jogo;
    char input[5];

    iniciar_jogo(&jogo);
    int run = 1;
    while(!jogo_terminou(&jogo) & run !=0) {

        mostrar_jogo(&jogo);

        int cmd = ler_comando(input);

        if(cmd == 2) {

            tirar_baralho(&jogo);

        }
        else if(cmd == 1) {

            Carta c = criar_carta(input[0], input[1]);
            jogar_carta(&jogo, c);

        }
        else if(cmd == 0) {

            printf("A sair do jogo...\n");
            run=0;
        }
    }

    printf("\n=== JOGO TERMINADO ===\n");
    return 0;
}