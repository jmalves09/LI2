/* src/Testes.c */

#include <stdio.h>
#include <string.h>

#include "Jogo.h"
#include "Parser.h"


void testarParser(void) {

    Dsl dsl;

    inicializaDsl(&dsl);

    parseFicheiro("paciencias/golf.paciencia", &dsl);

    if(strcmp(dsl.nomeJogo, "Golf") == 0) {

        printf("Parser OK\n");
    }

    else {

        printf("Parser ERRO\n");
    }
}


void testarInicializacao(void) {

    Jogo j;

    iniciarJogo(&j, "paciencias/golf.paciencia");

    if(j.numPilhas > 0) {

        printf("Inicializacao OK\n");
    }

    else {

        printf("Inicializacao ERRO\n");
    }
}


void testarUndo(void) {

    Jogo j;

    int topoAntes;

    iniciarJogo(&j, "paciencias/golf.paciencia");

    topoAntes = j.pilhas[0].pilha.topo;

    guardarUndo(&j);

    remover_n_cartas(&j.pilhas[0].pilha, 1);

    desfazerJogada(&j);

    if(j.pilhas[0].pilha.topo == topoAntes) {

        printf("Undo OK\n");
    }

    else {

        printf("Undo ERRO\n");
    }
}


void testarSaveLoad(void) {

    Jogo j1;
    Jogo j2;

    char paciencia[64];

    iniciarJogo(&j1, "paciencias/golf.paciencia");

    guardarJogo(&j1, "teste.txt", "paciencias/golf.paciencia");

    carregarJogo(&j2, "teste.txt", paciencia);

    if(j1.pilhas[0].pilha.topo == j2.pilhas[0].pilha.topo) {

        printf("Save/Load OK\n");
    }

    else {

        printf("Save/Load ERRO\n");
    }
}


void testarAjuda(void) {

    Jogo j;

    int origem;
    int destino;

    iniciarJogo(&j, "paciencias/golf.paciencia");

    if(encontrarAjuda(&j, &origem, &destino)) {

        printf("Ajuda OK\n");
    }

    else {

        printf("Ajuda ERRO\n");
    }
}


int main(void) {

    printf("=== TESTES ===\n\n");

    testarParser();

    testarInicializacao();

    testarUndo();

    testarSaveLoad();

    testarAjuda();

    return 0;
}