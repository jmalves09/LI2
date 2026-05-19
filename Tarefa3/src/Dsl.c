/* src/Dsl.c */

#include <stdio.h>
#include <string.h>

#include "../include/Dsl.h"


void inicializaDsl(Dsl *dsl) {

    dsl->nomeJogo[0] = '\0';
    dsl->numeroBaralhos = 0;
    dsl->numTipos = 0;
    dsl->numInits = 0;
    dsl->numMovimentos = 0;
    dsl->numAutos = 0;
    dsl->numWins = 0;
}


void adicionaJogo(Dsl *dsl,
                  const char *nome) {

    strcpy(dsl->nomeJogo,
           nome);
}


void adicionaBaralhos(Dsl *dsl,
                      int n) {

    dsl->numeroBaralhos = n;
}


void adicionaTipo(Dsl *dsl,
                  const char *tipo,
                  const char *flags) {

    TipoPilha *t;

    t = &dsl->tipos[dsl->numTipos];

    strcpy(t->nome,
           tipo);

    strcpy(t->flags,
           flags);

    dsl->numTipos++;
}


void adicionaInit(Dsl *dsl,
                  const char *tipo,
                  int quantidade) {

    InitPilha *i;

    i = &dsl->inits[dsl->numInits];

    strcpy(i->tipo,
           tipo);

    i->quantidade = quantidade;

    dsl->numInits++;
}


void adicionaMovimento(Dsl *dsl,
                       const char *origem,
                       const char *destino,
                       const char *flags) {

    RegraMovimento *m;

    m = &dsl->movimentos[dsl->numMovimentos];

    strcpy(m->origem,
           origem);

    strcpy(m->destino,
           destino);

    strcpy(m->flags,
           flags);

    dsl->numMovimentos++;
}


void adicionaAuto(Dsl *dsl,
                  const char *origem,
                  const char *destino,
                  const char *flags) {

    RegraMovimento *a;

    a = &dsl->autos[dsl->numAutos];

    strcpy(a->origem,
           origem);

    strcpy(a->destino,
           destino);

    strcpy(a->flags,
           flags);

    dsl->numAutos++;
}


void adicionaWin(Dsl *dsl,
                 const char *tipo,
                 int objetivo) {

    RegraWin *w;

    w = &dsl->wins[dsl->numWins];

    strcpy(w->tipo,
           tipo);

    w->objetivo = objetivo;

    dsl->numWins++;
}


int temFlag(const char *flags,
            char flag) {

    return strchr(flags,
                  flag) != NULL;
}


void imprimeDsl(const Dsl *dsl) {

    int i;

    printf("JOGO: %s\n",
           dsl->nomeJogo);

    printf("BARALHOS: %d\n\n",
           dsl->numeroBaralhos);


    printf("TIPOS\n");

    for (i = 0; i < dsl->numTipos; i++) {

        printf("  %s %s\n",
               dsl->tipos[i].nome,
               dsl->tipos[i].flags);
    }


    printf("\nINITS\n");

    for (i = 0; i < dsl->numInits; i++) {

        printf("  %s %d\n",
               dsl->inits[i].tipo,
               dsl->inits[i].quantidade);
    }


    printf("\nMOVIMENTOS\n");

    for (i = 0; i < dsl->numMovimentos; i++) {

        printf("  %s -> %s [%s]\n",
               dsl->movimentos[i].origem,
               dsl->movimentos[i].destino,
               dsl->movimentos[i].flags);
    }


    printf("\nAUTOS\n");

    for (i = 0; i < dsl->numAutos; i++) {

        printf("  %s -> %s [%s]\n",
               dsl->autos[i].origem,
               dsl->autos[i].destino,
               dsl->autos[i].flags);
    }


    printf("\nWINS\n");

    for (i = 0; i < dsl->numWins; i++) {

        printf("  %s %d\n",
               dsl->wins[i].tipo,
               dsl->wins[i].objetivo);
    }
}