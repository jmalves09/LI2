#ifndef PILHA_H
#define PILHA_H

#include "Carta.h"

typedef struct pilha Pilha;

/**
 * Esta função devolve uma pilha inicializada e que apontada para o seu início.
 * 
 */
void iniciar (Pilha *pilha);

//funcao que verifica se a pilha esta vazia
bool estaVazia(Pilha *pilha);

//funcao que verifica se a pilha esta cheia
bool estaCheia(Pilha *pilha);

//funcao que adiciona carta no topo da pilha
void adiciona(Pilha *p, Carta c);

//funcao que retira carta da pilha
void retiraCarta(Pilha *p);

#endif