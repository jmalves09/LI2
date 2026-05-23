#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Baralho.h"

 
void iniciar_baralho(Baralho *b){
    char valores[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char naipes[]  = {'S','H','D','C'};

    int i = 0;
    for(int n=0; n<4; n++) {
        for(int v=0; v<13; v++) {
            b->cartas[i++] = criar_carta(valores[v], naipes[n]);
        }
    }
b->topo = 0;
}
void baralhar(Baralho *b){
    srand(time(NULL));

    for(int j=0; j<TAM_BARALHO-1; j++) {
        int k = rand() % (j+1);
        Carta temp = b->cartas[j];
        b->cartas[j] = b->cartas[k];
        b->cartas[k] = temp;
    }
    b->topo = 0;
}

int baralho_vazio(Baralho *b){
    return b->topo >= TAM_BARALHO;
}

Carta tirar_carta(Baralho *b) {
    if(baralho_vazio(b)) {
        printf("Baralho vazio!\n");
        return criar_carta('0','0');
    }
    return b->cartas[b->topo++];
}