#include <stdio.h>
#include "Pilha.h"

void iniciar_pilha(Pilha *p){
    p->topo=0;
}

int adiciona_carta(Pilha *p, Carta c){
if (p->topo >= TAM_PILHA) {
        return 0;
    }
    p->cartas[p->topo++] = c;
    return 1;
}

Carta remove_Carta(Pilha *p){
    if (p->topo == 0) {
        printf("Pilha vazia!\n");
        return criar_carta('0','0');
    }
    return p->cartas[--p->topo];
}

Carta ver_topo(Pilha *p) {
    if (p->topo == 0) {
        return criar_carta('0','0'); // carta placeholder
    }
    return p->cartas[p->topo-1];
}

int pilha_vazia(Pilha *p){
    return p->topo == 0;
}