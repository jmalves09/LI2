/* src/Parser.c */

#include <stdio.h>
#include <string.h>

#include "Parser.h"
#include "Dsl.h"

#define MAX_LINHA 256


void removeComentario(char *linha) {

    char *comentario;

    comentario = strchr(linha,
                        '#');

    if(comentario != NULL) {
        *comentario = '\0';
    }
}


void parseFicheiro(const char *nomeFicheiro,
                   Dsl *dsl) {

    FILE *f;
    char linha[MAX_LINHA];

    f = fopen(nomeFicheiro,
              "r");

    if(f == NULL) {

        printf("Erro ao abrir ficheiro.\n");
        return;
    }

    while(fgets(linha,
                MAX_LINHA,
                f) != NULL) {

        char comando[32];

        removeComentario(linha);

        if(sscanf(linha,
                  "%s",
                  comando) != 1) {

            continue;
        }

        if(strcmp(comando,
                  "JOGO") == 0) {

            char nome[64];

            sscanf(linha,
                   "JOGO %s",
                   nome);

            adicionaJogo(dsl,
                         nome);
        }

        else if(strcmp(comando,
                       "BARALHOS") == 0) {

            int n;

            sscanf(linha,
                   "BARALHOS %d",
                   &n);

            adicionaBaralhos(dsl,
                             n);
        }

        else if(strcmp(comando,
                       "TIPO") == 0) {

            char tipo[32];
            char flags[32];

            sscanf(linha,
                   "TIPO %s %s",
                   tipo,
                   flags);

            adicionaTipo(dsl,
                         tipo,
                         flags);
        }

        else if(strcmp(comando,
                       "INIT") == 0) {

            char tipo[32];
            int quantidade;

            sscanf(linha,
                   "INIT %s %d",
                   tipo,
                   &quantidade);

            adicionaInit(dsl,
                         tipo,
                         quantidade);
        }

        else if(strcmp(comando,
                       "MOV") == 0) {

            char origem[32];
            char destino[32];
            char flags[32];

            sscanf(linha,
                   "MOV %s %s %s",
                   origem,
                   destino,
                   flags);

            adicionaMovimento(dsl,
                              origem,
                              destino,
                              flags);
        }

        else if(strcmp(comando,
                       "AUTO") == 0) {

            char origem[32];
            char destino[32];
            char flags[32];

            sscanf(linha,
                   "AUTO %s %s %s",
                   origem,
                   destino,
                   flags);

            adicionaAuto(dsl,
                         origem,
                         destino,
                         flags);
        }

        else if(strcmp(comando,
                       "WIN") == 0) {

            char tipo[32];
            int objetivo;

            sscanf(linha,
                   "WIN %s %d",
                   tipo,
                   &objetivo);

            adicionaWin(dsl,
                        tipo,
                        objetivo);
        }
    }

    fclose(f);
}