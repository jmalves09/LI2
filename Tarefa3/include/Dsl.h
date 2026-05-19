/* include/Dsl.h */

#ifndef DSL_H
#define DSL_H

#define MAX_NOME 32
#define MAX_FLAGS 32


//categoria de pilhas
//cada categora tem um tipo e as suas flags
typedef struct {
    char nome[MAX_NOME];
    char flags[MAX_FLAGS];
} TipoPilha;

//pilha 
typedef struct {
    char tipo[MAX_NOME];
    int quantidade;
} InitPilha;

// movimento tem
//pilha origem 
//pilha destinho
//flags
typedef struct {
    char origem[MAX_NOME];
    char destino[MAX_NOME];
    char flags[MAX_FLAGS];
} RegraMovimento;

//condição de vitória
typedef struct {
    char tipo[MAX_NOME];
    int objetivo;
} RegraWin;

//Estrutura Dsl
typedef struct {

    char nomeJogo[MAX_NOME];

    int numeroBaralhos;

    TipoPilha tipos[50];
    int numTipos;

    InitPilha inits[100];
    int numInits;

    RegraMovimento movimentos[100];
    int numMovimentos;

    RegraMovimento autos[100];
    int numAutos;

    RegraWin wins[50];
    int numWins;

} Dsl;


//Função que inicia Dsl
void inicializaDsl(Dsl *dsl);

//Função que guarda um jogo
void adicionaJogo(Dsl *dsl,
                  const char *nome);

//Função que guarda um número de Baralhos utilizados
void adicionaBaralhos(Dsl *dsl,
                      int n);

//Função que guarda um tipo de pilha
void adicionaTipo(Dsl *dsl,
                  const char *tipo,
                  const char *flags);

//Função que guarda a inicialização das Pilhas
void adicionaInit(Dsl *dsl,
                  const char *tipo,
                  int quantidade);

//Função que guarda Regra de Movimentos
void adicionaMovimento(Dsl *dsl,
                       const char *origem,
                       const char *destino,
                       const char *flags);

//Função que guarda uma regra Automática
void adicionaAuto(Dsl *dsl,
                  const char *origem,
                  const char *destino,
                  const char *flags);

//Função que guarda uma condição de Vitória
void adicionaWin(Dsl *dsl,
                 const char *tipo,
                 int objetivo);

//Função que verifica se uma flag existe
int temFlag(const char *flags,
            char flag);

//Imprime a Informação guardada
void imprimeDsl(const Dsl *dsl);

#endif