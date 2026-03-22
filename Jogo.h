#ifndef JOGO_H
#define JOGO_H
#include "Baralho.h"
#include "Pilha.h"

#define NUM_PILHAS 7

typedef struct {
    Pilha pilhas[NUM_PILHAS];
    Pilha descarte;
    Baralho baralho;
} Jogo;

//funcao inicia jogo
void iniciar_jogo(Jogo *j);

//Jogar da Pilha
int jogar_carta(Jogo *j, Carta c);

//Jogar do baralho
void tirar_baralho(Jogo *j);

//verifica se as pilhas estao todas vazias
int pilhas_vazias(Jogo *j);

//verifica se existe jogada possivel
int existe_jogada_possivel(Jogo *j);

// Estado
int jogo_terminou(Jogo *j);

//print do jogo
void mostrar_jogo(Jogo *j);
#endif