#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "Baralho.h"
#include "Carta.h"
#include "Pilha.h"

//cria baralho com 52 cartas
void iniciarBaralho(Pilha* b, Carta c){
    char valores[] = {'A','2','3','4','5','6','7','8','9','T','V','D','R'};
    char naipes[] = {'E','P','C','O'};

    iniciar(b);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){

            Carta c;
            c.valor = valores[j];
            c.naipe = naipes[i];

            adiciona(b, c);
        }
    }
}

/*baralhar
void baralhar(Pilha* b){
    for(int i=0; i<b->topo; i++){
        int j=rand()%52+i;

        Carta temp= b->cartas[i];
        b->cartas[i]=b->cartas[j];
        b->cartas[j]=temp;
    }
}*/

Carta tirarCarta(Pilha *b){
    return retiraCarta(b);
}

int baralhoVazio(Pilha *b){
    return pilhaVazia(b);
}


// funcao que pega no baralho ( baralhado ) organiza em 7 stacks de 5 + baralho restante ( este baralho restante so pode mostrar a cabe'ca da stack)