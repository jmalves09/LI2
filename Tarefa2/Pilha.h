#ifndef PILHA_H
#define PILHA_H
#include "Carta.h"
#define TAM_PILHA 52

typedef struct {
    Carta cartas[TAM_PILHA];
    int topo;
} Pilha;

// Funcao que inicia a pilha
//inicialmente a zero
void iniciar_pilha(Pilha *p);

//funcao que remove carta de uma pilha
Carta remove_Carta(Pilha *p);

//funcao que aficiona a carta no topo da pilha
int adiciona_carta(Pilha *p, Carta c);

//funcao que verifica topo da pilha
Carta ver_topo(Pilha *p);

//funcao que verifica se a pilha esta vazia
int pilha_vazia(Pilha *p);

//funcao que indica qual a carta na posicao pos da pilha p
Carta ver_carta(Pilha *p, int pos);

//funcao que remove n cartas de uma pilha p
int remover_n_cartas(Pilha *p, int n);

//funcao que acrescenta n cartas na pilha p
int adicionar_n_cartas(Pilha *p, Carta cartas[], int n);

//funcao que conta quantas cartas estao na sequencia correta
//sequencia decrescente e com o mesmo naipe
int contar_sequencia(Pilha *p, int pos);
#endif