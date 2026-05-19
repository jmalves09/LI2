#ifndef JOGO_H
#define JOGO_H

#include "Baralho.h"
#include "Pilha.h"

#define NUM_PILHAS 10

typedef struct {
    Baralho baralho;
    Pilha pilhas[NUM_PILHAS];
    int completas;
} Jogo;

//funcao que inicia o jogo
void iniciar_jogo(Jogo *j);

//funcao que verifica se uma determinada sequencia por ir para outra pilha
int verifica_sequencia(Jogo *j, int origem, int n);

//funcao precorre as pilhas e verifica se existe uma jogada possivel
int existe_jogada_possivel(Jogo *j);

//funcao que verifica se ha 13 cartas do mesmo naipe na sequencia correta,
//remove do jogo caso seja verdade
void sequencia_completa(Jogo *j, int pilha);

//funcao que encontra um destino para um numero n de cartas da pilha origem
int encontrar_destino(Jogo *j, int origem, int n);

//funcao que vai mover as cartas de uma determinada pilha de origem
int mover_cartas(Jogo *j, int origem);

//print do jogo
void mostrar_jogo(Jogo *j);

//estado
int jogo_terminou(Jogo *j);
#endif