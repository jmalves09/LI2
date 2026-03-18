#ifndef BARALHO_H
#define BARALHO_H

#include "Carta.h"
#include "Pilha.h"

//cria baralho com 52 cartas
void iniciarBaralho(Pilha *b, Carta c);

//baralhar
void baralhar(Pilha *b);

//
Carta tirarCarta(Pilha *b);

//
int baralhoVazio(Pilha *b);

#endif