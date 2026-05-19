/* src/Parser.c */

#include <stdio.h>
#include <string.h>

#include "Parser.h"
#include "Dsl.h"

#define MAX_LINHA 256


void parseJogo(Dsl *dsl,
               char *linha) {

    char nome[64];

    sscanf(linha,
           "JOGO %s",
           nome);

    adicionaJogo(dsl,
                 nome);
}


void parseBaralhos(Dsl *dsl,
                   char *linha) {

    int n;

    sscanf(linha,
           "BARALHOS %d",
           &n);

    adicionaBaralhos(dsl,
                     n);
}


void parseTipo(Dsl *dsl,
               char *linha) {

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


void parseInit(Dsl *dsl,
               char *linha) {

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


void parseMov(Dsl *dsl,
              char *linha) {

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


void parseAuto(Dsl *dsl,
               char *linha) {

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

void parseDist(Dsl *dsl,
               char *linha) {

    char tipo[32];

    int valores[20];

    int quantidade;

    quantidade = sscanf(linha,
                        "DIST %s %d %d %d %d %d %d %d %d %d %d",
                        tipo,
                        &valores[0],
                        &valores[1],
                        &valores[2],
                        &valores[3],
                        &valores[4],
                        &valores[5],
                        &valores[6],
                        &valores[7],
                        &valores[8],
                        &valores[9]);

    adicionaDistribuicao(dsl,
                         tipo,
                         valores,
                         quantidade - 1);
}

void parseWin(Dsl *dsl,
              char *linha) {

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


void processaLinha(Dsl *dsl,
                   char *linha) {

    char comando[32];

    if(sscanf(linha,
              "%s",
              comando) == 1) {

        if(strcmp(comando,
                  "JOGO") == 0) {

            parseJogo(dsl,
                      linha);
        }

        else if(strcmp(comando,
                       "BARALHOS") == 0) {

            parseBaralhos(dsl,
                           linha);
        }

        else if(strcmp(comando,
                       "TIPO") == 0) {

            parseTipo(dsl,
                      linha);
        }

        else if(strcmp(comando,
                       "INIT") == 0) {

            parseInit(dsl,
                      linha);
        }

        else if(strcmp(comando,
                       "MOV") == 0) {

            parseMov(dsl,
                     linha);
        }

        else if(strcmp(comando,
                       "AUTO") == 0) {

            parseAuto(dsl,
                      linha);
        }

        else if(strcmp(comando,
                      "DIST") == 0) {

              parseDist(dsl,
              linha);
}
        else if(strcmp(comando,
                       "WIN") == 0) {

            parseWin(dsl,
                     linha);
        }
    }
}


void parseFicheiro(const char *nomeFicheiro,
                   Dsl *dsl) {

    FILE *f;
    char linha[MAX_LINHA];

    f = fopen(nomeFicheiro,
              "r");

    if(f != NULL) {

        while(fgets(linha,
                    MAX_LINHA,
                    f) != NULL) {

            processaLinha(dsl,
                          linha);
        }

        fclose(f);
    }

    else {

        printf("Erro ao abrir ficheiro.\n");
    }
}