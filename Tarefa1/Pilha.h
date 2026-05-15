#ifndef PILHA_H
#define PILHA_H
#include "Carta.h"
#define TAM_PILHA 5

typedef struct {
    Carta cartas[TAM_PILHA];
    int topo;
} Pilha;

// Funcao que inicia a pilha
//inicialmente a zero
void iniciar_pilha(Pilha *p);

//funcao que aficiona a carta no topo da pilha
int adiciona_carta(Pilha *p, Carta c);

//funcao que remove carta de uma pilha
Carta remove_Carta(Pilha *p);

//funcao que verifica topo da pilha
Carta ver_topo(Pilha *p);

//funcao que verifica se a pilha esta vazia
int pilha_vazia(Pilha *p);

#endif