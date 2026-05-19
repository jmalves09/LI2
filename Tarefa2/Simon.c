#include <stdio.h>
#include "Jogo.h"
#include "Interface.h"

int main() {
    Jogo j;
    char input;
    int run = 1;

    iniciar_jogo(&j);

    while(!jogo_terminou(&j) && run!=0) {

        mostrar_jogo(&j);
        ler_comando(&input);

        if(input == 'X' || input == 'x') {
            printf("A sair do jogo...\n");
            run = 0;
        }
        else if(input == 'H' || input == 'h') {
            int ajuda = -1;

            for(int i = 0; i < NUM_PILHAS; i++) {
                if(!pilha_vazia(&j.pilhas[i])) {
                    for(int n = j.pilhas[i].topo; n >= 1; n--) {
                        int pos = j.pilhas[i].topo - n;

                        if(n == 1 || contar_sequencia(&j.pilhas[i], pos) >= n) {
                            if(encontrar_destino(&j, i, n) != -1) {
                                ajuda = i;
                                n = 0;
                                i = NUM_PILHAS;
                            }
                        }
                    }
                }
            }

            if(ajuda == -1) {
                printf("Nao ha jogadas possiveis.\n");
            }
            else {
                printf("Podes jogar a pilha %d\n", ajuda + 1);
            }
        }
        else {
            int origem = input - '0' - 1;

            if(!mover_cartas(&j, origem)) {
                printf("Jogada invalida!\n");
            }
        }
    }

    printf("\n=== JOGO TERMINADO ===\n");
    printf("Sequencias completas: %d\n", j.completas);

    return 0;
}