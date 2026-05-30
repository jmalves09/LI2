#ifndef JOGO_H
#define JOGO_H

#include "Carta.h"  
#include "Pilha.h"
#include "Baralho.h"
#include "Dsl.h"

#define MAX_PILHAS 100


typedef struct {

char nome[32];

/* tipo lógico */
char tipo[32];

/* representação visual */
char visivel;

Pilha pilha;

} PilhaJogo;


typedef struct {

    Baralho baralho;

    PilhaJogo pilhas[MAX_PILHAS];

    int numPilhas;

} EstadoJogo;

typedef struct {

    Dsl regras;

    Baralho baralho;

    PilhaJogo pilhas[MAX_PILHAS];

    int numPilhas;

    EstadoJogo undo;

    int existeUndo;

} Jogo;


// Inicialização jogo 
void iniciarJogo(Jogo *j, const char *ficheiroDsl);

//Função que cria as pilhas apartir da INIT
void criarPilhas(Jogo *j);

//Função que distribui as cartas
void distribuirCartas(Jogo *j);

//Função que procura o tipo de pilha na dsl
int encontrarTipo(Dsl *dsl, const char *tipo);

//Função que verifica se um bloco está em sequencia válida
int sequenciaValida(Pilha *p, int pos, int quantidade, int mesmoNaipe);








//Funcao que valida valores 
// '~' +-1
// '<' + 1
// '>' - 1
int validarValores(RegraMovimento *m, Carta origem, Carta destino) ;

//Funcao auxiliar a pilhaAceitaCarta
//Funcao que verifica se as regras sao validas
int regraValida(Jogo *j, RegraMovimento *m, int origem, int destino, int quantidade);

//Funcao auxiliar a pilhaAceitaCarta
//Funcao que verifica duas cartas tem a mesma cor ou nao
int validarCor(RegraMovimento *m, Carta origem, Carta destino);

//Funcao auxiliar a pilhaAceitaCarta
//funcao que verifica quais carta 'e que podem ir para uma pilha vazia
int validarDestinoVazio(RegraMovimento *m, Carta carta);

//Funcao auxiliar a pilhaAceitaCarta
//Funcao que verifica se e possivel mover uma sequencia de cartas
int validarSequencia(Jogo *j, RegraMovimento *m, int origem, int quantidade);

//Funcao auxiliar a pilhaAceitaCarta
//Funcao que verifica se a quantidade de cartas a mover e valida
int validarQuantidade(RegraMovimento *m,int quantidade);

//Função auxiliar a pilhaAceitaCarta
//Função verifica se sao do mesmo naipe ou nao
int validarNaipe(RegraMovimento *m, Carta origem, Carta destino);

//Função auxiliar a pilhaAceitaCarta
//Função que verifica um movimento
int movimentoCompativel(Jogo *j,RegraMovimento *m,int origem,int destino);

//Função que verifica se uma jogada respeita as flags MOV
int pilhaAceitaCarta(Jogo *j, int origem, int destino, int quantidade);













//Função que procura o maior bloco que pode ser movido
int maiorSequenciaMovivel(Jogo *j, int origem, int destino);

//Função que move cartas entre pilhas
int moverCartas(Jogo *j, int origem, int destino, int quantidade);

//Função que executa movimentos automáticos
int executarAuto(Jogo *j);

//Função que verifica se existe jogadas possíveis
int existeJogadaPossivel(Jogo *j);

//Função help
int encontrarAjuda(Jogo *j, int *origem, int *destino);

//Função que faz cópia de tudo
void guardarUndo(Jogo *j);

//Função que que faz undo. 
//Só pode voltar 1 jogada atrás
void desfazerJogada(Jogo *j);

//Função que verifica condições de vitória
int verificarWin(Jogo *j);

//Função que verifica se o jogo terminou
//termina se vençer ou se não existir mais nenhuma jogada possível
int jogoTerminou(Jogo *j);

//mostra o estado atual do jogo
void mostrarJogo(Jogo *j);

//Função que guarda o estado atual do jogo num ficheiro
int guardarJogo(Jogo *j, const char *ficheiro, const char *ficheiroPaciencia);

//Função que carrega um jogo guardado
int carregarJogo(Jogo *j, const char *ficheiro, char *ficheiroPaciencia);

#endif