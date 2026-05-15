/* src/parser.c */

#include <stdio.h>
#include <string.h>

#include "../include/parser.h"
#include "../include/dsl.h"

#define MAX_LINHA 256

static void removeComentario(char *linha) {
    char *comentario = strchr(linha, '#');

    if (comentario != NULL)
        *comentario = '\0';
}

void parseFicheiro(const char *nomeFicheiro) {

    FILE *f;
    char linha[MAX_LINHA];

    f = fopen(nomeFicheiro, "r");

    if (f == NULL) {
        printf("Erro ao abrir ficheiro.\n");
        return;
    }

    while (fgets(linha, MAX_LINHA, f) != NULL) {

        char comando[32];

        removeComentario(linha);

        if (sscanf(linha, "%s", comando) != 1)
            continue;

        if (strcmp(comando, "JOGO") == 0) {

            char nome[64];

            sscanf(linha, "JOGO %s", nome);

            adicionaJogo(nome);
        }

        else if (strcmp(comando, "BARALHOS") == 0) {

            int n;

            sscanf(linha, "BARALHOS %d", &n);

            adicionaBaralhos(n);
        }

        else if (strcmp(comando, "TIPO") == 0) {

            char tipo[32];
            char flags[32];

            sscanf(linha,
                   "TIPO %s %s",
                   tipo,
                   flags);

            adicionaTipo(tipo, flags);
        }

        else if (strcmp(comando, "INIT") == 0) {

            char tipo[32];
            int n;

            sscanf(linha,
                   "INIT %s %d",
                   tipo,
                   &n);

            adicionaInit(tipo, n);
        }

        else if (strcmp(comando, "MOV") == 0) {

            char origem[32];
            char destino[32];
            char flags[32];

            sscanf(linha,
                   "MOV %s %s %s",
                   origem,
                   destino,
                   flags);

            adicionaMovimento(origem,
                              destino,
                              flags);
        }

        else if (strcmp(comando, "AUTO") == 0) {

            char origem[32];
            char destino[32];
            char flags[32];

            sscanf(linha,
                   "AUTO %s %s %s",
                   origem,
                   destino,
                   flags);

            adicionaAuto(origem,
                         destino,
                         flags);
        }

        else if (strcmp(comando, "WIN") == 0) {

            char tipo[32];
            int n;

            sscanf(linha,
                   "WIN %s %d",
                   tipo,
                   &n);

            adicionaWin(tipo, n);
        }
    }

    fclose(f);
}