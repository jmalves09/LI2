#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carta.h"

Carta criar_carta(char valor, char naipe){
    Carta c;
    c.valor = valor;
    c.naipe = naipe;
    return c;
}


int valor_numerico(Carta c) {
    switch(c.valor) {
        case 'A': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        default: return c.valor - '0';
    }
}

int jogada_valida(Carta a, Carta b){
    int va = valor_numerico(a);
    int vb = valor_numerico(b);
    return (va==vb+1||va==vb-1);
}

// Getters 
int get_valor(Carta c){
    return c.valor;
}

int get_naipe(Carta c){
    return c.naipe;
}

void imprimir_carta(Carta c){
    printf("%c%c ", c.valor, c.naipe);
}
