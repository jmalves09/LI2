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


// Inicialização jogo 
void iniciarJogo(Jogo *j, const char *ficheiroDsl);

//Função que cria as pilhas apartir da INIT
void criarPilhas(Jogo *j);

//Função que distribui as cartas
void distribuirCartas(Jogo *j);

//Função que procura uma regra de Movimento
RegraMovimento *encontrarMovimento(Jogo *j, int origem, int destino);

//Função que procura o tipo de pilha na dsl
int encontrarTipo(Dsl *dsl, const char *tipo);

//Função que verifica se um bloco está em sequencia válida
int sequenciaValida(Pilha *p, int pos, int quantidade, int mesmoNaipe);

//Função que verifica se uma jogada respeita as flags MOV
int pilhaAceitaCarta(Jogo *j, int origem, int destino, int quantidade);

//Função que procura o maior bloco que pode ser movido
int maiorSequenciaMovivel(Jogo *j, int origem, int destino);

//Função que move cartas entre pilhas
int moverCartas(Jogo *j, int origem, int destino);

//Função que executa movimentos automáticos
int executarAuto(Jogo *j);

//Função que verifica condições de vitória
int verificarWin(Jogo *j);

//Função que verifica se o jogo terminou
int jogoTerminou(Jogo *j);

//mostra o estado atual do jogo
void mostrarJogo(Jogo *j);

#endif