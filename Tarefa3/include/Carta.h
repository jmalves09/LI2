
#ifndef CARTA_H
#define CARTA_H

typedef struct {
    char valor;   // As a Rei
    char naipe;   // D S H C
} Carta;


// Funcao que vai pegar criar a carta
Carta criar_carta(char valor, char naipe);

//funcao que indica o valor numerico das cartas
//A=1,(...) ,Dez(T)=10 ,Valete(J)=11 ,Rainha(Q)=12 ,Rei(R)=13
int valor_numerico(Carta c);

//funcao que verifica se uma carta a pode ser colada debaixo da carta b
//para isso, a = b - 1
int pode_mover(Carta a, Carta b);

//funcao que vai verificar se as cartas da pilha estao de ordem decrescente
//existem duas condicoes para esta funcao ser valida:
//carta a e carta b tem de ter o mesmo naipe
//a = b - 1 
int sequencia_valida (Carta a, Carta b);

// Getters 
int get_valor(Carta c);

// Getters
int get_naipe(Carta c);

// funcao que imprime a carta 
// exemplo As de Espadas == AS
void imprimir_carta(Carta c);

//Função que escreve a carta
void escrever_carta(FILE *f, Carta c);

//Função que Lê a carta
Carta ler_carta(char *texto);

//Função que verifica a cor de uma carta
//1 é vermelha 0 é preto
int cor_carta(Carta c);

#endif