/* include/Dsl.h */

#ifndef DSL_H
#define DSL_H

#define MAX_NOME 32
#define MAX_FLAGS 32

typedef struct {
    char nome[MAX_NOME];
    char flags[MAX_FLAGS];
} TipoPilha;

typedef struct {
    char tipo[MAX_NOME];
    int quantidade;
} InitPilha;

typedef struct {
    char origem[MAX_NOME];
    char destino[MAX_NOME];
    char flags[MAX_FLAGS];
} RegraMovimento;

typedef struct {
    char tipo[MAX_NOME];
    int objetivo;
} RegraWin;

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


/* Inicialização */

void inicializaDsl(Dsl *dsl);


/* Adicionar informação */

void adicionaJogo(Dsl *dsl,
                  const char *nome);

void adicionaBaralhos(Dsl *dsl,
                      int n);

void adicionaTipo(Dsl *dsl,
                  const char *tipo,
                  const char *flags);

void adicionaInit(Dsl *dsl,
                  const char *tipo,
                  int quantidade);

void adicionaMovimento(Dsl *dsl,
                       const char *origem,
                       const char *destino,
                       const char *flags);

void adicionaAuto(Dsl *dsl,
                  const char *origem,
                  const char *destino,
                  const char *flags);

void adicionaWin(Dsl *dsl,
                 const char *tipo,
                 int objetivo);


/* Utilitários */

int temFlag(const char *flags,
            char flag);

void imprimeDsl(const Dsl *dsl);

#endif