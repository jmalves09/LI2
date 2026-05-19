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

Carta ver_topo(Pilha *p) {
    if (p->topo == 0) {
        return criar_carta('0','0');
    }
    return p->cartas[p->topo-1];
}

int pilha_vazia(Pilha *p){
    return p->topo == 0;
}

//funcao que indica qual a carta na posicao pos da pilha p
Carta ver_carta(Pilha *p, int pos){
    if(pos < 0 || pos >= p->topo){
        return criar_carta('0','0');
    }
    return p->cartas[pos];
}

//funcao que remove n cartas de uma pilha p
int remover_n_cartas(Pilha *p, int n){
    if(n <= 0 || n > p->topo){
        return 0;
    }

    p->topo -= n;
    return 1;
}

//funcao que acrescenta n cartas na pilha p
int adicionar_n_cartas(Pilha *p, Carta cartas[], int n){
    if(n <= 0 || p->topo + n > TAM_PILHA){
        return 0;
    }

    for(int i = 0; i < n; i++){
        p->cartas[p->topo++] = cartas[i];
    }

    return 1;
}

//funcao que conta quantas cartas estao na sequencia correta
//sequencia decrescente e com o mesmo naipe
int contar_sequencia(Pilha *p, int pos){
     if(pos < 0 || pos >= p->topo){
        return 0;
    }

    int count = 1;

    for(int i = pos; i < p->topo - 1; i++){
        Carta atual = p->cartas[i];
        Carta seguinte = p->cartas[i + 1];

        if(get_naipe(atual) == get_naipe(seguinte) &&
           valor_numerico(atual) == valor_numerico(seguinte) + 1){
            count++;
        } else {
            break;
        }
    }

    return count;
}