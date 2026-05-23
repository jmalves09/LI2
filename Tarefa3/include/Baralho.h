#ifndef BARALHO_H
#define BARALHO_H
#include "Carta.h"
#define TAM_BARALHO 52

typedef struct {
    Carta cartas[TAM_BARALHO];
    int topo;
} Baralho;

// Inicialização
//funcao vai pegar nas duas listas e gerar um baralho de 52 cartas
void iniciar_baralho(Baralho *b);

// funcao que pega no baralho criado e baralha
// funcao swap com um valor aleatorio 
void baralhar(Baralho *b);

//funcao que verifica se o baralho esta vazio
int baralho_vazio(Baralho *b);

//funcao que tira uma carta do baralho
//funcao verifica se baralho esta vazio
Carta tirar_carta(Baralho *b);

#endif