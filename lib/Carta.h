#ifndef CARTA_H
#define CARTA_H

typedef struct carta Carta;

/**
 * @brief Função que converte um caracter num número inteiro. 
 * @param c 
 * @return inteiro correspondente ao caracter
 */
int valorCarta (Carta c);

//funcao que cria uma carta, sendo a posicao 0 o valor numerico 
// e a posicao 1 o naipe da mesma
Carta criarCarta(char *str);

int cartaIgual(Carta a, Carta b);

//funcao que verifica se duas cartas sao adjacentes
//O Rei nao pode ser adjacente ao As, nem vice-versa
int cartaAdjacente(Carta a, Carta b);

#endif