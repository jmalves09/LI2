
#ifndef CARTA_H
#define CARTA_H

typedef struct {
    char valor;   // As a Rei
    char naipe;   // O E P C
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

#endif