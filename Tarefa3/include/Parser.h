/* include/Parser.h */

#ifndef PARSER_H
#define PARSER_H

#include "Dsl.h"

#define MAX_LINHA 256

// função que processa a linha JOGO
void parseJogo(Dsl *dsl, char *linha) 

// função que processa a linha BARALHOS
void parseBaralhos(Dsl *dsl, char *linha)

// função que processa a linha TIPO
void parseTipo(Dsl *dsl, char *linha) 

// função que processa a linha INIT
void parseInit(Dsl *dsl, char *linha)

// função que processa a linha MOV
void parseMov(Dsl *dsl, char *linha)

// função que processa a linha AUTO
void parseAuto(Dsl *dsl, char *linha)

// função que processa a linha WIN
void parseWin(Dsl *dsl, char *linha)

//Função que identifica o comando da linha
//Compara com Strcmp e chama a função Parse correspondente
void processaLinha(Dsl *dsl, char *linha) 

//Função que lê Ficheiro paciência
//Lê linha a linha
void parseFicheiro(const char *nomeFicheiro, Dsl *dsl)