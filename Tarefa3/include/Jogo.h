#ifndef JOGO_H
#define JOGO_H

#include "Carta.h"
#include "Pilha.h"
#include "Baralho.h"
#include "Dsl.h"

#define MAX_PILHAS 100


typedef struct {

    char nome[32];
    char tipo[32];

    Pilha pilha;

} PilhaJogo;


typedef struct {

    Dsl regras;

    Baralho baralho;

    PilhaJogo pilhas[MAX_PILHAS];
    int numPilhas;

} Jogo;


/* Inicialização */

void iniciarJogo(Jogo *j,
                 const char *ficheiroDsl);

void criarPilhas(Jogo *j);

void distribuirCartas(Jogo *j);


/* Procura de regras */

RegraMovimento *encontrarMovimento(Jogo *j,
                                   int origem,
                                   int destino);

int encontrarTipo(Dsl *dsl,
                  const char *tipo);


/* Validação */

int sequenciaValida(Pilha *p,
                    int pos,
                    int quantidade,
                    int mesmoNaipe);

int pilhaAceitaCarta(Jogo *j,
                     int origem,
                     int destino,
                     int quantidade);

int maiorSequenciaMovivel(Jogo *j,
                          int origem,
                          int destino);


/* Movimentos */

int moverCartas(Jogo *j,
                int origem,
                int destino);

int executarAuto(Jogo *j);


/* Estado */

int verificarWin(Jogo *j);

int jogoTerminou(Jogo *j);


/* Interface */

void mostrarJogo(Jogo *j);

#endif