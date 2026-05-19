#ifndef INTERFACE_H
#define INTERFACE_H

#include "Jogo.h"

//Função que imprime os comandos possíveis
void mostrarComandos(void);

//Função que interpreta os comandos
void lerComando(char *cmd, int *origem, int *destino, char *ficheiro);

#endif